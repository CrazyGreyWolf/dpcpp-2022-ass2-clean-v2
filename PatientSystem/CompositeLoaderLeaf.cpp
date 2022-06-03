#include "CompositeLoaderLeaf.h"

CompositeLoaderLeaf::CompositeLoaderLeaf(AbstractPatientDatabaseLoader* loader)
  : _loader(loader)
{

}

void CompositeLoaderLeaf::operation(std::vector<Patient*>& patientIn)
{
  // Download Data
  _loader->loadPatients(patientIn);
}
