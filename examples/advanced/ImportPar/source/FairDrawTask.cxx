
#include "FairDrawTask.h"
#include "FairOutputContainer.h"
#include "FairExtPar.h"

#include "FairRuntimeDb.h"
#include "FairLogger.h"

#include "TH1F.h"

FairDrawTask::FairDrawTask()
    : FairTask("ReadParTask", 1)
    , fContainer(NULL)
{
}

FairDrawTask::~FairDrawTask() {}

void FairDrawTask::SetParContainers()
{
    fContainer = (FairOutputContainer*)FairRuntimeDb::instance()->getContainer("OutputContainer");
}

InitStatus FairDrawTask::Init()
{
    TObjArray* arr = fContainer->GetArray();
    LOG(INFO) << "DrawTask : Read array with " << arr->GetEntries() << " items" << FairLogger::endl;

    fh_zerolevel = new TH1F("h_zerolevel", "", 120, -0.1, 1.1);
    fh_gain = new TH1F("h_gain", "", 200, 0., 2.);

    FairExtPar* par = NULL;
    for (Int_t i = 0; i < fContainer->GetArray()->GetEntriesFast(); i++)
    {
        par = (FairExtPar*)fContainer->GetArray()->At(i);
        fh_zerolevel->Fill(par->GetZeroLevel());
        fh_gain->Fill(par->GetGain());
    }

    return kSUCCESS;
}

void FairDrawTask::Exec(Option_t*) {}

void FairDrawTask::FinishTask()
{
    fh_zerolevel->Write();
    fh_gain->Write();
}

ClassImp(FairDrawTask);
