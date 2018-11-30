#include "TROOT.h"

void PrepareFakeRateForCombine(string IsoWorkingPoint)
{
  TFile* PassFailFile = new TFile("../Distributions/PassFailOut.root");
  TDirectory* passDirectory = (TDirectory*) PassFailFile->Get("pass");
  
  TH1F* Data_Pass = (TH1F*) passDirectory->Get("Data_Pass");
  
  std::cout<<"Loading the ZMT Histograms"<<std::endl;

  TH1F* ZTauTau_Pass = (TH1F*) passDirectory->Get("GenMatch_DY_Pass");
  TH1F* ZTauTau1_Pass = (TH1F*) passDirectory->Get("GenMatch_DY1_Pass");
  TH1F* ZTauTau2_Pass = (TH1F*) passDirectory->Get("GenMatch_DY2_Pass");
  TH1F* ZTauTau3_Pass = (TH1F*) passDirectory->Get("GenMatch_DY3_Pass");
  TH1F* ZTauTau4_Pass = (TH1F*) passDirectory->Get("GenMatch_DY4_Pass");
  TH1F* LowGenMatch_DY_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY_Pass");
  TH1F* LowGenMatch_DY1_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY1_Pass");
  TH1F* LowGenMatch_DY2_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY2_Pass");
  TH1F* LowGenMatch_DY3_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY3_Pass");
  TH1F* LowGenMatch_DY4_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY4_Pass");
  TH1F* HighGenMatch_DY_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY_Pass");
  TH1F* HighGenMatch_DY1_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY1_Pass");
  TH1F* HighGenMatch_DY2_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY2_Pass");
  TH1F* HighGenMatch_DY3_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY3_Pass");
  TH1F* HighGenMatch_DY4_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY4_Pass");

  TH1F* TTTo2L2Nu_Pass = (TH1F*) passDirectory->Get("TTTo2L2Nu_Pass");
  TH1F* TTToHadronic_Pass = (TH1F*) passDirectory->Get("TTToHadronic_Pass");
  TH1F* TTToSemiLeptonic_Pass = (TH1F*) passDirectory->Get("TTToSemiLeptonic_Pass");  
  
  TH1F* WW_Pass = (TH1F*) passDirectory->Get("WW_Pass");
  TH1F* WZ_Pass = (TH1F*) passDirectory->Get("WZ_Pass");
  TH1F* ZZ_Pass = (TH1F*) passDirectory->Get("ZZ_Pass");

  //get the TES uncertainty for the Real Tau Distributions
  
  TH1F* ZTauTau_TES_UP_Pass = (TH1F*) passDirectory->Get("GenMatch_DY_1.030000_Pass");
  TH1F* ZTauTau1_TES_UP_Pass = (TH1F*) passDirectory->Get("GenMatch_DY1_1.030000_Pass");
  TH1F* ZTauTau2_TES_UP_Pass = (TH1F*) passDirectory->Get("GenMatch_DY2_1.030000_Pass");
  TH1F* ZTauTau3_TES_UP_Pass = (TH1F*) passDirectory->Get("GenMatch_DY3_1.030000_Pass");
  TH1F* ZTauTau4_TES_UP_Pass = (TH1F*) passDirectory->Get("GenMatch_DY4_1.030000_Pass");
  TH1F* ZTauTau_TES_DOWN_Pass = (TH1F*) passDirectory->Get("GenMatch_DY_0.970000_Pass");
  TH1F* ZTauTau1_TES_DOWN_Pass = (TH1F*) passDirectory->Get("GenMatch_DY1_0.970000_Pass");
  TH1F* ZTauTau2_TES_DOWN_Pass = (TH1F*) passDirectory->Get("GenMatch_DY2_0.970000_Pass");
  TH1F* ZTauTau3_TES_DOWN_Pass = (TH1F*) passDirectory->Get("GenMatch_DY3_0.970000_Pass");
  TH1F* ZTauTau4_TES_DOWN_Pass = (TH1F*) passDirectory->Get("GenMatch_DY4_0.970000_Pass");

  //mu to tau fake shape uncertainty
  TH1F* LowGenMatch_DY_Shape_UP_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY_1.100000_Pass");
  TH1F* LowGenMatch_DY1_Shape_UP_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY1_1.100000_Pass");
  TH1F* LowGenMatch_DY2_Shape_UP_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY2_1.100000_Pass");
  TH1F* LowGenMatch_DY3_Shape_UP_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY3_1.100000_Pass");
  TH1F* LowGenMatch_DY4_Shape_UP_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY4_1.100000_Pass");
  TH1F* LowGenMatch_DY_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY_0.900000_Pass");
  TH1F* LowGenMatch_DY1_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY1_0.900000_Pass");
  TH1F* LowGenMatch_DY2_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY2_0.900000_Pass");
  TH1F* LowGenMatch_DY3_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY3_0.900000_Pass");
  TH1F* LowGenMatch_DY4_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("LowGenMatch_DY4_0.900000_Pass");

  LowGenMatch_DY_Shape_UP_Pass->Add(LowGenMatch_DY1_Shape_UP_Pass);
  LowGenMatch_DY_Shape_UP_Pass->Add(LowGenMatch_DY2_Shape_UP_Pass);
  LowGenMatch_DY_Shape_UP_Pass->Add(LowGenMatch_DY3_Shape_UP_Pass);
  LowGenMatch_DY_Shape_UP_Pass->Add(LowGenMatch_DY4_Shape_UP_Pass);
  LowGenMatch_DY_Shape_DOWN_Pass->Add(LowGenMatch_DY1_Shape_DOWN_Pass);
  LowGenMatch_DY_Shape_DOWN_Pass->Add(LowGenMatch_DY2_Shape_DOWN_Pass);
  LowGenMatch_DY_Shape_DOWN_Pass->Add(LowGenMatch_DY3_Shape_DOWN_Pass);
  LowGenMatch_DY_Shape_DOWN_Pass->Add(LowGenMatch_DY4_Shape_DOWN_Pass);

  //Get the fake rates determined stuff
  TFile* FakeRateDeterminedDistributions = new TFile("../Distributions/FakeRateDeterminedDistributions.root");
  TH1F* JetDistribution; 
  TH1F* JetDistribution_DecayMode0_DOWN;
  TH1F* JetDistribution_DecayMode0_UP;
  TH1F* JetDistribution_DecayMode1_DOWN;
  TH1F* JetDistribution_DecayMode1_UP;
  TH1F* JetDistribution_DecayMode10_DOWN;
  TH1F* JetDistribution_DecayMode10_UP;
  assert(IsoWorkingPoint == "VLoose" ||
	 IsoWorkingPoint == "Loose" ||
	 IsoWorkingPoint == "Medium" ||
	 IsoWorkingPoint == "Tight" ||
	 IsoWorkingPoint == "VTight" ||
	 IsoWorkingPoint == "VVTight");
  if(IsoWorkingPoint == "VLoose")
    {	
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("VLoosePTFRJetDistribution");      
      JetDistribution_DecayMode0_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VLooseDecayMode0LowJetDistribution");
      JetDistribution_DecayMode0_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VLooseDecayMode0HighJetDistribution");
      JetDistribution_DecayMode1_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VLooseDecayMode1LowJetDistribution");
      JetDistribution_DecayMode1_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VLooseDecayMode1HighJetDistribution");
      JetDistribution_DecayMode10_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VLooseDecayMode1LowJetDistribution");
      JetDistribution_DecayMode10_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VLooseDecayMode1HighJetDistribution");
    }
  else if(IsoWorkingPoint == "Loose")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("LoosePTFRJetDistribution");
      JetDistribution_DecayMode0_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("LooseDecayMode0LowJetDistribution");
      JetDistribution_DecayMode0_UP = (TH1F*) FakeRateDeterminedDistributions->Get("LooseDecayMode0HighJetDistribution");
      JetDistribution_DecayMode1_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("LooseDecayMode1LowJetDistribution");
      JetDistribution_DecayMode1_UP = (TH1F*) FakeRateDeterminedDistributions->Get("LooseDecayMode1HighJetDistribution");
      JetDistribution_DecayMode10_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("LooseDecayMode1LowJetDistribution");
      JetDistribution_DecayMode10_UP = (TH1F*) FakeRateDeterminedDistributions->Get("LooseDecayMode1HighJetDistribution");
    }
  else if(IsoWorkingPoint == "Medium")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("MediumPTFRJetDistribution");      
      JetDistribution_DecayMode0_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("MediumDecayMode0LowJetDistribution");
      JetDistribution_DecayMode0_UP = (TH1F*) FakeRateDeterminedDistributions->Get("MediumDecayMode0HighJetDistribution");
      JetDistribution_DecayMode1_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("MediumDecayMode1LowJetDistribution");
      JetDistribution_DecayMode1_UP = (TH1F*) FakeRateDeterminedDistributions->Get("MediumDecayMode1HighJetDistribution");
      JetDistribution_DecayMode10_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("MediumDecayMode1LowJetDistribution");
      JetDistribution_DecayMode10_UP = (TH1F*) FakeRateDeterminedDistributions->Get("MediumDecayMode1HighJetDistribution");
    }
  else if(IsoWorkingPoint == "Tight")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("TightPTFRJetDistribution");      
      JetDistribution_DecayMode0_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("TightDecayMode0LowJetDistribution");
      JetDistribution_DecayMode0_UP = (TH1F*) FakeRateDeterminedDistributions->Get("TightDecayMode0HighJetDistribution");
      JetDistribution_DecayMode1_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("TightDecayMode1LowJetDistribution");
      JetDistribution_DecayMode1_UP = (TH1F*) FakeRateDeterminedDistributions->Get("TightDecayMode1HighJetDistribution");
      JetDistribution_DecayMode10_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("TightDecayMode1LowJetDistribution");
      JetDistribution_DecayMode10_UP = (TH1F*) FakeRateDeterminedDistributions->Get("TightDecayMode1HighJetDistribution");
    }
  else if(IsoWorkingPoint == "VTight")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("VTightPTFRJetDistribution");      
      JetDistribution_DecayMode0_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VTightDecayMode0LowJetDistribution");
      JetDistribution_DecayMode0_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VTightDecayMode0HighJetDistribution");
      JetDistribution_DecayMode1_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VTightDecayMode1LowJetDistribution");
      JetDistribution_DecayMode1_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VTightDecayMode1HighJetDistribution");
      JetDistribution_DecayMode10_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VTightDecayMode1LowJetDistribution");
      JetDistribution_DecayMode10_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VTightDecayMode1HighJetDistribution");
    }
  else if(IsoWorkingPoint == "VVTight")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightPTFRJetDistribution");      
      JetDistribution_DecayMode0_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightDecayMode0LowJetDistribution");
      JetDistribution_DecayMode0_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightDecayMode0HighJetDistribution");
      JetDistribution_DecayMode1_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightDecayMode1LowJetDistribution");
      JetDistribution_DecayMode1_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightDecayMode1HighJetDistribution");
      JetDistribution_DecayMode10_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightDecayMode1LowJetDistribution");
      JetDistribution_DecayMode10_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightDecayMode1HighJetDistribution");
    }    

  std::cout<<"Simplifying the DY Histos"<<std::endl;
  //pass compiling  
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY1_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY2_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY3_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY4_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY1_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY2_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY3_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY4_Pass);

  ZTauTau_Pass->Add(ZTauTau1_Pass);
  ZTauTau_Pass->Add(ZTauTau2_Pass);
  ZTauTau_Pass->Add(ZTauTau3_Pass);
  ZTauTau_Pass->Add(ZTauTau4_Pass);

  ZTauTau_TES_UP_Pass->Add(ZTauTau1_TES_UP_Pass);
  ZTauTau_TES_UP_Pass->Add(ZTauTau2_TES_UP_Pass);
  ZTauTau_TES_UP_Pass->Add(ZTauTau3_TES_UP_Pass);
  ZTauTau_TES_UP_Pass->Add(ZTauTau4_TES_UP_Pass);
  ZTauTau_TES_DOWN_Pass->Add(ZTauTau1_TES_DOWN_Pass);
  ZTauTau_TES_DOWN_Pass->Add(ZTauTau2_TES_DOWN_Pass);
  ZTauTau_TES_DOWN_Pass->Add(ZTauTau3_TES_DOWN_Pass);
  ZTauTau_TES_DOWN_Pass->Add(ZTauTau4_TES_DOWN_Pass);

  std::cout<<"Loading the ZMM Region..."<<std::endl;
  TFile* ZMuMuFile = new TFile("../Distributions/ZMuMu.root");
  TH1F* Data_MuMu = (TH1F*) ZMuMuFile->Get("Data");

  TH1F* DY1_MuMu = (TH1F*) ZMuMuFile->Get("DY1");
  TH1F* DY2_MuMu = (TH1F*) ZMuMuFile->Get("DY2");
  TH1F* DY3_MuMu = (TH1F*) ZMuMuFile->Get("DY3");
  TH1F* DY4_MuMu = (TH1F*) ZMuMuFile->Get("DY4");
  TH1F* DY_MuMu = (TH1F*) ZMuMuFile->Get("DY");
  
  //are these really necessary?
  TH1F* TTTo2L2Nu_MuMu = (TH1F*) ZMuMuFile->Get("TTTo2L2Nu");
  TH1F* TTToHadronic_MuMu = (TH1F*) ZMuMuFile->Get("TTToHadronic");
  TH1F* TTToSemiLeptonic_MuMu = (TH1F*) ZMuMuFile->Get("TTToSemiLeptonic");

  TH1F* WW_MuMu = (TH1F*) ZMuMuFile->Get("WW");
  TH1F* WZ_MuMu = (TH1F*) ZMuMuFile->Get("WZ");
  TH1F* ZZ_MuMu = (TH1F*) ZMuMuFile->Get("ZZ");

  //These moreso
  TH1F* W_MuMu = (TH1F*) ZMuMuFile->Get("W");
  TH1F* W1_MuMu = (TH1F*) ZMuMuFile->Get("W1");
  TH1F* W2_MuMu = (TH1F*) ZMuMuFile->Get("W2");
  TH1F* W3_MuMu = (TH1F*) ZMuMuFile->Get("W3");
  TH1F* W4_MuMu = (TH1F*) ZMuMuFile->Get("W4");
  
  TH1F* QCD_MuMu = (TH1F*) ZMuMuFile->Get("QCD");

  DY_MuMu->Add(DY1_MuMu);
  DY_MuMu->Add(DY2_MuMu);
  DY_MuMu->Add(DY3_MuMu);
  DY_MuMu->Add(DY4_MuMu);

  W_MuMu->Add(W1_MuMu);
  W_MuMu->Add(W2_MuMu);
  W_MuMu->Add(W3_MuMu);
  W_MuMu->Add(W4_MuMu);

  //no longer necessary?
  /*

  std::cout<<"Performing Prescale For ZMM region..."<<std::endl;
  std::cout<<"ZMM DY Integral: "<<DY_MuMu->Integral()<<std::endl;
  std::cout<<"ZMM Data Integral: "<<Data_MuMu->Integral()<<std::endl;
  float PrescaleFactor = Data_MuMu->Integral()/DY_MuMu->Integral();
  std::cout<<"DY Prescaling Factor: "<<PrescaleFactor<<std::endl;
  DY_MuMu->Scale(PrescaleFactor);
  ZTauTau_Pass->Scale(PrescaleFactor);
  LowGenMatch_DY_Pass->Scale(PrescaleFactor);
  HighGenMatch_DY_Pass->Scale(PrescaleFactor);
  */

  std::cout<<"Preparing the Zmt region."<<std::endl;

  TFile* CombineFile = new TFile(("../Distributions/"+IsoWorkingPoint+"FakeRateCombineFile.root").c_str(),"RECREATE");
  TDirectory* ZMTDirectory = CombineFile->mkdir("zmt");
  ZMTDirectory->cd();
  
  std::cout<<"Processing Histos..."<<std::endl;

  std::cout<<"processing data..."<<std::endl;
  
  Data_Pass->SetNameTitle("data_obs","data_obs");
  Data_Pass->Write();

  std::cout<<"DYB..."<<std::endl;
  
  LowGenMatch_DY_Pass->SetNameTitle("DYB","DYB");
  LowGenMatch_DY_Pass->Write();

  LowGenMatch_DY_Shape_UP_Pass->SetNameTitle("DYB_muToTauUp","DYB_muToTauUp");
  LowGenMatch_DY_Shape_UP_Pass->Write();

  LowGenMatch_DY_Shape_DOWN_Pass->SetNameTitle("DYB_muToTauDown","DYB_muToTauDown");
  LowGenMatch_DY_Shape_DOWN_Pass->Write();

  std::cout<<"DYJ..."<<std::endl;

  HighGenMatch_DY_Pass->SetNameTitle("DYJ","DYJ");
  HighGenMatch_DY_Pass->Write();
  
  std::cout<<"DYS"<<std::endl;

  ZTauTau_Pass->SetNameTitle("DYS","DYS");  
  ZTauTau_Pass->Write();

  ZTauTau_TES_UP_Pass->SetNameTitle("DYS_TESUp","DYS_TESUp");
  ZTauTau_TES_UP_Pass->Write();

  ZTauTau_TES_DOWN_Pass->SetNameTitle("DYS_TESDown","DYS_TESDown");
  ZTauTau_TES_DOWN_Pass->Write();

  std::cout<<"TTbar..."<<std::endl;

  TH1F* TT_Pass = new TH1F("TT",
			   "TT",
			   TTTo2L2Nu_Pass->GetSize()-2,
			   TTTo2L2Nu_Pass->GetXaxis()->GetXmin(),
			   TTTo2L2Nu_Pass->GetXaxis()->GetXmax());
  TT_Pass->Add(TTTo2L2Nu_Pass,TTToHadronic_Pass);
  TT_Pass->Add(TTToSemiLeptonic_Pass);
  TT_Pass->Write();
  
  std::cout<<"Diboson..."<<std::endl;

  TH1F* DiBoson_Pass = new TH1F("VV",
				"VV",
				WW_Pass->GetSize()-2,
				WW_Pass->GetXaxis()->GetXmin(),
				WW_Pass->GetXaxis()->GetXmax());
  DiBoson_Pass->Add(WW_Pass,WZ_Pass);
  DiBoson_Pass->Add(ZZ_Pass);
  DiBoson_Pass->Write();

  std::cout<<"Jets..."<<std::endl;

  JetDistribution->SetNameTitle("Jets","Jets");
  JetDistribution->Write();

  JetDistribution_DecayMode0_DOWN->SetNameTitle("Jets_DM0FakeRateUncertaintyDown","Jets_DM0FakeRateUncertaintyDown");
  JetDistribution_DecayMode0_DOWN->Write();

  JetDistribution_DecayMode0_UP->SetNameTitle("Jets_DM0FakeRateUncertaintyUp","Jets_DM0FakeRateUncertaintyUp");
  JetDistribution_DecayMode0_UP->Write();

  JetDistribution_DecayMode1_DOWN->SetNameTitle("Jets_DM1FakeRateUncertaintyDown","Jets_DM1FakeRateUncertaintyDown");
  JetDistribution_DecayMode1_DOWN->Write();

  JetDistribution_DecayMode1_UP->SetNameTitle("Jets_DM1FakeRateUncertaintyUp","Jets_DM1FakeRateUncertaintyUp");
  JetDistribution_DecayMode1_UP->Write();

  JetDistribution_DecayMode10_DOWN->SetNameTitle("Jets_DM10FakeRateUncertaintyDown","Jets_DM10FakeRateUncertaintyDown");
  JetDistribution_DecayMode10_DOWN->Write();

  JetDistribution_DecayMode10_UP->SetNameTitle("Jets_DM10FakeRateUncertaintyUp","Jets_DM10FakeRateUncertaintyUp");
  JetDistribution_DecayMode10_UP->Write();
  
  std::cout<<"Preparing the Zmm region"<<std::endl;  
  TDirectory* ZMMDirectory = CombineFile->mkdir("zmm");
  ZMMDirectory->cd();  

  Data_MuMu->SetNameTitle("data_obs","data_obs");
  Data_MuMu->Write();

  DY_MuMu->SetNameTitle("DYB","DYB");
  DY_MuMu->Write();
  //let's try pulling these out again temporarily now that the
  //prescaling has made combine a bit firendlier.
  TH1F* TT_MuMu = new TH1F("TT",
			   "TT",
			   TTTo2L2Nu_MuMu->GetSize()-2,
			   TTTo2L2Nu_MuMu->GetXaxis()->GetXmin(),
			   TTTo2L2Nu_MuMu->GetXaxis()->GetXmax());
  TT_MuMu->Add(TTTo2L2Nu_MuMu,TTToHadronic_MuMu);
  TT_MuMu->Add(TTToSemiLeptonic_MuMu);
  TT_MuMu->Write();
  
  TH1F* DiBoson_MuMu = new TH1F("VV",
				"VV",
				WW_MuMu->GetSize()-2,
				WW_MuMu->GetXaxis()->GetXmin(),
				WW_MuMu->GetXaxis()->GetXmax());
  DiBoson_MuMu->Add(WW_MuMu,WZ_MuMu);
  DiBoson_MuMu->Add(ZZ_MuMu);
  DiBoson_MuMu->Write();
  // pull a temporary thing where we include a temporary "jets" into the ZMM region
  // for the sake of having the same distributions as the ZMT region
  // and then we'll also include empty "DYB" and "DYJ" regions as well.

  TH1F* Jets_MuMu = new TH1F("Jets",
			     "Jets",
			     DY_MuMu->GetSize()-2,
			     DY_MuMu->GetXaxis()->GetXmin(),
			     DY_MuMu->GetXaxis()->GetXmax());
  Jets_MuMu->Write();

  TH1F* DYS_MuMu = new TH1F("DYS",
			    "DYS",
			    DY_MuMu->GetSize()-2,
			    DY_MuMu->GetXaxis()->GetXmin(),
			    DY_MuMu->GetXaxis()->GetXmax());
  DYS_MuMu->Write();

  TH1F* DYJ_MuMu = new TH1F("DYJ",
			    "DYJ",
			    DY_MuMu->GetSize()-2,
			    DY_MuMu->GetXaxis()->GetXmin(),
			    DY_MuMu->GetXaxis()->GetXmax());
  DYJ_MuMu->Write();
  
  /*
    W_MuMu->SetNameTitle("W","W");
    W_MuMu->Write();

    QCD_MuMu->SetNameTitle("QCD","QCD");
    QCD_MuMu->Write();
  */
  CombineFile->Close();
  FakeRateDeterminedDistributions->Close();
  PassFailFile->Close();
}
