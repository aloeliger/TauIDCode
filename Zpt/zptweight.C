/*
 * @short: provide Z pt weights at drawing level
 *         root file from Cecile
 * @author: Izaak Neutelings (June 2018)
 *
 */

#include "TROOT.h"
#include "TFile.h"
#include "TH2.h"
#include "TH2F.h"
#include <iostream>
#include <algorithm>
using namespace std;

TString filenameZb   = "Zpt_weights_2016_btag.root";
TString filenameHTT  = "Zpt_weights_2016_BtoH.root";
TString filename2017 = "~/private/TauIDCode/Zpt/Zpt_weights_2017_Izaak.root";
TH2F* histZb;
TH2F* histHTT;
TH2F* histIWN;


void readZptFile(){  
  /*
  std::cout << ">>> opening " << filenameZb << std::endl;
  TFile *file = new TFile(filenameZb);
  histZb = (TH2F*) file->Get("zptmass_histo");
  histZb->SetDirectory(0);
  file->Close();
  
  std::cout << ">>> opening " << filenameHTT << std::endl;
  TFile *fileHTT = new TFile(filenameHTT);
  histHTT = (TH2F*) fileHTT->Get("zptmass_histo");
  histHTT->SetDirectory(0);
  fileHTT->Close();
  */
  std::cout << ">>> opening " << filename2017 << std::endl;
  TFile *fileIWN = new TFile(filename2017);
  histIWN = (TH2F*) fileIWN->Get("zptmass_weights");
  histIWN->SetDirectory(0);
  fileIWN->Close();
  
}


Float_t getZpt(Float_t pt_genboson){
  return histZb->GetBinContent(histZb->GetXaxis()->FindBin(90.),histZb->GetYaxis()->FindBin(pt_genboson));
}


Float_t getZpt_HTT(Float_t m_genboson, Float_t pt_genboson){
  return histHTT->GetBinContent(histHTT->GetXaxis()->FindBin(m_genboson),histHTT->GetYaxis()->FindBin(pt_genboson));
}


Float_t getZpt_2017(Float_t m_genboson, Float_t pt_genboson){
  //Int_t xbin = histIWN->GetXaxis()->FindBin(m_genboson);
  //Int_t ybin = histIWN->GetYaxis()->FindBin(pt_genboson);
  //while(xbin<1) xbin++; while(xbin>histIWN->GetXaxis()->GetNbins()) xbin--;
  //while(ybin<1) ybin++; while(ybin>histIWN->GetYaxis()->GetNbins()) ybin--;
  //return histIWN->GetBinContent(xbin,ybin);
  return histIWN->GetBinContent(histIWN->GetXaxis()->FindBin(m_genboson),histIWN->GetYaxis()->FindBin(pt_genboson));
}

Float_t getZpt_2017Down(Float_t m_genboson, Float_t pt_genboson, Float_t shift=0.90){
  return 1.+shift*(getZpt_2017(m_genboson,pt_genboson)-1.);
}

Float_t getZpt_2017Up(Float_t m_genboson, Float_t pt_genboson, Float_t shift=1.10){
  return 1.+shift*(getZpt_2017(m_genboson,pt_genboson)-1.);
}


void zptweight(){
  std::cout << ">>> initializing zptweights.C ... " << std::endl;
  readZptFile();
}

