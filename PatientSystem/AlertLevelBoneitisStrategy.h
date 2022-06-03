#pragma once

#include "AlertLevelStrategy.h"

// Alarm Level Algorithm for Boneitis Disease

class AlertLevelBoneitisStrategy : public AlertLevelStrategy
{
public:
  virtual const void calculate(Patient* p, const Vitals* v) override;
};

