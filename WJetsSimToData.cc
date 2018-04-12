#include "TROOT.h"

void WJetsSimToData()
{
  TFile* WJetFile = new TFile("Distributions/WJetsDistributions.root","READ");
  TDirectory *WJet_PassDir = (TDirectory *) WJetFile->Get("pass");
  TDirectory* WJet_FailDir = (TDirectory *) WJetFile->Get("fail");
  
  //pass histos
  cout<<"Retrieving Pass Region Histograms"<<std::endl;
  TH1F* WJets_Pass = (TH1F *) WJet_PassDir->Get("WJets_Data_Pass");
  TH1F* DY_Pass = (TH1F *) WJet_PassDir->Get("WJets_DY_Pass");
  TH1F* TTTo2L2Nu_Pass = (TH1F *) WJet_PassDir->Get("WJets_TTTo2L2Nu_Pass");
  TH1F* TTToHadronic_Pass = (TH1F *) WJet_PassDir->Get("WJets_TTToHadronic_Pass");
  TH1F* TTToSemiLeptonic_Pass =  (TH1F *) WJet_PassDir->Get("WJets_TTToSemiLeptonic_Pass");
  TH1F* W_Pass = (TH1F *) WJet_PassDir->Get("WJets_W_Pass");
  TH1F* WW_Pass = (TH1F *) WJet_PassDir->Get("WJets_WW_Pass");
  TH1F* WZ_Pass = (TH1F *) WJet_PassDir->Get("WJets_WZ_Pass");
  TH1F* ZZ_Pass = (TH1F *) WJet_PassDir->Get("WJets_ZZ_Pass");
  TH1F* QCD_Pass = (TH1F *) WJet_PassDir->Get("CorrectedQCDContribution_Pass");
  
  //fail histos
  std::cout<<"Retrieving Fail Region Histograms"<<std::endl;
  TH1F* WJets_Fail = (TH1F *) WJet_FailDir->Get("WJets_Data_Fail");
  TH1F* DY_Fail = (TH1F *) WJet_FailDir->Get("WJets_DY_Pass");
  TH1F* TTTo2L2Nu_Fail = (TH1F *) WJet_FailDir->Get("WJets_TTTo2L2Nu_Fail");
  TH1F* TTToHadronic_Fail = (TH1F *) WJet_FailDir->Get("WJets_TTToHadronic_Fail");
  TH1F* TTToSemiLeptonic_Fail =  (TH1F *) WJet_FailDir->Get("WJets_TTToSemiLeptonic_Fail");
  TH1F* W_Fail = (TH1F *) WJet_FailDir->Get("WJets_W_Fail");
  TH1F* WW_Fail = (TH1F *) WJet_FailDir->Get("WJets_WW_Fail");
  TH1F* WZ_Fail = (TH1F *) WJet_FailDir->Get("WJets_WZ_Fail");
  TH1F* ZZ_Fail = (TH1F *) WJet_FailDir->Get("WJets_ZZ_Fail");
  TH1F* QCD_Fail = (TH1F *) WJet_FailDir->Get("CorrectedQCDContribution_Fail");

  //now we subtract off the contributions (except for the W+Jets distribution)
  std::cout<<"Subtracting backgrounds..."<<std::endl;
  std::cout<<"Pass Event totals beforehand "<<WJets_Pass->Integral()<<std::endl;
  //Currently doesn't seem to be any drell yan events?
  WJets_Pass->Add(DY_Pass, -1.0);
  WJets_Pass->Add(TTTo2L2Nu_Pass, -1.0);
  WJets_Pass->Add(TTToHadronic_Pass, -1.0);
  WJets_Pass->Add(TTToSemiLeptonic_Pass, -1.0);
  WJets_Pass->Add(WW_Pass, -1.0);
  WJets_Pass->Add(WZ_Pass, -1.0);
  WJets_Pass->Add(ZZ_Pass, -1.0);
  WJets_Pass->Add(QCD_Pass, -1.0);
  std::cout<<"Pass Event totals afterwards "<<WJets_Pass->Integral()<<std::endl;
  std::cout<<"Total Pass MC "<<W_Pass->Integral()<<std::endl;
  
  std::cout<<"Fail Event totals beforehand "<<WJets_Fail->Integral()<<std::endl;
  WJets_Fail->Add(DY_Fail, -1.0);
  WJets_Fail->Add(TTTo2L2Nu_Fail, -1.0);
  WJets_Fail->Add(TTToHadronic_Fail, -1.0);
  WJets_Fail->Add(TTToSemiLeptonic_Fail, -1.0);
  WJets_Fail->Add(WW_Fail, -1.0);
  WJets_Fail->Add(WZ_Fail, -1.0);
  WJets_Fail->Add(ZZ_Fail, -1.0);
  WJets_Fail->Add(QCD_Fail, -1.0);
  std::cout<<"Fail Event totals afterwards "<<WJets_Fail->Integral()<<std::endl;
  std::cout<<"Total Fail MC "<<W_Fail->Integral()<<std::endl;
  std::cout<<std::endl;  
    
  std::cout<<"WJets Scale Factor: "<<(WJets_Pass->Integral() + WJets_Fail->Integral()) / (W_Pass->Integral() + W_Fail->Integral())<<std::endl;
  
  float WJetsScaleFactor = (WJets_Pass->Integral() + WJets_Fail->Integral()) / (W_Pass->Integral() + W_Fail->Integral());

  TFile* PassFailFile = new TFile("Distributions/PassFailOut.root","UPDATE");
  TDirectory* PassFail_PassDir = (TDirectory *) PassFailFile->Get("pass");
  TDirectory* PassFail_FailDir = (TDirectory *) PassFailFile->Get("fail");

  TH1F* PassFail_WJets_Pass = (TH1F *) PassFail_PassDir->Get("W_Pass");
  TH1F* PassFail_WJets_Fail = (TH1F *) PassFail_FailDir->Get("W_Fail");
  
  std::cout<<"Creating Newly Scaled Histos"<<std::endl;
  TH1F* Rescaled_WJets_Pass = new TH1F(*PassFail_WJets_Pass);
  TH1F* Rescaled_WJets_Fail = new TH1F(*PassFail_WJets_Fail);

  Rescaled_WJets_Pass->Scale(WJetsScaleFactor);
  Rescaled_WJets_Fail->Scale(WJetsScaleFactor);

  Rescaled_WJets_Pass->SetName("Rescaled_WJets_Pass");
  Rescaled_WJets_Fail->SetName("Rescaled_WJets_Fail");

  //Shove this back into the old file, and we'll roll with that.
  std::cout<<"Writing Newly Scaled Histos to the Pass/Fail File"<<std::endl;
  PassFail_PassDir->cd();
  Rescaled_WJets_Pass->Write();

  PassFail_FailDir->cd();
  Rescaled_WJets_Fail->Write();  
}
