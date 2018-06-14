//Determine the final QCD contirbution to the signal region.
#include "TROOT.h"

void FinalizeQCDBackground()
{
  TFile* QCDFile = new TFile("Distributions/QCDDistributions.root","READ");
  TDirectory* QCD_PassDir = (TDirectory *) QCDFile->Get("pass");
  TDirectory* QCD_FailDir = (TDirectory *) QCDFile->Get("fail");
  
  //pass histos
  cout<<"Retrieving Pass Region Histograms"<<std::endl;
  TH1F* QCD_Pass = (TH1F *) QCD_PassDir->Get("QCD_Data_Pass");
    
  TH1F* ZTauTau_Pass = (TH1F *) QCD_PassDir->Get("QCD_GenMatch_DY_Pass");
  TH1F* ZTauTau1_Pass = (TH1F *) QCD_PassDir->Get("QCD_GenMatch_DY1_Pass");
  TH1F* ZTauTau2_Pass = (TH1F *) QCD_PassDir->Get("QCD_GenMatch_DY2_Pass");
  TH1F* ZTauTau3_Pass = (TH1F *) QCD_PassDir->Get("QCD_GenMatch_DY3_Pass");
  TH1F* ZTauTau4_Pass = (TH1F *) QCD_PassDir->Get("QCD_GenMatch_DY4_Pass");
  TH1F* LowGenMatch_DY_Pass = (TH1F *) QCD_PassDir->Get("QCD_LowGenMatch_DY_Pass");
  TH1F* LowGenMatch_DY1_Pass = (TH1F *) QCD_PassDir->Get("QCD_LowGenMatch_DY1_Pass");
  TH1F* LowGenMatch_DY2_Pass = (TH1F *) QCD_PassDir->Get("QCD_LowGenMatch_DY2_Pass");
  TH1F* LowGenMatch_DY3_Pass = (TH1F *) QCD_PassDir->Get("QCD_LowGenMatch_DY3_Pass");
  TH1F* LowGenMatch_DY4_Pass = (TH1F *) QCD_PassDir->Get("QCD_LowGenMatch_DY4_Pass");
  TH1F* HighGenMatch_DY_Pass = (TH1F *) QCD_PassDir->Get("QCD_HighGenMatch_DY_Pass");
  TH1F* HighGenMatch_DY1_Pass = (TH1F *) QCD_PassDir->Get("QCD_HighGenMatch_DY1_Pass");
  TH1F* HighGenMatch_DY2_Pass = (TH1F *) QCD_PassDir->Get("QCD_HighGenMatch_DY2_Pass");
  TH1F* HighGenMatch_DY3_Pass = (TH1F *) QCD_PassDir->Get("QCD_HighGenMatch_DY3_Pass");
  TH1F* HighGenMatch_DY4_Pass = (TH1F *) QCD_PassDir->Get("QCD_HighGenMatch_DY4_Pass");

  TH1F* TTTo2L2Nu_Pass = (TH1F *) QCD_PassDir->Get("QCD_TTTo2L2Nu_Pass");
  TH1F* TTToHadronic_Pass = (TH1F *) QCD_PassDir->Get("QCD_TTToHadronic_Pass");
  TH1F* TTToSemiLeptonic_Pass =  (TH1F *) QCD_PassDir->Get("QCD_TTToSemiLeptonic_Pass");
  TH1F* W_Pass = (TH1F *) QCD_PassDir->Get("QCD_W_Pass");
  TH1F* W1_Pass = (TH1F *) QCD_PassDir->Get("QCD_W1_Pass");
  TH1F* W2_Pass = (TH1F *) QCD_PassDir->Get("QCD_W2_Pass");
  TH1F* W3_Pass = (TH1F *) QCD_PassDir->Get("QCD_W3_Pass");
  TH1F* W4_Pass = (TH1F *) QCD_PassDir->Get("QCD_W4_Pass");
  TH1F* WW_Pass = (TH1F *) QCD_PassDir->Get("QCD_WW_Pass");
  TH1F* WZ_Pass = (TH1F *) QCD_PassDir->Get("QCD_WZ_Pass");
  TH1F* ZZ_Pass = (TH1F *) QCD_PassDir->Get("QCD_ZZ_Pass");

  QCD_Pass->SetName("QCD_Pass");

  //fail histos
  std::cout<<"Retrieving Fail Region Histograms"<<std::endl;
  TH1F* QCD_Fail = (TH1F *) QCD_FailDir->Get("QCD_Data_Fail");
    
  TH1F* ZTauTau_Fail = (TH1F *) QCD_FailDir->Get("QCD_GenMatch_DY_Fail");
  TH1F* ZTauTau1_Fail = (TH1F *) QCD_FailDir->Get("QCD_GenMatch_DY1_Fail");
  TH1F* ZTauTau2_Fail = (TH1F *) QCD_FailDir->Get("QCD_GenMatch_DY2_Fail");
  TH1F* ZTauTau3_Fail = (TH1F *) QCD_FailDir->Get("QCD_GenMatch_DY3_Fail");
  TH1F* ZTauTau4_Fail = (TH1F *) QCD_FailDir->Get("QCD_GenMatch_DY4_Fail");
  TH1F* LowGenMatch_DY_Fail = (TH1F *) QCD_FailDir->Get("QCD_LowGenMatch_DY_Fail");
  TH1F* LowGenMatch_DY1_Fail = (TH1F *) QCD_FailDir->Get("QCD_LowGenMatch_DY1_Fail");
  TH1F* LowGenMatch_DY2_Fail = (TH1F *) QCD_FailDir->Get("QCD_LowGenMatch_DY2_Fail");
  TH1F* LowGenMatch_DY3_Fail = (TH1F *) QCD_FailDir->Get("QCD_LowGenMatch_DY3_Fail");
  TH1F* LowGenMatch_DY4_Fail = (TH1F *) QCD_FailDir->Get("QCD_LowGenMatch_DY4_Fail");
  TH1F* HighGenMatch_DY_Fail = (TH1F *) QCD_FailDir->Get("QCD_HighGenMatch_DY_Fail");
  TH1F* HighGenMatch_DY1_Fail = (TH1F *) QCD_FailDir->Get("QCD_HighGenMatch_DY1_Fail");
  TH1F* HighGenMatch_DY2_Fail = (TH1F *) QCD_FailDir->Get("QCD_HighGenMatch_DY2_Fail");
  TH1F* HighGenMatch_DY3_Fail = (TH1F *) QCD_FailDir->Get("QCD_HighGenMatch_DY3_Fail");
  TH1F* HighGenMatch_DY4_Fail = (TH1F *) QCD_FailDir->Get("QCD_HighGenMatch_DY4_Fail");

  TH1F* TTTo2L2Nu_Fail = (TH1F *) QCD_FailDir->Get("QCD_TTTo2L2Nu_Fail");
  TH1F* TTToHadronic_Fail = (TH1F *) QCD_FailDir->Get("QCD_TTToHadronic_Fail");
  TH1F* TTToSemiLeptonic_Fail =  (TH1F *) QCD_FailDir->Get("QCD_TTToSemiLeptonic_Fail");
  TH1F* W_Fail = (TH1F *) QCD_FailDir->Get("QCD_W_Fail");
  TH1F* W1_Fail = (TH1F *) QCD_FailDir->Get("QCD_W1_Fail");
  TH1F* W2_Fail = (TH1F *) QCD_FailDir->Get("QCD_W2_Fail");
  TH1F* W3_Fail = (TH1F *) QCD_FailDir->Get("QCD_W3_Fail");
  TH1F* W4_Fail = (TH1F *) QCD_FailDir->Get("QCD_W4_Fail");
  TH1F* WW_Fail = (TH1F *) QCD_FailDir->Get("QCD_WW_Fail");
  TH1F* WZ_Fail = (TH1F *) QCD_FailDir->Get("QCD_WZ_Fail");
  TH1F* ZZ_Fail = (TH1F *) QCD_FailDir->Get("QCD_ZZ_Fail");

  QCD_Fail->SetName("QCD_Fail");

  //4/24/2018 TODO: Need to find a way to properly reweight the WJets MC
  // from the script, right now it is called un-scaled.

  std::cout<<"Subtracting backgrounds..."<<std::endl;  
  QCD_Pass->Add(ZTauTau_Pass, -1.0);
  QCD_Pass->Add(ZTauTau1_Pass, -1.0);
  QCD_Pass->Add(ZTauTau2_Pass, -1.0);
  QCD_Pass->Add(ZTauTau3_Pass, -1.0);
  QCD_Pass->Add(ZTauTau4_Pass, -1.0);
  QCD_Pass->Add(LowGenMatch_DY_Pass, -1.0);
  QCD_Pass->Add(LowGenMatch_DY1_Pass, -1.0);
  QCD_Pass->Add(LowGenMatch_DY2_Pass, -1.0);
  QCD_Pass->Add(LowGenMatch_DY3_Pass, -1.0);
  QCD_Pass->Add(LowGenMatch_DY4_Pass, -1.0);
  QCD_Pass->Add(HighGenMatch_DY_Pass, -1.0);
  QCD_Pass->Add(HighGenMatch_DY1_Pass, -1.0);
  QCD_Pass->Add(HighGenMatch_DY2_Pass, -1.0);
  QCD_Pass->Add(HighGenMatch_DY3_Pass, -1.0);
  QCD_Pass->Add(HighGenMatch_DY4_Pass, -1.0);

  QCD_Pass->Add(TTTo2L2Nu_Pass, -1.0);
  QCD_Pass->Add(TTToHadronic_Pass, -1.0);
  QCD_Pass->Add(TTToSemiLeptonic_Pass, -1.0);
  QCD_Pass->Add(WW_Pass, -1.0);
  QCD_Pass->Add(WZ_Pass, -1.0);
  QCD_Pass->Add(ZZ_Pass, -1.0);
  QCD_Pass->Add(W_Pass, -1.0);
  QCD_Pass->Add(W1_Pass, -1.0);
  QCD_Pass->Add(W2_Pass, -1.0);
  QCD_Pass->Add(W3_Pass, -1.0);
  QCD_Pass->Add(W4_Pass, -1.0);
    
  QCD_Fail->Add(ZTauTau_Fail, -1.0);
  QCD_Fail->Add(ZTauTau1_Fail, -1.0);
  QCD_Fail->Add(ZTauTau2_Fail, -1.0);
  QCD_Fail->Add(ZTauTau3_Fail, -1.0);
  QCD_Fail->Add(ZTauTau4_Fail, -1.0);
  QCD_Fail->Add(LowGenMatch_DY_Fail, -1.0);
  QCD_Fail->Add(LowGenMatch_DY1_Fail, -1.0);
  QCD_Fail->Add(LowGenMatch_DY2_Fail, -1.0);
  QCD_Fail->Add(LowGenMatch_DY3_Fail, -1.0);
  QCD_Fail->Add(LowGenMatch_DY4_Fail, -1.0);
  QCD_Fail->Add(HighGenMatch_DY_Fail, -1.0);
  QCD_Fail->Add(HighGenMatch_DY1_Fail, -1.0);
  QCD_Fail->Add(HighGenMatch_DY2_Fail, -1.0);
  QCD_Fail->Add(HighGenMatch_DY3_Fail, -1.0);
  QCD_Fail->Add(HighGenMatch_DY4_Fail, -1.0);

  QCD_Fail->Add(TTTo2L2Nu_Fail, -1.0);
  QCD_Fail->Add(TTToHadronic_Fail, -1.0);
  QCD_Fail->Add(TTToSemiLeptonic_Fail, -1.0);
  QCD_Fail->Add(WW_Fail, -1.0);
  QCD_Fail->Add(WZ_Fail, -1.0);
  QCD_Fail->Add(ZZ_Fail, -1.0);
  QCD_Fail->Add(W_Fail, -1.0);
  QCD_Fail->Add(W1_Fail, -1.0);
  QCD_Fail->Add(W2_Fail, -1.0);
  QCD_Fail->Add(W3_Fail, -1.0);
  QCD_Fail->Add(W4_Fail, -1.0);

  //we've subtracted off the backgrounds, now we just scale by 1.05
  // as mentioned in the AN to go from SS to OS regions.
  
  QCD_Pass->Scale(1.05);
  QCD_Fail->Scale(1.05);
  
  //now let's grab the Pass/Fail File and write all this stuff there.
  TFile* PassFailFile = new TFile("Distributions/PassFailOut.root","UPDATE");
  TDirectory* PassFail_PassDir = (TDirectory *) PassFailFile->Get("pass");
  TDirectory* PassFail_FailDir = (TDirectory *) PassFailFile->Get("fail");

  PassFail_PassDir->cd();
  QCD_Pass->Write();
  
  PassFail_FailDir->cd();
  QCD_Fail->Write();
}
