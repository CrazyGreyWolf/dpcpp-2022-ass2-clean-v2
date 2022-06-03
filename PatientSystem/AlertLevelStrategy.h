#pragma once

#include "PatientAlertLevels.h"
#include "Vitals.h"
#include "Patient.h"

// The strategy class of the alarm level The parent class of the specific strategy


class AlertLevelStrategy
{
public:
  virtual const void calculate(Patient* p, const Vitals* v) = 0;
};

