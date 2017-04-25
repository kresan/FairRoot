
#ifndef FAIR_READ_PAR_TASK
#define FAIR_READ_PAR_TASK

#include "FairTask.h"

class FairInputContainer;
class FairOutputContainer;

class FairReadParTask : public FairTask
{
  public:
    FairReadParTask();

    ~FairReadParTask();

    void SetParContainers();

    InitStatus Init();

    void Exec(Option_t* = "");

    void FinishTask();

  private:
    FairInputContainer* fInputContainer;   //!
    FairOutputContainer* fOutputContainer; //!

    ClassDef(FairReadParTask, 1);
};

#endif //! FAIR_READ_PAR_TASK
