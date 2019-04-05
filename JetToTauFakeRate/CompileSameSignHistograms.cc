#include "TROOT.h"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/CMS_lumi.C"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/tdrstyle.C"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/MakeRatioPlot.cc"
#include <string>

void CompileSameSignHistograms(std::string Iso)
{
  setTDRStyle();
  
  writeExtraText = true;
  extraText = "Preliminary";
  lumi_sqrtS = "41 fb^{-1}, 13 TeV";

  TFile * QCDFile = new TFile("../Distributions/QCDDistributions.root");
  TDirectory *PassDirectory = (TDirectory*) QCDFile->Get("pass");
  TDirectory *FailDirectory = (TDirectory*) QCDFile->Get("fail");

  TH1F* Data_Pass = (TH1F*) PassDirectory->Get("QCD_Data_Pass");
  
  TH1F* ZTauTau_Pass = (TH1F*) PassDirectory->Get("QCD_GenMatch_DY_Pass");
  TH1F* ZTauTau1_Pass = (TH1F*) PassDirectory->Get("QCD_GenMatch_DY1_Pass");
  TH1F* ZTauTau2_Pass = (TH1F*) PassDirectory->Get("QCD_GenMatch_DY2_Pass");
  TH1F* ZTauTau3_Pass = (TH1F*) PassDirectory->Get("QCD_GenMatch_DY3_Pass");
  TH1F* ZTauTau4_Pass = (TH1F*) PassDirectory->Get("QCD_GenMatch_DY4_Pass");
  ZTauTau_Pass->Add(ZTauTau1_Pass);
  ZTauTau_Pass->Add(ZTauTau2_Pass);
  ZTauTau_Pass->Add(ZTauTau3_Pass);
  ZTauTau_Pass->Add(ZTauTau4_Pass);
  TH1F* LowGenMatch_DY_Pass = (TH1F*) PassDirectory->Get("QCD_LowGenMatch_DY_Pass");
  TH1F* LowGenMatch_DY1_Pass = (TH1F*) PassDirectory->Get("QCD_LowGenMatch_DY1_Pass");
  TH1F* LowGenMatch_DY2_Pass = (TH1F*) PassDirectory->Get("QCD_LowGenMatch_DY2_Pass");
  TH1F* LowGenMatch_DY3_Pass = (TH1F*) PassDirectory->Get("QCD_LowGenMatch_DY3_Pass");
  TH1F* LowGenMatch_DY4_Pass = (TH1F*) PassDirectory->Get("QCD_LowGenMatch_DY4_Pass");
  TH1F* HighGenMatch_DY_Pass = (TH1F*) PassDirectory->Get("QCD_HighGenMatch_DY_Pass");
  TH1F* HighGenMatch_DY1_Pass = (TH1F*) PassDirectory->Get("QCD_HighGenMatch_DY1_Pass");
  TH1F* HighGenMatch_DY2_Pass = (TH1F*) PassDirectory->Get("QCD_HighGenMatch_DY2_Pass");
  TH1F* HighGenMatch_DY3_Pass = (TH1F*) PassDirectory->Get("QCD_HighGenMatch_DY3_Pass");
  TH1F* HighGenMatch_DY4_Pass = (TH1F*) PassDirectory->Get("QCD_HighGenMatch_DY4_Pass");
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY1_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY2_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY3_Pass);
  LowGenMatch_DY_Pass->Add(LowGenMatch_DY4_Pass);
  LowGenMatch_DY_Pass->Add(HighGenMatch_DY_Pass);
  LowGenMatch_DY_Pass->Add(HighGenMatch_DY1_Pass);
  LowGenMatch_DY_Pass->Add(HighGenMatch_DY2_Pass);
  LowGenMatch_DY_Pass->Add(HighGenMatch_DY3_Pass);
  LowGenMatch_DY_Pass->Add(HighGenMatch_DY4_Pass);
  
  TH1F* TTTo2L2Nu_Pass = (TH1F*) PassDirectory->Get("QCD_TTTo2L2Nu_Pass");
  TH1F* TTToHadronic_Pass = (TH1F*) PassDirectory->Get("QCD_TTToHadronic_Pass");
  TH1F* TTToSemiLeptonic_Pass = (TH1F*) PassDirectory->Get("QCD_TTToSemiLeptonic_Pass");

  TH1F* WW_Pass = (TH1F*) PassDirectory->Get("QCD_WW_Pass");
  TH1F* WZ_Pass = (TH1F*) PassDirectory->Get("QCD_WZ_Pass");
  TH1F* ZZ_Pass = (TH1F*) PassDirectory->Get("QCD_ZZ_Pass");
  
  TFile* FakeRateDeterminedDistributions = new TFile("../Distributions/CorrectedFakeRateDeterminedDistributions.root"); 
  TH1F* JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get((Iso+"PTFRJetDistribution_SS").c_str());

  TCanvas* TheCanvas = new TCanvas("TheCanvas", "#mu#tau Invariant Mass");
  TheCanvas->SetTickx();
  TheCanvas->SetTicky();

  TH1F* DiBoson_Pass = new TH1F("DiBoson_Pass","DiBoson_Pass",Data_Pass->GetSize()-2,Data_Pass->GetXaxis()->GetXmin(),Data_Pass->GetXaxis()->GetXmax());
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

  JetDistribution->SetLineColor(kBlack);
  JetDistribution->SetFillColor(kRed);

  THStack * PassStack = new THStack("PassStack","PassStack");
  PassStack->Add(JetDistribution,"hist");
  PassStack->Add(ZTauTau_Pass,"hist");
  PassStack->Add(LowGenMatch_DY_Pass,"hist");
  PassStack->Add(TT_Pass,"hist");
  PassStack->Add(DiBoson_Pass,"hist");

  TPad* PlotPad_Pass = MakeRatioPlot(TheCanvas, PassStack, Data_Pass,"m_{vis}",0.7,1.3);    

  PassStack->Draw();
  PassStack->SetTitle("#mu#tau Invariant Mass Same Sign");  
  PassStack->GetXaxis()->SetTitle("#mu#tau Invariant Mass (GeV)");
  PassStack->GetYaxis()->SetTitle("Events");
  Data_Pass->Draw("SAME");
  CMS_lumi(PlotPad_Pass,0,33);

  TLegend* Legend = new TLegend(0.7, 0.5, 0.88, 0.68);
  Legend->AddEntry(Data_Pass, "Data", "ep");
  Legend->AddEntry(ZTauTau_Pass,"Z #rightarrow #tau#tau", "f");
  Legend->AddEntry(LowGenMatch_DY_Pass, "Other Drell-Yan", "f");
  Legend->AddEntry(DiBoson_Pass, "DiBoson", "f");
  Legend->AddEntry(TT_Pass, "t#bar{t}","f");
  Legend->AddEntry(JetDistribution, "Fakes", "f");
  
  Legend->Draw();

  TheCanvas->Draw();

  TheCanvas->SaveAs("../Histos/SameSignJets.png");
}
