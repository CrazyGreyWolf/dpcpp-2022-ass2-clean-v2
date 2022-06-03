#pragma once

#include <vector>

#include "Composite.h"
#include "AbstractPatientDatabaseLoader.h"

// leaf node

class CompositeLoaderLeaf : public Composite
{
public:
  CompositeLoaderLeaf(AbstractPatientDatabaseLoader* loader);
  virtual void operation(std::vector<Patient*>& patientIn) override;

private:
  AbstractPatientDatabaseLoader* _loader;
};

