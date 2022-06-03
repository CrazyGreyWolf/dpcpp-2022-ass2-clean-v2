#include "AlertLevelContext.h"


const void AlertLevelContext::set(std::shared_ptr< AlertLevelStrategy> strategy)
{
  _strategy = strategy;
}

const void AlertLevelContext::calculate(Patient* p, const Vitals* v) const
{
  _strategy->calculate(p, v);
}

