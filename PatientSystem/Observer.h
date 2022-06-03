#pragma once

#include "Patient.h"

// Observer's parent class

class Observer
{
public:
  virtual void send(Patient* p) = 0;
};
