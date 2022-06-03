#include "AdapterPatientFileLoader.h"

// Initialization file loading class
AdapterPatientFileLoader::AdapterPatientFileLoader() :
  _patientFileLoader(std::make_unique<PatientFileLoader>())
{

}

void AdapterPatientFileLoader::initialiseConnection()
{
  // do nothing
}

void AdapterPatientFileLoader::loadPatients(std::vector<Patient*>& patientIn)
{
  // load file content
  std::string file = "patients.txt";
  std::vector<Patient*> patientTemp = _patientFileLoader->loadPatientFile(file);

  // Append data to vector
  for (Patient* item : patientTemp)
  {
    patientIn.push_back(item);
  }
}

void AdapterPatientFileLoader::closeConnection()
{
  // do nothing
}
