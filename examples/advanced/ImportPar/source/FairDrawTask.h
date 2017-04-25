
#ifndef FAIR_DRAW_TASK
#define FAIR_DRAW_TASK

#include "FairTask.h"

class FairOutputContainer;
class TH1F;

class FairDrawTask : public FairTask
{
  public:
    FairDrawTask();

    ~FairDrawTask();

    void SetParContainers();

    InitStatus Init();

    void Exec(Option_t* = "");

    void FinishTask();

  private:
    FairOutputContainer* fContainer; //!
    TH1F* fh_zerolevel; //!
    TH1F* fh_gain; //!
    
    ClassDef(FairDrawTask, 1);
};

#endif //! FAIR_DRAW_TASK
