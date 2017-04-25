void generate_input()
{
    // Initialize random number generator
    TRandom3* random = new TRandom3(11111);

    // Create the file
    TFile* file = new TFile("input_par.root", "RECREATE");

    // Create array for storing the objects
    TObjArray* array = new TObjArray();

    FairExtPar* par = NULL;
    Float_t zeroLevel = 0.;
    Float_t gain = 0.;

    // Create parameters
    for (Int_t i = 0; i < 1000; i++)
    {
        // Generate dummy values
        zeroLevel = random->Uniform(0.1, 0.9);
        gain = random->Gaus(1., 0.1);
        // Create container
        par = new FairExtPar(Form("par_%d", i), i + 1, zeroLevel, gain);
        // Add to array
        array->Add(par);
    }

    // Write array to the file as a single key
    array->Write("TestContainer", TObject::kSingleKey);

    cout << "INFO : parameters generated" << endl;

    file->Close();
}
