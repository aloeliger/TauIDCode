#include "TROOT.h"

void CompareJetsToWAndQCD(string IsoWorkingPoint)
{
  TFile* JetsFile = new TFile("../Distributions/FakeRateDeterminedDistributions.root");
  TFile* WAndQCDFile = new TFile("../Distributions/PassFailOut.root");
  TDirectory* passDirectory = (TDirectory*) WAndQCDFile->Get("pass");
  
  TH1F* JetsDistribution;
  if(IsoWorkingPoint == "VLoose") JetsDistribution = (TH1F*) JetsFile->Get("VLoosePTFRJetDistribution");
  else if(IsoWorkingPoint == "Loose") JetsDistribution = (TH1F*) JetsFile->Get("LoosePTFRJetDistribution");
  else if(IsoWorkingPoint == "Medium") JetsDistribution = (TH1F*) JetsFile->Get("MediumPTFRJetDistribution");
  else if(IsoWorkingPoint == "Tight") JetsDistribution = (TH1F*) JetsFile->Get("TightPTFRJetDistribution");
  else if(IsoWorkingPoint == "VTight") JetsDistribution = (TH1F*) JetsFile->Get("VTightPTFRJetDistribution");
  else if(IsoWorkingPoint == "VVTight") JetsDistribution = (TH1F*) JetsFile->Get("VVTightPTFRJetDistribution");
  
  TH1F* WJets = (TH1F*) passDirectory->Get("Rescaled_WJets_Pass");
  TH1F* QCD = (TH1F*) passDirectory->Get("QCD_Pass");

  TH1F* RatioHist = (TH1F*) JetsDistribution->Clone();
  TH1F* DenominatorHisto = (TH1F*) WJets->Clone();
  DenominatorHisto->Add(QCD);
  
  RatioHist->Divide(DenominatorHisto);
  
  //Start reweighting things
  
  TH1F* DownWeightedJetsDistribution = (TH1F*) JetsDistribution->Clone();
  TH1F* UpWeightedJetsDistribution = (TH1F*) JetsDistribution->Clone();
  for(int Index = 1; Index <= JetsDistribution->GetNbinsX(); ++Index)
    {
      DownWeightedJetsDistribution->SetBinContent(Index, (1.0/RatioHist->GetBinContent(Index))*JetsDistribution->GetBinContent(Index));
      UpWeightedJetsDistribution->SetBinContent(Index,(2.0*(RatioHist->GetBinContent(Index)-1.0)+1.0)*JetsDistribution->GetBinContent(Index));
    }

  //ought these be area normalized to the regular jets distribution?
  DownWeightedJetsDistribution->Scale(JetsDistribution->Integral()/DownWeightedJetsDistribution->Integral());
  UpWeightedJetsDistribution->Scale(JetsDistribution->Integral()/UpWeightedJetsDistribution->Integral());

  JetsDistribution->SetLineColor(kRed);
  DenominatorHisto->SetLineColor(kBlue);
  DownWeightedJetsDistribution->SetLineColor(kGreen);
  UpWeightedJetsDistribution->SetLineColor(kOrange);

  TLegend* TheLegend = new TLegend(0.7,0.7,0.9,0.9);
  TheLegend->AddEntry(JetsDistribution, "Nominal Jets", "l");
  TheLegend->AddEntry(DenominatorHisto, "QCD WJets", "l");
  TheLegend->AddEntry(DownWeightedJetsDistribution, "Downweighted Jets", "l");
  TheLegend->AddEntry(UpWeightedJetsDistribution, "UpweightedJets", "l");

  TCanvas* TheCanvas = new TCanvas("Comparisons","Comparison");

  UpWeightedJetsDistribution->Draw();
  JetsDistribution->Draw("SAME");
  DenominatorHisto->Draw("SAME");
  DownWeightedJetsDistribution->Draw("SAME");

  TheLegend->Draw();
  
  DownWeightedJetsDistribution->SetNameTitle("Jets_WQCDShapeDown","Jets_WQCDShapeDown");
  UpWeightedJetsDistribution->SetNameTitle("Jets_WQCDShapeUp","Jets_WQCDShapeUp");

  TFile* UpdateFile = new TFile("../Distributions/FakeRateDeterminedDistributions.root","UPDATE");
  DownWeightedJetsDistribution->Write();
  UpWeightedJetsDistribution->Write();
}
