#include "GPObserver.h"



GPObserver::GPObserver(GPNotificationSystemFacade * gpNotificationSystemFacade)
  : _gpNotificationSystemFacade(gpNotificationSystemFacade)
{
}

void GPObserver::send(Patient* p)
{
  _gpNotificationSystemFacade->sendGPNotificationForPatient(p);
}
