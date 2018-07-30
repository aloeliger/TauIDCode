#include "TROOT.h"

void GenerateMuMuQCD()
{
  TFile* QCDFile = new TFile("../Distributions/ZMuMu.root", "UPDATE");
  
  TH1F* QCDHisto = (TH1F*) ((TH1F*) QCDFile->Get("Data_QCD"))->Clone("QCD");
  
  TH1F* DYHisto = (TH1F*) QCDFile->Get("DY_QCD");
  TH1F* DY1Histo = (TH1F*) QCDFile->Get("DY1_QCD");
  TH1F* DY2Histo = (TH1F*) QCDFile->Get("DY2_QCD");
  TH1F* DY3Histo = (TH1F*) QCDFile->Get("DY3_QCD");
  TH1F* DY4Histo = (TH1F*) QCDFile->Get("DY4_QCD");
  TH1F* TTTo2L2NuHisto = (TH1F*) QCDFile->Get("TTTo2L2Nu_QCD");
  TH1F* TTToHadronicHisto = (TH1F*) QCDFile->Get("TTToHadronic_QCD");
  TH1F* TTToSemiLeptonicHisto = (TH1F*) QCDFile->Get("TTToSemiLeptonic_QCD");
  TH1F* WHisto = (TH1F*) QCDFile->Get("W_QCD");
  TH1F* W1Histo = (TH1F*) QCDFile->Get("W1_QCD");
  TH1F* W2Histo = (TH1F*) QCDFile->Get("W2_QCD");
  TH1F* W3Histo = (TH1F*) QCDFile->Get("W3_QCD");
  TH1F* W4Histo = (TH1F*) QCDFile->Get("W4_QCD");
  TH1F* WWHisto = (TH1F*) QCDFile->Get("WW_QCD");
  TH1F* WZHisto = (TH1F*) QCDFile->Get("WZ_QCD");
  TH1F* ZZHisto = (TH1F*) QCDFile->Get("ZZ_QCD");

  QCDHisto->Add(DYHisto, -1.0);
  QCDHisto->Add(DY1Histo, -1.0);
  QCDHisto->Add(DY2Histo, -1.0);
  QCDHisto->Add(DY3Histo, -1.0);
  QCDHisto->Add(DY4Histo, -1.0);
  QCDHisto->Add(TTTo2L2NuHisto, -1.0);
  QCDHisto->Add(TTToHadronicHisto, -1.0);
  QCDHisto->Add(TTToSemiLeptonicHisto, -1.0);
  QCDHisto->Add(WHisto, -1.0);
  QCDHisto->Add(W1Histo, -1.0);
  QCDHisto->Add(W2Histo, -1.0);
  QCDHisto->Add(W3Histo, -1.0);
  QCDHisto->Add(W4Histo, -1.0);
  QCDHisto->Add(WWHisto, -1.0);
  QCDHisto->Add(WZHisto, -1.0);
  QCDHisto->Add(ZZHisto, -1.0);

  QCDHisto->Scale(1.05);
  
  QCDHisto->Write();
  
}
