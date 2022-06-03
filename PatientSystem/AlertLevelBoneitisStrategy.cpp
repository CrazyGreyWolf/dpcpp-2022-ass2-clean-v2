#include "AlertLevelBoneitisStrategy.h"



const void AlertLevelBoneitisStrategy::calculate(Patient* p, const Vitals* v)
{
  // calculate level
  if (v->RR() > 40) {
    p->setAlertLevel(AlertLevel::Red);
  }
  else if (v->RR() > 30) {
    p->setAlertLevel(AlertLevel::Orange);
  }
  else if (v->RR() > 20) {
    p->setAlertLevel(AlertLevel::Yellow);
  }
  else {
    p->setAlertLevel(AlertLevel::Green);
  }
}
