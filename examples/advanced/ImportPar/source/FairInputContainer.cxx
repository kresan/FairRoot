
#include "FairInputContainer.h"

#include "FairParIo.h"

#include "TObjArray.h"
#include "TDirectory.h"

FairInputContainer::FairInputContainer(const char* name, const char* title, const char* context)
    : FairParSet(name, title, context)
    , fArray(NULL)
{
}

FairInputContainer::~FairInputContainer(void) {}

void FairInputContainer::clear(void) {}

Bool_t FairInputContainer::init(FairParIo* par_io)
{
    par_io->cd();

    fArray = (TObjArray*)gDirectory->Get("TestContainer");

    if (NULL == fArray)
    {
        return kFALSE;
    }

    return kTRUE;
}

ClassImp(FairInputContainer);
