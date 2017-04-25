
#include "FairExtPar.h"
#include "FairLogger.h"

FairExtPar::FairExtPar()
    : TNamed("FairExtPar", "Input Parameters")
    , fChannelId(-1)
    , fZeroLevel(0.)
    , fGain(1.)
{
}

FairExtPar::FairExtPar(const char* name, Int_t channelId, Float_t zeroLevel, Float_t gain)
    : TNamed(name, "Input Parameters")
    , fChannelId(channelId)
    , fZeroLevel(zeroLevel)
    , fGain(gain)
{
}

FairExtPar::~FairExtPar() {}

void FairExtPar::Print(Option_t*) const
{
    LOG(INFO) << fName << " " << fChannelId << " : " << fZeroLevel << " / " << fGain << FairLogger::endl;
}

ClassImp(FairExtPar);
