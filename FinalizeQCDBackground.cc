#include "TROOT.h"

void FinalizeQCDBackground()
{
  TFile* QCDFile = new TFile("QCDDistributions.root","READ");
  TDirectory* QCD_PassDir = (TDirectory *) QCDFile->Get("PassRegion");
  TDirectory* QCD_FailDir = (TDirectory *) QCDFile->Get("FailRegion");
  
  //pass histos
  cout<<"Retrieving Pass Region Histograms"<<std::endl;
  TH1F* QCD_Pass = (TH1F *) QCD_PassDir->Get("Data_Pass");
  TH1F* DY_Pass = (TH1F *) QCD_PassDir->Get("DY_pass");
  TH1F* TTTo2L2Nu_Pass = (TH1F *) QCD_PassDir->Get("TTTo2L2Nu_Pass");
  TH1F* TTToHadronic_Pass = (TH1F *) QCD_PassDir->Get("TTToHadronic_Pass");
  TH1F* TTToSemiLeptonic_Pass =  (TH1F *) QCD_PassDir->Get("TTToSemiLeptonic_Pass");
  TH1F* W_Pass = (TH1F *) QCD_PassDir->Get("W_Pass");
  TH1F* WW_Pass = (TH1F *) QCD_PassDir->Get("WW_Pass");
  TH1F* WZ_Pass = (TH1F *) QCD_PassDir->Get("WZ_Pass");
  TH1F* ZZ_Pass = (TH1F *) QCD_PassDir->Get("ZZ_Pass");

  QCD_Pass->SetName("QCD_Pass");

  //fail histos
  std::cout<<"Retrieving Fail Region Histograms"<<std::endl;
  TH1F* QCD_Fail = (TH1F *) QCD_FailDir->Get("Data_Fail");
  TH1F* DY_Fail = (TH1F *) QCD_FailDir->Get("DY_pass");
  TH1F* TTTo2L2Nu_Fail = (TH1F *) QCD_FailDir->Get("TTTo2L2Nu_Fail");
  TH1F* TTToHadronic_Fail = (TH1F *) QCD_FailDir->Get("TTToHadronic_Fail");
  TH1F* TTToSemiLeptonic_Fail =  (TH1F *) QCD_FailDir->Get("TTToSemiLeptonic_Fail");
  TH1F* W_Fail = (TH1F *) QCD_FailDir->Get("W_Fail");
  TH1F* WW_Fail = (TH1F *) QCD_FailDir->Get("WW_Fail");
  TH1F* WZ_Fail = (TH1F *) QCD_FailDir->Get("WZ_Fail");
  TH1F* ZZ_Fail = (TH1F *) QCD_FailDir->Get("ZZ_Fail");

  QCD_Fail->SetName("QCD_Fail");

  //reweight the wjets histogram by the scale factors we figured out
  TFile* ScaleFactorFile = new TFile("TemporaryFiles/CorrectedWJetsDistributions.root");
  
  TH1F* ScaleFactors_Pass = (TH1F*) ScaleFactorFile->Get("ScaleFactors_Pass");
  TH1F* ScaleFactors_Fail = (TH1F*) ScaleFactorFile->Get("ScaleFactors_Fail");

  for(int i=1; i<= ScaleFactors_Pass->GetSize()-2; i++)
    {
      QCD_Pass->SetBinContent(i,QCD_Pass->GetBinContent(i)*ScaleFactors_Pass->GetBinContent(i));
      QCD_Fail->SetBinContent(i,QCD_Fail->GetBinContent(i)*ScaleFactors_Fail->GetBinContent(i));
    }

  //Now we just subtract all of these things from the data and we should be left with our QCD distributions
  std::cout<<"Subtracting backgrounds..."<<std::endl;
  QCD_Pass->Add(DY_Pass, -1.0);
  QCD_Pass->Add(TTTo2L2Nu_Pass, -1.0);
  QCD_Pass->Add(TTToHadronic_Pass, -1.0);
  QCD_Pass->Add(TTToSemiLeptonic_Pass, -1.0);
  QCD_Pass->Add(WW_Pass, -1.0);
  QCD_Pass->Add(WZ_Pass, -1.0);
  QCD_Pass->Add(ZZ_Pass, -1.0);
  
  QCD_Fail->Add(DY_Fail, -1.0);
  QCD_Fail->Add(TTTo2L2Nu_Fail, -1.0);
  QCD_Fail->Add(TTToHadronic_Fail, -1.0);
  QCD_Fail->Add(TTToSemiLeptonic_Fail, -1.0);
  QCD_Fail->Add(WW_Fail, -1.0);
  QCD_Fail->Add(WZ_Fail, -1.0);
  QCD_Fail->Add(ZZ_Fail, -1.0);

  //we've subtracted off the backgrounds, now we just scale by 1.05
  // as mentioned in the AN to go from SS to OS regions.
  
  QCD_Pass->Scale(1.05);
  QCD_Fail->Scale(1.05);
  
  //now let's grab the Pass/Fail File and write all this stuff there.
  TFile* PassFailFile = new TFile("PassFailOut.root","UPDATE");
  TDirectory* PassFail_PassDir = (TDirectory *) PassFailFile->Get("PassRegion");
  TDirectory* PassFail_FailDir = (TDirectory *) PassFailFile->Get("FailRegion");

  PassFail_PassDir->cd();
  QCD_Pass->Write();
  
  PassFail_FailDir->cd();
  QCD_Fail->Write();
}
