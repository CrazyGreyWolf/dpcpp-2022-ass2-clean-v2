#pragma once

#include "Observer.h"
#include "GPNotificationSystemFacade.h"

// observer GP

class GPObserver : public Observer
{
public:
  GPObserver(GPNotificationSystemFacade * gpNotificationSystemFacade);
  virtual void send(Patient* p) override;

private:
  GPNotificationSystemFacade * _gpNotificationSystemFacade;
};

