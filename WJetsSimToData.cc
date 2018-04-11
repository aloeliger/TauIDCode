#include "TROOT.h"

void WJetsSimToData()
{
  TFile* WJetFile = new TFile("Distributions/WJetsDistributions.root","READ");
  TDirectory *WJet_PassDir = (TDirectory *) WJetFile->Get("pass");
  TDirectory* WJet_FailDir = (TDirectory *) WJetFile->Get("fail");
  
  //pass histos
  cout<<"Retrieving Pass Region Histograms"<<std::endl;
  TH1F* WJets_Pass = (TH1F *) WJet_PassDir->Get("WJets_Data_Pass");
  TH1F* DY_Pass = (TH1F *) WJet_PassDir->Get("WJets_DY_Pass");
  TH1F* TTTo2L2Nu_Pass = (TH1F *) WJet_PassDir->Get("WJets_TTTo2L2Nu_Pass");
  TH1F* TTToHadronic_Pass = (TH1F *) WJet_PassDir->Get("WJets_TTToHadronic_Pass");
  TH1F* TTToSemiLeptonic_Pass =  (TH1F *) WJet_PassDir->Get("WJets_TTToSemiLeptonic_Pass");
  TH1F* W_Pass = (TH1F *) WJet_PassDir->Get("WJets_W_Pass");
  TH1F* WW_Pass = (TH1F *) WJet_PassDir->Get("WJets_WW_Pass");
  TH1F* WZ_Pass = (TH1F *) WJet_PassDir->Get("WJets_WZ_Pass");
  TH1F* ZZ_Pass = (TH1F *) WJet_PassDir->Get("WJets_ZZ_Pass");
  TH1F* QCD_Pass = (TH1F *) WJet_PassDir->Get("CorrectedQCDContribution_Pass");
  
  //fail histos
  std::cout<<"Retrieving Fail Region Histograms"<<std::endl;
  TH1F* WJets_Fail = (TH1F *) WJet_FailDir->Get("WJets_Data_Fail");
  TH1F* DY_Fail = (TH1F *) WJet_FailDir->Get("WJets_DY_Pass");
  TH1F* TTTo2L2Nu_Fail = (TH1F *) WJet_FailDir->Get("WJets_TTTo2L2Nu_Fail");
  TH1F* TTToHadronic_Fail = (TH1F *) WJet_FailDir->Get("WJets_TTToHadronic_Fail");
  TH1F* TTToSemiLeptonic_Fail =  (TH1F *) WJet_FailDir->Get("WJets_TTToSemiLeptonic_Fail");
  TH1F* W_Fail = (TH1F *) WJet_FailDir->Get("WJets_W_Fail");
  TH1F* WW_Fail = (TH1F *) WJet_FailDir->Get("WJets_WW_Fail");
  TH1F* WZ_Fail = (TH1F *) WJet_FailDir->Get("WJets_WZ_Fail");
  TH1F* ZZ_Fail = (TH1F *) WJet_FailDir->Get("WJets_ZZ_Fail");
  TH1F* QCD_Fail = (TH1F *) WJet_FailDir->Get("CorrectedQCDContribution_Fail");

  //now we subtract off the contributions (except for the W+Jets distribution)
  std::cout<<"Subtracting backgrounds..."<<std::endl;
  std::cout<<"Pass Event totals beforehand "<<WJets_Pass->Integral()<<std::endl;
  //Currently doesn't seem to be any drell yan events?
  WJets_Pass->Add(DY_Pass, -1.0);
  WJets_Pass->Add(TTTo2L2Nu_Pass, -1.0);
  WJets_Pass->Add(TTToHadronic_Pass, -1.0);
  WJets_Pass->Add(TTToSemiLeptonic_Pass, -1.0);
  WJets_Pass->Add(WW_Pass, -1.0);
  WJets_Pass->Add(WZ_Pass, -1.0);
  WJets_Pass->Add(ZZ_Pass, -1.0);
  WJets_Pass->Add(QCD_Pass, -1.0);
  std::cout<<"Pass Event totals afterwards "<<WJets_Pass->Integral()<<std::endl;
  std::cout<<"Total Pass MC "<<W_Pass->Integral()<<std::endl;
  
  std::cout<<"Fail Event totals beforehand "<<WJets_Fail->Integral()<<std::endl;
  WJets_Fail->Add(DY_Fail, -1.0);
  WJets_Fail->Add(TTTo2L2Nu_Fail, -1.0);
  WJets_Fail->Add(TTToHadronic_Fail, -1.0);
  WJets_Fail->Add(TTToSemiLeptonic_Fail, -1.0);
  WJets_Fail->Add(WW_Fail, -1.0);
  WJets_Fail->Add(WZ_Fail, -1.0);
  WJets_Fail->Add(ZZ_Fail, -1.0);
  WJets_Fail->Add(QCD_Fail, -1.0);
  std::cout<<"Fail Event totals afterwards "<<WJets_Fail->Integral()<<std::endl;
  std::cout<<"Total Fail MC "<<W_Fail->Integral()<<std::endl;
  std::cout<<std::endl;
  
  std::cout<<"Writing Scale Factors..."<<std::endl;
  TFile* OutFile = new TFile("TemporaryFiles/CorrectedWJetsDistributions.root","RECREATE");
  
  WJets_Pass->SetName("CorrectedWJetsDistribution_Pass");
  WJets_Fail->SetName("CorrectedWJetsDistribution_Fail");
  
  //Let's now create a histogram where we divide the data bins by sim bins
  //so we get a scale factor that we can apply to the other sim data
  TH1F* ScaleFactors_Pass = new TH1F("ScaleFactors_Pass","ScaleFactors_Pass", WJets_Pass->GetSize()-2, WJets_Pass->GetXaxis()->GetXmin(), WJets_Pass->GetXaxis()->GetXmax());
  ScaleFactors_Pass->Divide(WJets_Pass,W_Pass);

  TH1F* ScaleFactors_Fail = new TH1F("ScaleFactors_Fail","ScaleFactors_Fail", WJets_Fail->GetSize()-2, WJets_Fail->GetXaxis()->GetXmin(), WJets_Fail->GetXaxis()->GetXmax());
  ScaleFactors_Fail->Divide(WJets_Fail,W_Fail);
  
  ScaleFactors_Pass->SetName("ScaleFactors_Pass");
  ScaleFactors_Pass->Write();
  
  ScaleFactors_Fail->SetName("ScaleFactors_Fail");
  ScaleFactors_Fail->Write();
  
  //try and reweight our extant w-jets distributions and rewrite them as
  //normalized to the distributions file.

  std::cout<<"Reweighting Low Transverse Mass W+Jets..."<<std::endl;
  TFile* PassFailFile = new TFile("Distributions/PassFailOut.root","UPDATE");
  std::cout<<"Grabbing Directories"<<std::endl;
  TDirectory* PassFail_PassDir = (TDirectory *) PassFailFile->Get("pass");
  TDirectory* PassFail_FailDir = (TDirectory *) PassFailFile->Get("fail");

  std::cout<<"Grabbing Histograms"<<std::endl;
  TH1F* PassFail_WJets_Pass = (TH1F *) PassFail_PassDir->Get("W_Pass");
  TH1F* PassFail_WJets_Fail = (TH1F *) PassFail_FailDir->Get("W_Fail");
  
  std::cout<<"Creating Newly Scaled Histos"<<std::endl;
  TH1F* Rescaled_WJets_Pass = new TH1F("Rescaled_WJets_Pass","Rescaled_WJets_Pass", PassFail_WJets_Pass->GetSize()-2, PassFail_WJets_Pass->GetXaxis()->GetXmin(), PassFail_WJets_Pass->GetXaxis()->GetXmax());
  TH1F* Rescaled_WJets_Fail = new TH1F("Rescaled_WJets_Fail","Rescaled_WJets_Fail", PassFail_WJets_Fail->GetSize()-2, PassFail_WJets_Fail->GetXaxis()->GetXmin(), PassFail_WJets_Fail->GetXaxis()->GetXmax());

  //std::cout<<"Filling Them"<<std::endl;
  for(int i =1; i <= PassFail_WJets_Pass->GetSize()-2; i++)
    {
      std::cout<<"Bin #"<<i<<std::endl;
      std::cout<<"Pass Scale Factor is: "<<ScaleFactors_Pass->GetBinContent(i)<<std::endl;
      std::cout<<"Fail Scale Factor is: "<<ScaleFactors_Fail->GetBinContent(i)<<std::endl;
      /*
      std::cout<<"PassFail_WJets_Pass content is: "<<PassFail_WJets_Pass->GetBinContent(i)<<std::endl;
      std::cout<<"PassFail_WJets_Pass content is: "<<PassFail_WJets_Fail->GetBinContent(i)<<std::endl;
      */
      Rescaled_WJets_Pass->SetBinContent(i,PassFail_WJets_Pass->GetBinContent(i)*ScaleFactors_Pass->GetBinContent(i));
      Rescaled_WJets_Fail->SetBinContent(i,PassFail_WJets_Fail->GetBinContent(i)*ScaleFactors_Fail->GetBinContent(i));
    }

  //Shove this back into the old file, and we'll roll with that.
  std::cout<<"Writing Newly Scaled Histos to the Pass/Fail File"<<std::endl;
  PassFail_PassDir->cd();
  Rescaled_WJets_Pass->Write();

  PassFail_FailDir->cd();
  Rescaled_WJets_Fail->Write();

  std::cout<<std::endl;
  std::cout<<"General pass scale factor would be: "<<(WJets_Pass->Integral()/W_Pass->Integral())<<std::endl;
  std::cout<<"General fail scale factor would be: "<<(WJets_Fail->Integral()/W_Fail->Integral())<<std::endl;
  std::cout<<"Most general possible scale factor would be: "<<(WJets_Pass->Integral() + WJets_Fail->Integral()) / (W_Pass->Integral() + W_Fail->Integral())<<std::endl;
}
