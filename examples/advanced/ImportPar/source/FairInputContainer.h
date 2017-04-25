
#ifndef FAIR_INPUT_CONTAINER
#define FAIR_INPUT_CONTAINER

#include "FairParSet.h"

#include "Rtypes.h"

class TObjArray;

class FairInputContainer : public FairParSet
{
  public:
    FairInputContainer(const char* name = "InputContainer",
                      const char* title = "Test Container for input parameters",
                      const char* context = "TestDefaultContext");
    ~FairInputContainer(void);

    void clear(void);

    TObjArray* GetArray() { return fArray; }
    
    Bool_t init(FairParIo*);

  protected:
    TObjArray* fArray;

    ClassDef(FairInputContainer, 1)
};

#endif //! FAIR_INPUT_CONTAINER
