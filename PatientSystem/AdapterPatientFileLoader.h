#pragma once

#include <vector>
#include <memory>

#include "AbstractPatientDatabaseLoader.h"
#include "PatientFileLoader.h"

// Adapter mode, used to adapt AbstractPatientDatabaseLoader

class AdapterPatientFileLoader : public AbstractPatientDatabaseLoader
{
public:
  AdapterPatientFileLoader();
  // Inherited via AbstractPatientDatabaseLoader
  virtual void initialiseConnection() override;

  virtual void loadPatients(std::vector<Patient*>& patientIn) override;

  virtual void closeConnection() override;

private:
  std::unique_ptr< PatientFileLoader> _patientFileLoader;
};

