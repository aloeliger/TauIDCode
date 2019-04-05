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

void GenerateJetSamples(int PtBracket = 0, int EtaBracket = 0)
{
  TFile *MyFile = new TFile("/data/aloeliger/CMSSW_9_4_0/src/SMHTTAnalysis/SkimmedNtuples/TauID2017/Data.root");
  //TFile *MyFile = new TFile("/data/aloeliger/CMSSW_9_4_0/src/SMHTTAnalysis/SkimmedNtuples/OldTauID/Data.root");
  TTree *Tree = (TTree*) MyFile->Get("mutau_tree");
  
  UInt_t run,lumi;
  //Float_t run,lumi;
  Float_t evt,NUP;
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
  Float_t nbtag,njets;
  //Int_t nbtag,njets;
  //These are now precalculated in the ntuple
  float PZetaVis;
  float PZetaAll;
  float PZeta;
  float TransverseMass;

  // now we branch address these guys, and we can start running trees
  Tree->SetBranchAddress("run",&run);
  Tree->SetBranchAddress("lumi",&lumi);
  Tree->SetBranchAddress("evt",&evt);
  Tree->SetBranchAddress("NUP",&NUP);
  Tree->SetBranchAddress("npv",&npv);
  Tree->SetBranchAddress("npu",&npu);
  //Tree->SetBranchAddress("amcatNLO_weight",&amcatNLO_weight);
  Tree->SetBranchAddress("pt_1",&pt_1);
  Tree->SetBranchAddress("phi_1",&phi_1);
  Tree->SetBranchAddress("eta_1",&eta_1);
  Tree->SetBranchAddress("m_1",&m_1);
  //Tree->SetBranchAddress("e_1",&e_1);
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
  //Tree->SetBranchAddress("e_2",&e_2);
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
  //Tree->SetBranchAddress("byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_2",&byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_2);
  //Tree->SetBranchAddress("byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_2",&byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_2);
  //Tree->SetBranchAddress("byTightCombinedIsolationDeltaBetaCorr3HitsdR03_2",&byTightCombinedIsolationDeltaBetaCorr3HitsdR03_2);
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
  //Tree->SetBranchAddress("byIsolationMVA3oldDMwoLTraw_2",&byIsolationMVA3oldDMwoLTraw_2);
  //Tree->SetBranchAddress("byIsolationMVA3oldDMwLTraw_2",&byIsolationMVA3oldDMwLTraw_2);
  //Tree->SetBranchAddress("byIsolationMVA3newDMwoLTraw_2",&byIsolationMVA3newDMwoLTraw_2);
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
  //Tree->SetBranchAddress("chargedIsoPtSum_2",&chargedIsoPtSum_2);
  Tree->SetBranchAddress("decayModeFinding_2",&decayModeFinding_2);
  Tree->SetBranchAddress("decayModeFindingNewDMs_2",&decayModeFindingNewDMs_2);
  //Tree->SetBranchAddress("neutralIsoPtSum_2",&neutralIsoPtSum_2);
  //Tree->SetBranchAddress("puCorrPtSum_2",&puCorrPtSum_2);
  //Tree->SetBranchAddress("chargedIso_2",&chargedIso_2);
  //Tree->SetBranchAddress("neutralIso_2",&neutralIso_2);
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
  //Tree->SetBranchAddress("genweight",&genweight);
  Tree->SetBranchAddress("gen_match_2",&gen_match_2);
  Tree->SetBranchAddress("met",&met);
  Tree->SetBranchAddress("metphi",&metphi);
  Tree->SetBranchAddress("nbtag",&nbtag);
  Tree->SetBranchAddress("njets",&njets);
  Tree->SetBranchAddress("PZetaVis",&PZetaVis);
  Tree->SetBranchAddress("PZetaAll",&PZetaAll);
  Tree->SetBranchAddress("PZeta",&PZeta);
  Tree->SetBranchAddress("TransverseMass",&TransverseMass);

  int NumberOfEntries = (int) Tree->GetEntries();
  
  //Create the jet distributions
  //Do we want to open the pass fail master file and take a quick peek at 
  // one of the ata histos to make sure we can get accurate measurements on histogram size?
  TFile* PassFailFile = new TFile("../Distributions/PassFailOut.root");
  TH1F* Data_Pass = (TH1F*)((TDirectory*)PassFailFile->Get("pass"))->Get("Data_Pass");
  
  //PT reweighted histos
  //This forms our the basis of our jet histograms
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



  TFile* FakeRateFile = new TFile("../Distributions/FakeRateDistributions.root");
  //start with just the overall fake rates  
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
  //get the new barrel/endcap split decay modes
  //barrel
  TH1F* VLooseDecayMode0PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("VLooseDecayMode0PTBarrelFakeRates");
  TH1F* VLooseDecayMode1PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("VLooseDecayMode1PTBarrelFakeRates");
  TH1F* VLooseDecayMode10PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("VLooseDecayMode10PTBarrelFakeRates");

  TH1F* LooseDecayMode0PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("LooseDecayMode0PTBarrelFakeRates");
  TH1F* LooseDecayMode1PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("LooseDecayMode1PTBarrelFakeRates");
  TH1F* LooseDecayMode10PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("LooseDecayMode10PTBarrelFakeRates");

  TH1F* MediumDecayMode0PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("MediumDecayMode0PTBarrelFakeRates");
  TH1F* MediumDecayMode1PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("MediumDecayMode1PTBarrelFakeRates");
  TH1F* MediumDecayMode10PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("MediumDecayMode10PTBarrelFakeRates");

  TH1F* TightDecayMode0PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("TightDecayMode0PTBarrelFakeRates");
  TH1F* TightDecayMode1PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("TightDecayMode1PTBarrelFakeRates");
  TH1F* TightDecayMode10PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("TightDecayMode10PTBarrelFakeRates");

  TH1F* VTightDecayMode0PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("VTightDecayMode0PTBarrelFakeRates");
  TH1F* VTightDecayMode1PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("VTightDecayMode1PTBarrelFakeRates");
  TH1F* VTightDecayMode10PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("VTightDecayMode10PTBarrelFakeRates");

  TH1F* VVTightDecayMode0PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("VVTightDecayMode0PTBarrelFakeRates");
  TH1F* VVTightDecayMode1PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("VVTightDecayMode1PTBarrelFakeRates");
  TH1F* VVTightDecayMode10PTBarrelFakeRates = (TH1F*)FakeRateFile->Get("VVTightDecayMode10PTBarrelFakeRates");

  //endcap
  TH1F* VLooseDecayMode0PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("VLooseDecayMode0PTEndcapFakeRates");
  TH1F* VLooseDecayMode1PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("VLooseDecayMode1PTEndcapFakeRates");
  TH1F* VLooseDecayMode10PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("VLooseDecayMode10PTEndcapFakeRates");

  TH1F* LooseDecayMode0PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("LooseDecayMode0PTEndcapFakeRates");
  TH1F* LooseDecayMode1PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("LooseDecayMode1PTEndcapFakeRates");
  TH1F* LooseDecayMode10PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("LooseDecayMode10PTEndcapFakeRates");

  TH1F* MediumDecayMode0PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("MediumDecayMode0PTEndcapFakeRates");
  TH1F* MediumDecayMode1PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("MediumDecayMode1PTEndcapFakeRates");
  TH1F* MediumDecayMode10PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("MediumDecayMode10PTEndcapFakeRates");

  TH1F* TightDecayMode0PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("TightDecayMode0PTEndcapFakeRates");
  TH1F* TightDecayMode1PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("TightDecayMode1PTEndcapFakeRates");
  TH1F* TightDecayMode10PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("TightDecayMode10PTEndcapFakeRates");

  TH1F* VTightDecayMode0PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("VTightDecayMode0PTEndcapFakeRates");
  TH1F* VTightDecayMode1PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("VTightDecayMode1PTEndcapFakeRates");
  TH1F* VTightDecayMode10PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("VTightDecayMode10PTEndcapFakeRates");

  TH1F* VVTightDecayMode0PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("VVTightDecayMode0PTEndcapFakeRates");
  TH1F* VVTightDecayMode1PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("VVTightDecayMode1PTEndcapFakeRates");
  TH1F* VVTightDecayMode10PTEndcapFakeRates = (TH1F*)FakeRateFile->Get("VVTightDecayMode10PTEndcapFakeRates");

  //add in control plots
  //VLoose
  TH1F* VLoose_MuPt = new TH1F("Jet_VLoose_MuPt",
			       "Jet_VLoose_MuPt",
			       100,
			       0.0,
			       200.0);
  
  TH1F* VLoose_TauPt = new TH1F("Jet_VLoose_TauPt",
				"Jet_VLoose_TauPt",
				100,
				0.0,
				200.0);
  
  TH1F* VLoose_MuEta = new TH1F("Jet_VLoose_MuEta",
				"Jet_VLoose_MuEta",
				100,
				-4.0,
				4.0);
  
  TH1F* VLoose_TauEta = new TH1F("Jet_VLoose_TauEta",
				 "Jet_VLoose_TauEta",
				 100,
				 -4.0,
				 4.0);
  
  TH1F* VLoose_NJets = new TH1F("Jet_VLoose_njets",
				"Jet_VLoose_njets",
				5,
				0.0,
				5.0);
  
  TH1F* VLoose_NBtag = new TH1F("Jet_VLoose_nbtag",
				"Jet_VLoose_nbtag",
				5,
				0.0,
				5.0);
  
  TH1F* VLoose_ZMass = new TH1F("Jet_VLoose_ZMass",
				"Jet_VLoose_ZMass",
				100,
				0.0,
				200.0);
  
  TH1F* VLoose_ZPT = new TH1F("Jet_VLoose_ZPT",
			      "Jet_VLoose_ZPT",
			      100,
			      0.0,
			      500.0);
  TH1F* VLoose_MT = new TH1F("Jet_VLoose_MT",
			     "Jet_VLoose_MT",
			     100,
			     0.0,
			     200.0);
  //Loose
  TH1F* Loose_MuPt = new TH1F("Jet_Loose_MuPt",
			      "Jet_Loose_MuPt",
			       100,
			       0.0,
			       200.0);
  
  TH1F* Loose_TauPt = new TH1F("Jet_Loose_TauPt",
			       "Jet_Loose_TauPt",
				100,
				0.0,
				200.0);
  
  TH1F* Loose_MuEta = new TH1F("Jet_Loose_MuEta",
			       "Jet_Loose_MuEta",
				100,
				-4.0,
				4.0);
  
  TH1F* Loose_TauEta = new TH1F("Jet_Loose_TauEta",
				"Jet_Loose_TauEta",
				 100,
				 -4.0,
				 4.0);
  
  TH1F* Loose_NJets = new TH1F("Jet_Loose_njets",
			       "Jet_Loose_njets",
				5,
				0.0,
				5.0);
  
  TH1F* Loose_NBtag = new TH1F("Jet_Loose_nbtag",
			       "Jet_Loose_nbtag",
				5,
				0.0,
				5.0);
  
  TH1F* Loose_ZMass = new TH1F("Jet_Loose_ZMass",
			       "Jet_Loose_ZMass",
				100,
				0.0,
				200.0);
  
  TH1F* Loose_ZPT = new TH1F("Jet_Loose_ZPT",
			     "Jet_Loose_ZPT",
			      100,
			      0.0,
			      500.0);
  TH1F* Loose_MT = new TH1F("Jet_Loose_MT",
			    "Jet_Loose_MT",
			     100,
			     0.0,
			     200.0);
  //Medium
  TH1F* Medium_MuPt = new TH1F("Jet_Medium_MuPt",
			       "Jet_Medium_MuPt",
			       100,
			       0.0,
			       200.0);
  
  TH1F* Medium_TauPt = new TH1F("Jet_Medium_TauPt",
				"Jet_Medium_TauPt",
				100,
				0.0,
				200.0);
  
  TH1F* Medium_MuEta = new TH1F("Jet_Medium_MuEta",
				"Jet_Medium_MuEta",
				100,
				-4.0,
				4.0);
  
  TH1F* Medium_TauEta = new TH1F("Jet_Medium_TauEta",
				 "Jet_Medium_TauEta",
				 100,
				 -4.0,
				 4.0);
  
  TH1F* Medium_NJets = new TH1F("Jet_Medium_njets",
				"Jet_Medium_njets",
				5,
				0.0,
				5.0);
  
  TH1F* Medium_NBtag = new TH1F("Jet_Medium_nbtag",
				"Jet_Medium_nbtag",
				5,
				0.0,
				5.0);
  
  TH1F* Medium_ZMass = new TH1F("Jet_Medium_ZMass",
				"Jet_Medium_ZMass",
				100,
				0.0,
				200.0);
  
  TH1F* Medium_ZPT = new TH1F("Jet_Medium_ZPT",
			      "Jet_Medium_ZPT",
			      100,
			      0.0,
			      500.0);
  TH1F* Medium_MT = new TH1F("Jet_Medium_MT",
			     "Jet_Medium_MT",
			     100,
			     0.0,
			     200.0);
  //Tight
  TH1F* Tight_MuPt = new TH1F("Jet_Tight_MuPt",
			      "Jet_Tight_MuPt",
			       100,
			       0.0,
			       200.0);
  
  TH1F* Tight_TauPt = new TH1F("Jet_Tight_TauPt",
			       "Jet_Tight_TauPt",
				100,
				0.0,
				200.0);
  
  TH1F* Tight_MuEta = new TH1F("Jet_Tight_MuEta",
			       "Jet_Tight_MuEta",
				100,
				-4.0,
				4.0);
  
  TH1F* Tight_TauEta = new TH1F("Jet_Tight_TauEta",
				"Jet_Tight_TauEta",
				 100,
				 -4.0,
				 4.0);
  
  TH1F* Tight_NJets = new TH1F("Jet_Tight_njets",
			       "Jet_Tight_njets",
				5,
				0.0,
				5.0);
  
  TH1F* Tight_NBtag = new TH1F("Jet_Tight_nbtag",
			       "Jet_Tight_nbtag",
				5,
				0.0,
				5.0);
  
  TH1F* Tight_ZMass = new TH1F("Jet_Tight_ZMass",
			       "Jet_Tight_ZMass",
				100,
				0.0,
				200.0);
  
  TH1F* Tight_ZPT = new TH1F("Jet_Tight_ZPT",
			     "Jet_Tight_ZPT",
			      100,
			      0.0,
			      500.0);
  TH1F* Tight_MT = new TH1F("Jet_Tight_MT",
			    "Jet_Tight_MT",
			     100,
			     0.0,
			     200.0);
  //VTight
  TH1F* VTight_MuPt = new TH1F("Jet_VTight_MuPt",
			       "Jet_VTight_MuPt",
			       100,
			       0.0,
			       200.0);
  
  TH1F* VTight_TauPt = new TH1F("Jet_VTight_TauPt",
				"Jet_VTight_TauPt",
				100,
				0.0,
				200.0);
  
  TH1F* VTight_MuEta = new TH1F("Jet_VTight_MuEta",
				"Jet_VTight_MuEta",
				100,
				-4.0,
				4.0);
  
  TH1F* VTight_TauEta = new TH1F("Jet_VTight_TauEta",
				 "Jet_VTight_TauEta",
				 100,
				 -4.0,
				 4.0);
  
  TH1F* VTight_NJets = new TH1F("Jet_VTight_njets",
				"Jet_VTight_njets",
				5,
				0.0,
				5.0);
  
  TH1F* VTight_NBtag = new TH1F("Jet_VTight_nbtag",
				"Jet_VTight_nbtag",
				5,
				0.0,
				5.0);
  
  TH1F* VTight_ZMass = new TH1F("Jet_VTight_ZMass",
				"Jet_VTight_ZMass",
				100,
				0.0,
				200.0);
  
  TH1F* VTight_ZPT = new TH1F("Jet_VTight_ZPT",
			      "Jet_VTight_ZPT",
			      100,
			      0.0,
			      500.0);
  TH1F* VTight_MT = new TH1F("Jet_VTight_MT",
			     "Jet_VTight_MT",
			     100,
			     0.0,
			     200.0);
  //VVTight
  TH1F* VVTight_MuPt = new TH1F("Jet_VVTight_MuPt",
				"Jet_VVTight_MuPt",
			       100,
			       0.0,
			       200.0);
  
  TH1F* VVTight_TauPt = new TH1F("Jet_VVTight_TauPt",
				 "Jet_VVTight_TauPt",
				100,
				0.0,
				200.0);
  
  TH1F* VVTight_MuEta = new TH1F("Jet_VVTight_MuEta",
				 "Jet_VVTight_MuEta",
				100,
				-4.0,
				4.0);
  
  TH1F* VVTight_TauEta = new TH1F("Jet_VVTight_TauEta",
				  "Jet_VVTight_TauEta",
				 100,
				 -4.0,
				 4.0);
  
  TH1F* VVTight_NJets = new TH1F("Jet_VVTight_njets",
				 "Jet_VVTight_njets",
				5,
				0.0,
				5.0);
  
  TH1F* VVTight_NBtag = new TH1F("Jet_VVTight_nbtag",
				 "Jet_VVTight_nbtag",
				5,
				0.0,
				5.0);
  
  TH1F* VVTight_ZMass = new TH1F("Jet_VVTight_ZMass",
				 "Jet_VVTight_ZMass",
				100,
				0.0,
				200.0);
  
  TH1F* VVTight_ZPT = new TH1F("Jet_VVTight_ZPT",
			       "Jet_VVTight_ZPT",
			      100,
			      0.0,
			      500.0);
  TH1F* VVTight_MT = new TH1F("Jet_VVTight_MT",
			      "Jet_VVTight_MT",
			      100,
			      0.0,
			      200.0);

  //Same Sign Control Plots  
  //VLoose
  TH1F* VLoose_MuPt_SS = new TH1F("Jet_VLoose_MuPt_SS",
				  "Jet_VLoose_MuPt_SS",
				  100,
				  0.0,
				  200.0);
  
  TH1F* VLoose_TauPt_SS = new TH1F("Jet_VLoose_TauPt_SS",
				   "Jet_VLoose_TauPt_SS",
				   100,
				   0.0,
				   200.0);
  
  TH1F* VLoose_MuEta_SS = new TH1F("Jet_VLoose_MuEta_SS",
				   "Jet_VLoose_MuEta_SS",
				   100,
				   -4.0,
				   4.0);
  
  TH1F* VLoose_TauEta_SS = new TH1F("Jet_VLoose_TauEta_SS",
				    "Jet_VLoose_TauEta_SS",
				    100,
				    -4.0,
				    4.0);
  
  TH1F* VLoose_NJets_SS = new TH1F("Jet_VLoose_njets_SS",
				   "Jet_VLoose_njets_SS",
				   5,
				   0.0,
				   5.0);
  
  TH1F* VLoose_NBtag_SS = new TH1F("Jet_VLoose_nbtag_SS",
				   "Jet_VLoose_nbtag_SS",
				   5,
				   0.0,
				   5.0);
  
  TH1F* VLoose_ZMass_SS = new TH1F("Jet_VLoose_ZMass_SS",
				   "Jet_VLoose_ZMass_SS",
				   100,
				   0.0,
				   200.0);
  
  TH1F* VLoose_ZPT_SS = new TH1F("Jet_VLoose_ZPT_SS",
				 "Jet_VLoose_ZPT_SS",
				 100,
				 0.0,
				 500.0);
  TH1F* VLoose_MT_SS = new TH1F("Jet_VLoose_MT_SS",
				"Jet_VLoose_MT_SS",
				100,
				0.0,
				200.0);
  //Loose
  TH1F* Loose_MuPt_SS = new TH1F("Jet_Loose_MuPt_SS",
				 "Jet_Loose_MuPt_SS",
				 100,
				 0.0,
				 200.0);
  
  TH1F* Loose_TauPt_SS = new TH1F("Jet_Loose_TauPt_SS",
				  "Jet_Loose_TauPt_SS",
				  100,
				  0.0,
				  200.0);
  
  TH1F* Loose_MuEta_SS = new TH1F("Jet_Loose_MuEta_SS",
				  "Jet_Loose_MuEta_SS",
				  100,
				  -4.0,
				  4.0);
  
  TH1F* Loose_TauEta_SS = new TH1F("Jet_Loose_TauEta_SS",
				   "Jet_Loose_TauEta_SS",
				   100,
				   -4.0,
				   4.0);
  
  TH1F* Loose_NJets_SS = new TH1F("Jet_Loose_njets_SS",
				  "Jet_Loose_njets_SS",
				  5,
				  0.0,
				  5.0);
  
  TH1F* Loose_NBtag_SS = new TH1F("Jet_Loose_nbtag_SS",
				  "Jet_Loose_nbtag_SS",
				  5,
				  0.0,
				  5.0);
  
  TH1F* Loose_ZMass_SS = new TH1F("Jet_Loose_ZMass_SS",
				  "Jet_Loose_ZMass_SS",
				  100,
				  0.0,
				  200.0);
  
  TH1F* Loose_ZPT_SS = new TH1F("Jet_Loose_ZPT_SS",
				"Jet_Loose_ZPT_SS",
				100,
				0.0,
				500.0);
  TH1F* Loose_MT_SS = new TH1F("Jet_Loose_MT_SS",
			       "Jet_Loose_MT_SS",
			       100,
			       0.0,
			       200.0);
  //Medium
  TH1F* Medium_MuPt_SS = new TH1F("Jet_Medium_MuPt_SS",
				  "Jet_Medium_MuPt_SS",
				  100,
				  0.0,
				  200.0);
  
  TH1F* Medium_TauPt_SS = new TH1F("Jet_Medium_TauPt_SS",
				   "Jet_Medium_TauPt_SS",
				   100,
				   0.0,
				   200.0);
  
  TH1F* Medium_MuEta_SS = new TH1F("Jet_Medium_MuEta_SS",
				   "Jet_Medium_MuEta_SS",
				   100,
				   -4.0,
				   4.0);
  
  TH1F* Medium_TauEta_SS = new TH1F("Jet_Medium_TauEta_SS",
				    "Jet_Medium_TauEta_SS",
				    100,
				    -4.0,
				    4.0);
  
  TH1F* Medium_NJets_SS = new TH1F("Jet_Medium_njets_SS",
				   "Jet_Medium_njets_SS",
				   5,
				   0.0,
				   5.0);
  
  TH1F* Medium_NBtag_SS = new TH1F("Jet_Medium_nbtag_SS",
				   "Jet_Medium_nbtag_SS",
				   5,
				   0.0,
				   5.0);
  
  TH1F* Medium_ZMass_SS = new TH1F("Jet_Medium_ZMass_SS",
				   "Jet_Medium_ZMass_SS",
				   100,
				   0.0,
				   200.0);
  
  TH1F* Medium_ZPT_SS = new TH1F("Jet_Medium_ZPT_SS",
				 "Jet_Medium_ZPT_SS",
				 100,
				 0.0,
				 500.0);
  TH1F* Medium_MT_SS = new TH1F("Jet_Medium_MT_SS",
				"Jet_Medium_MT_SS",
				100,
				0.0,
				200.0);
  //Tight
  TH1F* Tight_MuPt_SS = new TH1F("Jet_Tight_MuPt_SS",
				 "Jet_Tight_MuPt_SS",
				 100,
				 0.0,
				 200.0);
  
  TH1F* Tight_TauPt_SS = new TH1F("Jet_Tight_TauPt_SS",
				  "Jet_Tight_TauPt_SS",
				  100,
				  0.0,
				  200.0);
  
  TH1F* Tight_MuEta_SS = new TH1F("Jet_Tight_MuEta_SS",
				  "Jet_Tight_MuEta_SS",
				  100,
				  -4.0,
				  4.0);
  
  TH1F* Tight_TauEta_SS = new TH1F("Jet_Tight_TauEta_SS",
				   "Jet_Tight_TauEta_SS",
				   100,
				   -4.0,
				   4.0);
  
  TH1F* Tight_NJets_SS = new TH1F("Jet_Tight_njets_SS",
				  "Jet_Tight_njets_SS",
				  5,
				  0.0,
				  5.0);
  
  TH1F* Tight_NBtag_SS = new TH1F("Jet_Tight_nbtag_SS",
				  "Jet_Tight_nbtag_SS",
				  5,
				  0.0,
				  5.0);
  
  TH1F* Tight_ZMass_SS = new TH1F("Jet_Tight_ZMass_SS",
				  "Jet_Tight_ZMass_SS",
				  100,
				  0.0,
				  200.0);
  
  TH1F* Tight_ZPT_SS = new TH1F("Jet_Tight_ZPT_SS",
				"Jet_Tight_ZPT_SS",
				100,
				0.0,
				500.0);
  TH1F* Tight_MT_SS = new TH1F("Jet_Tight_MT_SS",
			       "Jet_Tight_MT_SS",
			       100,
			       0.0,
			       200.0);
  //VTight
  TH1F* VTight_MuPt_SS = new TH1F("Jet_VTight_MuPt_SS",
				  "Jet_VTight_MuPt_SS",
				  100,
				  0.0,
				  200.0);
  
  TH1F* VTight_TauPt_SS = new TH1F("Jet_VTight_TauPt_SS",
				   "Jet_VTight_TauPt_SS",
				   100,
				   0.0,
				   200.0);
  
  TH1F* VTight_MuEta_SS = new TH1F("Jet_VTight_MuEta_SS",
				   "Jet_VTight_MuEta_SS",
				   100,
				   -4.0,
				   4.0);
  
  TH1F* VTight_TauEta_SS = new TH1F("Jet_VTight_TauEta_SS",
				    "Jet_VTight_TauEta_SS",
				    100,
				    -4.0,
				    4.0);
  
  TH1F* VTight_NJets_SS = new TH1F("Jet_VTight_njets_SS",
				   "Jet_VTight_njets_SS",
				   5,
				   0.0,
				   5.0);
  
  TH1F* VTight_NBtag_SS = new TH1F("Jet_VTight_nbtag_SS",
				   "Jet_VTight_nbtag_SS",
				   5,
				   0.0,
				   5.0);
  
  TH1F* VTight_ZMass_SS = new TH1F("Jet_VTight_ZMass_SS",
				   "Jet_VTight_ZMass_SS",
				   100,
				   0.0,
				   200.0);
  
  TH1F* VTight_ZPT_SS = new TH1F("Jet_VTight_ZPT_SS",
				 "Jet_VTight_ZPT_SS",
				 100,
				 0.0,
				 500.0);
  TH1F* VTight_MT_SS = new TH1F("Jet_VTight_MT_SS",
				"Jet_VTight_MT_SS",
				100,
				0.0,
				200.0);
  //VVTight
  TH1F* VVTight_MuPt_SS = new TH1F("Jet_VVTight_MuPt_SS",
				   "Jet_VVTight_MuPt_SS",
				   100,
				   0.0,
				   200.0);
  
  TH1F* VVTight_TauPt_SS = new TH1F("Jet_VVTight_TauPt_SS",
				    "Jet_VVTight_TauPt_SS",
				    100,
				    0.0,
				    200.0);
  
  TH1F* VVTight_MuEta_SS = new TH1F("Jet_VVTight_MuEta_SS",
				    "Jet_VVTight_MuEta_SS",
				    100,
				    -4.0,
				    4.0);
  
  TH1F* VVTight_TauEta_SS = new TH1F("Jet_VVTight_TauEta_SS",
				     "Jet_VVTight_TauEta_SS",
				     100,
				     -4.0,
				     4.0);
  
  TH1F* VVTight_NJets_SS = new TH1F("Jet_VVTight_njets_SS",
				    "Jet_VVTight_njets_SS",
				    5,
				    0.0,
				    5.0);
  
  TH1F* VVTight_NBtag_SS = new TH1F("Jet_VVTight_nbtag_SS",
				    "Jet_VVTight_nbtag_SS",
				    5,
				    0.0,
				    5.0);
  
  TH1F* VVTight_ZMass_SS = new TH1F("Jet_VVTight_ZMass_SS",
				    "Jet_VVTight_ZMass_SS",
				    100,
				    0.0,
				    200.0);
  
  TH1F* VVTight_ZPT_SS = new TH1F("Jet_VVTight_ZPT_SS",
				  "Jet_VVTight_ZPT_SS",
				  100,
				  0.0,
				  500.0);
  TH1F* VVTight_MT_SS = new TH1F("Jet_VVTight_MT_SS",
				 "Jet_VVTight_MT_SS",
				 100,
				 0.0,
				 200.0);
  //Andrew's super special secret controls used for developing corrections
  //MT 0-50
  TH1F* VLoose_MuPt_LowMT = new TH1F("Jet_VLoose_MuPt_LowMT",
				     "Jet_VLoose_MuPt_LowMT",
				     100,
				     0.0,
				     200.0);
  TH1F* VLoose_TauPt_LowMT = new TH1F("Jet_VLoose_TauPt_LowMT",
				      "Jet_VLoose_TauPt_LowMT",
				      100,
				      0.0,
				      200.0);
  TH1F* VLoose_MT_LowMT = new TH1F("Jet_VLoose_MT_LowMT",
				   "Jet_VLoose_MT_LowMT",
				   25,
				   0.0,
				   50.0);
  TH1F* Loose_MuPt_LowMT = new TH1F("Jet_Loose_MuPt_LowMT",
				    "Jet_Loose_MuPt_LowMT",
				    100,
				    0.0,
				    200.0);
  TH1F* Loose_TauPt_LowMT = new TH1F("Jet_Loose_TauPt_LowMT",
				     "Jet_Loose_TauPt_LowMT",
				     100,
				     0.0,
				     200.0);
  TH1F* Loose_MT_LowMT = new TH1F("Jet_Loose_MT_LowMT",
				  "Jet_Loose_MT_LowMT",
				  25,
				  0.0,
				  50.0);
  TH1F* Medium_MuPt_LowMT = new TH1F("Jet_Medium_MuPt_LowMT",
				     "Jet_Medium_MuPt_LowMT",
				     100,
				     0.0,
				     200.0);
  TH1F* Medium_TauPt_LowMT = new TH1F("Jet_Medium_TauPt_LowMT",
				      "Jet_Medium_TauPt_LowMT",
				      100,
				      0.0,
				      200.0);
  TH1F* Medium_MT_LowMT = new TH1F("Jet_Medium_MT_LowMT",
				   "Jet_Medium_MT_LowMT",
				   25,
				   0.0,
				   50.0);
  TH1F* Tight_MuPt_LowMT = new TH1F("Jet_Tight_MuPt_LowMT",
				    "Jet_Tight_MuPt_LowMT",
				    100,
				    0.0,
				    200.0);
  TH1F* Tight_TauPt_LowMT = new TH1F("Jet_Tight_TauPt_LowMT",
				     "Jet_Tight_TauPt_LowMT",
				     100,
				     0.0,
				     200.0);
  TH1F* Tight_MT_LowMT = new TH1F("Jet_Tight_MT_LowMT",
				  "Jet_Tight_MT_LowMT",
				  25,
				  0.0,
				  50.0);
  TH1F* VTight_MuPt_LowMT = new TH1F("Jet_VTight_MuPt_LowMT",
				     "Jet_VTight_MuPt_LowMT",
				     100,
				     0.0,
				     200.0);
  TH1F* VTight_TauPt_LowMT = new TH1F("Jet_VTight_TauPt_LowMT",
				      "Jet_VTight_TauPt_LowMT",
				      100,
				      0.0,
				      200.0);
  TH1F* VTight_MT_LowMT = new TH1F("Jet_VTight_MT_LowMT",
				   "Jet_VTight_MT_LowMT",
				   25,
				   0.0,
				   50.0);
  TH1F* VVTight_MuPt_LowMT = new TH1F("Jet_VVTight_MuPt_LowMT",
				      "Jet_VVTight_MuPt_LowMT",
				      100,
				      0.0,
				      200.0);
  TH1F* VVTight_TauPt_LowMT = new TH1F("Jet_VVTight_TauPt_LowMT",
				       "Jet_VVTight_TauPt_LowMT",
				       100,
				       0.0,
				       200.0);
  TH1F* VVTight_MT_LowMT = new TH1F("Jet_VVTight_MT_LowMT",
				    "Jet_VVTight_MT_LowMT",
				    25,
				    0.0,
				    50.0);
  //MT 50-100
  TH1F* VLoose_MuPt_HighMT = new TH1F("Jet_VLoose_MuPt_HighMT",
				      "Jet_VLoose_MuPt_HighMT",
				      100,
				      0.0,
				      200.0);
  TH1F* VLoose_TauPt_HighMT = new TH1F("Jet_VLoose_TauPt_HighMT",
				       "Jet_VLoose_TauPt_HighMT",
				       100,
				       0.0,
				       200.0);
  TH1F* VLoose_MT_HighMT = new TH1F("Jet_VLoose_MT_HighMT",
				    "Jet_VLoose_MT_HighMT",
				    25,
				    50.0,
				    100.0);
  TH1F* Loose_MuPt_HighMT = new TH1F("Jet_Loose_MuPt_HighMT",
				     "Jet_Loose_MuPt_HighMT",
				     100,
				     0.0,
				     200.0);
  TH1F* Loose_TauPt_HighMT = new TH1F("Jet_Loose_TauPt_HighMT",
				      "Jet_Loose_TauPt_HighMT",
				      100,
				      0.0,
				      200.0);
  TH1F* Loose_MT_HighMT = new TH1F("Jet_Loose_MT_HighMT",
				   "Jet_Loose_MT_HighMT",
				   25,
				   50.0,
				   100.0);
  TH1F* Medium_MuPt_HighMT = new TH1F("Jet_Medium_MuPt_HighMT",
				      "Jet_Medium_MuPt_HighMT",
				      100,
				      0.0,
				      200.0);
  TH1F* Medium_TauPt_HighMT = new TH1F("Jet_Medium_TauPt_HighMT",
				       "Jet_Medium_TauPt_HighMT",
				       100,
				       0.0,
				       200.0);
  TH1F* Medium_MT_HighMT = new TH1F("Jet_Medium_MT_HighMT",
				    "Jet_Medium_MT_HighMT",
				    25,
				    50.0,
				    100.0);
  TH1F* Tight_MuPt_HighMT = new TH1F("Jet_Tight_MuPt_HighMT",
				     "Jet_Tight_MuPt_HighMT",
				     100,
				     0.0,
				     200.0);
  TH1F* Tight_TauPt_HighMT = new TH1F("Jet_Tight_TauPt_HighMT",
				      "Jet_Tight_TauPt_HighMT",
				      100,
				      0.0,
				      200.0);
  TH1F* Tight_MT_HighMT = new TH1F("Jet_Tight_MT_HighMT",
				   "Jet_Tight_MT_HighMT",
				   25,
				   50.0,
				   100.0);
  TH1F* VTight_MuPt_HighMT = new TH1F("Jet_VTight_MuPt_HighMT",
				      "Jet_VTight_MuPt_HighMT",
				      100,
				      0.0,
				      200.0);
  TH1F* VTight_TauPt_HighMT = new TH1F("Jet_VTight_TauPt_HighMT",
				       "Jet_VTight_TauPt_HighMT",
				       100,
				       0.0,
				       200.0);
  TH1F* VTight_MT_HighMT = new TH1F("Jet_VTight_MT_HighMT",
				    "Jet_VTight_MT_HighMT",
				    25,
				    50.0,
				    100.0);
  TH1F* VVTight_MuPt_HighMT = new TH1F("Jet_VVTight_MuPt_HighMT",
				       "Jet_VVTight_MuPt_HighMT",
				       100,
				       0.0,
				       200.0);
  TH1F* VVTight_TauPt_HighMT = new TH1F("Jet_VVTight_TauPt_HighMT",
					"Jet_VVTight_TauPt_HighMT",
					100,
					0.0,
					200.0);
  TH1F* VVTight_MT_HighMT = new TH1F("Jet_VVTight_MT_HighMT",
				     "Jet_VVTight_MT_HighMT",
				     25,
				     50.0,
				     100.0);
  //The VHigh MT region 100-200
  TH1F* VLoose_MuPt_VHighMT = new TH1F("Jet_VLoose_MuPt_VHighMT",
				     "Jet_VLoose_MuPt_VHighMT",
				       100,
				       0.0,
				       200.0);
  TH1F* VLoose_TauPt_VHighMT = new TH1F("Jet_VLoose_TauPt_VHighMT",
					"Jet_VLoose_TauPt_VHighMT",
					100,
					0.0,
					200.0);
  TH1F* VLoose_MT_VHighMT = new TH1F("Jet_VLoose_MT_VHighMT",
				     "Jet_VLoose_MT_VHighMT",
				     50,
				     100.0,
				     200.0);
  TH1F* Loose_MuPt_VHighMT = new TH1F("Jet_Loose_MuPt_VHighMT",
				      "Jet_Loose_MuPt_VHighMT",
				      100,
				      0.0,
				      200.0);
  TH1F* Loose_TauPt_VHighMT = new TH1F("Jet_Loose_TauPt_VHighMT",
				       "Jet_Loose_TauPt_VHighMT",
				       100,
				       0.0,
				       200.0);
  TH1F* Loose_MT_VHighMT = new TH1F("Jet_Loose_MT_VHighMT",
				    "Jet_Loose_MT_VHighMT",
				    50,
				    100.0,
				    200.0);
  TH1F* Medium_MuPt_VHighMT = new TH1F("Jet_Medium_MuPt_VHighMT",
				       "Jet_Medium_MuPt_VHighMT",
				       100,
				       0.0,
				       200.0);
  TH1F* Medium_TauPt_VHighMT = new TH1F("Jet_Medium_TauPt_VHighMT",
					"Jet_Medium_TauPt_VHighMT",
					100,
					0.0,
					200.0);
  TH1F* Medium_MT_VHighMT = new TH1F("Jet_Medium_MT_VHighMT",
				     "Jet_Medium_MT_VHighMT",
				     50,
				     100.0,
				     200.0);
  TH1F* Tight_MuPt_VHighMT = new TH1F("Jet_Tight_MuPt_VHighMT",
				      "Jet_Tight_MuPt_VHighMT",
				      100,
				      0.0,
				      200.0);
  TH1F* Tight_TauPt_VHighMT = new TH1F("Jet_Tight_TauPt_VHighMT",
				       "Jet_Tight_TauPt_VHighMT",
				       100,
				       0.0,
				       200.0);
  TH1F* Tight_MT_VHighMT = new TH1F("Jet_Tight_MT_VHighMT",
				    "Jet_Tight_MT_VHighMT",
				    50,
				    100.0,
				    200.0);
  TH1F* VTight_MuPt_VHighMT = new TH1F("Jet_VTight_MuPt_VHighMT",
				       "Jet_VTight_MuPt_VHighMT",
				       100,
				       0.0,
				       200.0);
  TH1F* VTight_TauPt_VHighMT = new TH1F("Jet_VTight_TauPt_VHighMT",
					"Jet_VTight_TauPt_VHighMT",
					100,
					0.0,
					200.0);
  TH1F* VTight_MT_VHighMT = new TH1F("Jet_VTight_MT_VHighMT",
				     "Jet_VTight_MT_VHighMT",
				     50,
				     100.0,
				     200.0);
  TH1F* VVTight_MuPt_VHighMT = new TH1F("Jet_VVTight_MuPt_VHighMT",
					"Jet_VVTight_MuPt_VHighMT",
					100,
					0.0,
					200.0);
  TH1F* VVTight_TauPt_VHighMT = new TH1F("Jet_VVTight_TauPt_VHighMT",
					 "Jet_VVTight_TauPt_VHighMT",
					 100,
					 0.0,
					 200.0);
  TH1F* VVTight_MT_VHighMT = new TH1F("Jet_VVTight_MT_VHighMT",
				      "Jet_VVTight_MT_VHighMT",
				      50,
				      100.0,
				      200.0);

  //Sascha's shape idea
  //split this up into W+ and W- shapes
  //W+
  TH1F* VLoose_MT_WPlus =new TH1F("Jet_VLoose_MT_WPlus","Jet_VLoose_MT_WPlus",
				  100,
				  0.0,
				  200.0);
  TH1F* Loose_MT_WPlus = new TH1F("Jet_Loose_MT_WPlus","Jet_Loose_MT_WPlus",
				  100,
				  0.0,
				  200.0);
  TH1F* Medium_MT_WPlus = new TH1F("Jet_Medium_MT_WPlus","Jet_Medium_MT_WPlus",
				   100,
				   0.0,
				   200.0);
  TH1F* Tight_MT_WPlus = new TH1F("Jet_Tight_MT_WPlus","Jet_Tight_MT_WPlus",
				  100,
				  0.0,
				  200.0);
  TH1F* VTight_MT_WPlus = new TH1F("Jet_VTight_MT_WPlus","Jet_VTight_MT_WPlus",
				   100,
				   0.0,
				   200.0);
  TH1F* VVTight_MT_WPlus = new TH1F("Jet_VVTight_MT_WPlus","Jet_VVTight_MT_WPlus",
				    100,
				    0.0,
				    200.0);
  //W-
  TH1F* VLoose_MT_WMinus =new TH1F("Jet_VLoose_MT_WMinus","Jet_VLoose_MT_WMinus",
				   100,
				   0.0,
				   200.0);
  TH1F* Loose_MT_WMinus = new TH1F("Jet_Loose_MT_WMinus","Jet_Loose_MT_WMinus",
				   100,
				   0.0,
				   200.0);
  TH1F* Medium_MT_WMinus = new TH1F("Jet_Medium_MT_WMinus","Jet_Medium_MT_WMinus",
				    100,
				    0.0,
				    200.0);
  TH1F* Tight_MT_WMinus = new TH1F("Jet_Tight_MT_WMinus","Jet_Tight_MT_WMinus",
				   100,
				   0.0,
				   200.0);
  TH1F* VTight_MT_WMinus = new TH1F("Jet_VTight_MT_WMinus","Jet_VTight_MT_WMinus",
				    100,
				    0.0,
				    200.0);
  TH1F* VVTight_MT_WMinus = new TH1F("Jet_VVTight_MT_WMinus","Jet_VVTight_MT_WMinus",
				     100,
				     0.0,
				     200.0);
  
  
  int VLooseApplication = 0;
  int LooseApplication = 0;
  int MediumApplication = 0;
  int TightApplication = 0;
  int VTightApplication = 0;
  int VVTightApplication = 0;

  int VLoose_PositiveMuon = 0;
  int VLoose_NegativeMuon = 0;
  int Loose_PositiveMuon = 0;
  int Loose_NegativeMuon = 0;
  int Medium_PositiveMuon = 0;
  int Medium_NegativeMuon = 0;
  int Tight_PositiveMuon = 0;
  int Tight_NegativeMuon = 0;
  int VTight_PositiveMuon = 0;
  int VTight_NegativeMuon = 0;
  int VVTight_PositiveMuon = 0;
  int VVTight_NegativeMuon = 0;

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

      TLorentzVector l1; l1.SetPtEtaPhiM(pt_1, eta_1, phi_1, m_1); //muon
      TLorentzVector l2; l2.SetPtEtaPhiM(pt_2, eta_2, phi_2, m_2); //tau

      //math diego's pt > 30 cut instead of my original 29.0 cut.
      if(pt_1 < 30.0 or std::abs(eta_1) > 2.4 or !id_m_medium_1 or iso_1 > 0.15 or std::abs(dZ_1) > 0.2 or std::abs(d0_1) > 0.045 or !matchIsoMu27_1) continue;
      //tau criteria
      //added the decaymodefinding_2 which catches the old decay mode finding.
      if(pt_2 < 20.0  or std::abs(eta_2) > 2.3 or againstElectronVLooseMVA6_2 != 1 or againstMuonTight3_2 != 1 or !decayModeFinding_2 or std::abs(dZ_2) > 0.2 or std::abs(q_2) > 1.0) continue;      
      
      //hacked in brief way to examine pt/eta brackets.
      //pt:
      if(PtBracket == 1)
	{
	  //tau pt 20-25
	  if(pt_2 <= 20.0 or pt_2 >= 25) continue;
	}
      else if (PtBracket == 2)
	{
	  //tau pt 25-30
	  if(pt_2 <= 25.0 or pt_2 >= 30.0) continue;
	}
      else if (PtBracket == 3)
	{
	  //tau pt 30-32
	  if(pt_2 <= 30.0 or pt_2 >= 32.0) continue;
	}
      if(PtBracket == 4)
	{
	  //tau pt 32-35
	  if(pt_2 <= 32.0 or pt_2 >= 35.0) continue;
	}
      if(PtBracket == 5)
	{
	  //tau pt 30-35
	  if(pt_2 <= 30.0 or pt_2 >= 35.0) continue;
	}
      if(PtBracket == 6)
	{
	  //tau pt 35-40
	  if(pt_2 <= 35.0 or pt_2 >= 40.0) continue;
	}
      if(PtBracket == 7)
	{
	  //tau pt 40-50
	  if(pt_2 <= 40.0 or pt_2 >= 50.0) continue;
	}
      if(PtBracket == 8)
	{
	  //tau pt 50-60
	  if(pt_2 <= 50.0 or pt_2 >= 60.0) continue;
	}
      if(PtBracket == 9)
	{
	  //tau pt 60-70
	  if(pt_2 <= 60.0 or pt_2 >= 70.0) continue;
	}
      if(PtBracket == 10)
	{
	  //tau pt 70-100
	  if(pt_2 <= 70.0 or pt_2 >= 100.0) continue;
	}
      else if(PtBracket == 11)
	{
	  //tau pt > 100+
	  if(pt_2 <= 100.0) continue;
	}
      
      //eta:
      if(EtaBracket == 1)
	{
	  //eta < 1.479
	  if(std::abs(eta_2) >= 1.479) continue;
	}
      else if(EtaBracket == 2)
	{
	  //eta > 1.479
	  if(std::abs(eta_2) <= 1.479) continue;
	}

      //pair criteria            
      float DeltaR = l1.DeltaR(l2);
      if(DeltaR <= 0.5)  continue;
      
      float HistoHighEdge = Data_Pass->GetXaxis()->GetXmax();
      float HistoLowEdge = Data_Pass->GetXaxis()->GetXmin();            

      float Var = (l1+l2).M();      
      //float Var = TransverseMass;
      //float Var = njets;
      //float Var = l2.Eta();
      //float Var = l1.Eta();
      //float Var = l1.Pt();
      //float Var = l2.Pt();
      //float Var = npv;
      //changed the mt cut to 50 to match diego, instead of my original 40
      if(q_1 * q_2 < 0.0 and TransverseMass < 200.0 /*and PZeta > -25.0*/)
	{
	  VLooseApplication++;
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
		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode0PTBarrelFakeRates->GetBinContent(VLooseDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode0PTBarrelFakeRates->GetBinContent(VLooseDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VLooseDecayMode0PTEndcapFakeRates->GetBinContent(VLooseDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VLooseDecayMode0PTEndcapFakeRates->GetBinContent(VLooseDecayMode0PTEndcapFakeRates->FindBin(199.0));

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
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode1PTBarrelFakeRates->GetBinContent(VLooseDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode1PTBarrelFakeRates->GetBinContent(VLooseDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VLooseDecayMode1PTEndcapFakeRates->GetBinContent(VLooseDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VLooseDecayMode1PTEndcapFakeRates->GetBinContent(VLooseDecayMode1PTEndcapFakeRates->FindBin(199.0));		  
		  
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
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode10PTBarrelFakeRates->GetBinContent(VLooseDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode10PTBarrelFakeRates->GetBinContent(VLooseDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VLooseDecayMode10PTEndcapFakeRates->GetBinContent(VLooseDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VLooseDecayMode10PTEndcapFakeRates->GetBinContent(VLooseDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  
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

	      //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      PTWeighting = 1.0;
	      
	      VLoosePTFRJetDistribution->Fill(Var,PTWeighting);
	      //fill sascha's special shapes
	      if(q_1 > 0.0){VLoose_MT_WPlus->Fill(TransverseMass,PTWeighting); VLoose_PositiveMuon++;}
	      else {VLoose_MT_WMinus->Fill(TransverseMass,PTWeighting);VLoose_NegativeMuon++;}
	      //fill controls
	      VLoose_MuPt->Fill(l1.Pt(),PTWeighting);
	      VLoose_TauPt->Fill(l2.Pt(),PTWeighting);
	      VLoose_MuEta->Fill(l1.Eta(),PTWeighting);
	      VLoose_TauEta->Fill(l2.Eta(),PTWeighting);
	      VLoose_NJets->Fill(njets,PTWeighting);
	      VLoose_NBtag->Fill(nbtag,PTWeighting);
	      VLoose_ZMass->Fill((l1+l2).M(),PTWeighting);
	      VLoose_ZPT->Fill((l1+l2).Pt(),PTWeighting);
	      VLoose_MT->Fill(TransverseMass,PTWeighting);
	    }
	  
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byLooseIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	      
	      LooseApplication++;
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode0PTBarrelFakeRates->GetBinContent(LooseDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode0PTBarrelFakeRates->GetBinContent(LooseDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = LooseDecayMode0PTEndcapFakeRates->GetBinContent(LooseDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = LooseDecayMode0PTEndcapFakeRates->GetBinContent(LooseDecayMode0PTEndcapFakeRates->FindBin(199.0));		  

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
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode1PTBarrelFakeRates->GetBinContent(LooseDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode1PTBarrelFakeRates->GetBinContent(LooseDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = LooseDecayMode1PTEndcapFakeRates->GetBinContent(LooseDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = LooseDecayMode1PTEndcapFakeRates->GetBinContent(LooseDecayMode1PTEndcapFakeRates->FindBin(199.0));		  
		  
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
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode10PTBarrelFakeRates->GetBinContent(LooseDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode10PTBarrelFakeRates->GetBinContent(LooseDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = LooseDecayMode10PTEndcapFakeRates->GetBinContent(LooseDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = LooseDecayMode10PTEndcapFakeRates->GetBinContent(LooseDecayMode10PTEndcapFakeRates->FindBin(199.0));		  
		  
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

	      //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      PTWeighting = 1.0;
	      
	      LoosePTFRJetDistribution->Fill(Var,PTWeighting);
	      //fill sascha's special shapes
	      if(q_1 > 0.0) {Loose_MT_WPlus->Fill(TransverseMass,PTWeighting);Loose_PositiveMuon++;}
	      else {Loose_MT_WMinus->Fill(TransverseMass,PTWeighting);Loose_NegativeMuon++;}
	      
	      //fill controls
	      Loose_MuPt->Fill(l1.Pt(),PTWeighting);
	      Loose_TauPt->Fill(l2.Pt(),PTWeighting);
	      Loose_MuEta->Fill(l1.Eta(),PTWeighting);
	      Loose_TauEta->Fill(l2.Eta(),PTWeighting);
	      Loose_NJets->Fill(njets,PTWeighting);
	      Loose_NBtag->Fill(nbtag,PTWeighting);
	      Loose_ZMass->Fill((l1+l2).M(),PTWeighting);
	      Loose_ZPT->Fill((l1+l2).Pt(),PTWeighting);
	      Loose_MT->Fill(TransverseMass,PTWeighting);
	    }

	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byMediumIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      MediumApplication++;
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode0PTBarrelFakeRates->GetBinContent(MediumDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode0PTBarrelFakeRates->GetBinContent(MediumDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = MediumDecayMode0PTEndcapFakeRates->GetBinContent(MediumDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = MediumDecayMode0PTEndcapFakeRates->GetBinContent(MediumDecayMode0PTEndcapFakeRates->FindBin(199.0));

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
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode1PTBarrelFakeRates->GetBinContent(MediumDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode1PTBarrelFakeRates->GetBinContent(MediumDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = MediumDecayMode1PTEndcapFakeRates->GetBinContent(MediumDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = MediumDecayMode1PTEndcapFakeRates->GetBinContent(MediumDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  
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
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode10PTBarrelFakeRates->GetBinContent(MediumDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode10PTBarrelFakeRates->GetBinContent(MediumDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = MediumDecayMode10PTEndcapFakeRates->GetBinContent(MediumDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = MediumDecayMode10PTEndcapFakeRates->GetBinContent(MediumDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  
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
	      //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      PTWeighting = 1.0;
	      
	      MediumPTFRJetDistribution->Fill(Var,PTWeighting);
	      //fill sascha's special shapes
	      if(q_1 > 0.0) {Medium_MT_WPlus->Fill(TransverseMass,PTWeighting);Medium_PositiveMuon++;}
	      else {Medium_MT_WMinus->Fill(TransverseMass,PTWeighting);Medium_NegativeMuon++;}
	      
	      //fill controls
	      Medium_MuPt->Fill(l1.Pt(),PTWeighting);
	      Medium_TauPt->Fill(l2.Pt(),PTWeighting);
	      Medium_MuEta->Fill(l1.Eta(),PTWeighting);
	      Medium_TauEta->Fill(l2.Eta(),PTWeighting);
	      Medium_NJets->Fill(njets,PTWeighting);
	      Medium_NBtag->Fill(nbtag,PTWeighting);
	      Medium_ZMass->Fill((l1+l2).M(),PTWeighting);
	      Medium_ZPT->Fill((l1+l2).Pt(),PTWeighting);
	      Medium_MT->Fill(TransverseMass,PTWeighting);
	    }

	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      TightApplication++;
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode0PTBarrelFakeRates->GetBinContent(TightDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode0PTBarrelFakeRates->GetBinContent(TightDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = TightDecayMode0PTEndcapFakeRates->GetBinContent(TightDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = TightDecayMode0PTEndcapFakeRates->GetBinContent(TightDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  
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
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode1PTBarrelFakeRates->GetBinContent(TightDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode1PTBarrelFakeRates->GetBinContent(TightDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = TightDecayMode1PTEndcapFakeRates->GetBinContent(TightDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = TightDecayMode1PTEndcapFakeRates->GetBinContent(TightDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  
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
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode10PTBarrelFakeRates->GetBinContent(TightDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode10PTBarrelFakeRates->GetBinContent(TightDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = TightDecayMode10PTEndcapFakeRates->GetBinContent(TightDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = TightDecayMode10PTEndcapFakeRates->GetBinContent(TightDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  
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

	      //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      PTWeighting = 1.0;
	      
	      TightPTFRJetDistribution->Fill(Var,PTWeighting);
	      //fill sascha's special shapes
	      if(q_1 > 0.0) {Tight_MT_WPlus->Fill(TransverseMass,PTWeighting);Tight_PositiveMuon++;}
	      else {Tight_MT_WMinus->Fill(TransverseMass,PTWeighting);Tight_NegativeMuon++;}
	      
	      //fill controls
	      Tight_MuPt->Fill(l1.Pt(),PTWeighting);
	      Tight_TauPt->Fill(l2.Pt(),PTWeighting);
	      Tight_MuEta->Fill(l1.Eta(),PTWeighting);
	      Tight_TauEta->Fill(l2.Eta(),PTWeighting);
	      Tight_NJets->Fill(njets,PTWeighting);
	      Tight_NBtag->Fill(nbtag,PTWeighting);
	      Tight_ZMass->Fill((l1+l2).M(),PTWeighting);
	      Tight_ZPT->Fill((l1+l2).Pt(),PTWeighting);
	      Tight_MT->Fill(TransverseMass,PTWeighting);
	    }

	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	
	      VTightApplication++;
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode0PTBarrelFakeRates->GetBinContent(VTightDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode0PTBarrelFakeRates->GetBinContent(VTightDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VTightDecayMode0PTEndcapFakeRates->GetBinContent(VTightDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VTightDecayMode0PTEndcapFakeRates->GetBinContent(VTightDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  
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
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode1PTBarrelFakeRates->GetBinContent(VTightDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode1PTBarrelFakeRates->GetBinContent(VTightDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VTightDecayMode1PTEndcapFakeRates->GetBinContent(VTightDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VTightDecayMode1PTEndcapFakeRates->GetBinContent(VTightDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  
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
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode10PTBarrelFakeRates->GetBinContent(VTightDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode10PTBarrelFakeRates->GetBinContent(VTightDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VTightDecayMode10PTEndcapFakeRates->GetBinContent(VTightDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VTightDecayMode10PTEndcapFakeRates->GetBinContent(VTightDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  
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
	      //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      PTWeighting = 1.0;
	      
	      VTightPTFRJetDistribution->Fill(Var,PTWeighting);
	      //fill sascha's special shapes
	      if(q_1 > 0.0) {VTight_MT_WPlus->Fill(TransverseMass,PTWeighting);VTight_PositiveMuon++;}
	      else {VTight_MT_WMinus->Fill(TransverseMass,PTWeighting);VTight_NegativeMuon++;}
	      
	      //fill controls
	      VTight_MuPt->Fill(l1.Pt(),PTWeighting);
	      VTight_TauPt->Fill(l2.Pt(),PTWeighting);
	      VTight_MuEta->Fill(l1.Eta(),PTWeighting);
	      VTight_TauEta->Fill(l2.Eta(),PTWeighting);
	      VTight_NJets->Fill(njets,PTWeighting);
	      VTight_NBtag->Fill(nbtag,PTWeighting);
	      VTight_ZMass->Fill((l1+l2).M(),PTWeighting);
	      VTight_ZPT->Fill((l1+l2).Pt(),PTWeighting);
	      VTight_MT->Fill(TransverseMass,PTWeighting);
	    }

	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	
	      VVTightApplication++;
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode0PTBarrelFakeRates->GetBinContent(VVTightDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode0PTBarrelFakeRates->GetBinContent(VVTightDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VVTightDecayMode0PTEndcapFakeRates->GetBinContent(VVTightDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VVTightDecayMode0PTEndcapFakeRates->GetBinContent(VVTightDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  
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
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode1PTBarrelFakeRates->GetBinContent(VVTightDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode1PTBarrelFakeRates->GetBinContent(VVTightDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VVTightDecayMode1PTEndcapFakeRates->GetBinContent(VVTightDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VVTightDecayMode1PTEndcapFakeRates->GetBinContent(VVTightDecayMode1PTEndcapFakeRates->FindBin(199.0));

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
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode10PTBarrelFakeRates->GetBinContent(VVTightDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode10PTBarrelFakeRates->GetBinContent(VVTightDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VVTightDecayMode10PTEndcapFakeRates->GetBinContent(VVTightDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VVTightDecayMode10PTEndcapFakeRates->GetBinContent(VVTightDecayMode10PTEndcapFakeRates->FindBin(199.0));

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
	      //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      PTWeighting = 1.0;
	      
	      VVTightPTFRJetDistribution->Fill(Var,PTWeighting);
	      //fill sascha's special shapes
	      if(q_1 > 0.0) {VVTight_MT_WPlus->Fill(TransverseMass,PTWeighting);VVTight_PositiveMuon++;}
	      else {VVTight_MT_WMinus->Fill(TransverseMass,PTWeighting);VVTight_NegativeMuon++;}
	      
	      //fill controls
	      VVTight_MuPt->Fill(l1.Pt(),PTWeighting);
	      VVTight_TauPt->Fill(l2.Pt(),PTWeighting);
	      VVTight_MuEta->Fill(l1.Eta(),PTWeighting);
	      VVTight_TauEta->Fill(l2.Eta(),PTWeighting);
	      VVTight_NJets->Fill(njets,PTWeighting);
	      VVTight_NBtag->Fill(nbtag,PTWeighting);
	      VVTight_ZMass->Fill((l1+l2).M(),PTWeighting);
	      VVTight_ZPT->Fill((l1+l2).Pt(),PTWeighting);
	      VVTight_MT->Fill(TransverseMass,PTWeighting);
	      
	    }
	} //end of checking for signal region
      
      // same sign region
      if(q_1 * q_2 > 0.0 /*and TransverseMass < 50.0 and PZeta > -25.0*/)
	{	  
	  float PTFakeRate = 0.0;
	  float PTWeighting = 0.0;
	  float ExacerbatedFakeRate = 0.0;
	  float ExacerbatedWeighting = 0.0;	  
	  if(!byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {  
	      if(l2_decayMode == 0)
		{	  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode0PTBarrelFakeRates->GetBinContent(VLooseDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode0PTBarrelFakeRates->GetBinContent(VLooseDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VLooseDecayMode0PTEndcapFakeRates->GetBinContent(VLooseDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VLooseDecayMode0PTEndcapFakeRates->GetBinContent(VLooseDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  		  
		  //fill controls
		  VLoose_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  VLoose_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  VLoose_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  VLoose_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  VLoose_NJets_SS->Fill(njets,PTWeighting);
		  VLoose_NBtag_SS->Fill(nbtag,PTWeighting);
		  VLoose_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  VLoose_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  VLoose_MT_SS->Fill(TransverseMass,PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode1PTBarrelFakeRates->GetBinContent(VLooseDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode1PTBarrelFakeRates->GetBinContent(VLooseDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VLooseDecayMode1PTEndcapFakeRates->GetBinContent(VLooseDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VLooseDecayMode1PTEndcapFakeRates->GetBinContent(VLooseDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  		  
		  VLoose_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  VLoose_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  VLoose_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  VLoose_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  VLoose_NJets_SS->Fill(njets,PTWeighting);
		  VLoose_NBtag_SS->Fill(nbtag,PTWeighting);
		  VLoose_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  VLoose_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  VLoose_MT_SS->Fill(TransverseMass,PTWeighting);
		  		  ;
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode10PTBarrelFakeRates->GetBinContent(VLooseDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode10PTBarrelFakeRates->GetBinContent(VLooseDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VLooseDecayMode10PTEndcapFakeRates->GetBinContent(VLooseDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VLooseDecayMode10PTEndcapFakeRates->GetBinContent(VLooseDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  VLoose_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  VLoose_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  VLoose_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  VLoose_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  VLoose_NJets_SS->Fill(njets,PTWeighting);
		  VLoose_NBtag_SS->Fill(nbtag,PTWeighting);
		  VLoose_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  VLoose_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  VLoose_MT_SS->Fill(TransverseMass,PTWeighting);
		  		  
		}	      	      
	    }
	  
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byLooseIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	      
	      LooseApplication++;
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode0PTBarrelFakeRates->GetBinContent(LooseDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode0PTBarrelFakeRates->GetBinContent(LooseDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = LooseDecayMode0PTEndcapFakeRates->GetBinContent(LooseDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = LooseDecayMode0PTEndcapFakeRates->GetBinContent(LooseDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  		  
		  //fill controls
		  Loose_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  Loose_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  Loose_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  Loose_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  Loose_NJets_SS->Fill(njets,PTWeighting);
		  Loose_NBtag_SS->Fill(nbtag,PTWeighting);
		  Loose_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  Loose_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  Loose_MT_SS->Fill(TransverseMass,PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode1PTBarrelFakeRates->GetBinContent(LooseDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode1PTBarrelFakeRates->GetBinContent(LooseDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = LooseDecayMode1PTEndcapFakeRates->GetBinContent(LooseDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = LooseDecayMode1PTEndcapFakeRates->GetBinContent(LooseDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  Loose_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  Loose_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  Loose_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  Loose_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  Loose_NJets_SS->Fill(njets,PTWeighting);
		  Loose_NBtag_SS->Fill(nbtag,PTWeighting);
		  Loose_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  Loose_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  Loose_MT_SS->Fill(TransverseMass,PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode10PTBarrelFakeRates->GetBinContent(LooseDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode10PTBarrelFakeRates->GetBinContent(LooseDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = LooseDecayMode10PTEndcapFakeRates->GetBinContent(LooseDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = LooseDecayMode10PTEndcapFakeRates->GetBinContent(LooseDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  Loose_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  Loose_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  Loose_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  Loose_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  Loose_NJets_SS->Fill(njets,PTWeighting);
		  Loose_NBtag_SS->Fill(nbtag,PTWeighting);
		  Loose_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  Loose_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  Loose_MT_SS->Fill(TransverseMass,PTWeighting);
		}	      	      
	    }

	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byMediumIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      MediumApplication++;
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode0PTBarrelFakeRates->GetBinContent(MediumDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode0PTBarrelFakeRates->GetBinContent(MediumDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = MediumDecayMode0PTEndcapFakeRates->GetBinContent(MediumDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = MediumDecayMode0PTEndcapFakeRates->GetBinContent(MediumDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  Medium_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  Medium_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  Medium_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  Medium_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  Medium_NJets_SS->Fill(njets,PTWeighting);
		  Medium_NBtag_SS->Fill(nbtag,PTWeighting);
		  Medium_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  Medium_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  Medium_MT_SS->Fill(TransverseMass,PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode1PTBarrelFakeRates->GetBinContent(MediumDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode1PTBarrelFakeRates->GetBinContent(MediumDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = MediumDecayMode1PTEndcapFakeRates->GetBinContent(MediumDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = MediumDecayMode1PTEndcapFakeRates->GetBinContent(MediumDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  Medium_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  Medium_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  Medium_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  Medium_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  Medium_NJets_SS->Fill(njets,PTWeighting);
		  Medium_NBtag_SS->Fill(nbtag,PTWeighting);
		  Medium_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  Medium_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  Medium_MT_SS->Fill(TransverseMass,PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode10PTBarrelFakeRates->GetBinContent(MediumDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode10PTBarrelFakeRates->GetBinContent(MediumDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = MediumDecayMode10PTEndcapFakeRates->GetBinContent(MediumDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = MediumDecayMode10PTEndcapFakeRates->GetBinContent(MediumDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  Medium_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  Medium_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  Medium_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  Medium_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  Medium_NJets_SS->Fill(njets,PTWeighting);
		  Medium_NBtag_SS->Fill(nbtag,PTWeighting);
		  Medium_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  Medium_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  Medium_MT_SS->Fill(TransverseMass,PTWeighting);
		}	      	      
	    }

	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      TightApplication++;
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode0PTBarrelFakeRates->GetBinContent(TightDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode0PTBarrelFakeRates->GetBinContent(TightDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = TightDecayMode0PTEndcapFakeRates->GetBinContent(TightDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = TightDecayMode0PTEndcapFakeRates->GetBinContent(TightDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  Tight_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  Tight_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  Tight_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  Tight_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  Tight_NJets_SS->Fill(njets,PTWeighting);
		  Tight_NBtag_SS->Fill(nbtag,PTWeighting);
		  Tight_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  Tight_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  Tight_MT_SS->Fill(TransverseMass,PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode1PTBarrelFakeRates->GetBinContent(TightDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode1PTBarrelFakeRates->GetBinContent(TightDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = TightDecayMode1PTEndcapFakeRates->GetBinContent(TightDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = TightDecayMode1PTEndcapFakeRates->GetBinContent(TightDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  Tight_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  Tight_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  Tight_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  Tight_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  Tight_NJets_SS->Fill(njets,PTWeighting);
		  Tight_NBtag_SS->Fill(nbtag,PTWeighting);
		  Tight_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  Tight_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  Tight_MT_SS->Fill(TransverseMass,PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode10PTBarrelFakeRates->GetBinContent(TightDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode10PTBarrelFakeRates->GetBinContent(TightDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = TightDecayMode10PTEndcapFakeRates->GetBinContent(TightDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = TightDecayMode10PTEndcapFakeRates->GetBinContent(TightDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  Tight_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  Tight_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  Tight_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  Tight_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  Tight_NJets_SS->Fill(njets,PTWeighting);
		  Tight_NBtag_SS->Fill(nbtag,PTWeighting);
		  Tight_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  Tight_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  Tight_MT_SS->Fill(TransverseMass,PTWeighting);
		}	      	      
	    }

	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	
	      VTightApplication++;
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode0PTBarrelFakeRates->GetBinContent(VTightDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode0PTBarrelFakeRates->GetBinContent(VTightDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VTightDecayMode0PTEndcapFakeRates->GetBinContent(VTightDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VTightDecayMode0PTEndcapFakeRates->GetBinContent(VTightDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  VTight_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  VTight_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  VTight_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  VTight_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  VTight_NJets_SS->Fill(njets,PTWeighting);
		  VTight_NBtag_SS->Fill(nbtag,PTWeighting);
		  VTight_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  VTight_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  VTight_MT_SS->Fill(TransverseMass,PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode1PTBarrelFakeRates->GetBinContent(VTightDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode1PTBarrelFakeRates->GetBinContent(VTightDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VTightDecayMode1PTEndcapFakeRates->GetBinContent(VTightDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VTightDecayMode1PTEndcapFakeRates->GetBinContent(VTightDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  VTight_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  VTight_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  VTight_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  VTight_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  VTight_NJets_SS->Fill(njets,PTWeighting);
		  VTight_NBtag_SS->Fill(nbtag,PTWeighting);
		  VTight_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  VTight_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  VTight_MT_SS->Fill(TransverseMass,PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode10PTBarrelFakeRates->GetBinContent(VTightDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode10PTBarrelFakeRates->GetBinContent(VTightDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VTightDecayMode10PTEndcapFakeRates->GetBinContent(VTightDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VTightDecayMode10PTEndcapFakeRates->GetBinContent(VTightDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  VTight_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  VTight_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  VTight_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  VTight_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  VTight_NJets_SS->Fill(njets,PTWeighting);
		  VTight_NBtag_SS->Fill(nbtag,PTWeighting);
		  VTight_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  VTight_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  VTight_MT_SS->Fill(TransverseMass,PTWeighting);		  
		}	      	      
	    }

	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	
	      VVTightApplication++;
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode0PTBarrelFakeRates->GetBinContent(VVTightDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode0PTBarrelFakeRates->GetBinContent(VVTightDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VVTightDecayMode0PTEndcapFakeRates->GetBinContent(VVTightDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VVTightDecayMode0PTEndcapFakeRates->GetBinContent(VVTightDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  VVTight_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  VVTight_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  VVTight_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  VVTight_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  VVTight_NJets_SS->Fill(njets,PTWeighting);
		  VVTight_NBtag_SS->Fill(nbtag,PTWeighting);
		  VVTight_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  VVTight_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  VVTight_MT_SS->Fill(TransverseMass,PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode1PTBarrelFakeRates->GetBinContent(VVTightDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode1PTBarrelFakeRates->GetBinContent(VVTightDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VVTightDecayMode1PTEndcapFakeRates->GetBinContent(VVTightDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VVTightDecayMode1PTEndcapFakeRates->GetBinContent(VVTightDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  VVTight_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  VVTight_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  VVTight_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  VVTight_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  VVTight_NJets_SS->Fill(njets,PTWeighting);
		  VVTight_NBtag_SS->Fill(nbtag,PTWeighting);
		  VVTight_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  VVTight_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  VVTight_MT_SS->Fill(TransverseMass,PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode10PTBarrelFakeRates->GetBinContent(VVTightDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode10PTBarrelFakeRates->GetBinContent(VVTightDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VVTightDecayMode10PTEndcapFakeRates->GetBinContent(VVTightDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VVTightDecayMode10PTEndcapFakeRates->GetBinContent(VVTightDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  //PTWeighting = 1.0;
		  
		  //fill controls
		  VVTight_MuPt_SS->Fill(l1.Pt(),PTWeighting);
		  VVTight_TauPt_SS->Fill(l2.Pt(),PTWeighting);
		  VVTight_MuEta_SS->Fill(l1.Eta(),PTWeighting);
		  VVTight_TauEta_SS->Fill(l2.Eta(),PTWeighting);
		  VVTight_NJets_SS->Fill(njets,PTWeighting);
		  VVTight_NBtag_SS->Fill(nbtag,PTWeighting);
		  VVTight_ZMass_SS->Fill((l1+l2).M(),PTWeighting);
		  VVTight_ZPT_SS->Fill((l1+l2).Pt(),PTWeighting);
		  VVTight_MT_SS->Fill(TransverseMass,PTWeighting);
		}	      	      
	    }
	} //end of checking Same Sign Region
    }
  std::cout<<std::endl;    
  std::cout<<"Events in each region: "<<std::endl;
  std::cout<<"VLoose: "<<VLooseApplication<<std::endl;
  std::cout<<"Loose: "<<LooseApplication<<std::endl;
  std::cout<<"Medium: "<<MediumApplication<<std::endl;
  std::cout<<"Tight: "<<TightApplication<<std::endl;
  std::cout<<"VTight: "<<VTightApplication<<std::endl;
  std::cout<<"VVTight: "<<VVTightApplication<<std::endl;
  std::cout<<std::endl;
  std::cout<<"VLoose_PositiveMuon: "<<VLoose_PositiveMuon<<std::endl;
  std::cout<<"VLoose_NegativeMuon: "<<VLoose_NegativeMuon<<std::endl;
  std::cout<<"Loose_PositiveMuon: "<<Loose_PositiveMuon<<std::endl;
  std::cout<<"Loose_NegativeMuon: "<<Loose_NegativeMuon<<std::endl;
  std::cout<<"Medium_PositiveMuon: "<<Medium_PositiveMuon<<std::endl;
  std::cout<<"Medium_NegativeMuon: "<<Medium_NegativeMuon<<std::endl;
  std::cout<<"Tight_PositiveMuon: "<<Tight_PositiveMuon<<std::endl;
  std::cout<<"Tight_NegativeMuon: "<<Tight_NegativeMuon<<std::endl;
  std::cout<<"VTight_PositiveMuon: "<<VTight_PositiveMuon<<std::endl;
  std::cout<<"VTight_NegativeMuon: "<<VTight_NegativeMuon<<std::endl;
  std::cout<<"VVTight_PositiveMuon: "<<VVTight_PositiveMuon<<std::endl;
  std::cout<<"VVTight_NegativeMuon: "<<VVTight_NegativeMuon<<std::endl;

  //Alright let's right this out and get the heck out of here.
  TFile* FakeRateDeterminedDistributions = new TFile("../Distributions/FakeRateDeterminedDistributions.root","RECREATE");

  VLoosePTFRJetDistribution->Write();
  LoosePTFRJetDistribution->Write();
  MediumPTFRJetDistribution->Write();
  TightPTFRJetDistribution->Write();
  VTightPTFRJetDistribution->Write();
  VVTightPTFRJetDistribution->Write(); 

  //sascha's special shapes
  VLoose_MT_WPlus->Write();
  Loose_MT_WPlus->Write();
  Medium_MT_WPlus->Write();
  Tight_MT_WPlus->Write();
  VTight_MT_WPlus->Write();
  VVTight_MT_WPlus->Write(); 
  VLoose_MT_WMinus->Write();
  Loose_MT_WMinus->Write();
  Medium_MT_WMinus->Write();
  Tight_MT_WMinus->Write();
  VTight_MT_WMinus->Write();
  VVTight_MT_WMinus->Write(); 

  //Write the control plots
  //VLoose
  VLoose_MuPt->Write();
  VLoose_TauPt->Write();
  VLoose_MuEta->Write();
  VLoose_TauEta->Write();
  VLoose_NJets->Write();
  VLoose_NBtag->Write();
  VLoose_ZMass->Write();
  VLoose_ZPT->Write();
  VLoose_MT->Write();
  //Loose
  Loose_MuPt->Write();
  Loose_TauPt->Write();
  Loose_MuEta->Write();
  Loose_TauEta->Write();
  Loose_NJets->Write();
  Loose_NBtag->Write();
  Loose_ZMass->Write();
  Loose_ZPT->Write();
  Loose_MT->Write();
  //Medium
  Medium_MuPt->Write();
  Medium_TauPt->Write();
  Medium_MuEta->Write();
  Medium_TauEta->Write();
  Medium_NJets->Write();
  Medium_NBtag->Write();
  Medium_ZMass->Write();
  Medium_ZPT->Write();
  Medium_MT->Write();
  //Tight
  Tight_MuPt->Write();
  Tight_TauPt->Write();
  Tight_MuEta->Write();
  Tight_TauEta->Write();
  Tight_NJets->Write();
  Tight_NBtag->Write();
  Tight_ZMass->Write();
  Tight_ZPT->Write();
  Tight_MT->Write();
  //VTight
  VTight_MuPt->Write();
  VTight_TauPt->Write();
  VTight_MuEta->Write();
  VTight_TauEta->Write();
  VTight_NJets->Write();
  VTight_NBtag->Write();
  VTight_ZMass->Write();
  VTight_ZPT->Write();
  VTight_MT->Write();
  //VVTight
  VVTight_MuPt->Write();
  VVTight_TauPt->Write();
  VVTight_MuEta->Write();
  VVTight_TauEta->Write();
  VVTight_NJets->Write();
  VVTight_NBtag->Write();
  VVTight_ZMass->Write();
  VVTight_ZPT->Write();
  VVTight_MT->Write();

  //Same Sign Control Plots  
  //VLoose
  VLoose_MuPt_SS->Write();
  VLoose_TauPt_SS->Write();
  VLoose_MuEta_SS->Write();
  VLoose_TauEta_SS->Write();
  VLoose_NJets_SS->Write();
  VLoose_NBtag_SS->Write();
  VLoose_ZMass_SS->Write();
  VLoose_ZPT_SS->Write();
  VLoose_MT_SS->Write();
  //Loose
  Loose_MuPt_SS->Write();
  Loose_TauPt_SS->Write();
  Loose_MuEta_SS->Write();
  Loose_TauEta_SS->Write();
  Loose_NJets_SS->Write();
  Loose_NBtag_SS->Write();
  Loose_ZMass_SS->Write();
  Loose_ZPT_SS->Write();
  Loose_MT_SS->Write();
  //Medium
  Medium_MuPt_SS->Write();
  Medium_TauPt_SS->Write();
  Medium_MuEta_SS->Write();
  Medium_TauEta_SS->Write();
  Medium_NJets_SS->Write();
  Medium_NBtag_SS->Write();
  Medium_ZMass_SS->Write();
  Medium_ZPT_SS->Write();
  Medium_MT_SS->Write();
  //Tight
  Tight_MuPt_SS->Write();
  Tight_TauPt_SS->Write();
  Tight_MuEta_SS->Write();
  Tight_TauEta_SS->Write();
  Tight_NJets_SS->Write();
  Tight_NBtag_SS->Write();
  Tight_ZMass_SS->Write();
  Tight_ZPT_SS->Write();
  Tight_MT_SS->Write();
  //VTight
  VTight_MuPt_SS->Write();
  VTight_TauPt_SS->Write();
  VTight_MuEta_SS->Write();
  VTight_TauEta_SS->Write();
  VTight_NJets_SS->Write();
  VTight_NBtag_SS->Write();
  VTight_ZMass_SS->Write();
  VTight_ZPT_SS->Write();
  VTight_MT_SS->Write();
  //VVTight
  VVTight_MuPt_SS->Write();
  VVTight_TauPt_SS->Write();
  VVTight_MuEta_SS->Write();
  VVTight_TauEta_SS->Write();
  VVTight_NJets_SS->Write();
  VVTight_NBtag_SS->Write();
  VVTight_ZMass_SS->Write();
  VVTight_ZPT_SS->Write();
  VVTight_MT_SS->Write();
  
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
