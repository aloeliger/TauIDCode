#include "TROOT.h"
#include "/afs/cern.ch/user/a/aloelige/private/RootMacros/CMS_lumi.C"
#include "/afs/cern.ch/user/a/aloelige/private/RootMacros/tdrstyle.C"

void CompileHistograms()
{
  setTDRStyle();
  
  writeExtraText = true;
  extraText = "Preliminary";
  lumi_sqrtS = "41 fb^{-1}, 13 TeV";

  TFile *PassFailFile = new TFile("Distributions/PassFailOut.root");
  TDirectory *PassDirectory = (TDirectory*) PassFailFile->Get("pass");
  TDirectory *FailDirectory = (TDirectory*) PassFailFile->Get("fail");

  //Pass Region Plots
  TH1F* Data_Pass = (TH1F*) PassDirectory->Get("Data_Pass");
  
  TH1F* ZTauTau_Pass = (TH1F*) PassDirectory->Get("GenMatch_DY_Pass");
  TH1F* ZTauTau1_Pass = (TH1F*) PassDirectory->Get("GenMatch_DY1_Pass");
  TH1F* ZTauTau2_Pass = (TH1F*) PassDirectory->Get("GenMatch_DY2_Pass");
  TH1F* ZTauTau3_Pass = (TH1F*) PassDirectory->Get("GenMatch_DY3_Pass");
  TH1F* ZTauTau4_Pass = (TH1F*) PassDirectory->Get("GenMatch_DY4_Pass");
  TH1F* LowGenMatch_DY_Pass = (TH1F*) PassDirectory->Get("LowGenMatch_DY_Pass");
  TH1F* LowGenMatch_DY1_Pass = (TH1F*) PassDirectory->Get("LowGenMatch_DY1_Pass");
  TH1F* LowGenMatch_DY2_Pass = (TH1F*) PassDirectory->Get("LowGenMatch_DY2_Pass");
  TH1F* LowGenMatch_DY3_Pass = (TH1F*) PassDirectory->Get("LowGenMatch_DY3_Pass");
  TH1F* LowGenMatch_DY4_Pass = (TH1F*) PassDirectory->Get("LowGenMatch_DY4_Pass");
  TH1F* HighGenMatch_DY_Pass = (TH1F*) PassDirectory->Get("HighGenMatch_DY_Pass");
  TH1F* HighGenMatch_DY1_Pass = (TH1F*) PassDirectory->Get("HighGenMatch_DY1_Pass");
  TH1F* HighGenMatch_DY2_Pass = (TH1F*) PassDirectory->Get("HighGenMatch_DY2_Pass");
  TH1F* HighGenMatch_DY3_Pass = (TH1F*) PassDirectory->Get("HighGenMatch_DY3_Pass");
  TH1F* HighGenMatch_DY4_Pass = (TH1F*) PassDirectory->Get("HighGenMatch_DY4_Pass");

  TH1F* TTTo2L2Nu_Pass = (TH1F*) PassDirectory->Get("TTTo2L2Nu_Pass");
  TH1F* TTToHadronic_Pass = (TH1F*) PassDirectory->Get("TTToHadronic_Pass");
  TH1F* TTToSemiLeptonic_Pass = (TH1F*) PassDirectory->Get("TTToSemiLeptonic_Pass");
  TH1F* WJets_Pass = (TH1F*) PassDirectory->Get("Rescaled_WJets_Pass");
  TH1F* WW_Pass = (TH1F*) PassDirectory->Get("WW_Pass");
  TH1F* WZ_Pass = (TH1F*) PassDirectory->Get("WZ_Pass");
  TH1F* ZZ_Pass = (TH1F*) PassDirectory->Get("ZZ_Pass");
  TH1F* QCD_Pass = (TH1F*) PassDirectory->Get("QCD_Pass");

  //Fail Region Plots
  TH1F* Data_Fail = (TH1F*) FailDirectory->Get("Data_Fail");
  
  TH1F* ZTauTau_Fail = (TH1F*) FailDirectory->Get("GenMatch_DY_Fail");
  TH1F* ZTauTau1_Fail = (TH1F*) FailDirectory->Get("GenMatch_DY1_Fail");
  TH1F* ZTauTau2_Fail = (TH1F*) FailDirectory->Get("GenMatch_DY2_Fail");
  TH1F* ZTauTau3_Fail = (TH1F*) FailDirectory->Get("GenMatch_DY3_Fail");
  TH1F* ZTauTau4_Fail = (TH1F*) FailDirectory->Get("GenMatch_DY4_Fail");
  TH1F* LowGenMatch_DY_Fail = (TH1F*) FailDirectory->Get("LowGenMatch_DY_Fail");
  TH1F* LowGenMatch_DY1_Fail = (TH1F*) FailDirectory->Get("LowGenMatch_DY1_Fail");
  TH1F* LowGenMatch_DY2_Fail = (TH1F*) FailDirectory->Get("LowGenMatch_DY2_Fail");
  TH1F* LowGenMatch_DY3_Fail = (TH1F*) FailDirectory->Get("LowGenMatch_DY3_Fail");
  TH1F* LowGenMatch_DY4_Fail = (TH1F*) FailDirectory->Get("LowGenMatch_DY4_Fail");
  TH1F* HighGenMatch_DY_Fail = (TH1F*) FailDirectory->Get("HighGenMatch_DY_Fail");
  TH1F* HighGenMatch_DY1_Fail = (TH1F*) FailDirectory->Get("HighGenMatch_DY1_Fail");
  TH1F* HighGenMatch_DY2_Fail = (TH1F*) FailDirectory->Get("HighGenMatch_DY2_Fail");
  TH1F* HighGenMatch_DY3_Fail = (TH1F*) FailDirectory->Get("HighGenMatch_DY3_Fail");
  TH1F* HighGenMatch_DY4_Fail = (TH1F*) FailDirectory->Get("HighGenMatch_DY4_Fail");

  TH1F* TTTo2L2Nu_Fail = (TH1F*) FailDirectory->Get("TTTo2L2Nu_Fail");
  TH1F* TTToHadronic_Fail = (TH1F*) FailDirectory->Get("TTToHadronic_Fail");
  TH1F* TTToSemiLeptonic_Fail = (TH1F*) FailDirectory->Get("TTToSemiLeptonic_Fail");
  TH1F* WJets_Fail = (TH1F*) FailDirectory->Get("Rescaled_WJets_Fail");
  TH1F* WW_Fail = (TH1F*) FailDirectory->Get("WW_Fail");
  TH1F* WZ_Fail = (TH1F*) FailDirectory->Get("WZ_Fail");
  TH1F* ZZ_Fail = (TH1F*) FailDirectory->Get("ZZ_Fail");
  TH1F* QCD_Fail = (TH1F*) FailDirectory->Get("QCD_Fail");

  //New way ofd doing DY backgrounds, but we'll just compile them together here.
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY1_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY2_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY3_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY4_Pass);
  LowGenMatch_DY_Pass->Add(HighGenMatch_DY_Pass);
  LowGenMatch_DY_Pass->Add(HighGenMatch_DY1_Pass);
  LowGenMatch_DY_Pass->Add(HighGenMatch_DY2_Pass);
  LowGenMatch_DY_Pass->Add(HighGenMatch_DY3_Pass);
  LowGenMatch_DY_Pass->Add(HighGenMatch_DY4_Pass);
  
  LowGenMatch_DY_Fail->Add(LowGenMatch_DY1_Fail);
  LowGenMatch_DY_Fail->Add(LowGenMatch_DY2_Fail);
  LowGenMatch_DY_Fail->Add(LowGenMatch_DY3_Fail);
  LowGenMatch_DY_Fail->Add(LowGenMatch_DY4_Fail);
  LowGenMatch_DY_Fail->Add(HighGenMatch_DY_Fail);
  LowGenMatch_DY_Fail->Add(HighGenMatch_DY1_Fail);
  LowGenMatch_DY_Fail->Add(HighGenMatch_DY2_Fail);
  LowGenMatch_DY_Fail->Add(HighGenMatch_DY3_Fail);
  LowGenMatch_DY_Fail->Add(HighGenMatch_DY4_Fail);

  ZTauTau_Pass->Add(ZTauTau1_Pass);
  ZTauTau_Pass->Add(ZTauTau2_Pass);
  ZTauTau_Pass->Add(ZTauTau3_Pass);
  ZTauTau_Pass->Add(ZTauTau4_Pass);

  ZTauTau_Fail->Add(ZTauTau1_Fail);
  ZTauTau_Fail->Add(ZTauTau2_Fail);
  ZTauTau_Fail->Add(ZTauTau3_Fail);
  ZTauTau_Fail->Add(ZTauTau4_Fail);
  
  
  gStyle->SetOptStat(0);

  TCanvas* C1 = new TCanvas("C1", "#mu#tau Invariant Mass");
  C1->SetTickx();
  C1->SetTicky();

  TH1F* DiBoson_Pass = new TH1F("DiBoson_Pass","DiBoson_Pass", Data_Pass->GetSize()-2, Data_Pass->GetXaxis()->GetXmin(), Data_Pass->GetXaxis()->GetXmax());
  DiBoson_Pass->Add(WW_Pass,WZ_Pass);
  DiBoson_Pass->Add(ZZ_Pass);

  TH1F* TT_Pass = new TH1F("TT_Pass", "TT_Pass", Data_Pass->GetSize()-2, Data_Pass->GetXaxis()->GetXmin(), Data_Pass->GetXaxis()->GetXmax());
  TT_Pass->Add(TTTo2L2Nu_Pass,TTToHadronic_Pass);
  TT_Pass->Add(TTToSemiLeptonic_Pass);
  
  Data_Pass->SetMarkerStyle(20);
  Data_Pass->Sumw2();
  
  ZTauTau_Pass->SetLineColor(kBlack);
  ZTauTau_Pass->SetFillColor(kYellow);

  LowGenMatch_DY_Pass->SetLineColor(kBlack);
  LowGenMatch_DY_Pass->SetFillColor(kAzure-3);

  DiBoson_Pass->SetLineColor(kBlack);
  DiBoson_Pass->SetFillColor(kPink-3);

  TT_Pass->SetLineColor(kBlack);
  TT_Pass->SetFillColor(kViolet-3);

  WJets_Pass->SetLineColor(kBlack);
  WJets_Pass->SetFillColor(kGreen-3);

  QCD_Pass->SetLineColor(kBlack);
  QCD_Pass->SetFillColor(kPink+1);

  THStack * PassStack = new THStack("PassStack","PassStack");
  PassStack->Add(QCD_Pass,"hist");  
  PassStack->Add(WJets_Pass,"hist");
  PassStack->Add(ZTauTau_Pass,"hist");
  PassStack->Add(LowGenMatch_DY_Pass,"hist");
  PassStack->Add(TT_Pass,"hist");
  PassStack->Add(DiBoson_Pass,"hist");

  Data_Pass->Draw();
  PassStack->Draw("SAME");
  Data_Pass->SetTitle("#mu#tau Invariant Mass Pass");
  Data_Pass->Draw("SAME");
  Data_Pass->GetXaxis()->SetTitle("#mu#tau Invariant Mass (GeV)");
  Data_Pass->GetYaxis()->SetTitle("Events");

  CMS_lumi(C1,0,33);
  
  TLegend* Legend = new TLegend(0.7, 0.5, 0.88, 0.68);
  Legend->AddEntry(Data_Pass, "Data", "ep");
  Legend->AddEntry(ZTauTau_Pass,"Z #rightarrow #tau#tau", "f");
  Legend->AddEntry(LowGenMatch_DY_Pass, "Other Drell-Yan", "f");
  Legend->AddEntry(DiBoson_Pass, "DiBoson", "f");
  Legend->AddEntry(TT_Pass, "t#bar{t}","f");
  Legend->AddEntry(WJets_Pass, "W+Jets","f");
  Legend->AddEntry(QCD_Pass, "QCD", "f");

  Legend->Draw();

  //Fail Region
  TCanvas* C2 = new TCanvas("C2", "#mu#tau Invariant Mass");
  C2->SetTickx();
  C2->SetTicky();

  TH1F* DiBoson_Fail = new TH1F("DiBoson_Fail","DiBoson_Fail", Data_Fail->GetSize()-2, Data_Fail->GetXaxis()->GetXmin(), Data_Fail->GetXaxis()->GetXmax());
  DiBoson_Fail->Add(WW_Fail,WZ_Fail);
  DiBoson_Fail->Add(ZZ_Fail);

  TH1F* TT_Fail = new TH1F("TT_Fail", "TT_Fail", Data_Fail->GetSize()-2, Data_Fail->GetXaxis()->GetXmin(), Data_Fail->GetXaxis()->GetXmax());
  TT_Fail->Add(TTTo2L2Nu_Fail,TTToHadronic_Fail);
  TT_Fail->Add(TTToSemiLeptonic_Fail);
  
  Data_Fail->SetMarkerStyle(20);
  Data_Fail->Sumw2();
  
  ZTauTau_Fail->SetLineColor(kBlack);
  ZTauTau_Fail->SetFillColor(kYellow);

  LowGenMatch_DY_Fail->SetLineColor(kBlack);
  LowGenMatch_DY_Fail->SetFillColor(kAzure-3);

  DiBoson_Fail->SetLineColor(kBlack);
  DiBoson_Fail->SetFillColor(kPink-3);

  TT_Fail->SetLineColor(kBlack);
  TT_Fail->SetFillColor(kViolet-3);

  WJets_Fail->SetLineColor(kBlack);
  WJets_Fail->SetFillColor(kGreen-3);

  QCD_Fail->SetLineColor(kBlack);
  QCD_Fail->SetFillColor(kPink+1);

  THStack * FailStack = new THStack("FailStack","FailStack");
  FailStack->Add(QCD_Fail,"hist");
  FailStack->Add(WJets_Fail,"hist");
  FailStack->Add(ZTauTau_Fail,"hist");
  FailStack->Add(LowGenMatch_DY_Fail,"hist");
  FailStack->Add(TT_Fail,"hist");
  FailStack->Add(DiBoson_Fail,"hist");  

  Data_Fail->Draw();
  FailStack->Draw("SAME");
  Data_Fail->SetTitle("#mu#tau Invariant Mass Fail");
  Data_Fail->Draw("SAME");
  Data_Fail->GetXaxis()->SetTitle("#mu#tau Invariant Mass (GeV)");
  Data_Fail->GetYaxis()->SetTitle("Events");

  CMS_lumi(C2,0,33);

  Legend->Draw();
  

  //Write these to a histo file.
  TFile* HistoFile = new TFile("Histos/HistoFile.root","RECREATE");
  C1->Write();
  C2->Write();
  HistoFile->Close();

  C1->SaveAs("Histos/pass.png");
  C2->SaveAs("Histos/fail.png");  
}
