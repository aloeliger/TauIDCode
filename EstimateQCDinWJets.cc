//This script does some histogram subtraction to determine the QCD contribution to the W+jets region
#include "TROOT.h"
#include <string>

TH1F* EstimateInControls(string ControlVar)
{
  std::cout<<"Processing the estimation in: "<<ControlVar<<std::endl;
  TFile* ContributionFile = new TFile("Distributions/WJetsQCDContributions.root");
  TDirectory* Contribution_ControlDir = (TDirectory *)ContributionFile->Get("control");
  
  TH1F* Contribution_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_Data_"+ControlVar).c_str());  
  TH1F* ZTauTau_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_GenMatch_DY_"+ControlVar).c_str());
  TH1F* ZTauTau1_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_GenMatch_DY1_"+ControlVar).c_str());
  TH1F* ZTauTau2_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_GenMatch_DY2_"+ControlVar).c_str());
  TH1F* ZTauTau3_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_GenMatch_DY3_"+ControlVar).c_str());
  TH1F* ZTauTau4_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_GenMatch_DY4_"+ControlVar).c_str());  
  TH1F* LowGenMatch_DY_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_LowGenMatch_DY_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY1_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_LowGenMatch_DY1_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY2_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_LowGenMatch_DY2_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY3_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_LowGenMatch_DY3_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY4_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_LowGenMatch_DY4_"+ControlVar).c_str());  
  TH1F* HighGenMatch_DY_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_HighGenMatch_DY_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY1_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_HighGenMatch_DY1_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY2_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_HighGenMatch_DY2_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY3_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_HighGenMatch_DY3_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY4_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_HighGenMatch_DY4_"+ControlVar).c_str());
  
  TH1F* TTTo2L2Nu_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_TTTo2L2Nu_"+ControlVar).c_str());
  TH1F* TTToHadronic_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_TTToHadronic_"+ControlVar).c_str());
  TH1F* TTToSemiLeptonic_Control =  (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_TTToSemiLeptonic_"+ControlVar).c_str());  
  TH1F* W_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_W_"+ControlVar).c_str());
  TH1F* W1_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_W1_"+ControlVar).c_str());
  TH1F* W2_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_W2_"+ControlVar).c_str());
  TH1F* W3_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_W3_"+ControlVar).c_str());
  TH1F* W4_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_W4_"+ControlVar).c_str());  
  TH1F* WW_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_WW_"+ControlVar).c_str());
  TH1F* WZ_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_WZ_"+ControlVar).c_str());
  TH1F* ZZ_Control = (TH1F *) Contribution_ControlDir->Get(("WJets_QCD_ZZ_"+ControlVar).c_str());  
  
  Contribution_Control->SetName(("CorrectedQCDContribution_"+ControlVar).c_str());

  std::cout<<"Performing the subtraction..."<<std::endl;
  std::cout<<"Low Gen Match DY..."<<std::endl;
  Contribution_Control->Add(LowGenMatch_DY_Control, -1.0);
  Contribution_Control->Add(LowGenMatch_DY1_Control, -1.0);
  Contribution_Control->Add(LowGenMatch_DY2_Control, -1.0);
  Contribution_Control->Add(LowGenMatch_DY3_Control, -1.0);
  Contribution_Control->Add(LowGenMatch_DY4_Control, -1.0);
  std::cout<<"High Gen Match DY..."<<std::endl;
  Contribution_Control->Add(HighGenMatch_DY_Control, -1.0);
  Contribution_Control->Add(HighGenMatch_DY1_Control, -1.0);
  Contribution_Control->Add(HighGenMatch_DY2_Control, -1.0);
  Contribution_Control->Add(HighGenMatch_DY3_Control, -1.0);
  Contribution_Control->Add(HighGenMatch_DY4_Control, -1.0);
  std::cout<<"ZTauTau..."<<std::endl;
  Contribution_Control->Add(ZTauTau_Control, -1.0);
  Contribution_Control->Add(ZTauTau1_Control, -1.0);
  Contribution_Control->Add(ZTauTau2_Control, -1.0);
  Contribution_Control->Add(ZTauTau3_Control, -1.0);
  Contribution_Control->Add(ZTauTau4_Control, -1.0);

  std::cout<<"TT..."<<std::endl;
  Contribution_Control->Add(TTTo2L2Nu_Control, -1.0);
  Contribution_Control->Add(TTToHadronic_Control, -1.0);
  Contribution_Control->Add(TTToSemiLeptonic_Control, -1.0);
  std::cout<<"Diboson..."<<std::endl;
  Contribution_Control->Add(WW_Control, -1.0);
  Contribution_Control->Add(WZ_Control, -1.0);
  Contribution_Control->Add(ZZ_Control, -1.0);
  Contribution_Control->Add(W_Control, -1.0);
  std::cout<<"W..."<<std::endl;
  Contribution_Control->Add(W1_Control, -1.0);
  Contribution_Control->Add(W2_Control, -1.0);
  Contribution_Control->Add(W3_Control, -1.0);
  Contribution_Control->Add(W4_Control, -1.0);

  //Contribution_Control->Scale(1.05);
  Contribution_Control->Scale(1.12);
  return Contribution_Control;
}

void EstimateQCDinWJets()
{
  TFile* ContributionFile = new TFile("Distributions/WJetsQCDContributions.root");
  TDirectory* Contribution_PassDir = (TDirectory *)ContributionFile->Get("pass");
  TDirectory* Contribution_FailDir = (TDirectory *)ContributionFile->Get("fail");
  
  //pass histos
  cout<<"Retrieving Pass Region Histograms"<<std::endl;
  TH1F* Contribution_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_Data_Pass");
  
  TH1F* ZTauTau_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_GenMatch_DY_Pass");
  TH1F* ZTauTau1_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_GenMatch_DY1_Pass");
  TH1F* ZTauTau2_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_GenMatch_DY2_Pass");
  TH1F* ZTauTau3_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_GenMatch_DY3_Pass");
  TH1F* ZTauTau4_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_GenMatch_DY4_Pass");
  TH1F* LowGenMatch_DY_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_LowGenMatch_DY_Pass");
  TH1F* LowGenMatch_DY1_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_LowGenMatch_DY1_Pass");
  TH1F* LowGenMatch_DY2_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_LowGenMatch_DY2_Pass");
  TH1F* LowGenMatch_DY3_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_LowGenMatch_DY3_Pass");
  TH1F* LowGenMatch_DY4_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_LowGenMatch_DY4_Pass");
  TH1F* HighGenMatch_DY_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_HighGenMatch_DY_Pass");
  TH1F* HighGenMatch_DY1_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_HighGenMatch_DY1_Pass");
  TH1F* HighGenMatch_DY2_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_HighGenMatch_DY2_Pass");
  TH1F* HighGenMatch_DY3_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_HighGenMatch_DY3_Pass");
  TH1F* HighGenMatch_DY4_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_HighGenMatch_DY4_Pass");


  TH1F* TTTo2L2Nu_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_TTTo2L2Nu_Pass");
  TH1F* TTToHadronic_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_TTToHadronic_Pass");
  TH1F* TTToSemiLeptonic_Pass =  (TH1F *) Contribution_PassDir->Get("WJets_QCD_TTToSemiLeptonic_Pass");
  TH1F* W_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_W_Pass");
  TH1F* W1_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_W1_Pass");
  TH1F* W2_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_W2_Pass");
  TH1F* W3_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_W3_Pass");
  TH1F* W4_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_W4_Pass");
  TH1F* WW_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_WW_Pass");
  TH1F* WZ_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_WZ_Pass");
  TH1F* ZZ_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_ZZ_Pass");  
  

  Contribution_Pass->SetName("CorrectedQCDContribution_Pass");

  //fail histos
  std::cout<<"Retrieving Fail Region Histograms"<<std::endl;
  TH1F* Contribution_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_Data_Fail");
    
  TH1F* ZTauTau_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_GenMatch_DY_Fail");
  TH1F* ZTauTau1_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_GenMatch_DY1_Fail");
  TH1F* ZTauTau2_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_GenMatch_DY2_Fail");
  TH1F* ZTauTau3_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_GenMatch_DY3_Fail");
  TH1F* ZTauTau4_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_GenMatch_DY4_Fail");
  TH1F* LowGenMatch_DY_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_LowGenMatch_DY_Fail");
  TH1F* LowGenMatch_DY1_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_LowGenMatch_DY1_Fail");
  TH1F* LowGenMatch_DY2_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_LowGenMatch_DY2_Fail");
  TH1F* LowGenMatch_DY3_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_LowGenMatch_DY3_Fail");
  TH1F* LowGenMatch_DY4_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_LowGenMatch_DY4_Fail");
  TH1F* HighGenMatch_DY_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_HighGenMatch_DY_Fail");
  TH1F* HighGenMatch_DY1_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_HighGenMatch_DY1_Fail");
  TH1F* HighGenMatch_DY2_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_HighGenMatch_DY2_Fail");
  TH1F* HighGenMatch_DY3_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_HighGenMatch_DY3_Fail");
  TH1F* HighGenMatch_DY4_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_HighGenMatch_DY4_Fail");

  TH1F* TTTo2L2Nu_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_TTTo2L2Nu_Fail");
  TH1F* TTToHadronic_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_TTToHadronic_Fail");
  TH1F* TTToSemiLeptonic_Fail =  (TH1F *) Contribution_FailDir->Get("WJets_QCD_TTToSemiLeptonic_Fail");
  TH1F* W_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_W_Fail");
  TH1F* W1_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_W1_Fail");
  TH1F* W2_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_W2_Fail");
  TH1F* W3_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_W3_Fail");
  TH1F* W4_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_W4_Fail");
  TH1F* WW_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_WW_Fail");
  TH1F* WZ_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_WZ_Fail");
  TH1F* ZZ_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_ZZ_Fail");  

  Contribution_Fail->SetName("CorrectedQCDContribution_Fail");

  std::cout<<"Subtracting Pass backgrounds..."<<std::endl;  
  Contribution_Pass->Add(LowGenMatch_DY_Pass, -1.0);
  Contribution_Pass->Add(LowGenMatch_DY1_Pass, -1.0);
  Contribution_Pass->Add(LowGenMatch_DY2_Pass, -1.0);
  Contribution_Pass->Add(LowGenMatch_DY3_Pass, -1.0);
  Contribution_Pass->Add(LowGenMatch_DY4_Pass, -1.0);
  Contribution_Pass->Add(HighGenMatch_DY_Pass, -1.0);
  Contribution_Pass->Add(HighGenMatch_DY1_Pass, -1.0);
  Contribution_Pass->Add(HighGenMatch_DY2_Pass, -1.0);
  Contribution_Pass->Add(HighGenMatch_DY3_Pass, -1.0);
  Contribution_Pass->Add(HighGenMatch_DY4_Pass, -1.0);
  Contribution_Pass->Add(ZTauTau_Pass, -1.0);
  Contribution_Pass->Add(ZTauTau1_Pass, -1.0);
  Contribution_Pass->Add(ZTauTau2_Pass, -1.0);
  Contribution_Pass->Add(ZTauTau3_Pass, -1.0);
  Contribution_Pass->Add(ZTauTau4_Pass, -1.0);

  Contribution_Pass->Add(TTTo2L2Nu_Pass, -1.0);
  Contribution_Pass->Add(TTToHadronic_Pass, -1.0);
  Contribution_Pass->Add(TTToSemiLeptonic_Pass, -1.0);
  Contribution_Pass->Add(WW_Pass, -1.0);
  Contribution_Pass->Add(WZ_Pass, -1.0);
  Contribution_Pass->Add(ZZ_Pass, -1.0);
  Contribution_Pass->Add(W_Pass, -1.0);
  Contribution_Pass->Add(W1_Pass, -1.0);
  Contribution_Pass->Add(W2_Pass, -1.0);
  Contribution_Pass->Add(W3_Pass, -1.0);
  Contribution_Pass->Add(W4_Pass, -1.0);
  
  std::cout<<"Subtracting Fail backgrounds..."<<std::endl;  
  Contribution_Fail->Add(LowGenMatch_DY_Fail, -1.0);
  Contribution_Fail->Add(LowGenMatch_DY1_Fail, -1.0);
  Contribution_Fail->Add(LowGenMatch_DY2_Fail, -1.0);
  Contribution_Fail->Add(LowGenMatch_DY3_Fail, -1.0);
  Contribution_Fail->Add(LowGenMatch_DY4_Fail, -1.0);
  Contribution_Fail->Add(HighGenMatch_DY_Fail, -1.0);
  Contribution_Fail->Add(HighGenMatch_DY1_Fail, -1.0);
  Contribution_Fail->Add(HighGenMatch_DY2_Fail, -1.0);
  Contribution_Fail->Add(HighGenMatch_DY3_Fail, -1.0);
  Contribution_Fail->Add(HighGenMatch_DY4_Fail, -1.0);
  Contribution_Fail->Add(ZTauTau_Fail, -1.0);
  Contribution_Fail->Add(ZTauTau1_Fail, -1.0);
  Contribution_Fail->Add(ZTauTau2_Fail, -1.0);
  Contribution_Fail->Add(ZTauTau3_Fail, -1.0);
  Contribution_Fail->Add(ZTauTau4_Fail, -1.0);

  Contribution_Fail->Add(TTTo2L2Nu_Fail, -1.0);
  Contribution_Fail->Add(TTToHadronic_Fail, -1.0);
  Contribution_Fail->Add(TTToSemiLeptonic_Fail, -1.0);
  Contribution_Fail->Add(WW_Fail, -1.0);
  Contribution_Fail->Add(WZ_Fail, -1.0);
  Contribution_Fail->Add(ZZ_Fail, -1.0);
  Contribution_Fail->Add(W_Fail, -1.0);
  Contribution_Fail->Add(W1_Fail, -1.0);
  Contribution_Fail->Add(W2_Fail, -1.0);
  Contribution_Fail->Add(W3_Fail, -1.0);
  Contribution_Fail->Add(W4_Fail, -1.0);

  //Contribution_Pass->Scale(1.05);
  //Contribution_Fail->Scale(1.05);
  Contribution_Pass->Scale(1.12);
  Contribution_Fail->Scale(1.12);

  TH1F* Contribution_MuPt;
  TH1F* Contribution_TauPt;
  TH1F* Contribution_MuEta;
  TH1F* Contribution_TauEta;
  TH1F* Contribution_NJets;
  TH1F* Contribution_NBtag;
  TH1F* Contribution_ZMass;
  TH1F* Contribution_ZPT;
  TH1F* Contribution_MT;

  Contribution_MuPt = EstimateInControls("MuPt");
  Contribution_TauPt = EstimateInControls("TauPt");
  Contribution_MuEta = EstimateInControls("MuEta");
  Contribution_TauEta = EstimateInControls("TauEta");
  Contribution_NJets = EstimateInControls("njets");
  Contribution_NBtag = EstimateInControls("nbtag");
  Contribution_ZMass = EstimateInControls("ZMass");
  Contribution_ZPT = EstimateInControls("ZPT");
  Contribution_MT = EstimateInControls("MT");

  TFile* WJetsFile = new TFile("Distributions/WJetsDistributions.root","UPDATE");
  TDirectory* WJets_PassDir = (TDirectory *) WJetsFile->Get("pass");
  TDirectory* WJets_FailDir = (TDirectory *) WJetsFile->Get("fail");
  TDirectory* WJets_ControlDir = (TDirectory* ) WJetsFile->Get("control");

  WJets_PassDir->cd();
  Contribution_Pass->Write();

  WJets_FailDir->cd();
  Contribution_Fail->Write();

  WJets_ControlDir->cd();
  Contribution_MuPt->Write();
  Contribution_TauPt->Write();
  Contribution_MuEta->Write();
  Contribution_TauEta->Write();
  Contribution_NJets->Write();
  Contribution_NBtag->Write();
  Contribution_ZMass->Write();
  Contribution_ZPT->Write();
  Contribution_MT->Write();
}
