#pragma once

#include "AlertLevelStrategy.h"

// Alarm Level Algorithm for SimianFlu Disease


class AlertLevelSimianFluStrategy : public AlertLevelStrategy
{
public:
  virtual const void calculate(Patient* p, const Vitals* v) override;
};

