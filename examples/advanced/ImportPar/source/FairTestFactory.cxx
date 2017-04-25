
#include "FairTestFactory.h"

#include "FairRuntimeDb.h"
#include "FairInputContainer.h"
#include "FairOutputContainer.h"

#include "TList.h"
#include "TString.h"

#include <string.h>

// class FairParSet;

ClassImp(FairTestFactory)

    static FairTestFactory gFairTestFactory;

FairTestFactory::FairTestFactory()
    : FairContFact()
{
    /** Constructor (called when the library is loaded) */
    fName = "FairTestFactory";
    fTitle = "Factory for parameter containers in ImportPar";
    setAllContainers();
    FairRuntimeDb::instance()->addContFactory(this);
}

void FairTestFactory::setAllContainers()
{
    /** Creates the Container objects with all accepted
     contexts and adds them to
     the list of containers for the Tutorial1 library.
     */

    FairContainer* p1 = new FairContainer("InputContainer", "TObjArray of TNamed", "TestDefaultContext");
    p1->addContext("TestNonDefaultContext");
    
    FairContainer* p2 = new FairContainer("OutputContainer", "TObjArray of TNamed", "TestDefaultContext");
    p2->addContext("TestNonDefaultContext");

    containers->Add(p1);
    containers->Add(p2);
}

FairParSet* FairTestFactory::createContainer(FairContainer* c)
{
    /** Calls the constructor of the corresponding parameter container.
     For an actual context, which is not an empty string and not
     the default context
     of this container, the name is concatinated with the context.
     */
    const char* name = c->GetName();
    FairParSet* p = NULL;
    if (strcmp(name, "InputContainer") == 0)
    {
        p = new FairInputContainer(c->getConcatName().Data(), c->GetTitle(), c->getContext());
    }
    else if (strcmp(name, "OutputContainer") == 0)
    {
        p = new FairOutputContainer(c->getConcatName().Data(), c->GetTitle(), c->getContext());
    }
    return p;
}
