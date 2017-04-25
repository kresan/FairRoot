void main_macro()
{
    // File names
    TString parFileIn = "input_par.root";
    TString parFile = "output_par.root";
    TString outputFile = "test.root";
    
    // Create run manager ------------------------------------------------------
    FairRunAna* run = new FairRunAna();
    // Set the output file for data
    run->SetOutputFile(outputFile);
    
    // Add task for import of the parameters
    run->AddTask(new FairReadParTask());
    
    // Add example user task
    run->AddTask(new FairDrawTask());
    
    // Get the parameter manager -----------------------------------------------
    FairRuntimeDb* rtdb = FairRuntimeDb::instance();
    // Open input file
    FairParRootFileIo* io1 = new FairParRootFileIo();
    io1->open(parFileIn);
    // Open output file
    FairParRootFileIo* out = new FairParRootFileIo(kTRUE);
    out->open(parFile);
    // Set input and output to parameter manager
    rtdb->setFirstInput(io1);
    rtdb->setOutput(out);
    
    // Initialize --------------------------------------------------------------
    run->Init();
    
    // Execute event loop ------------------------------------------------------
    run->Run();
    
    // Save containers
    rtdb->saveOutput();
    // Debug output
    rtdb->print();
}
