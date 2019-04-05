#include "TROOT.h"
#include <string>

TH1F* RemoveMCFromControls(std::string IsoWorkingPoint, std::string ControlVar)
{
  std::cout<<"Removing MC from control plot: "<<ControlVar<<std::endl;
  TFile* MCInJetsFile = new TFile("../Distributions/MCInJetsRegion.root");
  TFile* FakeRateDeterminedDistributions = new TFile("../Distributions/FakeRateDeterminedDistributions.root");
  //start grabbin histos
  std::cout<<"Retrieving Drell Yan..."<<std::endl;
  TH1F* DY_InJets = (TH1F*) MCInJetsFile->Get(("DY_"+IsoWorkingPoint+"_"+ControlVar).c_str());
  TH1F* DY1_InJets = (TH1F*) MCInJetsFile->Get(("DY1_"+IsoWorkingPoint+"_"+ControlVar).c_str());
  TH1F* DY2_InJets = (TH1F*) MCInJetsFile->Get(("DY2_"+IsoWorkingPoint+"_"+ControlVar).c_str());
  TH1F* DY3_InJets = (TH1F*) MCInJetsFile->Get(("DY3_"+IsoWorkingPoint+"_"+ControlVar).c_str());
  TH1F* DY4_InJets = (TH1F*) MCInJetsFile->Get(("DY4_"+IsoWorkingPoint+"_"+ControlVar).c_str());
  DY_InJets->Add(DY1_InJets);
  DY_InJets->Add(DY2_InJets);
  DY_InJets->Add(DY3_InJets);
  DY_InJets->Add(DY4_InJets);

  std::cout<<"Retrieving ttbar..."<<std::endl;
  TH1F* TTTo2L2Nu_InJets = (TH1F*) MCInJetsFile->Get(("TTTo2L2Nu_"+IsoWorkingPoint+"_"+ControlVar).c_str());
  TH1F* TTToHadronic_InJets = (TH1F*) MCInJetsFile->Get(("TTToHadronic_"+IsoWorkingPoint+"_"+ControlVar).c_str());
  TH1F* TTToSemiLeptonic_InJets = (TH1F*) MCInJetsFile->Get(("TTToSemiLeptonic_"+IsoWorkingPoint+"_"+ControlVar).c_str());
  
  TH1F* TT_InJets = (TH1F*) TTTo2L2Nu_InJets->Clone();
  TT_InJets->Add(TTToHadronic_InJets);
  TT_InJets->Add(TTToSemiLeptonic_InJets);

  std::cout<<"Retrieving Diboson..."<<std::endl;
  TH1F* WW_InJets = (TH1F*) MCInJetsFile->Get(("WW_"+IsoWorkingPoint+"_"+ControlVar).c_str());
  TH1F* WZ_InJets = (TH1F*) MCInJetsFile->Get(("WZ_"+IsoWorkingPoint+"_"+ControlVar).c_str());
  TH1F* ZZ_InJets = (TH1F*) MCInJetsFile->Get(("ZZ_"+IsoWorkingPoint+"_"+ControlVar).c_str());

  std::cout<<"Retrieving single top..."<<std::endl;
  TH1F* ST_top_InJets = (TH1F*) MCInJetsFile->Get(("ST_top_"+IsoWorkingPoint+"_"+ControlVar).c_str());
  TH1F* ST_antitop_InJets = (TH1F*) MCInJetsFile->Get(("ST_antitop_"+IsoWorkingPoint+"_"+ControlVar).c_str());
  TH1F* ST_tW_top_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_top_"+IsoWorkingPoint+"_"+ControlVar).c_str());
  TH1F* ST_tW_antitop_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_antitop_"+IsoWorkingPoint+"_"+ControlVar).c_str());
  
  TH1F* Diboson_InJets = (TH1F*) WW_InJets->Clone();
  Diboson_InJets->Add(WZ_InJets);
  Diboson_InJets->Add(ZZ_InJets);

  Diboson_InJets->Add(ST_top_InJets);
  Diboson_InJets->Add(ST_antitop_InJets);
  Diboson_InJets->Add(ST_tW_top_InJets);
  Diboson_InJets->Add(ST_tW_antitop_InJets);

  assert(IsoWorkingPoint == "VLoose" ||
	 IsoWorkingPoint == "Loose" ||
	 IsoWorkingPoint == "Medium" ||
	 IsoWorkingPoint == "Tight" ||
	 IsoWorkingPoint == "VTight" ||
	 IsoWorkingPoint == "VVTight");
  TH1F* JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get(("Jet_"+IsoWorkingPoint+"_"+ControlVar).c_str());  
  
  std::cout<<ControlVar+"\tJet\t Integral: "<<JetDistribution->Integral()<<std::endl;
  std::cout<<ControlVar+"\tJet\t Underflow: "<<JetDistribution->GetBinContent(0)<<std::endl;
  std::cout<<ControlVar+"\tJet\t Overflow: "<<JetDistribution->GetBinContent(JetDistribution->GetNbinsX()+1)<<std::endl;

  std::cout<<ControlVar+"\tDY\t Integral: "<<DY_InJets->Integral()<<std::endl;
  std::cout<<ControlVar+"\tDY\t Underflow: "<<DY_InJets->GetBinContent(0)<<std::endl;
  std::cout<<ControlVar+"\tDY\t Overflow: "<<DY_InJets->GetBinContent(DY_InJets->GetNbinsX()+1)<<std::endl;
  
  std::cout<<ControlVar+"\tTT\t Integral: "<<TT_InJets->Integral()<<std::endl;
  std::cout<<ControlVar+"\tTT\t Underflow: "<<TT_InJets->GetBinContent(0)<<std::endl;
  std::cout<<ControlVar+"\tTT\t Overflow: "<<TT_InJets->GetBinContent(TT_InJets->GetNbinsX()+1)<<std::endl;

  std::cout<<ControlVar+"\tDiboson\t Integral: "<<Diboson_InJets->Integral()<<std::endl;
  std::cout<<ControlVar+"\tDiboson\t Underflow: "<<Diboson_InJets->GetBinContent(0)<<std::endl;
  std::cout<<ControlVar+"\tDiboson\t Overflow: "<<Diboson_InJets->GetBinContent(Diboson_InJets->GetNbinsX()+1)<<std::endl;

  JetDistribution->Add(DY_InJets,-1.0);
  JetDistribution->Add(TT_InJets,-1.0);
  JetDistribution->Add(Diboson_InJets,-1.0);
  
  std::cout<<ControlVar+"\tJetFinal\t Integral: "<<JetDistribution->Integral()<<std::endl;
  std::cout<<ControlVar+"\tJetFinal\t Underflow: "<<JetDistribution->GetBinContent(0)<<std::endl;
  std::cout<<ControlVar+"\tJetFinal\t Overflow: "<<JetDistribution->GetBinContent(JetDistribution->GetNbinsX()+1)<<std::endl;

  return JetDistribution;
}


void RemoveMCFromJets(std::string IsoWorkingPoint)
{
  //this script needs to be changed to start handling the new shapes present

  TFile* MCInJetsFile = new TFile("../Distributions/MCInJetsRegion.root");
  TFile* FakeRateDeterminedDistributions = new TFile("../Distributions/FakeRateDeterminedDistributions.root");
  //start grabbin histos
  std::cout<<"Retrieving Drell Yan..."<<std::endl;
  TH1F* DY_InJets = (TH1F*) MCInJetsFile->Get(("DY_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY1_InJets = (TH1F*) MCInJetsFile->Get(("DY1_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY2_InJets = (TH1F*) MCInJetsFile->Get(("DY2_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY3_InJets = (TH1F*) MCInJetsFile->Get(("DY3_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY4_InJets = (TH1F*) MCInJetsFile->Get(("DY4_"+IsoWorkingPoint+"_JetRegion").c_str());
  DY_InJets->Add(DY1_InJets);
  DY_InJets->Add(DY2_InJets);
  DY_InJets->Add(DY3_InJets);
  DY_InJets->Add(DY4_InJets);

  std::cout<<"Up, Decay Mode 0 ..."<<std::endl;
  TH1F* DY_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY1_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY1_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY2_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY2_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY3_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY3_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY4_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY4_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  DY_DecayMode0_UP_InJets->Add(DY1_DecayMode0_UP_InJets);
  DY_DecayMode0_UP_InJets->Add(DY2_DecayMode0_UP_InJets);
  DY_DecayMode0_UP_InJets->Add(DY3_DecayMode0_UP_InJets);
  DY_DecayMode0_UP_InJets->Add(DY4_DecayMode0_UP_InJets);

  std::cout<<"Up, Decay Mode 1 ..."<<std::endl;
  TH1F* DY_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY1_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY1_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY2_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY2_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY3_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY3_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY4_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY4_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  DY_DecayMode1_UP_InJets->Add(DY1_DecayMode1_UP_InJets);
  DY_DecayMode1_UP_InJets->Add(DY2_DecayMode1_UP_InJets);
  DY_DecayMode1_UP_InJets->Add(DY3_DecayMode1_UP_InJets);
  DY_DecayMode1_UP_InJets->Add(DY4_DecayMode1_UP_InJets);

  std::cout<<"Up, Decay Mode 10 ..."<<std::endl;
  TH1F* DY_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY1_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY1_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY2_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY2_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY3_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY3_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY4_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("DY4_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  DY_DecayMode10_UP_InJets->Add(DY1_DecayMode10_UP_InJets);
  DY_DecayMode10_UP_InJets->Add(DY2_DecayMode10_UP_InJets);
  DY_DecayMode10_UP_InJets->Add(DY3_DecayMode10_UP_InJets);
  DY_DecayMode10_UP_InJets->Add(DY4_DecayMode10_UP_InJets);

  std::cout<<"Down, Decay Mode 0 ..."<<std::endl;
  TH1F* DY_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY1_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY1_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY2_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY2_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY3_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY3_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY4_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY4_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  DY_DecayMode0_DOWN_InJets->Add(DY1_DecayMode0_DOWN_InJets);
  DY_DecayMode0_DOWN_InJets->Add(DY2_DecayMode0_DOWN_InJets);
  DY_DecayMode0_DOWN_InJets->Add(DY3_DecayMode0_DOWN_InJets);
  DY_DecayMode0_DOWN_InJets->Add(DY4_DecayMode0_DOWN_InJets);

  std::cout<<"Down, Decay Mode 1 ..."<<std::endl;
  TH1F* DY_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY1_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY1_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY2_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY2_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY3_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY3_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY4_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY4_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  DY_DecayMode1_DOWN_InJets->Add(DY1_DecayMode1_DOWN_InJets);
  DY_DecayMode1_DOWN_InJets->Add(DY2_DecayMode1_DOWN_InJets);
  DY_DecayMode1_DOWN_InJets->Add(DY3_DecayMode1_DOWN_InJets);
  DY_DecayMode1_DOWN_InJets->Add(DY4_DecayMode1_DOWN_InJets);

  std::cout<<"Down, Decay Mode 10 ..."<<std::endl;
  TH1F* DY_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY1_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY1_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY2_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY2_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY3_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY3_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* DY4_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("DY4_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  DY_DecayMode10_DOWN_InJets->Add(DY1_DecayMode10_DOWN_InJets);
  DY_DecayMode10_DOWN_InJets->Add(DY2_DecayMode10_DOWN_InJets);
  DY_DecayMode10_DOWN_InJets->Add(DY3_DecayMode10_DOWN_InJets);
  DY_DecayMode10_DOWN_InJets->Add(DY4_DecayMode10_DOWN_InJets);

  std::cout<<"Retrieving ttbar..."<<std::endl;
  TH1F* TTTo2L2Nu_InJets = (TH1F*) MCInJetsFile->Get(("TTTo2L2Nu_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToHadronic_InJets = (TH1F*) MCInJetsFile->Get(("TTToHadronic_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToSemiLeptonic_InJets = (TH1F*) MCInJetsFile->Get(("TTToSemiLeptonic_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* TT_InJets = (TH1F*) TTTo2L2Nu_InJets->Clone();
  TT_InJets->Add(TTToHadronic_InJets);
  TT_InJets->Add(TTToSemiLeptonic_InJets);
  
  std::cout<<"Up, Decay Mode 0..."<<std::endl;
  TH1F* TTTo2L2Nu_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("TTTo2L2Nu_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToHadronic_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("TTToHadronic_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToSemiLeptonic_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("TTToSemiLeptonic_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* TT_DecayMode0_UP_InJets = (TH1F*) TTTo2L2Nu_DecayMode0_UP_InJets->Clone();
  TT_DecayMode0_UP_InJets->Add(TTToHadronic_DecayMode0_UP_InJets);
  TT_DecayMode0_UP_InJets->Add(TTToSemiLeptonic_DecayMode0_UP_InJets);

  std::cout<<"Up, Decay Mode 1..."<<std::endl;
  TH1F* TTTo2L2Nu_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("TTTo2L2Nu_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToHadronic_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("TTToHadronic_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToSemiLeptonic_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("TTToSemiLeptonic_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* TT_DecayMode1_UP_InJets = (TH1F*) TTTo2L2Nu_DecayMode1_UP_InJets->Clone();
  TT_DecayMode1_UP_InJets->Add(TTToHadronic_DecayMode1_UP_InJets);
  TT_DecayMode1_UP_InJets->Add(TTToSemiLeptonic_DecayMode1_UP_InJets);

  std::cout<<"Up, Decay Mode 10..."<<std::endl;
  TH1F* TTTo2L2Nu_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("TTTo2L2Nu_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToHadronic_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("TTToHadronic_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToSemiLeptonic_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("TTToSemiLeptonic_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* TT_DecayMode10_UP_InJets = (TH1F*) TTTo2L2Nu_DecayMode10_UP_InJets->Clone();
  TT_DecayMode10_UP_InJets->Add(TTToHadronic_DecayMode10_UP_InJets);
  TT_DecayMode10_UP_InJets->Add(TTToSemiLeptonic_DecayMode10_UP_InJets);

  std::cout<<"Down, Decay Mode 0..."<<std::endl;
  TH1F* TTTo2L2Nu_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("TTTo2L2Nu_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToHadronic_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("TTToHadronic_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToSemiLeptonic_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("TTToSemiLeptonic_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* TT_DecayMode0_DOWN_InJets = (TH1F*) TTTo2L2Nu_DecayMode0_DOWN_InJets->Clone();
  TT_DecayMode0_DOWN_InJets->Add(TTToHadronic_DecayMode0_DOWN_InJets);
  TT_DecayMode0_DOWN_InJets->Add(TTToSemiLeptonic_DecayMode0_DOWN_InJets);

  std::cout<<"Down, Decay Mode 1..."<<std::endl;
  TH1F* TTTo2L2Nu_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("TTTo2L2Nu_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToHadronic_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("TTToHadronic_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToSemiLeptonic_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("TTToSemiLeptonic_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* TT_DecayMode1_DOWN_InJets = (TH1F*) TTTo2L2Nu_DecayMode1_DOWN_InJets->Clone();
  TT_DecayMode1_DOWN_InJets->Add(TTToHadronic_DecayMode1_DOWN_InJets);
  TT_DecayMode1_DOWN_InJets->Add(TTToSemiLeptonic_DecayMode1_DOWN_InJets);

  std::cout<<"Down, Decay Mode 10..."<<std::endl;
  TH1F* TTTo2L2Nu_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("TTTo2L2Nu_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToHadronic_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("TTToHadronic_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* TTToSemiLeptonic_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("TTToSemiLeptonic_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* TT_DecayMode10_DOWN_InJets = (TH1F*) TTTo2L2Nu_DecayMode10_DOWN_InJets->Clone();
  TT_DecayMode10_DOWN_InJets->Add(TTToHadronic_DecayMode10_DOWN_InJets);
  TT_DecayMode10_DOWN_InJets->Add(TTToSemiLeptonic_DecayMode10_DOWN_InJets);

  std::cout<<"Retrieving Diboson + ST..."<<std::endl;
  TH1F* WW_InJets = (TH1F*) MCInJetsFile->Get(("WW_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* WZ_InJets = (TH1F*) MCInJetsFile->Get(("WZ_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ZZ_InJets = (TH1F*) MCInJetsFile->Get(("ZZ_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* ST_top_InJets = (TH1F*) MCInJetsFile->Get(("ST_top_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_antitop_InJets = (TH1F*) MCInJetsFile->Get(("ST_antitop_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_tW_top_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_top_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_tW_antitop_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_antitop_"+IsoWorkingPoint+"_JetRegion").c_str());
 
  TH1F* Diboson_InJets = (TH1F*) WW_InJets->Clone();
  Diboson_InJets->Add(WZ_InJets);
  Diboson_InJets->Add(ZZ_InJets);

  Diboson_InJets->Add(ST_top_InJets);
  Diboson_InJets->Add(ST_antitop_InJets);
  Diboson_InJets->Add(ST_tW_top_InJets);
  Diboson_InJets->Add(ST_tW_antitop_InJets);

  std::cout<<"Up, Decay Mode 0..."<<std::endl;
  TH1F* WW_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("WW_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* WZ_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("WZ_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ZZ_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("ZZ_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());

  TH1F* ST_top_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("ST_top_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_antitop_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("ST_antitop_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_tW_top_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_top_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_tW_antitop_DecayMode0_UP_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_antitop_DecayMode0_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* Diboson_DecayMode0_UP_InJets = (TH1F*) WW_DecayMode0_UP_InJets->Clone();
  Diboson_DecayMode0_UP_InJets->Add(WZ_DecayMode0_UP_InJets);
  Diboson_DecayMode0_UP_InJets->Add(ZZ_DecayMode0_UP_InJets);

  Diboson_DecayMode0_UP_InJets->Add(ST_top_DecayMode0_UP_InJets);
  Diboson_DecayMode0_UP_InJets->Add(ST_antitop_DecayMode0_UP_InJets);
  Diboson_DecayMode0_UP_InJets->Add(ST_tW_top_DecayMode0_UP_InJets);
  Diboson_DecayMode0_UP_InJets->Add(ST_tW_antitop_DecayMode0_UP_InJets);

  std::cout<<"Up, Decay Mode 1..."<<std::endl;
  TH1F* WW_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("WW_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* WZ_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("WZ_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ZZ_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("ZZ_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* ST_top_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("ST_top_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_antitop_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("ST_antitop_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_tW_top_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_top_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_tW_antitop_DecayMode1_UP_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_antitop_DecayMode1_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* Diboson_DecayMode1_UP_InJets = (TH1F*) WW_DecayMode1_UP_InJets->Clone();
  Diboson_DecayMode1_UP_InJets->Add(WZ_DecayMode1_UP_InJets);
  Diboson_DecayMode1_UP_InJets->Add(ZZ_DecayMode1_UP_InJets);

  Diboson_DecayMode1_UP_InJets->Add(ST_top_DecayMode1_UP_InJets);
  Diboson_DecayMode1_UP_InJets->Add(ST_antitop_DecayMode1_UP_InJets);
  Diboson_DecayMode1_UP_InJets->Add(ST_tW_top_DecayMode1_UP_InJets);
  Diboson_DecayMode1_UP_InJets->Add(ST_tW_antitop_DecayMode1_UP_InJets);

  std::cout<<"Up, Decay Mode 10..."<<std::endl;
  TH1F* WW_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("WW_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* WZ_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("WZ_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ZZ_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("ZZ_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* ST_top_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("ST_top_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_antitop_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("ST_antitop_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_tW_top_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_top_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_tW_antitop_DecayMode10_UP_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_antitop_DecayMode10_UP_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* Diboson_DecayMode10_UP_InJets = (TH1F*) WW_DecayMode10_UP_InJets->Clone();
  Diboson_DecayMode10_UP_InJets->Add(WZ_DecayMode10_UP_InJets);
  Diboson_DecayMode10_UP_InJets->Add(ZZ_DecayMode10_UP_InJets);

  Diboson_DecayMode10_UP_InJets->Add(ST_top_DecayMode10_UP_InJets);
  Diboson_DecayMode10_UP_InJets->Add(ST_antitop_DecayMode10_UP_InJets);
  Diboson_DecayMode10_UP_InJets->Add(ST_tW_top_DecayMode10_UP_InJets);
  Diboson_DecayMode10_UP_InJets->Add(ST_tW_antitop_DecayMode10_UP_InJets);

  std::cout<<"Down, Decay Mode 0..."<<std::endl;
  TH1F* WW_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("WW_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* WZ_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("WZ_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ZZ_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ZZ_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* ST_top_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ST_top_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_antitop_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ST_antitop_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_tW_top_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_top_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_tW_antitop_DecayMode0_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_antitop_DecayMode0_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* Diboson_DecayMode0_DOWN_InJets = (TH1F*) WW_DecayMode0_DOWN_InJets->Clone();
  Diboson_DecayMode0_DOWN_InJets->Add(WZ_DecayMode0_DOWN_InJets);
  Diboson_DecayMode0_DOWN_InJets->Add(ZZ_DecayMode0_DOWN_InJets);

  Diboson_DecayMode0_DOWN_InJets->Add(ST_top_DecayMode0_DOWN_InJets);
  Diboson_DecayMode0_DOWN_InJets->Add(ST_antitop_DecayMode0_DOWN_InJets);
  Diboson_DecayMode0_DOWN_InJets->Add(ST_tW_top_DecayMode0_DOWN_InJets);
  Diboson_DecayMode0_DOWN_InJets->Add(ST_tW_antitop_DecayMode0_DOWN_InJets);

  std::cout<<"Down, Decay Mode 1..."<<std::endl;
  TH1F* WW_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("WW_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* WZ_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("WZ_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ZZ_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ZZ_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* ST_top_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ST_top_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_antitop_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ST_antitop_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_tW_top_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_top_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_tW_antitop_DecayMode1_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_antitop_DecayMode1_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* Diboson_DecayMode1_DOWN_InJets = (TH1F*) WW_DecayMode1_DOWN_InJets->Clone();
  Diboson_DecayMode1_DOWN_InJets->Add(WZ_DecayMode1_DOWN_InJets);
  Diboson_DecayMode1_DOWN_InJets->Add(ZZ_DecayMode1_DOWN_InJets);

  Diboson_DecayMode1_DOWN_InJets->Add(ST_top_DecayMode1_DOWN_InJets);
  Diboson_DecayMode1_DOWN_InJets->Add(ST_antitop_DecayMode1_DOWN_InJets);
  Diboson_DecayMode1_DOWN_InJets->Add(ST_tW_top_DecayMode1_DOWN_InJets);
  Diboson_DecayMode1_DOWN_InJets->Add(ST_tW_antitop_DecayMode1_DOWN_InJets);

  std::cout<<"Down, Decay Mode 10..."<<std::endl;
  TH1F* WW_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("WW_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* WZ_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("WZ_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ZZ_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ZZ_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* ST_top_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ST_top_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_antitop_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ST_antitop_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_tW_top_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_top_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  TH1F* ST_tW_antitop_DecayMode10_DOWN_InJets = (TH1F*) MCInJetsFile->Get(("ST_tW_antitop_DecayMode10_DOWN_"+IsoWorkingPoint+"_JetRegion").c_str());
  
  TH1F* Diboson_DecayMode10_DOWN_InJets = (TH1F*) WW_DecayMode10_DOWN_InJets->Clone();
  Diboson_DecayMode10_DOWN_InJets->Add(WZ_DecayMode10_DOWN_InJets);
  Diboson_DecayMode10_DOWN_InJets->Add(ZZ_DecayMode10_DOWN_InJets);

  Diboson_DecayMode10_DOWN_InJets->Add(ST_top_DecayMode10_DOWN_InJets);
  Diboson_DecayMode10_DOWN_InJets->Add(ST_antitop_DecayMode10_DOWN_InJets);
  Diboson_DecayMode10_DOWN_InJets->Add(ST_tW_top_DecayMode10_DOWN_InJets);
  Diboson_DecayMode10_DOWN_InJets->Add(ST_tW_antitop_DecayMode10_DOWN_InJets);
  
  TH1F* JetDistribution; 
  TH1F* JetDistribution_DecayMode0_DOWN;
  TH1F* JetDistribution_DecayMode0_UP;
  TH1F* JetDistribution_DecayMode1_DOWN;
  TH1F* JetDistribution_DecayMode1_UP;
  TH1F* JetDistribution_DecayMode10_DOWN;
  TH1F* JetDistribution_DecayMode10_UP;  
  assert(IsoWorkingPoint == "VLoose" ||
	 IsoWorkingPoint == "Loose" ||
	 IsoWorkingPoint == "Medium" ||
	 IsoWorkingPoint == "Tight" ||
	 IsoWorkingPoint == "VTight" ||
	 IsoWorkingPoint == "VVTight");
  if(IsoWorkingPoint == "VLoose")
    {	
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("VLoosePTFRJetDistribution");
      JetDistribution_DecayMode0_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VLooseDecayMode0LowJetDistribution");
      JetDistribution_DecayMode0_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VLooseDecayMode0HighJetDistribution");
      JetDistribution_DecayMode1_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VLooseDecayMode1LowJetDistribution");
      JetDistribution_DecayMode1_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VLooseDecayMode1HighJetDistribution");
      JetDistribution_DecayMode10_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VLooseDecayMode10LowJetDistribution");
      JetDistribution_DecayMode10_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VLooseDecayMode10HighJetDistribution");
    }
  else if(IsoWorkingPoint == "Loose")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("LoosePTFRJetDistribution");
      JetDistribution_DecayMode0_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("LooseDecayMode0LowJetDistribution");
      JetDistribution_DecayMode0_UP = (TH1F*) FakeRateDeterminedDistributions->Get("LooseDecayMode0HighJetDistribution");
      JetDistribution_DecayMode1_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("LooseDecayMode1LowJetDistribution");
      JetDistribution_DecayMode1_UP = (TH1F*) FakeRateDeterminedDistributions->Get("LooseDecayMode1HighJetDistribution");
      JetDistribution_DecayMode10_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("LooseDecayMode10LowJetDistribution");
      JetDistribution_DecayMode10_UP = (TH1F*) FakeRateDeterminedDistributions->Get("LooseDecayMode10HighJetDistribution");
    }
  else if(IsoWorkingPoint == "Medium")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("MediumPTFRJetDistribution");
      JetDistribution_DecayMode0_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("MediumDecayMode0LowJetDistribution");
      JetDistribution_DecayMode0_UP = (TH1F*) FakeRateDeterminedDistributions->Get("MediumDecayMode0HighJetDistribution");
      JetDistribution_DecayMode1_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("MediumDecayMode1LowJetDistribution");
      JetDistribution_DecayMode1_UP = (TH1F*) FakeRateDeterminedDistributions->Get("MediumDecayMode1HighJetDistribution");
      JetDistribution_DecayMode10_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("MediumDecayMode10LowJetDistribution");
      JetDistribution_DecayMode10_UP = (TH1F*) FakeRateDeterminedDistributions->Get("MediumDecayMode10HighJetDistribution");
    }
  else if(IsoWorkingPoint == "Tight")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("TightPTFRJetDistribution");
      JetDistribution_DecayMode0_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("TightDecayMode0LowJetDistribution");
      JetDistribution_DecayMode0_UP = (TH1F*) FakeRateDeterminedDistributions->Get("TightDecayMode0HighJetDistribution");
      JetDistribution_DecayMode1_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("TightDecayMode1LowJetDistribution");
      JetDistribution_DecayMode1_UP = (TH1F*) FakeRateDeterminedDistributions->Get("TightDecayMode1HighJetDistribution");
      JetDistribution_DecayMode10_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("TightDecayMode10LowJetDistribution");
      JetDistribution_DecayMode10_UP = (TH1F*) FakeRateDeterminedDistributions->Get("TightDecayMode10HighJetDistribution");
    }
  else if(IsoWorkingPoint == "VTight")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("VTightPTFRJetDistribution");
      JetDistribution_DecayMode0_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VTightDecayMode0LowJetDistribution");
      JetDistribution_DecayMode0_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VTightDecayMode0HighJetDistribution");
      JetDistribution_DecayMode1_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VTightDecayMode1LowJetDistribution");
      JetDistribution_DecayMode1_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VTightDecayMode1HighJetDistribution");
      JetDistribution_DecayMode10_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VTightDecayMode10LowJetDistribution");
      JetDistribution_DecayMode10_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VTightDecayMode10HighJetDistribution");
    }
  else if(IsoWorkingPoint == "VVTight")
    {
      JetDistribution = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightPTFRJetDistribution");
      JetDistribution_DecayMode0_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightDecayMode0LowJetDistribution");
      JetDistribution_DecayMode0_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightDecayMode0HighJetDistribution");
      JetDistribution_DecayMode1_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightDecayMode1LowJetDistribution");
      JetDistribution_DecayMode1_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightDecayMode1HighJetDistribution");
      JetDistribution_DecayMode10_DOWN = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightDecayMode10LowJetDistribution");
      JetDistribution_DecayMode10_UP = (TH1F*) FakeRateDeterminedDistributions->Get("VVTightDecayMode10HighJetDistribution");
    }

  JetDistribution->Add(DY_InJets,-1.0);
  JetDistribution->Add(TT_InJets,-1.0);
  JetDistribution->Add(Diboson_InJets,-1.0);

  JetDistribution_DecayMode0_UP->Add(DY_DecayMode0_UP_InJets,-1.0);
  JetDistribution_DecayMode0_UP->Add(TT_DecayMode0_UP_InJets,-1.0);
  JetDistribution_DecayMode0_UP->Add(Diboson_DecayMode0_UP_InJets,-1.0);

  JetDistribution_DecayMode1_UP->Add(DY_DecayMode1_UP_InJets,-1.0);
  JetDistribution_DecayMode1_UP->Add(TT_DecayMode1_UP_InJets,-1.0);
  JetDistribution_DecayMode1_UP->Add(Diboson_DecayMode1_UP_InJets,-1.0);

  JetDistribution_DecayMode10_UP->Add(DY_DecayMode10_UP_InJets,-1.0);
  JetDistribution_DecayMode10_UP->Add(TT_DecayMode10_UP_InJets,-1.0);
  JetDistribution_DecayMode10_UP->Add(Diboson_DecayMode10_UP_InJets,-1.0);

  JetDistribution_DecayMode0_DOWN->Add(DY_DecayMode0_DOWN_InJets,-1.0);
  JetDistribution_DecayMode0_DOWN->Add(TT_DecayMode0_DOWN_InJets,-1.0);
  JetDistribution_DecayMode0_DOWN->Add(Diboson_DecayMode0_DOWN_InJets,-1.0);

  JetDistribution_DecayMode1_DOWN->Add(DY_DecayMode1_DOWN_InJets,-1.0);
  JetDistribution_DecayMode1_DOWN->Add(TT_DecayMode1_DOWN_InJets,-1.0);
  JetDistribution_DecayMode1_DOWN->Add(Diboson_DecayMode1_DOWN_InJets,-1.0);

  JetDistribution_DecayMode10_DOWN->Add(DY_DecayMode10_DOWN_InJets,-1.0);
  JetDistribution_DecayMode10_DOWN->Add(TT_DecayMode10_DOWN_InJets,-1.0);
  JetDistribution_DecayMode10_DOWN->Add(Diboson_DecayMode10_DOWN_InJets,-1.0);

  //Create and get the Control plot jet distributions
  TH1F* JetDistribution_MuPt;
  TH1F* JetDistribution_TauPt;
  TH1F* JetDistribution_MuEta;
  TH1F* JetDistribution_TauEta;
  TH1F* JetDistribution_NJets;
  TH1F* JetDistribution_NBTag;
  TH1F* JetDistribution_ZMass;
  TH1F* JetDistribution_ZPT;
  TH1F* JetDistribution_MT;
  TH1F* JetDistribution_MT_WPlus;
  TH1F* JetDistribution_MT_WMinus;

  JetDistribution_MuPt = RemoveMCFromControls(IsoWorkingPoint, "MuPt");  
  JetDistribution_TauPt = RemoveMCFromControls( IsoWorkingPoint, "TauPt");  
  JetDistribution_MuEta = RemoveMCFromControls(IsoWorkingPoint, "MuEta");
  JetDistribution_TauEta = RemoveMCFromControls(IsoWorkingPoint, "TauEta");
  JetDistribution_NJets = RemoveMCFromControls(IsoWorkingPoint, "njets");
  JetDistribution_NBTag = RemoveMCFromControls(IsoWorkingPoint, "nbtag");
  JetDistribution_ZMass = RemoveMCFromControls(IsoWorkingPoint, "ZMass");
  JetDistribution_ZPT = RemoveMCFromControls(IsoWorkingPoint, "ZPT");
  JetDistribution_MT = RemoveMCFromControls(IsoWorkingPoint, "MT");
  JetDistribution_MT_WPlus = RemoveMCFromControls(IsoWorkingPoint,"MT_WPlus");
  JetDistribution_MT_WMinus = RemoveMCFromControls(IsoWorkingPoint,"MT_WMinus");

  TFile* CorrectedFakeRateDeterminedDistributions = new TFile("../Distributions/CorrectedFakeRateDeterminedDistributions.root","RECREATE");
  JetDistribution->Write();
  JetDistribution_DecayMode0_UP->Write();
  JetDistribution_DecayMode0_DOWN->Write();
  JetDistribution_DecayMode1_UP->Write();
  JetDistribution_DecayMode1_DOWN->Write();
  JetDistribution_DecayMode10_UP->Write();
  JetDistribution_DecayMode10_DOWN->Write();

  JetDistribution_MuPt->Write();
  JetDistribution_TauPt->Write();
  JetDistribution_MuEta->Write();
  JetDistribution_TauEta->Write();
  JetDistribution_NJets->Write();
  JetDistribution_NBTag->Write();
  JetDistribution_ZMass->Write();
  JetDistribution_ZPT->Write();
  JetDistribution_MT->Write();  
  JetDistribution_MT_WPlus->Write();
  JetDistribution_MT_WMinus->Write();
}
