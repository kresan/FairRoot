
#include "FairReadParTask.h"
#include "FairInputContainer.h"
#include "FairOutputContainer.h"
#include "FairRuntimeDb.h"
#include "FairLogger.h"

FairReadParTask::FairReadParTask()
    : FairTask("ReadParTask", 1)
    , fInputContainer(NULL)
    , fOutputContainer(NULL)
{
}

FairReadParTask::~FairReadParTask() {}

void FairReadParTask::SetParContainers()
{
    fInputContainer = (FairInputContainer*)FairRuntimeDb::instance()->getContainer("InputContainer");
    fOutputContainer = (FairOutputContainer*)FairRuntimeDb::instance()->getContainer("OutputContainer");
}

InitStatus FairReadParTask::Init()
{
    LOG(INFO) << "ReadParTask : Read array with " << fInputContainer->GetArray()->GetEntries() << " items" << FairLogger::endl;
    
    fOutputContainer->SetArray(fInputContainer->GetArray());
    fOutputContainer->setChanged();

    return kSUCCESS;
}

void FairReadParTask::Exec(Option_t*) {}

void FairReadParTask::FinishTask() {}

ClassImp(FairReadParTask);
