#pragma once

#include <list>
#include <memory>

#include "Observer.h"
#include "Patient.h"

// Observer pattern implementation notification class

class Subject
{
public:
  void add(std::shared_ptr<Observer> observer);
  void notify(Patient* p);
private:
  std::list<std::shared_ptr<Observer>> _observerList;
};

