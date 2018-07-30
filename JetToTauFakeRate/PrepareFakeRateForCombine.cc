#include "TROOT.h"

void PrepareFakeRateForCombine()
{
  TFile* PassFailFile = new TFile("../Distributions/PassFailOut.root");
  TDirectory* passDirectory = (TDirectory*) PassFailFile->Get("pass");
  
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
  
  TH1F* WW_Pass = (TH1F*) passDirectory->Get("WW_Pass");
  TH1F* WZ_Pass = (TH1F*) passDirectory->Get("WZ_Pass");
  TH1F* ZZ_Pass = (TH1F*) passDirectory->Get("ZZ_Pass");
  
  //Get the fake rates determined stuff
  TFile* FakeRateDeterminedDistributions = new TFile("../Distributions/FakeRateDeterminedDistributions.root");
  TH1F* TightJetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("TightJetDistribution");
  
  std::cout<<"Simplifying the DY Histos"<<std::endl;
  //pass compiling  
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY1_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY2_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY3_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY4_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY1_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY2_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY3_Pass);
  HighGenMatch_DY_Pass->Add(HighGenMatch_DY4_Pass);

  ZTauTau_Pass->Add(ZTauTau1_Pass);
  ZTauTau_Pass->Add(ZTauTau2_Pass);
  ZTauTau_Pass->Add(ZTauTau3_Pass);
  ZTauTau_Pass->Add(ZTauTau4_Pass);

  std::cout<<"Preparing the Zmt region."<<std::endl;

  TFile* CombineFile = new TFile("../Distributions/FakeRateCombineFile.root","RECREATE");
  TDirectory* ZMTDirectory = CombineFile->mkdir("zmt");
  ZMTDirectory->cd();
  
  Data_Pass->SetNameTitle("data_obs","data_obs");
  Data_Pass->Write();
  
  LowGenMatch_DY_Pass->SetNameTitle("DYB","DYB");
  LowGenMatch_DY_Pass->Write();

  HighGenMatch_DY_Pass->SetNameTitle("DYJ","DYJ");
  HighGenMatch_DY_Pass->Write();
  
  ZTauTau_Pass->SetNameTitle("DYS","DYS");  
  ZTauTau_Pass->Write();

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
				WW_Pass->GetSize()-2,
				WW_Pass->GetXaxis()->GetXmin(),
				WW_Pass->GetXaxis()->GetXmax());
  DiBoson_Pass->Add(WW_Pass,WZ_Pass);
  DiBoson_Pass->Add(ZZ_Pass);
  DiBoson_Pass->Write();

  TightJetDistribution->SetNameTitle("Jets","Jets");
  TightJetDistribution->Write();
  
  std::cout<<"Preparing the Zmm region"<<std::endl;
  TFile* ZMuMuFile = new TFile("../Distributions/ZMuMu.root");
  TH1F* Data_MuMu = (TH1F*) ZMuMuFile->Get("Data");

  TH1F* DY1_MuMu = (TH1F*) ZMuMuFile->Get("DY1");
  TH1F* DY2_MuMu = (TH1F*) ZMuMuFile->Get("DY2");
  TH1F* DY3_MuMu = (TH1F*) ZMuMuFile->Get("DY3");
  TH1F* DY4_MuMu = (TH1F*) ZMuMuFile->Get("DY4");
  TH1F* DY_MuMu = (TH1F*) ZMuMuFile->Get("DY");
  
  //are these really necessary?
  TH1F* TTTo2L2Nu_MuMu = (TH1F*) ZMuMuFile->Get("TTTo2L2Nu");
  TH1F* TTToHadronic_MuMu = (TH1F*) ZMuMuFile->Get("TTToHadronic");
  TH1F* TTToSemiLeptonic_MuMu = (TH1F*) ZMuMuFile->Get("TTToSemiLeptonic");

  TH1F* WW_MuMu = (TH1F*) ZMuMuFile->Get("WW");
  TH1F* WZ_MuMu = (TH1F*) ZMuMuFile->Get("WZ");
  TH1F* ZZ_MuMu = (TH1F*) ZMuMuFile->Get("ZZ");

  //These moreso
  TH1F* W_MuMu = (TH1F*) ZMuMuFile->Get("W");
  TH1F* W1_MuMu = (TH1F*) ZMuMuFile->Get("W1");
  TH1F* W2_MuMu = (TH1F*) ZMuMuFile->Get("W2");
  TH1F* W3_MuMu = (TH1F*) ZMuMuFile->Get("W3");
  TH1F* W4_MuMu = (TH1F*) ZMuMuFile->Get("W4");
  
  TH1F* QCD_MuMu = (TH1F*) ZMuMuFile->Get("QCD");

  TDirectory* ZMMDirectory = CombineFile->mkdir("zmm");
  ZMMDirectory->cd();

  DY_MuMu->Add(DY1_MuMu);
  DY_MuMu->Add(DY2_MuMu);
  DY_MuMu->Add(DY3_MuMu);
  DY_MuMu->Add(DY4_MuMu);

  W_MuMu->Add(W1_MuMu);
  W_MuMu->Add(W2_MuMu);
  W_MuMu->Add(W3_MuMu);
  W_MuMu->Add(W4_MuMu);

  Data_MuMu->SetNameTitle("data_obs","data_obs");
  Data_MuMu->Write();

  DY_MuMu->SetNameTitle("DYB","DYB");
  DY_MuMu->Write();

  TH1F* TT_MuMu = new TH1F("TT",
			  "TT",
			  TTTo2L2Nu_MuMu->GetSize()-2,
			  TTTo2L2Nu_MuMu->GetXaxis()->GetXmin(),
			  TTTo2L2Nu_MuMu->GetXaxis()->GetXmax());
  TT_MuMu->Add(TTTo2L2Nu_MuMu,TTToHadronic_MuMu);
  TT_MuMu->Add(TTToSemiLeptonic_MuMu);
  TT_MuMu->Write();
  
  TH1F* DiBoson_MuMu = new TH1F("VV",
				"VV",
				WW_MuMu->GetSize()-2,
				WW_MuMu->GetXaxis()->GetXmin(),
				WW_MuMu->GetXaxis()->GetXmax());
  DiBoson_MuMu->Add(WW_MuMu,WZ_MuMu);
  DiBoson_MuMu->Add(ZZ_MuMu);
  DiBoson_MuMu->Write();
  
  W_MuMu->SetNameTitle("W","W");
  W_MuMu->Write();

  QCD_MuMu->SetNameTitle("QCD","QCD");
  QCD_MuMu->Write();

  CombineFile->Close();
  FakeRateDeterminedDistributions->Close();
  PassFailFile->Close();
}
