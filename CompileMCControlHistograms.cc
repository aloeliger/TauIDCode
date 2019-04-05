#include "TROOT.h"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/CMS_lumi.C"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/tdrstyle.C"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/MakeRatioPlot.cc"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/MakeStackErrors.cc"
#include <string>

void CompileMCControlHistograms(std::string ControlVar)
{
  setTDRStyle();
  
  writeExtraText = true;
  extraText = "Preliminary";
  lumi_sqrtS = "41.5 fb^{-1}, 13 TeV";

  TFile *PassFailFile = new TFile("Distributions/PassFailOut.root");
  TDirectory* ControlDir = (TDirectory*) PassFailFile->Get("control");

  TH1F* Data_Histo = (TH1F*) ControlDir->Get(("Data_"+ControlVar).c_str());

  TH1F* ZTauTau_Histo = (TH1F*) ControlDir->Get(("GenMatch_DY_"+ControlVar).c_str());
  TH1F* ZTauTau1_Histo = (TH1F*) ControlDir->Get(("GenMatch_DY1_"+ControlVar).c_str());
  TH1F* ZTauTau2_Histo = (TH1F*) ControlDir->Get(("GenMatch_DY2_"+ControlVar).c_str());
  TH1F* ZTauTau3_Histo = (TH1F*) ControlDir->Get(("GenMatch_DY3_"+ControlVar).c_str());
  TH1F* ZTauTau4_Histo = (TH1F*) ControlDir->Get(("GenMatch_DY4_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY_Histo = (TH1F*) ControlDir->Get(("LowGenMatch_DY_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY1_Histo = (TH1F*) ControlDir->Get(("LowGenMatch_DY1_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY2_Histo = (TH1F*) ControlDir->Get(("LowGenMatch_DY2_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY3_Histo = (TH1F*) ControlDir->Get(("LowGenMatch_DY3_"+ControlVar).c_str());
  TH1F* LowGenMatch_DY4_Histo = (TH1F*) ControlDir->Get(("LowGenMatch_DY4_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY_Histo = (TH1F*) ControlDir->Get(("HighGenMatch_DY_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY1_Histo = (TH1F*) ControlDir->Get(("HighGenMatch_DY1_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY2_Histo = (TH1F*) ControlDir->Get(("HighGenMatch_DY2_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY3_Histo = (TH1F*) ControlDir->Get(("HighGenMatch_DY3_"+ControlVar).c_str());
  TH1F* HighGenMatch_DY4_Histo = (TH1F*) ControlDir->Get(("HighGenMatch_DY4_"+ControlVar).c_str());

  TH1F* TTTo2L2Nu_Histo = (TH1F*) ControlDir->Get(("TTTo2L2Nu_"+ControlVar).c_str());
  TH1F* TTToHadronic_Histo = (TH1F*) ControlDir->Get(("TTToHadronic_"+ControlVar).c_str());
  TH1F* TTToSemiLeptonic_Histo = (TH1F*) ControlDir->Get(("TTToSemiLeptonic_"+ControlVar).c_str());
  
  TH1F* WW_Histo = (TH1F*) ControlDir->Get(("WW_"+ControlVar).c_str());
  TH1F* WZ_Histo = (TH1F*) ControlDir->Get(("WZ_"+ControlVar).c_str());
  TH1F* ZZ_Histo = (TH1F*) ControlDir->Get(("ZZ_"+ControlVar).c_str());
  
  TH1F* WJets_Histo = (TH1F*) ControlDir->Get(("Rescaled_WJets_"+ControlVar).c_str());
  /*TH1F* WJets_Histo = (TH1F*) ControlDir->Get(("W_"+ControlVar).c_str());
  WJets_Histo->Add((TH1F*) ControlDir->Get(("W1_"+ControlVar).c_str()));
  WJets_Histo->Add((TH1F*) ControlDir->Get(("W2_"+ControlVar).c_str()));
  WJets_Histo->Add((TH1F*) ControlDir->Get(("W3_"+ControlVar).c_str()));
  WJets_Histo->Add((TH1F*) ControlDir->Get(("W4_"+ControlVar).c_str()));*/
  
  TH1F* QCD_Histo = (TH1F*) ControlDir->Get(("QCD_"+ControlVar).c_str());

  LowGenMatch_DY_Histo->Add(LowGenMatch_DY1_Histo);
  LowGenMatch_DY_Histo->Add(LowGenMatch_DY2_Histo);
  LowGenMatch_DY_Histo->Add(LowGenMatch_DY3_Histo);
  LowGenMatch_DY_Histo->Add(LowGenMatch_DY4_Histo);
  LowGenMatch_DY_Histo->Add(HighGenMatch_DY_Histo);
  LowGenMatch_DY_Histo->Add(HighGenMatch_DY1_Histo);
  LowGenMatch_DY_Histo->Add(HighGenMatch_DY2_Histo);
  LowGenMatch_DY_Histo->Add(HighGenMatch_DY3_Histo);
  LowGenMatch_DY_Histo->Add(HighGenMatch_DY4_Histo);

  ZTauTau_Histo->Add(ZTauTau1_Histo);
  ZTauTau_Histo->Add(ZTauTau2_Histo);
  ZTauTau_Histo->Add(ZTauTau3_Histo);
  ZTauTau_Histo->Add(ZTauTau4_Histo);

  TH1F* TT_Histo = (TH1F*) TTTo2L2Nu_Histo->Clone();
  TT_Histo->Add(TTToHadronic_Histo);
  TT_Histo->Add(TTToSemiLeptonic_Histo);

  TH1F* Diboson_Histo = (TH1F*) WW_Histo->Clone();
  Diboson_Histo->Add(WZ_Histo);
  Diboson_Histo->Add(ZZ_Histo);

  TCanvas* TheCanvas = new TCanvas("TheCanvas", "TheCanvas");

  Data_Histo->SetMarkerStyle(20);
 
  ZTauTau_Histo->SetLineColor(kBlack);
  ZTauTau_Histo->SetFillColor(TColor::GetColor("#ffcc66"));

  LowGenMatch_DY_Histo->SetLineColor(kBlack);
  LowGenMatch_DY_Histo->SetFillColor(TColor::GetColor("#4496c8"));

  Diboson_Histo->SetLineColor(kBlack);
  Diboson_Histo->SetFillColor(TColor::GetColor("#12cadd"));

  TT_Histo->SetLineColor(kBlack);
  TT_Histo->SetFillColor(TColor::GetColor("#9999cc"));

  WJets_Histo->SetLineColor(kBlack);
  WJets_Histo->SetFillColor(TColor::GetColor("#a53db8"));

  QCD_Histo->SetLineColor(kBlack);
  QCD_Histo->SetFillColor(TColor::GetColor("#ffccff"));

  THStack* BackgroundStack = new THStack("backgroundStack","BackgroundStack");
  BackgroundStack->Add(QCD_Histo,"hist");
  BackgroundStack->Add(WJets_Histo,"hist");
  BackgroundStack->Add(ZTauTau_Histo,"hist");
  BackgroundStack->Add(LowGenMatch_DY_Histo,"hist");
  BackgroundStack->Add(TT_Histo,"hist");
  BackgroundStack->Add(Diboson_Histo,"hist");

  TH1F* BackgroundStack_Errors = MakeStackErrors(BackgroundStack);

  TPad* PlotPad = MakeRatioPlot(TheCanvas,BackgroundStack,Data_Histo,ControlVar,0.7,1.3);

  BackgroundStack->SetMaximum(max(BackgroundStack->GetMaximum(),Data_Histo->GetMaximum()));
  BackgroundStack->Draw();
  BackgroundStack->SetTitle(("#mu#tau "+ControlVar).c_str());
  BackgroundStack->GetXaxis()->SetLabelSize(0.0);
  BackgroundStack->GetYaxis()->SetTitle("Events");
  Data_Histo->Draw("SAME e1");
  BackgroundStack_Errors->Draw("SAME e2");

  CMS_lumi(PlotPad,0,33);

  TLegend* TheLegend = new TLegend(0.7,0.5,0.88,0.68);
  TheLegend->AddEntry(Data_Histo, "Data","EP");
  TheLegend->AddEntry(ZTauTau_Histo, "Z #rightarrow #tau#tau", "f");
  TheLegend->AddEntry(LowGenMatch_DY_Histo, "Other Drell-Yan", "f");
  TheLegend->AddEntry(Diboson_Histo, "VV", "f");
  TheLegend->AddEntry(TT_Histo, "t#bar{t}","f");
  TheLegend->AddEntry(WJets_Histo, "W+Jets","f");
  TheLegend->AddEntry(QCD_Histo ,"QCD", "f");
  
  TheLegend->Draw();
  TheCanvas->Draw();
  
  TheCanvas->SaveAs(("Histos/Control_"+ControlVar+".png").c_str());
}
