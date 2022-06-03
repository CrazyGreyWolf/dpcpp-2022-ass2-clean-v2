#include "CompositeLoader.h"

void CompositeLoader::add(std::shared_ptr<Composite> composite)
{
  // add to the list object
  _compositeVec.push_back(composite);
}

std::shared_ptr<Composite> CompositeLoader::get(int index)
{
  return _compositeVec.at(index);
}

void CompositeLoader::operation(std::vector<Patient*>& patientIn)
{
  // perform all operations
  for (std::shared_ptr<Composite> composite : _compositeVec)
  {
    composite->operation(patientIn);
  }
}
