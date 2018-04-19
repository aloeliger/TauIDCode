#include "TROOT.h"

void PrepForCombine()
{
  TFile* PassFailFile = new TFile("Distributions/PassFailOut.root");
  TDirectory* passDirectory = (TDirectory*) PassFailFile->Get("pass");
  TDirectory* failDirectory = (TDirectory*) PassFailFile->Get("fail");

  TH1F* Data_Pass = (TH1F*) passDirectory->Get("Data_Pass");
  TH1F* DY_Pass = (TH1F*) passDirectory->Get("DY_Pass");
  TH1F* TTTo2L2Nu_Pass = (TH1F*) passDirectory->Get("TTTo2L2Nu_Pass");
  TH1F* TTToHadronic_Pass = (TH1F*) passDirectory->Get("TTToHadronic_Pass");
  TH1F* TTToSemiLeptonic_Pass = (TH1F*) passDirectory->Get("TTToSemiLeptonic_Pass");
  TH1F* W_Pass = (TH1F*) passDirectory->Get("Rescaled_WJets_Pass");
  TH1F* WW_Pass = (TH1F*) passDirectory->Get("WW_Pass");
  TH1F* WZ_Pass = (TH1F*) passDirectory->Get("WZ_Pass");
  TH1F* ZZ_Pass = (TH1F*) passDirectory->Get("ZZ_Pass");
  TH1F* QCD_Pass = (TH1F*) passDirectory->Get("QCD_Pass");

  TH1F* Data_Fail = (TH1F*) failDirectory->Get("Data_Fail");
  TH1F* DY_Fail = (TH1F*) failDirectory->Get("DY_Fail");
  TH1F* TTTo2L2Nu_Fail = (TH1F*) failDirectory->Get("TTTo2L2Nu_Fail");
  TH1F* TTToHadronic_Fail = (TH1F*) failDirectory->Get("TTToHadronic_Fail");
  TH1F* TTToSemiLeptonic_Fail = (TH1F*) failDirectory->Get("TTToSemiLeptonic_Fail");
  TH1F* W_Fail = (TH1F*) failDirectory->Get("Rescaled_WJets_Fail");
  TH1F* WW_Fail = (TH1F*) failDirectory->Get("WW_Fail");
  TH1F* WZ_Fail = (TH1F*) failDirectory->Get("WZ_Fail");
  TH1F* ZZ_Fail = (TH1F*) failDirectory->Get("ZZ_Fail");
  TH1F* QCD_Fail = (TH1F*) failDirectory->Get("QCD_Fail");

  Data_Pass->SetName("data_obs");
  
  Data_Fail->SetName("data_obs");


  TFile* CombineFile = new TFile("Distributions/CombineFile.root","RECREATE");
  //compile Pass histos
  TDirectory* CombinePassDirectory = CombineFile->mkdir("pass");
  CombinePassDirectory->cd();
  Data_Pass->Write();
  DY_Pass->Write();
  
  TH1F* TT_Pass = new TH1F("TT_Pass",
			   "TT_Pass",
			   TTTo2L2Nu_Pass->GetSize()-2,
			   TTTo2L2Nu_Pass->GetXaxis()->GetXmin(),
			   TTTo2L2Nu_Pass->GetXaxis()->GetXmax());
  TT_Pass->Add(TTTo2L2Nu_Pass,TTToHadronic_Pass);
  TT_Pass->Add(TTToSemiLeptonic_Pass);
  TT_Pass->Write();
  
  TH1F* DiBoson_Pass = new TH1F("DiBoson_Pass",
				"DiBoson_Pass",
				W_Pass->GetSize()-2,
				W_Pass->GetXaxis()->GetXmin(),
				W_Pass->GetXaxis()->GetXmax());
  DiBoson_Pass->Add(W_Pass,WW_Pass);
  DiBoson_Pass->Add(WZ_Pass);
  DiBoson_Pass->Add(ZZ_Pass);
  DiBoson_Pass->Write();

  QCD_Pass->Write();

  //Compile Fail Histos
  TDirectory* CombineFailDirectory = CombineFile->mkdir("fail");
  CombineFailDirectory->cd();
  Data_Fail->Write();
  DY_Fail->Write();
  
  TH1F* TT_Fail = new TH1F("TT_Fail",
			   "TT_Fail",
			   TTTo2L2Nu_Fail->GetSize()-2,
			   TTTo2L2Nu_Fail->GetXaxis()->GetXmin(),
			   TTTo2L2Nu_Fail->GetXaxis()->GetXmax());
  TT_Fail->Add(TTTo2L2Nu_Fail,TTToHadronic_Fail);
  TT_Fail->Add(TTToSemiLeptonic_Fail);
  TT_Fail->Write();
  
  TH1F* DiBoson_Fail = new TH1F("DiBoson_Fail",
				"DiBoson_Fail",
				W_Fail->GetSize()-2,
				W_Fail->GetXaxis()->GetXmin(),
				W_Fail->GetXaxis()->GetXmax());
  DiBoson_Fail->Add(W_Fail,WW_Fail);
  DiBoson_Fail->Add(WZ_Fail);
  DiBoson_Fail->Add(ZZ_Fail);
  DiBoson_Fail->Write();

  QCD_Fail->Write();

  CombineFile->Close();
  PassFailFile->Close();
}
