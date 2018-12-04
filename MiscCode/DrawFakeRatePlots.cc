#include "TROOT.h"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/CMS_lumi.C"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/tdrstyle.C"

void DrawFakeRatePlots()
{
  setTDRStyle();
  
  writeExtraText = true;
  extraText = "Preliminary";
  lumi_sqrtS = "41.4 fb^{-1}, 13 TeV";

  TFile* FakeRateFile = new TFile("../Distributions/FakeRateDistributions.root");
  
  TH1F* TightDecayMode0PTFakeRates = (TH1F*) FakeRateFile->Get("TightDecayMode0PTFakeRates");
  TH1F* TightDecayMode1PTFakeRates = (TH1F*) FakeRateFile->Get("TightDecayMode1PTFakeRates");
  TH1F* TightDecayMode10PTFakeRates = (TH1F*) FakeRateFile->Get("TightDecayMode10PTFakeRates");

  gStyle->SetOptStat(0);

  TCanvas* CanvasOne = new TCanvas("CanvasOne","CanvasOne");
  CanvasOne->SetTickx();
  CanvasOne->SetTicky();

  TightDecayMode0PTFakeRates->SetMarkerStyle(20);
  TightDecayMode0PTFakeRates->SetMarkerColor(kBlack);
  TightDecayMode0PTFakeRates->SetLineColor(kBlack);
  TightDecayMode0PTFakeRates->Sumw2();
  TightDecayMode0PTFakeRates->SetMaximum(1.0);
  TightDecayMode0PTFakeRates->SetMinimum(0.0);
  TightDecayMode0PTFakeRates->GetXaxis()->SetTitle("#tau p_{t}");
  TightDecayMode0PTFakeRates->GetYaxis()->SetTitle("Fake Rate");
  TightDecayMode0PTFakeRates->SetTitle("DM0 Fake Rate");

  TightDecayMode0PTFakeRates->Draw();
  
  CMS_lumi(CanvasOne,0,33);

  CanvasOne->SaveAs("../Histos/TightDM0PtFakeRates.png");

  TCanvas* CanvasTwo = new TCanvas("CanvasTwo","CanvasTwo");
  CanvasTwo->SetTickx();
  CanvasTwo->SetTicky();

  TightDecayMode1PTFakeRates->SetMarkerStyle(20);
  TightDecayMode1PTFakeRates->SetMarkerColor(kBlack);
  TightDecayMode1PTFakeRates->SetLineColor(kBlack);
  TightDecayMode1PTFakeRates->Sumw2();
  TightDecayMode1PTFakeRates->SetMaximum(1.0);
  TightDecayMode1PTFakeRates->SetMinimum(0.0);
  TightDecayMode1PTFakeRates->GetXaxis()->SetTitle("#tau p_{t}");
  TightDecayMode1PTFakeRates->GetYaxis()->SetTitle("Fake Rate");
  TightDecayMode1PTFakeRates->SetTitle("DM1 Fake Rate");

  TightDecayMode1PTFakeRates->Draw();
  
  CMS_lumi(CanvasTwo,0,33);

  CanvasTwo->SaveAs("../Histos/TightDM1PtFakeRates.png");

  TCanvas* CanvasThree = new TCanvas("CanvasThree","CanvasThree");
  CanvasThree->SetTickx();
  CanvasThree->SetTicky();

  TightDecayMode10PTFakeRates->SetMarkerStyle(20);
  TightDecayMode10PTFakeRates->SetMarkerColor(kBlack);
  TightDecayMode10PTFakeRates->SetLineColor(kBlack);
  TightDecayMode10PTFakeRates->Sumw2();
  TightDecayMode10PTFakeRates->SetMaximum(1.0);
  TightDecayMode10PTFakeRates->SetMinimum(0.0);
  TightDecayMode10PTFakeRates->GetXaxis()->SetTitle("#tau p_{t}");
  TightDecayMode10PTFakeRates->GetYaxis()->SetTitle("Fake Rate");
  TightDecayMode10PTFakeRates->SetTitle("DM10 Fake Rate");

  TightDecayMode10PTFakeRates->Draw();
  
  CMS_lumi(CanvasThree,0,33);

  CanvasThree->SaveAs("../Histos/TightDM10PtFakeRates.png");
}
