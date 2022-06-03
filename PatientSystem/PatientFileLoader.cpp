#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>

#include "Patient.h"
#include "Vitals.h"

using namespace std;


inline const std::vector<std::string> split(const std::string& in, const std::string& delim)
{
  std::regex re{ delim };
  // call std::vector::vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type())
  // Constructor, completes string segmentation
  return std::vector<std::string> {
    std::sregex_token_iterator(in.begin(), in.end(), re, -1),
      std::sregex_token_iterator()
  };
}

std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
  vector<Patient*> patients{};

  std::ifstream inFile(file);
  if (inFile.is_open()) {

    std::string delim_field = "\\|";
    std::string delim_name = ",";
    std::string delim_value = ",";
    std::string delim_vital = ";";

    while (!inFile.eof()) {
      char szline[1024] = {};
      inFile.getline(szline, 1024);

      std::vector<std::string> vecFields = split(szline, delim_field);

      // split name
      std::vector<std::string> vecNames = split(vecFields.at(1), delim_name);

      // creation time
      std::tm t{ };
      std::istringstream ss(vecFields.at(2));
      ss >> std::get_time(&t, "%d-%m-%Y");

      // Read data content into vector
      Patient* patinet = new Patient(vecNames.at(0), vecNames.at(1), t);

      // Add Diagnosis
      patinet->addDiagnosis(vecFields.at(3));

      // split vital
      if (vecFields.size() == 5) {
        std::vector<std::string> vecVital = split(vecFields.at(4), delim_vital);

        for (string &item : vecVital)
        {
          // split vital value
          std::vector<std::string> vecValue = split(item, delim_value);
          Vitals* vital = new Vitals(std::stof(vecValue.at(0)), std::stoi(vecValue.at(1)), std::stoi(vecValue.at(2)), std::stoi(vecValue.at(3)));
          patinet->addVitals(vital);
        }
      }

      patients.push_back(patinet);
    }
  }

  return patients;
}
