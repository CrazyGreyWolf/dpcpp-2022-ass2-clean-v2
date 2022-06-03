#include "AlertLevelSimianFluStrategy.h"

const void AlertLevelSimianFluStrategy::calculate(Patient* p, const Vitals* v)
{

  // calculate level
  if (v->BP() > 140) {
    p->setAlertLevel(AlertLevel::Red);
  }
  else if (v->BP() > 130) {
    p->setAlertLevel(AlertLevel::Orange);
  }
  else if (v->BP() > 110) {
    p->setAlertLevel(AlertLevel::Yellow);
  }
  else {
    p->setAlertLevel(AlertLevel::Green);
  }
}
