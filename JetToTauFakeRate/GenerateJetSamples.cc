#include "TROOT.h"

//Mirrors the entry across the midpoint of the axis
float GenerateFlippedJetDistribution(float LowBinEdge, float HighBinEdge, float Entry)
{
  return HighBinEdge+LowBinEdge-Entry;
}

//generates a pt based fake rate with twice the discrepancy from the flat fake rate
float GenerateExacerbatedFakeRate(float NominalFakeRate, float FlatFakeRate)
{
  return 2.0*NominalFakeRate-FlatFakeRate;
}

float GenerateExacerbatedWeighting(float NominalWeight, float FlatWeight)
{
  return 2.0*NominalWeight-FlatWeight;
}

void GenerateJetSamples()
{
  TFile *MyFile = new TFile("/data/ccaillol/tauid_20june_mt/Data.root");
  TTree *Tree = (TTree*) MyFile->Get("mutau_tree");
  
  int run,lumi,evt,NUP;
  float npv,npu,amcatNLO_weight;
  float pt_1,phi_1,eta_1,m_1,e_1,q_1,d0_1,dZ_1,iso_1,id_m_medium_1,id_m_tight_1;
  float pt_2,phi_2,eta_2,m_2,e_2,q_2,d0_2,dZ_2,iso_2,l2_decayMode;
  float againstElectronLooseMVA6_2,againstElectronMediumMVA6_2,againstElectronTightMVA6_2,againstElectronVLooseMVA6_2,againstElectronVTightMVA6_2;
  float againstMuonLoose3_2,againstMuonTight3_2;
  //tau iso stuff
  float byLooseCombinedIsolationDeltaBetaCorr3Hits_2,byMediumCombinedIsolationDeltaBetaCorr3Hits_2,byTightCombinedIsolationDeltaBetaCorr3Hits_2,byCombinedIsolationDeltaBetaCorrRaw3Hits_2;
  float byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_2,byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_2,byTightCombinedIsolationDeltaBetaCorr3HitsdR03_2;
  float byVLooseIsolationMVArun2v1DBnewDMwLT_2,byVLooseIsolationMVArun2v1DBoldDMwLT_2,byVLooseIsolationMVArun2v1DBdR03oldDMwLT_2;
  float byLooseIsolationMVArun2v1DBnewDMwLT_2,byLooseIsolationMVArun2v1DBoldDMwLT_2,byLooseIsolationMVArun2v1DBdR03oldDMwLT_2;
  float byMediumIsolationMVArun2v1DBnewDMwLT_2,byMediumIsolationMVArun2v1DBoldDMwLT_2,byMediumIsolationMVArun2v1DBdR03oldDMwLT_2;
  float byTightIsolationMVArun2v1DBnewDMwLT_2,byTightIsolationMVArun2v1DBoldDMwLT_2,byTightIsolationMVArun2v1DBdR03oldDMwLT_2;
  float byVTightIsolationMVArun2v1DBnewDMwLT_2,byVTightIsolationMVArun2v1DBoldDMwLT_2,byVTightIsolationMVArun2v1DBdR03oldDMwLT_2;
  float byVVTightIsolationMVArun2v1DBnewDMwLT_2,byVVTightIsolationMVArun2v1DBoldDMwLT_2,byVVTightIsolationMVArun2v1DBdR03oldDMwLT_2;
  float byIsolationMVA3oldDMwoLTraw_2,byIsolationMVA3oldDMwLTraw_2,byIsolationMVA3newDMwoLTraw_2,byIsolationMVA3newDMwLTraw_2;
  float byVLooseIsolationRerunMVArun2v1DBoldDMwLT_2,byLooseIsolationRerunMVArun2v1DBoldDMwLT_2,byMediumIsolationRerunMVArun2v1DBoldDMwLT_2,byTightIsolationRerunMVArun2v1DBoldDMwLT_2,byVTightIsolationRerunMVArun2v1DBoldDMwLT_2,byVVTightIsolationRerunMVArun2v1DBoldDMwLT_2;
  float byIsolationRerunMVA3oldDMwLTraw_2;

  float byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2,byLooseIsolationRerunMVArun2v2DBoldDMwLT_2,byMediumIsolationRerunMVArun2v2DBoldDMwLT_2,byTightIsolationRerunMVArun2v2DBoldDMwLT_2,byVTightIsolationRerunMVArun2v2DBoldDMwLT_2,byVVTightIsolationRerunMVArun2v2DBoldDMwLT_2,byIsolationRerunMVA3oldDMwLTrawv2_2;

  float chargedIsoPtSum_2,decayModeFinding_2,decayModeFindingNewDMs_2,neutralIsoPtSum_2,puCorrPtSum_2,chargedIso_2,neutralIso_2,puIso_2,photonIso_2,trackpt_2;
  float numGenJets,jetPt_2,charged_signalCone_2,charged_isoCone_2;
  float matchIsoMu27_1,passIsoMu27,pt_top1,pt_top2,genweight,gen_match_2;
  float met,metphi;
  int nbtag,njets;

  // now we branch address these guys, and we can start running trees
  Tree->SetBranchAddress("run",&run);
  Tree->SetBranchAddress("lumi",&lumi);
  Tree->SetBranchAddress("evt",&evt);
  Tree->SetBranchAddress("NUP",&NUP);
  Tree->SetBranchAddress("npv",&npv);
  Tree->SetBranchAddress("npu",&npu);
  Tree->SetBranchAddress("amcatNLO_weight",&amcatNLO_weight);
  Tree->SetBranchAddress("pt_1",&pt_1);
  Tree->SetBranchAddress("phi_1",&phi_1);
  Tree->SetBranchAddress("eta_1",&eta_1);
  Tree->SetBranchAddress("m_1",&m_1);
  Tree->SetBranchAddress("e_1",&e_1);
  Tree->SetBranchAddress("q_1",&q_1);
  Tree->SetBranchAddress("d0_1",&d0_1);
  Tree->SetBranchAddress("dZ_1",&dZ_1);
  Tree->SetBranchAddress("iso_1",&iso_1);
  Tree->SetBranchAddress("id_m_medium_1",&id_m_medium_1);
  Tree->SetBranchAddress("id_m_tight_1",&id_m_tight_1);
  Tree->SetBranchAddress("pt_2",&pt_2);
  Tree->SetBranchAddress("phi_2",&phi_2);
  Tree->SetBranchAddress("eta_2",&eta_2);
  Tree->SetBranchAddress("m_2",&m_2);
  Tree->SetBranchAddress("e_2",&e_2);
  Tree->SetBranchAddress("q_2",&q_2);
  Tree->SetBranchAddress("d0_2",&d0_2);
  Tree->SetBranchAddress("dZ_2",&dZ_2);
  Tree->SetBranchAddress("iso_2",&iso_2);
  Tree->SetBranchAddress("l2_decayMode",&l2_decayMode);
  Tree->SetBranchAddress("againstElectronLooseMVA6_2",&againstElectronLooseMVA6_2);
  Tree->SetBranchAddress("againstElectronMediumMVA6_2",&againstElectronMediumMVA6_2);
  Tree->SetBranchAddress("againstElectronTightMVA6_2",&againstElectronTightMVA6_2);
  Tree->SetBranchAddress("againstElectronVLooseMVA6_2",&againstElectronVLooseMVA6_2);
  Tree->SetBranchAddress("againstElectronVTightMVA6_2",&againstElectronVTightMVA6_2);
  Tree->SetBranchAddress("againstMuonLoose3_2",&againstMuonLoose3_2);
  Tree->SetBranchAddress("againstMuonTight3_2",&againstMuonTight3_2);
  Tree->SetBranchAddress("byLooseCombinedIsolationDeltaBetaCorr3Hits_2",&byLooseCombinedIsolationDeltaBetaCorr3Hits_2);
  Tree->SetBranchAddress("byMediumCombinedIsolationDeltaBetaCorr3Hits_2",&byMediumCombinedIsolationDeltaBetaCorr3Hits_2);
  Tree->SetBranchAddress("byTightCombinedIsolationDeltaBetaCorr3Hits_2",&byTightCombinedIsolationDeltaBetaCorr3Hits_2);
  Tree->SetBranchAddress("byCombinedIsolationDeltaBetaCorrRaw3Hits_2",&byCombinedIsolationDeltaBetaCorrRaw3Hits_2);
  Tree->SetBranchAddress("byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_2",&byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_2);
  Tree->SetBranchAddress("byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_2",&byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_2);
  Tree->SetBranchAddress("byTightCombinedIsolationDeltaBetaCorr3HitsdR03_2",&byTightCombinedIsolationDeltaBetaCorr3HitsdR03_2);
  Tree->SetBranchAddress("byVLooseIsolationMVArun2v1DBnewDMwLT_2",&byVLooseIsolationMVArun2v1DBnewDMwLT_2);
  Tree->SetBranchAddress("byVLooseIsolationMVArun2v1DBoldDMwLT_2",&byVLooseIsolationMVArun2v1DBoldDMwLT_2);
  Tree->SetBranchAddress("byVLooseIsolationMVArun2v1DBdR03oldDMwLT_2",&byVLooseIsolationMVArun2v1DBdR03oldDMwLT_2);
  Tree->SetBranchAddress("byLooseIsolationMVArun2v1DBnewDMwLT_2",&byLooseIsolationMVArun2v1DBnewDMwLT_2);
  Tree->SetBranchAddress("byLooseIsolationMVArun2v1DBoldDMwLT_2",&byLooseIsolationMVArun2v1DBoldDMwLT_2);
  Tree->SetBranchAddress("byLooseIsolationMVArun2v1DBdR03oldDMwLT_2",&byLooseIsolationMVArun2v1DBdR03oldDMwLT_2);
  Tree->SetBranchAddress("byMediumIsolationMVArun2v1DBnewDMwLT_2",&byMediumIsolationMVArun2v1DBnewDMwLT_2);
  Tree->SetBranchAddress("byMediumIsolationMVArun2v1DBoldDMwLT_2",&byMediumIsolationMVArun2v1DBoldDMwLT_2);
  Tree->SetBranchAddress("byMediumIsolationMVArun2v1DBdR03oldDMwLT_2",&byMediumIsolationMVArun2v1DBdR03oldDMwLT_2);
  Tree->SetBranchAddress("byTightIsolationMVArun2v1DBnewDMwLT_2",&byTightIsolationMVArun2v1DBnewDMwLT_2);
  Tree->SetBranchAddress("byTightIsolationMVArun2v1DBoldDMwLT_2",&byTightIsolationMVArun2v1DBoldDMwLT_2);
  Tree->SetBranchAddress("byTightIsolationMVArun2v1DBdR03oldDMwLT_2",&byTightIsolationMVArun2v1DBdR03oldDMwLT_2);
  Tree->SetBranchAddress("byVTightIsolationMVArun2v1DBnewDMwLT_2",&byVTightIsolationMVArun2v1DBnewDMwLT_2);
  Tree->SetBranchAddress("byVTightIsolationMVArun2v1DBoldDMwLT_2",&byVTightIsolationMVArun2v1DBoldDMwLT_2);
  Tree->SetBranchAddress("byVTightIsolationMVArun2v1DBdR03oldDMwLT_2",&byVTightIsolationMVArun2v1DBdR03oldDMwLT_2);
  Tree->SetBranchAddress("byVVTightIsolationMVArun2v1DBnewDMwLT_2",&byVVTightIsolationMVArun2v1DBnewDMwLT_2);
  Tree->SetBranchAddress("byVVTightIsolationMVArun2v1DBoldDMwLT_2",&byVVTightIsolationMVArun2v1DBoldDMwLT_2);
  Tree->SetBranchAddress("byVVTightIsolationMVArun2v1DBdR03oldDMwLT_2",&byVVTightIsolationMVArun2v1DBdR03oldDMwLT_2);
  Tree->SetBranchAddress("byIsolationMVA3oldDMwoLTraw_2",&byIsolationMVA3oldDMwoLTraw_2);
  Tree->SetBranchAddress("byIsolationMVA3oldDMwLTraw_2",&byIsolationMVA3oldDMwLTraw_2);
  Tree->SetBranchAddress("byIsolationMVA3newDMwoLTraw_2",&byIsolationMVA3newDMwoLTraw_2);
  Tree->SetBranchAddress("byIsolationMVA3newDMwLTraw_2",&byIsolationMVA3newDMwLTraw_2);
  Tree->SetBranchAddress("byVLooseIsolationRerunMVArun2v1DBoldDMwLT_2",&byVLooseIsolationRerunMVArun2v1DBoldDMwLT_2);
  Tree->SetBranchAddress("byLooseIsolationRerunMVArun2v1DBoldDMwLT_2",&byLooseIsolationRerunMVArun2v1DBoldDMwLT_2);
  Tree->SetBranchAddress("byMediumIsolationRerunMVArun2v1DBoldDMwLT_2",&byMediumIsolationRerunMVArun2v1DBoldDMwLT_2);
  Tree->SetBranchAddress("byTightIsolationRerunMVArun2v1DBoldDMwLT_2",&byTightIsolationRerunMVArun2v1DBoldDMwLT_2);
  Tree->SetBranchAddress("byVTightIsolationRerunMVArun2v1DBoldDMwLT_2",&byVTightIsolationRerunMVArun2v1DBoldDMwLT_2);
  Tree->SetBranchAddress("byVVTightIsolationRerunMVArun2v1DBoldDMwLT_2",&byVVTightIsolationRerunMVArun2v1DBoldDMwLT_2);
  Tree->SetBranchAddress("byIsolationRerunMVA3oldDMwLTraw_2",&byIsolationRerunMVA3oldDMwLTraw_2);
  Tree->SetBranchAddress("byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2",&byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2);
  Tree->SetBranchAddress("byLooseIsolationRerunMVArun2v2DBoldDMwLT_2",&byLooseIsolationRerunMVArun2v2DBoldDMwLT_2);
  Tree->SetBranchAddress("byMediumIsolationRerunMVArun2v2DBoldDMwLT_2",&byMediumIsolationRerunMVArun2v2DBoldDMwLT_2);
  Tree->SetBranchAddress("byTightIsolationRerunMVArun2v2DBoldDMwLT_2",&byTightIsolationRerunMVArun2v2DBoldDMwLT_2);
  Tree->SetBranchAddress("byVTightIsolationRerunMVArun2v2DBoldDMwLT_2",&byVTightIsolationRerunMVArun2v2DBoldDMwLT_2);
  Tree->SetBranchAddress("byVVTightIsolationRerunMVArun2v2DBoldDMwLT_2",&byVVTightIsolationRerunMVArun2v2DBoldDMwLT_2);
  Tree->SetBranchAddress("byIsolationRerunMVA3oldDMwLTrawv2_2",&byIsolationRerunMVA3oldDMwLTrawv2_2);
  Tree->SetBranchAddress("chargedIsoPtSum_2",&chargedIsoPtSum_2);
  Tree->SetBranchAddress("decayModeFinding_2",&decayModeFinding_2);
  Tree->SetBranchAddress("decayModeFindingNewDMs_2",&decayModeFindingNewDMs_2);
  Tree->SetBranchAddress("neutralIsoPtSum_2",&neutralIsoPtSum_2);
  Tree->SetBranchAddress("puCorrPtSum_2",&puCorrPtSum_2);
  Tree->SetBranchAddress("chargedIso_2",&chargedIso_2);
  Tree->SetBranchAddress("neutralIso_2",&neutralIso_2);
  Tree->SetBranchAddress("puIso_2",&puIso_2);
  Tree->SetBranchAddress("trackpt_2",&trackpt_2);
  Tree->SetBranchAddress("numGenJets",&numGenJets);
  Tree->SetBranchAddress("jetPt_2",&jetPt_2);
  Tree->SetBranchAddress("charged_signalCone_2",&charged_signalCone_2);
  Tree->SetBranchAddress("charged_isoCone_2",&charged_isoCone_2);
  Tree->SetBranchAddress("matchIsoMu27_1",&matchIsoMu27_1);
  Tree->SetBranchAddress("passIsoMu27",&passIsoMu27);
  Tree->SetBranchAddress("pt_top1",&pt_top1);
  Tree->SetBranchAddress("pt_top2",&pt_top2);
  Tree->SetBranchAddress("genweight",&genweight);
  Tree->SetBranchAddress("gen_match_2",&gen_match_2);
  Tree->SetBranchAddress("met",&met);
  Tree->SetBranchAddress("metphi",&metphi);
  Tree->SetBranchAddress("nbtag",&nbtag);
  Tree->SetBranchAddress("njets",&njets);

  int NumberOfEntries = (int) Tree->GetEntries();
  
  //Create the jet distributions
  //Do we want to open the pass fail master file and take a quick peek at 
  // one of the ata histos to make sure we can get accurate measurements on histogram size?
  TFile* PassFailFile = new TFile("../Distributions/PassFailOut.root");
  TH1F* Data_Pass = (TH1F*)((TDirectory*)PassFailFile->Get("pass"))->Get("Data_Pass");
  
  //PT reweighted histos
  //This forms our gneral grabbed histograms.

  TH1F* VLoosePTFRJetDistribution =new TH1F("VLoosePTFRJetDistribution","VLoosePTFRJetDistribution",
					    Data_Pass->GetSize()-2,
					    Data_Pass->GetXaxis()->GetXmin(),
					    Data_Pass->GetXaxis()->GetXmax());
  TH1F* LoosePTFRJetDistribution = new TH1F("LoosePTFRJetDistribution","LoosePTFRJetDistribution",
					Data_Pass->GetSize()-2,
					Data_Pass->GetXaxis()->GetXmin(),
					Data_Pass->GetXaxis()->GetXmax());
  TH1F* MediumPTFRJetDistribution = new TH1F("MediumPTFRJetDistribution","MediumPTFRJetDistribution",
					 Data_Pass->GetSize()-2,
					 Data_Pass->GetXaxis()->GetXmin(),
					 Data_Pass->GetXaxis()->GetXmax());
  TH1F* TightPTFRJetDistribution = new TH1F("TightPTFRJetDistribution","TightPTFRJetDistribution",
					Data_Pass->GetSize()-2,
					Data_Pass->GetXaxis()->GetXmin(),
					Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightPTFRJetDistribution = new TH1F("VTightPTFRJetDistribution","VTightPTFRJetDistribution",
					 Data_Pass->GetSize()-2,
					 Data_Pass->GetXaxis()->GetXmin(),
					 Data_Pass->GetXaxis()->GetXmax());
  TH1F* VVTightPTFRJetDistribution = new TH1F("VVTightPTFRJetDistribution","VVTightPTFRJetDistribution",
					  Data_Pass->GetSize()-2,
					  Data_Pass->GetXaxis()->GetXmin(),
					  Data_Pass->GetXaxis()->GetXmax());  
  
  //General Weight reweighted histos.
  //These form our low end shape uncertainty?
  TH1F* VLooseLowJetDistribution = new TH1F("VLooseLowJetDistribution","VLooseLowJetDistribution",
					 Data_Pass->GetSize()-2,
					 Data_Pass->GetXaxis()->GetXmin(),
					 Data_Pass->GetXaxis()->GetXmax());
  TH1F* LooseLowJetDistribution = new TH1F("LooseLowJetDistribution","LooseLowJetDistribution",
					Data_Pass->GetSize()-2,
					Data_Pass->GetXaxis()->GetXmin(),
					Data_Pass->GetXaxis()->GetXmax());
  TH1F* MediumLowJetDistribution = new TH1F("MediumLowJetDistribution","MediumLowJetDistribution",
					 Data_Pass->GetSize()-2,
					 Data_Pass->GetXaxis()->GetXmin(),
					 Data_Pass->GetXaxis()->GetXmax());
  TH1F* TightLowJetDistribution = new TH1F("TightLowJetDistribution","TightLowJetDistribution",
					Data_Pass->GetSize()-2,
					Data_Pass->GetXaxis()->GetXmin(),
					Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightLowJetDistribution = new TH1F("VTightLowJetDistribution","VTightLowJetDistribution",
					 Data_Pass->GetSize()-2,
					 Data_Pass->GetXaxis()->GetXmin(),
					 Data_Pass->GetXaxis()->GetXmax());
  TH1F* VVTightLowJetDistribution = new TH1F("VVTightLowJetDistribution","VVTightLowJetDistribution",
					  Data_Pass->GetSize()-2,
					  Data_Pass->GetXaxis()->GetXmin(),
					  Data_Pass->GetXaxis()->GetXmax());

  //This forms the high end of our shape uncertainty
  TH1F* VLooseHighJetDistribution = new TH1F("VLooseHighJetDistribution","VLooseHighJetDistribution",
					     Data_Pass->GetSize()-2,
					     Data_Pass->GetXaxis()->GetXmin(),
					     Data_Pass->GetXaxis()->GetXmax());
  TH1F* LooseHighJetDistribution = new TH1F("LooseHighJetDistribution","LooseHighJetDistribution",
					    Data_Pass->GetSize()-2,
					    Data_Pass->GetXaxis()->GetXmin(),
					    Data_Pass->GetXaxis()->GetXmax());
  TH1F* MediumHighJetDistribution = new TH1F("MediumHighJetDistribution","MediumHighJetDistribution",
					     Data_Pass->GetSize()-2,
					     Data_Pass->GetXaxis()->GetXmin(),
					     Data_Pass->GetXaxis()->GetXmax());
  TH1F* TightHighJetDistribution = new TH1F("TightHighJetDistribution","TightHighJetDistribution",
					    Data_Pass->GetSize()-2,
					    Data_Pass->GetXaxis()->GetXmin(),
					    Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightHighJetDistribution = new TH1F("VTightHighJetDistribution","VTightHighJetDistribution",
					     Data_Pass->GetSize()-2,
					     Data_Pass->GetXaxis()->GetXmin(),
					     Data_Pass->GetXaxis()->GetXmax());
  TH1F* VVTightHighJetDistribution = new TH1F("VVTightHighJetDistribution","VVTightHighJetDistribution",
					      Data_Pass->GetSize()-2,
					      Data_Pass->GetXaxis()->GetXmin(),
					      Data_Pass->GetXaxis()->GetXmax());
  //We need a symmetric flip of these histograms to form our high end shape uncertainty.
  // how do we go about flipping it?

  TFile* FakeRateFile = new TFile("../Distributions/FakeRateDistributions.root");
  //start with just the oerall fake rates
  TH1F* OverallFakeRates = (TH1F*)FakeRateFile->Get("OverallFakeRates");
  float VLooseFakeRate = OverallFakeRates->GetBinContent(1);
  float LooseFakeRate = OverallFakeRates->GetBinContent(2);
  float MediumFakeRate = OverallFakeRates->GetBinContent(3);
  float TightFakeRate = OverallFakeRates->GetBinContent(4);
  float VTightFakeRate = OverallFakeRates->GetBinContent(5);
  float VVTightFakeRate = OverallFakeRates->GetBinContent(6);

  TH1F* OverallDecayMode0FakeRates = (TH1F*)FakeRateFile->Get("OverallDecayMode0FakeRates");
  float DecayMode0VLooseFakeRate = OverallDecayMode0FakeRates->GetBinContent(1);
  float DecayMode0LooseFakeRate = OverallDecayMode0FakeRates->GetBinContent(2);
  float DecayMode0MediumFakeRate = OverallDecayMode0FakeRates->GetBinContent(3);
  float DecayMode0TightFakeRate = OverallDecayMode0FakeRates->GetBinContent(4);
  float DecayMode0VTightFakeRate = OverallDecayMode0FakeRates->GetBinContent(5);
  float DecayMode0VVTightFakeRate = OverallDecayMode0FakeRates->GetBinContent(6);

  TH1F* OverallDecayMode1FakeRates = (TH1F*)FakeRateFile->Get("OverallDecayMode1FakeRates");
  float DecayMode1VLooseFakeRate = OverallDecayMode1FakeRates->GetBinContent(1);
  float DecayMode1LooseFakeRate = OverallDecayMode1FakeRates->GetBinContent(2);
  float DecayMode1MediumFakeRate = OverallDecayMode1FakeRates->GetBinContent(3);
  float DecayMode1TightFakeRate = OverallDecayMode1FakeRates->GetBinContent(4);
  float DecayMode1VTightFakeRate = OverallDecayMode1FakeRates->GetBinContent(5);
  float DecayMode1VVTightFakeRate = OverallDecayMode1FakeRates->GetBinContent(6);

  TH1F* OverallDecayMode10FakeRates = (TH1F*)FakeRateFile->Get("OverallDecayMode10FakeRates");
  float DecayMode10VLooseFakeRate = OverallDecayMode10FakeRates->GetBinContent(1);
  float DecayMode10LooseFakeRate = OverallDecayMode10FakeRates->GetBinContent(2);
  float DecayMode10MediumFakeRate = OverallDecayMode10FakeRates->GetBinContent(3);
  float DecayMode10TightFakeRate = OverallDecayMode10FakeRates->GetBinContent(4);
  float DecayMode10VTightFakeRate = OverallDecayMode10FakeRates->GetBinContent(5);
  float DecayMode10VVTightFakeRate = OverallDecayMode10FakeRates->GetBinContent(6);
  
  //now get the pt based fake rates
  TH1F* VLoosePTFR = (TH1F*)FakeRateFile->Get("VLooseFakeRates");
  TH1F* LoosePTFR = (TH1F*)FakeRateFile->Get("LooseFakeRates");
  TH1F* MediumPTFR = (TH1F*)FakeRateFile->Get("MediumFakeRates");
  TH1F* TightPTFR = (TH1F*)FakeRateFile->Get("TightFakeRates");
  TH1F* VTightPTFR = (TH1F*)FakeRateFile->Get("VTightFakeRates");
  TH1F* VVTightPTFR = (TH1F*)FakeRateFile->Get("VVTightFakeRates");

  //get the pt based decay mode fake rates

  TH1F* VLooseDecayMode0PTFakeRates = (TH1F*)FakeRateFile->Get("VLooseDecayMode0PTFakeRates");
  TH1F* VLooseDecayMode1PTFakeRates = (TH1F*)FakeRateFile->Get("VLooseDecayMode1PTFakeRates");
  TH1F* VLooseDecayMode10PTFakeRates = (TH1F*)FakeRateFile->Get("VLooseDecayMode10PTFakeRates");

  TH1F* LooseDecayMode0PTFakeRates = (TH1F*)FakeRateFile->Get("LooseDecayMode0PTFakeRates");
  TH1F* LooseDecayMode1PTFakeRates = (TH1F*)FakeRateFile->Get("LooseDecayMode1PTFakeRates");
  TH1F* LooseDecayMode10PTFakeRates = (TH1F*)FakeRateFile->Get("LooseDecayMode10PTFakeRates");

  TH1F* MediumDecayMode0PTFakeRates = (TH1F*)FakeRateFile->Get("MediumDecayMode0PTFakeRates");
  TH1F* MediumDecayMode1PTFakeRates = (TH1F*)FakeRateFile->Get("MediumDecayMode1PTFakeRates");
  TH1F* MediumDecayMode10PTFakeRates = (TH1F*)FakeRateFile->Get("MediumDecayMode10PTFakeRates");

  TH1F* TightDecayMode0PTFakeRates = (TH1F*)FakeRateFile->Get("TightDecayMode0PTFakeRates");
  TH1F* TightDecayMode1PTFakeRates = (TH1F*)FakeRateFile->Get("TightDecayMode1PTFakeRates");
  TH1F* TightDecayMode10PTFakeRates = (TH1F*)FakeRateFile->Get("TightDecayMode10PTFakeRates");

  TH1F* VTightDecayMode0PTFakeRates = (TH1F*)FakeRateFile->Get("VTightDecayMode0PTFakeRates");
  TH1F* VTightDecayMode1PTFakeRates = (TH1F*)FakeRateFile->Get("VTightDecayMode1PTFakeRates");
  TH1F* VTightDecayMode10PTFakeRates = (TH1F*)FakeRateFile->Get("VTightDecayMode10PTFakeRates");

  TH1F* VVTightDecayMode0PTFakeRates = (TH1F*)FakeRateFile->Get("VVTightDecayMode0PTFakeRates");
  TH1F* VVTightDecayMode1PTFakeRates = (TH1F*)FakeRateFile->Get("VVTightDecayMode1PTFakeRates");
  TH1F* VVTightDecayMode10PTFakeRates = (TH1F*)FakeRateFile->Get("VVTightDecayMode10PTFakeRates");

  //get our new pt,eta and decay mode based fake rates.
  /*
  TH2F* VLooseDecayMode0FakeRates = (TH2F*) FakeRateFile->Get("VLooseDecayMode0FakeRates");
  TH2F* VLooseDecayMode1FakeRates = (TH2F*) FakeRateFile->Get("VLooseDecayMode1FakeRates");
  TH2F* VLooseDecayMode10FakeRates = (TH2F*) FakeRateFile->Get("VLooseDecayMode10FakeRates");

  TH2F* LooseDecayMode0FakeRates = (TH2F*) FakeRateFile->Get("LooseDecayMode0FakeRates");
  TH2F* LooseDecayMode1FakeRates = (TH2F*) FakeRateFile->Get("LooseDecayMode1FakeRates");
  TH2F* LooseDecayMode10FakeRates = (TH2F*) FakeRateFile->Get("LooseDecayMode10FakeRates");

  TH2F* MediumDecayMode0FakeRates = (TH2F*) FakeRateFile->Get("MediumDecayMode0FakeRates");
  TH2F* MediumDecayMode1FakeRates = (TH2F*) FakeRateFile->Get("MediumDecayMode1FakeRates");
  TH2F* MediumDecayMode10FakeRates = (TH2F*) FakeRateFile->Get("MediumDecayMode10FakeRates");

  TH2F* TightDecayMode0FakeRates = (TH2F*) FakeRateFile->Get("TightDecayMode0FakeRates");
  TH2F* TightDecayMode1FakeRates = (TH2F*) FakeRateFile->Get("TightDecayMode1FakeRates");
  TH2F* TightDecayMode10FakeRates = (TH2F*) FakeRateFile->Get("TightDecayMode10FakeRates");

  TH2F* VTightDecayMode0FakeRates = (TH2F*) FakeRateFile->Get("VTightDecayMode0FakeRates");
  TH2F* VTightDecayMode1FakeRates = (TH2F*) FakeRateFile->Get("VTightDecayMode1FakeRates");
  TH2F* VTightDecayMode10FakeRates = (TH2F*) FakeRateFile->Get("VTightDecayMode10FakeRates");
  
  TH2F* VVTightDecayMode0FakeRates = (TH2F*) FakeRateFile->Get("VVTightDecayMode0FakeRates");
  TH2F* VVTightDecayMode1FakeRates = (TH2F*) FakeRateFile->Get("VVTightDecayMode1FakeRates");
  TH2F* VVTightDecayMode10FakeRates = (TH2F*) FakeRateFile->Get("VVTightDecayMode10FakeRates");  
  */
  
  float NumVLooseEvents = 0.0;
  float AverageVLoosePT = 0.0;
  float AverageVLooseFakeRate = 0.0;
  float AverageVLooseWeight = 0.0;

  float NumLooseEvents = 0.0;
  float AverageLoosePT = 0.0;
  float AverageLooseFakeRate = 0.0;
  float AverageLooseWeight = 0.0;

  float NumMediumEvents = 0.0;
  float AverageMediumPT = 0.0;
  float AverageMediumFakeRate = 0.0;
  float AverageMediumWeight = 0.0;

  float NumTightEvents = 0.0;
  float AverageTightPT = 0.0;
  float AverageTightFakeRate = 0.0;
  float AverageTightWeight = 0.0;

  float NumVTightEvents = 0.0;
  float AverageVTightPT = 0.0;
  float AverageVTightFakeRate = 0.0;
  float AverageVTightWeight = 0.0;

  float NumVVTightEvents = 0.0;
  float AverageVVTightPT = 0.0;
  float AverageVVTightFakeRate = 0.0;
  float AverageVVTightWeight = 0.0;
  //let's try doing the average 
  for(int i=0;i < NumberOfEntries; i++)
    {
      Tree->GetEntry(i);
      if(i%(NumberOfEntries/20)==0 ||  i==(NumberOfEntries-1)) 
	{	  
	  fprintf(stdout,"<"); 
	  for(int NumEquals = 0;NumEquals < i/(NumberOfEntries/20); NumEquals++) fprintf(stdout,"="); 
	  for(int NumSpaces = 0;NumSpaces < 20-(i/(NumberOfEntries/20));NumSpaces++) fprintf(stdout," ");
	  fprintf(stdout,">\r");
	  if(i==(NumberOfEntries-1)) fprintf(stdout,"<====================>\n");
	  fflush(stdout);
	}

      TLorentzVector l1; l1.SetPtEtaPhiE(pt_1, eta_1, phi_1, e_1); //muon
      TLorentzVector l2; l2.SetPtEtaPhiE(pt_2, eta_2, phi_2, e_2); //tau

      //match diego's >30 pt cut instead of my original 29.0 cut
      if(pt_1 < 30.0 or std::abs(eta_1) > 2.4 or !id_m_medium_1 or iso_1 > 0.15 or std::abs(dZ_1) > 0.2 or std::abs(d0_1) > 0.045 or !matchIsoMu27_1) continue;
      //tau criteria
      //added the decaymodefinding_2 which catches the old decay mode finding.
      if(pt_2 < 20.0  or std::abs(eta_2) > 2.3 or againstElectronVLooseMVA6_2 != 1 or againstMuonTight3_2 != 1 or !decayModeFinding_2 /*or std::abs(dZ_2) > 0.2*/) continue;      

      //if(pt_2 < 20.0 or pt_2 > 25.0) continue;

      //pair criteria            
      float deltaphi = std::abs(phi_1-phi_2);
      if (deltaphi > M_PI) deltaphi-=2.0*M_PI;
      float DeltaR = std::sqrt((eta_1-eta_2)*(eta_1-eta_2)+deltaphi*deltaphi);
      if(DeltaR <= 0.5)  continue;
	 
      TLorentzVector MissingP;
      MissingP.SetPtEtaPhiM(met,0,metphi,0);
      
      float TransverseMass = std::sqrt(2.0*l1.Pt()*MissingP.Pt()*(1.0-std::cos(l1.DeltaPhi(MissingP))));

      //get a bisector in the transverse plane?      
      TVector3 ZetaUnit;
      
      float BisectorAngle = (l1.Vect().Phi() + l2.Vect().Phi())/2.0;
      ZetaUnit.SetPhi(BisectorAngle);
      ZetaUnit = ZetaUnit.Unit();
      //correct it if it faces the wrong direction
      if(ZetaUnit.Dot(l1.Vect()) < 0.0 or ZetaUnit.Dot(l2.Vect()) < 0.0)
	{
	  if(BisectorAngle >= 0.0) BisectorAngle -= M_PI;
	  else BisectorAngle += M_PI;
	}
      ZetaUnit.SetPhi(BisectorAngle);
      ZetaUnit = ZetaUnit.Unit();      
      //method(s) below seems to offer worse agreement?
      /*
      ZetaUnit = l1.Vect().Unit()+l2.Vect().Unit();
      ZetaUnit.SetPtEtaPhi(ZetaUnit.Pt(),0.0,ZetaUnit.Phi());
      ZetaUnit = ZetaUnit.Unit();
      */
      /*
      ZetaUnit = l1.Vect().Unit()+l2.Vect().Unit();
      ZetaUnit = ZetaUnit.Unit();
      */
      float PZetaVis = (l1.Vect()+l2.Vect()).Dot(ZetaUnit);
      float PZetaAll = (l1.Vect()+l2.Vect()+MissingP.Vect()).Dot(ZetaUnit);
      float PZeta = PZetaAll - 0.85 * PZetaVis;
      
      float HistoHighEdge = Data_Pass->GetXaxis()->GetXmax();
      float HistoLowEdge = Data_Pass->GetXaxis()->GetXmin();
      
      float Var = (l1+l2).M();      
      
      //changed the mt cut to 50 to match diego, instead of my original 40
      if(q_1 * q_2 < 0.0 and TransverseMass < 50.0 and PZeta > -25.0)      
	{
	  float PTFakeRate = 0.0;
	  float PTWeighting = 0.0;
	  if(!byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      NumVLooseEvents += 1.0;
	      if(l2_decayMode == 0) PTFakeRate = VLooseDecayMode0PTFakeRates->GetBinContent(VLooseDecayMode0PTFakeRates->FindBin(l2.Pt()));	      
	      else if(l2_decayMode == 1) PTFakeRate = VLooseDecayMode1PTFakeRates->GetBinContent(VLooseDecayMode1PTFakeRates->FindBin(l2.Pt()));	      
	      else if(l2_decayMode == 10) PTFakeRate = VLooseDecayMode10PTFakeRates->GetBinContent(VLooseDecayMode10PTFakeRates->FindBin(l2.Pt()));
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      AverageVLoosePT += l2.Pt();
	      AverageVLooseFakeRate += PTFakeRate;
	      AverageVLooseWeight += PTWeighting;
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byLooseIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	 
	      NumLooseEvents += 1.0;
	      if(l2_decayMode == 0) PTFakeRate = LooseDecayMode0PTFakeRates->GetBinContent(LooseDecayMode0PTFakeRates->FindBin(l2.Pt()));	      
	      else if(l2_decayMode == 1) PTFakeRate = LooseDecayMode1PTFakeRates->GetBinContent(LooseDecayMode1PTFakeRates->FindBin(l2.Pt()));	      
	      else if(l2_decayMode == 10) PTFakeRate = LooseDecayMode10PTFakeRates->GetBinContent(LooseDecayMode10PTFakeRates->FindBin(l2.Pt()));	      
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      AverageLoosePT += l2.Pt();
	      AverageLooseFakeRate += PTFakeRate;
	      AverageLooseWeight += PTWeighting;
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byMediumIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	 
	      NumMediumEvents += 1.0;
	      if(l2_decayMode == 0) PTFakeRate = MediumDecayMode0PTFakeRates->GetBinContent(MediumDecayMode0PTFakeRates->FindBin(l2.Pt()));	      
	      else if(l2_decayMode == 1) PTFakeRate = MediumDecayMode1PTFakeRates->GetBinContent(MediumDecayMode1PTFakeRates->FindBin(l2.Pt()));	      
	      else if(l2_decayMode == 10) PTFakeRate = MediumDecayMode10PTFakeRates->GetBinContent(MediumDecayMode10PTFakeRates->FindBin(l2.Pt()));
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      AverageMediumPT += l2.Pt();
	      AverageMediumFakeRate += PTFakeRate;
	      AverageMediumWeight += PTWeighting;
		
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	 
	      NumTightEvents += 1.0;
	      if(l2_decayMode == 0) PTFakeRate = TightDecayMode0PTFakeRates->GetBinContent(TightDecayMode0PTFakeRates->FindBin(l2.Pt()));	      
	      else if(l2_decayMode == 1) PTFakeRate = TightDecayMode1PTFakeRates->GetBinContent(TightDecayMode1PTFakeRates->FindBin(l2.Pt()));	      	      
	      else if(l2_decayMode == 10) PTFakeRate = TightDecayMode10PTFakeRates->GetBinContent(TightDecayMode10PTFakeRates->FindBin(l2.Pt()));	      
		PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		AverageTightPT += l2.Pt();
		AverageTightFakeRate += PTFakeRate;
		AverageTightWeight += PTWeighting;

	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	 
	      NumVTightEvents += 1.0;
	      if(l2_decayMode == 0) PTFakeRate = VTightDecayMode0PTFakeRates->GetBinContent(VTightDecayMode0PTFakeRates->FindBin(l2.Pt()));	      	      
	      else if(l2_decayMode == 1) PTFakeRate = VTightDecayMode1PTFakeRates->GetBinContent(VTightDecayMode1PTFakeRates->FindBin(l2.Pt()));	      		
	      else if(l2_decayMode == 10) PTFakeRate = VTightDecayMode10PTFakeRates->GetBinContent(VTightDecayMode10PTFakeRates->FindBin(l2.Pt()));	      	      
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      AverageVTightPT += l2.Pt();
	      AverageVTightFakeRate += PTFakeRate;
	      AverageVTightWeight += PTWeighting;
	      
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	 
	      NumVVTightEvents += 1.0;
	      if(l2_decayMode == 0) PTFakeRate = VVTightDecayMode0PTFakeRates->GetBinContent(VVTightDecayMode0PTFakeRates->FindBin(l2.Pt()));	      	      
	      else if(l2_decayMode == 1) PTFakeRate = VVTightDecayMode1PTFakeRates->GetBinContent(VVTightDecayMode1PTFakeRates->FindBin(l2.Pt()));	      		
	      else if(l2_decayMode == 10) PTFakeRate = VVTightDecayMode10PTFakeRates->GetBinContent(VVTightDecayMode10PTFakeRates->FindBin(l2.Pt()));
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      AverageVVTightPT += l2.Pt();
	      AverageVVTightFakeRate += PTFakeRate;
	      AverageVVTightWeight += PTWeighting;
	      
	    }
	} // end of charge sign check.
    }//end of average calculation loop

  if(NumVLooseEvents != 0.0)
    {
      AverageVLoosePT = AverageVLoosePT / NumVLooseEvents;
      AverageVLooseFakeRate = AverageVLooseFakeRate / NumVLooseEvents;
      AverageVLooseWeight = AverageVLooseWeight / NumVLooseEvents;
      std::cout<<"Num VLoose Events: "<<NumVLooseEvents<<std::endl;
      std::cout<<"Average VLoose PT: "<<AverageVLoosePT<<std::endl;
      std::cout<<"Average VLoose Fake Rate: "<<AverageVLooseFakeRate<<std::endl;
      std::cout<<"Average VLoose Weight: "<<AverageVLooseWeight<<std::endl;
      std::cout<<std::endl;
    }
  if(NumLooseEvents != 0.0)
    {
      AverageLoosePT = AverageLoosePT / NumLooseEvents;
      AverageLooseFakeRate = AverageLooseFakeRate / NumLooseEvents;
      AverageLooseWeight = AverageLooseWeight / NumLooseEvents;
      std::cout<<"Num Loose Events: "<<NumLooseEvents<<std::endl;
      std::cout<<"Average Loose PT: "<<AverageLoosePT<<std::endl;
      std::cout<<"Average Loose Fake Rate: "<<AverageLooseFakeRate<<std::endl;
      std::cout<<"Average Loose Weight: "<<AverageLooseWeight<<std::endl;
      std::cout<<std::endl;
    }
  if(NumMediumEvents != 0.0)
    {
      AverageMediumPT = AverageMediumPT / NumMediumEvents;
      AverageMediumFakeRate = AverageMediumFakeRate / NumMediumEvents;
      AverageMediumWeight = AverageMediumWeight / NumMediumEvents;
      std::cout<<"Num Medium Events: "<<NumMediumEvents<<std::endl;
      std::cout<<"Average Medium PT: "<<AverageMediumPT<<std::endl;
      std::cout<<"Average Medium Fake Rate: "<<AverageMediumFakeRate<<std::endl;
      std::cout<<"Average Medium Weight: "<<AverageMediumWeight<<std::endl;
      std::cout<<std::endl;
    }
  if(NumTightEvents != 0.0)
    {
      AverageTightPT = AverageTightPT / NumTightEvents;
      AverageTightFakeRate = AverageTightFakeRate / NumTightEvents;
      AverageTightWeight = AverageTightWeight / NumTightEvents;
      std::cout<<"Num Tight Events: "<<NumTightEvents<<std::endl;
      std::cout<<"Average Tight PT: "<<AverageTightPT<<std::endl;
      std::cout<<"Average Tight Fake Rate: "<<AverageTightFakeRate<<std::endl;
      std::cout<<"Average Tight Weight: "<<AverageTightWeight<<std::endl;
      std::cout<<std::endl;
    }
  if(NumVTightEvents != 0.0)
    {
      AverageVTightPT = AverageVTightPT / NumVTightEvents;
      AverageVTightFakeRate = AverageVTightFakeRate / NumVTightEvents;
      AverageVTightWeight = AverageVTightWeight / NumVTightEvents;
      std::cout<<"Num VTight Events: "<<NumVTightEvents<<std::endl;
      std::cout<<"Average VTight PT: "<<AverageVTightPT<<std::endl;
      std::cout<<"Average VTight Fake Rate: "<<AverageVTightFakeRate<<std::endl;
      std::cout<<"Average VTight Weight: "<<AverageVTightWeight<<std::endl;
      std::cout<<std::endl;      
    }
  if(NumVVTightEvents != 0.0)
    {
      AverageVVTightPT = AverageVVTightPT / NumVVTightEvents;
      AverageVVTightFakeRate = AverageVVTightFakeRate / NumVVTightEvents;
      AverageVVTightWeight = AverageVVTightWeight / NumVVTightEvents;
      std::cout<<"Num VVTight Events: "<<NumVVTightEvents<<std::endl;
      std::cout<<"Average VVTight PT: "<<AverageVVTightPT<<std::endl;
      std::cout<<"Average VVTight Fake Rate: "<<AverageVVTightFakeRate<<std::endl;
      std::cout<<"Average VVTight Weight: "<<AverageVVTightWeight<<std::endl;
      std::cout<<std::endl;
    }
  

  //do the generation of the distributions
  for(int i=0;i < NumberOfEntries; i++)
    {
      Tree->GetEntry(i);
      if(i%(NumberOfEntries/20)==0 ||  i==(NumberOfEntries-1)) 
	{	  
	  fprintf(stdout,"<"); 
	  for(int NumEquals = 0;NumEquals < i/(NumberOfEntries/20); NumEquals++) fprintf(stdout,"="); 
	  for(int NumSpaces = 0;NumSpaces < 20-(i/(NumberOfEntries/20));NumSpaces++) fprintf(stdout," ");
	  fprintf(stdout,">\r");
	  if(i==(NumberOfEntries-1)) fprintf(stdout,"<====================>\n");
	  fflush(stdout);
	}

      TLorentzVector l1; l1.SetPtEtaPhiE(pt_1, eta_1, phi_1, e_1); //muon
      TLorentzVector l2; l2.SetPtEtaPhiE(pt_2, eta_2, phi_2, e_2); //tau

      //math diego's pt > 30 cut instead of my original 29.0 cut.
      if(pt_1 < 30.0 or std::abs(eta_1) > 2.4 or !id_m_medium_1 or iso_1 > 0.15 or std::abs(dZ_1) > 0.2 or std::abs(d0_1) > 0.045 or !matchIsoMu27_1) continue;
      //tau criteria
      //added the decaymodefinding_2 which catches the old decay mode finding.
      if(pt_2 < 20.0  or std::abs(eta_2) > 2.3 or againstElectronVLooseMVA6_2 != 1 or againstMuonTight3_2 != 1 or !decayModeFinding_2 /*or std::abs(dZ_2) > 0.2*/) continue;      
      
      //if(pt_2 < 50.0) continue;

      //pair criteria            
      float deltaphi = std::abs(phi_1-phi_2);
      if (deltaphi > M_PI) deltaphi-=2.0*M_PI;
      float DeltaR = std::sqrt((eta_1-eta_2)*(eta_1-eta_2)+deltaphi*deltaphi);
      if(DeltaR <= 0.5)  continue;
	 
      TLorentzVector MissingP;
      MissingP.SetPtEtaPhiM(met,0,metphi,0);
      
      float TransverseMass = std::sqrt(2.0*l1.Pt()*MissingP.Pt()*(1.0-std::cos(l1.DeltaPhi(MissingP))));

      //get a bisector in the transverse plane?      
      TVector3 ZetaUnit;
      
      float BisectorAngle = (l1.Vect().Phi() + l2.Vect().Phi())/2.0;
      ZetaUnit.SetPhi(BisectorAngle);
      ZetaUnit = ZetaUnit.Unit();
      //correct it if it faces the wrong direction
      if(ZetaUnit.Dot(l1.Vect()) < 0.0 or ZetaUnit.Dot(l2.Vect()) < 0.0)
	{
	  if(BisectorAngle >= 0.0) BisectorAngle -= M_PI;
	  else BisectorAngle += M_PI;
	}
      ZetaUnit.SetPhi(BisectorAngle);
      ZetaUnit = ZetaUnit.Unit();      
      //method(s) below seems to offer worse agreement?
      /*
      ZetaUnit = l1.Vect().Unit()+l2.Vect().Unit();
      ZetaUnit.SetPtEtaPhi(ZetaUnit.Pt(),0.0,ZetaUnit.Phi());
      ZetaUnit = ZetaUnit.Unit();
      */
      /*
      ZetaUnit = l1.Vect().Unit()+l2.Vect().Unit();
      ZetaUnit = ZetaUnit.Unit();
      */
      float PZetaVis = (l1.Vect()+l2.Vect()).Dot(ZetaUnit);
      float PZetaAll = (l1.Vect()+l2.Vect()+MissingP.Vect()).Dot(ZetaUnit);
      float PZeta = PZetaAll - 0.85 * PZetaVis;
      
      float HistoHighEdge = Data_Pass->GetXaxis()->GetXmax();
      float HistoLowEdge = Data_Pass->GetXaxis()->GetXmin();
      
      float Var = (l1+l2).M();      
      //changed the mt cut to 50 to match diego, instead of my original 40
      if(q_1 * q_2 < 0.0 and TransverseMass < 50.0 and PZeta > -25.0)      
	{
	  //alright, now we look at each of the indivudal MVA working points and find the
	  // we find the ones that fail, and we reweight them, and record the visible mass
	  float PTFakeRate = 0.0;
	  float PTWeighting = 0.0;
	  float ExacerbatedFakeRate = 0.0;
	  float ExacerbatedWeighting = 0.0;	  
	  if(!byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      //Look at the decay mode of our claimed tau?
	      if(l2_decayMode == 0)
		{		  
		  PTFakeRate = VLooseDecayMode0PTFakeRates->GetBinContent(VLooseDecayMode0PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0VLooseFakeRate);
		  VLooseHighJetDistribution->Fill(Var,DecayMode0VLooseFakeRate/(1.0-DecayMode0VLooseFakeRate));   	      
		}
	      else if(l2_decayMode == 1)
		{		  
		  PTFakeRate = VLooseDecayMode1PTFakeRates->GetBinContent(VLooseDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1VLooseFakeRate);
		  VLooseHighJetDistribution->Fill(Var,DecayMode1VLooseFakeRate/(1.0-DecayMode1VLooseFakeRate));
		}
	      else if(l2_decayMode == 10)
		{		  
		  PTFakeRate = VLooseDecayMode10PTFakeRates->GetBinContent(VLooseDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10VLooseFakeRate);
		  VLooseHighJetDistribution->Fill(Var,DecayMode10VLooseFakeRate/(1.0-DecayMode10VLooseFakeRate));
		}	      
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      //ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, VLooseFakeRate);
	      ExacerbatedWeighting = /*GenerateExacerbatedWeighting(PTWeighting,AverageVLooseWeight);*/ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      	      	      
	      //VLooseWeighting = VLooseFakeRate/(1.0-VLooseFakeRate);

	      VLooseLowJetDistribution->Fill(Var,ExacerbatedWeighting);
	      VLoosePTFRJetDistribution->Fill(Var,PTWeighting);
	      //VLooseHighJetDistribution->Fill(Var,VLooseWeighting);
	      //VLooseHighJetDistribution->Fill(Var,AverageVLooseWeight);
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byLooseIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	      
	      if(l2_decayMode == 0)
		{		  
		  PTFakeRate = LooseDecayMode0PTFakeRates->GetBinContent(LooseDecayMode0PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0LooseFakeRate);
		  LooseHighJetDistribution->Fill(Var,DecayMode0LooseFakeRate/(1.0-DecayMode0LooseFakeRate));
		}
	      else if(l2_decayMode == 1)
		{		  
		  PTFakeRate = LooseDecayMode1PTFakeRates->GetBinContent(LooseDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1LooseFakeRate);
		  LooseHighJetDistribution->Fill(Var,DecayMode1LooseFakeRate/(1.0-DecayMode1LooseFakeRate));
		}
	      else if(l2_decayMode == 10)
		{		  
		  PTFakeRate = LooseDecayMode10PTFakeRates->GetBinContent(LooseDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10LooseFakeRate);
		  LooseHighJetDistribution->Fill(Var,DecayMode10LooseFakeRate/(1.0-DecayMode10LooseFakeRate));
		}	      
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      //ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, LooseFakeRate);
	      ExacerbatedWeighting = /*GenerateExacerbatedWeighting(PTWeighting,AverageLooseWeight);*/ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      	      
	     
	      LooseLowJetDistribution->Fill(Var,ExacerbatedWeighting);
	      LoosePTFRJetDistribution->Fill(Var,PTWeighting);	      
	      //LooseHighJetDistribution->Fill(Var,LooseFakeRate/(1.0-LooseFakeRate));
	      //LooseHighJetDistribution->Fill(Var,AverageLooseWeight);
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byMediumIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      if(l2_decayMode == 0)
		{		 
		  PTFakeRate = MediumDecayMode0PTFakeRates->GetBinContent(MediumDecayMode0PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0MediumFakeRate);
		  MediumHighJetDistribution->Fill(Var,DecayMode0MediumFakeRate/(1.0-DecayMode0MediumFakeRate));
		}
	      else if(l2_decayMode == 1)
		{		  
		  PTFakeRate = MediumDecayMode1PTFakeRates->GetBinContent(MediumDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1MediumFakeRate);
		  MediumHighJetDistribution->Fill(Var,DecayMode1MediumFakeRate/(1.0-DecayMode1MediumFakeRate));
		}
	      else if(l2_decayMode == 10)
		{		  
		  PTFakeRate = MediumDecayMode10PTFakeRates->GetBinContent(MediumDecayMode0PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10MediumFakeRate);
		  MediumHighJetDistribution->Fill(Var,DecayMode10MediumFakeRate/(1.0-DecayMode10MediumFakeRate));
		}	      
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      //ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, MediumFakeRate);
	      ExacerbatedWeighting = /*GenerateExacerbatedWeighting(PTWeighting,AverageMediumWeight);*/ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      
	      
	      MediumLowJetDistribution->Fill(Var,ExacerbatedWeighting);
	      MediumPTFRJetDistribution->Fill(Var,PTWeighting);	 
	      //MediumHighJetDistribution->Fill(Var,MediumFakeRate/(1.0-MediumFakeRate));
	      //MediumHighJetDistribution->Fill(Var,AverageMediumWeight);
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      if(l2_decayMode == 0)
		{		  
		  PTFakeRate = TightDecayMode0PTFakeRates->GetBinContent(TightDecayMode0PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0TightFakeRate);
		  TightHighJetDistribution->Fill(Var,DecayMode0TightFakeRate/(1.0-DecayMode0TightFakeRate));
		}
	      else if(l2_decayMode == 1)
		{		  
		  PTFakeRate = TightDecayMode1PTFakeRates->GetBinContent(TightDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1TightFakeRate);
		  TightHighJetDistribution->Fill(Var,DecayMode1TightFakeRate/(1.0-DecayMode1TightFakeRate));
		}
	      else if(l2_decayMode == 10)
		{		  
		  PTFakeRate = TightDecayMode10PTFakeRates->GetBinContent(TightDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10TightFakeRate);
		  TightHighJetDistribution->Fill(Var,DecayMode10TightFakeRate/(1.0-DecayMode10TightFakeRate));
		}	      
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      //ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, TightFakeRate);
	      ExacerbatedWeighting = /*GenerateExacerbatedWeighting(PTWeighting,AverageTightWeight);*/ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      
	      
	      TightLowJetDistribution->Fill(Var,ExacerbatedWeighting);
	      TightPTFRJetDistribution->Fill(Var,PTWeighting);
	      //TightHighJetDistribution->Fill(Var,TightFakeRate/(1.0-TightFakeRate));
	      //TightHighJetDistribution->Fill(Var,AverageTightWeight);
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	
	      if(l2_decayMode == 0)
		{		  
		  PTFakeRate = VTightDecayMode0PTFakeRates->GetBinContent(VTightDecayMode0PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0VTightFakeRate);
		  VTightHighJetDistribution->Fill(Var,DecayMode0VTightFakeRate/(1.0-DecayMode0VTightFakeRate));
		}
	      else if(l2_decayMode == 1)
		{		  
		  PTFakeRate = VTightDecayMode1PTFakeRates->GetBinContent(VTightDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1VTightFakeRate);
		  VTightHighJetDistribution->Fill(Var,DecayMode1VTightFakeRate/(1.0-DecayMode1VTightFakeRate));
		}
	      else if(l2_decayMode == 10)
		{		  
		  PTFakeRate = VTightDecayMode10PTFakeRates->GetBinContent(LooseDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10VTightFakeRate);
		  VTightHighJetDistribution->Fill(Var,DecayMode10VTightFakeRate/(1.0-DecayMode10VTightFakeRate));
		}	      
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);	      
	      //ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, VTightFakeRate);
	      ExacerbatedWeighting = /*GenerateExacerbatedWeighting(PTWeighting,AverageVTightWeight);*/ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

	      VTightLowJetDistribution->Fill(Var,ExacerbatedWeighting);
	      VTightPTFRJetDistribution->Fill(Var,PTWeighting);
	      //VTightHighJetDistribution->Fill(Var,VTightFakeRate/(1.0-VTightFakeRate));
	      //VTightHighJetDistribution->Fill(Var,AverageVTightWeight);
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	
	      if(l2_decayMode == 0)
		{		  
		  PTFakeRate = VVTightDecayMode0PTFakeRates->GetBinContent(VVTightDecayMode0PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0VVTightFakeRate);
		  VVTightHighJetDistribution->Fill(Var,DecayMode0VVTightFakeRate/(1.0-DecayMode0VVTightFakeRate));
		}
	      else if(l2_decayMode == 1)
		{		  
		  PTFakeRate = VVTightDecayMode1PTFakeRates->GetBinContent(VVTightDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1VVTightFakeRate);
		  VVTightHighJetDistribution->Fill(Var,DecayMode1VVTightFakeRate/(1.0-DecayMode1VVTightFakeRate));
		}
	      else if(l2_decayMode == 10)
		{		  
		  PTFakeRate = VVTightDecayMode10PTFakeRates->GetBinContent(VVTightDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10VVTightFakeRate);
		  VVTightHighJetDistribution->Fill(Var,DecayMode10VVTightFakeRate/(1.0-DecayMode10VVTightFakeRate));
		}	      
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);	      
	      //ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, VVTightFakeRate);
	      ExacerbatedWeighting = /*GenerateExacerbatedWeighting(PTWeighting,AverageVVTightWeight);*/ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

	      VVTightLowJetDistribution->Fill(Var,ExacerbatedWeighting);
	      VVTightPTFRJetDistribution->Fill(Var,PTWeighting);
	      //VVTightHighJetDistribution->Fill(Var,VVTightFakeRate/(1.0-VVTightFakeRate));
	      //VVTightHighJetDistribution->Fill(Var,AverageVVTightWeight);
	    }
	} //end of checking for signal region
    } //end of for loop

  std::cout<<std::endl;    

  //Alright let's right this out and get the heck out of here.
  TFile* FakeRateDeterminedDistributions = new TFile("../Distributions/FakeRateDeterminedDistributions.root","RECREATE");

  VLoosePTFRJetDistribution->Write();
  LoosePTFRJetDistribution->Write();
  MediumPTFRJetDistribution->Write();
  TightPTFRJetDistribution->Write();
  VTightPTFRJetDistribution->Write();
  VVTightPTFRJetDistribution->Write();  
  
  VLooseLowJetDistribution->Write();
  LooseLowJetDistribution->Write();
  MediumLowJetDistribution->Write();
  TightLowJetDistribution->Write();
  VTightLowJetDistribution->Write();
  VVTightLowJetDistribution->Write();  

  VLooseHighJetDistribution->Write();
  LooseHighJetDistribution->Write();
  MediumHighJetDistribution->Write();
  TightHighJetDistribution->Write();
  VTightHighJetDistribution->Write();
  VVTightHighJetDistribution->Write();  

  FakeRateDeterminedDistributions->Close();
}
