#include "TROOT.h"
#include <string>
#include "/data/aloeliger/CMSSW_9_4_0/src/PhysicsTools/Utilities/interface/LumiReweightingStandAlone.h"
//just for the helper functions
//this is sorta overkill
#include "GenerateJetSamples.cc"
#include "../Zpt/zptweight.C"

void GenerateMCInJetsRegion(std::string input, int PtBracket = 0, int EtaBracket = 0)
{
  TFile *MyFile = new TFile(("/data/aloeliger/CMSSW_9_4_0/src/SMHTTAnalysis/SkimmedNtuples/TauID2017/"+input+".root").c_str());
  TTree *Tree = (TTree*) MyFile->Get("mutau_tree");
  TH1F* nevents = (TH1F*) MyFile->Get("summedWeights");
  float TotalNumberOfEvents = nevents->GetBinContent(1);

  readZptFile();
  
  UInt_t run,lumi;
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
  //These are now precalculated in the ntuple
  float PZetaVis;
  float PZetaAll;
  float PZeta;
  float TransverseMass;
  // needed for ZPT reweighting
  float genpT;
  float genM;

  // now we branch address these guys, and we can start running trees
  Tree->SetBranchAddress("run",&run);
  Tree->SetBranchAddress("lumi",&lumi);
  Tree->SetBranchAddress("evt",&evt);
  Tree->SetBranchAddress("NUP",&NUP);
  Tree->SetBranchAddress("npv",&npv);
  Tree->SetBranchAddress("npu",&npu);
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
  //needed for ZPT reweighting
  Tree->SetBranchAddress("genpT", &genpT);
  Tree->SetBranchAddress("genM", &genM);

  int NumberOfEntries = (int) Tree->GetEntries();

  //this needs to change to have the new splti shapes accounted for.
  
  TFile* PassFailFile = new TFile("../Distributions/PassFailOut.root");
  TH1F* Data_Pass = (TH1F*)((TDirectory*)PassFailFile->Get("pass"))->Get("Data_Pass");

  TH1F* VLooseResultHisto = new TH1F((input+"_VLoose_JetRegion").c_str(),
				     (input+"_VLoose_JetRegion").c_str(),
				     Data_Pass->GetNbinsX(),
				     Data_Pass->GetXaxis()->GetXmin(),
				     Data_Pass->GetXaxis()->GetXmax());

  TH1F* LooseResultHisto = new TH1F((input+"_Loose_JetRegion").c_str(),
				    (input+"_Loose_JetRegion").c_str(),
				    Data_Pass->GetNbinsX(),
				    Data_Pass->GetXaxis()->GetXmin(),
				    Data_Pass->GetXaxis()->GetXmax());

  TH1F* MediumResultHisto = new TH1F((input+"_Medium_JetRegion").c_str(),
				     (input+"_Medium_JetRegion").c_str(),
				     Data_Pass->GetNbinsX(),
				     Data_Pass->GetXaxis()->GetXmin(),
				     Data_Pass->GetXaxis()->GetXmax());

  TH1F* TightResultHisto = new TH1F((input+"_Tight_JetRegion").c_str(),
				    (input+"_Tight_JetRegion").c_str(),
				    Data_Pass->GetNbinsX(),
				    Data_Pass->GetXaxis()->GetXmin(),
				    Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightResultHisto = new TH1F((input+"_VTight_JetRegion").c_str(),
				     (input+"_VTight_JetRegion").c_str(),
				     Data_Pass->GetNbinsX(),
				     Data_Pass->GetXaxis()->GetXmin(),
				     Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* VVTightResultHisto = new TH1F((input+"_VVTight_JetRegion").c_str(),
				     (input+"_VVTight_JetRegion").c_str(),
				     Data_Pass->GetNbinsX(),
				     Data_Pass->GetXaxis()->GetXmin(),
				     Data_Pass->GetXaxis()->GetXmax());

  //control plots  
  //VLoose
  TH1F* VLoose_MuPt = new TH1F((input+"_VLoose_MuPt").c_str(),
			       (input+"_VLoose_MuPt").c_str(),
			       100,
			       0.0,
			       200.0);
  
  TH1F* VLoose_TauPt = new TH1F((input+"_VLoose_TauPt").c_str(),
				(input+"_VLoose_TauPt").c_str(),
				100,
				0.0,
				200.0);
  
  TH1F* VLoose_MuEta = new TH1F((input+"_VLoose_MuEta").c_str(),
				(input+"_VLoose_MuEta").c_str(),
				100,
				-4.0,
				4.0);
  
  TH1F* VLoose_TauEta = new TH1F((input+"_VLoose_TauEta").c_str(),
				 (input+"_VLoose_TauEta").c_str(),
				 100,
				 -4.0,
				 4.0);
  
  TH1F* VLoose_NJets = new TH1F((input+"_VLoose_njets").c_str(),
				(input+"_VLoose_njets").c_str(),
				5,
				0.0,
				5.0);
  
  TH1F* VLoose_NBtag = new TH1F((input+"_VLoose_nbtag").c_str(),
				(input+"_VLoose_nbtag").c_str(),
				5,
				0.0,
				5.0);
  
  TH1F* VLoose_ZMass = new TH1F((input+"_VLoose_ZMass").c_str(),
				(input+"_VLoose_ZMass").c_str(),
				100,
				0.0,
				200.0);
  
  TH1F* VLoose_ZPT = new TH1F((input+"_VLoose_ZPT").c_str(),
			      (input+"_VLoose_ZPT").c_str(),
			      100,
			      0.0,
			      500.0);
  TH1F* VLoose_MT = new TH1F((input+"_VLoose_MT").c_str(),
			     (input+"_VLoose_MT").c_str(),
			     100,
			     0.0,
			     200.0);
  //Loose
  TH1F* Loose_MuPt = new TH1F((input+"_Loose_MuPt").c_str(),
			       (input+"_Loose_MuPt").c_str(),
			       100,
			       0.0,
			       200.0);
  
  TH1F* Loose_TauPt = new TH1F((input+"_Loose_TauPt").c_str(),
				(input+"_Loose_TauPt").c_str(),
				100,
				0.0,
				200.0);
  
  TH1F* Loose_MuEta = new TH1F((input+"_Loose_MuEta").c_str(),
				(input+"_Loose_MuEta").c_str(),
				100,
				-4.0,
				4.0);
  
  TH1F* Loose_TauEta = new TH1F((input+"_Loose_TauEta").c_str(),
				 (input+"_Loose_TauEta").c_str(),
				 100,
				 -4.0,
				 4.0);
  
  TH1F* Loose_NJets = new TH1F((input+"_Loose_njets").c_str(),
				(input+"_Loose_njets").c_str(),
				5,
				0.0,
				5.0);
  
  TH1F* Loose_NBtag = new TH1F((input+"_Loose_nbtag").c_str(),
				(input+"_Loose_nbtag").c_str(),
				5,
				0.0,
				5.0);
  
  TH1F* Loose_ZMass = new TH1F((input+"_Loose_ZMass").c_str(),
				(input+"_Loose_ZMass").c_str(),
				100,
				0.0,
				200.0);
  
  TH1F* Loose_ZPT = new TH1F((input+"_Loose_ZPT").c_str(),
			      (input+"_Loose_ZPT").c_str(),
			      100,
			      0.0,
			      500.0);
  TH1F* Loose_MT = new TH1F((input+"_Loose_MT").c_str(),
			     (input+"_Loose_MT").c_str(),
			     100,
			     0.0,
			     200.0);
  //Medium
  TH1F* Medium_MuPt = new TH1F((input+"_Medium_MuPt").c_str(),
			       (input+"_Medium_MuPt").c_str(),
			       100,
			       0.0,
			       200.0);
  
  TH1F* Medium_TauPt = new TH1F((input+"_Medium_TauPt").c_str(),
				(input+"_Medium_TauPt").c_str(),
				100,
				0.0,
				200.0);
  
  TH1F* Medium_MuEta = new TH1F((input+"_Medium_MuEta").c_str(),
				(input+"_Medium_MuEta").c_str(),
				100,
				-4.0,
				4.0);
  
  TH1F* Medium_TauEta = new TH1F((input+"_Medium_TauEta").c_str(),
				 (input+"_Medium_TauEta").c_str(),
				 100,
				 -4.0,
				 4.0);
  
  TH1F* Medium_NJets = new TH1F((input+"_Medium_njets").c_str(),
				(input+"_Medium_njets").c_str(),
				5,
				0.0,
				5.0);
  
  TH1F* Medium_NBtag = new TH1F((input+"_Medium_nbtag").c_str(),
				(input+"_Medium_nbtag").c_str(),
				5,
				0.0,
				5.0);
  
  TH1F* Medium_ZMass = new TH1F((input+"_Medium_ZMass").c_str(),
				(input+"_Medium_ZMass").c_str(),
				100,
				0.0,
				200.0);
  
  TH1F* Medium_ZPT = new TH1F((input+"_Medium_ZPT").c_str(),
			      (input+"_Medium_ZPT").c_str(),
			      100,
			      0.0,
			      500.0);
  TH1F* Medium_MT = new TH1F((input+"_Medium_MT").c_str(),
			     (input+"_Medium_MT").c_str(),
			     100,
			     0.0,
			     200.0);
  //Tight
  TH1F* Tight_MuPt = new TH1F((input+"_Tight_MuPt").c_str(),
			       (input+"_Tight_MuPt").c_str(),
			       100,
			       0.0,
			       200.0);
  
  TH1F* Tight_TauPt = new TH1F((input+"_Tight_TauPt").c_str(),
				(input+"_Tight_TauPt").c_str(),
				100,
				0.0,
				200.0);
  
  TH1F* Tight_MuEta = new TH1F((input+"_Tight_MuEta").c_str(),
				(input+"_Tight_MuEta").c_str(),
				100,
				-4.0,
				4.0);
  
  TH1F* Tight_TauEta = new TH1F((input+"_Tight_TauEta").c_str(),
				 (input+"_Tight_TauEta").c_str(),
				 100,
				 -4.0,
				 4.0);
  
  TH1F* Tight_NJets = new TH1F((input+"_Tight_njets").c_str(),
				(input+"_Tight_njets").c_str(),
				5,
				0.0,
				5.0);
  
  TH1F* Tight_NBtag = new TH1F((input+"_Tight_nbtag").c_str(),
				(input+"_Tight_nbtag").c_str(),
				5,
				0.0,
				5.0);
  
  TH1F* Tight_ZMass = new TH1F((input+"_Tight_ZMass").c_str(),
				(input+"_Tight_ZMass").c_str(),
				100,
				0.0,
				200.0);
  
  TH1F* Tight_ZPT = new TH1F((input+"_Tight_ZPT").c_str(),
			      (input+"_Tight_ZPT").c_str(),
			      100,
			      0.0,
			      500.0);
  TH1F* Tight_MT = new TH1F((input+"_Tight_MT").c_str(),
			     (input+"_Tight_MT").c_str(),
			     100,
			     0.0,
			     200.0);
  //VTight
  TH1F* VTight_MuPt = new TH1F((input+"_VTight_MuPt").c_str(),
			       (input+"_VTight_MuPt").c_str(),
			       100,
			       0.0,
			       200.0);
  
  TH1F* VTight_TauPt = new TH1F((input+"_VTight_TauPt").c_str(),
				(input+"_VTight_TauPt").c_str(),
				100,
				0.0,
				200.0);
  
  TH1F* VTight_MuEta = new TH1F((input+"_VTight_MuEta").c_str(),
				(input+"_VTight_MuEta").c_str(),
				100,
				-4.0,
				4.0);
  
  TH1F* VTight_TauEta = new TH1F((input+"_VTight_TauEta").c_str(),
				 (input+"_VTight_TauEta").c_str(),
				 100,
				 -4.0,
				 4.0);
  
  TH1F* VTight_NJets = new TH1F((input+"_VTight_njets").c_str(),
				(input+"_VTight_njets").c_str(),
				5,
				0.0,
				5.0);
  
  TH1F* VTight_NBtag = new TH1F((input+"_VTight_nbtag").c_str(),
				(input+"_VTight_nbtag").c_str(),
				5,
				0.0,
				5.0);
  
  TH1F* VTight_ZMass = new TH1F((input+"_VTight_ZMass").c_str(),
				(input+"_VTight_ZMass").c_str(),
				100,
				0.0,
				200.0);
  
  TH1F* VTight_ZPT = new TH1F((input+"_VTight_ZPT").c_str(),
			      (input+"_VTight_ZPT").c_str(),
			      100,
			      0.0,
			      500.0);
  TH1F* VTight_MT = new TH1F((input+"_VTight_MT").c_str(),
			     (input+"_VTight_MT").c_str(),
			     100,
			     0.0,
			     200.0);
  //VVTight
  TH1F* VVTight_MuPt = new TH1F((input+"_VVTight_MuPt").c_str(),
			       (input+"_VVTight_MuPt").c_str(),
			       100,
			       0.0,
			       200.0);
  
  TH1F* VVTight_TauPt = new TH1F((input+"_VVTight_TauPt").c_str(),
				(input+"_VVTight_TauPt").c_str(),
				100,
				0.0,
				200.0);
  
  TH1F* VVTight_MuEta = new TH1F((input+"_VVTight_MuEta").c_str(),
				(input+"_VVTight_MuEta").c_str(),
				100,
				-4.0,
				4.0);
  
  TH1F* VVTight_TauEta = new TH1F((input+"_VVTight_TauEta").c_str(),
				 (input+"_VVTight_TauEta").c_str(),
				 100,
				 -4.0,
				 4.0);
  
  TH1F* VVTight_NJets = new TH1F((input+"_VVTight_njets").c_str(),
				(input+"_VVTight_njets").c_str(),
				5,
				0.0,
				5.0);
  
  TH1F* VVTight_NBtag = new TH1F((input+"_VVTight_nbtag").c_str(),
				(input+"_VVTight_nbtag").c_str(),
				5,
				0.0,
				5.0);
  
  TH1F* VVTight_ZMass = new TH1F((input+"_VVTight_ZMass").c_str(),
				(input+"_VVTight_ZMass").c_str(),
				100,
				0.0,
				200.0);
  
  TH1F* VVTight_ZPT = new TH1F((input+"_VVTight_ZPT").c_str(),
			      (input+"_VVTight_ZPT").c_str(),
			      100,
			      0.0,
			      500.0);
  TH1F* VVTight_MT = new TH1F((input+"_VVTight_MT").c_str(),
			     (input+"_VVTight_MT").c_str(),
			     100,
			     0.0,
			     200.0);

  //SS control plots  
  //VLoose
  TH1F* VLoose_MuPt_SS = new TH1F((input+"_VLoose_MuPt_SS").c_str(),
				  (input+"_VLoose_MuPt_SS").c_str(),
				  100,
				  0.0,
				  200.0);
  
  TH1F* VLoose_TauPt_SS = new TH1F((input+"_VLoose_TauPt_SS").c_str(),
				   (input+"_VLoose_TauPt_SS").c_str(),
				   100,
				   0.0,
				   200.0);
  
  TH1F* VLoose_MuEta_SS = new TH1F((input+"_VLoose_MuEta_SS").c_str(),
				   (input+"_VLoose_MuEta_SS").c_str(),
				   100,
				   -4.0,
				   4.0);
  
  TH1F* VLoose_TauEta_SS = new TH1F((input+"_VLoose_TauEta_SS").c_str(),
				    (input+"_VLoose_TauEta_SS").c_str(),
				    100,
				    -4.0,
				    4.0);
  
  TH1F* VLoose_NJets_SS = new TH1F((input+"_VLoose_njets_SS").c_str(),
				   (input+"_VLoose_njets_SS").c_str(),
				   5,
				   0.0,
				   5.0);
  
  TH1F* VLoose_NBtag_SS = new TH1F((input+"_VLoose_nbtag_SS").c_str(),
				   (input+"_VLoose_nbtag_SS").c_str(),
				   5,
				   0.0,
				   5.0);
  
  TH1F* VLoose_ZMass_SS = new TH1F((input+"_VLoose_ZMass_SS").c_str(),
				   (input+"_VLoose_ZMass_SS").c_str(),
				   100,
				   0.0,
				   200.0);
  
  TH1F* VLoose_ZPT_SS = new TH1F((input+"_VLoose_ZPT_SS").c_str(),
				 (input+"_VLoose_ZPT_SS").c_str(),
				 100,
				 0.0,
				 500.0);
  TH1F* VLoose_MT_SS = new TH1F((input+"_VLoose_MT_SS").c_str(),
				(input+"_VLoose_MT_SS").c_str(),
				100,
				0.0,
				200.0);
  //Loose
  TH1F* Loose_MuPt_SS = new TH1F((input+"_Loose_MuPt_SS").c_str(),
				 (input+"_Loose_MuPt_SS").c_str(),
				 100,
				 0.0,
				 200.0);
  
  TH1F* Loose_TauPt_SS = new TH1F((input+"_Loose_TauPt_SS").c_str(),
				  (input+"_Loose_TauPt_SS").c_str(),
				  100,
				  0.0,
				  200.0);
  
  TH1F* Loose_MuEta_SS = new TH1F((input+"_Loose_MuEta_SS").c_str(),
				  (input+"_Loose_MuEta_SS").c_str(),
				  100,
				  -4.0,
				  4.0);
  
  TH1F* Loose_TauEta_SS = new TH1F((input+"_Loose_TauEta_SS").c_str(),
				   (input+"_Loose_TauEta_SS").c_str(),
				   100,
				   -4.0,
				   4.0);
  
  TH1F* Loose_NJets_SS = new TH1F((input+"_Loose_njets_SS").c_str(),
				  (input+"_Loose_njets_SS").c_str(),
				  5,
				  0.0,
				  5.0);
  
  TH1F* Loose_NBtag_SS = new TH1F((input+"_Loose_nbtag_SS").c_str(),
				  (input+"_Loose_nbtag_SS").c_str(),
				  5,
				  0.0,
				  5.0);
  
  TH1F* Loose_ZMass_SS = new TH1F((input+"_Loose_ZMass_SS").c_str(),
				  (input+"_Loose_ZMass_SS").c_str(),
				  100,
				  0.0,
				  200.0);
  
  TH1F* Loose_ZPT_SS = new TH1F((input+"_Loose_ZPT_SS").c_str(),
				(input+"_Loose_ZPT_SS").c_str(),
				100,
				0.0,
				500.0);
  TH1F* Loose_MT_SS = new TH1F((input+"_Loose_MT_SS").c_str(),
			       (input+"_Loose_MT_SS").c_str(),
			       100,
			       0.0,
			       200.0);
  //Medium
  TH1F* Medium_MuPt_SS = new TH1F((input+"_Medium_MuPt_SS").c_str(),
				  (input+"_Medium_MuPt_SS").c_str(),
				  100,
				  0.0,
				  200.0);
  
  TH1F* Medium_TauPt_SS = new TH1F((input+"_Medium_TauPt_SS").c_str(),
				   (input+"_Medium_TauPt_SS").c_str(),
				   100,
				   0.0,
				   200.0);
  
  TH1F* Medium_MuEta_SS = new TH1F((input+"_Medium_MuEta_SS").c_str(),
				   (input+"_Medium_MuEta_SS").c_str(),
				   100,
				   -4.0,
				   4.0);
  
  TH1F* Medium_TauEta_SS = new TH1F((input+"_Medium_TauEta_SS").c_str(),
				    (input+"_Medium_TauEta_SS").c_str(),
				    100,
				    -4.0,
				    4.0);
  
  TH1F* Medium_NJets_SS = new TH1F((input+"_Medium_njets_SS").c_str(),
				   (input+"_Medium_njets_SS").c_str(),
				   5,
				   0.0,
				   5.0);
  
  TH1F* Medium_NBtag_SS = new TH1F((input+"_Medium_nbtag_SS").c_str(),
				   (input+"_Medium_nbtag_SS").c_str(),
				   5,
				   0.0,
				   5.0);
  
  TH1F* Medium_ZMass_SS = new TH1F((input+"_Medium_ZMass_SS").c_str(),
				   (input+"_Medium_ZMass_SS").c_str(),
				   100,
				   0.0,
				   200.0);
  
  TH1F* Medium_ZPT_SS = new TH1F((input+"_Medium_ZPT_SS").c_str(),
				 (input+"_Medium_ZPT_SS").c_str(),
				 100,
				 0.0,
				 500.0);
  TH1F* Medium_MT_SS = new TH1F((input+"_Medium_MT_SS").c_str(),
				(input+"_Medium_MT_SS").c_str(),
				100,
				0.0,
				200.0);
  //Tight
  TH1F* Tight_MuPt_SS = new TH1F((input+"_Tight_MuPt_SS").c_str(),
				 (input+"_Tight_MuPt_SS").c_str(),
				 100,
				 0.0,
				 200.0);
  
  TH1F* Tight_TauPt_SS = new TH1F((input+"_Tight_TauPt_SS").c_str(),
				  (input+"_Tight_TauPt_SS").c_str(),
				  100,
				  0.0,
				  200.0);
  
  TH1F* Tight_MuEta_SS = new TH1F((input+"_Tight_MuEta_SS").c_str(),
				  (input+"_Tight_MuEta_SS").c_str(),
				  100,
				  -4.0,
				  4.0);
  
  TH1F* Tight_TauEta_SS = new TH1F((input+"_Tight_TauEta_SS").c_str(),
				   (input+"_Tight_TauEta_SS").c_str(),
				   100,
				   -4.0,
				   4.0);
  
  TH1F* Tight_NJets_SS = new TH1F((input+"_Tight_njets_SS").c_str(),
				  (input+"_Tight_njets_SS").c_str(),
				  5,
				  0.0,
				  5.0);
  
  TH1F* Tight_NBtag_SS = new TH1F((input+"_Tight_nbtag_SS").c_str(),
				  (input+"_Tight_nbtag_SS").c_str(),
				  5,
				  0.0,
				  5.0);
  
  TH1F* Tight_ZMass_SS = new TH1F((input+"_Tight_ZMass_SS").c_str(),
				  (input+"_Tight_ZMass_SS").c_str(),
				  100,
				  0.0,
				  200.0);
  
  TH1F* Tight_ZPT_SS = new TH1F((input+"_Tight_ZPT_SS").c_str(),
				(input+"_Tight_ZPT_SS").c_str(),
				100,
				0.0,
				500.0);
  TH1F* Tight_MT_SS = new TH1F((input+"_Tight_MT_SS").c_str(),
			       (input+"_Tight_MT_SS").c_str(),
			       100,
			       0.0,
			       200.0);
  //VTight
  TH1F* VTight_MuPt_SS = new TH1F((input+"_VTight_MuPt_SS").c_str(),
				  (input+"_VTight_MuPt_SS").c_str(),
				  100,
				  0.0,
				  200.0);
  
  TH1F* VTight_TauPt_SS = new TH1F((input+"_VTight_TauPt_SS").c_str(),
				   (input+"_VTight_TauPt_SS").c_str(),
				   100,
				   0.0,
				   200.0);
  
  TH1F* VTight_MuEta_SS = new TH1F((input+"_VTight_MuEta_SS").c_str(),
				   (input+"_VTight_MuEta_SS").c_str(),
				   100,
				   -4.0,
				   4.0);
  
  TH1F* VTight_TauEta_SS = new TH1F((input+"_VTight_TauEta_SS").c_str(),
				    (input+"_VTight_TauEta_SS").c_str(),
				    100,
				    -4.0,
				    4.0);
  
  TH1F* VTight_NJets_SS = new TH1F((input+"_VTight_njets_SS").c_str(),
				   (input+"_VTight_njets_SS").c_str(),
				   5,
				   0.0,
				   5.0);
  
  TH1F* VTight_NBtag_SS = new TH1F((input+"_VTight_nbtag_SS").c_str(),
				   (input+"_VTight_nbtag_SS").c_str(),
				   5,
				   0.0,
				   5.0);
  
  TH1F* VTight_ZMass_SS = new TH1F((input+"_VTight_ZMass_SS").c_str(),
				   (input+"_VTight_ZMass_SS").c_str(),
				   100,
				   0.0,
				   200.0);
  
  TH1F* VTight_ZPT_SS = new TH1F((input+"_VTight_ZPT_SS").c_str(),
				 (input+"_VTight_ZPT_SS").c_str(),
				 100,
				 0.0,
				 500.0);
  TH1F* VTight_MT_SS = new TH1F((input+"_VTight_MT_SS").c_str(),
				(input+"_VTight_MT_SS").c_str(),
				100,
				0.0,
				200.0);
  //VVTight
  TH1F* VVTight_MuPt_SS = new TH1F((input+"_VVTight_MuPt_SS").c_str(),
				   (input+"_VVTight_MuPt_SS").c_str(),
				   100,
				   0.0,
				   200.0);
  
  TH1F* VVTight_TauPt_SS = new TH1F((input+"_VVTight_TauPt_SS").c_str(),
				    (input+"_VVTight_TauPt_SS").c_str(),
				    100,
				    0.0,
				    200.0);
  
  TH1F* VVTight_MuEta_SS = new TH1F((input+"_VVTight_MuEta_SS").c_str(),
				    (input+"_VVTight_MuEta_SS").c_str(),
				    100,
				    -4.0,
				    4.0);
  
  TH1F* VVTight_TauEta_SS = new TH1F((input+"_VVTight_TauEta_SS").c_str(),
				     (input+"_VVTight_TauEta_SS").c_str(),
				     100,
				     -4.0,
				     4.0);
  
  TH1F* VVTight_NJets_SS = new TH1F((input+"_VVTight_njets_SS").c_str(),
				    (input+"_VVTight_njets_SS").c_str(),
				    5,
				    0.0,
				    5.0);
  
  TH1F* VVTight_NBtag_SS = new TH1F((input+"_VVTight_nbtag_SS").c_str(),
				    (input+"_VVTight_nbtag_SS").c_str(),
				    5,
				    0.0,
				    5.0);
  
  TH1F* VVTight_ZMass_SS = new TH1F((input+"_VVTight_ZMass_SS").c_str(),
				    (input+"_VVTight_ZMass_SS").c_str(),
				    100,
				    0.0,
				    200.0);
  
  TH1F* VVTight_ZPT_SS = new TH1F((input+"_VVTight_ZPT_SS").c_str(),
				  (input+"_VVTight_ZPT_SS").c_str(),
				  100,
				  0.0,
				  500.0);
  TH1F* VVTight_MT_SS = new TH1F((input+"_VVTight_MT_SS").c_str(),
				 (input+"_VVTight_MT_SS").c_str(),
				 100,
				 0.0,
				 200.0);
  
  
  //shape uncertainties
  TH1F* VLooseDecayMode0UPResultHisto = new TH1F((input+"_DecayMode0_UP_VLoose_JetRegion").c_str(),
				       (input+"_DecayMode0_UP_VLoose_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* LooseDecayMode0UPResultHisto = new TH1F((input+"_DecayMode0_UP_Loose_JetRegion").c_str(),
				      (input+"_DecayMode0_UP_Loose_JetRegion").c_str(),
				      Data_Pass->GetNbinsX(),
				      Data_Pass->GetXaxis()->GetXmin(),
				      Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* MediumDecayMode0UPResultHisto = new TH1F((input+"_DecayMode0_UP_Medium_JetRegion").c_str(),
				       (input+"_DecayMode0UP_Medium_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* TightDecayMode0UPResultHisto = new TH1F((input+"_DecayMode0_UP_Tight_JetRegion").c_str(),
				      (input+"_DecayMode0_UP_Tight_JetRegion").c_str(),
				      Data_Pass->GetNbinsX(),
				      Data_Pass->GetXaxis()->GetXmin(),
				      Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightDecayMode0UPResultHisto = new TH1F((input+"_DecayMode0_UP_VTight_JetRegion").c_str(),
				       (input+"_DecayMode0_UP_VTight_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* VVTightDecayMode0UPResultHisto = new TH1F((input+"_DecayMode0_UP_VVTight_JetRegion").c_str(),
					(input+"_DecayMode0_UP_VVTight_JetRegion").c_str(),
					Data_Pass->GetNbinsX(),
					Data_Pass->GetXaxis()->GetXmin(),
					Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* VLooseDecayMode1UPResultHisto = new TH1F((input+"_DecayMode1_UP_VLoose_JetRegion").c_str(),
				       (input+"_DecayMode1_UP_VLoose_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* LooseDecayMode1UPResultHisto = new TH1F((input+"_DecayMode1_UP_Loose_JetRegion").c_str(),
				      (input+"_DecayMode1_UP_Loose_JetRegion").c_str(),
				      Data_Pass->GetNbinsX(),
				      Data_Pass->GetXaxis()->GetXmin(),
				      Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* MediumDecayMode1UPResultHisto = new TH1F((input+"_DecayMode1_UP_Medium_JetRegion").c_str(),
				       (input+"_DecayMode1UP_Medium_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* TightDecayMode1UPResultHisto = new TH1F((input+"_DecayMode1_UP_Tight_JetRegion").c_str(),
				      (input+"_DecayMode1_UP_Tight_JetRegion").c_str(),
				      Data_Pass->GetNbinsX(),
				      Data_Pass->GetXaxis()->GetXmin(),
				      Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightDecayMode1UPResultHisto = new TH1F((input+"_DecayMode1_UP_VTight_JetRegion").c_str(),
				       (input+"_DecayMode1_UP_VTight_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* VVTightDecayMode1UPResultHisto = new TH1F((input+"_DecayMode1_UP_VVTight_JetRegion").c_str(),
					(input+"_DecayMode1_UP_VVTight_JetRegion").c_str(),
					Data_Pass->GetNbinsX(),
					Data_Pass->GetXaxis()->GetXmin(),
					Data_Pass->GetXaxis()->GetXmax());

  TH1F* VLooseDecayMode10UPResultHisto = new TH1F((input+"_DecayMode10_UP_VLoose_JetRegion").c_str(),
				       (input+"_DecayMode10_UP_VLoose_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* LooseDecayMode10UPResultHisto = new TH1F((input+"_DecayMode10_UP_Loose_JetRegion").c_str(),
				      (input+"_DecayMode10_UP_Loose_JetRegion").c_str(),
				      Data_Pass->GetNbinsX(),
				      Data_Pass->GetXaxis()->GetXmin(),
				      Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* MediumDecayMode10UPResultHisto = new TH1F((input+"_DecayMode10_UP_Medium_JetRegion").c_str(),
				       (input+"_DecayMode10UP_Medium_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* TightDecayMode10UPResultHisto = new TH1F((input+"_DecayMode10_UP_Tight_JetRegion").c_str(),
				      (input+"_DecayMode10_UP_Tight_JetRegion").c_str(),
				      Data_Pass->GetNbinsX(),
				      Data_Pass->GetXaxis()->GetXmin(),
				      Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightDecayMode10UPResultHisto = new TH1F((input+"_DecayMode10_UP_VTight_JetRegion").c_str(),
				       (input+"_DecayMode10_UP_VTight_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* VVTightDecayMode10UPResultHisto = new TH1F((input+"_DecayMode10_UP_VVTight_JetRegion").c_str(),
					(input+"_DecayMode10_UP_VVTight_JetRegion").c_str(),
					Data_Pass->GetNbinsX(),
					Data_Pass->GetXaxis()->GetXmin(),
					Data_Pass->GetXaxis()->GetXmax());

  TH1F* VLooseDecayMode0DOWNResultHisto = new TH1F((input+"_DecayMode0_DOWN_VLoose_JetRegion").c_str(),
				       (input+"_DecayMode0_DOWN_VLoose_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* LooseDecayMode0DOWNResultHisto = new TH1F((input+"_DecayMode0_DOWN_Loose_JetRegion").c_str(),
				      (input+"_DecayMode0_DOWN_Loose_JetRegion").c_str(),
				      Data_Pass->GetNbinsX(),
				      Data_Pass->GetXaxis()->GetXmin(),
				      Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* MediumDecayMode0DOWNResultHisto = new TH1F((input+"_DecayMode0_DOWN_Medium_JetRegion").c_str(),
				       (input+"_DecayMode0DOWN_Medium_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* TightDecayMode0DOWNResultHisto = new TH1F((input+"_DecayMode0_DOWN_Tight_JetRegion").c_str(),
				      (input+"_DecayMode0_DOWN_Tight_JetRegion").c_str(),
				      Data_Pass->GetNbinsX(),
				      Data_Pass->GetXaxis()->GetXmin(),
				      Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightDecayMode0DOWNResultHisto = new TH1F((input+"_DecayMode0_DOWN_VTight_JetRegion").c_str(),
				       (input+"_DecayMode0_DOWN_VTight_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* VVTightDecayMode0DOWNResultHisto = new TH1F((input+"_DecayMode0_DOWN_VVTight_JetRegion").c_str(),
					(input+"_DecayMode0_DOWN_VVTight_JetRegion").c_str(),
					Data_Pass->GetNbinsX(),
					Data_Pass->GetXaxis()->GetXmin(),
					Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* VLooseDecayMode1DOWNResultHisto = new TH1F((input+"_DecayMode1_DOWN_VLoose_JetRegion").c_str(),
				       (input+"_DecayMode1_DOWN_VLoose_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* LooseDecayMode1DOWNResultHisto = new TH1F((input+"_DecayMode1_DOWN_Loose_JetRegion").c_str(),
				      (input+"_DecayMode1_DOWN_Loose_JetRegion").c_str(),
				      Data_Pass->GetNbinsX(),
				      Data_Pass->GetXaxis()->GetXmin(),
				      Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* MediumDecayMode1DOWNResultHisto = new TH1F((input+"_DecayMode1_DOWN_Medium_JetRegion").c_str(),
				       (input+"_DecayMode1DOWN_Medium_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* TightDecayMode1DOWNResultHisto = new TH1F((input+"_DecayMode1_DOWN_Tight_JetRegion").c_str(),
				      (input+"_DecayMode1_DOWN_Tight_JetRegion").c_str(),
				      Data_Pass->GetNbinsX(),
				      Data_Pass->GetXaxis()->GetXmin(),
				      Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightDecayMode1DOWNResultHisto = new TH1F((input+"_DecayMode1_DOWN_VTight_JetRegion").c_str(),
				       (input+"_DecayMode1_DOWN_VTight_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* VVTightDecayMode1DOWNResultHisto = new TH1F((input+"_DecayMode1_DOWN_VVTight_JetRegion").c_str(),
					(input+"_DecayMode1_DOWN_VVTight_JetRegion").c_str(),
					Data_Pass->GetNbinsX(),
					Data_Pass->GetXaxis()->GetXmin(),
					Data_Pass->GetXaxis()->GetXmax());

  TH1F* VLooseDecayMode10DOWNResultHisto = new TH1F((input+"_DecayMode10_DOWN_VLoose_JetRegion").c_str(),
				       (input+"_DecayMode10_DOWN_VLoose_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* LooseDecayMode10DOWNResultHisto = new TH1F((input+"_DecayMode10_DOWN_Loose_JetRegion").c_str(),
				      (input+"_DecayMode10_DOWN_Loose_JetRegion").c_str(),
				      Data_Pass->GetNbinsX(),
				      Data_Pass->GetXaxis()->GetXmin(),
				      Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* MediumDecayMode10DOWNResultHisto = new TH1F((input+"_DecayMode10_DOWN_Medium_JetRegion").c_str(),
				       (input+"_DecayMode10DOWN_Medium_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* TightDecayMode10DOWNResultHisto = new TH1F((input+"_DecayMode10_DOWN_Tight_JetRegion").c_str(),
				      (input+"_DecayMode10_DOWN_Tight_JetRegion").c_str(),
				      Data_Pass->GetNbinsX(),
				      Data_Pass->GetXaxis()->GetXmin(),
				      Data_Pass->GetXaxis()->GetXmax());
  TH1F* VTightDecayMode10DOWNResultHisto = new TH1F((input+"_DecayMode10_DOWN_VTight_JetRegion").c_str(),
				       (input+"_DecayMode10_DOWN_VTight_JetRegion").c_str(),
				       Data_Pass->GetNbinsX(),
				       Data_Pass->GetXaxis()->GetXmin(),
				       Data_Pass->GetXaxis()->GetXmax());
  
  TH1F* VVTightDecayMode10DOWNResultHisto = new TH1F((input+"_DecayMode10_DOWN_VVTight_JetRegion").c_str(),
					(input+"_DecayMode10_DOWN_VVTight_JetRegion").c_str(),
					Data_Pass->GetNbinsX(),
					Data_Pass->GetXaxis()->GetXmin(),
					Data_Pass->GetXaxis()->GetXmax());

  
  TH1F* VLoose_MT_WPlus =new TH1F((input+"_VLoose_MT_WPlus").c_str(),(input+"_VLoose_MT_WPlus").c_str(),
				  100,
				  0.0,
				  200.0);
  TH1F* Loose_MT_WPlus = new TH1F((input+"_Loose_MT_WPlus").c_str(),(input+"_Loose_MT_WPlus").c_str(),
				  100,
				  0.0,
				  200.0);
  TH1F* Medium_MT_WPlus = new TH1F((input+"_Medium_MT_WPlus").c_str(),(input+"_Medium_MT_WPlus").c_str(),
				   100,
				   0.0,
				   200.0);
  TH1F* Tight_MT_WPlus = new TH1F((input+"_Tight_MT_WPlus").c_str(),(input+"_Tight_MT_WPlus").c_str(),
				  100,
				  0.0,
				  200.0);
  TH1F* VTight_MT_WPlus = new TH1F((input+"_VTight_MT_WPlus").c_str(),(input+"_VTight_MT_WPlus").c_str(),
				   100,
				   0.0,
				   200.0);
  TH1F* VVTight_MT_WPlus = new TH1F((input+"_VVTight_MT_WPlus").c_str(),(input+"_VVTight_MT_WPlus").c_str(),
				    100,
				    0.0,
				    200.0);
  //W-
  TH1F* VLoose_MT_WMinus =new TH1F((input+"_VLoose_MT_WMinus").c_str(),(input+"_VLoose_MT_WMinus").c_str(),
				   100,
				   0.0,
				   200.0);
  TH1F* Loose_MT_WMinus = new TH1F((input+"_Loose_MT_WMinus").c_str(),(input+"_Loose_MT_WMinus").c_str(),
				   100,
				   0.0,
				   200.0);
  TH1F* Medium_MT_WMinus = new TH1F((input+"_Medium_MT_WMinus").c_str(),(input+"_Medium_MT_WMinus").c_str(),
				    100,
				    0.0,
				    200.0);
  TH1F* Tight_MT_WMinus = new TH1F((input+"_Tight_MT_WMinus").c_str(),(input+"_Tight_MT_WMinus").c_str(),
				   100,
				   0.0,
				   200.0);
  TH1F* VTight_MT_WMinus = new TH1F((input+"_VTight_MT_WMinus").c_str(),(input+"_VTight_MT_WMinus").c_str(),
				    100,
				    0.0,
				    200.0);
  TH1F* VVTight_MT_WMinus = new TH1F((input+"_VVTight_MT_WMinus").c_str(),(input+"_VVTight_MT_WMinus").c_str(),
				     100,
				     0.0,
				     200.0);

  
  //Weighting Information
  float LHCLumi = 41.370e15;
  float NormalizationWeight;
  float XSecWeight; 
  if(input == "WW")XSecWeight = LHCLumi * 118.7e-12 / TotalNumberOfEvents;
  else if(input == "WZ") XSecWeight = LHCLumi * 47.13e-12 / TotalNumberOfEvents;
  else if(input == "ZZ") XSecWeight = LHCLumi * 16.523e-12 / TotalNumberOfEvents;
  else if(input == "TTTo2L2Nu") XSecWeight = LHCLumi * 88.34e-12/ TotalNumberOfEvents;
  else if(input == "TTToHadronic") XSecWeight = LHCLumi * 377.96e-12 / TotalNumberOfEvents;
  else if(input == "TTToSemiLeptonic") XSecWeight = LHCLumi * 365.45e-12 / TotalNumberOfEvents;
  else if(input == "ST_top") XSecWeight = LHCLumi * 113.3e-12 /TotalNumberOfEvents;
  else if(input == "ST_antitop") XSecWeight = LHCLumi * 67.91e-12 /TotalNumberOfEvents;
  else if(input == "ST_tW_top") XSecWeight = LHCLumi * 34.91e-12 /TotalNumberOfEvents;
  else if(input == "ST_tW_antitop") XSecWeight = LHCLumi * 34.91e-12 /TotalNumberOfEvents;
  else if(input == "DY") XSecWeight = LHCLumi * 6225.42e-12 / TotalNumberOfEvents;
  else if(input == "DY1") XSecWeight = LHCLumi * 1178.29e-12 /TotalNumberOfEvents;
  else if(input == "DY2") XSecWeight = LHCLumi * 387.34e-12 /TotalNumberOfEvents;
  else if(input == "DY3") XSecWeight = LHCLumi * 118.429e-12 /TotalNumberOfEvents;
  else if(input == "DY4") XSecWeight = LHCLumi * 63.73e-12 /TotalNumberOfEvents;
  
  reweight::LumiReWeighting* LumiWeights_12;
  LumiWeights_12 = new reweight::LumiReWeighting(("/data/aloeliger/CMSSW_9_4_0/src/SMHTTAnalysis/SkimmedNtuples/TauID2017/"+input+".root").c_str(),
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

  //for simulating the fake rate applied to potentialy non jet events
  TFile* FakeRateFile = new TFile("../Distributions/FakeRateDistributions.root");
  //start with just the oerall fake rates
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

  //get the pt based decay mode fake rates
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
  
      //match diegos pt > 30 cut as opposed to my original 29.0 cut
      if(pt_1 < 30.0 or std::abs(eta_1) > 2.4 or !id_m_medium_1 or iso_1 > 0.15 or std::abs(dZ_1) > 0.2 or std::abs(d0_1) > 0.045 or !matchIsoMu27_1) continue;
      //tau criteria
      //added the decaymodefinding_2 which catches the old decay mode finding.
      if(pt_2 < 20.0  or std::abs(eta_2) > 2.3 or againstElectronVLooseMVA6_2 != 1 or againstMuonTight3_2 != 1 or !decayModeFinding_2 or std::abs(dZ_2) > 0.2 or std::abs(q_2) > 1) continue;            
      
      /*
      if(input != "Data"
	 and input != "W"
	 and input != "W1"
	 and input != "W2"
	 and input != "W3"
	 and input != "W4")
	{
	  if(gen_match_2 == 6) continue;
	}
      */
      
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
      //Create the weighting
      float PileupWeight = LumiWeights_12->weight(npu);
      
      float muTriggerSF = TriggerWeightings->GetBinContent(TriggerWeightings->FindBin(fabs(l1.Eta()),l1.Pt()));
      float muIDSF;
      if(l1.Pt() < 120.0) muIDSF =  IDWeightings->GetBinContent(IDWeightings->FindBin(l1.Pt(),fabs(l1.Eta())));
      else muIDSF =  IDWeightings->GetBinContent(IDWeightings->FindBin(119.0,fabs(l1.Eta())));
      float muISOSF;
      if(l1.Pt() < 120.0) muISOSF =  ISOWeightings->GetBinContent(ISOWeightings->FindBin(l1.Pt(),fabs(l1.Eta())));
      else muISOSF =  ISOWeightings->GetBinContent(ISOWeightings->FindBin(119.0,fabs(l1.Eta())));

      if(input == "WW")NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(input == "WZ") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(input == "ZZ") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;            
      else if(input == "W"
	      or input == "W1"
	      or input == "W2"
	      or input == "W3"
	      or input == "W4") 
	{
	  NormalizationWeight = PileupWeight*muTriggerSF*muIDSF*muISOSF;	  
	  
	  if(numGenJets==0) NormalizationWeight = NormalizationWeight*34.644;
	  if(numGenJets==1) NormalizationWeight = NormalizationWeight*4.2559;
	  if(numGenJets==2) NormalizationWeight = NormalizationWeight*17.668;
	  if(numGenJets==3) NormalizationWeight = NormalizationWeight*1.9254;
	  if(numGenJets==4) NormalizationWeight = NormalizationWeight*2.7165;
	}
      else if(input == "TTTo2L2Nu") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(input == "TTToHadronic") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(input == "TTToSemiLeptonic") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;      
      else if(input == "DY"
	      or input == "DY1"
	      or input == "DY2"
	      or input == "DY3"
	      or input == "DY4")
	{	  
	  NormalizationWeight = PileupWeight*muTriggerSF*muIDSF*muISOSF;
	  
	  if(numGenJets==0) NormalizationWeight = NormalizationWeight*2.373;
	  if(numGenJets==1) NormalizationWeight = NormalizationWeight*0.804;
	  if(numGenJets==2) NormalizationWeight = NormalizationWeight*0.816;
	  if(numGenJets==3) NormalizationWeight = NormalizationWeight*0.546;
	  if(numGenJets==4) NormalizationWeight = NormalizationWeight*0.478;

	  //ZPT Reweighting
	  float ZPTWeight = getZpt_2017(genM,genpT);
	  NormalizationWeight = NormalizationWeight*ZPTWeight;
	}            
      
      else if(input == "ST_top") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(input == "ST_antitop") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(input == "ST_tW_top") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(input == "ST_tW_antitop") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      NormalizationWeight = NormalizationWeight*amcatNLO_weight;      
      if(input == "Data") NormalizationWeight = 1.0;
      

      //alright now we start examining MC in the same region as the jets
      //changed the mt cut to 50 to match diego, instead of my original 40
      if(q_1 * q_2 < 0.0 and TransverseMass < 200.0 /*and PZeta > -25.0*/)
	{
	  //just handle this category by category as we do the jets.
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
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  VLooseResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) VLoose_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else VLoose_MT_WMinus->Fill(TransverseMass,PTWeighting);

		  //controls
		  VLoose_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VLoose_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VLoose_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VLoose_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VLoose_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VLoose_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VLoose_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VLoose_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VLoose_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0VLooseFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 0 /up/down with exaggerations
		  VLooseDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode0VLooseFakeRate/(1.0-DecayMode0VLooseFakeRate)));
		  VLooseDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  VLooseDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VLooseDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VLooseDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VLooseDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode1PTBarrelFakeRates->GetBinContent(VLooseDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode1PTBarrelFakeRates->GetBinContent(VLooseDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VLooseDecayMode1PTEndcapFakeRates->GetBinContent(VLooseDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VLooseDecayMode1PTEndcapFakeRates->GetBinContent(VLooseDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  VLooseResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) VLoose_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else VLoose_MT_WMinus->Fill(TransverseMass,PTWeighting);
		  
		  //controls
		  VLoose_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VLoose_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VLoose_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VLoose_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VLoose_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VLoose_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VLoose_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VLoose_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VLoose_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1VLooseFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 1 /up/down with exaggerations
		  VLooseDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode1VLooseFakeRate/(1.0-DecayMode1VLooseFakeRate)));
		  VLooseDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  VLooseDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VLooseDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VLooseDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VLooseDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode10PTBarrelFakeRates->GetBinContent(VLooseDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode10PTBarrelFakeRates->GetBinContent(VLooseDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VLooseDecayMode10PTEndcapFakeRates->GetBinContent(VLooseDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VLooseDecayMode10PTEndcapFakeRates->GetBinContent(VLooseDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  VLooseResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) VLoose_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else VLoose_MT_WMinus->Fill(TransverseMass,PTWeighting);
		  
		  //controls
		  VLoose_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VLoose_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VLoose_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VLoose_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VLoose_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VLoose_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VLoose_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VLoose_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VLoose_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10VLooseFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 10 /up/down with exaggerations
		  VLooseDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode10VLooseFakeRate/(1.0-DecayMode10VLooseFakeRate)));
		  VLooseDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  VLooseDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VLooseDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VLooseDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VLooseDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}	      	      	      	      	      
	      	      	      
	    }
	  
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byLooseIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode0PTBarrelFakeRates->GetBinContent(LooseDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode0PTBarrelFakeRates->GetBinContent(LooseDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = LooseDecayMode0PTEndcapFakeRates->GetBinContent(LooseDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = LooseDecayMode0PTEndcapFakeRates->GetBinContent(LooseDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;
		  
		  LooseResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) Loose_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else Loose_MT_WMinus->Fill(TransverseMass,PTWeighting);
		  
		  //controls
		  Loose_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Loose_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Loose_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Loose_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Loose_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Loose_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Loose_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Loose_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Loose_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0LooseFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 0 /up/down with exaggerations
		  LooseDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode0LooseFakeRate/(1.0-DecayMode0LooseFakeRate)));
		  LooseDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  LooseDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  LooseDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  LooseDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  LooseDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode1PTBarrelFakeRates->GetBinContent(LooseDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode1PTBarrelFakeRates->GetBinContent(LooseDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = LooseDecayMode1PTEndcapFakeRates->GetBinContent(LooseDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = LooseDecayMode1PTEndcapFakeRates->GetBinContent(LooseDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  LooseResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) Loose_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else Loose_MT_WMinus->Fill(TransverseMass,PTWeighting);
		  
		  //controls
		  Loose_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Loose_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Loose_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Loose_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Loose_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Loose_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Loose_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Loose_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Loose_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1LooseFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 1 /up/down with exaggerations
		  LooseDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode1LooseFakeRate/(1.0-DecayMode1LooseFakeRate)));
		  LooseDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  LooseDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  LooseDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  LooseDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  LooseDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode10PTBarrelFakeRates->GetBinContent(LooseDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode10PTBarrelFakeRates->GetBinContent(LooseDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = LooseDecayMode10PTEndcapFakeRates->GetBinContent(LooseDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = LooseDecayMode10PTEndcapFakeRates->GetBinContent(LooseDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  LooseResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) Loose_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else Loose_MT_WMinus->Fill(TransverseMass,PTWeighting);

		  //controls
		  Loose_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Loose_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Loose_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Loose_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Loose_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Loose_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Loose_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Loose_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Loose_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10LooseFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 10 /up/down with exaggerations
		  LooseDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode10LooseFakeRate/(1.0-DecayMode10LooseFakeRate)));
		  LooseDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  LooseDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  LooseDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  LooseDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  LooseDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}	      	      	      	      	      
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byMediumIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode0PTBarrelFakeRates->GetBinContent(MediumDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode0PTBarrelFakeRates->GetBinContent(MediumDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = MediumDecayMode0PTEndcapFakeRates->GetBinContent(MediumDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = MediumDecayMode0PTEndcapFakeRates->GetBinContent(MediumDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  MediumResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) Medium_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else Medium_MT_WMinus->Fill(TransverseMass,PTWeighting);
		  
		  //controls
		  Medium_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Medium_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Medium_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Medium_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Medium_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Medium_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Medium_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Medium_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Medium_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0MediumFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 0 /up/down with exaggerations
		  MediumDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode0MediumFakeRate/(1.0-DecayMode0MediumFakeRate)));
		  MediumDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  MediumDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  MediumDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  MediumDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  MediumDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode1PTBarrelFakeRates->GetBinContent(MediumDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode1PTBarrelFakeRates->GetBinContent(MediumDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = MediumDecayMode1PTEndcapFakeRates->GetBinContent(MediumDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = MediumDecayMode1PTEndcapFakeRates->GetBinContent(MediumDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;
		  
		  MediumResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) Medium_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else Medium_MT_WMinus->Fill(TransverseMass,PTWeighting);

		  //controls
		  Medium_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Medium_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Medium_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Medium_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Medium_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Medium_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Medium_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Medium_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Medium_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1MediumFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 1 /up/down with exaggerations
		  MediumDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode1MediumFakeRate/(1.0-DecayMode1MediumFakeRate)));
		  MediumDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  MediumDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  MediumDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  MediumDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  MediumDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode10PTBarrelFakeRates->GetBinContent(MediumDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode10PTBarrelFakeRates->GetBinContent(MediumDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = MediumDecayMode10PTEndcapFakeRates->GetBinContent(MediumDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  MediumResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) Medium_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else Medium_MT_WMinus->Fill(TransverseMass,PTWeighting);

		  //controls
		  Medium_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Medium_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Medium_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Medium_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Medium_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Medium_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Medium_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Medium_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Medium_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10MediumFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 10 /up/down with exaggerations
		  MediumDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode10MediumFakeRate/(1.0-DecayMode10MediumFakeRate)));
		  MediumDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  MediumDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  MediumDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  MediumDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  MediumDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}	      	      	      	      	      
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode0PTBarrelFakeRates->GetBinContent(TightDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode0PTBarrelFakeRates->GetBinContent(TightDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = TightDecayMode0PTEndcapFakeRates->GetBinContent(TightDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = TightDecayMode0PTEndcapFakeRates->GetBinContent(TightDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  TightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) Tight_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else Tight_MT_WMinus->Fill(TransverseMass,PTWeighting);
		  
		  //controls
		  Tight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Tight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Tight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Tight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Tight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Tight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Tight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Tight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Tight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0TightFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 0 /up/down with exaggerations
		  TightDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode0TightFakeRate/(1.0-DecayMode0TightFakeRate)));
		  TightDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  TightDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  TightDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  TightDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  TightDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode1PTBarrelFakeRates->GetBinContent(TightDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode1PTBarrelFakeRates->GetBinContent(TightDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = TightDecayMode1PTEndcapFakeRates->GetBinContent(TightDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = TightDecayMode1PTEndcapFakeRates->GetBinContent(TightDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  TightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) Tight_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else Tight_MT_WMinus->Fill(TransverseMass,PTWeighting);
		  
		  //controls
		  Tight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Tight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Tight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Tight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Tight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Tight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Tight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Tight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Tight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1TightFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 1 /up/down with exaggerations
		  TightDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode1TightFakeRate/(1.0-DecayMode1TightFakeRate)));
		  TightDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  TightDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  TightDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  TightDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  TightDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode10PTBarrelFakeRates->GetBinContent(TightDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode10PTBarrelFakeRates->GetBinContent(TightDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = TightDecayMode10PTEndcapFakeRates->GetBinContent(TightDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = TightDecayMode10PTEndcapFakeRates->GetBinContent(TightDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  TightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) Tight_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else Tight_MT_WMinus->Fill(TransverseMass,PTWeighting);
		  
		  //controls
		  Tight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Tight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Tight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Tight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Tight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Tight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Tight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Tight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Tight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10TightFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 10 /up/down with exaggerations
		  TightDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode10TightFakeRate/(1.0-DecayMode10TightFakeRate)));
		  TightDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  TightDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  TightDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  TightDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  TightDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}	      	      	      	      	      
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode0PTBarrelFakeRates->GetBinContent(VTightDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode0PTBarrelFakeRates->GetBinContent(VTightDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VTightDecayMode0PTEndcapFakeRates->GetBinContent(VTightDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VTightDecayMode0PTEndcapFakeRates->GetBinContent(VTightDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  VTightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) VTight_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else VTight_MT_WMinus->Fill(TransverseMass,PTWeighting);
		  
		  //controls
		  VTight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VTight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VTight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VTight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VTight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VTight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VTight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VTight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VTight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0VTightFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 0 /up/down with exaggerations
		  VTightDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode0VTightFakeRate/(1.0-DecayMode0VTightFakeRate)));
		  VTightDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  VTightDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VTightDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VTightDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VTightDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode1PTBarrelFakeRates->GetBinContent(VTightDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode1PTBarrelFakeRates->GetBinContent(VTightDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VTightDecayMode1PTEndcapFakeRates->GetBinContent(VTightDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VTightDecayMode1PTEndcapFakeRates->GetBinContent(VTightDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  VTightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) VTight_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else VTight_MT_WMinus->Fill(TransverseMass,PTWeighting);
		  
		  //controls
		  VTight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VTight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VTight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VTight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VTight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VTight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VTight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VTight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VTight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1VTightFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 1 /up/down with exaggerations
		  VTightDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode1VTightFakeRate/(1.0-DecayMode1VTightFakeRate)));
		  VTightDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  VTightDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VTightDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VTightDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VTightDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode10PTBarrelFakeRates->GetBinContent(VTightDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode10PTBarrelFakeRates->GetBinContent(VTightDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VTightDecayMode10PTEndcapFakeRates->GetBinContent(VTightDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VTightDecayMode10PTEndcapFakeRates->GetBinContent(VTightDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  VTightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) VTight_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else VTight_MT_WMinus->Fill(TransverseMass,PTWeighting);
		  
		  //controls
		  VTight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VTight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VTight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VTight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VTight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VTight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VTight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VTight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VTight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10VTightFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 10 /up/down with exaggerations
		  VTightDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode10VTightFakeRate/(1.0-DecayMode10VTightFakeRate)));
		  VTightDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  VTightDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VTightDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VTightDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VTightDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}	      	      	      	      	      
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode0PTBarrelFakeRates->GetBinContent(VVTightDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode0PTBarrelFakeRates->GetBinContent(VVTightDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VVTightDecayMode0PTEndcapFakeRates->GetBinContent(VVTightDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VVTightDecayMode0PTEndcapFakeRates->GetBinContent(VVTightDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;
		  
		  VVTightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) VVTight_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else VVTight_MT_WMinus->Fill(TransverseMass,PTWeighting);
		  
		  //controls
		  VVTight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VVTight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VVTight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VVTight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VVTight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VVTight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VVTight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VVTight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VVTight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode0VVTightFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 0 /up/down with exaggerations
		  VVTightDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode0VVTightFakeRate/(1.0-DecayMode0VVTightFakeRate)));
		  VVTightDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  VVTightDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VVTightDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VVTightDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VVTightDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode1PTBarrelFakeRates->GetBinContent(VVTightDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode1PTBarrelFakeRates->GetBinContent(VVTightDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VVTightDecayMode1PTEndcapFakeRates->GetBinContent(VVTightDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VVTightDecayMode1PTEndcapFakeRates->GetBinContent(VVTightDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  VVTightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) VVTight_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else VVTight_MT_WMinus->Fill(TransverseMass,PTWeighting);
		  
		  //controls
		  VVTight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VVTight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VVTight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VVTight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VVTight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VVTight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VVTight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VVTight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VVTight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode1VVTightFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 1 /up/down with exaggerations
		  VVTightDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode1VVTightFakeRate/(1.0-DecayMode1VVTightFakeRate)));
		  VVTightDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  VVTightDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VVTightDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VVTightDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VVTightDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode10PTBarrelFakeRates->GetBinContent(VVTightDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode10PTBarrelFakeRates->GetBinContent(VVTightDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VVTightDecayMode10PTEndcapFakeRates->GetBinContent(VVTightDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VVTightDecayMode10PTEndcapFakeRates->GetBinContent(VVTightDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  VVTightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  //fill sascha's special shapes
		  if(q_1 > 0.0) VVTight_MT_WPlus->Fill(TransverseMass,PTWeighting);
		  else VVTight_MT_WMinus->Fill(TransverseMass,PTWeighting);
		  
		  //controls
		  VVTight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VVTight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VVTight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VVTight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VVTight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VVTight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VVTight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VVTight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VVTight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		  
		  ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, DecayMode10VVTightFakeRate);
		  ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
		  //fill decay mode 10 /up/down with exaggerations
		  VVTightDecayMode10DOWNResultHisto->Fill(Var,NormalizationWeight*(DecayMode10VVTightFakeRate/(1.0-DecayMode10VVTightFakeRate)));
		  VVTightDecayMode10UPResultHisto->Fill(Var,NormalizationWeight*ExacerbatedWeighting);
		  //fill the other decay modes with nominals
		  VVTightDecayMode1DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VVTightDecayMode1UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VVTightDecayMode0DOWNResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  VVTightDecayMode0UPResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		}	      	      	      	      	      
	    }
	}//end of jets region	

	if(q_1 * q_2 > 0.0 /*and TransverseMass < 50.0 and PZeta > -25.0*/)
	{
	  //just handle this category by category as we do the jets.
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
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  //controls
		  VLoose_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VLoose_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VLoose_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VLoose_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VLoose_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VLoose_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VLoose_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VLoose_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VLoose_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode1PTBarrelFakeRates->GetBinContent(VLooseDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode1PTBarrelFakeRates->GetBinContent(VLooseDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VLooseDecayMode1PTEndcapFakeRates->GetBinContent(VLooseDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VLooseDecayMode1PTEndcapFakeRates->GetBinContent(VLooseDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  //controls
		  VLoose_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VLoose_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VLoose_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VLoose_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VLoose_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VLoose_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VLoose_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VLoose_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VLoose_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode10PTBarrelFakeRates->GetBinContent(VLooseDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VLooseDecayMode10PTBarrelFakeRates->GetBinContent(VLooseDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VLooseDecayMode10PTEndcapFakeRates->GetBinContent(VLooseDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VLooseDecayMode10PTEndcapFakeRates->GetBinContent(VLooseDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  //controls
		  VLoose_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VLoose_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VLoose_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VLoose_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VLoose_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VLoose_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VLoose_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VLoose_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VLoose_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}	      	      	      	      	      
	      	      	      
	    }
	  
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byLooseIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode0PTBarrelFakeRates->GetBinContent(LooseDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode0PTBarrelFakeRates->GetBinContent(LooseDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = LooseDecayMode0PTEndcapFakeRates->GetBinContent(LooseDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = LooseDecayMode0PTEndcapFakeRates->GetBinContent(LooseDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;
		  
		  //controls
		  Loose_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Loose_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Loose_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Loose_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Loose_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Loose_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Loose_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Loose_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Loose_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode1PTBarrelFakeRates->GetBinContent(LooseDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode1PTBarrelFakeRates->GetBinContent(LooseDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = LooseDecayMode1PTEndcapFakeRates->GetBinContent(LooseDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = LooseDecayMode1PTEndcapFakeRates->GetBinContent(LooseDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  //controls
		  Loose_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Loose_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Loose_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Loose_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Loose_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Loose_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Loose_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Loose_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Loose_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode10PTBarrelFakeRates->GetBinContent(LooseDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = LooseDecayMode10PTBarrelFakeRates->GetBinContent(LooseDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = LooseDecayMode10PTEndcapFakeRates->GetBinContent(LooseDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = LooseDecayMode10PTEndcapFakeRates->GetBinContent(LooseDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  //controls
		  Loose_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Loose_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Loose_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Loose_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Loose_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Loose_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Loose_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Loose_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Loose_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}	      	      	      	      	      
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byMediumIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode0PTBarrelFakeRates->GetBinContent(MediumDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode0PTBarrelFakeRates->GetBinContent(MediumDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = MediumDecayMode0PTEndcapFakeRates->GetBinContent(MediumDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = MediumDecayMode0PTEndcapFakeRates->GetBinContent(MediumDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  //controls
		  Medium_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Medium_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Medium_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Medium_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Medium_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Medium_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Medium_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Medium_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Medium_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode1PTBarrelFakeRates->GetBinContent(MediumDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode1PTBarrelFakeRates->GetBinContent(MediumDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = MediumDecayMode1PTEndcapFakeRates->GetBinContent(MediumDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = MediumDecayMode1PTEndcapFakeRates->GetBinContent(MediumDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;
		  
		  //controls
		  Medium_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Medium_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Medium_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Medium_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Medium_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Medium_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Medium_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Medium_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Medium_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode10PTBarrelFakeRates->GetBinContent(MediumDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = MediumDecayMode10PTBarrelFakeRates->GetBinContent(MediumDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = MediumDecayMode10PTEndcapFakeRates->GetBinContent(MediumDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  //controls
		  Medium_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Medium_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Medium_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Medium_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Medium_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Medium_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Medium_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Medium_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Medium_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}	      	      	      	      	      
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode0PTBarrelFakeRates->GetBinContent(TightDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode0PTBarrelFakeRates->GetBinContent(TightDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = TightDecayMode0PTEndcapFakeRates->GetBinContent(TightDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = TightDecayMode0PTEndcapFakeRates->GetBinContent(TightDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  //controls
		  Tight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Tight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Tight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Tight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Tight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Tight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Tight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Tight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Tight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode1PTBarrelFakeRates->GetBinContent(TightDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode1PTBarrelFakeRates->GetBinContent(TightDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = TightDecayMode1PTEndcapFakeRates->GetBinContent(TightDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = TightDecayMode1PTEndcapFakeRates->GetBinContent(TightDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  //controls
		  Tight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Tight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Tight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Tight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Tight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Tight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Tight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Tight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Tight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode10PTBarrelFakeRates->GetBinContent(TightDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = TightDecayMode10PTBarrelFakeRates->GetBinContent(TightDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = TightDecayMode10PTEndcapFakeRates->GetBinContent(TightDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = TightDecayMode10PTEndcapFakeRates->GetBinContent(TightDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  //controls
		  Tight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  Tight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  Tight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  Tight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  Tight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  Tight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  Tight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  Tight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  Tight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}	      	      	      	      	      
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode0PTBarrelFakeRates->GetBinContent(VTightDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode0PTBarrelFakeRates->GetBinContent(VTightDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VTightDecayMode0PTEndcapFakeRates->GetBinContent(VTightDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VTightDecayMode0PTEndcapFakeRates->GetBinContent(VTightDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  //controls
		  VTight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VTight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VTight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VTight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VTight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VTight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VTight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VTight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VTight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode1PTBarrelFakeRates->GetBinContent(VTightDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode1PTBarrelFakeRates->GetBinContent(VTightDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VTightDecayMode1PTEndcapFakeRates->GetBinContent(VTightDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VTightDecayMode1PTEndcapFakeRates->GetBinContent(VTightDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;
		  
		  //controls
		  VTight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VTight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VTight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VTight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VTight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VTight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VTight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VTight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VTight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode10PTBarrelFakeRates->GetBinContent(VTightDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VTightDecayMode10PTBarrelFakeRates->GetBinContent(VTightDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VTightDecayMode10PTEndcapFakeRates->GetBinContent(VTightDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VTightDecayMode10PTEndcapFakeRates->GetBinContent(VTightDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  //controls
		  VTight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VTight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VTight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VTight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VTight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VTight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VTight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VTight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VTight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}	      	      	      	      	      
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	
	      if(l2_decayMode == 0)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode0PTBarrelFakeRates->GetBinContent(VVTightDecayMode0PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode0PTBarrelFakeRates->GetBinContent(VVTightDecayMode0PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VVTightDecayMode0PTEndcapFakeRates->GetBinContent(VVTightDecayMode0PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VVTightDecayMode0PTEndcapFakeRates->GetBinContent(VVTightDecayMode0PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  //controls
		  VVTight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VVTight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VVTight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VVTight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VVTight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VVTight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VVTight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VVTight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VVTight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 1)
		{
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode1PTBarrelFakeRates->GetBinContent(VVTightDecayMode1PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode1PTBarrelFakeRates->GetBinContent(VVTightDecayMode1PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VVTightDecayMode1PTEndcapFakeRates->GetBinContent(VVTightDecayMode1PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VVTightDecayMode1PTEndcapFakeRates->GetBinContent(VVTightDecayMode1PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;
		  
		  //controls
		  VVTight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VVTight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VVTight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VVTight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VVTight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VVTight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VVTight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VVTight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VVTight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}
	      else if(l2_decayMode == 10)
		{		  
		  if(l2.Pt() < 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode10PTBarrelFakeRates->GetBinContent(VVTightDecayMode10PTBarrelFakeRates->FindBin(l2.Pt()));		  
		  else if(l2.Pt() > 200 && std::abs(eta_2) < 1.479) PTFakeRate = VVTightDecayMode10PTBarrelFakeRates->GetBinContent(VVTightDecayMode10PTBarrelFakeRates->FindBin(199.0));
		  else if(l2.Pt() < 200 && std::abs(eta_2) > 1.479) PTFakeRate = VVTightDecayMode10PTEndcapFakeRates->GetBinContent(VVTightDecayMode10PTEndcapFakeRates->FindBin(l2.Pt()));		  
		  else  PTFakeRate = VVTightDecayMode10PTEndcapFakeRates->GetBinContent(VVTightDecayMode10PTEndcapFakeRates->FindBin(199.0));
		  //PTWeighting = PTFakeRate/(1.0-PTFakeRate);
		  PTWeighting = 1.0;

		  //controls
		  VVTight_MuPt->Fill(l1.Pt(),NormalizationWeight*PTWeighting);
		  VVTight_TauPt->Fill(l2.Pt(),NormalizationWeight*PTWeighting);
		  VVTight_MuEta->Fill(l1.Eta(),NormalizationWeight*PTWeighting);
		  VVTight_TauEta->Fill(l2.Eta(),NormalizationWeight*PTWeighting);
		  VVTight_NJets->Fill(njets,NormalizationWeight*PTWeighting);
		  VVTight_NBtag->Fill(nbtag,NormalizationWeight*PTWeighting);
		  VVTight_ZMass->Fill((l1+l2).M(),NormalizationWeight*PTWeighting);
		  VVTight_ZPT->Fill((l1+l2).Pt(),NormalizationWeight*PTWeighting);
		  VVTight_MT->Fill(TransverseMass,NormalizationWeight*PTWeighting);
		}	      	      	      	      	      
	    }
	}//end of same sign region
    }// end of for loop.
  TFile* OutFile = new TFile(("../TemporaryFiles/"+input+"_InJetsRegion.root").c_str(),"RECREATE");
  VLooseResultHisto->Write();
  LooseResultHisto->Write();
  MediumResultHisto->Write();
  TightResultHisto->Write();
  VTightResultHisto->Write();
  VVTightResultHisto->Write();  

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

  //Write some controls
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
  
  //SS control plots  
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

  VLooseDecayMode0UPResultHisto->Write();
  LooseDecayMode0UPResultHisto->Write();
  MediumDecayMode0UPResultHisto->Write();
  TightDecayMode0UPResultHisto->Write();
  VTightDecayMode0UPResultHisto->Write();
  VVTightDecayMode0UPResultHisto->Write();  

  VLooseDecayMode1UPResultHisto->Write();
  LooseDecayMode1UPResultHisto->Write();
  MediumDecayMode1UPResultHisto->Write();
  TightDecayMode1UPResultHisto->Write();
  VTightDecayMode1UPResultHisto->Write();
  VVTightDecayMode1UPResultHisto->Write();  

  VLooseDecayMode10UPResultHisto->Write();
  LooseDecayMode10UPResultHisto->Write();
  MediumDecayMode10UPResultHisto->Write();
  TightDecayMode10UPResultHisto->Write();
  VTightDecayMode10UPResultHisto->Write();
  VVTightDecayMode10UPResultHisto->Write();  
  
  VLooseDecayMode0DOWNResultHisto->Write();
  LooseDecayMode0DOWNResultHisto->Write();
  MediumDecayMode0DOWNResultHisto->Write();
  TightDecayMode0DOWNResultHisto->Write();
  VTightDecayMode0DOWNResultHisto->Write();
  VVTightDecayMode0DOWNResultHisto->Write();  

  VLooseDecayMode1DOWNResultHisto->Write();
  LooseDecayMode1DOWNResultHisto->Write();
  MediumDecayMode1DOWNResultHisto->Write();
  TightDecayMode1DOWNResultHisto->Write();
  VTightDecayMode1DOWNResultHisto->Write();
  VVTightDecayMode1DOWNResultHisto->Write();  

  VLooseDecayMode10DOWNResultHisto->Write();
  LooseDecayMode10DOWNResultHisto->Write();
  MediumDecayMode10DOWNResultHisto->Write();
  TightDecayMode10DOWNResultHisto->Write();
  VTightDecayMode10DOWNResultHisto->Write();
  VVTightDecayMode10DOWNResultHisto->Write();  

  OutFile->Close();
}
