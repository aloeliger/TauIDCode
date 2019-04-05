#include "TROOT.h"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/CMS_lumi.C"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/tdrstyle.C"
#include "/afs/cern.ch/user/a/aloelige/private/ScriptsAndMacros/MakeRatioPlot.cc"
#include <string>

void CompileMuMuHistograms(std::string tag = "")
{

  setTDRStyle();

  writeExtraText = true;
  extraText = "Preliminary";
  lumi_sqrtS = "41 fb^{-1}, 13TeV";

  TFile* LoadFile = new TFile("../Distributions/ZMuMu.root");
  
  TH1F* DataHisto = (TH1F*)LoadFile->Get(("Data"+tag).c_str());
  TH1F* DY1Histo = (TH1F*)LoadFile->Get(("DY1"+tag).c_str());
  TH1F* DY2Histo = (TH1F*)LoadFile->Get(("DY2"+tag).c_str());
  TH1F* DY3Histo = (TH1F*)LoadFile->Get(("DY3"+tag).c_str());
  TH1F* DY4Histo = (TH1F*)LoadFile->Get(("DY4"+tag).c_str());
  TH1F* DYHisto = (TH1F*)LoadFile->Get(("DY"+tag).c_str());
  TH1F* TTTo2L2NuHisto = (TH1F*)LoadFile->Get(("TTTo2L2Nu"+tag).c_str());
  TH1F* TTToHadronicHisto = (TH1F*)LoadFile->Get(("TTToHadronic"+tag).c_str());
  TH1F* TTToSemiLeptonicHisto = (TH1F*)LoadFile->Get(("TTToSemiLeptonic"+tag).c_str());
  TH1F* W1Histo = (TH1F*)LoadFile->Get(("W1"+tag).c_str());
  TH1F* W2Histo = (TH1F*)LoadFile->Get(("W2"+tag).c_str());
  TH1F* W3Histo = (TH1F*)LoadFile->Get(("W3"+tag).c_str());
  TH1F* W4Histo = (TH1F*)LoadFile->Get(("W4"+tag).c_str());
  TH1F* WHisto = (TH1F*)LoadFile->Get(("W"+tag).c_str());
  TH1F* WWHisto = (TH1F*)LoadFile->Get(("WW"+tag).c_str());
  TH1F* WZHisto = (TH1F*)LoadFile->Get(("WZ"+tag).c_str());
  TH1F* ZZHisto = (TH1F*)LoadFile->Get(("ZZ"+tag).c_str());
  //new Single top stuff
  TH1F* ST_topHisto = (TH1F*) LoadFile->Get(("ST_top"+tag).c_str());
  TH1F* ST_antitopHisto = (TH1F*) LoadFile->Get(("ST_antitop"+tag).c_str());
  TH1F* ST_tW_topHisto = (TH1F*) LoadFile->Get(("ST_tW_top"+tag).c_str());
  TH1F* ST_tW_antitopHisto = (TH1F*) LoadFile->Get(("ST_tW_antitop"+tag).c_str());
  
  DYHisto->Add(DY1Histo);
  DYHisto->Add(DY2Histo);
  DYHisto->Add(DY3Histo);
  DYHisto->Add(DY4Histo);

  WHisto->Add(W1Histo);
  WHisto->Add(W2Histo);
  WHisto->Add(W3Histo);
  WHisto->Add(W4Histo);

  gStyle->SetOptStat(0);

  std::cout<<"DY Integral: "<<DYHisto->Integral()<<std::endl;
  std::cout<<"Data Integral: "<<DataHisto->Integral()<<std::endl;
  std::cout<<"Data/DY: "<<(DataHisto->Integral()/DYHisto->Integral())<<std::endl;  

  TCanvas* C1 = new TCanvas("C1","#mu#mu");
  C1->SetTickx();
  C1->SetTicky();

  TH1F* DiBosonHisto = new TH1F("DiBosonHisto","DiBosonHisto", DataHisto->GetSize()-2, DataHisto->GetXaxis()->GetXmin(), DataHisto->GetXaxis()->GetXmax());
  DiBosonHisto->Add(WWHisto,WZHisto);
  DiBosonHisto->Add(ZZHisto);
  //add the ST to this
  DiBosonHisto->Add(ST_topHisto);
  DiBosonHisto->Add(ST_antitopHisto);
  DiBosonHisto->Add(ST_tW_topHisto);
  DiBosonHisto->Add(ST_tW_antitopHisto);

  TH1F* TTHisto = new TH1F("TTHisto","TTHisto",DataHisto->GetSize()-2, DataHisto->GetXaxis()->GetXmin(), DataHisto->GetXaxis()->GetXmax());
  TTHisto->Add(TTTo2L2NuHisto,TTToHadronicHisto);
  TTHisto->Add(TTToSemiLeptonicHisto);

  DataHisto->SetMarkerStyle(20);
  DataHisto->Sumw2();

  DYHisto->SetLineColor(kBlack);
  DYHisto->SetFillColor(TColor::GetColor("#4496c8"));
  
  DiBosonHisto->SetLineColor(kBlack);
  DiBosonHisto->SetFillColor(TColor::GetColor("#12cadd"));
  
  TTHisto->SetLineColor(kBlack);
  TTHisto->SetFillColor(TColor::GetColor("#9999cc"));
  
  WHisto->SetLineColor(kBlack);
  WHisto->SetFillColor(TColor::GetColor("#a53db8"));
  
  THStack* BackgroundStack = new THStack("BackgroundStack","BackgroundStack");  
  BackgroundStack->Add(DiBosonHisto, "hist");  
  BackgroundStack->Add(WHisto, "hist");  
  BackgroundStack->Add(TTHisto, "hist");
  BackgroundStack->Add(DYHisto,"hist");  

  std::cout<<"Data/Background: "<<(DataHisto->Integral()/(DiBosonHisto->Integral()+WHisto->Integral()+TTHisto->Integral()+DYHisto->Integral()))<<std::endl;

  BackgroundStack->SetMaximum(max(BackgroundStack->GetMaximum(),DataHisto->GetMaximum())*1.05);
  BackgroundStack->SetMinimum(0.1);

  string Xaxis = tag;
  if(Xaxis == "") Xaxis = "m_{vis}";
  else Xaxis.erase(0,1);
  std::cout<<tag<<std::endl;
  std::cout<<Xaxis<<std::endl;
  
  TPad* PlotPad = MakeRatioPlot(C1, BackgroundStack, DataHisto, Xaxis ,0.5,2.5);
  PlotPad->SetLogy();
  BackgroundStack->Draw();
  string OverallTitle = tag;
  if(OverallTitle == "") OverallTitle="Invariant Mass";
  else OverallTitle.erase(0,1);
  BackgroundStack->SetTitle(("#mu#mu "+OverallTitle).c_str());
  //BackgroundStack->GetXaxis()->SetTitle("#mu#mu Invariant Mass (GeV)");
  BackgroundStack->GetXaxis()->SetLabelSize(0.0);
  BackgroundStack->GetYaxis()->SetTitle("Events");
  DataHisto->Draw("SAME");
  CMS_lumi(PlotPad,0,33);

  TLegend* Legend = new TLegend(0.7, 0.5, 0.88, 0.68);
  Legend->AddEntry(DataHisto, "Data", "ep");
  Legend->AddEntry(DYHisto, "Z #rightarrow #mu#mu", "f");
  Legend->AddEntry(DiBosonHisto, "VV+ST", "f");
  Legend->AddEntry(TTHisto, "t#bar{t}", "f");
  Legend->AddEntry(WHisto, "W+Jets", "f");

  Legend->Draw();
  
  C1->Draw();

  TFile* HistoFile = new TFile("../Histos/MuMuHistoFile.root","RECREATE");
  C1->Write();
  
  C1->SaveAs(("../Histos/MuMu"+tag+".png").c_str());
}
