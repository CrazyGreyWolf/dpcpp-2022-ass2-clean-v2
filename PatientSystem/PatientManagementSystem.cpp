#include "PatientManagementSystem.h"

#include <iostream>
#include <map>
#include <tuple>

#include "Patient.h"
#include "PatientDatabaseLoader.h"
#include "AdapterPatientFileLoader.h"
#include "Vitals.h"

#include "GPNotificationSystemFacade.h"
#include "HospitalAlertSystemFacade.h"

#include "CompositeLoader.h"
#include "CompositeLoaderLeaf.h"
#include "Subject.h"
#include "HospitalObserver.h"
#include "GPObserver.h"

using namespace std;


PatientManagementSystem::PatientManagementSystem() :
  _patientDatabaseLoader(std::make_unique<PatientDatabaseLoader>()),
  _patientFileLoader(std::make_unique<AdapterPatientFileLoader>()),
  _hospitalAlertSystem(std::make_unique<HospitalAlertSystemFacade>()),
  _gpNotificationSystem(std::make_unique<GPNotificationSystemFacade>()),
  _subject(std::make_unique<Subject>())
{
  _patientDatabaseLoader->initialiseConnection();
}

PatientManagementSystem::~PatientManagementSystem()
{
  _patientDatabaseLoader->closeConnection();

  // clear patient memory
  for (Patient* p : _patients) {

    // Clear Vitals memory
    for (const Vitals* item : p->vitals())
    {
      delete item;
    }

    delete p;
  }
}

void PatientManagementSystem::init()
{
  std::shared_ptr<CompositeLoader> compositeLoader = std::make_shared<CompositeLoader>();

  // add leaves to each combination
  std::shared_ptr<CompositeLoaderLeaf> compositeLoaderLeafDatabase = std::make_shared<CompositeLoaderLeaf>(_patientDatabaseLoader.get());
  std::shared_ptr<CompositeLoaderLeaf> compositeLoaderLeafFile = std::make_shared<CompositeLoaderLeaf>(_patientFileLoader.get());

  // Add three combinations
  std::shared_ptr<CompositeLoader> compositeDatabaseLoader = std::make_shared<CompositeLoader>();
  std::shared_ptr<CompositeLoader> compositeFileLoader = std::make_shared<CompositeLoader>();
  std::shared_ptr<CompositeLoader> compositeDatabaseAndFileLoader = std::make_shared<CompositeLoader>();

  compositeDatabaseLoader->add(compositeLoaderLeafDatabase);

  compositeFileLoader->add(compositeLoaderLeafFile);

  compositeDatabaseAndFileLoader->add(compositeLoaderLeafDatabase);
  compositeDatabaseAndFileLoader->add(compositeLoaderLeafFile);

  compositeLoader->add(compositeDatabaseLoader);
  compositeLoader->add(compositeFileLoader);
  compositeLoader->add(compositeDatabaseAndFileLoader);

  // Download Data
  // 0 load from database
  // 1 load from file
  // 2 Load the data in the database first, then append the data in the file
  compositeLoader->get(2)->operation(_patients);

  // Create an observer
  std::shared_ptr<HospitalObserver> hospitalObserver = std::make_shared<HospitalObserver>(_hospitalAlertSystem.get());
  std::shared_ptr<GPObserver> gpObserver = std::make_shared<GPObserver>(_gpNotificationSystem.get());

  // add to subject
  _subject->add(hospitalObserver);
  _subject->add(gpObserver);

  for (Patient* p : _patients) {
    _patientLookup[p->uid()] = p;
  }

  for (Patient* p : _patients) {
    // TODO: do any processing you need here
  }
}

void PatientManagementSystem::run()
{
  printWelcomeMessage();

  bool running = true;
  while (running) {
    printMainMenu();
    int option = 0;
    cin >> option;

    // handle basic errors
    if (cin.bad()) {
      cin.clear();
      cin.ignore();
      continue;
    }

    // switch based on the selected option
    switch (option) {
    case 1:
      printPatients();
      break;
    case 2:
      addVitalsRecord();
      break;
    case 3:
      running = false;
      break;
    }
  }
}

void PatientManagementSystem::addVitalsRecord()
{
  cout << "Patients" << endl;
  printPatients();
  cout << endl;
  cout << "Enter the patient ID to declare vitals for > ";

  string pid{ "" };
  cin >> pid;
  if (_patientLookup.count(pid)) {
    float bodyTemperature;
    int bloodPressure;
    int heartRate;
    int respitoryRate;

    cout << "enter body temperature: ";
    cin >> bodyTemperature;
    cout << "enter blood pressure: ";
    cin >> bloodPressure;
    cout << "enter heart rate: ";
    cin >> heartRate;
    cout << "enter respitory rate: ";
    cin >> respitoryRate;

    Vitals* v = new Vitals(bodyTemperature, bloodPressure, heartRate, respitoryRate);
    _patientLookup[pid]->addVitals(v);

    // If the alarm level is red, send a notification message
    if (_patientLookup[pid]->alertLevel() == AlertLevel::Red) {
      _subject->notify(_patientLookup[pid]);
    }
  }
  else {
    cout << "Patient not found" << endl;
  }
}

void PatientManagementSystem::printWelcomeMessage() const
{
  cout << "WELCOME TO HEALTHCO 3000" << endl;
  cout << "------------------------" << endl;
}

void PatientManagementSystem::printMainMenu() const
{
  cout << endl << "Select an option:" << endl;
  cout << "1. List patients" << endl;
  cout << "2. Add vitals record" << endl;
  cout << "3. Quit" << endl;
  cout << "> ";
}

void PatientManagementSystem::printPatients() const
{
  for (Patient* p : _patients) {
    std::cout << *p << std::endl;
  }
}
