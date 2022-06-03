#include "AlertLevelGreyscaleStrategy.h"


const void AlertLevelGreyscaleStrategy::calculate(Patient* p, const Vitals* v)
{

  // calculate level
  if (((p->age() < 12) && (v->HR() > 120)) || ((p->age() >= 12) && (v->HR() > 100))) {
    p->setAlertLevel(AlertLevel::Red);
  }
  else {
    p->setAlertLevel(AlertLevel::Green);
  }
}
