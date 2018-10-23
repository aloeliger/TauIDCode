#include "TROOT.h"
#include <cmath>

void JetToTauFakesMeasurement()
{
  TFile* TheFile = new TFile("/data/ccaillol/tauid_20june_mmt/Data.root");
  TTree* Tree = (TTree*) TheFile->Get("mumutau_tree");
  TH1F* nevents = (TH1F*) TheFile->Get("nevents");
  float TotalNumberOfEvents = nevents->GetBinContent(1);

  //Setup the run branches
  int run,lumi,evt,NUP;
  float npv,npu,numGenJets,amcatNLO_weight,pt_1,phi_1,eta_1,m_1,e_1,q_1,d0_1,dZ_1,iso_1;
  float id_m_medium_1,id_m_tight_1,id_m_loose_1,pt_2,phi_2,eta_2,m_2,e_2,q_2,d0_2,dZ_2;
  float iso_2,id_m_medium_2,id_m_tight_2,id_m_loose_2,neutralIsoPtSumdR03_3;
  float chargedIsoPtSumdR03_3,chargedIsoPtSum_3;
  float byLooseCombinedIsolationDeltaBetaCorr3Hits_3;
  float byMediumCombinedIsolationDeltaBetaCorr3Hits_3;
  float byTightCombinedIsolationDeltaBetaCorr3Hits_3;
  float byCombinedIsolationDeltaBetaCorrRaw3Hits_3;
  float byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_3;
  float byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_3;
  float byTightCombinedIsolationDeltaBetaCorr3HitsdR03_3;
  float byVLooseIsolationMVArun2v1DBnewDMwLT_3;
  float byVLooseIsolationMVArun2v1DBoldDMwLT_3;
  float byVLooseIsolationMVArun2v1DBdR03oldDMwLT_3;
  float byLooseIsolationMVArun2v1DBnewDMwLT_3;
  float byLooseIsolationMVArun2v1DBoldDMwLT_3;
  float byLooseIsolationMVArun2v1DBdR03oldDMwLT_3;
  float byMediumIsolationMVArun2v1DBnewDMwLT_3;
  float byMediumIsolationMVArun2v1DBoldDMwLT_3;
  float byMediumIsolationMVArun2v1DBdR03oldDMwLT_3;
  float byTightIsolationMVArun2v1DBnewDMwLT_3;
  float byTightIsolationMVArun2v1DBoldDMwLT_3;
  float byTightIsolationMVArun2v1DBdR03oldDMwLT_3;
  float byVTightIsolationMVArun2v1DBnewDMwLT_3;
  float byVTightIsolationMVArun2v1DBoldDMwLT_3;
  float byVTightIsolationMVArun2v1DBdR03oldDMwLT_3;
  float byVVTightIsolationMVArun2v1DBnewDMwLT_3;
  float byVVTightIsolationMVArun2v1DBoldDMwLT_3;
  float byVVTightIsolationMVArun2v1DBdR03oldDMwLT_3;
  float byIsolationMVA3oldDMwoLTraw_3;
  float byIsolationMVA3oldDMwLTraw_3;
  float byIsolationMVA3newDMwoLTraw_3;
  float byIsolationMVA3newDMwLTraw_3;
  float byVLooseIsolationRerunMVArun2v1DBoldDMwLT_3;
  float byLooseIsolationRerunMVArun2v1DBoldDMwLT_3;
  float byMediumIsolationRerunMVArun2v1DBoldDMwLT_3;
  float byTightIsolationRerunMVArun2v1DBoldDMwLT_3;
  float byVTightIsolationRerunMVArun2v1DBoldDMwLT_3;
  float byVVTightIsolationRerunMVArun2v1DBoldDMwLT_3;
  float byIsolationRerunMVA3oldDMwLTraw_3;
  float byVLooseIsolationRerunMVArun2v2DBoldDMwLT_3;
  float byLooseIsolationRerunMVArun2v2DBoldDMwLT_3;
  float byMediumIsolationRerunMVArun2v2DBoldDMwLT_3;
  float byTightIsolationRerunMVArun2v2DBoldDMwLT_3;
  float byVTightIsolationRerunMVArun2v2DBoldDMwLT_3;
  float byVVTightIsolationRerunMVArun2v2DBoldDMwLT_3;
  float byIsolationRerunMVA3oldDMwLTrawv2_3;
  float pt_3,phi_3,eta_3,m_3,e_3,q_3,d0_3,dZ_3,iso_3,l3_decayMode;
  float againstElectronLooseMVA6_3,againstElectronMediumMVA6_3,againstElectronTightMVA6_3;
  float againstElectronVLooseMVA6_3,againstElectronVTightMVA6_3,againstMuonLoose3_3;
  float againstMuonTight3_3,matchIsoMu27_1,matchIsoMu27_2,passIsoMu27,pt_top1,pt_top2;
  float genweight,gen_match_2,gen_match_1,met,metphi;
  int nbtag,njets;

  Tree->SetBranchAddress("run",&run);
  Tree->SetBranchAddress("lumi",&lumi);
  Tree->SetBranchAddress("evt",&evt);
  Tree->SetBranchAddress("NUP",&NUP);
  Tree->SetBranchAddress("npv",&npv);
  Tree->SetBranchAddress("npu",&npu);
  Tree->SetBranchAddress("numGenJets",&numGenJets);
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
  Tree->SetBranchAddress("id_m_loose_1",&id_m_loose_1);
  Tree->SetBranchAddress("pt_2",&pt_2);
  Tree->SetBranchAddress("phi_2",&phi_2);
  Tree->SetBranchAddress("eta_2",&eta_2);
  Tree->SetBranchAddress("m_2",&m_2);
  Tree->SetBranchAddress("e_2",&e_2);
  Tree->SetBranchAddress("q_2",&q_2);
  Tree->SetBranchAddress("d0_2",&d0_2);
  Tree->SetBranchAddress("dZ_2",&dZ_2);
  Tree->SetBranchAddress("iso_2",&iso_2);
  Tree->SetBranchAddress("id_m_medium_2",&id_m_medium_2);
  Tree->SetBranchAddress("id_m_tight_2",&id_m_tight_2);
  Tree->SetBranchAddress("id_m_loose_2",&id_m_loose_2);
  Tree->SetBranchAddress("neutralIsoPtSumdR03_3",&neutralIsoPtSumdR03_3);
  Tree->SetBranchAddress("chargedIsoPtSumdR03_3",&chargedIsoPtSumdR03_3);
  Tree->SetBranchAddress("chargedIsoPtSum_3",&chargedIsoPtSum_3);
  Tree->SetBranchAddress("byLooseCombinedIsolationDeltaBetaCorr3Hits_3",&byLooseCombinedIsolationDeltaBetaCorr3Hits_3);
  Tree->SetBranchAddress("byMediumCombinedIsolationDeltaBetaCorr3Hits_3",&byMediumCombinedIsolationDeltaBetaCorr3Hits_3);
  Tree->SetBranchAddress("byTightCombinedIsolationDeltaBetaCorr3Hits_3",&byTightCombinedIsolationDeltaBetaCorr3Hits_3);
  Tree->SetBranchAddress("byCombinedIsolationDeltaBetaCorrRaw3Hits_3",&byCombinedIsolationDeltaBetaCorrRaw3Hits_3);
  Tree->SetBranchAddress("byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_3",&byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_3);
  Tree->SetBranchAddress("byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_3",&byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_3);
  Tree->SetBranchAddress("byTightCombinedIsolationDeltaBetaCorr3HitsdR03_3",&byTightCombinedIsolationDeltaBetaCorr3HitsdR03_3);
  Tree->SetBranchAddress("byVLooseIsolationMVArun2v1DBnewDMwLT_3",&byVLooseIsolationMVArun2v1DBnewDMwLT_3);
  Tree->SetBranchAddress("byVLooseIsolationMVArun2v1DBoldDMwLT_3",&byVLooseIsolationMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byVLooseIsolationMVArun2v1DBdR03oldDMwLT_3",&byVLooseIsolationMVArun2v1DBdR03oldDMwLT_3);
  Tree->SetBranchAddress("byLooseIsolationMVArun2v1DBnewDMwLT_3",&byLooseIsolationMVArun2v1DBnewDMwLT_3);
  Tree->SetBranchAddress("byLooseIsolationMVArun2v1DBoldDMwLT_3",&byLooseIsolationMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byLooseIsolationMVArun2v1DBdR03oldDMwLT_3",&byLooseIsolationMVArun2v1DBdR03oldDMwLT_3);
  Tree->SetBranchAddress("byMediumIsolationMVArun2v1DBnewDMwLT_3",&byMediumIsolationMVArun2v1DBnewDMwLT_3);
  Tree->SetBranchAddress("byMediumIsolationMVArun2v1DBoldDMwLT_3",&byMediumIsolationMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byMediumIsolationMVArun2v1DBdR03oldDMwLT_3",&byMediumIsolationMVArun2v1DBdR03oldDMwLT_3);
  Tree->SetBranchAddress("byTightIsolationMVArun2v1DBnewDMwLT_3",&byTightIsolationMVArun2v1DBnewDMwLT_3);
  Tree->SetBranchAddress("byTightIsolationMVArun2v1DBoldDMwLT_3",&byTightIsolationMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byTightIsolationMVArun2v1DBdR03oldDMwLT_3",&byTightIsolationMVArun2v1DBdR03oldDMwLT_3);
  Tree->SetBranchAddress("byVTightIsolationMVArun2v1DBnewDMwLT_3",&byVTightIsolationMVArun2v1DBnewDMwLT_3);
  Tree->SetBranchAddress("byVTightIsolationMVArun2v1DBoldDMwLT_3",&byVTightIsolationMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byVTightIsolationMVArun2v1DBdR03oldDMwLT_3",&byVTightIsolationMVArun2v1DBdR03oldDMwLT_3);
  Tree->SetBranchAddress("byVVTightIsolationMVArun2v1DBnewDMwLT_3",&byVVTightIsolationMVArun2v1DBnewDMwLT_3);
  Tree->SetBranchAddress("byVVTightIsolationMVArun2v1DBoldDMwLT_3",&byVVTightIsolationMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byVVTightIsolationMVArun2v1DBdR03oldDMwLT_3",&byVVTightIsolationMVArun2v1DBdR03oldDMwLT_3);
  Tree->SetBranchAddress("byIsolationMVA3oldDMwoLTraw_3",&byIsolationMVA3oldDMwoLTraw_3);
  Tree->SetBranchAddress("byIsolationMVA3oldDMwLTraw_3",&byIsolationMVA3oldDMwLTraw_3);
  Tree->SetBranchAddress("byIsolationMVA3newDMwoLTraw_3",&byIsolationMVA3newDMwoLTraw_3);
  Tree->SetBranchAddress("byIsolationMVA3newDMwLTraw_3",&byIsolationMVA3newDMwLTraw_3);
  Tree->SetBranchAddress("byIsolationMVA3newDMwLTraw_3",&byIsolationMVA3newDMwLTraw_3);
  Tree->SetBranchAddress("byVLooseIsolationRerunMVArun2v1DBoldDMwLT_3",&byVLooseIsolationRerunMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byLooseIsolationRerunMVArun2v1DBoldDMwLT_3",&byLooseIsolationRerunMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byMediumIsolationRerunMVArun2v1DBoldDMwLT_3",&byMediumIsolationRerunMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byTightIsolationRerunMVArun2v1DBoldDMwLT_3",&byTightIsolationRerunMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byVTightIsolationRerunMVArun2v1DBoldDMwLT_3",&byVTightIsolationRerunMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byVVTightIsolationRerunMVArun2v1DBoldDMwLT_3",&byVVTightIsolationRerunMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byIsolationRerunMVA3oldDMwLTraw_3",&byIsolationRerunMVA3oldDMwLTraw_3);
  Tree->SetBranchAddress("byVLooseIsolationRerunMVArun2v2DBoldDMwLT_3",&byVLooseIsolationRerunMVArun2v2DBoldDMwLT_3);
  Tree->SetBranchAddress("byLooseIsolationRerunMVArun2v2DBoldDMwLT_3",&byLooseIsolationRerunMVArun2v2DBoldDMwLT_3);
  Tree->SetBranchAddress("byMediumIsolationRerunMVArun2v2DBoldDMwLT_3",&byMediumIsolationRerunMVArun2v2DBoldDMwLT_3);
  Tree->SetBranchAddress("byTightIsolationRerunMVArun2v2DBoldDMwLT_3",&byTightIsolationRerunMVArun2v2DBoldDMwLT_3);
  Tree->SetBranchAddress("byVTightIsolationRerunMVArun2v2DBoldDMwLT_3",&byVTightIsolationRerunMVArun2v2DBoldDMwLT_3);
  Tree->SetBranchAddress("byVVTightIsolationRerunMVArun2v2DBoldDMwLT_3",&byVVTightIsolationRerunMVArun2v2DBoldDMwLT_3);
  Tree->SetBranchAddress("byIsolationRerunMVA3oldDMwLTrawv2_3",&byIsolationRerunMVA3oldDMwLTrawv2_3);
  Tree->SetBranchAddress("pt_3",&pt_3);
  Tree->SetBranchAddress("phi_3",&phi_3);
  Tree->SetBranchAddress("eta_3",&eta_3);
  Tree->SetBranchAddress("m_3",&m_3);
  Tree->SetBranchAddress("e_3",&e_3);
  Tree->SetBranchAddress("q_3",&q_3);
  Tree->SetBranchAddress("d0_3",&d0_3);
  Tree->SetBranchAddress("dZ_3",&dZ_3);
  Tree->SetBranchAddress("iso_3",&iso_3);
  Tree->SetBranchAddress("l3_decayMode",&l3_decayMode);
  Tree->SetBranchAddress("againstElectronLooseMVA6_3",&againstElectronLooseMVA6_3);
  Tree->SetBranchAddress("againstElectronMediumMVA6_3",&againstElectronMediumMVA6_3);
  Tree->SetBranchAddress("againstElectronTightMVA6_3",&againstElectronTightMVA6_3);
  Tree->SetBranchAddress("againstElectronVLooseMVA6_3",&againstElectronVLooseMVA6_3);
  Tree->SetBranchAddress("againstElectronVTightMVA6_3",&againstElectronVTightMVA6_3);
  Tree->SetBranchAddress("againstMuonLoose3_3",&againstMuonLoose3_3);
  Tree->SetBranchAddress("againstMuonTight3_3",&againstMuonTight3_3);
  Tree->SetBranchAddress("matchIsoMu27_1",&matchIsoMu27_1);
  Tree->SetBranchAddress("matchIsoMu27_2",&matchIsoMu27_2);
  Tree->SetBranchAddress("passIsoMu27",&passIsoMu27);
  Tree->SetBranchAddress("pt_top1",&pt_top1);
  Tree->SetBranchAddress("pt_top2",&pt_top2);
  Tree->SetBranchAddress("genweight",&genweight);
  Tree->SetBranchAddress("gen_match_2",&gen_match_2);
  Tree->SetBranchAddress("gen_match_1",&gen_match_1);
  Tree->SetBranchAddress("met",&met);
  Tree->SetBranchAddress("metphi",&metphi);
  Tree->SetBranchAddress("nbtag",&nbtag);
  Tree->SetBranchAddress("njets",&njets);

  int NumberOfEntries = (int) Tree->GetEntries();
  
  float BaselineSelectedTaus = 0.0;  
  float TausPassVLooseMVAIso = 0.0;
  float TausPassLooseMVAIso = 0.0;
  float TausPassMediumMVAIso = 0.0;
  float TausPassTightMVAIso = 0.0;
  float TausPassVTightMVAIso = 0.0;
  float TausPassVVTightMVAIso = 0.0;

  float DecayMode0BaselineSelectedTaus = 0.0;  
  float DecayMode0TausPassVLooseMVAIso = 0.0;
  float DecayMode0TausPassLooseMVAIso = 0.0;
  float DecayMode0TausPassMediumMVAIso = 0.0;
  float DecayMode0TausPassTightMVAIso = 0.0;
  float DecayMode0TausPassVTightMVAIso = 0.0;
  float DecayMode0TausPassVVTightMVAIso = 0.0;
  
  float DecayMode1BaselineSelectedTaus = 0.0;  
  float DecayMode1TausPassVLooseMVAIso = 0.0;
  float DecayMode1TausPassLooseMVAIso = 0.0;
  float DecayMode1TausPassMediumMVAIso = 0.0;
  float DecayMode1TausPassTightMVAIso = 0.0;
  float DecayMode1TausPassVTightMVAIso = 0.0;
  float DecayMode1TausPassVVTightMVAIso = 0.0;
  
  float DecayMode10BaselineSelectedTaus = 0.0;  
  float DecayMode10TausPassVLooseMVAIso = 0.0;
  float DecayMode10TausPassLooseMVAIso = 0.0;
  float DecayMode10TausPassMediumMVAIso = 0.0;
  float DecayMode10TausPassTightMVAIso = 0.0;
  float DecayMode10TausPassVTightMVAIso = 0.0;
  float DecayMode10TausPassVVTightMVAIso = 0.0;

  float UnrecognizedDecayMode = 0.0;  

  
  Double_t Pt_binning[] = {20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0,  
			   70.0, 75.0, 80.0, 90.0, 100.0, 120.0, 200.0};
  int Pt_binnumber = sizeof(Pt_binning)/sizeof(Double_t) - 1;

  Double_t Eta_binning[] = {0.0, 0.15, 0.3, 0.45, 0.6, 0.75, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9, 2.1, 2.3};
  int Eta_binnumber = sizeof(Eta_binning)/sizeof(Double_t) - 1;


  TH1F* OverallFakeRates = new TH1F("OverallFakeRates","OverallFakeRates",6,0.0,6.0);  
  TH1F* OverallDecayMode0FakeRates = new TH1F("OverallDecayMode0FakeRates","OverallDecayMode0FakeRates",6,0.0,6.0);
  TH1F* OverallDecayMode1FakeRates = new TH1F("OverallDecayMode1FakeRates","OverallDecayMode1FakeRates",6,0.0,6.0);
  TH1F* OverallDecayMode10FakeRates = new TH1F("OverallDecayMode10FakeRates","OverallDecayMode10FakeRates",6,0.0,6.0);
  TH1F* BaselineSelectedTauPT = new TH1F("BasicSelectedTauPT","BasicSlsectedTauPT",Pt_binnumber,Pt_binning);
  TH1F* VLoosePTFakeRates = new TH1F("VLooseFakeRates","VLooseFakeRates",Pt_binnumber,Pt_binning);
  TH1F* LoosePTFakeRates = new TH1F("LooseFakeRates","LooseFakeRates",Pt_binnumber,Pt_binning);
  TH1F* MediumPTFakeRates = new TH1F("MediumFakeRates","MediumFakeRates",Pt_binnumber,Pt_binning);
  TH1F* TightPTFakeRates = new TH1F("TightFakeRates","TightFakeRates",Pt_binnumber,Pt_binning);
  TH1F* VTightPTFakeRates = new TH1F("VTightFakeRates","VTightFakeRates",Pt_binnumber,Pt_binning);
  TH1F* VVTightPTFakeRates = new TH1F("VVTightFakeRates","VVTightFakeRates",Pt_binnumber,Pt_binning);

  //run a similar thing to above where we just split this up by fake rates
  TH1F* BaselineDecayMode0PTFakeRates = new TH1F("BaselineDecayMode0PTFakeRates","BaselineDecayMode0PTFakeRates",Pt_binnumber,Pt_binning);
  TH1F* BaselineDecayMode1PTFakeRates = new TH1F("BaselineDecayMode1PTFakeRates","BaselineDecayMode1PTFakeRates",Pt_binnumber,Pt_binning);
  TH1F* BaselineDecayMode10PTFakeRates = new TH1F("BaselineDecayMode10PTFakeRates","BaselineDecayMode10PTFakeRates",Pt_binnumber,Pt_binning);

  TH1F* VLooseDecayMode0PTFakeRates = new TH1F("VLooseDecayMode0PTFakeRates","VLooseDecayMode0PTFakeRates",Pt_binnumber,Pt_binning);
  TH1F* VLooseDecayMode1PTFakeRates = new TH1F("VLooseDecayMode1PTFakeRates","VLooseDecayMode1PTFakeRates",Pt_binnumber,Pt_binning);
  TH1F* VLooseDecayMode10PTFakeRates = new TH1F("VLooseDecayMode10PTFakeRates","VLooseDecayMode10PTFakeRates",Pt_binnumber,Pt_binning);

  TH1F* LooseDecayMode0PTFakeRates = new TH1F("LooseDecayMode0PTFakeRates","LooseDecayMode0PTFakeRates",Pt_binnumber,Pt_binning);
  TH1F* LooseDecayMode1PTFakeRates = new TH1F("LooseDecayMode1PTFakeRates","LooseDecayMode1PTFakeRates",Pt_binnumber,Pt_binning);
  TH1F* LooseDecayMode10PTFakeRates = new TH1F("LooseDecayMode10PTFakeRates","LooseDecayMode10PTFakeRates",Pt_binnumber,Pt_binning);

  TH1F* MediumDecayMode0PTFakeRates = new TH1F("MediumDecayMode0PTFakeRates","MediumDecayMode0PTFakeRates",Pt_binnumber,Pt_binning);
  TH1F* MediumDecayMode1PTFakeRates = new TH1F("MediumDecayMode1PTFakeRates","MediumDecayMode1PTFakeRates",Pt_binnumber,Pt_binning);
  TH1F* MediumDecayMode10PTFakeRates = new TH1F("MediumDecayMode10PTFakeRates","MediumDecayMode10PTFakeRates",Pt_binnumber,Pt_binning);

  TH1F* TightDecayMode0PTFakeRates = new TH1F("TightDecayMode0PTFakeRates","TightDecayMode0PTFakeRates",Pt_binnumber,Pt_binning);
  TH1F* TightDecayMode1PTFakeRates = new TH1F("TightDecayMode1PTFakeRates","TightDecayMode1PTFakeRates",Pt_binnumber,Pt_binning);
  TH1F* TightDecayMode10PTFakeRates = new TH1F("TightDecayMode10PTFakeRates","TightDecayMode10PTFakeRates",Pt_binnumber,Pt_binning);
  
  TH1F* VTightDecayMode0PTFakeRates = new TH1F("VTightDecayMode0PTFakeRates","VTightDecayMode0PTFakeRates",Pt_binnumber,Pt_binning);
  TH1F* VTightDecayMode1PTFakeRates = new TH1F("VTightDecayMode1PTFakeRates","VTightDecayMode1PTFakeRates",Pt_binnumber,Pt_binning);
  TH1F* VTightDecayMode10PTFakeRates = new TH1F("VTightDecayMode10PTFakeRates","VTightDecayMode10PTFakeRates",Pt_binnumber,Pt_binning);

  TH1F* VVTightDecayMode0PTFakeRates = new TH1F("VVTightDecayMode0PTFakeRates","VVTightDecayMode0PTFakeRates",Pt_binnumber,Pt_binning);
  TH1F* VVTightDecayMode1PTFakeRates = new TH1F("VVTightDecayMode1PTFakeRates","VVTightDecayMode1PTFakeRates",Pt_binnumber,Pt_binning);
  TH1F* VVTightDecayMode10PTFakeRates = new TH1F("VVTightDecayMode10PTFakeRates","VVTightDecayMode10PTFakeRates",Pt_binnumber,Pt_binning);
  
  //This has problems. it stretches the stats too thin.
  //Pt in x, |eta| in y
  TH2F* BaselineReconstructionDecayMode0 = new TH2F("BaselineReconstructionDecayMode0","BaselineReconstructionDecayMode0", Pt_binnumber, Pt_binning, Eta_binnumber,Eta_binning);
  TH2F* BaselineReconstructionDecayMode1 = new TH2F("BaselineReconstructionDecayMode1","BaselineReconstructionDecayMode1", Pt_binnumber, Pt_binning, Eta_binnumber,Eta_binning);
  TH2F* BaselineReconstructionDecayMode10 = new TH2F("BaselineReconstructionDecayMode10","BaselineReconstructionDecayMode10", Pt_binnumber, Pt_binning, Eta_binnumber,Eta_binning);

  TH2F* VLooseDecayMode0FakeRates = new TH2F("VLooseDecayMode0FakeRates","VLooseDecayMode0FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  TH2F* VLooseDecayMode1FakeRates = new TH2F("VLooseDecayMode1FakeRates","VLooseDecayMode1FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  TH2F* VLooseDecayMode10FakeRates = new TH2F("VLooseDecayMode10FakeRates","VLooseDecayMode10FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  
  TH2F* LooseDecayMode0FakeRates = new TH2F("LooseDecayMode0FakeRates","LooseDecayMode0FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  TH2F* LooseDecayMode1FakeRates = new TH2F("LooseDecayMode1FakeRates","LooseDecayMode1FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  TH2F* LooseDecayMode10FakeRates = new TH2F("LooseDecayMode10FakeRates","LooseDecayMode10FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  
  TH2F* MediumDecayMode0FakeRates = new TH2F("MediumDecayMode0FakeRates","MediumDecayMode0FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  TH2F* MediumDecayMode1FakeRates = new TH2F("MediumDecayMode1FakeRates","MediumDecayMode1FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  TH2F* MediumDecayMode10FakeRates = new TH2F("MediumDecayMode10FakeRates","MediumDecayMode10FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);

  TH2F* TightDecayMode0FakeRates = new TH2F("TightDecayMode0FakeRates","TightDecayMode0FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  TH2F* TightDecayMode1FakeRates = new TH2F("TightDecayMode1FakeRates","TightDecayMode1FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  TH2F* TightDecayMode10FakeRates = new TH2F("TightDecayMode10FakeRates","TightDecayMode10FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);

  TH2F* VTightDecayMode0FakeRates = new TH2F("VTightDecayMode0FakeRates","VTightDecayMode0FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  TH2F* VTightDecayMode1FakeRates = new TH2F("VTightDecayMode1FakeRates","VTightDecayMode1FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  TH2F* VTightDecayMode10FakeRates = new TH2F("VTightDecayMode10FakeRates","VTightDecayMode10FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  
  TH2F* VVTightDecayMode0FakeRates = new TH2F("VVTightDecayMode0FakeRates","VVTightDecayMode0FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  TH2F* VVTightDecayMode1FakeRates = new TH2F("VVTightDecayMode1FakeRates","VVTightDecayMode1FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
  TH2F* VVTightDecayMode10FakeRates = new TH2F("VVTightDecayMode10FakeRates","VVTightDecayMode10FakeRates",Pt_binnumber,Pt_binning, Eta_binnumber,Eta_binning);
      
  std::cout<<"Number of Entries: "<<NumberOfEntries<<std::endl;

  //loop over the entries and pick out events that meet loose tau reconstruction, 
  // but fail on closer scrutiny. These will be the Jets faking to Taus
  for(int i=0;i<NumberOfEntries;i++)
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

      // get three lorentz vectors going. first two are muons, the third is a tau
      TLorentzVector l1; l1.SetPtEtaPhiE(pt_1,eta_1,phi_1,e_1); //muon 1
      TLorentzVector l2; l2.SetPtEtaPhiE(pt_2,eta_2,phi_2,e_2); //muon 2
      TLorentzVector l3; l3.SetPtEtaPhiE(pt_3,eta_3,phi_3,e_3); //tau 3

      //make sure we pass some muon selection?
      //I guess we just do the same muon region as the actually mt region to make 
      // we get as close to possible to the actual region we care about?
      
      //match diego's pt > 30 cut as opposed to my original 29.0 cut
      if(pt_1 < 30.0 or std::abs(eta_1) > 2.4 or !id_m_medium_1 or iso_1 > 0.15 or std::abs(dZ_1) > 0.2 or std::abs(d0_1) > 0.045 or !matchIsoMu27_1) continue;
      
      if(pt_2 < 30.0 or std::abs(eta_2) > 2.4 or !id_m_medium_2 or iso_2 > 0.15 or std::abs(dZ_2) > 0.2 or std::abs(d0_2) > 0.045 or !matchIsoMu27_2) continue;
      
      //We'll do some loose selection of tau stuff, saving the  
      if(pt_3 < 20.0 or std::abs(eta_3) > 2.3 or againstElectronVLooseMVA6_3 != 1 or againstMuonTight3_3 != 1 /*or !decayModeFinding_3*/ /*or std::abs(dZ_3) > 0.2*/) continue;      
      
      // the only sort of other criteria we'll require is stringent selection of a Z mass
      // should we also require opposite sign mu's to ensure the Z decay?
      // may as well?
      if((l1+l2).M() <= 80.0 or (l1+l2).M() >= 100.0 or q_1*q_2 > 0) continue;
      
      // okay we should now be working witha Z decay to mu's and what is nominally a tau
      BaselineSelectedTaus += 1.0;
      BaselineSelectedTauPT->Fill(pt_3);
      if(l3_decayMode == 0)
	{
	  BaselineReconstructionDecayMode0->Fill(pt_3,std::abs(eta_3));
	  BaselineDecayMode0PTFakeRates->Fill(pt_3);
	  DecayMode0BaselineSelectedTaus += 1.0;
	}
      else if (l3_decayMode == 1)
	{
	  BaselineReconstructionDecayMode1->Fill(pt_3,std::abs(eta_3));
	  BaselineDecayMode1PTFakeRates->Fill(pt_3);
	  DecayMode1BaselineSelectedTaus += 1.0;
	}
      else if (l3_decayMode == 10)
	{
	  BaselineReconstructionDecayMode10->Fill(pt_3,std::abs(eta_3));
	  BaselineDecayMode10PTFakeRates->Fill(pt_3);
	  DecayMode10BaselineSelectedTaus += 1.0;
	}
      else
	{
	  UnrecognizedDecayMode+=1.0;
	}
      
      if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_3) 
	{
	  TausPassVLooseMVAIso+=1.0;
	  VLoosePTFakeRates->Fill(pt_3);
	  if(l3_decayMode == 0)
	    {
	      VLooseDecayMode0FakeRates->Fill(pt_3,std::abs(eta_3));
	      VLooseDecayMode0PTFakeRates->Fill(pt_3);
	      DecayMode0TausPassVLooseMVAIso+=1.0;
	    }
	  else if(l3_decayMode == 1)
	    {
	      VLooseDecayMode1FakeRates->Fill(pt_3,std::abs(eta_3));
	      VLooseDecayMode1PTFakeRates->Fill(pt_3);
	      DecayMode1TausPassVLooseMVAIso+=1.0;
	    }
	  else if(l3_decayMode == 10)
	    {
	      VLooseDecayMode10FakeRates->Fill(pt_3,std::abs(eta_3));
	      VLooseDecayMode10PTFakeRates->Fill(pt_3);
	      DecayMode10TausPassVLooseMVAIso+=1.0;
	    }
	  else
	    {
	      UnrecognizedDecayMode+=1.0;
	    }
	}
      if(byLooseIsolationRerunMVArun2v2DBoldDMwLT_3)
	{ 
	  TausPassLooseMVAIso+=1.0;
	  LoosePTFakeRates->Fill(pt_3);
	  if(l3_decayMode == 0)
	    {
	      LooseDecayMode0FakeRates->Fill(pt_3,std::abs(eta_3));
	      LooseDecayMode0PTFakeRates->Fill(pt_3);
	      DecayMode0TausPassLooseMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 1)
	    {
	      LooseDecayMode1FakeRates->Fill(pt_3,std::abs(eta_3));
	      LooseDecayMode1PTFakeRates->Fill(pt_3);
	      DecayMode1TausPassLooseMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 10)
	    {
	      LooseDecayMode10FakeRates->Fill(pt_3,std::abs(eta_3));
	      LooseDecayMode10PTFakeRates->Fill(pt_3);
	      DecayMode10TausPassLooseMVAIso+=1.0;
	    }
	  else
	    {
	      UnrecognizedDecayMode+=1.0;
	    }
	}
      if(byMediumIsolationRerunMVArun2v2DBoldDMwLT_3)
	{ 
	  TausPassMediumMVAIso+=1.0;
	  MediumPTFakeRates->Fill(pt_3);
	  if(l3_decayMode == 0)
	    {
	      MediumDecayMode0FakeRates->Fill(pt_3,std::abs(eta_3));
	      MediumDecayMode0PTFakeRates->Fill(pt_3);
	      DecayMode0TausPassMediumMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 1)
	    {
	      MediumDecayMode1FakeRates->Fill(pt_3,std::abs(eta_3));
	      MediumDecayMode1PTFakeRates->Fill(pt_3);
	      DecayMode1TausPassMediumMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 10)
	    {
	      MediumDecayMode10FakeRates->Fill(pt_3,std::abs(eta_3));
	      MediumDecayMode10PTFakeRates->Fill(pt_3);
	      DecayMode10TausPassMediumMVAIso+=1.0;
	    }
	  else
	    {
	      UnrecognizedDecayMode+=1.0;
	    }
	}
      if(byTightIsolationRerunMVArun2v2DBoldDMwLT_3) 
	{
	  TausPassTightMVAIso+=1.0;
	  TightPTFakeRates->Fill(pt_3);
	  if(l3_decayMode == 0)
	    {
	      TightDecayMode0FakeRates->Fill(pt_3,std::abs(eta_3));
	      TightDecayMode0PTFakeRates->Fill(pt_3);
	      DecayMode0TausPassTightMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 1)
	    {
	      TightDecayMode1FakeRates->Fill(pt_3,std::abs(eta_3));
	      TightDecayMode1PTFakeRates->Fill(pt_3);
	      DecayMode1TausPassTightMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 10)
	    {
	      TightDecayMode10FakeRates->Fill(pt_3,std::abs(eta_3));
	      TightDecayMode10PTFakeRates->Fill(pt_3);
	      DecayMode10TausPassTightMVAIso+=1.0;
	    }
	  else
	    {
	      UnrecognizedDecayMode+=1.0;
	    }
	}
      if(byVTightIsolationRerunMVArun2v2DBoldDMwLT_3) 
	{
	  TausPassVTightMVAIso+=1.0;
	  VTightPTFakeRates->Fill(pt_3);
	  if(l3_decayMode == 0)
	    {
	      VTightDecayMode0FakeRates->Fill(pt_3,std::abs(eta_3));
	      VTightDecayMode0PTFakeRates->Fill(pt_3);
	      DecayMode0TausPassVTightMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 1)
	    {
	      VTightDecayMode1FakeRates->Fill(pt_3,std::abs(eta_3));
	      VTightDecayMode1PTFakeRates->Fill(pt_3);
	      DecayMode1TausPassVTightMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 10)
	    {
	      VTightDecayMode10FakeRates->Fill(pt_3,std::abs(eta_3));
	      VTightDecayMode10PTFakeRates->Fill(pt_3);
	      DecayMode10TausPassVTightMVAIso+=1.0;
	    }
	  else
	    {
	      UnrecognizedDecayMode+=1.0;
	    }
	}
      if(byVVTightIsolationRerunMVArun2v2DBoldDMwLT_3) 
	{
	  TausPassVVTightMVAIso+=1.0;
	  VVTightPTFakeRates->Fill(pt_3);
	  if(l3_decayMode == 0)
	    {
	      VVTightDecayMode0FakeRates->Fill(pt_3,std::abs(eta_3));
	      VVTightDecayMode0PTFakeRates->Fill(pt_3);
	      DecayMode0TausPassVVTightMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 1)
	    {
	      VVTightDecayMode1FakeRates->Fill(pt_3,std::abs(eta_3));
	      VVTightDecayMode1PTFakeRates->Fill(pt_3);
	      DecayMode1TausPassVVTightMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 10)
	    {
	      VVTightDecayMode10FakeRates->Fill(pt_3,std::abs(eta_3));
	      VVTightDecayMode10PTFakeRates->Fill(pt_3);
	      DecayMode10TausPassVVTightMVAIso+=1.0;
	    }
	  else
	    {
	      UnrecognizedDecayMode+=1.0;
	    }
	}

    }

  std::cout<<"BaselineSelectedTaus: "<<BaselineSelectedTaus<<std::endl;  
  std::cout<<"TausPassVLooseIso: "<<TausPassVLooseMVAIso<<std::endl;
  std::cout<<"TausPassLooseIso: "<<TausPassLooseMVAIso<<std::endl;
  std::cout<<"TausPassMediumIso: "<<TausPassMediumMVAIso<<std::endl;
  std::cout<<"TausPassTightIso: "<<TausPassTightMVAIso<<std::endl;
  std::cout<<"TausPassVTightIso: "<<TausPassVTightMVAIso<<std::endl;
  std::cout<<"TausPassVVTightIso: "<<TausPassVVTightMVAIso<<std::endl;

  // create the ratios.
  float VLooseFakeRate = TausPassVLooseMVAIso/BaselineSelectedTaus;
  float LooseFakeRate = TausPassLooseMVAIso/TausPassVLooseMVAIso;
  float MediumFakeRate = TausPassMediumMVAIso/TausPassVLooseMVAIso;
  float TightFakeRate = TausPassTightMVAIso/TausPassVLooseMVAIso;
  float VTightFakeRate = TausPassVTightMVAIso/TausPassVLooseMVAIso;
  float VVTightFakeRate = TausPassVVTightMVAIso/TausPassVLooseMVAIso;

  float DecayMode0VLooseFakeRate = DecayMode0TausPassVLooseMVAIso/DecayMode0BaselineSelectedTaus;
  float DecayMode0LooseFakeRate = DecayMode0TausPassLooseMVAIso/DecayMode0TausPassVLooseMVAIso;
  float DecayMode0MediumFakeRate = DecayMode0TausPassMediumMVAIso/DecayMode0TausPassVLooseMVAIso;
  float DecayMode0TightFakeRate = DecayMode0TausPassTightMVAIso/DecayMode0TausPassVLooseMVAIso;
  float DecayMode0VTightFakeRate = DecayMode0TausPassVTightMVAIso/DecayMode0TausPassVLooseMVAIso;
  float DecayMode0VVTightFakeRate = DecayMode0TausPassVVTightMVAIso/DecayMode0TausPassVLooseMVAIso;
  
  float DecayMode1VLooseFakeRate = DecayMode1TausPassVLooseMVAIso/DecayMode1BaselineSelectedTaus;
  float DecayMode1LooseFakeRate = DecayMode1TausPassLooseMVAIso/DecayMode1TausPassVLooseMVAIso;
  float DecayMode1MediumFakeRate = DecayMode1TausPassMediumMVAIso/DecayMode1TausPassVLooseMVAIso;
  float DecayMode1TightFakeRate = DecayMode1TausPassTightMVAIso/DecayMode1TausPassVLooseMVAIso;
  float DecayMode1VTightFakeRate = DecayMode1TausPassVTightMVAIso/DecayMode1TausPassVLooseMVAIso;
  float DecayMode1VVTightFakeRate = DecayMode1TausPassVVTightMVAIso/DecayMode1TausPassVLooseMVAIso;

  float DecayMode10VLooseFakeRate = DecayMode10TausPassVLooseMVAIso/DecayMode10BaselineSelectedTaus;
  float DecayMode10LooseFakeRate = DecayMode10TausPassLooseMVAIso/DecayMode10TausPassVLooseMVAIso;
  float DecayMode10MediumFakeRate = DecayMode10TausPassMediumMVAIso/DecayMode10TausPassVLooseMVAIso;
  float DecayMode10TightFakeRate = DecayMode10TausPassTightMVAIso/DecayMode10TausPassVLooseMVAIso;
  float DecayMode10VTightFakeRate = DecayMode10TausPassVTightMVAIso/DecayMode10TausPassVLooseMVAIso;
  float DecayMode10VVTightFakeRate = DecayMode10TausPassVVTightMVAIso/DecayMode10TausPassVLooseMVAIso;
  
  std::cout<<std::endl;
  std::cout<<"VLooseFakeRate: "<<VLooseFakeRate<<std::endl;
  std::cout<<"LooseFakeRate: "<<LooseFakeRate<<std::endl;
  std::cout<<"MediumFakeRate: "<<MediumFakeRate<<std::endl;
  std::cout<<"TightFakeRate: "<<TightFakeRate<<std::endl;
  std::cout<<"VTightFakeRate: "<<VTightFakeRate<<std::endl;
  std::cout<<"VVTightFakeRate: "<<VVTightFakeRate<<std::endl;
  std::cout<<std::endl;
  
  OverallFakeRates->SetBinContent(1,VLooseFakeRate);
  OverallFakeRates->SetBinContent(2,LooseFakeRate);
  OverallFakeRates->SetBinContent(3,MediumFakeRate);
  OverallFakeRates->SetBinContent(4,TightFakeRate);
  OverallFakeRates->SetBinContent(5,VTightFakeRate);
  OverallFakeRates->SetBinContent(6,VVTightFakeRate);

  OverallDecayMode0FakeRates->SetBinContent(1,DecayMode0VLooseFakeRate);
  OverallDecayMode0FakeRates->SetBinContent(2,DecayMode0LooseFakeRate);
  OverallDecayMode0FakeRates->SetBinContent(3,DecayMode0MediumFakeRate);
  OverallDecayMode0FakeRates->SetBinContent(4,DecayMode0TightFakeRate);
  OverallDecayMode0FakeRates->SetBinContent(5,DecayMode0VTightFakeRate);
  OverallDecayMode0FakeRates->SetBinContent(6,DecayMode0VVTightFakeRate);

  OverallDecayMode1FakeRates->SetBinContent(1,DecayMode1VLooseFakeRate);
  OverallDecayMode1FakeRates->SetBinContent(2,DecayMode1LooseFakeRate);
  OverallDecayMode1FakeRates->SetBinContent(3,DecayMode1MediumFakeRate);
  OverallDecayMode1FakeRates->SetBinContent(4,DecayMode1TightFakeRate);
  OverallDecayMode1FakeRates->SetBinContent(5,DecayMode1VTightFakeRate);
  OverallDecayMode1FakeRates->SetBinContent(6,DecayMode1VVTightFakeRate);

  OverallDecayMode10FakeRates->SetBinContent(1,DecayMode10VLooseFakeRate);
  OverallDecayMode10FakeRates->SetBinContent(2,DecayMode10LooseFakeRate);
  OverallDecayMode10FakeRates->SetBinContent(3,DecayMode10MediumFakeRate);
  OverallDecayMode10FakeRates->SetBinContent(4,DecayMode10TightFakeRate);
  OverallDecayMode10FakeRates->SetBinContent(5,DecayMode10VTightFakeRate);
  OverallDecayMode10FakeRates->SetBinContent(6,DecayMode10VVTightFakeRate);

  OverallFakeRates->GetXaxis()->SetBinLabel(1,"VLooseFakeRate");
  OverallFakeRates->GetXaxis()->SetBinLabel(2,"LooseFakeRates");
  OverallFakeRates->GetXaxis()->SetBinLabel(3,"MediumFakeRates");
  OverallFakeRates->GetXaxis()->SetBinLabel(4,"TightFakeRates");
  OverallFakeRates->GetXaxis()->SetBinLabel(5,"VTightFakeRates");
  OverallFakeRates->GetXaxis()->SetBinLabel(6,"VVTightFakeRates");

  OverallDecayMode0FakeRates->GetXaxis()->SetBinLabel(1,"VLooseFakeRate");
  OverallDecayMode0FakeRates->GetXaxis()->SetBinLabel(2,"LooseFakeRates");
  OverallDecayMode0FakeRates->GetXaxis()->SetBinLabel(3,"MediumFakeRates");
  OverallDecayMode0FakeRates->GetXaxis()->SetBinLabel(4,"TightFakeRates");
  OverallDecayMode0FakeRates->GetXaxis()->SetBinLabel(5,"VTightFakeRates");
  OverallDecayMode0FakeRates->GetXaxis()->SetBinLabel(6,"VVTightFakeRates");

  OverallDecayMode1FakeRates->GetXaxis()->SetBinLabel(1,"VLooseFakeRate");
  OverallDecayMode1FakeRates->GetXaxis()->SetBinLabel(2,"LooseFakeRates");
  OverallDecayMode1FakeRates->GetXaxis()->SetBinLabel(3,"MediumFakeRates");
  OverallDecayMode1FakeRates->GetXaxis()->SetBinLabel(4,"TightFakeRates");
  OverallDecayMode1FakeRates->GetXaxis()->SetBinLabel(5,"VTightFakeRates");
  OverallDecayMode1FakeRates->GetXaxis()->SetBinLabel(6,"VVTightFakeRates");

  OverallDecayMode10FakeRates->GetXaxis()->SetBinLabel(1,"VLooseFakeRate");
  OverallDecayMode10FakeRates->GetXaxis()->SetBinLabel(2,"LooseFakeRates");
  OverallDecayMode10FakeRates->GetXaxis()->SetBinLabel(3,"MediumFakeRates");
  OverallDecayMode10FakeRates->GetXaxis()->SetBinLabel(4,"TightFakeRates");
  OverallDecayMode10FakeRates->GetXaxis()->SetBinLabel(5,"VTightFakeRates");
  OverallDecayMode10FakeRates->GetXaxis()->SetBinLabel(6,"VVTightFakeRates");
  
  //create the pt distributions fake rate distributions
  BaselineSelectedTauPT->Sumw2();
  VVTightPTFakeRates->Sumw2();
  VTightPTFakeRates->Sumw2();
  TightPTFakeRates->Sumw2();
  MediumPTFakeRates->Sumw2();
  LoosePTFakeRates->Sumw2();
  VLoosePTFakeRates->Sumw2();
  
  VVTightPTFakeRates->Divide(VLoosePTFakeRates);
  VTightPTFakeRates->Divide(VLoosePTFakeRates);
  TightPTFakeRates->Divide(VLoosePTFakeRates);
  MediumPTFakeRates->Divide(VLoosePTFakeRates);
  LoosePTFakeRates->Divide(VLoosePTFakeRates);
  VLoosePTFakeRates->Divide(BaselineSelectedTauPT);

  //errors
  BaselineDecayMode0PTFakeRates->Sumw2();
  BaselineDecayMode1PTFakeRates->Sumw2();
  BaselineDecayMode10PTFakeRates->Sumw2();
  
  VLooseDecayMode0PTFakeRates->Sumw2();
  VLooseDecayMode1PTFakeRates->Sumw2();
  VLooseDecayMode10PTFakeRates->Sumw2();

  LooseDecayMode0PTFakeRates->Sumw2();
  LooseDecayMode1PTFakeRates->Sumw2();
  LooseDecayMode10PTFakeRates->Sumw2();

  MediumDecayMode0PTFakeRates->Sumw2();
  MediumDecayMode1PTFakeRates->Sumw2();
  MediumDecayMode10PTFakeRates->Sumw2();

  TightDecayMode0PTFakeRates->Sumw2();
  TightDecayMode1PTFakeRates->Sumw2();
  TightDecayMode10PTFakeRates->Sumw2();

  VTightDecayMode0PTFakeRates->Sumw2();
  VTightDecayMode1PTFakeRates->Sumw2();
  VTightDecayMode10PTFakeRates->Sumw2();

  VVTightDecayMode0PTFakeRates->Sumw2();
  VVTightDecayMode1PTFakeRates->Sumw2();
  VVTightDecayMode10PTFakeRates->Sumw2();

  //Division
  VVTightDecayMode0PTFakeRates->Divide(VLooseDecayMode0PTFakeRates);
  VVTightDecayMode1PTFakeRates->Divide(VLooseDecayMode1PTFakeRates);
  VVTightDecayMode10PTFakeRates->Divide(VLooseDecayMode10PTFakeRates);

  VTightDecayMode0PTFakeRates->Divide(VLooseDecayMode0PTFakeRates);
  VTightDecayMode1PTFakeRates->Divide(VLooseDecayMode1PTFakeRates);
  VTightDecayMode10PTFakeRates->Divide(VLooseDecayMode10PTFakeRates);

  TightDecayMode0PTFakeRates->Divide(VLooseDecayMode0PTFakeRates);
  TightDecayMode1PTFakeRates->Divide(VLooseDecayMode1PTFakeRates);
  TightDecayMode10PTFakeRates->Divide(VLooseDecayMode10PTFakeRates);

  MediumDecayMode0PTFakeRates->Divide(VLooseDecayMode0PTFakeRates);
  MediumDecayMode1PTFakeRates->Divide(VLooseDecayMode1PTFakeRates);
  MediumDecayMode10PTFakeRates->Divide(VLooseDecayMode10PTFakeRates);

  LooseDecayMode0PTFakeRates->Divide(VLooseDecayMode0PTFakeRates);
  LooseDecayMode1PTFakeRates->Divide(VLooseDecayMode1PTFakeRates);
  LooseDecayMode10PTFakeRates->Divide(VLooseDecayMode10PTFakeRates);

  VLooseDecayMode0PTFakeRates->Divide(BaselineDecayMode0PTFakeRates);
  VLooseDecayMode1PTFakeRates->Divide(BaselineDecayMode1PTFakeRates);
  VLooseDecayMode10PTFakeRates->Divide(BaselineDecayMode10PTFakeRates);

  //errors
  BaselineReconstructionDecayMode0->Sumw2();
  BaselineReconstructionDecayMode1->Sumw2();
  BaselineReconstructionDecayMode10->Sumw2();
  
  VLooseDecayMode0FakeRates->Sumw2();
  VLooseDecayMode1FakeRates->Sumw2();
  VLooseDecayMode10FakeRates->Sumw2();

  LooseDecayMode0FakeRates->Sumw2();
  LooseDecayMode1FakeRates->Sumw2();
  LooseDecayMode10FakeRates->Sumw2();

  MediumDecayMode0FakeRates->Sumw2();
  MediumDecayMode1FakeRates->Sumw2();
  MediumDecayMode10FakeRates->Sumw2();

  TightDecayMode0FakeRates->Sumw2();
  TightDecayMode1FakeRates->Sumw2();
  TightDecayMode10FakeRates->Sumw2();

  VTightDecayMode0FakeRates->Sumw2();
  VTightDecayMode1FakeRates->Sumw2();
  VTightDecayMode10FakeRates->Sumw2();

  VVTightDecayMode0FakeRates->Sumw2();
  VVTightDecayMode1FakeRates->Sumw2();
  VVTightDecayMode10FakeRates->Sumw2();

  //Division
  VVTightDecayMode0FakeRates->Divide(VLooseDecayMode0FakeRates);
  VVTightDecayMode1FakeRates->Divide(VLooseDecayMode1FakeRates);
  VVTightDecayMode10FakeRates->Divide(VLooseDecayMode10FakeRates);

  VTightDecayMode0FakeRates->Divide(VLooseDecayMode0FakeRates);
  VTightDecayMode1FakeRates->Divide(VLooseDecayMode1FakeRates);
  VTightDecayMode10FakeRates->Divide(VLooseDecayMode10FakeRates);  

  TightDecayMode0FakeRates->Divide(VLooseDecayMode0FakeRates);
  TightDecayMode1FakeRates->Divide(VLooseDecayMode1FakeRates);
  TightDecayMode10FakeRates->Divide(VLooseDecayMode10FakeRates);  

  MediumDecayMode0FakeRates->Divide(VLooseDecayMode0FakeRates);
  MediumDecayMode1FakeRates->Divide(VLooseDecayMode1FakeRates);
  MediumDecayMode10FakeRates->Divide(VLooseDecayMode10FakeRates);  
  
  LooseDecayMode0FakeRates->Divide(VLooseDecayMode0FakeRates);
  LooseDecayMode1FakeRates->Divide(VLooseDecayMode1FakeRates);
  LooseDecayMode10FakeRates->Divide(VLooseDecayMode10FakeRates);    

  VLooseDecayMode0FakeRates->Divide(BaselineReconstructionDecayMode0);
  VLooseDecayMode1FakeRates->Divide(BaselineReconstructionDecayMode1);
  VLooseDecayMode10FakeRates->Divide(BaselineReconstructionDecayMode10);  
  
  VLooseDecayMode0FakeRates->SetOption("COLZ");
  VLooseDecayMode1FakeRates->SetOption("COLZ");
  VLooseDecayMode10FakeRates->SetOption("COLZ");

  LooseDecayMode0FakeRates->SetOption("COLZ");
  LooseDecayMode1FakeRates->SetOption("COLZ");
  LooseDecayMode10FakeRates->SetOption("COLZ");

  MediumDecayMode0FakeRates->SetOption("COLZ");
  MediumDecayMode1FakeRates->SetOption("COLZ");
  MediumDecayMode10FakeRates->SetOption("COLZ");

  TightDecayMode0FakeRates->SetOption("COLZ");
  TightDecayMode1FakeRates->SetOption("COLZ");
  TightDecayMode10FakeRates->SetOption("COLZ");

  VTightDecayMode0FakeRates->SetOption("COLZ");
  VTightDecayMode1FakeRates->SetOption("COLZ");
  VTightDecayMode10FakeRates->SetOption("COLZ");

  VVTightDecayMode0FakeRates->SetOption("COLZ");
  VVTightDecayMode1FakeRates->SetOption("COLZ");
  VVTightDecayMode10FakeRates->SetOption("COLZ");

  TFile* FakeRateFile = new TFile("../Distributions/FakeRateDistributions.root","RECREATE");
  OverallFakeRates->Write();
  OverallDecayMode0FakeRates->Write();
  OverallDecayMode1FakeRates->Write();
  OverallDecayMode10FakeRates->Write();
  VLoosePTFakeRates->Write();
  LoosePTFakeRates->Write();
  MediumPTFakeRates->Write();
  TightPTFakeRates->Write();
  VTightPTFakeRates->Write();
  VVTightPTFakeRates->Write();

  VVTightDecayMode0PTFakeRates->Write();
  VVTightDecayMode1PTFakeRates->Write();
  VVTightDecayMode10PTFakeRates->Write();

  VTightDecayMode0PTFakeRates->Write();
  VTightDecayMode1PTFakeRates->Write();
  VTightDecayMode10PTFakeRates->Write();

  TightDecayMode0PTFakeRates->Write();
  TightDecayMode1PTFakeRates->Write();
  TightDecayMode10PTFakeRates->Write();

  MediumDecayMode0PTFakeRates->Write();
  MediumDecayMode1PTFakeRates->Write();
  MediumDecayMode10PTFakeRates->Write();

  LooseDecayMode0PTFakeRates->Write();
  LooseDecayMode1PTFakeRates->Write();
  LooseDecayMode10PTFakeRates->Write();

  VLooseDecayMode0PTFakeRates->Write();
  VLooseDecayMode1PTFakeRates->Write();
  VLooseDecayMode10PTFakeRates->Write();

  VLooseDecayMode0FakeRates->Write();
  VLooseDecayMode1FakeRates->Write();
  VLooseDecayMode10FakeRates->Write();

  LooseDecayMode0FakeRates->Write();
  LooseDecayMode1FakeRates->Write();
  LooseDecayMode10FakeRates->Write();

  MediumDecayMode0FakeRates->Write();
  MediumDecayMode1FakeRates->Write();
  MediumDecayMode10FakeRates->Write();

  TightDecayMode0FakeRates->Write();
  TightDecayMode1FakeRates->Write();
  TightDecayMode10FakeRates->Write();

  VTightDecayMode0FakeRates->Write();
  VTightDecayMode1FakeRates->Write();
  VTightDecayMode10FakeRates->Write();

  VVTightDecayMode0FakeRates->Write();
  VVTightDecayMode1FakeRates->Write();
  VVTightDecayMode10FakeRates->Write();

  FakeRateFile->Close();
}
