
#ifndef FAIR_EXT_PAR_H
#define FAIR_EXT_PAR_H

#include "TNamed.h"

class FairExtPar : public TNamed
{
  public:
    FairExtPar();
    
    FairExtPar(const char* name, Int_t channelId, Float_t zeroLevel, Float_t gain);

    virtual ~FairExtPar();
    
    void Print(Option_t* = "") const;
    
    const Int_t& GetChannelId() const { return fChannelId; }
    const Float_t& GetZeroLevel() const { return fZeroLevel; }
    const Float_t& GetGain() const { return fGain; }

  protected:
    Int_t fChannelId;
    Float_t fZeroLevel;
    Float_t fGain;
    
    ClassDef(FairExtPar, 1);
};

#endif //!FAIR_EXT_PAR_H
