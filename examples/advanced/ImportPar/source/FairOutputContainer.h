
#ifndef FAIR_OUTPUT_CONTAINER
#define FAIR_OUTPUT_CONTAINER

#include "FairParGenericSet.h"

#include "Rtypes.h"

class TObjArray;
class FairParamList;

class FairOutputContainer : public FairParGenericSet
{
  public:
    FairOutputContainer(const char* name = "OutputContainer",
                      const char* title = "Test Container for input parameters",
                      const char* context = "TestDefaultContext");
    ~FairOutputContainer(void);

    void clear(void);
    void putParams(FairParamList*);
    Bool_t getParams(FairParamList*);

    TObjArray* GetArray() { return fArray; }
    
    void SetArray(TObjArray* arr) { fArray = arr; }

  protected:
    TObjArray* fArray;

    ClassDef(FairOutputContainer, 1)
};

#endif //! FAIR_OUTPUT_CONTAINER
