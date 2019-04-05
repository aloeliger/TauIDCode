#include "TROOT.h"
#include <cmath>
#include "/data/aloeliger/CMSSW_9_4_0/src/PhysicsTools/Utilities/interface/LumiReweightingStandAlone.h"
#include "../Zpt/zptweight.C"

void JetToTauFakesMeasurement(std::string Input)
{
  TFile* TheFile = new TFile(("/data/aloeliger/CMSSW_9_4_0/src/SMHTTAnalysis/SkimmedNtuples/TauID2017_mmt/"+Input+".root").c_str());
  TTree* Tree = (TTree*) TheFile->Get("mutau_tree");
  TH1F* nevents = (TH1F*) TheFile->Get("summedWeights");
  float TotalNumberOfEvents = nevents->GetBinContent(1);

  //Setup the run branches
  UInt_t run,lumi;
  Float_t evt;
  int NUP;
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
  Float_t nbtag,njets;
  //new things
  Float_t gen_match_3;
  Float_t genM;
  Float_t genpT;

  Tree->SetBranchAddress("run",&run);
  Tree->SetBranchAddress("lumi",&lumi);
  Tree->SetBranchAddress("evt",&evt);
  //Tree->SetBranchAddress("NUP",&NUP);
  Tree->SetBranchAddress("npv",&npv);
  Tree->SetBranchAddress("npu",&npu);
  Tree->SetBranchAddress("numGenJets",&numGenJets);
  Tree->SetBranchAddress("aMCatNLO_weight",&amcatNLO_weight);
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
  Tree->SetBranchAddress("id_m_loose_1",&id_m_loose_1);
  Tree->SetBranchAddress("pt_2",&pt_2);
  Tree->SetBranchAddress("phi_2",&phi_2);
  Tree->SetBranchAddress("eta_2",&eta_2);
  Tree->SetBranchAddress("m_2",&m_2);
  //Tree->SetBranchAddress("e_2",&e_2);
  Tree->SetBranchAddress("q_2",&q_2);
  Tree->SetBranchAddress("d0_2",&d0_2);
  Tree->SetBranchAddress("dZ_2",&dZ_2);
  Tree->SetBranchAddress("iso_2",&iso_2);
  Tree->SetBranchAddress("id_m_medium_2",&id_m_medium_2);
  Tree->SetBranchAddress("id_m_tight_2",&id_m_tight_2);
  Tree->SetBranchAddress("id_m_loose_2",&id_m_loose_2);
  //Tree->SetBranchAddress("neutralIsoPtSumdR03_3",&neutralIsoPtSumdR03_3);
  //Tree->SetBranchAddress("chargedIsoPtSumdR03_3",&chargedIsoPtSumdR03_3);
  //Tree->SetBranchAddress("chargedIsoPtSum_3",&chargedIsoPtSum_3);
  //Tree->SetBranchAddress("byLooseCombinedIsolationDeltaBetaCorr3Hits_3",&byLooseCombinedIsolationDeltaBetaCorr3Hits_3);
  //Tree->SetBranchAddress("byMediumCombinedIsolationDeltaBetaCorr3Hits_3",&byMediumCombinedIsolationDeltaBetaCorr3Hits_3);
  //Tree->SetBranchAddress("byTightCombinedIsolationDeltaBetaCorr3Hits_3",&byTightCombinedIsolationDeltaBetaCorr3Hits_3);
  Tree->SetBranchAddress("byCombinedIsolationDeltaBetaCorrRaw3Hits_3",&byCombinedIsolationDeltaBetaCorrRaw3Hits_3);
  //Tree->SetBranchAddress("byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_3",&byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_3);
  //Tree->SetBranchAddress("byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_3",&byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_3);
  //Tree->SetBranchAddress("byTightCombinedIsolationDeltaBetaCorr3HitsdR03_3",&byTightCombinedIsolationDeltaBetaCorr3HitsdR03_3);
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
  //Tree->SetBranchAddress("byIsolationMVA3oldDMwoLTraw_3",&byIsolationMVA3oldDMwoLTraw_3);
  Tree->SetBranchAddress("byIsolationMVA3oldDMwLTraw_3",&byIsolationMVA3oldDMwLTraw_3);
  Tree->SetBranchAddress("byIsolationMVA3newDMwoLTraw_3",&byIsolationMVA3newDMwoLTraw_3);
  //Tree->SetBranchAddress("byIsolationMVA3newDMwLTraw_3",&byIsolationMVA3newDMwLTraw_3);
  //Tree->SetBranchAddress("byIsolationMVA3newDMwLTraw_3",&byIsolationMVA3newDMwLTraw_3);
  Tree->SetBranchAddress("byVLooseIsolationRerunMVArun2v1DBoldDMwLT_3",&byVLooseIsolationRerunMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byLooseIsolationRerunMVArun2v1DBoldDMwLT_3",&byLooseIsolationRerunMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byMediumIsolationRerunMVArun2v1DBoldDMwLT_3",&byMediumIsolationRerunMVArun2v1DBoldDMwLT_3);
  Tree->SetBranchAddress("byTightIsolationRerunMVArun2v1DBoldDMwLT_3",&byTightIsolationRerunMVArun2v1DBoldDMwLT_3);
  //Tree->SetBranchAddress("byVTightIsolationRerunMVArun2v1DBoldDMwLT_3",&byVTightIsolationRerunMVArun2v1DBoldDMwLT_3);
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
  //Tree->SetBranchAddress("e_3",&e_3);
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
  //new things
  Tree->SetBranchAddress("gen_match_3",&gen_match_3);
  Tree->SetBranchAddress("genM",&genM);
  Tree->SetBranchAddress("genpT",&genpT);

  int NumberOfEntries = (int) Tree->GetEntries();    
  
  Double_t Pt_binning[] = {20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0,  
			   70.0, 75.0, 80.0, 90.0, 100.0, 120.0, 200.0};
  int Pt_binnumber = sizeof(Pt_binning)/sizeof(Double_t) - 1;

  Double_t Eta_binning[] = {0.0, 0.15, 0.3, 0.45, 0.6, 0.75, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9, 2.1, 2.3};
  int Eta_binnumber = sizeof(Eta_binning)/sizeof(Double_t) - 1;


  TH1F* OverallEvents = new TH1F((Input+"_OverallEvents").c_str(),(Input+"_OverallEvents").c_str(),7,0.0,7.0);  
  TH1F* OverallDecayMode0Events = new TH1F((Input+"_OverallDecayMode0Events").c_str(),(Input+"_OverallDecayMode0Events").c_str(),7,0.0,7.0);
  TH1F* OverallDecayMode1Events = new TH1F((Input+"_OverallDecayMode1Events").c_str(),(Input+"_OverallDecayMode1Events").c_str(),7,0.0,7.0);
  TH1F* OverallDecayMode10Events = new TH1F((Input+"_OverallDecayMode10Events").c_str(),(Input+"_OverallDecayMode10Events").c_str(),7,0.0,7.0);
  TH1F* BaselineSelectedTauPT = new TH1F((Input+"_BasicSelectedTauPT").c_str(),(Input+"_BasicSlsectedTauPT").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VLoosePTEvents = new TH1F((Input+"_VLooseEvents").c_str(),(Input+"_VLooseEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* LoosePTEvents = new TH1F((Input+"_LooseEvents").c_str(),(Input+"_LooseEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* MediumPTEvents = new TH1F((Input+"_MediumEvents").c_str(),(Input+"_MediumEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* TightPTEvents = new TH1F((Input+"_TightEvents").c_str(),(Input+"_TightEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VTightPTEvents = new TH1F((Input+"_VTightEvents").c_str(),(Input+"_VTightEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VVTightPTEvents = new TH1F((Input+"_VVTightEvents").c_str(),(Input+"_VVTightEvents").c_str(),Pt_binnumber,Pt_binning);

  //run a similar thing to above where we just split this up by fake rates
  TH1F* BaselineDecayMode0PTEvents = new TH1F((Input+"_BaselineDecayMode0PTEvents").c_str(),(Input+"_BaselineDecayMode0PTEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* BaselineDecayMode1PTEvents = new TH1F((Input+"_BaselineDecayMode1PTEvents").c_str(),(Input+"_BaselineDecayMode1PTEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* BaselineDecayMode10PTEvents = new TH1F((Input+"_BaselineDecayMode10PTEvents").c_str(),(Input+"_BaselineDecayMode10PTEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* VLooseDecayMode0PTEvents = new TH1F((Input+"_VLooseDecayMode0PTEvents").c_str(),(Input+"_VLooseDecayMode0PTEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VLooseDecayMode1PTEvents = new TH1F((Input+"_VLooseDecayMode1PTEvents").c_str(),(Input+"_VLooseDecayMode1PTEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VLooseDecayMode10PTEvents = new TH1F((Input+"_VLooseDecayMode10PTEvents").c_str(),(Input+"_VLooseDecayMode10PTEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* LooseDecayMode0PTEvents = new TH1F((Input+"_LooseDecayMode0PTEvents").c_str(),(Input+"_LooseDecayMode0PTEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* LooseDecayMode1PTEvents = new TH1F((Input+"_LooseDecayMode1PTEvents").c_str(),(Input+"_LooseDecayMode1PTEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* LooseDecayMode10PTEvents = new TH1F((Input+"_LooseDecayMode10PTEvents").c_str(),(Input+"_LooseDecayMode10PTEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* MediumDecayMode0PTEvents = new TH1F((Input+"_MediumDecayMode0PTEvents").c_str(),(Input+"_MediumDecayMode0PTEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* MediumDecayMode1PTEvents = new TH1F((Input+"_MediumDecayMode1PTEvents").c_str(),(Input+"_MediumDecayMode1PTEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* MediumDecayMode10PTEvents = new TH1F((Input+"_MediumDecayMode10PTEvents").c_str(),(Input+"_MediumDecayMode10PTEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* TightDecayMode0PTEvents = new TH1F((Input+"_TightDecayMode0PTEvents").c_str(),(Input+"_TightDecayMode0PTEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* TightDecayMode1PTEvents = new TH1F((Input+"_TightDecayMode1PTEvents").c_str(),(Input+"_TightDecayMode1PTEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* TightDecayMode10PTEvents = new TH1F((Input+"_TightDecayMode10PTEvents").c_str(),(Input+"_TightDecayMode10PTEvents").c_str(),Pt_binnumber,Pt_binning);
  
  TH1F* VTightDecayMode0PTEvents = new TH1F((Input+"_VTightDecayMode0PTEvents").c_str(),(Input+"_VTightDecayMode0PTEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VTightDecayMode1PTEvents = new TH1F((Input+"_VTightDecayMode1PTEvents").c_str(),(Input+"_VTightDecayMode1PTEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VTightDecayMode10PTEvents = new TH1F((Input+"_VTightDecayMode10PTEvents").c_str(),(Input+"_VTightDecayMode10PTEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* VVTightDecayMode0PTEvents = new TH1F((Input+"_VVTightDecayMode0PTEvents").c_str(),(Input+"_VVTightDecayMode0PTEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VVTightDecayMode1PTEvents = new TH1F((Input+"_VVTightDecayMode1PTEvents").c_str(),(Input+"_VVTightDecayMode1PTEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VVTightDecayMode10PTEvents = new TH1F((Input+"_VVTightDecayMode10PTEvents").c_str(),(Input+"_VVTightDecayMode10PTEvents").c_str(),Pt_binnumber,Pt_binning);
  
  //barrel fake rates
  TH1F* BaselineDecayMode0PTBarrelEvents = new TH1F((Input+"_BaselineDecayMode0PTBarrelEvents").c_str(),(Input+"_BaselineDecayMode0PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* BaselineDecayMode1PTBarrelEvents = new TH1F((Input+"_BaselineDecayMode1PTBarrelEvents").c_str(),(Input+"_BaselineDecayMode1PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* BaselineDecayMode10PTBarrelEvents = new TH1F((Input+"_BaselineDecayMode10PTBarrelEvents").c_str(),(Input+"_BaselineDecayMode10PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* VLooseDecayMode0PTBarrelEvents = new TH1F((Input+"_VLooseDecayMode0PTBarrelEvents").c_str(),(Input+"_VLooseDecayMode0PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VLooseDecayMode1PTBarrelEvents = new TH1F((Input+"_VLooseDecayMode1PTBarrelEvents").c_str(),(Input+"_VLooseDecayMode1PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VLooseDecayMode10PTBarrelEvents = new TH1F((Input+"_VLooseDecayMode10PTBarrelEvents").c_str(),(Input+"_VLooseDecayMode10PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* LooseDecayMode0PTBarrelEvents = new TH1F((Input+"_LooseDecayMode0PTBarrelEvents").c_str(),(Input+"_LooseDecayMode0PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* LooseDecayMode1PTBarrelEvents = new TH1F((Input+"_LooseDecayMode1PTBarrelEvents").c_str(),(Input+"_LooseDecayMode1PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* LooseDecayMode10PTBarrelEvents = new TH1F((Input+"_LooseDecayMode10PTBarrelEvents").c_str(),(Input+"_LooseDecayMode10PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* MediumDecayMode0PTBarrelEvents = new TH1F((Input+"_MediumDecayMode0PTBarrelEvents").c_str(),(Input+"_MediumDecayMode0PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* MediumDecayMode1PTBarrelEvents = new TH1F((Input+"_MediumDecayMode1PTBarrelEvents").c_str(),(Input+"_MediumDecayMode1PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* MediumDecayMode10PTBarrelEvents = new TH1F((Input+"_MediumDecayMode10PTBarrelEvents").c_str(),(Input+"_MediumDecayMode10PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* TightDecayMode0PTBarrelEvents = new TH1F((Input+"_TightDecayMode0PTBarrelEvents").c_str(),(Input+"_TightDecayMode0PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* TightDecayMode1PTBarrelEvents = new TH1F((Input+"_TightDecayMode1PTBarrelEvents").c_str(),(Input+"_TightDecayMode1PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* TightDecayMode10PTBarrelEvents = new TH1F((Input+"_TightDecayMode10PTBarrelEvents").c_str(),(Input+"_TightDecayMode10PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  
  TH1F* VTightDecayMode0PTBarrelEvents = new TH1F((Input+"_VTightDecayMode0PTBarrelEvents").c_str(),(Input+"_VTightDecayMode0PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VTightDecayMode1PTBarrelEvents = new TH1F((Input+"_VTightDecayMode1PTBarrelEvents").c_str(),(Input+"_VTightDecayMode1PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VTightDecayMode10PTBarrelEvents = new TH1F((Input+"_VTightDecayMode10PTBarrelEvents").c_str(),(Input+"_VTightDecayMode10PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* VVTightDecayMode0PTBarrelEvents = new TH1F((Input+"_VVTightDecayMode0PTBarrelEvents").c_str(),(Input+"_VVTightDecayMode0PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VVTightDecayMode1PTBarrelEvents = new TH1F((Input+"_VVTightDecayMode1PTBarrelEvents").c_str(),(Input+"_VVTightDecayMode1PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VVTightDecayMode10PTBarrelEvents = new TH1F((Input+"_VVTightDecayMode10PTBarrelEvents").c_str(),(Input+"_VVTightDecayMode10PTBarrelEvents").c_str(),Pt_binnumber,Pt_binning);

  //endcap fake rates  
  TH1F* BaselineDecayMode0PTEndcapEvents = new TH1F((Input+"_BaselineDecayMode0PTEndcapEvents").c_str(),(Input+"_BaselineDecayMode0PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* BaselineDecayMode1PTEndcapEvents = new TH1F((Input+"_BaselineDecayMode1PTEndcapEvents").c_str(),(Input+"_BaselineDecayMode1PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* BaselineDecayMode10PTEndcapEvents = new TH1F((Input+"_BaselineDecayMode10PTEndcapEvents").c_str(),(Input+"_BaselineDecayMode10PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* VLooseDecayMode0PTEndcapEvents = new TH1F((Input+"_VLooseDecayMode0PTEndcapEvents").c_str(),(Input+"_VLooseDecayMode0PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VLooseDecayMode1PTEndcapEvents = new TH1F((Input+"_VLooseDecayMode1PTEndcapEvents").c_str(),(Input+"_VLooseDecayMode1PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VLooseDecayMode10PTEndcapEvents = new TH1F((Input+"_VLooseDecayMode10PTEndcapEvents").c_str(),(Input+"_VLooseDecayMode10PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* LooseDecayMode0PTEndcapEvents = new TH1F((Input+"_LooseDecayMode0PTEndcapEvents").c_str(),(Input+"_LooseDecayMode0PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* LooseDecayMode1PTEndcapEvents = new TH1F((Input+"_LooseDecayMode1PTEndcapEvents").c_str(),(Input+"_LooseDecayMode1PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* LooseDecayMode10PTEndcapEvents = new TH1F((Input+"_LooseDecayMode10PTEndcapEvents").c_str(),(Input+"_LooseDecayMode10PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* MediumDecayMode0PTEndcapEvents = new TH1F((Input+"_MediumDecayMode0PTEndcapEvents").c_str(),(Input+"_MediumDecayMode0PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* MediumDecayMode1PTEndcapEvents = new TH1F((Input+"_MediumDecayMode1PTEndcapEvents").c_str(),(Input+"_MediumDecayMode1PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* MediumDecayMode10PTEndcapEvents = new TH1F((Input+"_MediumDecayMode10PTEndcapEvents").c_str(),(Input+"_MediumDecayMode10PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* TightDecayMode0PTEndcapEvents = new TH1F((Input+"_TightDecayMode0PTEndcapEvents").c_str(),(Input+"_TightDecayMode0PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* TightDecayMode1PTEndcapEvents = new TH1F((Input+"_TightDecayMode1PTEndcapEvents").c_str(),(Input+"_TightDecayMode1PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* TightDecayMode10PTEndcapEvents = new TH1F((Input+"_TightDecayMode10PTEndcapEvents").c_str(),(Input+"_TightDecayMode10PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  
  TH1F* VTightDecayMode0PTEndcapEvents = new TH1F((Input+"_VTightDecayMode0PTEndcapEvents").c_str(),(Input+"_VTightDecayMode0PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VTightDecayMode1PTEndcapEvents = new TH1F((Input+"_VTightDecayMode1PTEndcapEvents").c_str(),(Input+"_VTightDecayMode1PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VTightDecayMode10PTEndcapEvents = new TH1F((Input+"_VTightDecayMode10PTEndcapEvents").c_str(),(Input+"_VTightDecayMode10PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);

  TH1F* VVTightDecayMode0PTEndcapEvents = new TH1F((Input+"_VVTightDecayMode0PTEndcapEvents").c_str(),(Input+"_VVTightDecayMode0PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VVTightDecayMode1PTEndcapEvents = new TH1F((Input+"_VVTightDecayMode1PTEndcapEvents").c_str(),(Input+"_VVTightDecayMode1PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);
  TH1F* VVTightDecayMode10PTEndcapEvents = new TH1F((Input+"_VVTightDecayMode10PTEndcapEvents").c_str(),(Input+"_VVTightDecayMode10PTEndcapEvents").c_str(),Pt_binnumber,Pt_binning);

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

  float DecayMode0BarrelBaselineSelectedTaus = 0.0;  
  float DecayMode0BarrelTausPassVLooseMVAIso = 0.0;
  float DecayMode0BarrelTausPassLooseMVAIso = 0.0;
  float DecayMode0BarrelTausPassMediumMVAIso = 0.0;
  float DecayMode0BarrelTausPassTightMVAIso = 0.0;
  float DecayMode0BarrelTausPassVTightMVAIso = 0.0;
  float DecayMode0BarrelTausPassVVTightMVAIso = 0.0;
  
  float DecayMode0EndcapBaselineSelectedTaus = 0.0;  
  float DecayMode0EndcapTausPassVLooseMVAIso = 0.0;
  float DecayMode0EndcapTausPassLooseMVAIso = 0.0;
  float DecayMode0EndcapTausPassMediumMVAIso = 0.0;
  float DecayMode0EndcapTausPassTightMVAIso = 0.0;
  float DecayMode0EndcapTausPassVTightMVAIso = 0.0;
  float DecayMode0EndcapTausPassVVTightMVAIso = 0.0;
  
  float DecayMode1BaselineSelectedTaus = 0.0;  
  float DecayMode1TausPassVLooseMVAIso = 0.0;
  float DecayMode1TausPassLooseMVAIso = 0.0;
  float DecayMode1TausPassMediumMVAIso = 0.0;
  float DecayMode1TausPassTightMVAIso = 0.0;
  float DecayMode1TausPassVTightMVAIso = 0.0;
  float DecayMode1TausPassVVTightMVAIso = 0.0;

  float DecayMode1BarrelBaselineSelectedTaus = 0.0;  
  float DecayMode1BarrelTausPassVLooseMVAIso = 0.0;
  float DecayMode1BarrelTausPassLooseMVAIso = 0.0;
  float DecayMode1BarrelTausPassMediumMVAIso = 0.0;
  float DecayMode1BarrelTausPassTightMVAIso = 0.0;
  float DecayMode1BarrelTausPassVTightMVAIso = 0.0;
  float DecayMode1BarrelTausPassVVTightMVAIso = 0.0;
  
  float DecayMode1EndcapBaselineSelectedTaus = 0.0;  
  float DecayMode1EndcapTausPassVLooseMVAIso = 0.0;
  float DecayMode1EndcapTausPassLooseMVAIso = 0.0;
  float DecayMode1EndcapTausPassMediumMVAIso = 0.0;
  float DecayMode1EndcapTausPassTightMVAIso = 0.0;
  float DecayMode1EndcapTausPassVTightMVAIso = 0.0;
  float DecayMode1EndcapTausPassVVTightMVAIso = 0.0;
  
  float DecayMode10BaselineSelectedTaus = 0.0;  
  float DecayMode10TausPassVLooseMVAIso = 0.0;
  float DecayMode10TausPassLooseMVAIso = 0.0;
  float DecayMode10TausPassMediumMVAIso = 0.0;
  float DecayMode10TausPassTightMVAIso = 0.0;
  float DecayMode10TausPassVTightMVAIso = 0.0;
  float DecayMode10TausPassVVTightMVAIso = 0.0;

  float DecayMode10BarrelBaselineSelectedTaus = 0.0;  
  float DecayMode10BarrelTausPassVLooseMVAIso = 0.0;
  float DecayMode10BarrelTausPassLooseMVAIso = 0.0;
  float DecayMode10BarrelTausPassMediumMVAIso = 0.0;
  float DecayMode10BarrelTausPassTightMVAIso = 0.0;
  float DecayMode10BarrelTausPassVTightMVAIso = 0.0;
  float DecayMode10BarrelTausPassVVTightMVAIso = 0.0;
  
  float DecayMode10EndcapBaselineSelectedTaus = 0.0;  
  float DecayMode10EndcapTausPassVLooseMVAIso = 0.0;
  float DecayMode10EndcapTausPassLooseMVAIso = 0.0;
  float DecayMode10EndcapTausPassMediumMVAIso = 0.0;
  float DecayMode10EndcapTausPassTightMVAIso = 0.0;
  float DecayMode10EndcapTausPassVTightMVAIso = 0.0;
  float DecayMode10EndcapTausPassVVTightMVAIso = 0.0;

  float UnrecognizedDecayMode = 0.0;  

  //Weighting Information
  float LHCLumi = 41.370e15;
  float NormalizationWeight;
  float XSecWeight; 
  if(Input == "WW")XSecWeight = LHCLumi * 118.7e-12 / TotalNumberOfEvents;
  else if(Input == "WZ") XSecWeight = LHCLumi * 47.13e-12 / TotalNumberOfEvents;
  else if(Input == "ZZ") XSecWeight = LHCLumi * 16.523e-12 / TotalNumberOfEvents;
  else if(Input == "TTTo2L2Nu") XSecWeight = LHCLumi * 88.34e-12/ TotalNumberOfEvents;
  else if(Input == "TTToHadronic") XSecWeight = LHCLumi * 377.96e-12 / TotalNumberOfEvents;
  else if(Input == "TTToSemiLeptonic") XSecWeight = LHCLumi * 365.45e-12 / TotalNumberOfEvents;
  else if(Input == "ST_top") XSecWeight = LHCLumi * 113.3e-12 /TotalNumberOfEvents;
  else if(Input == "ST_antitop") XSecWeight = LHCLumi * 67.91e-12 /TotalNumberOfEvents;
  else if(Input == "ST_tW_top") XSecWeight = LHCLumi * 34.91e-12 /TotalNumberOfEvents;
  else if(Input == "ST_tW_antitop") XSecWeight = LHCLumi * 34.91e-12 /TotalNumberOfEvents;
  else if(Input == "DY") XSecWeight = LHCLumi * 6225.42e-12 / TotalNumberOfEvents;
  else if(Input == "DY1") XSecWeight = LHCLumi * 1178.29e-12 /TotalNumberOfEvents;
  else if(Input == "DY2") XSecWeight = LHCLumi * 387.34e-12 /TotalNumberOfEvents;
  else if(Input == "DY3") XSecWeight = LHCLumi * 118.429e-12 /TotalNumberOfEvents;
  else if(Input == "DY4") XSecWeight = LHCLumi * 63.73e-12 /TotalNumberOfEvents;
  
  reweight::LumiReWeighting* LumiWeights_12;
  LumiWeights_12 = new reweight::LumiReWeighting(("/data/aloeliger/CMSSW_9_4_0/src/SMHTTAnalysis/SkimmedNtuples/TauID2017/"+Input+".root").c_str(),
						 "../Weightings/MyDataPileupHistogram.root",
						 "pileup_mc",
						 "pileup");
  
  TFile* TriggerFile = new TFile("../Weightings/EfficienciesAndSF_RunBtoF_Nov17Nov2017.root");
  TDirectoryFile* TriggerMuDirectory = (TDirectoryFile* )TriggerFile->Get("IsoMu27_PtEtaBins");
  TH2F* TriggerWeightings = (TH2F*) TriggerMuDirectory->Get("abseta_pt_ratio");
  
  TFile* IDFile = new TFile("../Weightings/RunBCDEF_SF_ID.root");
  TH2F* IDWeightings = (TH2F*) IDFile->Get("NUM_MediumID_DEN_genTracks_pt_abseta");
  
  TFile* ISOFile = new TFile("../Weightings/RunBCDEF_SF_ISO.root");
  TH2F* ISOWeightings = (TH2F*) ISOFile->Get("NUM_TightRelIso_DEN_MediumID_pt_abseta");

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
      TLorentzVector l1; l1.SetPtEtaPhiM(pt_1,eta_1,phi_1,m_1); //muon 1
      TLorentzVector l2; l2.SetPtEtaPhiM(pt_2,eta_2,phi_2,m_2); //muon 2
      TLorentzVector l3; l3.SetPtEtaPhiM(pt_3,eta_3,phi_3,m_3); //tau 3

      //make sure we pass some muon selection?
      //I guess we just do the same muon region as the actually mt region to make 
      // we get as close to possible to the actual region we care about?
      
      //match diego's pt > 30 cut as opposed to my original 29.0 cut
      if(pt_1 < 20.0 or std::abs(eta_1) > 2.4 or !id_m_medium_1 or iso_1 > 0.15 or std::abs(dZ_1) > 0.2 or std::abs(d0_1) > 0.045 /*or !matchIsoMu27_1*/) continue;
      
      if(pt_2 < 20.0 or std::abs(eta_2) > 2.4 or !id_m_medium_2 or iso_2 > 0.15 or std::abs(dZ_2) > 0.2 or std::abs(d0_2) > 0.045 /*or !matchIsoMu27_2*/) continue;
      
      //do some proper muon pair criteria here
      if(matchIsoMu27_1 && !matchIsoMu27_2 && !(pt_1 > 30.0)) continue;
      if(matchIsoMu27_2 && !matchIsoMu27_1 && !(pt_2 > 30.0)) continue;
      if(matchIsoMu27_1 && matchIsoMu27_2 && !(pt_1 >30.0 || pt_2 > 30.0)) continue;
      if(!matchIsoMu27_1 && !matchIsoMu27_2) continue;
      if(!(pt_1>30.0) && !(pt_2>30.0))continue;

      //We'll do some loose selection of tau stuff, saving the  
      if(pt_3 < 20.0 or std::abs(eta_3) > 2.3 or againstElectronVLooseMVA6_3 != 1 or againstMuonTight3_3 != 1 /*or !decayModeFinding_3*/ or std::abs(dZ_3) > 0.2 or std::abs(q_3) > 1) continue;      
      
      //ensure the Z decay
      if((l1+l2).M() <= 80.0 or (l1+l2).M() >= 100.0 or q_1*q_2 > 0) continue;

      //
      if(Input != "Data" and gen_match_3 == 6) continue;

      //Create the weighting
      float PileupWeight = LumiWeights_12->weight(npu);
      
      float muTriggerSF;
      if(matchIsoMu27_1)
	muTriggerSF = TriggerWeightings->GetBinContent(TriggerWeightings->FindBin(fabs(l1.Eta()),l1.Pt()));
      else
	muTriggerSF = TriggerWeightings->GetBinContent(TriggerWeightings->FindBin(fabs(l2.Eta()),l2.Pt()));
      float muIDSF;      
      if(l1.Pt() < 120.0) muIDSF =  IDWeightings->GetBinContent(IDWeightings->FindBin(l1.Pt(),fabs(l1.Eta())));
      else muIDSF =  IDWeightings->GetBinContent(IDWeightings->FindBin(119.0,fabs(l1.Eta())));
      
      if(l2.Pt() < 120.0) muIDSF *=  IDWeightings->GetBinContent(IDWeightings->FindBin(l2.Pt(),fabs(l2.Eta())));
      else muIDSF *=  IDWeightings->GetBinContent(IDWeightings->FindBin(119.0,fabs(l2.Eta())));

      float muISOSF;
      if(l1.Pt() < 120.0) muISOSF =  ISOWeightings->GetBinContent(ISOWeightings->FindBin(l1.Pt(),fabs(l1.Eta())));
      else muISOSF =  ISOWeightings->GetBinContent(ISOWeightings->FindBin(119.0,fabs(l1.Eta())));

      if(l2.Pt() < 120.0) muISOSF *=  ISOWeightings->GetBinContent(ISOWeightings->FindBin(l2.Pt(),fabs(l2.Eta())));
      else muISOSF *=  ISOWeightings->GetBinContent(ISOWeightings->FindBin(119.0,fabs(l2.Eta())));

      if(Input == "WW")NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(Input == "WZ") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(Input == "ZZ") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;            
      else if(Input == "TTTo2L2Nu") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(Input == "TTToHadronic") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(Input == "TTToSemiLeptonic") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;      
      else if(Input == "DY"
	      or Input == "DY1"
	      or Input == "DY2"
	      or Input == "DY3"
	      or Input == "DY4")
	{	  
	  NormalizationWeight = PileupWeight*muTriggerSF*muIDSF*muISOSF;
	  
	  if(numGenJets==0) NormalizationWeight = NormalizationWeight*2.373;
	  if(numGenJets==1) NormalizationWeight = NormalizationWeight*0.804;
	  if(numGenJets==2) NormalizationWeight = NormalizationWeight*0.816;
	  if(numGenJets==3) NormalizationWeight = NormalizationWeight*0.546;
	  if(numGenJets==4) NormalizationWeight = NormalizationWeight*0.478;

	  //ZPT Reweighting
	  //float ZPTWeight = getZpt_2017(genM,genpT);
	  //NormalizationWeight = NormalizationWeight*ZPTWeight;
	}            
      else if(Input == "ST_top") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(Input == "ST_antitop") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(Input == "ST_tW_top") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(Input == "ST_tW_antitop") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      NormalizationWeight = NormalizationWeight*amcatNLO_weight;      
      if(Input == "Data") NormalizationWeight = 1.0;
      
      // okay we should now be working witha Z decay to mu's and what is nominally a tau
      BaselineSelectedTaus += 1.0;
      BaselineSelectedTauPT->Fill(pt_3,NormalizationWeight);
      if(l3_decayMode == 0)
	{	  
	  if(std::abs(eta_3) < 1.479)
	    {
	      DecayMode0BarrelBaselineSelectedTaus += 1.0;
	      BaselineDecayMode0PTBarrelEvents->Fill(pt_3,NormalizationWeight);
	    }
	  else
	    {
	      DecayMode0EndcapBaselineSelectedTaus += 1.0;
	      BaselineDecayMode0PTBarrelEvents->Fill(pt_3,NormalizationWeight);
	    }
	  BaselineDecayMode0PTEvents->Fill(pt_3,NormalizationWeight);
	  DecayMode0BaselineSelectedTaus += 1.0;
	}
      else if (l3_decayMode == 1)
	{
	  if(std::abs(eta_3) < 1.479)
	    {
	      DecayMode1BarrelBaselineSelectedTaus += 1.0;
	      BaselineDecayMode1PTBarrelEvents->Fill(pt_3,NormalizationWeight);
	    }
	  else
	    {
	      DecayMode1EndcapBaselineSelectedTaus += 1.0;
	      BaselineDecayMode1PTEndcapEvents->Fill(pt_3,NormalizationWeight);
	    }
	  BaselineDecayMode1PTEvents->Fill(pt_3,NormalizationWeight);
	  DecayMode1BaselineSelectedTaus += 1.0;
	}
      else if (l3_decayMode == 10)
	{
	  if(std::abs(eta_3) < 1.479)
	    {
	      DecayMode10BarrelBaselineSelectedTaus += 1.0;
	      BaselineDecayMode10PTBarrelEvents->Fill(pt_3,NormalizationWeight);
	    }
	  else
	    {
	      DecayMode10EndcapBaselineSelectedTaus += 1.0;
	      BaselineDecayMode10PTEndcapEvents->Fill(pt_3,NormalizationWeight);
	    }
	  BaselineDecayMode10PTEvents->Fill(pt_3,NormalizationWeight);
	  DecayMode10BaselineSelectedTaus += 1.0;
	}
      else
	{
	  UnrecognizedDecayMode+=1.0;
	}
      
      if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_3) 
	{
	  TausPassVLooseMVAIso+=1.0;
	  VLoosePTEvents->Fill(pt_3,NormalizationWeight);
	  if(l3_decayMode == 0)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode0BarrelTausPassVLooseMVAIso += 1.0;
		  VLooseDecayMode0PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode0EndcapTausPassVLooseMVAIso += 1.0;
		  VLooseDecayMode0PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}
	      VLooseDecayMode0PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode0TausPassVLooseMVAIso+=1.0;
	    }
	  else if(l3_decayMode == 1)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode1BarrelTausPassVLooseMVAIso += 1.0;
		  VLooseDecayMode1PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode1EndcapTausPassVLooseMVAIso += 1.0;
		  VLooseDecayMode1PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}
	      VLooseDecayMode1PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode1TausPassVLooseMVAIso+=1.0;
	    }
	  else if(l3_decayMode == 10)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode10BarrelTausPassVLooseMVAIso += 1.0;
		  VLooseDecayMode10PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode10EndcapTausPassVLooseMVAIso += 1.0;
		  VLooseDecayMode10PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}
	      VLooseDecayMode10PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode10TausPassVLooseMVAIso+=1.0;
	    }
	  else
	    {
	      UnrecognizedDecayMode+=1.0;
	    }
	}
      if(byLooseIsolationRerunMVArun2v2DBoldDMwLT_3 && byVLooseIsolationRerunMVArun2v2DBoldDMwLT_3)
	{ 
	  TausPassLooseMVAIso+=1.0;
	  LoosePTEvents->Fill(pt_3,NormalizationWeight);
	  if(l3_decayMode == 0)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode0BarrelTausPassLooseMVAIso += 1.0;
		  LooseDecayMode0PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode0EndcapTausPassLooseMVAIso += 1.0;
		  LooseDecayMode0PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}
	      LooseDecayMode0PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode0TausPassLooseMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 1)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode1BarrelTausPassLooseMVAIso += 1.0;
		  LooseDecayMode1PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode1EndcapTausPassLooseMVAIso += 1.0;
		  LooseDecayMode1PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}
	      LooseDecayMode1PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode1TausPassLooseMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 10)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode10BarrelTausPassLooseMVAIso += 1.0;
		  LooseDecayMode10PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode10EndcapTausPassLooseMVAIso += 1.0;
		  LooseDecayMode10PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}
	      LooseDecayMode10PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode10TausPassLooseMVAIso+=1.0;
	    }
	  else
	    {
	      UnrecognizedDecayMode+=1.0;
	    }
	}
      if(byMediumIsolationRerunMVArun2v2DBoldDMwLT_3 && byVLooseIsolationRerunMVArun2v2DBoldDMwLT_3)
	{ 
	  TausPassMediumMVAIso+=1.0;
	  MediumPTEvents->Fill(pt_3,NormalizationWeight);
	  if(l3_decayMode == 0)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode0BarrelTausPassMediumMVAIso += 1.0;
		  MediumDecayMode0PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode0EndcapTausPassMediumMVAIso += 1.0;
		  MediumDecayMode0PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}
	      MediumDecayMode0PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode0TausPassMediumMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 1)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode1BarrelTausPassMediumMVAIso += 1.0;
		  MediumDecayMode1PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode1EndcapTausPassMediumMVAIso += 1.0;
		  MediumDecayMode1PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}
	      
	      MediumDecayMode1PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode1TausPassMediumMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 10)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode10BarrelTausPassMediumMVAIso += 1.0;
		  MediumDecayMode10PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode10EndcapTausPassMediumMVAIso += 1.0;
		  MediumDecayMode10PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}

	      MediumDecayMode10PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode10TausPassMediumMVAIso+=1.0;
	    }
	  else
	    {
	      UnrecognizedDecayMode+=1.0;
	    }
	}
      if(byTightIsolationRerunMVArun2v2DBoldDMwLT_3 && byVLooseIsolationRerunMVArun2v2DBoldDMwLT_3) 
	{
	  TausPassTightMVAIso+=1.0;
	  TightPTEvents->Fill(pt_3,NormalizationWeight);
	  if(l3_decayMode == 0)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode0BarrelTausPassTightMVAIso += 1.0;
		  TightDecayMode0PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode0EndcapTausPassTightMVAIso += 1.0;
		  TightDecayMode0PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}

	      TightDecayMode0PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode0TausPassTightMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 1)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode1BarrelTausPassTightMVAIso += 1.0;
		  TightDecayMode1PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode1EndcapTausPassTightMVAIso += 1.0;
		  TightDecayMode1PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}
	      
	      TightDecayMode1PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode1TausPassTightMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 10)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode10BarrelTausPassTightMVAIso += 1.0;
		  TightDecayMode10PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode10EndcapTausPassTightMVAIso += 1.0;
		  TightDecayMode10PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}
	      
	      TightDecayMode10PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode10TausPassTightMVAIso+=1.0;
	    }
	  else
	    {
	      UnrecognizedDecayMode+=1.0;
	    }
	}
      if(byVTightIsolationRerunMVArun2v2DBoldDMwLT_3 && byVLooseIsolationRerunMVArun2v2DBoldDMwLT_3) 
	{
	  TausPassVTightMVAIso+=1.0;
	  VTightPTEvents->Fill(pt_3,NormalizationWeight);
	  if(l3_decayMode == 0)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode0BarrelTausPassVTightMVAIso += 1.0;
		  VTightDecayMode0PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode0EndcapTausPassVTightMVAIso += 1.0;
		  VTightDecayMode0PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}

	      VTightDecayMode0PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode0TausPassVTightMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 1)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode1BarrelTausPassVTightMVAIso += 1.0;
		  VTightDecayMode1PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode1EndcapTausPassVTightMVAIso += 1.0;
		  VTightDecayMode1PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}
	      
	      VTightDecayMode1PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode1TausPassVTightMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 10)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode10BarrelTausPassVTightMVAIso += 1.0;
		  VTightDecayMode10PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode10EndcapTausPassVTightMVAIso += 1.0;
		  VTightDecayMode10PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}
	      
	      VTightDecayMode10PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode10TausPassVTightMVAIso+=1.0;
	    }
	  else
	    {
	      UnrecognizedDecayMode+=1.0;
	    }
	}
      if(byVVTightIsolationRerunMVArun2v2DBoldDMwLT_3 && byVLooseIsolationRerunMVArun2v2DBoldDMwLT_3) 
	{
	  TausPassVVTightMVAIso+=1.0;
	  VVTightPTEvents->Fill(pt_3,NormalizationWeight);
	  if(l3_decayMode == 0)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode0BarrelTausPassVVTightMVAIso += 1.0;
		  VVTightDecayMode0PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode0EndcapTausPassVVTightMVAIso += 1.0;
		  VVTightDecayMode0PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}
	      
	      VVTightDecayMode0PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode0TausPassVVTightMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 1)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode1BarrelTausPassVVTightMVAIso += 1.0;
		  VVTightDecayMode1PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode1EndcapTausPassVVTightMVAIso += 1.0;
		  VVTightDecayMode1PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}

	      VVTightDecayMode1PTEvents->Fill(pt_3,NormalizationWeight);
	      DecayMode1TausPassVVTightMVAIso+=1.0;
	    }
	  else if (l3_decayMode == 10)
	    {
	      if(std::abs(eta_3) < 1.479)
		{
		  DecayMode10BarrelTausPassVVTightMVAIso += 1.0;
		  VVTightDecayMode10PTBarrelEvents->Fill(pt_3,NormalizationWeight);
		}
	      else
		{
		  DecayMode10EndcapTausPassVVTightMVAIso += 1.0;
		  VVTightDecayMode10PTEndcapEvents->Fill(pt_3,NormalizationWeight);
		}

	      VVTightDecayMode10PTEvents->Fill(pt_3,NormalizationWeight);
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
  std::cout<<std::endl;

  std::cout<<"DecayMode0BaselineSelectedTaus: "<<DecayMode0BaselineSelectedTaus<<std::endl;
  std::cout<<"DecayMode0TausPassVLooseMVAIso: "<<DecayMode0TausPassVLooseMVAIso<<std::endl;
  std::cout<<"DecayMode0TausPassLooseMVAIso: "<<DecayMode0TausPassLooseMVAIso<<std::endl;
  std::cout<<"DecayMode0TausPassMediumMVAIso: "<<DecayMode0TausPassMediumMVAIso<<std::endl;
  std::cout<<"DecayMode0TausPassTightMVAIso: "<<DecayMode0TausPassTightMVAIso<<std::endl;
  std::cout<<"DecayMode0TausPassVTightMVAIso: "<<DecayMode0TausPassVTightMVAIso<<std::endl;
  std::cout<<"DecayMode0TausPassVVTightMVAIso: "<<DecayMode0TausPassVVTightMVAIso<<std::endl;
  std::cout<<std::endl;
  
  std::cout<<"DecayMode0BarrelBaselineSelectedTaus: "<<DecayMode0BarrelBaselineSelectedTaus<<std::endl;
  std::cout<<"DecayMode0BarrelTausPassVLooseMVAIso: "<<DecayMode0BarrelTausPassVLooseMVAIso<<std::endl;
  std::cout<<"DecayMode0BarrelTausPassLooseMVAIso: "<<DecayMode0BarrelTausPassLooseMVAIso<<std::endl;
  std::cout<<"DecayMode0BarrelTausPassMediumMVAIso: "<<DecayMode0BarrelTausPassMediumMVAIso<<std::endl;
  std::cout<<"DecayMode0BarrelTausPassTightMVAIso: "<<DecayMode0BarrelTausPassTightMVAIso<<std::endl;
  std::cout<<"DecayMode0BarrelTausPassVTightMVAIso: "<<DecayMode0BarrelTausPassVTightMVAIso<<std::endl;
  std::cout<<"DecayMode0BarrelTausPassVVTightMVAIso: "<<DecayMode0BarrelTausPassVVTightMVAIso<<std::endl;
  std::cout<<std::endl;
  
  std::cout<<"DecayMode0EndcapBaselineSelectedTaus: "<<DecayMode0EndcapBaselineSelectedTaus<<std::endl;
  std::cout<<"DecayMode0EndcapTausPassVLooseMVAIso: "<<DecayMode0EndcapTausPassVLooseMVAIso<<std::endl;
  std::cout<<"DecayMode0EndcapTausPassLooseMVAIso: "<<DecayMode0EndcapTausPassLooseMVAIso<<std::endl;
  std::cout<<"DecayMode0EndcapTausPassMediumMVAIso: "<<DecayMode0EndcapTausPassMediumMVAIso<<std::endl;
  std::cout<<"DecayMode0EndcapTausPassTightMVAIso: "<<DecayMode0EndcapTausPassTightMVAIso<<std::endl;
  std::cout<<"DecayMode0EndcapTausPassVTightMVAIso: "<<DecayMode0EndcapTausPassVTightMVAIso<<std::endl;
  std::cout<<"DecayMode0EndcapTausPassVVTightMVAIso: "<<DecayMode0EndcapTausPassVVTightMVAIso<<std::endl;
  std::cout<<std::endl;
  
  std::cout<<"DecayMode1BaselineSelectedTaus: "<<DecayMode1BaselineSelectedTaus<<std::endl;
  std::cout<<"DecayMode1TausPassVLooseMVAIso: "<<DecayMode1TausPassVLooseMVAIso<<std::endl;
  std::cout<<"DecayMode1TausPassLooseMVAIso: "<<DecayMode1TausPassLooseMVAIso<<std::endl;
  std::cout<<"DecayMode1TausPassMediumMVAIso: "<<DecayMode1TausPassMediumMVAIso<<std::endl;
  std::cout<<"DecayMode1TausPassTightMVAIso: "<<DecayMode1TausPassTightMVAIso<<std::endl;
  std::cout<<"DecayMode1TausPassVTightMVAIso: "<<DecayMode1TausPassVTightMVAIso<<std::endl;
  std::cout<<"DecayMode1TausPassVVTightMVAIso: "<<DecayMode1TausPassVVTightMVAIso<<std::endl;
  std::cout<<std::endl;
  
  std::cout<<"DecayMode1BarrelBaselineSelectedTaus: "<<DecayMode1BarrelBaselineSelectedTaus<<std::endl;
  std::cout<<"DecayMode1BarrelTausPassVLooseMVAIso: "<<DecayMode1BarrelTausPassVLooseMVAIso<<std::endl;
  std::cout<<"DecayMode1BarrelTausPassLooseMVAIso: "<<DecayMode1BarrelTausPassLooseMVAIso<<std::endl;
  std::cout<<"DecayMode1BarrelTausPassMediumMVAIso: "<<DecayMode1BarrelTausPassMediumMVAIso<<std::endl;
  std::cout<<"DecayMode1BarrelTausPassTightMVAIso: "<<DecayMode1BarrelTausPassTightMVAIso<<std::endl;
  std::cout<<"DecayMode1BarrelTausPassVTightMVAIso: "<<DecayMode1BarrelTausPassVTightMVAIso<<std::endl;
  std::cout<<"DecayMode1BarrelTausPassVVTightMVAIso: "<<DecayMode1BarrelTausPassVVTightMVAIso<<std::endl;
  std::cout<<std::endl;
  
  std::cout<<"DecayMode1EndcapBaselineSelectedTaus: "<<DecayMode1EndcapBaselineSelectedTaus<<std::endl;
  std::cout<<"DecayMode1EndcapTausPassVLooseMVAIso: "<<DecayMode1EndcapTausPassVLooseMVAIso<<std::endl;
  std::cout<<"DecayMode1EndcapTausPassLooseMVAIso: "<<DecayMode1EndcapTausPassLooseMVAIso<<std::endl;
  std::cout<<"DecayMode1EndcapTausPassMediumMVAIso: "<<DecayMode1EndcapTausPassMediumMVAIso<<std::endl;
  std::cout<<"DecayMode1EndcapTausPassTightMVAIso: "<<DecayMode1EndcapTausPassTightMVAIso<<std::endl;
  std::cout<<"DecayMode1EndcapTausPassVTightMVAIso: "<<DecayMode1EndcapTausPassVTightMVAIso<<std::endl;
  std::cout<<"DecayMode1EndcapTausPassVVTightMVAIso: "<<DecayMode1EndcapTausPassVVTightMVAIso<<std::endl;
  std::cout<<std::endl;
  
  std::cout<<"DecayMode10BaselineSelectedTaus: "<<DecayMode10BaselineSelectedTaus<<std::endl;
  std::cout<<"DecayMode10TausPassVLooseMVAIso: "<<DecayMode10TausPassVLooseMVAIso<<std::endl;
  std::cout<<"DecayMode10TausPassLooseMVAIso: "<<DecayMode10TausPassLooseMVAIso<<std::endl;
  std::cout<<"DecayMode10TausPassMediumMVAIso: "<<DecayMode10TausPassMediumMVAIso<<std::endl;
  std::cout<<"DecayMode10TausPassTightMVAIso: "<<DecayMode10TausPassTightMVAIso<<std::endl;
  std::cout<<"DecayMode10TausPassVTightMVAIso: "<<DecayMode10TausPassVTightMVAIso<<std::endl;
  std::cout<<"DecayMode10TausPassVVTightMVAIso: "<<DecayMode10TausPassVVTightMVAIso<<std::endl;
  std::cout<<std::endl;
  
  std::cout<<"DecayMode10BarrelBaselineSelectedTaus: "<<DecayMode10BarrelBaselineSelectedTaus<<std::endl;
  std::cout<<"DecayMode10BarrelTausPassVLooseMVAIso: "<<DecayMode10BarrelTausPassVLooseMVAIso<<std::endl;
  std::cout<<"DecayMode10BarrelTausPassLooseMVAIso: "<<DecayMode10BarrelTausPassLooseMVAIso<<std::endl;
  std::cout<<"DecayMode10BarrelTausPassMediumMVAIso: "<<DecayMode10BarrelTausPassMediumMVAIso<<std::endl;
  std::cout<<"DecayMode10BarrelTausPassTightMVAIso: "<<DecayMode10BarrelTausPassTightMVAIso<<std::endl;
  std::cout<<"DecayMode10BarrelTausPassVTightMVAIso: "<<DecayMode10BarrelTausPassVTightMVAIso<<std::endl;
  std::cout<<"DecayMode10BarrelTausPassVVTightMVAIso: "<<DecayMode10BarrelTausPassVVTightMVAIso<<std::endl;
  std::cout<<std::endl;
  
  std::cout<<"DecayMode10EndcapBaselineSelectedTaus: "<<DecayMode10EndcapBaselineSelectedTaus<<std::endl;
  std::cout<<"DecayMode10EndcapTausPassVLooseMVAIso: "<<DecayMode10EndcapTausPassVLooseMVAIso<<std::endl;
  std::cout<<"DecayMode10EndcapTausPassLooseMVAIso: "<<DecayMode10EndcapTausPassLooseMVAIso<<std::endl;
  std::cout<<"DecayMode10EndcapTausPassMediumMVAIso: "<<DecayMode10EndcapTausPassMediumMVAIso<<std::endl;
  std::cout<<"DecayMode10EndcapTausPassTightMVAIso: "<<DecayMode10EndcapTausPassTightMVAIso<<std::endl;
  std::cout<<"DecayMode10EndcapTausPassVTightMVAIso: "<<DecayMode10EndcapTausPassVTightMVAIso<<std::endl;
  std::cout<<"DecayMode10EndcapTausPassVVTightMVAIso: "<<DecayMode10EndcapTausPassVVTightMVAIso<<std::endl;
  std::cout<<std::endl;
  
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
  
  OverallEvents->SetBinContent(1,BaselineSelectedTaus);
  OverallEvents->SetBinContent(2,TausPassVLooseMVAIso);
  OverallEvents->SetBinContent(3,TausPassLooseMVAIso);
  OverallEvents->SetBinContent(4,TausPassMediumMVAIso);
  OverallEvents->SetBinContent(5,TausPassTightMVAIso);
  OverallEvents->SetBinContent(6,TausPassVTightMVAIso);
  OverallEvents->SetBinContent(7,TausPassVVTightMVAIso);

  OverallDecayMode0Events->SetBinContent(1,DecayMode0BaselineSelectedTaus);
  OverallDecayMode0Events->SetBinContent(2,DecayMode0TausPassVLooseMVAIso);
  OverallDecayMode0Events->SetBinContent(3,DecayMode0TausPassLooseMVAIso);
  OverallDecayMode0Events->SetBinContent(4,DecayMode0TausPassMediumMVAIso);
  OverallDecayMode0Events->SetBinContent(5,DecayMode0TausPassTightMVAIso);
  OverallDecayMode0Events->SetBinContent(6,DecayMode0TausPassVTightMVAIso);
  OverallDecayMode0Events->SetBinContent(7,DecayMode0TausPassVVTightMVAIso);

  OverallDecayMode1Events->SetBinContent(1,DecayMode1BaselineSelectedTaus);
  OverallDecayMode1Events->SetBinContent(2,DecayMode1TausPassVLooseMVAIso);
  OverallDecayMode1Events->SetBinContent(3,DecayMode1TausPassLooseMVAIso);
  OverallDecayMode1Events->SetBinContent(4,DecayMode1TausPassMediumMVAIso);
  OverallDecayMode1Events->SetBinContent(5,DecayMode1TausPassTightMVAIso);
  OverallDecayMode1Events->SetBinContent(6,DecayMode1TausPassVTightMVAIso);
  OverallDecayMode1Events->SetBinContent(7,DecayMode1TausPassVVTightMVAIso);

  OverallDecayMode10Events->SetBinContent(1,DecayMode10BaselineSelectedTaus);
  OverallDecayMode10Events->SetBinContent(2,DecayMode10TausPassVLooseMVAIso);
  OverallDecayMode10Events->SetBinContent(3,DecayMode10TausPassLooseMVAIso);
  OverallDecayMode10Events->SetBinContent(4,DecayMode10TausPassMediumMVAIso);
  OverallDecayMode10Events->SetBinContent(5,DecayMode10TausPassTightMVAIso);
  OverallDecayMode10Events->SetBinContent(6,DecayMode10TausPassVTightMVAIso);
  OverallDecayMode10Events->SetBinContent(7,DecayMode10TausPassVVTightMVAIso);

  OverallEvents->GetXaxis()->SetBinLabel(1,"Baseline");
  OverallEvents->GetXaxis()->SetBinLabel(2,"VLooseEvents");
  OverallEvents->GetXaxis()->SetBinLabel(3,"LooseEvents");
  OverallEvents->GetXaxis()->SetBinLabel(4,"MediumEvents");
  OverallEvents->GetXaxis()->SetBinLabel(5,"TightEvents");
  OverallEvents->GetXaxis()->SetBinLabel(6,"VTightEvents");
  OverallEvents->GetXaxis()->SetBinLabel(7,"VVTightEvents");

  OverallDecayMode0Events->GetXaxis()->SetBinLabel(1,"Baseline");
  OverallDecayMode0Events->GetXaxis()->SetBinLabel(2,"VLooseEvents");
  OverallDecayMode0Events->GetXaxis()->SetBinLabel(3,"LooseEvents");
  OverallDecayMode0Events->GetXaxis()->SetBinLabel(4,"MediumEvents");
  OverallDecayMode0Events->GetXaxis()->SetBinLabel(5,"TightEvents");
  OverallDecayMode0Events->GetXaxis()->SetBinLabel(6,"VTightEvents");
  OverallDecayMode0Events->GetXaxis()->SetBinLabel(7,"VVTightEvents");

  OverallDecayMode1Events->GetXaxis()->SetBinLabel(1,"Baseline");
  OverallDecayMode1Events->GetXaxis()->SetBinLabel(2,"VLooseEvents");
  OverallDecayMode1Events->GetXaxis()->SetBinLabel(3,"LooseEvents");
  OverallDecayMode1Events->GetXaxis()->SetBinLabel(4,"MediumEvents");
  OverallDecayMode1Events->GetXaxis()->SetBinLabel(5,"TightEvents");
  OverallDecayMode1Events->GetXaxis()->SetBinLabel(6,"VTightEvents");
  OverallDecayMode1Events->GetXaxis()->SetBinLabel(7,"VVTightEvents");

  OverallDecayMode10Events->GetXaxis()->SetBinLabel(1,"Baseline");
  OverallDecayMode10Events->GetXaxis()->SetBinLabel(2,"VLooseEvents");
  OverallDecayMode10Events->GetXaxis()->SetBinLabel(3,"LooseEvents");
  OverallDecayMode10Events->GetXaxis()->SetBinLabel(4,"MediumEvents");
  OverallDecayMode10Events->GetXaxis()->SetBinLabel(5,"TightEvents");
  OverallDecayMode10Events->GetXaxis()->SetBinLabel(6,"VTightEvents");
  OverallDecayMode10Events->GetXaxis()->SetBinLabel(7,"VVTightEvents");
  
  //create the pt distributions fake rate distributions
  BaselineSelectedTauPT->Sumw2();
  VVTightPTEvents->Sumw2();
  VTightPTEvents->Sumw2();
  TightPTEvents->Sumw2();
  MediumPTEvents->Sumw2();
  LoosePTEvents->Sumw2();
  VLoosePTEvents->Sumw2();
  
  //errors
  BaselineDecayMode0PTEvents->Sumw2();
  BaselineDecayMode1PTEvents->Sumw2();
  BaselineDecayMode10PTEvents->Sumw2();
  
  VLooseDecayMode0PTEvents->Sumw2();
  VLooseDecayMode1PTEvents->Sumw2();
  VLooseDecayMode10PTEvents->Sumw2();

  LooseDecayMode0PTEvents->Sumw2();
  LooseDecayMode1PTEvents->Sumw2();
  LooseDecayMode10PTEvents->Sumw2();

  MediumDecayMode0PTEvents->Sumw2();
  MediumDecayMode1PTEvents->Sumw2();
  MediumDecayMode10PTEvents->Sumw2();

  TightDecayMode0PTEvents->Sumw2();
  TightDecayMode1PTEvents->Sumw2();
  TightDecayMode10PTEvents->Sumw2();

  VTightDecayMode0PTEvents->Sumw2();
  VTightDecayMode1PTEvents->Sumw2();
  VTightDecayMode10PTEvents->Sumw2();

  VVTightDecayMode0PTEvents->Sumw2();
  VVTightDecayMode1PTEvents->Sumw2();
  VVTightDecayMode10PTEvents->Sumw2();

  //barrel
  //errors
  BaselineDecayMode0PTBarrelEvents->Sumw2();
  BaselineDecayMode1PTBarrelEvents->Sumw2();
  BaselineDecayMode10PTBarrelEvents->Sumw2();
  
  VLooseDecayMode0PTBarrelEvents->Sumw2();
  VLooseDecayMode1PTBarrelEvents->Sumw2();
  VLooseDecayMode10PTBarrelEvents->Sumw2();

  LooseDecayMode0PTBarrelEvents->Sumw2();
  LooseDecayMode1PTBarrelEvents->Sumw2();
  LooseDecayMode10PTBarrelEvents->Sumw2();

  MediumDecayMode0PTBarrelEvents->Sumw2();
  MediumDecayMode1PTBarrelEvents->Sumw2();
  MediumDecayMode10PTBarrelEvents->Sumw2();

  TightDecayMode0PTBarrelEvents->Sumw2();
  TightDecayMode1PTBarrelEvents->Sumw2();
  TightDecayMode10PTBarrelEvents->Sumw2();

  VTightDecayMode0PTBarrelEvents->Sumw2();
  VTightDecayMode1PTBarrelEvents->Sumw2();
  VTightDecayMode10PTBarrelEvents->Sumw2();

  VVTightDecayMode0PTBarrelEvents->Sumw2();
  VVTightDecayMode1PTBarrelEvents->Sumw2();
  VVTightDecayMode10PTBarrelEvents->Sumw2();

  //endcap
  //errors
  BaselineDecayMode0PTEndcapEvents->Sumw2();
  BaselineDecayMode1PTEndcapEvents->Sumw2();
  BaselineDecayMode10PTEndcapEvents->Sumw2();
  
  VLooseDecayMode0PTEndcapEvents->Sumw2();
  VLooseDecayMode1PTEndcapEvents->Sumw2();
  VLooseDecayMode10PTEndcapEvents->Sumw2();

  LooseDecayMode0PTEndcapEvents->Sumw2();
  LooseDecayMode1PTEndcapEvents->Sumw2();
  LooseDecayMode10PTEndcapEvents->Sumw2();

  MediumDecayMode0PTEndcapEvents->Sumw2();
  MediumDecayMode1PTEndcapEvents->Sumw2();
  MediumDecayMode10PTEndcapEvents->Sumw2();

  TightDecayMode0PTEndcapEvents->Sumw2();
  TightDecayMode1PTEndcapEvents->Sumw2();
  TightDecayMode10PTEndcapEvents->Sumw2();

  VTightDecayMode0PTEndcapEvents->Sumw2();
  VTightDecayMode1PTEndcapEvents->Sumw2();
  VTightDecayMode10PTEndcapEvents->Sumw2();

  VVTightDecayMode0PTEndcapEvents->Sumw2();
  VVTightDecayMode1PTEndcapEvents->Sumw2();
  VVTightDecayMode10PTEndcapEvents->Sumw2();

  TFile* FakeRateEventsFile = new TFile(("../Distributions/FakeRate"+Input+"EventsDistributions.root").c_str(),"RECREATE");
  TDirectory* TheDirectory = FakeRateEventsFile->mkdir(Input.c_str());
  TheDirectory->cd();
  OverallEvents->Write();
  OverallDecayMode0Events->Write();
  OverallDecayMode1Events->Write();
  OverallDecayMode10Events->Write();
  BaselineSelectedTauPT->Write();
  VLoosePTEvents->Write();
  LoosePTEvents->Write();
  MediumPTEvents->Write();
  TightPTEvents->Write();
  VTightPTEvents->Write();
  VVTightPTEvents->Write();

  VVTightDecayMode0PTEvents->Write();
  VVTightDecayMode1PTEvents->Write();
  VVTightDecayMode10PTEvents->Write();

  VTightDecayMode0PTEvents->Write();
  VTightDecayMode1PTEvents->Write();
  VTightDecayMode10PTEvents->Write();

  TightDecayMode0PTEvents->Write();
  TightDecayMode1PTEvents->Write();
  TightDecayMode10PTEvents->Write();

  MediumDecayMode0PTEvents->Write();
  MediumDecayMode1PTEvents->Write();
  MediumDecayMode10PTEvents->Write();

  LooseDecayMode0PTEvents->Write();
  LooseDecayMode1PTEvents->Write();
  LooseDecayMode10PTEvents->Write();

  VLooseDecayMode0PTEvents->Write();
  VLooseDecayMode1PTEvents->Write();
  VLooseDecayMode10PTEvents->Write();
  
  BaselineDecayMode0PTEvents->Write();
  BaselineDecayMode1PTEvents->Write();
  BaselineDecayMode10PTEvents->Write();

  //barrel
  VVTightDecayMode0PTBarrelEvents->Write();
  VVTightDecayMode1PTBarrelEvents->Write();
  VVTightDecayMode10PTBarrelEvents->Write();

  VTightDecayMode0PTBarrelEvents->Write();
  VTightDecayMode1PTBarrelEvents->Write();
  VTightDecayMode10PTBarrelEvents->Write();

  TightDecayMode0PTBarrelEvents->Write();
  TightDecayMode1PTBarrelEvents->Write();
  TightDecayMode10PTBarrelEvents->Write();

  MediumDecayMode0PTBarrelEvents->Write();
  MediumDecayMode1PTBarrelEvents->Write();
  MediumDecayMode10PTBarrelEvents->Write();

  LooseDecayMode0PTBarrelEvents->Write();
  LooseDecayMode1PTBarrelEvents->Write();
  LooseDecayMode10PTBarrelEvents->Write();

  VLooseDecayMode0PTBarrelEvents->Write();
  VLooseDecayMode1PTBarrelEvents->Write();
  VLooseDecayMode10PTBarrelEvents->Write();

  BaselineDecayMode0PTBarrelEvents->Write();
  BaselineDecayMode1PTBarrelEvents->Write();
  BaselineDecayMode10PTBarrelEvents->Write();

  //endcap
  VVTightDecayMode0PTEndcapEvents->Write();
  VVTightDecayMode1PTEndcapEvents->Write();
  VVTightDecayMode10PTEndcapEvents->Write();

  VTightDecayMode0PTEndcapEvents->Write();
  VTightDecayMode1PTEndcapEvents->Write();
  VTightDecayMode10PTEndcapEvents->Write();

  TightDecayMode0PTEndcapEvents->Write();
  TightDecayMode1PTEndcapEvents->Write();
  TightDecayMode10PTEndcapEvents->Write();

  MediumDecayMode0PTEndcapEvents->Write();
  MediumDecayMode1PTEndcapEvents->Write();
  MediumDecayMode10PTEndcapEvents->Write();

  LooseDecayMode0PTEndcapEvents->Write();
  LooseDecayMode1PTEndcapEvents->Write();
  LooseDecayMode10PTEndcapEvents->Write();

  VLooseDecayMode0PTEndcapEvents->Write();
  VLooseDecayMode1PTEndcapEvents->Write();
  VLooseDecayMode10PTEndcapEvents->Write();

  BaselineDecayMode0PTEndcapEvents->Write();
  BaselineDecayMode1PTEndcapEvents->Write();
  BaselineDecayMode10PTEndcapEvents->Write();

  FakeRateEventsFile->Close();
}
