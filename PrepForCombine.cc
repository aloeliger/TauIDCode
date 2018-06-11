#include "TROOT.h"

void PrepForCombine()
{
  TFile* PassFailFile = new TFile("Distributions/PassFailOut.root");
  TDirectory* passDirectory = (TDirectory*) PassFailFile->Get("pass");
  TDirectory* failDirectory = (TDirectory*) PassFailFile->Get("fail");

  TH1F* Data_Pass = (TH1F*) passDirectory->Get("Data_Pass");
  TH1F* DY_Pass = (TH1F*) passDirectory->Get("DY_Pass");
  TH1F* DY1_Pass = (TH1F*) passDirectory->Get("DY1_Pass");
  TH1F* DY2_Pass = (TH1F*) passDirectory->Get("DY2_Pass");
  TH1F* DY3_Pass = (TH1F*) passDirectory->Get("DY3_Pass");
  TH1F* DY4_Pass = (TH1F*) passDirectory->Get("DY4_Pass");
  TH1F* ZTauTau_Pass = (TH1F*) passDirectory->Get("GenMatch_DY_Pass");
  TH1F* ZTauTau1_Pass = (TH1F*) passDirectory->Get("GenMatch_DY1_Pass");
  TH1F* ZTauTau2_Pass = (TH1F*) passDirectory->Get("GenMatch_DY2_Pass");
  TH1F* ZTauTau3_Pass = (TH1F*) passDirectory->Get("GenMatch_DY3_Pass");
  TH1F* ZTauTau4_Pass = (TH1F*) passDirectory->Get("GenMatch_DY4_Pass");
  TH1F* TTTo2L2Nu_Pass = (TH1F*) passDirectory->Get("TTTo2L2Nu_Pass");
  TH1F* TTToHadronic_Pass = (TH1F*) passDirectory->Get("TTToHadronic_Pass");
  TH1F* TTToSemiLeptonic_Pass = (TH1F*) passDirectory->Get("TTToSemiLeptonic_Pass");
  TH1F* W_Pass = (TH1F*) passDirectory->Get("Rescaled_WJets_Pass");
  TH1F* WW_Pass = (TH1F*) passDirectory->Get("WW_Pass");
  TH1F* WZ_Pass = (TH1F*) passDirectory->Get("WZ_Pass");
  TH1F* ZZ_Pass = (TH1F*) passDirectory->Get("ZZ_Pass");
  TH1F* QCD_Pass = (TH1F*) passDirectory->Get("QCD_Pass");
  TH1F* DY_Shape_UP_Pass = (TH1F*) passDirectory->Get("DY_1.100000_Pass");
  TH1F* DY1_Shape_UP_Pass = (TH1F*) passDirectory->Get("DY1_1.100000_Pass");
  TH1F* DY2_Shape_UP_Pass = (TH1F*) passDirectory->Get("DY2_1.100000_Pass");
  TH1F* DY3_Shape_UP_Pass = (TH1F*) passDirectory->Get("DY3_1.100000_Pass");
  TH1F* DY4_Shape_UP_Pass = (TH1F*) passDirectory->Get("DY4_1.100000_Pass");
  TH1F* DY_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("DY_0.900000_Pass");
  TH1F* DY1_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("DY1_0.900000_Pass");
  TH1F* DY2_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("DY2_0.900000_Pass");
  TH1F* DY3_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("DY3_0.900000_Pass");
  TH1F* DY4_Shape_DOWN_Pass = (TH1F*) passDirectory->Get("DY4_0.900000_Pass");
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

  TH1F* Data_Fail = (TH1F*) failDirectory->Get("Data_Fail");
  TH1F* DY_Fail = (TH1F*) failDirectory->Get("DY_Fail");
  TH1F* DY1_Fail = (TH1F*) failDirectory->Get("DY1_Fail");
  TH1F* DY2_Fail = (TH1F*) failDirectory->Get("DY2_Fail");
  TH1F* DY3_Fail = (TH1F*) failDirectory->Get("DY3_Fail");
  TH1F* DY4_Fail = (TH1F*) failDirectory->Get("DY4_Fail");
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
  TH1F* DY_Shape_UP_Fail = (TH1F*) failDirectory->Get("DY_1.100000_Fail");
  TH1F* DY1_Shape_UP_Fail = (TH1F*) failDirectory->Get("DY1_1.100000_Fail");
  TH1F* DY2_Shape_UP_Fail = (TH1F*) failDirectory->Get("DY2_1.100000_Fail");
  TH1F* DY3_Shape_UP_Fail = (TH1F*) failDirectory->Get("DY3_1.100000_Fail");
  TH1F* DY4_Shape_UP_Fail = (TH1F*) failDirectory->Get("DY4_1.100000_Fail");
  TH1F* DY_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("DY_0.900000_Fail");
  TH1F* DY1_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("DY1_0.900000_Fail");
  TH1F* DY2_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("DY2_0.900000_Fail");
  TH1F* DY3_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("DY3_0.900000_Fail");
  TH1F* DY4_Shape_DOWN_Fail = (TH1F*) failDirectory->Get("DY4_0.900000_Fail");
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

  DY_Pass->Add(DY1_Pass);
  DY_Pass->Add(DY2_Pass);
  DY_Pass->Add(DY3_Pass);
  DY_Pass->Add(DY4_Pass);
  DY_Shape_UP_Pass->Add(DY1_Shape_UP_Pass);
  DY_Shape_UP_Pass->Add(DY2_Shape_UP_Pass);
  DY_Shape_UP_Pass->Add(DY3_Shape_UP_Pass);
  DY_Shape_UP_Pass->Add(DY4_Shape_UP_Pass);
  DY_Shape_DOWN_Pass->Add(DY1_Shape_DOWN_Pass);
  DY_Shape_DOWN_Pass->Add(DY2_Shape_DOWN_Pass);
  DY_Shape_DOWN_Pass->Add(DY3_Shape_DOWN_Pass);
  DY_Shape_DOWN_Pass->Add(DY4_Shape_DOWN_Pass);

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
  
  DY_Fail->Add(DY1_Fail);
  DY_Fail->Add(DY2_Fail);
  DY_Fail->Add(DY3_Fail);
  DY_Fail->Add(DY4_Fail);
  DY_Shape_UP_Fail->Add(DY1_Shape_UP_Fail);
  DY_Shape_UP_Fail->Add(DY2_Shape_UP_Fail);
  DY_Shape_UP_Fail->Add(DY3_Shape_UP_Fail);
  DY_Shape_UP_Fail->Add(DY4_Shape_UP_Fail);
  DY_Shape_DOWN_Fail->Add(DY1_Shape_DOWN_Fail);
  DY_Shape_DOWN_Fail->Add(DY2_Shape_DOWN_Fail);
  DY_Shape_DOWN_Fail->Add(DY3_Shape_DOWN_Fail);
  DY_Shape_DOWN_Fail->Add(DY4_Shape_DOWN_Fail);
  
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

  TFile* CombineFile = new TFile("Distributions/CombineFile.root","RECREATE");
  //compile Pass histos
  TDirectory* CombinePassDirectory = CombineFile->mkdir("pass");
  CombinePassDirectory->cd();
  
  Data_Pass->SetNameTitle("data_obs","data_obs");
  Data_Pass->Write();
  
  DY_Pass->SetNameTitle("DY_Other","DY_Other");
  DY_Pass->Write();
  
  DY_Shape_UP_Pass->SetNameTitle("DY_Shape_UP","DY_Shape_UP");
  DY_Shape_UP_Pass->Write();

  DY_Shape_DOWN_Pass->SetNameTitle("DY_Shape_DOWN","DY_Shape_DOWN");
  DY_Shape_DOWN_Pass->Write();

  ZTauTau_Pass->SetNameTitle("ZTauTau","ZTauTau");  
  ZTauTau_Pass->Write();

  ZTauTau_Shape_UP_Pass->SetNameTitle("ZTauTau_Shape_UP","ZTauTau_Shape_UP");
  ZTauTau_Shape_UP_Pass->Write();

  ZTauTau_Shape_DOWN_Pass->SetNameTitle("ZTauTau_Shape_DOWN","ZTauTau_Shape_DOWN");
  ZTauTau_Shape_DOWN_Pass->Write();
  
  TH1F* TT_Pass = new TH1F("tt",
			   "tt",
			   TTTo2L2Nu_Pass->GetSize()-2,
			   TTTo2L2Nu_Pass->GetXaxis()->GetXmin(),
			   TTTo2L2Nu_Pass->GetXaxis()->GetXmax());
  TT_Pass->Add(TTTo2L2Nu_Pass,TTToHadronic_Pass);
  TT_Pass->Add(TTToSemiLeptonic_Pass);
  TT_Pass->Write();
  
  TH1F* DiBoson_Pass = new TH1F("DiBoson",
				"DiBoson",
				W_Pass->GetSize()-2,
				W_Pass->GetXaxis()->GetXmin(),
				W_Pass->GetXaxis()->GetXmax());
  DiBoson_Pass->Add(W_Pass,WW_Pass);
  DiBoson_Pass->Add(WZ_Pass);
  DiBoson_Pass->Add(ZZ_Pass);
  DiBoson_Pass->Write();

  QCD_Pass->SetNameTitle("QCD","QCD");
  QCD_Pass->Write();

  //Compile Fail Histos
  TDirectory* CombineFailDirectory = CombineFile->mkdir("fail");
  CombineFailDirectory->cd();

  Data_Fail->SetNameTitle("data_obs","data_obs");
  Data_Fail->Write();
  
  DY_Fail->SetNameTitle("DY_Other","DY_Other");
  DY_Fail->Write();

  DY_Shape_UP_Fail->SetNameTitle("DY_Shape_UP","DY_Shape_UP");
  DY_Shape_UP_Fail->Write();

  DY_Shape_DOWN_Fail->SetNameTitle("DY_Shape_DOWN","DY_Shape_DOWN");
  DY_Shape_DOWN_Fail->Write();
    
  ZTauTau_Fail->SetNameTitle("ZTauTau","ZTauTau");  
  ZTauTau_Fail->Write();

  ZTauTau_Shape_UP_Fail->SetNameTitle("ZTauTau_Shape_UP","ZTauTau_Shape_UP");
  ZTauTau_Shape_UP_Fail->Write();

  ZTauTau_Shape_DOWN_Fail->SetNameTitle("ZTauTau_Shape_DOWN","ZTauTau_Shape_DOWN");
  ZTauTau_Shape_DOWN_Fail->Write();

  TH1F* TT_Fail = new TH1F("tt",
			   "tt",
			   TTTo2L2Nu_Fail->GetSize()-2,
			   TTTo2L2Nu_Fail->GetXaxis()->GetXmin(),
			   TTTo2L2Nu_Fail->GetXaxis()->GetXmax());
  TT_Fail->Add(TTTo2L2Nu_Fail,TTToHadronic_Fail);
  TT_Fail->Add(TTToSemiLeptonic_Fail);
  TT_Fail->Write();
  
  TH1F* DiBoson_Fail = new TH1F("DiBoson",
				"DiBoson",
				W_Fail->GetSize()-2,
				W_Fail->GetXaxis()->GetXmin(),
				W_Fail->GetXaxis()->GetXmax());
  DiBoson_Fail->Add(W_Fail,WW_Fail);
  DiBoson_Fail->Add(WZ_Fail);
  DiBoson_Fail->Add(ZZ_Fail);
  DiBoson_Fail->Write();

  QCD_Fail->SetNameTitle("QCD","QCD");
  QCD_Fail->Write();

  CombineFile->Close();
  PassFailFile->Close();
}
