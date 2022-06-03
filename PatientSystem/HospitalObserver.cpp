#include "HospitalObserver.h"


HospitalObserver::HospitalObserver(HospitalAlertSystemFacade* hospitalAlertSystemFacade)
  : _hospitalAlertSystemFacade(hospitalAlertSystemFacade)
{

}

void HospitalObserver::send(Patient* p)
{
  _hospitalAlertSystemFacade->sendAlertForPatient(p);
}
