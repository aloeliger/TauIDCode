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
  TH1F* DY_Pass = (TH1F*) PassDirectory->Get("DY_Pass");
  TH1F* DY1_Pass = (TH1F*) PassDirectory->Get("DY1_Pass");
  TH1F* DY2_Pass = (TH1F*) PassDirectory->Get("DY2_Pass");
  TH1F* DY3_Pass = (TH1F*) PassDirectory->Get("DY3_Pass");
  TH1F* DY4_Pass = (TH1F*) PassDirectory->Get("DY4_Pass");
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
  TH1F* DY1_Fail = (TH1F*) FailDirectory->Get("DY1_Fail");
  TH1F* DY2_Fail = (TH1F*) FailDirectory->Get("DY2_Fail");
  TH1F* DY3_Fail = (TH1F*) FailDirectory->Get("DY3_Fail");
  TH1F* DY4_Fail = (TH1F*) FailDirectory->Get("DY4_Fail");
  TH1F* TTTo2L2Nu_Fail = (TH1F*) FailDirectory->Get("TTTo2L2Nu_Fail");
  TH1F* TTToHadronic_Fail = (TH1F*) FailDirectory->Get("TTToHadronic_Fail");
  TH1F* TTToSemiLeptonic_Fail = (TH1F*) FailDirectory->Get("TTToSemiLeptonic_Fail");
  TH1F* WJets_Fail = (TH1F*) FailDirectory->Get(/*"W_Fail"*/"Rescaled_WJets_Fail");
  TH1F* WW_Fail = (TH1F*) FailDirectory->Get("WW_Fail");
  TH1F* WZ_Fail = (TH1F*) FailDirectory->Get("WZ_Fail");
  TH1F* ZZ_Fail = (TH1F*) FailDirectory->Get("ZZ_Fail");
  TH1F* QCD_Fail = (TH1F*) FailDirectory->Get("QCD_Fail");

  //haha
  DY_Pass->Add(DY1_Pass);
  DY_Pass->Add(DY2_Pass);
  DY_Pass->Add(DY3_Pass);
  DY_Pass->Add(DY4_Pass);

  DY_Fail->Add(DY1_Fail);
  DY_Fail->Add(DY2_Fail);
  DY_Fail->Add(DY3_Fail);
  DY_Fail->Add(DY4_Fail);
  
  
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
  PassStack->Add(DY_Pass,"hist");
  PassStack->Add(TT_Pass,"hist");
  PassStack->Add(DiBoson_Pass,"hist");

  Data_Pass->Draw();
  PassStack->Draw("SAME");
  Data_Pass->SetTitle("#mu#tau Invariant Mass Pass");
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
  FailStack->Add(DY_Fail,"hist");
  FailStack->Add(TT_Fail,"hist");
  FailStack->Add(DiBoson_Fail,"hist");  

  Data_Fail->Draw();
  FailStack->Draw("SAME");
  Data_Fail->SetTitle("#mu#tau Invariant Mass Fail");
  Data_Fail->Draw("SAME");
  Data_Fail->GetXaxis()->SetTitle("#mu#tau Invariant Mass (GeV)");
  Data_Fail->GetYaxis()->SetTitle("Events");

  CMS_lumi(C2,0,11);

  Legend->Draw();

  TCanvas* C3 = new TCanvas("C3", "#mu#tau Invariant Mass");
  C3->SetTickx();
  C3->SetTicky();

  TH1F* Data = new TH1F("Data","Data",Data_Fail->GetSize()-2,Data_Fail->GetXaxis()->GetXmin(),Data_Fail->GetXaxis()->GetXmax());
  Data->Add(Data_Fail, Data_Pass);
  
  TH1F* DY = new TH1F("DY","DY",Data_Fail->GetSize()-2,Data_Fail->GetXaxis()->GetXmin(),Data_Fail->GetXaxis()->GetXmax());
  DY->Add(DY_Fail, DY_Pass);

  TH1F* DiBoson = new TH1F("DiBoson","DiBoson",Data_Fail->GetSize()-2,Data_Fail->GetXaxis()->GetXmin(),Data_Fail->GetXaxis()->GetXmax());
  DiBoson->Add(DiBoson_Fail, DiBoson_Pass);

  TH1F* TT = new TH1F("TT","TT",Data_Fail->GetSize()-2,Data_Fail->GetXaxis()->GetXmin(),Data_Fail->GetXaxis()->GetXmax());
  TT->Add(TT_Fail,TT_Pass);
  
  TH1F* WJets = new TH1F("WJets","WJets",Data_Fail->GetSize()-2,Data_Fail->GetXaxis()->GetXmin(),Data_Fail->GetXaxis()->GetXmax());
  WJets->Add(WJets_Fail,WJets_Pass);  
  
  TH1F* QCD = new TH1F("QCD","QCD",Data_Fail->GetSize()-2,Data_Fail->GetXaxis()->GetXmin(),Data_Fail->GetXaxis()->GetXmax());
  QCD->Add(QCD_Fail,QCD_Pass);

  Data->SetMarkerStyle(20);
  Data->Sumw2();
  
  DY->SetLineColor(kBlack);
  DY->SetFillColor(kAzure-3);

  DiBoson->SetLineColor(kBlack);
  DiBoson->SetFillColor(kPink-3);

  TT->SetLineColor(kBlack);
  TT->SetFillColor(kViolet-3);

  WJets->SetLineColor(kBlack);
  WJets->SetFillColor(kGreen-3);

  QCD->SetLineColor(kBlack);
  QCD->SetFillColor(kPink+1);

  THStack* TotalStack = new THStack("TotalStack","TotalStack");
  TotalStack->Add(QCD,"hist");
  TotalStack->Add(WJets,"hist");
  TotalStack->Add(DY,"hist");
  TotalStack->Add(TT,"hist");
  TotalStack->Add(DiBoson,"hist");  

  Data->Draw();
  TotalStack->Draw("SAME");
  Data->SetTitle("#mu#tau Invariant Mass");
  Data->Draw("SAME");
  Data->GetXaxis()->SetTitle("#mu#tau Invariant Mass (GeV)");
  Data->GetYaxis()->SetTitle("Events");

  CMS_lumi(C3,0,11);

  Legend->Draw();

  //Write these to a histo file.
  TFile* HistoFile = new TFile("Histos/HistoFile.root","RECREATE");
  C1->Write();
  C2->Write();
  C3->Write();
  HistoFile->Close();

  C1->SaveAs("Histos/pass.png");
  C2->SaveAs("Histos/fail.png");
  C3->SaveAs("Histos/total.png");

  std::cout<<std::endl;
  std::cout<<"Integrals: "<<std::endl;
  std::cout<<"Data Pass: "<<Data_Pass->Integral()<<std::endl;
  float PassStackIntegral = QCD_Pass->Integral()+WJets_Pass->Integral()+DY_Pass->Integral()+TT_Pass->Integral()+DiBoson_Pass->Integral();    
  std::cout<<"Pass Stack: "<<PassStackIntegral<<std::endl;  
  std::cout<<"Data Fail: "<<Data_Fail->Integral()<<std::endl;
  float FailStackIntegral = QCD_Fail->Integral()+WJets_Fail->Integral()+DY_Fail->Integral()+TT_Fail->Integral()+DiBoson_Fail->Integral();    
  std::cout<<"Fail Stack: "<<FailStackIntegral<<std::endl;
  std::cout<<std::endl;
}
