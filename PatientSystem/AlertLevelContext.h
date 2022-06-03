#pragma once

#include <memory>
#include "AlertLevelStrategy.h"

// Context class for alarm level


class AlertLevelContext
{
public:
  const void set(std::shared_ptr< AlertLevelStrategy> strategy);
  const void calculate(Patient* p, const Vitals* v) const;
private:
  std::shared_ptr< AlertLevelStrategy> _strategy;
};

