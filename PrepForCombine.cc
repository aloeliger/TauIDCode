#include "TROOT.h"

void PrepForCombine()
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
  TH1F* W_Pass = (TH1F*) passDirectory->Get("Rescaled_WJets_Pass");
  TH1F* WW_Pass = (TH1F*) passDirectory->Get("WW_Pass");
  TH1F* WZ_Pass = (TH1F*) passDirectory->Get("WZ_Pass");
  TH1F* ZZ_Pass = (TH1F*) passDirectory->Get("ZZ_Pass");
  TH1F* QCD_Pass = (TH1F*) passDirectory->Get("QCD_Pass");

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
  
  TH1F* ZTauTau_Shape_UP_Pass = (TH1F*) passDirectory->Get("GenMatch_DY_1.030000_Pass");
  TH1F* ZTauTau1_Shape_UP_Pass = (TH1F*) passDirectory->Get("GenMatch_DY1_1.030000_Pass");
  TH1F* ZTauTau2_Shape_UP_Pass = (TH1F*) passDirectory->Get("GenMatch_DY2_1.030000_Pass");
  TH1F* ZTauTau3_Shape_UP_Pass = (TH1F*) passDirectory->Get("GenMatch_DY3_1.030000_Pass");
  TH1F* ZTauTau4_Shape_UP_Pass = (TH1F*) passDirectory->Get("GenMatch_DY4_1.030000_Pass");
  TH1F* ZTauTau_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("GenMatch_DY_0.970000_Pass");
  TH1F* ZTauTau1_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("GenMatch_DY1_0.970000_Pass");
  TH1F* ZTauTau2_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("GenMatch_DY2_0.970000_Pass");
  TH1F* ZTauTau3_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("GenMatch_DY3_0.970000_Pass");
  TH1F* ZTauTau4_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("GenMatch_DY4_0.970000_Pass");

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
  TH1F* W_Fail = (TH1F*) failDirectory->Get("Rescaled_WJets_Fail");
  TH1F* WW_Fail = (TH1F*) failDirectory->Get("WW_Fail");
  TH1F* WZ_Fail = (TH1F*) failDirectory->Get("WZ_Fail");
  TH1F* ZZ_Fail = (TH1F*) failDirectory->Get("ZZ_Fail");
  TH1F* QCD_Fail = (TH1F*) failDirectory->Get("QCD_Fail");
  
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
  
  TH1F* ZTauTau_Shape_UP_Fail = (TH1F*) failDirectory->Get("GenMatch_DY_1.030000_Fail");
  TH1F* ZTauTau1_Shape_UP_Fail = (TH1F*) failDirectory->Get("GenMatch_DY1_1.030000_Fail");
  TH1F* ZTauTau2_Shape_UP_Fail = (TH1F*) failDirectory->Get("GenMatch_DY2_1.030000_Fail");
  TH1F* ZTauTau3_Shape_UP_Fail = (TH1F*) failDirectory->Get("GenMatch_DY3_1.030000_Fail");
  TH1F* ZTauTau4_Shape_UP_Fail = (TH1F*) failDirectory->Get("GenMatch_DY4_1.030000_Fail");
  TH1F* ZTauTau_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("GenMatch_DY_0.970000_Fail");
  TH1F* ZTauTau1_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("GenMatch_DY1_0.970000_Fail");
  TH1F* ZTauTau2_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("GenMatch_DY2_0.970000_Fail");
  TH1F* ZTauTau3_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("GenMatch_DY3_0.970000_Fail");
  TH1F* ZTauTau4_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("GenMatch_DY4_0.970000_Fail");

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
  ZTauTau_Shape_UP_Pass->Add(ZTauTau1_Shape_UP_Pass);
  ZTauTau_Shape_UP_Pass->Add(ZTauTau2_Shape_UP_Pass);
  ZTauTau_Shape_UP_Pass->Add(ZTauTau3_Shape_UP_Pass);
  ZTauTau_Shape_UP_Pass->Add(ZTauTau4_Shape_UP_Pass);
  ZTauTau_Shape_DOWN_Pass->Add(ZTauTau1_Shape_DOWN_Pass);
  ZTauTau_Shape_DOWN_Pass->Add(ZTauTau2_Shape_DOWN_Pass);
  ZTauTau_Shape_DOWN_Pass->Add(ZTauTau3_Shape_DOWN_Pass);
  ZTauTau_Shape_DOWN_Pass->Add(ZTauTau4_Shape_DOWN_Pass);
  
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
  ZTauTau_Shape_UP_Fail->Add(ZTauTau1_Shape_UP_Fail);
  ZTauTau_Shape_UP_Fail->Add(ZTauTau2_Shape_UP_Fail);
  ZTauTau_Shape_UP_Fail->Add(ZTauTau3_Shape_UP_Fail);
  ZTauTau_Shape_UP_Fail->Add(ZTauTau4_Shape_UP_Fail);
  ZTauTau_Shape_DOWN_Fail->Add(ZTauTau1_Shape_DOWN_Fail);
  ZTauTau_Shape_DOWN_Fail->Add(ZTauTau2_Shape_DOWN_Fail);
  ZTauTau_Shape_DOWN_Fail->Add(ZTauTau3_Shape_DOWN_Fail);
  ZTauTau_Shape_DOWN_Fail->Add(ZTauTau4_Shape_DOWN_Fail);

  std::cout<<"Writing the file"<<std::endl;
  TFile* CombineFile = new TFile("Distributions/CombineFile.root","RECREATE");
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

  ZTauTau_Shape_UP_Pass->SetNameTitle("DYS_UP","DYS_UP");
  ZTauTau_Shape_UP_Pass->Write();

  ZTauTau_Shape_DOWN_Pass->SetNameTitle("DYS_DOWN","DYS_DOWN");
  ZTauTau_Shape_DOWN_Pass->Write();
  
  TH1F* TT_Pass = new TH1F("TT",
			   "TT",
			   TTTo2L2Nu_Pass->GetSize()-2,
			   TTTo2L2Nu_Pass->GetXaxis()->GetXmin(),
			   TTTo2L2Nu_Pass->GetXaxis()->GetXmax());
  TT_Pass->Add(TTTo2L2Nu_Pass,TTToHadronic_Pass);
  TT_Pass->Add(TTToSemiLeptonic_Pass);
  TT_Pass->Write();
  
  TH1F* DiBoson_Pass = new TH1F("VV",
				"VV",
				W_Pass->GetSize()-2,
				W_Pass->GetXaxis()->GetXmin(),
				W_Pass->GetXaxis()->GetXmax());
  DiBoson_Pass->Add(WW_Pass,WZ_Pass);
  DiBoson_Pass->Add(ZZ_Pass);
  DiBoson_Pass->Write();

  QCD_Pass->SetNameTitle("QCD","QCD");
  QCD_Pass->Write();

  W_Pass->SetNameTitle("W","W");
  W_Pass->Write();

  //Compile Fail Histos
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

  ZTauTau_Shape_UP_Fail->SetNameTitle("DYS_UP","DYS_UP");
  ZTauTau_Shape_UP_Fail->Write();

  ZTauTau_Shape_DOWN_Fail->SetNameTitle("DYS_DOWN","DYS_DOWN");
  ZTauTau_Shape_DOWN_Fail->Write();

  TH1F* TT_Fail = new TH1F("TT",
			   "TT",
			   TTTo2L2Nu_Fail->GetSize()-2,
			   TTTo2L2Nu_Fail->GetXaxis()->GetXmin(),
			   TTTo2L2Nu_Fail->GetXaxis()->GetXmax());
  TT_Fail->Add(TTTo2L2Nu_Fail,TTToHadronic_Fail);
  TT_Fail->Add(TTToSemiLeptonic_Fail);
  TT_Fail->Write();
  
  TH1F* DiBoson_Fail = new TH1F("VV",
				"VV",
				W_Fail->GetSize()-2,
				W_Fail->GetXaxis()->GetXmin(),
				W_Fail->GetXaxis()->GetXmax());
  DiBoson_Fail->Add(WW_Fail,WZ_Fail);
  DiBoson_Fail->Add(ZZ_Fail);
  DiBoson_Fail->Write();

  QCD_Fail->SetNameTitle("QCD","QCD");
  QCD_Fail->Write();

  W_Fail->SetNameTitle("W","W");
  W_Fail->Write();  

  CombineFile->Close();
  PassFailFile->Close();
}
