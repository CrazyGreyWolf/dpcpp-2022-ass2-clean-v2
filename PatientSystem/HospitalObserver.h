#pragma once

#include "Observer.h"
#include "HospitalAlertSystemFacade.h"

// Observer Hospital

class HospitalObserver : public Observer
{
public:
  HospitalObserver(HospitalAlertSystemFacade* hospitalAlertSystemFacade);
  virtual void send(Patient* p) override;
private:
  HospitalAlertSystemFacade* _hospitalAlertSystemFacade;
};

