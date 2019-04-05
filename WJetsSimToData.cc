//Creates the final scaling factor and scales the signal region W+Jets by it
#include "TROOT.h"
#include <string>

TH1F* ScaleControl(string ControlVar)
{
  std::cout<<"Developing corrections in control region: "<<ControlVar<<std::endl;
  TFile* WJetFile = new TFile("Distributions/WJetsDistributions.root");
  TDirectory* WJet_ControlDir = (TDirectory*) WJetFile->Get("control");

  TH1F* DataEstimated_WJets_Control = (TH1F *) WJet_ControlDir->Get(("WJets_Data_"+ControlVar).c_str());
    
  TH1F* ZTauTau_Control = (TH1F *) WJet_ControlDir->Get(("WJets_GenMatch_DY_"+ControlVar).c_str());
  TH1F* ZTauTau1_Control = (TH1F *) WJet_ControlDir->Get(("WJets_GenMatch_DY1_"+ControlVar).c_str());
  TH1F* ZTauTau2_Control = (TH1F *) WJet_ControlDir->Get(("WJets_GenMatch_DY2_"+ControlVar).c_str());
  TH1F* ZTauTau3_Control = (TH1F *) WJet_ControlDir->Get(("WJets_GenMatch_DY3_"+ControlVar).c_str());
  TH1F* ZTauTau4_Control = (TH1F *) WJet_ControlDir->Get(("WJets_GenMatch_DY4_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY_Control = (TH1F *) WJet_ControlDir->Get(("WJets_LowGenMatch_DY_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY1_Control = (TH1F *) WJet_ControlDir->Get(("WJets_LowGenMatch_DY1_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY2_Control = (TH1F *) WJet_ControlDir->Get(("WJets_LowGenMatch_DY2_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY3_Control = (TH1F *) WJet_ControlDir->Get(("WJets_LowGenMatch_DY3_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY4_Control = (TH1F *) WJet_ControlDir->Get(("WJets_LowGenMatch_DY4_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY_Control = (TH1F *) WJet_ControlDir->Get(("WJets_HighGenMatch_DY_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY1_Control = (TH1F *) WJet_ControlDir->Get(("WJets_HighGenMatch_DY1_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY2_Control = (TH1F *) WJet_ControlDir->Get(("WJets_HighGenMatch_DY2_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY3_Control = (TH1F *) WJet_ControlDir->Get(("WJets_HighGenMatch_DY3_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY4_Control = (TH1F *) WJet_ControlDir->Get(("WJets_HighGenMatch_DY4_"+ControlVar).c_str());

  TH1F* TTTo2L2Nu_Control = (TH1F *) WJet_ControlDir->Get(("WJets_TTTo2L2Nu_"+ControlVar).c_str());
  TH1F* TTToHadronic_Control = (TH1F *) WJet_ControlDir->Get(("WJets_TTToHadronic_"+ControlVar).c_str());
  TH1F* TTToSemiLeptonic_Control =  (TH1F *) WJet_ControlDir->Get(("WJets_TTToSemiLeptonic_"+ControlVar).c_str());
  TH1F* W_Control = (TH1F *) WJet_ControlDir->Get(("WJets_W_"+ControlVar).c_str());
  TH1F* W1_Control = (TH1F *) WJet_ControlDir->Get(("WJets_W1_"+ControlVar).c_str());
  TH1F* W2_Control = (TH1F *) WJet_ControlDir->Get(("WJets_W2_"+ControlVar).c_str());
  TH1F* W3_Control = (TH1F *) WJet_ControlDir->Get(("WJets_W3_"+ControlVar).c_str());
  TH1F* W4_Control = (TH1F *) WJet_ControlDir->Get(("WJets_W4_"+ControlVar).c_str());
  TH1F* WW_Control = (TH1F *) WJet_ControlDir->Get(("WJets_WW_"+ControlVar).c_str());
  TH1F* WZ_Control = (TH1F *) WJet_ControlDir->Get(("WJets_WZ_"+ControlVar).c_str());
  TH1F* ZZ_Control = (TH1F *) WJet_ControlDir->Get(("WJets_ZZ_"+ControlVar).c_str());
  TH1F* QCD_Control = (TH1F *) WJet_ControlDir->Get(("CorrectedQCDContribution_"+ControlVar).c_str());

  W_Control->Add(W1_Control);
  W_Control->Add(W2_Control);
  W_Control->Add(W3_Control);
  W_Control->Add(W4_Control);

  std::cout<<"Before: DataEstimated_WJets_Control: "<<DataEstimated_WJets_Control->Integral()<<std::endl;
  std::cout<<"Before: W_Control: "<<W_Control->Integral()<<std::endl;

  DataEstimated_WJets_Control->Add(ZTauTau_Control, -1.0);
  DataEstimated_WJets_Control->Add(ZTauTau1_Control, -1.0);
  DataEstimated_WJets_Control->Add(ZTauTau2_Control, -1.0);
  DataEstimated_WJets_Control->Add(ZTauTau3_Control, -1.0);
  DataEstimated_WJets_Control->Add(ZTauTau4_Control, -1.0);
  DataEstimated_WJets_Control->Add(LowGenMatch_DY_Control, -1.0);
  DataEstimated_WJets_Control->Add(LowGenMatch_DY1_Control, -1.0);
  DataEstimated_WJets_Control->Add(LowGenMatch_DY2_Control, -1.0);
  DataEstimated_WJets_Control->Add(LowGenMatch_DY3_Control, -1.0);
  DataEstimated_WJets_Control->Add(LowGenMatch_DY4_Control, -1.0);
  DataEstimated_WJets_Control->Add(HighGenMatch_DY_Control, -1.0);
  DataEstimated_WJets_Control->Add(HighGenMatch_DY1_Control, -1.0);
  DataEstimated_WJets_Control->Add(HighGenMatch_DY2_Control, -1.0);
  DataEstimated_WJets_Control->Add(HighGenMatch_DY3_Control, -1.0);
  DataEstimated_WJets_Control->Add(HighGenMatch_DY4_Control, -1.0);

  DataEstimated_WJets_Control->Add(TTTo2L2Nu_Control, -1.0);
  DataEstimated_WJets_Control->Add(TTToHadronic_Control, -1.0);
  DataEstimated_WJets_Control->Add(TTToSemiLeptonic_Control, -1.0);
  DataEstimated_WJets_Control->Add(WW_Control, -1.0);
  DataEstimated_WJets_Control->Add(WZ_Control, -1.0);
  DataEstimated_WJets_Control->Add(ZZ_Control, -1.0);
  DataEstimated_WJets_Control->Add(QCD_Control, -1.0);  

  std::cout<<"DataEstimated_WJets_Control: "<<DataEstimated_WJets_Control->Integral()<<std::endl;
  std::cout<<"W_Control: "<<W_Control->Integral()<<std::endl;
  std::cout<<"WJets Scale Factor: "<<(DataEstimated_WJets_Control->Integral()) / (W_Control->Integral())<<std::endl;
  
  float WJetsScale = DataEstimated_WJets_Control->Integral() / W_Control->Integral();  

  TFile* PassFailFile = new TFile("Distributions/PassFailOut.root");
  TDirectory* PassFail_ControlDir = (TDirectory* ) PassFailFile->Get("control");  

  TH1F* PassFail_W_Control = (TH1F *) PassFail_ControlDir->Get(("W_"+ControlVar).c_str());
  TH1F* PassFail_W1_Control = (TH1F *) PassFail_ControlDir->Get(("W1_"+ControlVar).c_str());
  TH1F* PassFail_W2_Control = (TH1F *) PassFail_ControlDir->Get(("W2_"+ControlVar).c_str());
  TH1F* PassFail_W3_Control = (TH1F *) PassFail_ControlDir->Get(("W3_"+ControlVar).c_str());
  TH1F* PassFail_W4_Control = (TH1F *) PassFail_ControlDir->Get(("W4_"+ControlVar).c_str());
  
  TH1F* Rescaled_WJets_Control = new TH1F(*PassFail_W_Control);
  Rescaled_WJets_Control->Add(PassFail_W1_Control);
  Rescaled_WJets_Control->Add(PassFail_W2_Control);
  Rescaled_WJets_Control->Add(PassFail_W3_Control);
  Rescaled_WJets_Control->Add(PassFail_W4_Control);
  
  Rescaled_WJets_Control->Scale(WJetsScale);

  Rescaled_WJets_Control->SetNameTitle(("Rescaled_WJets_"+ControlVar).c_str(),("Rescaled_WJets_"+ControlVar).c_str());

  return Rescaled_WJets_Control;
}

void WJetsSimToData()
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

  TFile* PassFailFile = new TFile("Distributions/PassFailOut.root","UPDATE");
  TDirectory* PassFail_PassDir = (TDirectory *) PassFailFile->Get("pass");
  TDirectory* PassFail_FailDir = (TDirectory *) PassFailFile->Get("fail");

  TH1F* PassFail_W_Pass = (TH1F *) PassFail_PassDir->Get("W_Pass");
  TH1F* PassFail_W1_Pass = (TH1F *) PassFail_PassDir->Get("W1_Pass");
  TH1F* PassFail_W2_Pass = (TH1F *) PassFail_PassDir->Get("W2_Pass");
  TH1F* PassFail_W3_Pass = (TH1F *) PassFail_PassDir->Get("W3_Pass");
  TH1F* PassFail_W4_Pass = (TH1F *) PassFail_PassDir->Get("W4_Pass");
  TH1F* PassFail_W_Fail = (TH1F *) PassFail_FailDir->Get("W_Fail");
  TH1F* PassFail_W1_Fail = (TH1F *) PassFail_FailDir->Get("W1_Fail");
  TH1F* PassFail_W2_Fail = (TH1F *) PassFail_FailDir->Get("W2_Fail");
  TH1F* PassFail_W3_Fail = (TH1F *) PassFail_FailDir->Get("W3_Fail");
  TH1F* PassFail_W4_Fail = (TH1F *) PassFail_FailDir->Get("W4_Fail");
  
  std::cout<<"Creating Newly Scaled Histos"<<std::endl;
  TH1F* Rescaled_WJets_Pass = new TH1F(*PassFail_W_Pass);
  TH1F* Rescaled_WJets_Fail = new TH1F(*PassFail_W_Fail);
  
  Rescaled_WJets_Pass->Add(PassFail_W1_Pass);
  Rescaled_WJets_Pass->Add(PassFail_W2_Pass);
  Rescaled_WJets_Pass->Add(PassFail_W3_Pass);
  Rescaled_WJets_Pass->Add(PassFail_W4_Pass);

  Rescaled_WJets_Fail->Add(PassFail_W1_Fail);
  Rescaled_WJets_Fail->Add(PassFail_W2_Fail);
  Rescaled_WJets_Fail->Add(PassFail_W3_Fail);
  Rescaled_WJets_Fail->Add(PassFail_W4_Fail);

  Rescaled_WJets_Pass->Scale(WJetsScaleFactor);
  Rescaled_WJets_Fail->Scale(WJetsScaleFactor);

  Rescaled_WJets_Pass->SetName("Rescaled_WJets_Pass");
  Rescaled_WJets_Fail->SetName("Rescaled_WJets_Fail");
  
  std::cout<<"Creating Scale Controls..."<<std::endl;
  TH1F* Rescaled_WJets_MuPt;
  TH1F* Rescaled_WJets_TauPt;
  TH1F* Rescaled_WJets_MuEta;
  TH1F* Rescaled_WJets_TauEta;
  TH1F* Rescaled_WJets_NJets;
  TH1F* Rescaled_WJets_NBtag;
  TH1F* Rescaled_WJets_ZMass;
  TH1F* Rescaled_WJets_ZPT;
  TH1F* Rescaled_WJets_MT;
  
  Rescaled_WJets_MuPt = ScaleControl("MuPt");
  Rescaled_WJets_TauPt = ScaleControl("TauPt");
  Rescaled_WJets_MuEta = ScaleControl("MuEta");
  Rescaled_WJets_TauEta = ScaleControl("TauEta");
  Rescaled_WJets_NJets = ScaleControl("njets");
  Rescaled_WJets_NBtag = ScaleControl("nbtag");
  Rescaled_WJets_ZMass = ScaleControl("ZMass");
  Rescaled_WJets_ZPT = ScaleControl("ZPT");
  Rescaled_WJets_MT = ScaleControl("MT");

  //create the up and down W distributions.
  TH1F* Rescaled_WJets_WNorm_UP_Pass = (TH1F*) Rescaled_WJets_Pass->Clone();
  TH1F* Rescaled_WJets_WNorm_DOWN_Pass = (TH1F*) Rescaled_WJets_Pass->Clone();
  TH1F* Rescaled_WJets_WNorm_UP_Fail = (TH1F*) Rescaled_WJets_Fail->Clone();
  TH1F* Rescaled_WJets_WNorm_DOWN_Fail = (TH1F*) Rescaled_WJets_Fail->Clone();

  Rescaled_WJets_WNorm_UP_Pass->Scale(1.10);
  Rescaled_WJets_WNorm_UP_Fail->Scale(1.10);
  Rescaled_WJets_WNorm_DOWN_Pass->Scale(0.90);
  Rescaled_WJets_WNorm_DOWN_Pass->Scale(0.90);

  Rescaled_WJets_WNorm_UP_Pass->SetNameTitle("Rescaled_WJets_WNorm_UP_Pass","Rescaled_WJets_WNorm_UP_Pass");
  Rescaled_WJets_WNorm_DOWN_Pass->SetNameTitle("Rescaled_WJets_WNorm_DOWN_Pass","Rescaled_WJets_WNorm_DOWN_Pass");
  Rescaled_WJets_WNorm_UP_Fail->SetNameTitle("Rescaled_WJets_WNorm_UP_Fail","Rescaled_WJets_WNorm_UP_Fail");
  Rescaled_WJets_WNorm_DOWN_Fail->SetNameTitle("Rescaled_WJets_WNorm_DOWN_Fail","Rescaled_WJets_WNorm_DOWN_Fail");

  //Shove this back into the old file, and we'll roll with that.
  std::cout<<"Writing Newly Scaled Histos to the Pass/Fail File"<<std::endl;
  PassFail_PassDir->cd();
  Rescaled_WJets_Pass->Write();
  Rescaled_WJets_WNorm_UP_Pass->Write();
  Rescaled_WJets_WNorm_DOWN_Pass->Write();

  PassFail_FailDir->cd();
  Rescaled_WJets_Fail->Write();
  Rescaled_WJets_WNorm_UP_Fail->Write();
  Rescaled_WJets_WNorm_DOWN_Fail->Write();

  TDirectory* PassFail_ControlDir = (TDirectory *) PassFailFile->Get("control");
  PassFail_ControlDir->cd();
  Rescaled_WJets_MuPt->Write();
  Rescaled_WJets_TauPt->Write();
  Rescaled_WJets_MuEta->Write();
  Rescaled_WJets_TauEta->Write();
  Rescaled_WJets_NJets->Write();
  Rescaled_WJets_NBtag->Write();
  Rescaled_WJets_ZMass->Write();
  Rescaled_WJets_ZPT->Write();
  Rescaled_WJets_MT->Write();
  
  PassFailFile->Write();
  PassFailFile->Close();
}
