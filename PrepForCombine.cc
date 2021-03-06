#include "TROOT.h"

void PrepForCombine(std::string IsoWorkingPoint, int PtBracket, int EtaBracket)
{
  TFile* PassFailFile = new TFile("Distributions/PassFailOut.root");
  TDirectory* passDirectory = (TDirectory*) PassFailFile->Get("pass");
  TDirectory* failDirectory = (TDirectory*) PassFailFile->Get("fail");

  //pass
  TH1F* Data_Pass = (TH1F*) passDirectory->Get("Data_Pass");
  
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

  TH1F* TTTo2L2Nu_TES_UP_Pass = (TH1F*) passDirectory->Get("TTTo2L2Nu_1.030000_Pass");
  TH1F* TTToHadronic_TES_UP_Pass = (TH1F*) passDirectory->Get("TTToHadronic_1.030000_Pass");
  TH1F* TTToSemiLeptonic_TES_UP_Pass = (TH1F*) passDirectory->Get("TTToSemiLeptonic_1.030000_Pass");
  TH1F* TTTo2L2Nu_TES_DOWN_Pass = (TH1F*) passDirectory->Get("TTTo2L2Nu_0.970000_Pass");
  TH1F* TTToHadronic_TES_DOWN_Pass = (TH1F*) passDirectory->Get("TTToHadronic_0.970000_Pass");
  TH1F* TTToSemiLeptonic_TES_DOWN_Pass = (TH1F*) passDirectory->Get("TTToSemiLeptonic_0.970000_Pass");

  TH1F* W_Pass = (TH1F*) passDirectory->Get("Rescaled_WJets_Pass");
  TH1F* W_WNorm_UP_Pass = (TH1F*) passDirectory->Get("Rescaled_WJets_WNorm_UP_Pass");
  TH1F* W_WNorm_DOWN_Pass = (TH1F*) passDirectory->Get("Rescaled_WJets_WNorm_DOWN_Pass");
  TH1F* WW_Pass = (TH1F*) passDirectory->Get("WW_Pass");
  TH1F* WZ_Pass = (TH1F*) passDirectory->Get("WZ_Pass");
  TH1F* ZZ_Pass = (TH1F*) passDirectory->Get("ZZ_Pass");
  TH1F* WW_TES_UP_Pass = (TH1F*) passDirectory->Get("WW_1.030000_Pass");
  TH1F* WZ_TES_UP_Pass = (TH1F*) passDirectory->Get("WZ_1.030000_Pass");
  TH1F* ZZ_TES_UP_Pass = (TH1F*) passDirectory->Get("ZZ_1.030000_Pass");
  TH1F* WW_TES_DOWN_Pass = (TH1F*) passDirectory->Get("WW_0.970000_Pass");
  TH1F* WZ_TES_DOWN_Pass = (TH1F*) passDirectory->Get("WZ_0.970000_Pass");
  TH1F* ZZ_TES_DOWN_Pass = (TH1F*) passDirectory->Get("ZZ_0.970000_Pass");
  TH1F* QCD_Pass = (TH1F*) passDirectory->Get("QCD_Pass");
  TH1F* QCD_WNorm_UP_Pass = (TH1F*) passDirectory->Get("QCD_WNorm_UP_Pass");
  TH1F* QCD_WNorm_DOWN_Pass = (TH1F*) passDirectory->Get("QCD_WNorm_DOWN_Pass");
  TH1F* QCD_TES_UP_Pass = (TH1F*) passDirectory->Get("QCD_TES_UP_Pass");
  TH1F* QCD_TES_DOWN_Pass= (TH1F*) passDirectory->Get("QCD_TES_DOWN_Pass");

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
  TH1F* HighGenMatch_DY_Shape_UP_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY_1.100000_Pass");
  TH1F* HighGenMatch_DY1_Shape_UP_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY1_1.100000_Pass");
  TH1F* HighGenMatch_DY2_Shape_UP_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY2_1.100000_Pass");
  TH1F* HighGenMatch_DY3_Shape_UP_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY3_1.100000_Pass");
  TH1F* HighGenMatch_DY4_Shape_UP_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY4_1.100000_Pass");
  TH1F* HighGenMatch_DY_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY_0.900000_Pass");
  TH1F* HighGenMatch_DY1_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY1_0.900000_Pass");
  TH1F* HighGenMatch_DY2_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY2_0.900000_Pass");
  TH1F* HighGenMatch_DY3_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY3_0.900000_Pass");
  TH1F* HighGenMatch_DY4_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("HighGenMatch_DY4_0.900000_Pass");
  
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

  //fail
  TH1F* Data_Fail = (TH1F*) failDirectory->Get("Data_Fail");
  
  TH1F* LowGenMatch_DY_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY_Fail");
  TH1F* LowGenMatch_DY1_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY1_Fail");
  TH1F* LowGenMatch_DY2_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY2_Fail");
  TH1F* LowGenMatch_DY3_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY3_Fail");
  TH1F* LowGenMatch_DY4_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY4_Fail");
  TH1F* HighGenMatch_DY_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY_Fail");
  TH1F* HighGenMatch_DY1_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY1_Fail");
  TH1F* HighGenMatch_DY2_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY2_Fail");
  TH1F* HighGenMatch_DY3_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY3_Fail");
  TH1F* HighGenMatch_DY4_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY4_Fail");
  TH1F* ZTauTau_Fail = (TH1F*) failDirectory->Get("GenMatch_DY_Fail");
  TH1F* ZTauTau1_Fail = (TH1F*) failDirectory->Get("GenMatch_DY1_Fail");
  TH1F* ZTauTau2_Fail = (TH1F*) failDirectory->Get("GenMatch_DY2_Fail");
  TH1F* ZTauTau3_Fail = (TH1F*) failDirectory->Get("GenMatch_DY3_Fail");
  TH1F* ZTauTau4_Fail = (TH1F*) failDirectory->Get("GenMatch_DY4_Fail");

  TH1F* TTTo2L2Nu_Fail = (TH1F*) failDirectory->Get("TTTo2L2Nu_Fail");
  TH1F* TTToHadronic_Fail = (TH1F*) failDirectory->Get("TTToHadronic_Fail");
  TH1F* TTToSemiLeptonic_Fail = (TH1F*) failDirectory->Get("TTToSemiLeptonic_Fail");

  TH1F* TTTo2L2Nu_TES_UP_Fail = (TH1F*) failDirectory->Get("TTTo2L2Nu_1.030000_Fail");
  TH1F* TTToHadronic_TES_UP_Fail = (TH1F*) failDirectory->Get("TTToHadronic_1.030000_Fail");
  TH1F* TTToSemiLeptonic_TES_UP_Fail = (TH1F*) failDirectory->Get("TTToSemiLeptonic_1.030000_Fail");
  TH1F* TTTo2L2Nu_TES_DOWN_Fail = (TH1F*) failDirectory->Get("TTTo2L2Nu_0.970000_Fail");
  TH1F* TTToHadronic_TES_DOWN_Fail = (TH1F*) failDirectory->Get("TTToHadronic_0.970000_Fail");
  TH1F* TTToSemiLeptonic_TES_DOWN_Fail = (TH1F*) failDirectory->Get("TTToSemiLeptonic_0.970000_Fail");

  TH1F* W_Fail = (TH1F*) failDirectory->Get("Rescaled_WJets_Fail");
  TH1F* W_WNorm_UP_Fail = (TH1F*) failDirectory->Get("Rescaled_WJets_WNorm_UP_Fail");
  TH1F* W_WNorm_DOWN_Fail = (TH1F*) failDirectory->Get("Rescaled_WJets_WNorm_DOWN_Fail");
  TH1F* WW_Fail = (TH1F*) failDirectory->Get("WW_Fail");
  TH1F* WZ_Fail = (TH1F*) failDirectory->Get("WZ_Fail");
  TH1F* ZZ_Fail = (TH1F*) failDirectory->Get("ZZ_Fail");
  TH1F* WW_TES_UP_Fail = (TH1F*) failDirectory->Get("WW_1.030000_Fail");
  TH1F* WZ_TES_UP_Fail = (TH1F*) failDirectory->Get("WZ_1.030000_Fail");
  TH1F* ZZ_TES_UP_Fail = (TH1F*) failDirectory->Get("ZZ_1.030000_Fail");
  TH1F* WW_TES_DOWN_Fail = (TH1F*) failDirectory->Get("WW_0.970000_Fail");
  TH1F* WZ_TES_DOWN_Fail = (TH1F*) failDirectory->Get("WZ_0.970000_Fail");
  TH1F* ZZ_TES_DOWN_Fail = (TH1F*) failDirectory->Get("ZZ_0.970000_Fail");
  TH1F* QCD_Fail = (TH1F*) failDirectory->Get("QCD_Fail");
  TH1F* QCD_WNorm_UP_Fail = (TH1F*) failDirectory->Get("QCD_WNorm_UP_Fail");
  TH1F* QCD_WNorm_DOWN_Fail = (TH1F*) failDirectory->Get("QCD_WNorm_DOWN_Fail");
  TH1F* QCD_TES_UP_Fail = (TH1F*) failDirectory->Get("QCD_TES_UP_Fail");
  TH1F* QCD_TES_DOWN_Fail= (TH1F*) failDirectory->Get("QCD_TES_DOWN_Fail");
  
  TH1F* LowGenMatch_DY_Shape_UP_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY_1.100000_Fail");
  TH1F* LowGenMatch_DY1_Shape_UP_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY1_1.100000_Fail");
  TH1F* LowGenMatch_DY2_Shape_UP_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY2_1.100000_Fail");
  TH1F* LowGenMatch_DY3_Shape_UP_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY3_1.100000_Fail");
  TH1F* LowGenMatch_DY4_Shape_UP_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY4_1.100000_Fail");
  TH1F* LowGenMatch_DY_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY_0.900000_Fail");
  TH1F* LowGenMatch_DY1_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY1_0.900000_Fail");
  TH1F* LowGenMatch_DY2_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY2_0.900000_Fail");
  TH1F* LowGenMatch_DY3_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY3_0.900000_Fail");
  TH1F* LowGenMatch_DY4_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("LowGenMatch_DY4_0.900000_Fail");
  TH1F* HighGenMatch_DY_Shape_UP_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY_1.100000_Fail");
  TH1F* HighGenMatch_DY1_Shape_UP_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY1_1.100000_Fail");
  TH1F* HighGenMatch_DY2_Shape_UP_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY2_1.100000_Fail");
  TH1F* HighGenMatch_DY3_Shape_UP_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY3_1.100000_Fail");
  TH1F* HighGenMatch_DY4_Shape_UP_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY4_1.100000_Fail");
  TH1F* HighGenMatch_DY_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY_0.900000_Fail");
  TH1F* HighGenMatch_DY1_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY1_0.900000_Fail");
  TH1F* HighGenMatch_DY2_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY2_0.900000_Fail");
  TH1F* HighGenMatch_DY3_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY3_0.900000_Fail");
  TH1F* HighGenMatch_DY4_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("HighGenMatch_DY4_0.900000_Fail");
  
  TH1F* ZTauTau_TES_UP_Fail = (TH1F*) failDirectory->Get("GenMatch_DY_1.030000_Fail");
  TH1F* ZTauTau1_TES_UP_Fail = (TH1F*) failDirectory->Get("GenMatch_DY1_1.030000_Fail");
  TH1F* ZTauTau2_TES_UP_Fail = (TH1F*) failDirectory->Get("GenMatch_DY2_1.030000_Fail");
  TH1F* ZTauTau3_TES_UP_Fail = (TH1F*) failDirectory->Get("GenMatch_DY3_1.030000_Fail");
  TH1F* ZTauTau4_TES_UP_Fail = (TH1F*) failDirectory->Get("GenMatch_DY4_1.030000_Fail");
  TH1F* ZTauTau_TES_DOWN_Fail = (TH1F*) failDirectory->Get("GenMatch_DY_0.970000_Fail");
  TH1F* ZTauTau1_TES_DOWN_Fail = (TH1F*) failDirectory->Get("GenMatch_DY1_0.970000_Fail");
  TH1F* ZTauTau2_TES_DOWN_Fail = (TH1F*) failDirectory->Get("GenMatch_DY2_0.970000_Fail");
  TH1F* ZTauTau3_TES_DOWN_Fail = (TH1F*) failDirectory->Get("GenMatch_DY3_0.970000_Fail");
  TH1F* ZTauTau4_TES_DOWN_Fail = (TH1F*) failDirectory->Get("GenMatch_DY4_0.970000_Fail");

  // after this we need only worry about unnumbered DY histos
  std::cout<<"Simplifying the Pass DY Histos"<<std::endl;
  //pass compiling  
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY1_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY2_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY3_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY4_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY1_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY2_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY3_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY4_Pass);
  
  LowGenMatch_DY_Shape_UP_Pass->Add(LowGenMatch_DY1_Shape_UP_Pass);
  LowGenMatch_DY_Shape_UP_Pass->Add(LowGenMatch_DY2_Shape_UP_Pass);
  LowGenMatch_DY_Shape_UP_Pass->Add(LowGenMatch_DY3_Shape_UP_Pass);
  LowGenMatch_DY_Shape_UP_Pass->Add(LowGenMatch_DY4_Shape_UP_Pass);
  LowGenMatch_DY_Shape_DOWN_Pass->Add(LowGenMatch_DY1_Shape_DOWN_Pass);
  LowGenMatch_DY_Shape_DOWN_Pass->Add(LowGenMatch_DY2_Shape_DOWN_Pass);
  LowGenMatch_DY_Shape_DOWN_Pass->Add(LowGenMatch_DY3_Shape_DOWN_Pass);
  LowGenMatch_DY_Shape_DOWN_Pass->Add(LowGenMatch_DY4_Shape_DOWN_Pass);
  HighGenMatch_DY_Shape_UP_Pass->Add(HighGenMatch_DY1_Shape_UP_Pass);
  HighGenMatch_DY_Shape_UP_Pass->Add(HighGenMatch_DY2_Shape_UP_Pass);
  HighGenMatch_DY_Shape_UP_Pass->Add(HighGenMatch_DY3_Shape_UP_Pass);
  HighGenMatch_DY_Shape_UP_Pass->Add(HighGenMatch_DY4_Shape_UP_Pass);
  HighGenMatch_DY_Shape_DOWN_Pass->Add(HighGenMatch_DY1_Shape_DOWN_Pass);
  HighGenMatch_DY_Shape_DOWN_Pass->Add(HighGenMatch_DY2_Shape_DOWN_Pass);
  HighGenMatch_DY_Shape_DOWN_Pass->Add(HighGenMatch_DY3_Shape_DOWN_Pass);
  HighGenMatch_DY_Shape_DOWN_Pass->Add(HighGenMatch_DY4_Shape_DOWN_Pass);

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
  
  //fail compiling
  std::cout<<"Simplifying the Fail DY Histos"<<std::endl;
  LowGenMatch_DY_Fail->Add(LowGenMatch_DY1_Fail);
  LowGenMatch_DY_Fail->Add(LowGenMatch_DY2_Fail);
  LowGenMatch_DY_Fail->Add(LowGenMatch_DY3_Fail);
  LowGenMatch_DY_Fail->Add(LowGenMatch_DY4_Fail);
  HighGenMatch_DY_Fail->Add(HighGenMatch_DY1_Fail);
  HighGenMatch_DY_Fail->Add(HighGenMatch_DY2_Fail);
  HighGenMatch_DY_Fail->Add(HighGenMatch_DY3_Fail);
  HighGenMatch_DY_Fail->Add(HighGenMatch_DY4_Fail);
  
  LowGenMatch_DY_Shape_UP_Fail->Add(LowGenMatch_DY1_Shape_UP_Fail);
  LowGenMatch_DY_Shape_UP_Fail->Add(LowGenMatch_DY2_Shape_UP_Fail);
  LowGenMatch_DY_Shape_UP_Fail->Add(LowGenMatch_DY3_Shape_UP_Fail);
  LowGenMatch_DY_Shape_UP_Fail->Add(LowGenMatch_DY4_Shape_UP_Fail);
  LowGenMatch_DY_Shape_DOWN_Fail->Add(LowGenMatch_DY1_Shape_DOWN_Fail);
  LowGenMatch_DY_Shape_DOWN_Fail->Add(LowGenMatch_DY2_Shape_DOWN_Fail);
  LowGenMatch_DY_Shape_DOWN_Fail->Add(LowGenMatch_DY3_Shape_DOWN_Fail);
  LowGenMatch_DY_Shape_DOWN_Fail->Add(LowGenMatch_DY4_Shape_DOWN_Fail);
  HighGenMatch_DY_Shape_UP_Fail->Add(HighGenMatch_DY1_Shape_UP_Fail);
  HighGenMatch_DY_Shape_UP_Fail->Add(HighGenMatch_DY2_Shape_UP_Fail);
  HighGenMatch_DY_Shape_UP_Fail->Add(HighGenMatch_DY3_Shape_UP_Fail);
  HighGenMatch_DY_Shape_UP_Fail->Add(HighGenMatch_DY4_Shape_UP_Fail);
  HighGenMatch_DY_Shape_DOWN_Fail->Add(HighGenMatch_DY1_Shape_DOWN_Fail);
  HighGenMatch_DY_Shape_DOWN_Fail->Add(HighGenMatch_DY2_Shape_DOWN_Fail);
  HighGenMatch_DY_Shape_DOWN_Fail->Add(HighGenMatch_DY3_Shape_DOWN_Fail);
  HighGenMatch_DY_Shape_DOWN_Fail->Add(HighGenMatch_DY4_Shape_DOWN_Fail);
  
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

  std::cout<<"Writing the file"<<std::endl;
  std::cout<<"Pass.."<<std::endl;
  std::string FileName;
  std::string PtBracket_Name = "";
  std::string EtaBracket_Name = "";
  if(PtBracket == 1)
    {
      //tau pt 20-25
      PtBracket_Name = "_TauPt20-25_";
    }
  else if(PtBracket == 2)
    {
      //tau pt 25-32
      PtBracket_Name = "_TauPt25-30_";
    }
  else if(PtBracket == 3)
    {
      //tau pt 30-32
      PtBracket_Name = "_TauPt30-32_";
    }
  else if(PtBracket == 4)
    {
      //tau pt 32-35
      PtBracket_Name = "_TauPt32-35_";
    }
  else if(PtBracket == 5)
    {
      //tau pt 30-35
      PtBracket_Name = "_TauPt30-35_";
    }
  else if(PtBracket == 6)
    {
      //tau pt 35-40
      PtBracket_Name = "_TauPt35-40_";
    }
  else if(PtBracket == 7)
    {
      //tau pt 40-50
      PtBracket_Name = "_TauPt40-50_";
    }
  else if(PtBracket == 8)
    {
      //tau pt 50-60
      PtBracket_Name = "_TauPt50-60_";
    }
  else if(PtBracket == 9)
    {
      //tau pt 60-70
      PtBracket_Name = "_TauPt60-70_";
    }
  else if(PtBracket == 10)
    {
      //tau pt 70-100
      PtBracket_Name = "_TauPt70-100_";
    }
  else if(PtBracket == 11)
    {
      //tau pt > 100
      PtBracket_Name = "_TauPt100Up_";
    }

  if(EtaBracket == 1)
    {
      //tau eta < 1.479
      EtaBracket_Name = "_TauEtaBarrel_";
    }
  else if(EtaBracket == 2)
    {
      //tau eta > 1.479
      EtaBracket_Name = "_TauEtaEndcaps_";
    }
  FileName = IsoWorkingPoint+PtBracket_Name+EtaBracket_Name;
  TFile* CombineFile = new TFile(("Distributions/"+FileName+"CombineFile.root").c_str(),"RECREATE");
  //compile Pass histos  
  TDirectory* CombinePassDirectory = CombineFile->mkdir("passOS");
  CombinePassDirectory->cd();
  
  Data_Pass->SetNameTitle("data_obs","data_obs");
  Data_Pass->Write();
  
  LowGenMatch_DY_Pass->SetNameTitle("DYB","DYB");
  LowGenMatch_DY_Pass->Write();
  
  LowGenMatch_DY_Shape_UP_Pass->SetNameTitle("DYB_muToTauUp","DYB_muToTauUp");
  LowGenMatch_DY_Shape_UP_Pass->Write();

  LowGenMatch_DY_Shape_DOWN_Pass->SetNameTitle("DYB_muToTauDown","DYB_muToTauDown");
  LowGenMatch_DY_Shape_DOWN_Pass->Write();
  
  HighGenMatch_DY_Pass->SetNameTitle("DYJ","DYJ");
  HighGenMatch_DY_Pass->Write();
  
  HighGenMatch_DY_Shape_UP_Pass->SetNameTitle("DYJ_UP","DYJ_UP");
  HighGenMatch_DY_Shape_UP_Pass->Write();

  HighGenMatch_DY_Shape_DOWN_Pass->SetNameTitle("DYJ_DOWN","DYJ_DOWN");
  HighGenMatch_DY_Shape_DOWN_Pass->Write();

  ZTauTau_Pass->SetNameTitle("DYS","DYS");  
  ZTauTau_Pass->Write();

  ZTauTau_TES_UP_Pass->SetNameTitle("DYS_TESUp","DYS_TESUp");
  ZTauTau_TES_UP_Pass->Write();

  ZTauTau_TES_DOWN_Pass->SetNameTitle("DYS_TESDown","DYS_TESDown");
  ZTauTau_TES_DOWN_Pass->Write();
  
  TH1F* TT_Pass = new TH1F("TT",
			   "TT",
			   TTTo2L2Nu_Pass->GetSize()-2,
			   TTTo2L2Nu_Pass->GetXaxis()->GetXmin(),
			   TTTo2L2Nu_Pass->GetXaxis()->GetXmax());
  TT_Pass->Add(TTTo2L2Nu_Pass,TTToHadronic_Pass);
  TT_Pass->Add(TTToSemiLeptonic_Pass);
  TT_Pass->Write();

  TH1F* TT_TES_UP_Pass = new TH1F("TT_TESUp",
				  "TT_TESUp",
				  TTTo2L2Nu_TES_UP_Pass->GetSize()-2,
				  TTTo2L2Nu_TES_UP_Pass->GetXaxis()->GetXmin(),
				  TTTo2L2Nu_TES_UP_Pass->GetXaxis()->GetXmax());
  TT_TES_UP_Pass->Add(TTTo2L2Nu_TES_UP_Pass,TTToHadronic_TES_UP_Pass);
  TT_TES_UP_Pass->Add(TTToSemiLeptonic_TES_UP_Pass);
  TT_TES_UP_Pass->Write();

  TH1F* TT_TES_DOWN_Pass = new TH1F("TT_TESDown",
				  "TT_TESDown",
				  TTTo2L2Nu_TES_DOWN_Pass->GetSize()-2,
				  TTTo2L2Nu_TES_DOWN_Pass->GetXaxis()->GetXmin(),
				  TTTo2L2Nu_TES_DOWN_Pass->GetXaxis()->GetXmax());
  TT_TES_DOWN_Pass->Add(TTTo2L2Nu_TES_DOWN_Pass,TTToHadronic_TES_DOWN_Pass);
  TT_TES_DOWN_Pass->Add(TTToSemiLeptonic_TES_DOWN_Pass);
  TT_TES_DOWN_Pass->Write();
  
  TH1F* DiBoson_Pass = new TH1F("VV",
				"VV",
				WW_Pass->GetSize()-2,
				WW_Pass->GetXaxis()->GetXmin(),
				WW_Pass->GetXaxis()->GetXmax());
  DiBoson_Pass->Add(WW_Pass,WZ_Pass);
  DiBoson_Pass->Add(ZZ_Pass);
  DiBoson_Pass->Write();

  TH1F* DiBoson_TES_UP_Pass = new TH1F("VV_TESUp",
				       "VV_TESUp",
				       WW_TES_UP_Pass->GetSize()-2,
				       WW_TES_UP_Pass->GetXaxis()->GetXmin(),
				       WW_TES_UP_Pass->GetXaxis()->GetXmax());
  DiBoson_TES_UP_Pass->Add(WW_TES_UP_Pass,WZ_TES_UP_Pass);
  DiBoson_TES_UP_Pass->Add(ZZ_TES_UP_Pass);
  DiBoson_TES_UP_Pass->Write();

  TH1F* DiBoson_TES_DOWN_Pass = new TH1F("VV_TESDown",
				       "VV_TESDown",
				       WW_TES_DOWN_Pass->GetSize()-2,
				       WW_TES_DOWN_Pass->GetXaxis()->GetXmin(),
				       WW_TES_DOWN_Pass->GetXaxis()->GetXmax());
  DiBoson_TES_DOWN_Pass->Add(WW_TES_DOWN_Pass,WZ_TES_DOWN_Pass);
  DiBoson_TES_DOWN_Pass->Add(ZZ_TES_DOWN_Pass);
  DiBoson_TES_DOWN_Pass->Write();
  

  QCD_Pass->SetNameTitle("QCD","QCD");
  QCD_Pass->Write();
  
  QCD_WNorm_UP_Pass->SetNameTitle("QCD_WnormUp","QCD_WnormUp");
  QCD_WNorm_UP_Pass->Write();

  QCD_WNorm_DOWN_Pass->SetNameTitle("QCD_WnormDown", "QCD_WnormDown");
  QCD_WNorm_DOWN_Pass->Write();

  QCD_TES_UP_Pass->SetNameTitle("QCD_TESUp","QCD_TESDown");
  QCD_TES_UP_Pass->Write();

  QCD_TES_DOWN_Pass->SetNameTitle("QCD_TESDown","QCD_TESDown");
  QCD_TES_DOWN_Pass->Write();

  W_Pass->SetNameTitle("W","W");
  W_Pass->Write();
  
  W_WNorm_UP_Pass->SetNameTitle("W_WnormUp","W_WnormUp");
  W_WNorm_UP_Pass->Write();
  
  W_WNorm_DOWN_Pass->SetNameTitle("W_WnormDown","W_WnormDown");
  W_WNorm_DOWN_Pass->Write();

  //Compile Fail Histos
  std::cout<<"Fail..."<<std::endl;
  TDirectory* CombineFailDirectory = CombineFile->mkdir("failOS");
  CombineFailDirectory->cd();

  Data_Fail->SetNameTitle("data_obs","data_obs");
  Data_Fail->Write();
  
  LowGenMatch_DY_Fail->SetNameTitle("DYB","DYB");
  LowGenMatch_DY_Fail->Write();
  
  LowGenMatch_DY_Shape_UP_Fail->SetNameTitle("DYB_muToTauUp","DYB_MuToTauUp");
  LowGenMatch_DY_Shape_UP_Fail->Write();

  LowGenMatch_DY_Shape_DOWN_Fail->SetNameTitle("DYB_muToTauDown","DYB_muToTauDown");
  LowGenMatch_DY_Shape_DOWN_Fail->Write();
  
  HighGenMatch_DY_Fail->SetNameTitle("DYJ","DYJ");
  HighGenMatch_DY_Fail->Write();
  
  HighGenMatch_DY_Shape_UP_Fail->SetNameTitle("DYJ_UP","DYJ_UP");
  HighGenMatch_DY_Shape_UP_Fail->Write();

  HighGenMatch_DY_Shape_DOWN_Fail->SetNameTitle("DYJ_DOWN","DYJ_DOWN");
  HighGenMatch_DY_Shape_DOWN_Fail->Write();
    
  ZTauTau_Fail->SetNameTitle("DYS","DYS");  
  ZTauTau_Fail->Write();

  ZTauTau_TES_UP_Fail->SetNameTitle("DYS_TESUp","DYS_TESUp");
  ZTauTau_TES_UP_Fail->Write();

  ZTauTau_TES_DOWN_Fail->SetNameTitle("DYS_TESDown","DYS_TESDown");
  ZTauTau_TES_DOWN_Fail->Write();

  TH1F* TT_Fail = new TH1F("TT",
			   "TT",
			   TTTo2L2Nu_Fail->GetSize()-2,
			   TTTo2L2Nu_Fail->GetXaxis()->GetXmin(),
			   TTTo2L2Nu_Fail->GetXaxis()->GetXmax());
  TT_Fail->Add(TTTo2L2Nu_Fail,TTToHadronic_Fail);
  TT_Fail->Add(TTToSemiLeptonic_Fail);
  TT_Fail->Write();

  TH1F* TT_TES_UP_Fail = new TH1F("TT_TESUp",
				  "TT_TESUp",
				  TTTo2L2Nu_TES_UP_Fail->GetSize()-2,
				  TTTo2L2Nu_TES_UP_Fail->GetXaxis()->GetXmin(),
				  TTTo2L2Nu_TES_UP_Fail->GetXaxis()->GetXmax());
  TT_TES_UP_Fail->Add(TTTo2L2Nu_TES_UP_Fail,TTToHadronic_TES_UP_Fail);
  TT_TES_UP_Fail->Add(TTToSemiLeptonic_TES_UP_Fail);
  TT_TES_UP_Fail->Write();

  TH1F* TT_TES_DOWN_Fail = new TH1F("TT_TESDown",
				  "TT_TESDown",
				  TTTo2L2Nu_TES_DOWN_Fail->GetSize()-2,
				  TTTo2L2Nu_TES_DOWN_Fail->GetXaxis()->GetXmin(),
				  TTTo2L2Nu_TES_DOWN_Fail->GetXaxis()->GetXmax());
  TT_TES_DOWN_Fail->Add(TTTo2L2Nu_TES_DOWN_Fail,TTToHadronic_TES_DOWN_Fail);
  TT_TES_DOWN_Fail->Add(TTToSemiLeptonic_TES_DOWN_Fail);
  TT_TES_DOWN_Pass->Write();
  
  TH1F* DiBoson_Fail = new TH1F("VV",
				"VV",
				W_Fail->GetSize()-2,
				W_Fail->GetXaxis()->GetXmin(),
				W_Fail->GetXaxis()->GetXmax());
  DiBoson_Fail->Add(WW_Fail,WZ_Fail);
  DiBoson_Fail->Add(ZZ_Fail);
  DiBoson_Fail->Write();

  TH1F* DiBoson_TES_UP_Fail = new TH1F("VV_TESUp",
				       "VV_TESUp",
				       WW_TES_UP_Fail->GetSize()-2,
				       WW_TES_UP_Fail->GetXaxis()->GetXmin(),
				       WW_TES_UP_Fail->GetXaxis()->GetXmax());
  DiBoson_TES_UP_Fail->Add(WW_TES_UP_Fail,WZ_TES_UP_Fail);
  DiBoson_TES_UP_Fail->Add(ZZ_TES_UP_Fail);
  DiBoson_TES_UP_Fail->Write();

  TH1F* DiBoson_TES_DOWN_Fail = new TH1F("VV_TESDown",
				       "VV_TESDown",
				       WW_TES_DOWN_Fail->GetSize()-2,
				       WW_TES_DOWN_Fail->GetXaxis()->GetXmin(),
				       WW_TES_DOWN_Fail->GetXaxis()->GetXmax());
  DiBoson_TES_DOWN_Fail->Add(WW_TES_DOWN_Fail,WZ_TES_DOWN_Fail);
  DiBoson_TES_DOWN_Fail->Add(ZZ_TES_DOWN_Fail);
  DiBoson_TES_DOWN_Fail->Write();

  QCD_Fail->SetNameTitle("QCD","QCD");
  QCD_Fail->Write();

  QCD_WNorm_UP_Fail->SetNameTitle("QCD_WnormUp","QCD_WnormUp");
  QCD_WNorm_UP_Fail->Write();

  QCD_WNorm_DOWN_Fail->SetNameTitle("QCD_WnormDown", "QCD_WnormDown");
  QCD_WNorm_DOWN_Fail->Write();

  QCD_TES_UP_Fail->SetNameTitle("QCD_TESUp","QCD_TESUp");
  QCD_TES_UP_Fail->Write();
  
  QCD_TES_DOWN_Fail->SetNameTitle("QCD_TESDown","QCD_TESDown");
  QCD_TES_DOWN_Fail->Write();

  W_Fail->SetNameTitle("W","W");
  W_Fail->Write();  
  
  W_WNorm_UP_Fail->SetNameTitle("W_WnormUp","W_WnormUp");
  W_WNorm_UP_Fail->Write();
  
  W_WNorm_DOWN_Fail->SetNameTitle("W_WnormDown","W_WnormDown");
  W_WNorm_DOWN_Fail->Write();

  CombineFile->Close();
  PassFailFile->Close();
}
