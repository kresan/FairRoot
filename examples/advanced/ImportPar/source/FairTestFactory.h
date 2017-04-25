
#ifndef FAIR_TEST_FACTORY
#define FAIR_TEST_FACTORY

#include "FairContFact.h"

#include "Rtypes.h"

//class FairParSet;

class FairTestFactory : public FairContFact
{
  private:
    void setAllContainers();

  public:
    FairTestFactory();
    ~FairTestFactory() {}
    FairParSet* createContainer(FairContainer*);
    ClassDef(FairTestFactory, 1);
};

#endif //! FAIR_TEST_FACTORY
