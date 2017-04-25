
#include "FairOutputContainer.h"

#include "FairParIo.h"
#include "FairParamList.h"

#include "TObjArray.h"
#include "TDirectory.h"

FairOutputContainer::FairOutputContainer(const char* name, const char* title, const char* context)
    : FairParGenericSet(name, title, context)
    , fArray(new TObjArray())
{
}

FairOutputContainer::~FairOutputContainer(void) {}

void FairOutputContainer::clear(void) { delete fArray; }

void FairOutputContainer::putParams(FairParamList* l)
{
    if (!l)
    {
        return;
    }
    l->addObject("TObjArray of TNamed", fArray);
}

Bool_t FairOutputContainer::getParams(FairParamList* l)
{
    if (!l)
    {
        return kFALSE;
    }
    if (!l->fillObject("TObjArray of TNamed", fArray))
    {
        return kFALSE;
    }
    return kTRUE;
}

ClassImp(FairOutputContainer);
