#include "TROOT.h"

void EstimateQCDinWJets()
{
  TFile* ContributionFile = new TFile("WJetsQCDContributions.root");
  TDirectory* Contribution_PassDir = (TDirectory *)ContributionFile->Get("PassRegion");
  TDirectory* Contribution_FailDir = (TDirectory *)ContributionFile->Get("FailRegion");
  
  //pass histos
  cout<<"Retrieving Pass Region Histograms"<<std::endl;
  TH1F* Contribution_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_Data_Pass");
  TH1F* DY_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_DY_Pass");
  TH1F* TTTo2L2Nu_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_TTTo2L2Nu_Pass");
  TH1F* TTToHadronic_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_TTToHadronic_Pass");
  TH1F* TTToSemiLeptonic_Pass =  (TH1F *) Contribution_PassDir->Get("WJets_QCD_TTToSemiLeptonic_Pass");
  TH1F* W_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_W_Pass");
  TH1F* WW_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_WW_Pass");
  TH1F* WZ_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_WZ_Pass");
  TH1F* ZZ_Pass = (TH1F *) Contribution_PassDir->Get("WJets_QCD_ZZ_Pass");

  Contribution_Pass->SetName("CorrectedQCDContribution_Pass");

  //fail histos
  std::cout<<"Retrieving Fail Region Histograms"<<std::endl;
  TH1F* Contribution_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_Data_Fail");
  TH1F* DY_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_DY_Fail");
  TH1F* TTTo2L2Nu_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_TTTo2L2Nu_Fail");
  TH1F* TTToHadronic_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_TTToHadronic_Fail");
  TH1F* TTToSemiLeptonic_Fail =  (TH1F *) Contribution_FailDir->Get("WJets_QCD_TTToSemiLeptonic_Fail");
  TH1F* W_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_W_Fail");
  TH1F* WW_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_WW_Fail");
  TH1F* WZ_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_WZ_Fail");
  TH1F* ZZ_Fail = (TH1F *) Contribution_FailDir->Get("WJets_QCD_ZZ_Fail");

  Contribution_Fail->SetName("CorrectedQCDContribution_Fail");

  std::cout<<"Subtracting Pass backgrounds..."<<std::endl;
  Contribution_Pass->Add(DY_Pass, -1.0);
  Contribution_Pass->Add(TTTo2L2Nu_Pass, -1.0);
  Contribution_Pass->Add(TTToHadronic_Pass, -1.0);
  Contribution_Pass->Add(TTToSemiLeptonic_Pass, -1.0);
  Contribution_Pass->Add(WW_Pass, -1.0);
  Contribution_Pass->Add(WZ_Pass, -1.0);
  Contribution_Pass->Add(ZZ_Pass, -1.0);
  Contribution_Pass->Add(W_Pass, -1.0);
  
  std::cout<<"Subtracting Fail backgrounds..."<<std::endl;
  Contribution_Fail->Add(DY_Fail, -1.0);
  Contribution_Fail->Add(TTTo2L2Nu_Fail, -1.0);
  Contribution_Fail->Add(TTToHadronic_Fail, -1.0);
  Contribution_Fail->Add(TTToSemiLeptonic_Fail, -1.0);
  Contribution_Fail->Add(WW_Fail, -1.0);
  Contribution_Fail->Add(WZ_Fail, -1.0);
  Contribution_Fail->Add(ZZ_Fail, -1.0);
  Contribution_Fail->Add(W_Fail, -1.0);

  Contribution_Pass->Scale(1.05);
  Contribution_Fail->Scale(1.05);

  TFile* WJetsFile = new TFile("WJetsDistributions.root","UPDATE");
  TDirectory* WJets_PassDir = (TDirectory *) WJetsFile->Get("PassRegion");
  TDirectory* WJets_FailDir = (TDirectory *) WJetsFile->Get("FailRegion");

  WJets_PassDir->cd();
  Contribution_Pass->Write();

  WJets_FailDir->cd();
  Contribution_Fail->Write();
}
