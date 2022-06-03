#pragma once

#include <vector>
#include <memory>

#include "Patient.h"

// Parent class of Composite pattern

class Composite
{
public:
  void add(std::shared_ptr<Composite> composite) {};
  std::shared_ptr<Composite> get(int index) { return nullptr; };
  virtual void operation(std::vector<Patient*>& patientIn) = 0;
};

