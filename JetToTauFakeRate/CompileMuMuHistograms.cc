#include "TROOT.h"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/CMS_lumi.C"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/tdrstyle.C"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/MakeRatioPlot.cc"

void CompileMuMuHistograms()
{

  setTDRStyle();

  writeExtraText = true;
  extraText = "Preliminary";
  lumi_sqrtS = "41 fb^{-1}, 13TeV";

  TFile* LoadFile = new TFile("../Distributions/ZMuMu.root");
  
  TH1F* DataHisto = (TH1F*)LoadFile->Get("Data");
  TH1F* DY1Histo = (TH1F*)LoadFile->Get("DY1");
  TH1F* DY2Histo = (TH1F*)LoadFile->Get("DY2");
  TH1F* DY3Histo = (TH1F*)LoadFile->Get("DY3");
  TH1F* DY4Histo = (TH1F*)LoadFile->Get("DY4");
  TH1F* DYHisto = (TH1F*)LoadFile->Get("DY");
  TH1F* TTTo2L2NuHisto = (TH1F*)LoadFile->Get("TTTo2L2Nu");
  TH1F* TTToHadronicHisto = (TH1F*)LoadFile->Get("TTToHadronic");
  TH1F* TTToSemiLeptonicHisto = (TH1F*)LoadFile->Get("TTToSemiLeptonic");
  TH1F* W1Histo = (TH1F*)LoadFile->Get("W1");
  TH1F* W2Histo = (TH1F*)LoadFile->Get("W2");
  TH1F* W3Histo = (TH1F*)LoadFile->Get("W3");
  TH1F* W4Histo = (TH1F*)LoadFile->Get("W4");
  TH1F* WHisto = (TH1F*)LoadFile->Get("W");
  TH1F* WWHisto = (TH1F*)LoadFile->Get("WW");
  TH1F* WZHisto = (TH1F*)LoadFile->Get("WZ");
  TH1F* ZZHisto = (TH1F*)LoadFile->Get("ZZ");
  TH1F* QCDHisto = (TH1F*)LoadFile->Get("QCD");

  DYHisto->Add(DY1Histo);
  DYHisto->Add(DY2Histo);
  DYHisto->Add(DY3Histo);
  DYHisto->Add(DY4Histo);

  WHisto->Add(W1Histo);
  WHisto->Add(W2Histo);
  WHisto->Add(W3Histo);
  WHisto->Add(W4Histo);

  gStyle->SetOptStat(0);

  TCanvas* C1 = new TCanvas("C1","#mu#mu Invariant Mass");
  C1->SetTickx();
  C1->SetTicky();

  TH1F* DiBosonHisto = new TH1F("DiBosonHisto","DiBosonHisto", DataHisto->GetSize()-2, DataHisto->GetXaxis()->GetXmin(), DataHisto->GetXaxis()->GetXmax());
  DiBosonHisto->Add(WWHisto,WZHisto);
  DiBosonHisto->Add(ZZHisto);

  TH1F* TTHisto = new TH1F("TTHisto","TTHisto",DataHisto->GetSize()-2, DataHisto->GetXaxis()->GetXmin(), DataHisto->GetXaxis()->GetXmax());
  TTHisto->Add(TTTo2L2NuHisto,TTToHadronicHisto);
  TTHisto->Add(TTToSemiLeptonicHisto);

  DataHisto->SetMarkerStyle(20);
  DataHisto->Sumw2();

  DYHisto->SetLineColor(kBlack);
  DYHisto->SetFillColor(kBlue);
  
  DiBosonHisto->SetLineColor(kBlack);
  DiBosonHisto->SetFillColor(kPink-3);
  

  TTHisto->SetLineColor(kBlack);
  TTHisto->SetFillColor(kViolet-3);
  
  WHisto->SetLineColor(kBlack);
  WHisto->SetFillColor(kGreen-3);

  QCDHisto->SetLineColor(kBlack);
  QCDHisto->SetFillColor(kPink+1);
  
  THStack* BackgroundStack = new THStack("BackgroundStack","BackgroundStack");
  BackgroundStack->Add(QCDHisto,"hist");
  BackgroundStack->Add(WHisto, "hist");
  BackgroundStack->Add(DYHisto,"hist");
  BackgroundStack->Add(TTHisto, "hist");
  BackgroundStack->Add(DiBosonHisto, "hist");

  TPad* PlotPad = MakeRatioPlot(C1, BackgroundStack, DataHisto);
  BackgroundStack->Draw();
  BackgroundStack->SetTitle("#mu#mu Invariant Mass");
  BackgroundStack->GetXaxis()->SetTitle("#mu#mu Invariant Mass (GeV)");
  BackgroundStack->GetYaxis()->SetTitle("Events");
  DataHisto->Draw("SAME");
  CMS_lumi(PlotPad,0,33);

  TLegend* Legend = new TLegend(0.7, 0.5, 0.88, 0.68);
  Legend->AddEntry(DataHisto, "Data", "ep");
  Legend->AddEntry(DYHisto, "Z #rightarrow #mu#mu", "f");
  Legend->AddEntry(DiBosonHisto, "DiBoson", "f");
  Legend->AddEntry(TTHisto, "t#bar{t}", "f");
  Legend->AddEntry(WHisto, "W+Jets", "f");
  Legend->AddEntry(QCDHisto, "QCD", "f");

  Legend->Draw();
  
  C1->Draw();

  TFile* HistoFile = new TFile("../Histos/MuMuHistoFile.root","RECREATE");
  C1->Write();
  
  C1->SaveAs("../Histos/mumu.png");
}
