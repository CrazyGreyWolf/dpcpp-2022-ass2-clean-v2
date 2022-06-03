#include "Subject.h"


void Subject::add(std::shared_ptr<Observer> observer)
{
  _observerList.push_back(observer);
}

void Subject::notify(Patient* p)
{
  for (std::shared_ptr<Observer> observer : _observerList)
  {
    observer->send(p);
  }
}
