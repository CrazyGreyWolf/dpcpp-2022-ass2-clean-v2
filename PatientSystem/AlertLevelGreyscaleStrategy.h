#pragma once

#include "AlertLevelStrategy.h"

// Algorithm for alarm levels of Greyscale disease


class AlertLevelGreyscaleStrategy : public AlertLevelStrategy
{
public:
  virtual const void calculate(Patient* p, const Vitals* v) override;
};

