#pragma once

#include <memory>
#include <vector>

#include "AbstractPatientDatabaseLoader.h"
#include "Composite.h"

// tree node

class CompositeLoader : public Composite
{
public:
  void add(std::shared_ptr<Composite> composite);
  std::shared_ptr<Composite> get(int index);
  virtual void operation(std::vector<Patient*>& patientIn) override;
private:
  std::vector<std::shared_ptr<Composite>> _compositeVec;
};

