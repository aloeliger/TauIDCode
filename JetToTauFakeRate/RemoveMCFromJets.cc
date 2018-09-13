#include "TROOT.h"
#include <string>

void RemoveMCFromJets(std::string IsoWorkingPoint)
{
  TFile* MCInJetsFile = new TFile("../Distributions/MCInJetsRegion.root");
  TFile* FakeRateDeterminedDistributions = new TFile("../Distributions/FakeRateDeterminedDistributions.root");
  //start grabbin histos
  std::cout<<"Retrieving Drell Yan..."<<std::endl;
  TH1F* DY_InJets = (TH1F*) MCInJetsFile->Get(("DY_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY1_InJets = (TH1F*) MCInJetsFile->Get(("DY1_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY2_InJets = (TH1F*) MCInJetsFile->Get(("DY2_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY3_InJets = (TH1F*) MCInJetsFile->Get(("DY3_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY4_InJets = (TH1F*) MCInJetsFile->Get(("DY4_"+IsoWorkingPoint+"_JetRegion").c_str());
  DY_InJets->Add(DY1_InJets);
  DY_InJets->Add(DY2_InJets);
  DY_InJets->Add(DY3_InJets);
  DY_InJets->Add(DY4_InJets);

  std::cout<<"Up..."<<std::endl;
  TH1F* DYUP_InJets = (TH1F*) MCInJetsFile->Get(("DYUP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY1UP_InJets = (TH1F*) MCInJetsFile->Get(("DY1UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY2UP_InJets = (TH1F*) MCInJetsFile->Get(("DY2UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY3UP_InJets = (TH1F*) MCInJetsFile->Get(("DY3UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY4UP_InJets = (TH1F*) MCInJetsFile->Get(("DY4UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  DYUP_InJets->Add(DY1UP_InJets);
  DYUP_InJets->Add(DY2UP_InJets);
  DYUP_InJets->Add(DY3UP_InJets);
  DYUP_InJets->Add(DY4UP_InJets);

  std::cout<<"Down..."<<std::endl;
  TH1F* DYDOWN_InJets = (TH1F*) MCInJetsFile->Get(("DYDOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY1DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY1DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY2DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY2DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY3DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY3DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY4DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY4DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  DYDOWN_InJets->Add(DY1DOWN_InJets);
  DYDOWN_InJets->Add(DY2DOWN_InJets);
  DYDOWN_InJets->Add(DY3DOWN_InJets);
  DYDOWN_InJets->Add(DY4DOWN_InJets);

  std::cout<<"Retrieving ttbar..."<<std::endl;
  TH1F* TTTo2L2Nu_InJets = (TH1F*) MCInJetsFile->Get(("TTTo2L2Nu_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToHadronic_InJets = (TH1F*) MCInJetsFile->Get(("TTToHadronic_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToSemiLeptonic_InJets = (TH1F*) MCInJetsFile->Get(("TTToSemiLeptonic_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* TT_InJets = (TH1F*) TTTo2L2Nu_InJets->Clone();
  TT_InJets->Add(TTToHadronic_InJets);
  TT_InJets->Add(TTToSemiLeptonic_InJets);
  
  std::cout<<"Up..."<<std::endl;
  TH1F* TTTo2L2NuUP_InJets = (TH1F*) MCInJetsFile->Get(("TTTo2L2NuUP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToHadronicUP_InJets = (TH1F*) MCInJetsFile->Get(("TTToHadronicUP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToSemiLeptonicUP_InJets = (TH1F*) MCInJetsFile->Get(("TTToSemiLeptonicUP_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* TTUP_InJets = (TH1F*) TTTo2L2NuUP_InJets->Clone();
  TTUP_InJets->Add(TTToHadronicUP_InJets);
  TTUP_InJets->Add(TTToSemiLeptonicUP_InJets);

  std::cout<<"Down..."<<std::endl;
  TH1F* TTTo2L2NuDOWN_InJets = (TH1F*) MCInJetsFile->Get(("TTTo2L2NuDOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToHadronicDOWN_InJets = (TH1F*) MCInJetsFile->Get(("TTToHadronicDOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToSemiLeptonicDOWN_InJets = (TH1F*) MCInJetsFile->Get(("TTToSemiLeptonicDOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* TTDOWN_InJets = (TH1F*) TTTo2L2NuDOWN_InJets->Clone();
  TTDOWN_InJets->Add(TTToHadronicDOWN_InJets);
  TTDOWN_InJets->Add(TTToSemiLeptonicDOWN_InJets);

  std::cout<<"Retrieving Diboson..."<<std::endl;
  TH1F* WW_InJets = (TH1F*) MCInJetsFile->Get(("WW_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* WZ_InJets = (TH1F*) MCInJetsFile->Get(("WZ_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ZZ_InJets = (TH1F*) MCInJetsFile->Get(("ZZ_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* Diboson_InJets = (TH1F*) WW_InJets->Clone();
  Diboson_InJets->Add(WZ_InJets);
  Diboson_InJets->Add(ZZ_InJets);

  std::cout<<"Up..."<<std::endl;
  TH1F* WWUP_InJets = (TH1F*) MCInJetsFile->Get(("WWUP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* WZUP_InJets = (TH1F*) MCInJetsFile->Get(("WZUP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ZZUP_InJets = (TH1F*) MCInJetsFile->Get(("ZZUP_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* DibosonUP_InJets = (TH1F*) WWUP_InJets->Clone();
  DibosonUP_InJets->Add(WZUP_InJets);
  DibosonUP_InJets->Add(ZZUP_InJets);

  std::cout<<"Down..."<<std::endl;
  TH1F* WWDOWN_InJets = (TH1F*) MCInJetsFile->Get(("WWDOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* WZDOWN_InJets = (TH1F*) MCInJetsFile->Get(("WZDOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ZZDOWN_InJets = (TH1F*) MCInJetsFile->Get(("ZZDOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* DibosonDOWN_InJets = (TH1F*) WWDOWN_InJets->Clone();
  DibosonDOWN_InJets->Add(WZDOWN_InJets);
  DibosonDOWN_InJets->Add(ZZDOWN_InJets);
  
  TH1F* JetDistribution; 
  TH1F* JetDistribution_DOWN;
  TH1F* JetDistribution_UP;
  assert(IsoWorkingPoint == "VLoose" ||
	 IsoWorkingPoint == "Loose" ||
	 IsoWorkingPoint == "Medium" ||
	 IsoWorkingPoint == "Tight" ||
	 IsoWorkingPoint == "VTight" ||
	 IsoWorkingPoint == "VVTight");
  if(IsoWorkingPoint == "VLoose")
    {	
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("VLoosePTFRJetDistribution");
      JetDistribution_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VLooseLowJetDistribution");
      JetDistribution_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VLooseHighJetDistribution");
    }
  else if(IsoWorkingPoint == "Loose")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("LoosePTFRJetDistribution");
      JetDistribution_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("LooseLowJetDistribution");
      JetDistribution_UP = (TH1F*) FakeRateDeterminedDistributions->Get("LooseHighJetDistribution");
    }
  else if(IsoWorkingPoint == "Medium")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("MediumPTFRJetDistribution");
      JetDistribution_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("MediumLowJetDistribution");
      JetDistribution_UP = (TH1F*) FakeRateDeterminedDistributions->Get("MediumHighJetDistribution");
    }
  else if(IsoWorkingPoint == "Tight")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("TightPTFRJetDistribution");
      JetDistribution_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("TightLowJetDistribution");
      JetDistribution_UP = (TH1F*) FakeRateDeterminedDistributions->Get("TightHighJetDistribution");
    }
  else if(IsoWorkingPoint == "VTight")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("VTightPTFRJetDistribution");
      JetDistribution_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VTightLowJetDistribution");
      JetDistribution_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VTightHighJetDistribution");
    }
  else if(IsoWorkingPoint == "VVTight")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightPTFRJetDistribution");
      JetDistribution_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightLowJetDistribution");
      JetDistribution_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightHighJetDistribution");
    }

  JetDistribution->Add(DY_InJets,-1.0);
  JetDistribution->Add(TT_InJets,-1.0);
  JetDistribution->Add(Diboson_InJets,-1.0);

  JetDistribution_UP->Add(DYUP_InJets,-1.0);
  JetDistribution_UP->Add(TTUP_InJets,-1.0);
  JetDistribution_UP->Add(DibosonUP_InJets,-1.0);

  JetDistribution_DOWN->Add(DYDOWN_InJets,-1.0);
  JetDistribution_DOWN->Add(TTDOWN_InJets,-1.0);
  JetDistribution_DOWN->Add(DibosonDOWN_InJets,-1.0);

  FakeRateDeterminedDistributions = new TFile("../Distributions/FakeRateDeterminedDistributions.root","RECREATE");
  JetDistribution->Write();
  JetDistribution_UP->Write();
  JetDistribution_DOWN->Write();

}
