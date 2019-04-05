//Determine the final QCD contirbution to the signal region.
#include "TROOT.h"
#include "CalculateWJetsScaleFactor.cc"
#include <string>

TH1F* FinalizeControls(string ControlVar, float WJetsScaling)
{
  std::cout<<"Processing for: "<<ControlVar<<std::endl;
  TFile* QCDFile = new TFile("Distributions/QCDDistributions.root","READ");
  TDirectory* QCD_ControlDir = (TDirectory*) QCDFile->Get("control");

  TH1F* QCD_Control = (TH1F *) QCD_ControlDir->Get(("QCD_Data_"+ControlVar).c_str());
    
  TH1F* ZTauTau_Control = (TH1F *) QCD_ControlDir->Get(("QCD_GenMatch_DY_"+ControlVar).c_str());
  TH1F* ZTauTau1_Control = (TH1F *) QCD_ControlDir->Get(("QCD_GenMatch_DY1_"+ControlVar).c_str());
  TH1F* ZTauTau2_Control = (TH1F *) QCD_ControlDir->Get(("QCD_GenMatch_DY2_"+ControlVar).c_str());
  TH1F* ZTauTau3_Control = (TH1F *) QCD_ControlDir->Get(("QCD_GenMatch_DY3_"+ControlVar).c_str());
  TH1F* ZTauTau4_Control = (TH1F *) QCD_ControlDir->Get(("QCD_GenMatch_DY4_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY_Control = (TH1F *) QCD_ControlDir->Get(("QCD_LowGenMatch_DY_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY1_Control = (TH1F *) QCD_ControlDir->Get(("QCD_LowGenMatch_DY1_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY2_Control = (TH1F *) QCD_ControlDir->Get(("QCD_LowGenMatch_DY2_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY3_Control = (TH1F *) QCD_ControlDir->Get(("QCD_LowGenMatch_DY3_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY4_Control = (TH1F *) QCD_ControlDir->Get(("QCD_LowGenMatch_DY4_"+ControlVar).c_str());
  TH1F* GenMatch_DY_Control = (TH1F*) QCD_ControlDir->Get(("QCD_GenMatch_DY_"+ControlVar).c_str());
  TH1F* GenMatch_DY1_Control = (TH1F*) QCD_ControlDir->Get(("QCD_GenMatch_DY1_"+ControlVar).c_str());
  TH1F* GenMatch_DY2_Control = (TH1F*) QCD_ControlDir->Get(("QCD_GenMatch_DY2_"+ControlVar).c_str());
  TH1F* GenMatch_DY3_Control = (TH1F*) QCD_ControlDir->Get(("QCD_GenMatch_DY3_"+ControlVar).c_str());
  TH1F* GenMatch_DY4_Control = (TH1F*) QCD_ControlDir->Get(("QCD_GenMatch_DY4_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY_Control = (TH1F *) QCD_ControlDir->Get(("QCD_HighGenMatch_DY_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY1_Control = (TH1F *) QCD_ControlDir->Get(("QCD_HighGenMatch_DY1_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY2_Control = (TH1F *) QCD_ControlDir->Get(("QCD_HighGenMatch_DY2_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY3_Control = (TH1F *) QCD_ControlDir->Get(("QCD_HighGenMatch_DY3_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY4_Control = (TH1F *) QCD_ControlDir->Get(("QCD_HighGenMatch_DY4_"+ControlVar).c_str());

  TH1F* TTTo2L2Nu_Control = (TH1F *) QCD_ControlDir->Get(("QCD_TTTo2L2Nu_"+ControlVar).c_str());
  TH1F* TTToHadronic_Control = (TH1F *) QCD_ControlDir->Get(("QCD_TTToHadronic_"+ControlVar).c_str());
  TH1F* TTToSemiLeptonic_Control =  (TH1F *) QCD_ControlDir->Get(("QCD_TTToSemiLeptonic_"+ControlVar).c_str());
  TH1F* W_Control = (TH1F *) QCD_ControlDir->Get(("QCD_W_"+ControlVar).c_str());
  TH1F* W1_Control = (TH1F *) QCD_ControlDir->Get(("QCD_W1_"+ControlVar).c_str());
  TH1F* W2_Control = (TH1F *) QCD_ControlDir->Get(("QCD_W2_"+ControlVar).c_str());
  TH1F* W3_Control = (TH1F *) QCD_ControlDir->Get(("QCD_W3_"+ControlVar).c_str());
  TH1F* W4_Control = (TH1F *) QCD_ControlDir->Get(("QCD_W4_"+ControlVar).c_str());
  TH1F* WW_Control = (TH1F *) QCD_ControlDir->Get(("QCD_WW_"+ControlVar).c_str());
  TH1F* WZ_Control = (TH1F *) QCD_ControlDir->Get(("QCD_WZ_"+ControlVar).c_str());
  TH1F* ZZ_Control = (TH1F *) QCD_ControlDir->Get(("QCD_ZZ_"+ControlVar).c_str());

  QCD_Control->SetName(("QCD_"+ControlVar).c_str());

  W_Control->Add(W1_Control);
  W_Control->Add(W2_Control);
  W_Control->Add(W3_Control);
  W_Control->Add(W4_Control);
  
  W_Control->Scale(WJetsScaling);

  ZTauTau_Control->Add(ZTauTau1_Control);
  ZTauTau_Control->Add(ZTauTau2_Control);
  ZTauTau_Control->Add(ZTauTau3_Control);
  ZTauTau_Control->Add(ZTauTau4_Control);

  LowGenMatch_DY_Control->Add(LowGenMatch_DY1_Control);
  LowGenMatch_DY_Control->Add(LowGenMatch_DY2_Control);
  LowGenMatch_DY_Control->Add(LowGenMatch_DY3_Control);
  LowGenMatch_DY_Control->Add(LowGenMatch_DY4_Control);

  HighGenMatch_DY_Control->Add(HighGenMatch_DY1_Control);
  HighGenMatch_DY_Control->Add(HighGenMatch_DY2_Control);
  HighGenMatch_DY_Control->Add(HighGenMatch_DY3_Control);
  HighGenMatch_DY_Control->Add(HighGenMatch_DY4_Control);

  std::cout<<"Subtracting backgrounds..."<<std::endl;  
  //handle the pass side of things
  QCD_Control->Add(ZTauTau_Control, -1.0);
  QCD_Control->Add(LowGenMatch_DY_Control, -1.0);
  QCD_Control->Add(HighGenMatch_DY_Control, -1.0);  
  QCD_Control->Add(TTTo2L2Nu_Control, -1.0);
  QCD_Control->Add(TTToHadronic_Control, -1.0);
  QCD_Control->Add(TTToSemiLeptonic_Control, -1.0);
  QCD_Control->Add(WW_Control, -1.0);
  QCD_Control->Add(WZ_Control, -1.0);
  QCD_Control->Add(ZZ_Control, -1.0);  
  QCD_Control->Add(W_Control, -1.0);

  QCD_Control->Scale(1.05);

  return QCD_Control;
}

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
  TH1F* GenMatch_DY_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY_Pass");
  TH1F* GenMatch_DY1_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY1_Pass");
  TH1F* GenMatch_DY2_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY2_Pass");
  TH1F* GenMatch_DY3_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY3_Pass");
  TH1F* GenMatch_DY4_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY4_Pass");
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

  //Grab the TES relevant files
  TH1F* ZTauTau_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY_1.030000_Pass");
  TH1F* ZTauTau1_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY1_1.030000_Pass");
  TH1F* ZTauTau2_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY2_1.030000_Pass");
  TH1F* ZTauTau3_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY3_1.030000_Pass");
  TH1F* ZTauTau4_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY4_1.030000_Pass");
  TH1F* LowGenMatch_DY_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_LowGenMatch_DY_1.030000_Pass");
  TH1F* LowGenMatch_DY1_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_LowGenMatch_DY1_1.030000_Pass");
  TH1F* LowGenMatch_DY2_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_LowGenMatch_DY2_1.030000_Pass");
  TH1F* LowGenMatch_DY3_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_LowGenMatch_DY3_1.030000_Pass");
  TH1F* LowGenMatch_DY4_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_LowGenMatch_DY4_1.030000_Pass");
  TH1F* HighGenMatch_DY_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_HighGenMatch_DY_1.030000_Pass");
  TH1F* HighGenMatch_DY1_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_HighGenMatch_DY1_1.030000_Pass");
  TH1F* HighGenMatch_DY2_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_HighGenMatch_DY2_1.030000_Pass");
  TH1F* HighGenMatch_DY3_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_HighGenMatch_DY3_1.030000_Pass");
  TH1F* HighGenMatch_DY4_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_HighGenMatch_DY4_1.030000_Pass");
  TH1F* TTTo2L2Nu_TES_UP_Pass = (TH1F*)QCD_PassDir->Get("QCD_TTTo2L2Nu_1.030000_Pass");
  TH1F* TTToHadronic_TES_UP_Pass = (TH1F*)QCD_PassDir->Get("QCD_TTToHadronic_1.030000_Pass");
  TH1F* TTToSemiLeptonic_TES_UP_Pass = (TH1F*)QCD_PassDir->Get("QCD_TTToSemiLeptonic_1.030000_Pass");
  TH1F* W_TES_UP_Pass = (TH1F*)QCD_PassDir->Get("QCD_W_1.030000_Pass");
  TH1F* W1_TES_UP_Pass = (TH1F*)QCD_PassDir->Get("QCD_W1_1.030000_Pass");
  TH1F* W2_TES_UP_Pass = (TH1F*)QCD_PassDir->Get("QCD_W2_1.030000_Pass");
  TH1F* W3_TES_UP_Pass = (TH1F*)QCD_PassDir->Get("QCD_W3_1.030000_Pass");
  TH1F* W4_TES_UP_Pass = (TH1F*)QCD_PassDir->Get("QCD_W4_1.030000_Pass");
  TH1F* WW_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_WW_1.030000_Pass");
  TH1F* WZ_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_WZ_1.030000_Pass");
  TH1F* ZZ_TES_UP_Pass = (TH1F*) QCD_PassDir->Get("QCD_ZZ_1.030000_Pass");

  TH1F* ZTauTau_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY_0.970000_Pass");
  TH1F* ZTauTau1_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY1_0.970000_Pass");
  TH1F* ZTauTau2_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY2_0.970000_Pass");
  TH1F* ZTauTau3_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY3_0.970000_Pass");
  TH1F* ZTauTau4_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY4_0.970000_Pass");
  TH1F* LowGenMatch_DY_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_LowGenMatch_DY_0.970000_Pass");
  TH1F* LowGenMatch_DY1_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_LowGenMatch_DY1_0.970000_Pass");
  TH1F* LowGenMatch_DY2_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_LowGenMatch_DY2_0.970000_Pass");
  TH1F* LowGenMatch_DY3_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_LowGenMatch_DY3_0.970000_Pass");
  TH1F* LowGenMatch_DY4_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_LowGenMatch_DY4_0.970000_Pass");
  TH1F* GenMatch_DY_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY_TES_DOWN_Pass");
  TH1F* GenMatch_DY1_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY1_TES_DOWN_Pass");
  TH1F* GenMatch_DY2_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY2_TES_DOWN_Pass");
  TH1F* GenMatch_DY3_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY3_TES_DOWN_Pass");
  TH1F* GenMatch_DY4_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_GenMatch_DY4_TES_DOWN_Pass");
  TH1F* HighGenMatch_DY_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_HighGenMatch_DY_0.970000_Pass");
  TH1F* HighGenMatch_DY1_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_HighGenMatch_DY1_0.970000_Pass");
  TH1F* HighGenMatch_DY2_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_HighGenMatch_DY2_0.970000_Pass");
  TH1F* HighGenMatch_DY3_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_HighGenMatch_DY3_0.970000_Pass");
  TH1F* HighGenMatch_DY4_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_HighGenMatch_DY4_0.970000_Pass");
  TH1F* TTTo2L2Nu_TES_DOWN_Pass = (TH1F*)QCD_PassDir->Get("QCD_TTTo2L2Nu_0.970000_Pass");
  TH1F* TTToHadronic_TES_DOWN_Pass = (TH1F*)QCD_PassDir->Get("QCD_TTToHadronic_0.970000_Pass");
  TH1F* TTToSemiLeptonic_TES_DOWN_Pass = (TH1F*)QCD_PassDir->Get("QCD_TTToSemiLeptonic_0.970000_Pass");
  TH1F* W_TES_DOWN_Pass = (TH1F*)QCD_PassDir->Get("QCD_W_0.970000_Pass");
  TH1F* W1_TES_DOWN_Pass = (TH1F*)QCD_PassDir->Get("QCD_W1_0.970000_Pass");
  TH1F* W2_TES_DOWN_Pass = (TH1F*)QCD_PassDir->Get("QCD_W2_0.970000_Pass");
  TH1F* W3_TES_DOWN_Pass = (TH1F*)QCD_PassDir->Get("QCD_W3_0.970000_Pass");
  TH1F* W4_TES_DOWN_Pass = (TH1F*)QCD_PassDir->Get("QCD_W4_0.970000_Pass");
  TH1F* WW_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_WW_0.970000_Pass");
  TH1F* WZ_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_WZ_0.970000_Pass");
  TH1F* ZZ_TES_DOWN_Pass = (TH1F*) QCD_PassDir->Get("QCD_ZZ_0.970000_Pass");

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
  TH1F* GenMatch_DY_Fail  = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY_Fail");
  TH1F* GenMatch_DY1_Fail  = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY1_Fail");
  TH1F* GenMatch_DY2_Fail  = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY2_Fail");
  TH1F* GenMatch_DY3_Fail  = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY3_Fail");
  TH1F* GenMatch_DY4_Fail  = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY4_Fail");
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

  //Grab the TES relevant files
  TH1F* ZTauTau_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY_1.030000_Fail");
  TH1F* ZTauTau1_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY1_1.030000_Fail");
  TH1F* ZTauTau2_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY2_1.030000_Fail");
  TH1F* ZTauTau3_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY3_1.030000_Fail");
  TH1F* ZTauTau4_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY4_1.030000_Fail");
  TH1F* LowGenMatch_DY_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_LowGenMatch_DY_1.030000_Fail");
  TH1F* LowGenMatch_DY1_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_LowGenMatch_DY1_1.030000_Fail");
  TH1F* LowGenMatch_DY2_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_LowGenMatch_DY2_1.030000_Fail");
  TH1F* LowGenMatch_DY3_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_LowGenMatch_DY3_1.030000_Fail");
  TH1F* LowGenMatch_DY4_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_LowGenMatch_DY4_1.030000_Fail");
  TH1F* GenMatch_DY_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY_1.030000_Fail");
  TH1F* GenMatch_DY1_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY1_1.030000_Fail");
  TH1F* GenMatch_DY2_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY2_1.030000_Fail");
  TH1F* GenMatch_DY3_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY3_1.030000_Fail");
  TH1F* GenMatch_DY4_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY4_1.030000_Fail");
  TH1F* HighGenMatch_DY_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_HighGenMatch_DY_1.030000_Fail");
  TH1F* HighGenMatch_DY1_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_HighGenMatch_DY1_1.030000_Fail");
  TH1F* HighGenMatch_DY2_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_HighGenMatch_DY2_1.030000_Fail");
  TH1F* HighGenMatch_DY3_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_HighGenMatch_DY3_1.030000_Fail");
  TH1F* HighGenMatch_DY4_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_HighGenMatch_DY4_1.030000_Fail");
  TH1F* TTTo2L2Nu_TES_UP_Fail = (TH1F*)QCD_FailDir->Get("QCD_TTTo2L2Nu_1.030000_Fail");
  TH1F* TTToHadronic_TES_UP_Fail = (TH1F*)QCD_FailDir->Get("QCD_TTToHadronic_1.030000_Fail");
  TH1F* TTToSemiLeptonic_TES_UP_Fail = (TH1F*)QCD_FailDir->Get("QCD_TTToSemiLeptonic_1.030000_Fail");
  TH1F* W_TES_UP_Fail = (TH1F*)QCD_FailDir->Get("QCD_W_1.030000_Fail");
  TH1F* W1_TES_UP_Fail = (TH1F*)QCD_FailDir->Get("QCD_W1_1.030000_Fail");
  TH1F* W2_TES_UP_Fail = (TH1F*)QCD_FailDir->Get("QCD_W2_1.030000_Fail");
  TH1F* W3_TES_UP_Fail = (TH1F*)QCD_FailDir->Get("QCD_W3_1.030000_Fail");
  TH1F* W4_TES_UP_Fail = (TH1F*)QCD_FailDir->Get("QCD_W4_1.030000_Fail");
  TH1F* WW_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_WW_1.030000_Fail");
  TH1F* WZ_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_WZ_1.030000_Fail");
  TH1F* ZZ_TES_UP_Fail = (TH1F*) QCD_FailDir->Get("QCD_ZZ_1.030000_Fail");

  TH1F* ZTauTau_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY_0.970000_Fail");
  TH1F* ZTauTau1_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY1_0.970000_Fail");
  TH1F* ZTauTau2_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY2_0.970000_Fail");
  TH1F* ZTauTau3_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY3_0.970000_Fail");
  TH1F* ZTauTau4_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY4_0.970000_Fail");
  TH1F* LowGenMatch_DY_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_LowGenMatch_DY_0.970000_Fail");
  TH1F* LowGenMatch_DY1_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_LowGenMatch_DY1_0.970000_Fail");
  TH1F* LowGenMatch_DY2_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_LowGenMatch_DY2_0.970000_Fail");
  TH1F* LowGenMatch_DY3_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_LowGenMatch_DY3_0.970000_Fail");
  TH1F* LowGenMatch_DY4_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_LowGenMatch_DY4_0.970000_Fail");
  TH1F* GenMatch_DY_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY_0.970000_Fail");
  TH1F* GenMatch_DY1_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY1_0.970000_Fail");
  TH1F* GenMatch_DY2_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY2_0.970000_Fail");
  TH1F* GenMatch_DY3_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY3_0.970000_Fail");
  TH1F* GenMatch_DY4_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_GenMatch_DY4_0.970000_Fail");
  TH1F* HighGenMatch_DY_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_HighGenMatch_DY_0.970000_Fail");
  TH1F* HighGenMatch_DY1_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_HighGenMatch_DY1_0.970000_Fail");
  TH1F* HighGenMatch_DY2_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_HighGenMatch_DY2_0.970000_Fail");
  TH1F* HighGenMatch_DY3_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_HighGenMatch_DY3_0.970000_Fail");
  TH1F* HighGenMatch_DY4_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_HighGenMatch_DY4_0.970000_Fail");
  TH1F* TTTo2L2Nu_TES_DOWN_Fail = (TH1F*)QCD_FailDir->Get("QCD_TTTo2L2Nu_0.970000_Fail");
  TH1F* TTToHadronic_TES_DOWN_Fail = (TH1F*)QCD_FailDir->Get("QCD_TTToHadronic_0.970000_Fail");
  TH1F* TTToSemiLeptonic_TES_DOWN_Fail = (TH1F*)QCD_FailDir->Get("QCD_TTToSemiLeptonic_0.970000_Fail");
  TH1F* W_TES_DOWN_Fail = (TH1F*)QCD_FailDir->Get("QCD_W_0.970000_Fail");
  TH1F* W1_TES_DOWN_Fail = (TH1F*)QCD_FailDir->Get("QCD_W1_0.970000_Fail");
  TH1F* W2_TES_DOWN_Fail = (TH1F*)QCD_FailDir->Get("QCD_W2_0.970000_Fail");
  TH1F* W3_TES_DOWN_Fail = (TH1F*)QCD_FailDir->Get("QCD_W3_0.970000_Fail");
  TH1F* W4_TES_DOWN_Fail = (TH1F*)QCD_FailDir->Get("QCD_W4_0.970000_Fail");
  TH1F* WW_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_WW_0.970000_Fail");
  TH1F* WZ_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_WZ_0.970000_Fail");
  TH1F* ZZ_TES_DOWN_Fail = (TH1F*) QCD_FailDir->Get("QCD_ZZ_0.970000_Fail");

  //create copies for up and down W Normalizations and TES
  TH1F* QCD_WNorm_UP_Pass = (TH1F*)QCD_Pass->Clone();
  TH1F* QCD_WNorm_DOWN_Pass = (TH1F*)QCD_Pass->Clone();
  TH1F* QCD_WNorm_UP_Fail = (TH1F*)QCD_Fail->Clone();
  TH1F* QCD_WNorm_DOWN_Fail = (TH1F*)QCD_Fail->Clone();

  TH1F* QCD_TES_UP_Pass = (TH1F*)QCD_Pass->Clone();
  TH1F* QCD_TES_DOWN_Pass = (TH1F*)QCD_Pass->Clone();
  TH1F* QCD_TES_UP_Fail = (TH1F*)QCD_Fail->Clone();
  TH1F* QCD_TES_DOWN_Fail = (TH1F*)QCD_Fail->Clone();

  QCD_WNorm_UP_Pass->SetNameTitle("QCD_WNorm_UP_Pass","QCD_WNorm_UP_Pass");
  QCD_WNorm_DOWN_Pass->SetNameTitle("QCD_WNorm_DOWN_Pass","QCD_WNorm_DOWN_Pass");
  QCD_WNorm_UP_Fail->SetNameTitle("QCD_WNorm_UP_Fail","QCD_WNorm_UP_Fail");
  QCD_WNorm_DOWN_Fail->SetNameTitle("QCD_WNorm_DOWN_Fail","QCD_WNorm_DOWN_Fail");

  QCD_TES_UP_Pass->SetNameTitle("QCD_TES_UP_Pass","QCD_TES_UP_Pass");
  QCD_TES_DOWN_Pass->SetNameTitle("QCD_TES_DOWN_Pass","QCD_TES_DOWN_Pass");
  QCD_TES_UP_Fail->SetNameTitle("QCD_TES_UP_Fail","QCD_TES_UP_Fail");
  QCD_TES_DOWN_Fail->SetNameTitle("QCD_TES_DOWN_Fail","QCD_TES_DOWN_Fail");

  float WJetsScaling = CalculateWJetsScaleFactor();

  //Compile Histgrams. This will just make everything much simpler.
  std::cout<<"Compiling Histograms..."<<std::endl;
  W_Pass->Add(W1_Pass);
  W_Pass->Add(W2_Pass);
  W_Pass->Add(W3_Pass);
  W_Pass->Add(W4_Pass);
  W_Pass->Scale(WJetsScaling);

  W_TES_UP_Pass->Add(W1_TES_UP_Pass);
  W_TES_UP_Pass->Add(W2_TES_UP_Pass);
  W_TES_UP_Pass->Add(W3_TES_UP_Pass);
  W_TES_UP_Pass->Add(W4_TES_UP_Pass);
  W_TES_UP_Pass->Scale(WJetsScaling);

  W_TES_DOWN_Pass->Add(W1_TES_DOWN_Pass);
  W_TES_DOWN_Pass->Add(W2_TES_DOWN_Pass);
  W_TES_DOWN_Pass->Add(W3_TES_DOWN_Pass);
  W_TES_DOWN_Pass->Add(W4_TES_DOWN_Pass);
  W_TES_DOWN_Pass->Scale(WJetsScaling);

  W_Fail->Add(W1_Fail);
  W_Fail->Add(W2_Fail);
  W_Fail->Add(W3_Fail);
  W_Fail->Add(W4_Fail);
  W_Fail->Scale(WJetsScaling);

  W_TES_UP_Fail->Add(W1_TES_UP_Fail);
  W_TES_UP_Fail->Add(W2_TES_UP_Fail);
  W_TES_UP_Fail->Add(W3_TES_UP_Fail);
  W_TES_UP_Fail->Add(W4_TES_UP_Fail);
  W_TES_UP_Fail->Scale(WJetsScaling);

  W_TES_DOWN_Fail->Add(W1_TES_DOWN_Fail);
  W_TES_DOWN_Fail->Add(W2_TES_DOWN_Fail);
  W_TES_DOWN_Fail->Add(W3_TES_DOWN_Fail);
  W_TES_DOWN_Fail->Add(W4_TES_DOWN_Fail);
  W_TES_DOWN_Fail->Scale(WJetsScaling);
  
  //get copies of the w histograms to scale upward and downward
  TH1F* W_WNorm_UP_Pass = (TH1F*)W_Pass->Clone();
  TH1F* W_WNorm_DOWN_Pass = (TH1F*)W_Pass->Clone();
  TH1F* W_WNorm_UP_Fail = (TH1F*)W_Fail->Clone();
  TH1F* W_WNorm_DOWN_Fail = (TH1F*)W_Fail->Clone();
  W_WNorm_UP_Pass->Scale(1.10);
  W_WNorm_UP_Fail->Scale(1.10);
  W_WNorm_DOWN_Pass->Scale(0.90);
  W_WNorm_DOWN_Fail->Scale(0.90);

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

  ZTauTau_Fail->Add(ZTauTau1_Fail);
  ZTauTau_Fail->Add(ZTauTau2_Fail);
  ZTauTau_Fail->Add(ZTauTau3_Fail);
  ZTauTau_Fail->Add(ZTauTau4_Fail);
  
  ZTauTau_TES_UP_Fail->Add(ZTauTau1_TES_UP_Fail);
  ZTauTau_TES_UP_Fail->Add(ZTauTau2_TES_UP_Fail);
  ZTauTau_TES_UP_Fail->Add(ZTauTau3_TES_UP_Fail);
  ZTauTau_TES_UP_Fail->Add(ZTauTau4_TES_UP_Fail);
  
  ZTauTau_TES_DOWN_Fail->Add(ZTauTau1_TES_DOWN_Fail);
  ZTauTau_TES_DOWN_Fail->Add(ZTauTau2_TES_DOWN_Fail);
  ZTauTau_TES_DOWN_Fail->Add(ZTauTau3_TES_DOWN_Fail);
  ZTauTau_TES_DOWN_Fail->Add(ZTauTau4_TES_DOWN_Fail);

  LowGenMatch_DY_Pass->Add(LowGenMatch_DY1_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY2_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY3_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY4_Pass);

  LowGenMatch_DY_TES_UP_Pass->Add(LowGenMatch_DY1_TES_UP_Pass);
  LowGenMatch_DY_TES_UP_Pass->Add(LowGenMatch_DY2_TES_UP_Pass);
  LowGenMatch_DY_TES_UP_Pass->Add(LowGenMatch_DY3_TES_UP_Pass);
  LowGenMatch_DY_TES_UP_Pass->Add(LowGenMatch_DY4_TES_UP_Pass);

  LowGenMatch_DY_TES_DOWN_Pass->Add(LowGenMatch_DY1_TES_DOWN_Pass);
  LowGenMatch_DY_TES_DOWN_Pass->Add(LowGenMatch_DY2_TES_DOWN_Pass);
  LowGenMatch_DY_TES_DOWN_Pass->Add(LowGenMatch_DY3_TES_DOWN_Pass);
  LowGenMatch_DY_TES_DOWN_Pass->Add(LowGenMatch_DY4_TES_DOWN_Pass);

  LowGenMatch_DY_Fail->Add(LowGenMatch_DY1_Fail);
  LowGenMatch_DY_Fail->Add(LowGenMatch_DY2_Fail);
  LowGenMatch_DY_Fail->Add(LowGenMatch_DY3_Fail);
  LowGenMatch_DY_Fail->Add(LowGenMatch_DY4_Fail);

  LowGenMatch_DY_TES_UP_Fail->Add(LowGenMatch_DY1_TES_UP_Fail);
  LowGenMatch_DY_TES_UP_Fail->Add(LowGenMatch_DY2_TES_UP_Fail);
  LowGenMatch_DY_TES_UP_Fail->Add(LowGenMatch_DY3_TES_UP_Fail);
  LowGenMatch_DY_TES_UP_Fail->Add(LowGenMatch_DY4_TES_UP_Fail);

  LowGenMatch_DY_TES_DOWN_Fail->Add(LowGenMatch_DY1_TES_DOWN_Fail);
  LowGenMatch_DY_TES_DOWN_Fail->Add(LowGenMatch_DY2_TES_DOWN_Fail);
  LowGenMatch_DY_TES_DOWN_Fail->Add(LowGenMatch_DY3_TES_DOWN_Fail);
  LowGenMatch_DY_TES_DOWN_Fail->Add(LowGenMatch_DY4_TES_DOWN_Fail);  

  HighGenMatch_DY_Pass->Add(HighGenMatch_DY1_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY2_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY3_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY4_Pass);

  HighGenMatch_DY_TES_UP_Pass->Add(HighGenMatch_DY1_TES_UP_Pass);
  HighGenMatch_DY_TES_UP_Pass->Add(HighGenMatch_DY2_TES_UP_Pass);
  HighGenMatch_DY_TES_UP_Pass->Add(HighGenMatch_DY3_TES_UP_Pass);
  HighGenMatch_DY_TES_UP_Pass->Add(HighGenMatch_DY4_TES_UP_Pass);

  HighGenMatch_DY_TES_DOWN_Pass->Add(HighGenMatch_DY1_TES_DOWN_Pass);
  HighGenMatch_DY_TES_DOWN_Pass->Add(HighGenMatch_DY2_TES_DOWN_Pass);
  HighGenMatch_DY_TES_DOWN_Pass->Add(HighGenMatch_DY3_TES_DOWN_Pass);
  HighGenMatch_DY_TES_DOWN_Pass->Add(HighGenMatch_DY4_TES_DOWN_Pass);

  HighGenMatch_DY_Fail->Add(HighGenMatch_DY1_Fail);
  HighGenMatch_DY_Fail->Add(HighGenMatch_DY2_Fail);
  HighGenMatch_DY_Fail->Add(HighGenMatch_DY3_Fail);
  HighGenMatch_DY_Fail->Add(HighGenMatch_DY4_Fail);

  HighGenMatch_DY_TES_UP_Fail->Add(HighGenMatch_DY1_TES_UP_Fail);
  HighGenMatch_DY_TES_UP_Fail->Add(HighGenMatch_DY2_TES_UP_Fail);
  HighGenMatch_DY_TES_UP_Fail->Add(HighGenMatch_DY3_TES_UP_Fail);
  HighGenMatch_DY_TES_UP_Fail->Add(HighGenMatch_DY4_TES_UP_Fail);

  HighGenMatch_DY_TES_DOWN_Fail->Add(HighGenMatch_DY1_TES_DOWN_Fail);
  HighGenMatch_DY_TES_DOWN_Fail->Add(HighGenMatch_DY2_TES_DOWN_Fail);
  HighGenMatch_DY_TES_DOWN_Fail->Add(HighGenMatch_DY3_TES_DOWN_Fail);
  HighGenMatch_DY_TES_DOWN_Fail->Add(HighGenMatch_DY4_TES_DOWN_Fail);

  std::cout<<"Subtracting backgrounds..."<<std::endl;  
  //handle the pass side of things
  QCD_Pass->Add(ZTauTau_Pass, -1.0);
  QCD_Pass->Add(LowGenMatch_DY_Pass, -1.0);
  QCD_Pass->Add(HighGenMatch_DY_Pass, -1.0);  
  QCD_Pass->Add(TTTo2L2Nu_Pass, -1.0);
  QCD_Pass->Add(TTToHadronic_Pass, -1.0);
  QCD_Pass->Add(TTToSemiLeptonic_Pass, -1.0);
  QCD_Pass->Add(WW_Pass, -1.0);
  QCD_Pass->Add(WZ_Pass, -1.0);
  QCD_Pass->Add(ZZ_Pass, -1.0);  
  QCD_Pass->Add(W_Pass, -1.0);

  //Do the same thing for the up and down distributions,
  // only with the proper W distribution used.
  QCD_WNorm_UP_Pass->Add(ZTauTau_Pass, -1.0);
  QCD_WNorm_UP_Pass->Add(LowGenMatch_DY_Pass, -1.0);  
  QCD_WNorm_UP_Pass->Add(HighGenMatch_DY_Pass, -1.0);  
  QCD_WNorm_UP_Pass->Add(TTTo2L2Nu_Pass, -1.0);
  QCD_WNorm_UP_Pass->Add(TTToHadronic_Pass, -1.0);
  QCD_WNorm_UP_Pass->Add(TTToSemiLeptonic_Pass, -1.0);
  QCD_WNorm_UP_Pass->Add(WW_Pass, -1.0);
  QCD_WNorm_UP_Pass->Add(WZ_Pass, -1.0);
  QCD_WNorm_UP_Pass->Add(ZZ_Pass, -1.0);  
  QCD_WNorm_UP_Pass->Add(W_WNorm_UP_Pass, -1.0);

  QCD_WNorm_DOWN_Pass->Add(ZTauTau_Pass, -1.0);
  QCD_WNorm_DOWN_Pass->Add(LowGenMatch_DY_Pass, -1.0);
  QCD_WNorm_DOWN_Pass->Add(HighGenMatch_DY_Pass, -1.0);  
  QCD_WNorm_DOWN_Pass->Add(TTTo2L2Nu_Pass, -1.0);
  QCD_WNorm_DOWN_Pass->Add(TTToHadronic_Pass, -1.0);
  QCD_WNorm_DOWN_Pass->Add(TTToSemiLeptonic_Pass, -1.0);
  QCD_WNorm_DOWN_Pass->Add(WW_Pass, -1.0);
  QCD_WNorm_DOWN_Pass->Add(WZ_Pass, -1.0);
  QCD_WNorm_DOWN_Pass->Add(ZZ_Pass, -1.0);  
  QCD_WNorm_DOWN_Pass->Add(W_WNorm_DOWN_Pass, -1.0);

  //Handle the fail side of things
  QCD_Fail->Add(ZTauTau_Fail, -1.0);  
  QCD_Fail->Add(LowGenMatch_DY_Fail, -1.0);  
  QCD_Fail->Add(HighGenMatch_DY_Fail, -1.0);  
  QCD_Fail->Add(TTTo2L2Nu_Fail, -1.0);
  QCD_Fail->Add(TTToHadronic_Fail, -1.0);
  QCD_Fail->Add(TTToSemiLeptonic_Fail, -1.0);
  QCD_Fail->Add(WW_Fail, -1.0);
  QCD_Fail->Add(WZ_Fail, -1.0);
  QCD_Fail->Add(ZZ_Fail, -1.0);
  QCD_Fail->Add(W_Fail, -1.0);  

  //and the up/downs
  QCD_WNorm_UP_Fail->Add(ZTauTau_Fail, -1.0);
  QCD_WNorm_UP_Fail->Add(LowGenMatch_DY_Fail, -1.0);  
  QCD_WNorm_UP_Fail->Add(HighGenMatch_DY_Fail, -1.0);  
  QCD_WNorm_UP_Fail->Add(TTTo2L2Nu_Fail, -1.0);
  QCD_WNorm_UP_Fail->Add(TTToHadronic_Fail, -1.0);
  QCD_WNorm_UP_Fail->Add(TTToSemiLeptonic_Fail, -1.0);
  QCD_WNorm_UP_Fail->Add(WW_Fail, -1.0);
  QCD_WNorm_UP_Fail->Add(WZ_Fail, -1.0);
  QCD_WNorm_UP_Fail->Add(ZZ_Fail, -1.0);  
  QCD_WNorm_UP_Fail->Add(W_WNorm_UP_Fail, -1.0);

  QCD_WNorm_DOWN_Fail->Add(ZTauTau_Fail, -1.0);
  QCD_WNorm_DOWN_Fail->Add(LowGenMatch_DY_Fail, -1.0);  
  QCD_WNorm_DOWN_Fail->Add(HighGenMatch_DY_Fail, -1.0);  
  QCD_WNorm_DOWN_Fail->Add(TTTo2L2Nu_Fail, -1.0);
  QCD_WNorm_DOWN_Fail->Add(TTToHadronic_Fail, -1.0);
  QCD_WNorm_DOWN_Fail->Add(TTToSemiLeptonic_Fail, -1.0);
  QCD_WNorm_DOWN_Fail->Add(WW_Fail, -1.0);
  QCD_WNorm_DOWN_Fail->Add(WZ_Fail, -1.0);
  QCD_WNorm_DOWN_Fail->Add(ZZ_Fail, -1.0);  
  QCD_WNorm_DOWN_Fail->Add(W_WNorm_DOWN_Fail, -1.0);

  // now we handle the TES distributions
  std::cout<<"TES Backgrounds..."<<std::endl;
  QCD_TES_UP_Pass->Add(ZTauTau_TES_UP_Pass, -1.0);
  QCD_TES_UP_Pass->Add(LowGenMatch_DY_TES_UP_Pass, -1.0);
  QCD_TES_UP_Pass->Add(HighGenMatch_DY_TES_UP_Pass, -1.0);
  QCD_TES_UP_Pass->Add(TTTo2L2Nu_TES_UP_Pass, -1.0);
  QCD_TES_UP_Pass->Add(TTToHadronic_TES_UP_Pass, -1.0);
  QCD_TES_UP_Pass->Add(TTToSemiLeptonic_TES_UP_Pass, -1.0);
  QCD_TES_UP_Pass->Add(WW_TES_UP_Pass, -1.0);
  QCD_TES_UP_Pass->Add(WZ_TES_UP_Pass, -1.0);
  QCD_TES_UP_Pass->Add(ZZ_TES_UP_Pass, -1.0);
  QCD_TES_UP_Pass->Add(W_TES_UP_Pass, -1.0);

  QCD_TES_DOWN_Pass->Add(ZTauTau_TES_DOWN_Pass, -1.0);
  QCD_TES_DOWN_Pass->Add(LowGenMatch_DY_TES_DOWN_Pass, -1.0);
  QCD_TES_DOWN_Pass->Add(HighGenMatch_DY_TES_DOWN_Pass, -1.0);
  QCD_TES_DOWN_Pass->Add(TTTo2L2Nu_TES_DOWN_Pass, -1.0);
  QCD_TES_DOWN_Pass->Add(TTToHadronic_TES_DOWN_Pass, -1.0);
  QCD_TES_DOWN_Pass->Add(TTToSemiLeptonic_TES_DOWN_Pass, -1.0);
  QCD_TES_DOWN_Pass->Add(WW_TES_DOWN_Pass, -1.0);
  QCD_TES_DOWN_Pass->Add(WZ_TES_DOWN_Pass, -1.0);
  QCD_TES_DOWN_Pass->Add(ZZ_TES_DOWN_Pass, -1.0);
  QCD_TES_DOWN_Pass->Add(W_TES_DOWN_Pass, -1.0);

  QCD_TES_UP_Fail->Add(ZTauTau_TES_UP_Fail, -1.0);
  QCD_TES_UP_Fail->Add(LowGenMatch_DY_TES_UP_Fail, -1.0);
  QCD_TES_UP_Fail->Add(HighGenMatch_DY_TES_UP_Fail, -1.0);
  QCD_TES_UP_Fail->Add(TTTo2L2Nu_TES_UP_Fail, -1.0);
  QCD_TES_UP_Fail->Add(TTToHadronic_TES_UP_Fail, -1.0);
  QCD_TES_UP_Fail->Add(TTToSemiLeptonic_TES_UP_Fail, -1.0);
  QCD_TES_UP_Fail->Add(WW_TES_UP_Fail, -1.0);
  QCD_TES_UP_Fail->Add(WZ_TES_UP_Fail, -1.0);
  QCD_TES_UP_Fail->Add(ZZ_TES_UP_Fail, -1.0);
  QCD_TES_UP_Fail->Add(W_TES_UP_Fail, -1.0);

  QCD_TES_DOWN_Fail->Add(ZTauTau_TES_DOWN_Fail, -1.0);
  QCD_TES_DOWN_Fail->Add(LowGenMatch_DY_TES_DOWN_Fail, -1.0);
  QCD_TES_DOWN_Fail->Add(HighGenMatch_DY_TES_DOWN_Fail, -1.0);
  QCD_TES_DOWN_Fail->Add(TTTo2L2Nu_TES_DOWN_Fail, -1.0);
  QCD_TES_DOWN_Fail->Add(TTToHadronic_TES_DOWN_Fail, -1.0);
  QCD_TES_DOWN_Fail->Add(TTToSemiLeptonic_TES_DOWN_Fail, -1.0);
  QCD_TES_DOWN_Fail->Add(WW_TES_DOWN_Fail, -1.0);
  QCD_TES_DOWN_Fail->Add(WZ_TES_DOWN_Fail, -1.0);
  QCD_TES_DOWN_Fail->Add(ZZ_TES_DOWN_Fail, -1.0);
  QCD_TES_DOWN_Fail->Add(W_TES_DOWN_Fail, -1.0);

  //we've subtracted off the backgrounds, now we just scale by 1.05
  // as mentioned in the AN to go from SS to OS regions.

  //changed to 1.12 to test yuta's numbers
  
  QCD_Pass->Scale(1.12);
  QCD_WNorm_UP_Pass->Scale(1.12);
  QCD_WNorm_DOWN_Pass->Scale(1.12);
  QCD_TES_UP_Pass->Scale(1.12);
  QCD_TES_DOWN_Pass->Scale(1.12);

  QCD_Fail->Scale(1.12);
  QCD_WNorm_UP_Fail->Scale(1.12);
  QCD_WNorm_DOWN_Fail->Scale(1.12);
  QCD_TES_UP_Pass->Scale(1.12);
  QCD_TES_DOWN_Pass->Scale(1.12);
  
  //Make the Controls
  TH1F* QCD_MuPt;
  TH1F* QCD_TauPt;
  TH1F* QCD_MuEta;
  TH1F* QCD_TauEta;
  TH1F* QCD_NJets;
  TH1F* QCD_NBtag; 
  TH1F* QCD_ZMass;
  TH1F* QCD_ZPT;
  TH1F* QCD_MT;

  QCD_MuPt = FinalizeControls("MuPt",WJetsScaling);
  QCD_TauPt = FinalizeControls("TauPt",WJetsScaling);
  QCD_MuEta = FinalizeControls("MuEta",WJetsScaling);
  QCD_TauEta = FinalizeControls("TauEta",WJetsScaling);
  QCD_NJets = FinalizeControls("njets",WJetsScaling);
  QCD_NBtag = FinalizeControls("nbtag",WJetsScaling);
  QCD_ZMass = FinalizeControls("ZMass",WJetsScaling);
  QCD_ZPT = FinalizeControls("ZPT",WJetsScaling);
  QCD_MT = FinalizeControls("MT",WJetsScaling);

  //now let's grab the Pass/Fail File and write all this stuff there.
  TFile* PassFailFile = new TFile("Distributions/PassFailOut.root","UPDATE");
  TDirectory* PassFail_PassDir = (TDirectory *) PassFailFile->Get("pass");
  TDirectory* PassFail_FailDir = (TDirectory *) PassFailFile->Get("fail");
  TDirectory* PassFail_ControlDir = (TDirectory *) PassFailFile->Get("control");

  PassFail_PassDir->cd();
  QCD_Pass->Write();
  QCD_WNorm_UP_Pass->Write();
  QCD_WNorm_DOWN_Pass->Write();
  QCD_TES_UP_Pass->Write();
  QCD_TES_DOWN_Pass->Write();
  
  PassFail_FailDir->cd();
  QCD_Fail->Write();
  QCD_WNorm_UP_Fail->Write();
  QCD_WNorm_DOWN_Fail->Write();
  QCD_TES_UP_Fail->Write();
  QCD_TES_DOWN_Fail->Write();

  PassFail_ControlDir->cd();
  QCD_MuPt->Write();
  QCD_TauPt->Write();
  QCD_MuEta->Write();
  QCD_TauEta->Write();
  QCD_NJets->Write();
  QCD_NBtag->Write();
  QCD_ZMass->Write();
  QCD_ZPT->Write();
  QCD_MT->Write();
}
