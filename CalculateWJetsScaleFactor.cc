//Quickly calculates the scale factor used for scaling W+Jets stuff.
//Right now I only plan to apply it to the QCD generation script,
// but since I also just plan to take the WJetsSimToData code,
// I could kill a couple birds with one stone and pull it out of that file too.
#include "TROOT.h"

float CalculateWJetsScaleFactor()
{
  TFile* WJetFile = new TFile("Distributions/WJetsDistributions.root","READ");
  TDirectory *WJet_PassDir = (TDirectory *) WJetFile->Get("pass");
  TDirectory* WJet_FailDir = (TDirectory *) WJetFile->Get("fail");
  
  //pass histos
  cout<<"Retrieving Pass Region Histograms"<<std::endl;
  TH1F* DataEstimated_WJets_Pass = (TH1F *) WJet_PassDir->Get("WJets_Data_Pass");
    
  TH1F* ZTauTau_Pass = (TH1F *) WJet_PassDir->Get("WJets_GenMatch_DY_Pass");
  TH1F* ZTauTau1_Pass = (TH1F *) WJet_PassDir->Get("WJets_GenMatch_DY1_Pass");
  TH1F* ZTauTau2_Pass = (TH1F *) WJet_PassDir->Get("WJets_GenMatch_DY2_Pass");
  TH1F* ZTauTau3_Pass = (TH1F *) WJet_PassDir->Get("WJets_GenMatch_DY3_Pass");
  TH1F* ZTauTau4_Pass = (TH1F *) WJet_PassDir->Get("WJets_GenMatch_DY4_Pass");
  TH1F* LowGenMatch_DY_Pass = (TH1F *) WJet_PassDir->Get("WJets_LowGenMatch_DY_Pass");
  TH1F* LowGenMatch_DY1_Pass = (TH1F *) WJet_PassDir->Get("WJets_LowGenMatch_DY1_Pass");
  TH1F* LowGenMatch_DY2_Pass = (TH1F *) WJet_PassDir->Get("WJets_LowGenMatch_DY2_Pass");
  TH1F* LowGenMatch_DY3_Pass = (TH1F *) WJet_PassDir->Get("WJets_LowGenMatch_DY3_Pass");
  TH1F* LowGenMatch_DY4_Pass = (TH1F *) WJet_PassDir->Get("WJets_LowGenMatch_DY4_Pass");
  TH1F* HighGenMatch_DY_Pass = (TH1F *) WJet_PassDir->Get("WJets_HighGenMatch_DY_Pass");
  TH1F* HighGenMatch_DY1_Pass = (TH1F *) WJet_PassDir->Get("WJets_HighGenMatch_DY1_Pass");
  TH1F* HighGenMatch_DY2_Pass = (TH1F *) WJet_PassDir->Get("WJets_HighGenMatch_DY2_Pass");
  TH1F* HighGenMatch_DY3_Pass = (TH1F *) WJet_PassDir->Get("WJets_HighGenMatch_DY3_Pass");
  TH1F* HighGenMatch_DY4_Pass = (TH1F *) WJet_PassDir->Get("WJets_HighGenMatch_DY4_Pass");
  

  TH1F* TTTo2L2Nu_Pass = (TH1F *) WJet_PassDir->Get("WJets_TTTo2L2Nu_Pass");
  TH1F* TTToHadronic_Pass = (TH1F *) WJet_PassDir->Get("WJets_TTToHadronic_Pass");
  TH1F* TTToSemiLeptonic_Pass =  (TH1F *) WJet_PassDir->Get("WJets_TTToSemiLeptonic_Pass");
  TH1F* W_Pass = (TH1F *) WJet_PassDir->Get("WJets_W_Pass");
  TH1F* W1_Pass = (TH1F *) WJet_PassDir->Get("WJets_W1_Pass");
  TH1F* W2_Pass = (TH1F *) WJet_PassDir->Get("WJets_W2_Pass");
  TH1F* W3_Pass = (TH1F *) WJet_PassDir->Get("WJets_W3_Pass");
  TH1F* W4_Pass = (TH1F *) WJet_PassDir->Get("WJets_W4_Pass");
  TH1F* WW_Pass = (TH1F *) WJet_PassDir->Get("WJets_WW_Pass");
  TH1F* WZ_Pass = (TH1F *) WJet_PassDir->Get("WJets_WZ_Pass");
  TH1F* ZZ_Pass = (TH1F *) WJet_PassDir->Get("WJets_ZZ_Pass");
  TH1F* QCD_Pass = (TH1F *) WJet_PassDir->Get("CorrectedQCDContribution_Pass");
  
  //fail histos
  std::cout<<"Retrieving Fail Region Histograms"<<std::endl;
  TH1F* DataEstimated_WJets_Fail = (TH1F *) WJet_FailDir->Get("WJets_Data_Fail");
  
  TH1F* ZTauTau_Fail = (TH1F *) WJet_FailDir->Get("WJets_GenMatch_DY_Fail");
  TH1F* ZTauTau1_Fail = (TH1F *) WJet_FailDir->Get("WJets_GenMatch_DY1_Fail");
  TH1F* ZTauTau2_Fail = (TH1F *) WJet_FailDir->Get("WJets_GenMatch_DY2_Fail");
  TH1F* ZTauTau3_Fail = (TH1F *) WJet_FailDir->Get("WJets_GenMatch_DY3_Fail");
  TH1F* ZTauTau4_Fail = (TH1F *) WJet_FailDir->Get("WJets_GenMatch_DY4_Fail");
  TH1F* LowGenMatch_DY_Fail = (TH1F *) WJet_FailDir->Get("WJets_LowGenMatch_DY_Fail");
  TH1F* LowGenMatch_DY1_Fail = (TH1F *) WJet_FailDir->Get("WJets_LowGenMatch_DY1_Fail");
  TH1F* LowGenMatch_DY2_Fail = (TH1F *) WJet_FailDir->Get("WJets_LowGenMatch_DY2_Fail");
  TH1F* LowGenMatch_DY3_Fail = (TH1F *) WJet_FailDir->Get("WJets_LowGenMatch_DY3_Fail");
  TH1F* LowGenMatch_DY4_Fail = (TH1F *) WJet_FailDir->Get("WJets_LowGenMatch_DY4_Fail");
  TH1F* HighGenMatch_DY_Fail = (TH1F *) WJet_FailDir->Get("WJets_HighGenMatch_DY_Fail");
  TH1F* HighGenMatch_DY1_Fail = (TH1F *) WJet_FailDir->Get("WJets_HighGenMatch_DY1_Fail");
  TH1F* HighGenMatch_DY2_Fail = (TH1F *) WJet_FailDir->Get("WJets_HighGenMatch_DY2_Fail");
  TH1F* HighGenMatch_DY3_Fail = (TH1F *) WJet_FailDir->Get("WJets_HighGenMatch_DY3_Fail");
  TH1F* HighGenMatch_DY4_Fail = (TH1F *) WJet_FailDir->Get("WJets_HighGenMatch_DY4_Fail");

  TH1F* TTTo2L2Nu_Fail = (TH1F *) WJet_FailDir->Get("WJets_TTTo2L2Nu_Fail");
  TH1F* TTToHadronic_Fail = (TH1F *) WJet_FailDir->Get("WJets_TTToHadronic_Fail");
  TH1F* TTToSemiLeptonic_Fail =  (TH1F *) WJet_FailDir->Get("WJets_TTToSemiLeptonic_Fail");
  TH1F* W_Fail = (TH1F *) WJet_FailDir->Get("WJets_W_Fail");
  TH1F* W1_Fail = (TH1F *) WJet_FailDir->Get("WJets_W1_Fail");
  TH1F* W2_Fail = (TH1F *) WJet_FailDir->Get("WJets_W2_Fail");
  TH1F* W3_Fail = (TH1F *) WJet_FailDir->Get("WJets_W3_Fail");
  TH1F* W4_Fail = (TH1F *) WJet_FailDir->Get("WJets_W4_Fail");
  TH1F* WW_Fail = (TH1F *) WJet_FailDir->Get("WJets_WW_Fail");
  TH1F* WZ_Fail = (TH1F *) WJet_FailDir->Get("WJets_WZ_Fail");
  TH1F* ZZ_Fail = (TH1F *) WJet_FailDir->Get("WJets_ZZ_Fail");
  TH1F* QCD_Fail = (TH1F *) WJet_FailDir->Get("CorrectedQCDContribution_Fail");

  DataEstimated_WJets_Pass->SetName("DataEstimated_WJets_Pass");
  DataEstimated_WJets_Fail->SetName("DataEstimated_WJets_Fail");

  //now we subtract off the contributions (except for the W+Jets distribution)
  std::cout<<"Subtracting backgrounds..."<<std::endl;
  std::cout<<"Pass Event totals beforehand "<<DataEstimated_WJets_Pass->Integral()<<std::endl;
  
  DataEstimated_WJets_Pass->Add(ZTauTau_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(ZTauTau1_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(ZTauTau2_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(ZTauTau3_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(ZTauTau4_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(LowGenMatch_DY_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(LowGenMatch_DY1_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(LowGenMatch_DY2_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(LowGenMatch_DY3_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(LowGenMatch_DY4_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(HighGenMatch_DY_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(HighGenMatch_DY1_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(HighGenMatch_DY2_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(HighGenMatch_DY3_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(HighGenMatch_DY4_Pass, -1.0);

  DataEstimated_WJets_Pass->Add(TTTo2L2Nu_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(TTToHadronic_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(TTToSemiLeptonic_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(WW_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(WZ_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(ZZ_Pass, -1.0);
  DataEstimated_WJets_Pass->Add(QCD_Pass, -1.0);
  std::cout<<"Pass Event totals afterwards "<<DataEstimated_WJets_Pass->Integral()<<std::endl;
  //appropriate W+Jets MC?
  W_Pass->Add(W1_Pass);
  W_Pass->Add(W2_Pass);
  W_Pass->Add(W3_Pass);
  W_Pass->Add(W4_Pass);
  std::cout<<"Total Pass MC "<<W_Pass->Integral()<<std::endl;
  
  std::cout<<"Fail Event totals beforehand "<<DataEstimated_WJets_Fail->Integral()<<std::endl;
  
  DataEstimated_WJets_Fail->Add(ZTauTau_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(ZTauTau1_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(ZTauTau2_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(ZTauTau3_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(ZTauTau4_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(LowGenMatch_DY_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(LowGenMatch_DY1_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(LowGenMatch_DY2_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(LowGenMatch_DY3_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(LowGenMatch_DY4_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(HighGenMatch_DY_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(HighGenMatch_DY1_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(HighGenMatch_DY2_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(HighGenMatch_DY3_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(HighGenMatch_DY4_Fail, -1.0);

  DataEstimated_WJets_Fail->Add(TTTo2L2Nu_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(TTToHadronic_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(TTToSemiLeptonic_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(WW_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(WZ_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(ZZ_Fail, -1.0);
  DataEstimated_WJets_Fail->Add(QCD_Fail, -1.0);
  std::cout<<"Fail Event totals afterwards "<<DataEstimated_WJets_Fail->Integral()<<std::endl;
  //Appropriate W+Jets MC?
  W_Fail->Add(W1_Fail);
  W_Fail->Add(W2_Fail);
  W_Fail->Add(W3_Fail);
  W_Fail->Add(W4_Fail);
  std::cout<<"Total Fail MC "<<W_Fail->Integral()<<std::endl;
  std::cout<<std::endl;  
    
  std::cout<<"WJets Scale Factor: "<<(DataEstimated_WJets_Pass->Integral() + DataEstimated_WJets_Fail->Integral()) / (W_Pass->Integral() + W_Fail->Integral())<<std::endl;
  
  float WJetsScaleFactor = (DataEstimated_WJets_Pass->Integral() + DataEstimated_WJets_Fail->Integral()) / (W_Pass->Integral() + W_Fail->Integral());

  return WJetsScaleFactor;
}
