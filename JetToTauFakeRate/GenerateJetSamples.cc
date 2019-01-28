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
  TH1F* VLooseDecayMode0LowJetDistribution = new TH1F("VLooseDecayMode0LowJetDistribution","VLooseDecayMode0LowJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* LooseDecayMode0LowJetDistribution = new TH1F("LooseDecayMode0LowJetDistribution","LooseDecayMode0LowJetDistribution",
						     Data_Pass->GetSize()-2,
						     Data_Pass->GetXaxis()->GetXmin(),
						     Data_Pass->GetXaxis()->GetXmax());
  TH1F* MediumDecayMode0LowJetDistribution = new TH1F("MediumDecayMode0LowJetDistribution","MediumDecayMode0LowJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* TightDecayMode0LowJetDistribution = new TH1F("TightDecayMode0LowJetDistribution","TightDecayMode0LowJetDistribution",
						     Data_Pass->GetSize()-2,
						     Data_Pass->GetXaxis()->GetXmin(),
						     Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightDecayMode0LowJetDistribution = new TH1F("VTightDecayMode0LowJetDistribution","VTightDecayMode0LowJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* VVTightDecayMode0LowJetDistribution = new TH1F("VVTightDecayMode0LowJetDistribution","VVTightDecayMode0LowJetDistribution",
						       Data_Pass->GetSize()-2,
						       Data_Pass->GetXaxis()->GetXmin(),
						       Data_Pass->GetXaxis()->GetXmax());

  TH1F* VLooseDecayMode1LowJetDistribution = new TH1F("VLooseDecayMode1LowJetDistribution","VLooseDecayMode1LowJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* LooseDecayMode1LowJetDistribution = new TH1F("LooseDecayMode1LowJetDistribution","LooseDecayMode1LowJetDistribution",
						     Data_Pass->GetSize()-2,
						     Data_Pass->GetXaxis()->GetXmin(),
						     Data_Pass->GetXaxis()->GetXmax());
  TH1F* MediumDecayMode1LowJetDistribution = new TH1F("MediumDecayMode1LowJetDistribution","MediumDecayMode1LowJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* TightDecayMode1LowJetDistribution = new TH1F("TightDecayMode1LowJetDistribution","TightDecayMode1LowJetDistribution",
						     Data_Pass->GetSize()-2,
						     Data_Pass->GetXaxis()->GetXmin(),
						     Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightDecayMode1LowJetDistribution = new TH1F("VTightDecayMode1LowJetDistribution","VTightDecayMode1LowJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* VVTightDecayMode1LowJetDistribution = new TH1F("VVTightDecayMode1LowJetDistribution","VVTightDecayMode1LowJetDistribution",
						       Data_Pass->GetSize()-2,
						       Data_Pass->GetXaxis()->GetXmin(),
						       Data_Pass->GetXaxis()->GetXmax());

  TH1F* VLooseDecayMode10LowJetDistribution = new TH1F("VLooseDecayMode10LowJetDistribution","VLooseDecayMode10LowJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* LooseDecayMode10LowJetDistribution = new TH1F("LooseDecayMode10LowJetDistribution","LooseDecayMode10LowJetDistribution",
						     Data_Pass->GetSize()-2,
						     Data_Pass->GetXaxis()->GetXmin(),
						     Data_Pass->GetXaxis()->GetXmax());
  TH1F* MediumDecayMode10LowJetDistribution = new TH1F("MediumDecayMode10LowJetDistribution","MediumDecayMode10LowJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* TightDecayMode10LowJetDistribution = new TH1F("TightDecayMode10LowJetDistribution","TightDecayMode10LowJetDistribution",
						     Data_Pass->GetSize()-2,
						     Data_Pass->GetXaxis()->GetXmin(),
						     Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightDecayMode10LowJetDistribution = new TH1F("VTightDecayMode10LowJetDistribution","VTightDecayMode10LowJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* VVTightDecayMode10LowJetDistribution = new TH1F("VVTightDecayMode10LowJetDistribution","VVTightDecayMode10LowJetDistribution",
						       Data_Pass->GetSize()-2,
						       Data_Pass->GetXaxis()->GetXmin(),
						       Data_Pass->GetXaxis()->GetXmax());

  //This forms the high end of our shape uncertainty
  TH1F* VLooseDecayMode0HighJetDistribution = new TH1F("VLooseDecayMode0HighJetDistribution","VLooseDecayMode0HighJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* LooseDecayMode0HighJetDistribution = new TH1F("LooseDecayMode0HighJetDistribution","LooseDecayMode0HighJetDistribution",
						     Data_Pass->GetSize()-2,
						     Data_Pass->GetXaxis()->GetXmin(),
						     Data_Pass->GetXaxis()->GetXmax());
  TH1F* MediumDecayMode0HighJetDistribution = new TH1F("MediumDecayMode0HighJetDistribution","MediumDecayMode0HighJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* TightDecayMode0HighJetDistribution = new TH1F("TightDecayMode0HighJetDistribution","TightDecayMode0HighJetDistribution",
						     Data_Pass->GetSize()-2,
						     Data_Pass->GetXaxis()->GetXmin(),
						     Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightDecayMode0HighJetDistribution = new TH1F("VTightDecayMode0HighJetDistribution","VTightDecayMode0HighJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* VVTightDecayMode0HighJetDistribution = new TH1F("VVTightDecayMode0HighJetDistribution","VVTightDecayMode0HighJetDistribution",
						       Data_Pass->GetSize()-2,
						       Data_Pass->GetXaxis()->GetXmin(),
						       Data_Pass->GetXaxis()->GetXmax());

  TH1F* VLooseDecayMode1HighJetDistribution = new TH1F("VLooseDecayMode1HighJetDistribution","VLooseDecayMode1HighJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* LooseDecayMode1HighJetDistribution = new TH1F("LooseDecayMode1HighJetDistribution","LooseDecayMode1HighJetDistribution",
						     Data_Pass->GetSize()-2,
						     Data_Pass->GetXaxis()->GetXmin(),
						     Data_Pass->GetXaxis()->GetXmax());
  TH1F* MediumDecayMode1HighJetDistribution = new TH1F("MediumDecayMode1HighJetDistribution","MediumDecayMode1HighJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* TightDecayMode1HighJetDistribution = new TH1F("TightDecayMode1HighJetDistribution","TightDecayMode1HighJetDistribution",
						     Data_Pass->GetSize()-2,
						     Data_Pass->GetXaxis()->GetXmin(),
						     Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightDecayMode1HighJetDistribution = new TH1F("VTightDecayMode1HighJetDistribution","VTightDecayMode1HighJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* VVTightDecayMode1HighJetDistribution = new TH1F("VVTightDecayMode1HighJetDistribution","VVTightDecayMode1HighJetDistribution",
						       Data_Pass->GetSize()-2,
						       Data_Pass->GetXaxis()->GetXmin(),
						       Data_Pass->GetXaxis()->GetXmax());

  TH1F* VLooseDecayMode10HighJetDistribution = new TH1F("VLooseDecayMode10HighJetDistribution","VLooseDecayMode10HighJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* LooseDecayMode10HighJetDistribution = new TH1F("LooseDecayMode10HighJetDistribution","LooseDecayMode10HighJetDistribution",
						     Data_Pass->GetSize()-2,
						     Data_Pass->GetXaxis()->GetXmin(),
						     Data_Pass->GetXaxis()->GetXmax());
  TH1F* MediumDecayMode10HighJetDistribution = new TH1F("MediumDecayMode10HighJetDistribution","MediumDecayMode10HighJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* TightDecayMode10HighJetDistribution = new TH1F("TightDecayMode10HighJetDistribution","TightDecayMode10HighJetDistribution",
						     Data_Pass->GetSize()-2,
						     Data_Pass->GetXaxis()->GetXmin(),
						     Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightDecayMode10HighJetDistribution = new TH1F("VTightDecayMode10HighJetDistribution","VTightDecayMode10HighJetDistribution",
						      Data_Pass->GetSize()-2,
						      Data_Pass->GetXaxis()->GetXmin(),
						      Data_Pass->GetXaxis()->GetXmax());
  TH1F* VVTightDecayMode10HighJetDistribution = new TH1F("VVTightDecayMode10HighJetDistribution","VVTightDecayMode10HighJetDistribution",
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
      float DeltaR = l1.DeltaR(l2);
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
      //float Var = l2.Eta();
      //float Var = l1.Eta();
      //float Var = l1.Pt();
      //float Var = l2.Pt();
      //float Var = npv;
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
	      if(l2_decayMode == 0)
		{		  
		  PTFakeRate = VLooseDecayMode0PTFakeRates->GetBinContent(VLooseDecayMode0PTFakeRates->FindBin(l2.Pt()));		  
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  VLoosePTFRJetDistribution->Fill(Var,PTWeighting);

		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0VLooseFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 0 up/down distributions with the exagerations
		  VLooseDecayMode0LowJetDistribution->Fill(Var,DecayMode0VLooseFakeRate/(1.0-DecayMode0VLooseFakeRate));
		  VLooseDecayMode0HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  VLooseDecayMode1LowJetDistribution->Fill(Var,PTWeighting);
		  VLooseDecayMode10LowJetDistribution->Fill(Var,PTWeighting);
		  VLooseDecayMode1HighJetDistribution->Fill(Var,PTWeighting);
		  VLooseDecayMode10HighJetDistribution->Fill(Var,PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{		  
		  PTFakeRate = VLooseDecayMode1PTFakeRates->GetBinContent(VLooseDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  VLoosePTFRJetDistribution->Fill(Var,PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1VLooseFakeRate);		  
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 1 up/down distributions with the exagerations
		  VLooseDecayMode1LowJetDistribution->Fill(Var,DecayMode1VLooseFakeRate/(1.0-DecayMode1VLooseFakeRate));
		  VLooseDecayMode1HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  VLooseDecayMode0LowJetDistribution->Fill(Var,PTWeighting);
		  VLooseDecayMode10LowJetDistribution->Fill(Var,PTWeighting);
		  VLooseDecayMode0HighJetDistribution->Fill(Var,PTWeighting);
		  VLooseDecayMode10HighJetDistribution->Fill(Var,PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  PTFakeRate = VLooseDecayMode10PTFakeRates->GetBinContent(VLooseDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  VLoosePTFRJetDistribution->Fill(Var,PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10VLooseFakeRate);		  
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 10 up/down distributions with the exagerations
		  VLooseDecayMode10LowJetDistribution->Fill(Var,DecayMode1VLooseFakeRate/(1.0-DecayMode1VLooseFakeRate));
		  VLooseDecayMode10HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  VLooseDecayMode0LowJetDistribution->Fill(Var,PTWeighting);
		  VLooseDecayMode1LowJetDistribution->Fill(Var,PTWeighting);
		  VLooseDecayMode0HighJetDistribution->Fill(Var,PTWeighting);
		  VLooseDecayMode1HighJetDistribution->Fill(Var,PTWeighting);
		}	      	      
	    }
	  
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byLooseIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	      
	      if(l2_decayMode == 0)
		{		  
		  PTFakeRate = LooseDecayMode0PTFakeRates->GetBinContent(LooseDecayMode0PTFakeRates->FindBin(l2.Pt()));		  
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  LoosePTFRJetDistribution->Fill(Var,PTWeighting);

		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0LooseFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 0 up/down distributions with the exagerations
		  LooseDecayMode0LowJetDistribution->Fill(Var,DecayMode0LooseFakeRate/(1.0-DecayMode0LooseFakeRate));
		  LooseDecayMode0HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  LooseDecayMode1LowJetDistribution->Fill(Var,PTWeighting);
		  LooseDecayMode10LowJetDistribution->Fill(Var,PTWeighting);
		  LooseDecayMode1HighJetDistribution->Fill(Var,PTWeighting);
		  LooseDecayMode10HighJetDistribution->Fill(Var,PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{		  
		  PTFakeRate = LooseDecayMode1PTFakeRates->GetBinContent(LooseDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  LoosePTFRJetDistribution->Fill(Var,PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1LooseFakeRate);		  
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 1 up/down distributions with the exagerations
		  LooseDecayMode1LowJetDistribution->Fill(Var,DecayMode1LooseFakeRate/(1.0-DecayMode1LooseFakeRate));
		  LooseDecayMode1HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  LooseDecayMode0LowJetDistribution->Fill(Var,PTWeighting);
		  LooseDecayMode10LowJetDistribution->Fill(Var,PTWeighting);
		  LooseDecayMode0HighJetDistribution->Fill(Var,PTWeighting);
		  LooseDecayMode10HighJetDistribution->Fill(Var,PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  PTFakeRate = LooseDecayMode10PTFakeRates->GetBinContent(LooseDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  LoosePTFRJetDistribution->Fill(Var,PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10LooseFakeRate);		  
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 10 up/down distributions with the exagerations
		  LooseDecayMode10LowJetDistribution->Fill(Var,DecayMode1LooseFakeRate/(1.0-DecayMode1LooseFakeRate));
		  LooseDecayMode10HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  LooseDecayMode0LowJetDistribution->Fill(Var,PTWeighting);
		  LooseDecayMode1LowJetDistribution->Fill(Var,PTWeighting);
		  LooseDecayMode0HighJetDistribution->Fill(Var,PTWeighting);
		  LooseDecayMode1HighJetDistribution->Fill(Var,PTWeighting);
		}	      	      
	    }

	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byMediumIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      if(l2_decayMode == 0)
		{		  
		  PTFakeRate = MediumDecayMode0PTFakeRates->GetBinContent(MediumDecayMode0PTFakeRates->FindBin(l2.Pt()));		  
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  MediumPTFRJetDistribution->Fill(Var,PTWeighting);

		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0MediumFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 0 up/down distributions with the exagerations
		  MediumDecayMode0LowJetDistribution->Fill(Var,DecayMode0MediumFakeRate/(1.0-DecayMode0MediumFakeRate));
		  MediumDecayMode0HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  MediumDecayMode1LowJetDistribution->Fill(Var,PTWeighting);
		  MediumDecayMode10LowJetDistribution->Fill(Var,PTWeighting);
		  MediumDecayMode1HighJetDistribution->Fill(Var,PTWeighting);
		  MediumDecayMode10HighJetDistribution->Fill(Var,PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{		  
		  PTFakeRate = MediumDecayMode1PTFakeRates->GetBinContent(MediumDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  MediumPTFRJetDistribution->Fill(Var,PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1MediumFakeRate);		  
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 1 up/down distributions with the exagerations
		  MediumDecayMode1LowJetDistribution->Fill(Var,DecayMode1MediumFakeRate/(1.0-DecayMode1MediumFakeRate));
		  MediumDecayMode1HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  MediumDecayMode0LowJetDistribution->Fill(Var,PTWeighting);
		  MediumDecayMode10LowJetDistribution->Fill(Var,PTWeighting);
		  MediumDecayMode0HighJetDistribution->Fill(Var,PTWeighting);
		  MediumDecayMode10HighJetDistribution->Fill(Var,PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  PTFakeRate = MediumDecayMode10PTFakeRates->GetBinContent(MediumDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  MediumPTFRJetDistribution->Fill(Var,PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10MediumFakeRate);		  
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 10 up/down distributions with the exagerations
		  MediumDecayMode10LowJetDistribution->Fill(Var,DecayMode1MediumFakeRate/(1.0-DecayMode1MediumFakeRate));
		  MediumDecayMode10HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  MediumDecayMode0LowJetDistribution->Fill(Var,PTWeighting);
		  MediumDecayMode1LowJetDistribution->Fill(Var,PTWeighting);
		  MediumDecayMode0HighJetDistribution->Fill(Var,PTWeighting);
		  MediumDecayMode1HighJetDistribution->Fill(Var,PTWeighting);
		}	      	      
	    }

	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      if(l2_decayMode == 0)
		{		  
		  PTFakeRate = TightDecayMode0PTFakeRates->GetBinContent(TightDecayMode0PTFakeRates->FindBin(l2.Pt()));		  
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  TightPTFRJetDistribution->Fill(Var,PTWeighting);

		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0TightFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 0 up/down distributions with the exagerations
		  TightDecayMode0LowJetDistribution->Fill(Var,DecayMode0TightFakeRate/(1.0-DecayMode0TightFakeRate));
		  TightDecayMode0HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  TightDecayMode1LowJetDistribution->Fill(Var,PTWeighting);
		  TightDecayMode10LowJetDistribution->Fill(Var,PTWeighting);
		  TightDecayMode1HighJetDistribution->Fill(Var,PTWeighting);
		  TightDecayMode10HighJetDistribution->Fill(Var,PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{		  
		  PTFakeRate = TightDecayMode1PTFakeRates->GetBinContent(TightDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  TightPTFRJetDistribution->Fill(Var,PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1TightFakeRate);		  
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 1 up/down distributions with the exagerations
		  TightDecayMode1LowJetDistribution->Fill(Var,DecayMode1TightFakeRate/(1.0-DecayMode1TightFakeRate));
		  TightDecayMode1HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  TightDecayMode0LowJetDistribution->Fill(Var,PTWeighting);
		  TightDecayMode10LowJetDistribution->Fill(Var,PTWeighting);
		  TightDecayMode0HighJetDistribution->Fill(Var,PTWeighting);
		  TightDecayMode10HighJetDistribution->Fill(Var,PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  PTFakeRate = TightDecayMode10PTFakeRates->GetBinContent(TightDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  TightPTFRJetDistribution->Fill(Var,PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10TightFakeRate);		  
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 10 up/down distributions with the exagerations
		  TightDecayMode10LowJetDistribution->Fill(Var,DecayMode1TightFakeRate/(1.0-DecayMode1TightFakeRate));
		  TightDecayMode10HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  TightDecayMode0LowJetDistribution->Fill(Var,PTWeighting);
		  TightDecayMode1LowJetDistribution->Fill(Var,PTWeighting);
		  TightDecayMode0HighJetDistribution->Fill(Var,PTWeighting);
		  TightDecayMode1HighJetDistribution->Fill(Var,PTWeighting);
		}	      	      
	    }

	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	
	      if(l2_decayMode == 0)
		{		  
		  PTFakeRate = VTightDecayMode0PTFakeRates->GetBinContent(VTightDecayMode0PTFakeRates->FindBin(l2.Pt()));		  
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  VTightPTFRJetDistribution->Fill(Var,PTWeighting);

		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0VTightFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 0 up/down distributions with the exagerations
		  VTightDecayMode0LowJetDistribution->Fill(Var,DecayMode0VTightFakeRate/(1.0-DecayMode0VTightFakeRate));
		  VTightDecayMode0HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  VTightDecayMode1LowJetDistribution->Fill(Var,PTWeighting);
		  VTightDecayMode10LowJetDistribution->Fill(Var,PTWeighting);
		  VTightDecayMode1HighJetDistribution->Fill(Var,PTWeighting);
		  VTightDecayMode10HighJetDistribution->Fill(Var,PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{		  
		  PTFakeRate = VTightDecayMode1PTFakeRates->GetBinContent(VTightDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  VTightPTFRJetDistribution->Fill(Var,PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1VTightFakeRate);		  
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 1 up/down distributions with the exagerations
		  VTightDecayMode1LowJetDistribution->Fill(Var,DecayMode1VTightFakeRate/(1.0-DecayMode1VTightFakeRate));
		  VTightDecayMode1HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  VTightDecayMode0LowJetDistribution->Fill(Var,PTWeighting);
		  VTightDecayMode10LowJetDistribution->Fill(Var,PTWeighting);
		  VTightDecayMode0HighJetDistribution->Fill(Var,PTWeighting);
		  VTightDecayMode10HighJetDistribution->Fill(Var,PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  PTFakeRate = VTightDecayMode10PTFakeRates->GetBinContent(VTightDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  VTightPTFRJetDistribution->Fill(Var,PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10VTightFakeRate);		  
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 10 up/down distributions with the exagerations
		  VTightDecayMode10LowJetDistribution->Fill(Var,DecayMode1VTightFakeRate/(1.0-DecayMode1VTightFakeRate));
		  VTightDecayMode10HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  VTightDecayMode0LowJetDistribution->Fill(Var,PTWeighting);
		  VTightDecayMode1LowJetDistribution->Fill(Var,PTWeighting);
		  VTightDecayMode0HighJetDistribution->Fill(Var,PTWeighting);
		  VTightDecayMode1HighJetDistribution->Fill(Var,PTWeighting);
		}	      	      
	    }

	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	
	      if(l2_decayMode == 0)
		{		  
		  PTFakeRate = VVTightDecayMode0PTFakeRates->GetBinContent(VVTightDecayMode0PTFakeRates->FindBin(l2.Pt()));		  
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  VVTightPTFRJetDistribution->Fill(Var,PTWeighting);

		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0VVTightFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 0 up/down distributions with the exagerations
		  VVTightDecayMode0LowJetDistribution->Fill(Var,DecayMode0VVTightFakeRate/(1.0-DecayMode0VVTightFakeRate));
		  VVTightDecayMode0HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  VVTightDecayMode1LowJetDistribution->Fill(Var,PTWeighting);
		  VVTightDecayMode10LowJetDistribution->Fill(Var,PTWeighting);
		  VVTightDecayMode1HighJetDistribution->Fill(Var,PTWeighting);
		  VVTightDecayMode10HighJetDistribution->Fill(Var,PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{		  
		  PTFakeRate = VVTightDecayMode1PTFakeRates->GetBinContent(VVTightDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  VVTightPTFRJetDistribution->Fill(Var,PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1VVTightFakeRate);		  
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 1 up/down distributions with the exagerations
		  VVTightDecayMode1LowJetDistribution->Fill(Var,DecayMode1VVTightFakeRate/(1.0-DecayMode1VVTightFakeRate));
		  VVTightDecayMode1HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  VVTightDecayMode0LowJetDistribution->Fill(Var,PTWeighting);
		  VVTightDecayMode10LowJetDistribution->Fill(Var,PTWeighting);
		  VVTightDecayMode0HighJetDistribution->Fill(Var,PTWeighting);
		  VVTightDecayMode10HighJetDistribution->Fill(Var,PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  PTFakeRate = VVTightDecayMode10PTFakeRates->GetBinContent(VVTightDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  
		  VVTightPTFRJetDistribution->Fill(Var,PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10VVTightFakeRate);		  
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);	      

		  //fill decay mode 10 up/down distributions with the exagerations
		  VVTightDecayMode10LowJetDistribution->Fill(Var,DecayMode1VVTightFakeRate/(1.0-DecayMode1VVTightFakeRate));
		  VVTightDecayMode10HighJetDistribution->Fill(Var,ExacerbatedWeighting);
		  //fill the other decay modes with nominals to keep up the normalizations
		  VVTightDecayMode0LowJetDistribution->Fill(Var,PTWeighting);
		  VVTightDecayMode1LowJetDistribution->Fill(Var,PTWeighting);
		  VVTightDecayMode0HighJetDistribution->Fill(Var,PTWeighting);
		  VVTightDecayMode1HighJetDistribution->Fill(Var,PTWeighting);
		}	      	      
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
  
  VLooseDecayMode0LowJetDistribution->Write();
  LooseDecayMode0LowJetDistribution->Write();
  MediumDecayMode0LowJetDistribution->Write();
  TightDecayMode0LowJetDistribution->Write();
  VTightDecayMode0LowJetDistribution->Write();
  VVTightDecayMode0LowJetDistribution->Write();  

  VLooseDecayMode1LowJetDistribution->Write();
  LooseDecayMode1LowJetDistribution->Write();
  MediumDecayMode1LowJetDistribution->Write();
  TightDecayMode1LowJetDistribution->Write();
  VTightDecayMode1LowJetDistribution->Write();
  VVTightDecayMode1LowJetDistribution->Write();  

  VLooseDecayMode10LowJetDistribution->Write();
  LooseDecayMode10LowJetDistribution->Write();
  MediumDecayMode10LowJetDistribution->Write();
  TightDecayMode10LowJetDistribution->Write();
  VTightDecayMode10LowJetDistribution->Write();
  VVTightDecayMode10LowJetDistribution->Write();  

  VLooseDecayMode0HighJetDistribution->Write();
  LooseDecayMode0HighJetDistribution->Write();
  MediumDecayMode0HighJetDistribution->Write();
  TightDecayMode0HighJetDistribution->Write();
  VTightDecayMode0HighJetDistribution->Write();
  VVTightDecayMode0HighJetDistribution->Write();  

  VLooseDecayMode1HighJetDistribution->Write();
  LooseDecayMode1HighJetDistribution->Write();
  MediumDecayMode1HighJetDistribution->Write();
  TightDecayMode1HighJetDistribution->Write();
  VTightDecayMode1HighJetDistribution->Write();
  VVTightDecayMode1HighJetDistribution->Write();  

  VLooseDecayMode10HighJetDistribution->Write();
  LooseDecayMode10HighJetDistribution->Write();
  MediumDecayMode10HighJetDistribution->Write();
  TightDecayMode10HighJetDistribution->Write();
  VTightDecayMode10HighJetDistribution->Write();
  VVTightDecayMode10HighJetDistribution->Write();  

  FakeRateDeterminedDistributions->Close();
}
