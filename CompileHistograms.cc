#include "TROOT.h"
#include "/afs/cern.ch/user/a/aloelige/private/RootMacros/CMS_lumi.C"
#include "/afs/cern.ch/user/a/aloelige/private/RootMacros/tdrstyle.C"

void CompileHistograms()
{
  setTDRStyle();
  
  writeExtraText = true;
  extraText = "Preliminary";
  lumi_sqrtS = "46 fb^{-1}, 13 TeV";

  TFile *PassFailFile = new TFile("Distributions/PassFailOut.root");
  TDirectory *PassDirectory = (TDirectory*) PassFailFile->Get("pass");
  TDirectory *FailDirectory = (TDirectory*) PassFailFile->Get("fail");

  //Pass Region Plots
  TH1F* Data_Pass = (TH1F*) PassDirectory->Get("Data_Pass");
  TH1F* DY_Pass = (TH1F*) PassDirectory->Get("DY_Pass");
  TH1F* TTTo2L2Nu_Pass = (TH1F*) PassDirectory->Get("TTTo2L2Nu_Pass");
  TH1F* TTToHadronic_Pass = (TH1F*) PassDirectory->Get("TTToHadronic_Pass");
  TH1F* TTToSemiLeptonic_Pass = (TH1F*) PassDirectory->Get("TTToSemiLeptonic_Pass");
  TH1F* WJets_Pass = (TH1F*) PassDirectory->Get(/*"W_Pass"*/"Rescaled_WJets_Pass");
  TH1F* WW_Pass = (TH1F*) PassDirectory->Get("WW_Pass");
  TH1F* WZ_Pass = (TH1F*) PassDirectory->Get("WZ_Pass");
  TH1F* ZZ_Pass = (TH1F*) PassDirectory->Get("ZZ_Pass");
  TH1F* QCD_Pass = (TH1F*) PassDirectory->Get("QCD_Pass");

  //Fail Region Plots
  TH1F* Data_Fail = (TH1F*) FailDirectory->Get("Data_Fail");
  TH1F* DY_Fail = (TH1F*) FailDirectory->Get("DY_Fail");
  TH1F* TTTo2L2Nu_Fail = (TH1F*) FailDirectory->Get("TTTo2L2Nu_Fail");
  TH1F* TTToHadronic_Fail = (TH1F*) FailDirectory->Get("TTToHadronic_Fail");
  TH1F* TTToSemiLeptonic_Fail = (TH1F*) FailDirectory->Get("TTToSemiLeptonic_Fail");
  TH1F* WJets_Fail = (TH1F*) FailDirectory->Get(/*"W_Fail"*/"Rescaled_WJets_Fail");
  TH1F* WW_Fail = (TH1F*) FailDirectory->Get("WW_Fail");
  TH1F* WZ_Fail = (TH1F*) FailDirectory->Get("WZ_Fail");
  TH1F* ZZ_Fail = (TH1F*) FailDirectory->Get("ZZ_Fail");
  TH1F* QCD_Fail = (TH1F*) FailDirectory->Get("QCD_Fail");
  
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
  
  DY_Pass->SetLineColor(kBlack);
  DY_Pass->SetFillColor(kAzure-3);

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
  PassStack->Add(TT_Pass,"hist");
  PassStack->Add(DY_Pass,"hist");
  PassStack->Add(DiBoson_Pass,"hist");

  Data_Pass->Draw();
  PassStack->Draw("SAME");
  Data_Pass->Draw("SAME");
  Data_Pass->GetXaxis()->SetTitle("#mu#tau Invariant Mass (GeV)");
  Data_Pass->GetYaxis()->SetTitle("Events");

  CMS_lumi(C1,0,11);
  
  TLegend* Legend = new TLegend(0.7, 0.7, 0.88, 0.88);
  Legend->AddEntry(Data_Pass, "Data", "ep");
  Legend->AddEntry(DY_Pass, "Drell-Yan", "f");
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
  
  DY_Fail->SetLineColor(kBlack);
  DY_Fail->SetFillColor(kAzure-3);

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
  FailStack->Add(TT_Fail,"hist");
  FailStack->Add(DY_Fail,"hist");
  FailStack->Add(DiBoson_Fail,"hist");  

  Data_Fail->Draw();
  FailStack->Draw("SAME");
  Data_Fail->Draw("SAME");
  Data_Fail->GetXaxis()->SetTitle("#mu#tau Invariant Mass (GeV)");
  Data_Fail->GetYaxis()->SetTitle("Events");

  CMS_lumi(C2,0,11);

  Legend->Draw();

  //Write these to a histo file.
  TFile* HistoFile = new TFile("Histos/HistoFile.root","RECREATE");
  C1->Write();
  C2->Write();
  HistoFile->Close();

  C1->SaveAs("Histos/pass.png");
  C2->SaveAs("Histos/fail.png");
}
