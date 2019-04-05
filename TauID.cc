//Selection code for the Tau ID Efficiency measurements.
//Seperates the events into 4 different categories
// and then each of those categroies into pass/fail
// 1.) The Signal region
// 2.) High transverse mass region (W+Jets region)
// 3.) same sign region (for estimating QCD in the signal region
// 4.) same sign high transverse mass region (for estimating QCD in W+Jets region)
#include "TROOT.h"
//#include "/afs/cern.ch/user/a/aloelige//private/CMSSW_9_4_0/src/PhysicsTools/Utilities/interface/LumiReweightingStandAlone.h"
#include "/data/aloeliger/CMSSW_9_4_0/src/PhysicsTools/Utilities/interface/LumiReweightingStandAlone.h"
#include <cmath>
#include <string>
#include "Zpt/zptweight.C"

void TauID(std::string input, string IsoWorkingPoint,float ShapeUncertainty = 1.0, int PtBracket = 0, int EtaBracket = 0)
{
  //get the tree that we're going to run
  TFile *MyFile = new TFile(("/data/aloeliger/CMSSW_9_4_0/src/SMHTTAnalysis/SkimmedNtuples/TauID2017/"+input+".root").c_str());
  TTree *Tree = (TTree*) MyFile->Get("mutau_tree");
  TH1F* nevents = (TH1F*) MyFile->Get("summedWeights");
  float TotalNumberOfEvents = nevents->GetBinContent(1);

  readZptFile();
  
  //Variables for the tree branches
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
  //22/2/19 EDIT: Commented out branches not present in new samples
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
  
  TFile* SyncFile = new TFile("Distributions/SyncNtuple.root","RECREATE");
  TTree* SyncTree = new TTree("SyncTree","SyncTree");
  SyncTree->Branch("run",&run);
  SyncTree->Branch("lumi",&lumi);
  SyncTree->Branch("evt",&evt);
  SyncTree->Branch("pt_1",&pt_1);
  SyncTree->Branch("eta_1",&eta_1);
  SyncTree->Branch("phi_1",&phi_1);
  SyncTree->Branch("pt_2",&pt_2);
  SyncTree->Branch("phi_2",&phi_2);
  SyncTree->Branch("eta_2",&eta_2);
  SyncTree->Branch("TransverseMass", &TransverseMass);
  SyncTree->Branch("PZetaVis", &PZetaVis);
  SyncTree->Branch("PZetaAll", &PZetaAll);  
  SyncTree->Branch("PZeta", &PZeta);
  SyncTree->Branch("met", &met);
  SyncTree->Branch("metphi", &metphi);
  

  int NumberOfEntries = (int) Tree->GetEntries();

  //generate the relevant name
  std::string name;
  if(ShapeUncertainty != 1.0) name = (input+"_"+std::to_string(ShapeUncertainty));
  else name = input;

  //Relevant Histos
  TH1F* SignalRegion_Pass = new TH1F((name+"_Pass").c_str(),
				     "Signal_Pass",
				     20,
				     50.0,
				     150.0);
  TH1F* SignalRegion_Fail = new TH1F((name+"_Fail").c_str(),
				     "Signal_Fail",
				     20,
				     50.0,
				     150.0);

  TH1F* WJetsRegion_Pass = new TH1F(("WJets_"+name+"_Pass").c_str(), 
				    "WJets_Pass", 
				    SignalRegion_Pass->GetSize()-2, 
				    SignalRegion_Pass->GetXaxis()->GetXmin(),
				    SignalRegion_Pass->GetXaxis()->GetXmax());
  TH1F* WJetsRegion_Fail = new TH1F(("WJets_"+name+"_Fail").c_str(), 
				    "WJets_Fail", 
				    SignalRegion_Fail->GetSize()-2, 
				    SignalRegion_Fail->GetXaxis()->GetXmin(),
				    SignalRegion_Fail->GetXaxis()->GetXmax());
  
  TH1F* QCDRegion_Pass = new TH1F(("QCD_"+name+"_Pass").c_str(), 
				  "QCD_Pass", 
				  SignalRegion_Pass->GetSize()-2, 
				  SignalRegion_Pass->GetXaxis()->GetXmin(),
				  SignalRegion_Pass->GetXaxis()->GetXmax());
  
  TH1F* QCDRegion_Fail = new TH1F(("QCD_"+name+"_Fail").c_str(), 
				  "QCD_Fail", 
				  SignalRegion_Fail->GetSize()-2, 
				  SignalRegion_Fail->GetXaxis()->GetXmin(),
				  SignalRegion_Fail->GetXaxis()->GetXmax());
  
  TH1F* QCDinWJets_Pass = new TH1F(("WJets_QCD_"+name+"_Pass").c_str(), 
				   "WJets_QCD_Pass", 
				   SignalRegion_Pass->GetSize()-2, 
				   SignalRegion_Pass->GetXaxis()->GetXmin(),
				   SignalRegion_Pass->GetXaxis()->GetXmax());

  TH1F* QCDinWJets_Fail = new TH1F(("WJets_QCD_"+name+"_Fail").c_str(), 
				   "WJets_QCD_Fail", 
				   SignalRegion_Fail->GetSize()-2, 
				   SignalRegion_Fail->GetXaxis()->GetXmin(),
				   SignalRegion_Fail->GetXaxis()->GetXmax());

  //we'll use this for determining our Z->tautau signal
  //For genmatch == 5
  TH1F* GenMatch_SignalRegion_Pass = new TH1F(("GenMatch_"+name+"_Pass").c_str(),
					      "Signal_Pass",
					      SignalRegion_Pass->GetSize()-2, 
					      SignalRegion_Pass->GetXaxis()->GetXmin(),
					      SignalRegion_Pass->GetXaxis()->GetXmax());
  TH1F* GenMatch_SignalRegion_Fail = new TH1F(("GenMatch_"+name+"_Fail").c_str(),
					      "Signal_Fail",
					      SignalRegion_Fail->GetSize()-2, 
					      SignalRegion_Fail->GetXaxis()->GetXmin(),
					      SignalRegion_Fail->GetXaxis()->GetXmax());

  TH1F* GenMatch_SignalRegion_DM0Mod_Pass = new TH1F(("GenMatch_"+name+"_DM0Mod_Pass").c_str(),
						     ("GenMatch_"+name+"_DM0Mod_Pass").c_str(),
						     SignalRegion_Pass->GetSize()-2,
						     SignalRegion_Pass->GetXaxis()->GetXmin(),
						     SignalRegion_Pass->GetXaxis()->GetXmax());
  TH1F* GenMatch_SignalRegion_DM1Mod_Pass = new TH1F(("GenMatch_"+name+"_DM1Mod_Pass").c_str(),
						     ("GenMatch_"+name+"_DM1Mod_Pass").c_str(),
						     SignalRegion_Pass->GetSize()-2,
						     SignalRegion_Pass->GetXaxis()->GetXmin(),
						     SignalRegion_Pass->GetXaxis()->GetXmax());
  TH1F* GenMatch_SignalRegion_DM10Mod_Pass = new TH1F(("GenMatch_"+name+"_DM10Mod_Pass").c_str(),
						      ("GenMatch_"+name+"_DM10Mod_Pass").c_str(),
						      SignalRegion_Pass->GetSize()-2,
						      SignalRegion_Pass->GetXaxis()->GetXmin(),
						      SignalRegion_Pass->GetXaxis()->GetXmax());

  TH1F* GenMatch_WJetsRegion_Pass = new TH1F(("WJets_GenMatch_"+name+"_Pass").c_str(), 
					     "WJets_Pass", 
					     SignalRegion_Pass->GetSize()-2, 
					     SignalRegion_Pass->GetXaxis()->GetXmin(),
					     SignalRegion_Pass->GetXaxis()->GetXmax());
  TH1F* GenMatch_WJetsRegion_Fail = new TH1F(("WJets_GenMatch_"+name+"_Fail").c_str(), 
					     "WJets_Fail", 
					     SignalRegion_Fail->GetSize()-2, 
					     SignalRegion_Fail->GetXaxis()->GetXmin(),
					     SignalRegion_Fail->GetXaxis()->GetXmax());
  
  TH1F* GenMatch_QCDRegion_Pass = new TH1F(("QCD_GenMatch_"+name+"_Pass").c_str(), 
					   "QCD_Pass", 
					   SignalRegion_Pass->GetSize()-2, 
					   SignalRegion_Pass->GetXaxis()->GetXmin(),
					   SignalRegion_Pass->GetXaxis()->GetXmax());
  
  TH1F* GenMatch_QCDRegion_Fail = new TH1F(("QCD_GenMatch_"+name+"_Fail").c_str(), 
					   "QCD_Fail", 
					   SignalRegion_Fail->GetSize()-2, 
					   SignalRegion_Fail->GetXaxis()->GetXmin(),
					   SignalRegion_Fail->GetXaxis()->GetXmax());
  
  TH1F* GenMatch_QCDinWJets_Pass = new TH1F(("WJets_QCD_GenMatch_"+name+"_Pass").c_str(), 
					    "WJets_QCD_Pass", 
					    SignalRegion_Pass->GetSize()-2, 
					    SignalRegion_Pass->GetXaxis()->GetXmin(),
					    SignalRegion_Pass->GetXaxis()->GetXmax());

  TH1F* GenMatch_QCDinWJets_Fail = new TH1F(("WJets_QCD_GenMatch_"+name+"_Fail").c_str(), 
					    "WJets_QCD_Fail", 
					    SignalRegion_Fail->GetSize()-2, 
					    SignalRegion_Fail->GetXaxis()->GetXmin(),
					    SignalRegion_Fail->GetXaxis()->GetXmax());
  //for genmatch < 5
  TH1F* LowGenMatch_SignalRegion_Pass = new TH1F(("LowGenMatch_"+name+"_Pass").c_str(),
						 "Signal_Pass",
						 SignalRegion_Pass->GetSize()-2, 
						 SignalRegion_Pass->GetXaxis()->GetXmin(),
						 SignalRegion_Pass->GetXaxis()->GetXmax());
  TH1F* LowGenMatch_SignalRegion_Fail = new TH1F(("LowGenMatch_"+name+"_Fail").c_str(),
						 "Signal_Fail",
						 SignalRegion_Fail->GetSize()-2, 
						 SignalRegion_Fail->GetXaxis()->GetXmin(),
						 SignalRegion_Fail->GetXaxis()->GetXmax());

  TH1F* LowGenMatch_WJetsRegion_Pass = new TH1F(("WJets_LowGenMatch_"+name+"_Pass").c_str(), 
						"WJets_Pass", 
						SignalRegion_Pass->GetSize()-2, 
						SignalRegion_Pass->GetXaxis()->GetXmin(),
						SignalRegion_Pass->GetXaxis()->GetXmax());
  TH1F* LowGenMatch_WJetsRegion_Fail = new TH1F(("WJets_LowGenMatch_"+name+"_Fail").c_str(), 
						"WJets_Fail", 
						SignalRegion_Fail->GetSize()-2, 
						SignalRegion_Fail->GetXaxis()->GetXmin(),
						SignalRegion_Fail->GetXaxis()->GetXmax());
  
  TH1F* LowGenMatch_QCDRegion_Pass = new TH1F(("QCD_LowGenMatch_"+name+"_Pass").c_str(), 
					      "QCD_Pass", 
					      SignalRegion_Pass->GetSize()-2, 
					      SignalRegion_Pass->GetXaxis()->GetXmin(),
					      SignalRegion_Pass->GetXaxis()->GetXmax());
  
  TH1F* LowGenMatch_QCDRegion_Fail = new TH1F(("QCD_LowGenMatch_"+name+"_Fail").c_str(), 
					      "QCD_Fail", 
					      SignalRegion_Fail->GetSize()-2, 
					      SignalRegion_Fail->GetXaxis()->GetXmin(),
					      SignalRegion_Fail->GetXaxis()->GetXmax());
  
  TH1F* LowGenMatch_QCDinWJets_Pass = new TH1F(("WJets_QCD_LowGenMatch_"+name+"_Pass").c_str(), 
					       "WJets_QCD_Pass", 
					       SignalRegion_Pass->GetSize()-2, 
					       SignalRegion_Pass->GetXaxis()->GetXmin(),
					       SignalRegion_Pass->GetXaxis()->GetXmax());

  TH1F* LowGenMatch_QCDinWJets_Fail = new TH1F(("WJets_QCD_LowGenMatch_"+name+"_Fail").c_str(), 
					       "WJets_QCD_Fail", 
					       SignalRegion_Fail->GetSize()-2, 
					       SignalRegion_Fail->GetXaxis()->GetXmin(),
					       SignalRegion_Fail->GetXaxis()->GetXmax());
  //For genmatch == 6
  TH1F* HighGenMatch_SignalRegion_Pass = new TH1F(("HighGenMatch_"+name+"_Pass").c_str(),
						  "Signal_Pass",
						  SignalRegion_Pass->GetSize()-2, 
						  SignalRegion_Pass->GetXaxis()->GetXmin(),
						  SignalRegion_Pass->GetXaxis()->GetXmax());
  TH1F* HighGenMatch_SignalRegion_Fail = new TH1F(("HighGenMatch_"+name+"_Fail").c_str(),
						  "Signal_Fail",
						  SignalRegion_Fail->GetSize()-2, 
						  SignalRegion_Fail->GetXaxis()->GetXmin(),
						  SignalRegion_Fail->GetXaxis()->GetXmax());

  TH1F* HighGenMatch_WJetsRegion_Pass = new TH1F(("WJets_HighGenMatch_"+name+"_Pass").c_str(), 
						 "WJets_Pass", 
						 SignalRegion_Pass->GetSize()-2, 
						 SignalRegion_Pass->GetXaxis()->GetXmin(),
						 SignalRegion_Pass->GetXaxis()->GetXmax());
  TH1F* HighGenMatch_WJetsRegion_Fail = new TH1F(("WJets_HighGenMatch_"+name+"_Fail").c_str(), 
						 "WJets_Fail", 
						 SignalRegion_Fail->GetSize()-2, 
						 SignalRegion_Fail->GetXaxis()->GetXmin(),
						 SignalRegion_Fail->GetXaxis()->GetXmax());
  
  TH1F* HighGenMatch_QCDRegion_Pass = new TH1F(("QCD_HighGenMatch_"+name+"_Pass").c_str(), 
					       "QCD_Pass", 
					       SignalRegion_Pass->GetSize()-2, 
					       SignalRegion_Pass->GetXaxis()->GetXmin(),
					       SignalRegion_Pass->GetXaxis()->GetXmax());
  
  TH1F* HighGenMatch_QCDRegion_Fail = new TH1F(("QCD_HighGenMatch_"+name+"_Fail").c_str(), 
					       "QCD_Fail", 
					       SignalRegion_Fail->GetSize()-2, 
					       SignalRegion_Fail->GetXaxis()->GetXmin(),
					       SignalRegion_Fail->GetXaxis()->GetXmax());
  
  TH1F* HighGenMatch_QCDinWJets_Pass = new TH1F(("WJets_QCD_HighGenMatch_"+name+"_Pass").c_str(), 
						"WJets_QCD_Pass", 
						SignalRegion_Pass->GetSize()-2, 
						SignalRegion_Pass->GetXaxis()->GetXmin(),
						SignalRegion_Pass->GetXaxis()->GetXmax());

  TH1F* HighGenMatch_QCDinWJets_Fail = new TH1F(("WJets_QCD_HighGenMatch_"+name+"_Fail").c_str(), 
						"WJets_QCD_Fail", 
						SignalRegion_Fail->GetSize()-2, 
						SignalRegion_Fail->GetXaxis()->GetXmin(),
						SignalRegion_Fail->GetXaxis()->GetXmax());

  //Control plots
  TH1F* SignalRegion_MuPt = new TH1F((name+"_MuPt").c_str(),
				     (name+"_MuPt").c_str(),
				     100,
				     0.0,
				     200.0);
  
  TH1F* SignalRegion_TauPt = new TH1F((name+"_TauPt").c_str(),
				      (name+"_TauPt").c_str(),
				      100,
				      0.0,
				      200.0);
  
  TH1F* SignalRegion_MuEta = new TH1F((name+"_MuEta").c_str(),
				      (name+"_MuEta").c_str(),
				      100,
				      -4.0,
				      4.0);
  
  TH1F* SignalRegion_TauEta = new TH1F((name+"_TauEta").c_str(),
				       (name+"_TauEta").c_str(),
				       100,
				       -4.0,
				       4.0);

  TH1F* SignalRegion_NJets = new TH1F((name+"_njets").c_str(),
				      (name+"_njets").c_str(),
				      5,
				      0.0,
				      5.0);

  TH1F* SignalRegion_NBtag = new TH1F((name+"_nbtag").c_str(),
				      (name+"_nbtag").c_str(),
				      5,
				      0.0,
				      5.0);

  TH1F* SignalRegion_ZMass = new TH1F((name+"_ZMass").c_str(),
				      (name+"_ZMass").c_str(),
				      100,
				      0.0,
				      200.0);

  TH1F* SignalRegion_ZPT = new TH1F((name+"_ZPT").c_str(),
				    (name+"_ZPT").c_str(),
				    100,
				    0.0,
				    500.0);
  TH1F* SignalRegion_MT = new TH1F((name+"_MT").c_str(),
				   (name+"_MT").c_str(),
				   100,
				   0.0,
				   200.0);
  
  //do the genmatched version of these
  TH1F* GenMatch_SignalRegion_MuPt = new TH1F(("GenMatch_"+name+"_MuPt").c_str(),
					      ("GenMatch_"+name+"_MuPt").c_str(),
					      100,
					      0.0,
					      200.0);
  
  TH1F* GenMatch_SignalRegion_TauPt = new TH1F(("GenMatch_"+name+"_TauPt").c_str(),
					       ("GenMatch_"+name+"_TauPt").c_str(),
					       100,
					       0.0,
					       200.0);
  
  TH1F* GenMatch_SignalRegion_MuEta = new TH1F(("GenMatch_"+name+"_MuEta").c_str(),
					       ("GenMatch_"+name+"_MuEta").c_str(),
					       100,
					       -4.0,
					       4.0);
  
  TH1F* GenMatch_SignalRegion_TauEta = new TH1F(("GenMatch_"+name+"_TauEta").c_str(),
						("GenMatch_"+name+"_TauEta").c_str(),
						100,
						-4.0,
						4.0);
  
  TH1F* GenMatch_SignalRegion_NJets = new TH1F(("GenMatch_"+name+"_njets").c_str(),
					       ("GenMatch_"+name+"_njets").c_str(),
					       5,
					       0.0,
					       5.0);
  
  TH1F* GenMatch_SignalRegion_NBtag = new TH1F(("GenMatch_"+name+"_nbtag").c_str(),
					       ("GenMatch_"+name+"_nbtag").c_str(),
					       5,
					       0.0,
					       5.0);

  TH1F* GenMatch_SignalRegion_ZMass = new TH1F(("GenMatch_"+name+"_ZMass").c_str(),
					       ("GenMatch_"+name+"_ZMass").c_str(),
					       100,
					       0.0,
					       200.0);

  TH1F* GenMatch_SignalRegion_ZPT = new TH1F(("GenMatch_"+name+"_ZPT").c_str(),
					     ("GenMatch_"+name+"_ZPT").c_str(),
					     100,
					     0.0,
					     500.0);
  TH1F* GenMatch_SignalRegion_MT = new TH1F(("GenMatch_"+name+"_MT").c_str(),
					    ("GenMatch_"+name+"_MT").c_str(),
					    100,
					    0.0,
					    200.0);  

  TH1F* LowGenMatch_SignalRegion_MuPt = new TH1F(("LowGenMatch_"+name+"_MuPt").c_str(),
						 ("LowGenMatch_"+name+"_MuPt").c_str(),
						 100,
						 0.0,
						 200.0);
  
  TH1F* LowGenMatch_SignalRegion_TauPt = new TH1F(("LowGenMatch_"+name+"_TauPt").c_str(),
						  ("LowGenMatch_"+name+"_TauPt").c_str(),
						  100,
						  0.0,
						  200.0);
  
  TH1F* LowGenMatch_SignalRegion_MuEta = new TH1F(("LowGenMatch_"+name+"_MuEta").c_str(),
						  ("LowGenMatch_"+name+"_MuEta").c_str(),
						  100,
						  -4.0,
						  4.0);
  
  TH1F* LowGenMatch_SignalRegion_TauEta = new TH1F(("LowGenMatch_"+name+"_TauEta").c_str(),
						   ("LowGenMatch_"+name+"_TauEta").c_str(),
						   100,
						   -4.0,
						   4.0);
  
  TH1F* LowGenMatch_SignalRegion_NJets = new TH1F(("LowGenMatch_"+name+"_njets").c_str(),
						  ("LowGenMatch_"+name+"_njets").c_str(),
						  5,
						  0.0,
						  5.0);
  
  TH1F* LowGenMatch_SignalRegion_NBtag = new TH1F(("LowGenMatch_"+name+"_nbtag").c_str(),
						  ("LowGenMatch_"+name+"_nbtag").c_str(),
						  5,
						  0.0,
						  5.0);
  
  TH1F* LowGenMatch_SignalRegion_ZMass = new TH1F(("LowGenMatch_"+name+"_ZMass").c_str(),
						  ("LowGenMatch_"+name+"_ZMass").c_str(),
						  100,
						  0.0,
						  200.0);
  
  TH1F* LowGenMatch_SignalRegion_ZPT = new TH1F(("LowGenMatch_"+name+"_ZPT").c_str(),
						("LowGenMatch_"+name+"_ZPT").c_str(),
						100,
						0.0,
						500.0);
  TH1F* LowGenMatch_SignalRegion_MT = new TH1F(("LowGenMatch_"+name+"_MT").c_str(),
					       ("LowGenMatch_"+name+"_MT").c_str(),
					       100,
					       0.0,
					       200.0);

  TH1F* HighGenMatch_SignalRegion_MuPt = new TH1F(("HighGenMatch_"+name+"_MuPt").c_str(),
						  ("HighGenMatch_"+name+"_MuPt").c_str(),
						  100,
						  0.0,
						  200.0);
  
  TH1F* HighGenMatch_SignalRegion_TauPt = new TH1F(("HighGenMatch_"+name+"_TauPt").c_str(),
						   ("HighGenMatch_"+name+"_TauPt").c_str(),
						   100,
						   0.0,
						   200.0);
  
  TH1F* HighGenMatch_SignalRegion_MuEta = new TH1F(("HighGenMatch_"+name+"_MuEta").c_str(),
						   ("HighGenMatch_"+name+"_MuEta").c_str(),
						   100,
						   -4.0,
						   4.0);
  
  TH1F* HighGenMatch_SignalRegion_TauEta = new TH1F(("HighGenMatch_"+name+"_TauEta").c_str(),
						    ("HighGenMatch_"+name+"_TauEta").c_str(),
						    100,
						    -4.0,
						    4.0);
  
  TH1F* HighGenMatch_SignalRegion_NJets = new TH1F(("HighGenMatch_"+name+"_njets").c_str(),
						   ("HighGenMatch_"+name+"_njets").c_str(),
						   5,
						   0.0,
						   5.0);
  
  TH1F* HighGenMatch_SignalRegion_NBtag = new TH1F(("HighGenMatch_"+name+"_nbtag").c_str(),
						   ("HighGenMatch_"+name+"_nbtag").c_str(),
						   5,
						   0.0,
						   5.0);
  
  TH1F* HighGenMatch_SignalRegion_ZMass = new TH1F(("HighGenMatch_"+name+"_ZMass").c_str(),
						   ("HighGenMatch_"+name+"_ZMass").c_str(),
						   100,
						   0.0,
						   200.0);
  
  TH1F* HighGenMatch_SignalRegion_ZPT = new TH1F(("HighGenMatch_"+name+"_ZPT").c_str(),
						 ("HighGenMatch_"+name+"_ZPT").c_str(),
						 100,
						 0.0,
						 500.0);
  TH1F* HighGenMatch_SignalRegion_MT = new TH1F(("HighGenMatch_"+name+"_MT").c_str(),
						("HighGenMatch_"+name+"_MT").c_str(),
						100,
						0.0,
						200.0);
  //WJets Region Control Plots
  TH1F* WJetsRegion_MuPt = new TH1F(("WJets_"+name+"_MuPt").c_str(),
				    ("WJets_"+name+"_MuPt").c_str(),
				    100,
				    0.0,
				    200.0);
  
  TH1F* WJetsRegion_TauPt = new TH1F(("WJets_"+name+"_TauPt").c_str(),
				     ("WJets_"+name+"_TauPt").c_str(),
				     100,
				     0.0,
				     200.0);
  
  TH1F* WJetsRegion_MuEta = new TH1F(("WJets_"+name+"_MuEta").c_str(),
				     ("WJets_"+name+"_MuEta").c_str(),
				     100,
				     -4.0,
				     4.0);
  
  TH1F* WJetsRegion_TauEta = new TH1F(("WJets_"+name+"_TauEta").c_str(),
				      (name+"_TauEta").c_str(),
				      100,
				      -4.0,
				      4.0);

  TH1F* WJetsRegion_NJets = new TH1F(("WJets_"+name+"_njets").c_str(),
				     ("WJets_"+name+"_njets").c_str(),
				     5,
				     0.0,
				     5.0);

  TH1F* WJetsRegion_NBtag = new TH1F(("WJets_"+name+"_nbtag").c_str(),
				     ("WJets_"+name+"_nbtag").c_str(),
				     5,
				     0.0,
				     5.0);
  
  TH1F* WJetsRegion_ZMass = new TH1F(("WJets_"+name+"_ZMass").c_str(),
				     ("WJets_"+name+"_ZMass").c_str(),
				     100,
				     0.0,
				     200.0);

  TH1F* WJetsRegion_ZPT = new TH1F(("WJets_"+name+"_ZPT").c_str(),
				   ("WJets_"+name+"_ZPT").c_str(),
				   100,
				   0.0,
				   500.0);
  TH1F* WJetsRegion_MT = new TH1F(("WJets_"+name+"_MT").c_str(),
				  ("WJets_"+name+"_MT").c_str(),
				  100,
				  0.0,
				   200.0);
  
  //do the genmatched version of these
  TH1F* GenMatch_WJetsRegion_MuPt = new TH1F(("WJets_GenMatch_"+name+"_MuPt").c_str(),
					     ("WJets_GenMatch_"+name+"_MuPt").c_str(),
					     100,
					     0.0,
					     200.0);
  
  TH1F* GenMatch_WJetsRegion_TauPt = new TH1F(("WJets_GenMatch_"+name+"_TauPt").c_str(),
					      ("WJets_GenMatch_"+name+"_TauPt").c_str(),
					      100,
					      0.0,
					      200.0);
  
  TH1F* GenMatch_WJetsRegion_MuEta = new TH1F(("WJets_GenMatch_"+name+"_MuEta").c_str(),
					      ("WJets_GenMatch_"+name+"_MuEta").c_str(),
					      100,
					      -4.0,
					      4.0);
  
  TH1F* GenMatch_WJetsRegion_TauEta = new TH1F(("WJets_GenMatch_"+name+"_TauEta").c_str(),
					       ("WJets_GenMatch_"+name+"_TauEta").c_str(),
					       100,
					       -4.0,
					       4.0);
  
  TH1F* GenMatch_WJetsRegion_NJets = new TH1F(("WJets_GenMatch_"+name+"_njets").c_str(),
					      ("WJets_GenMatch_"+name+"_njets").c_str(),
					      5,
					      0.0,
					      5.0);
  
  TH1F* GenMatch_WJetsRegion_NBtag = new TH1F(("WJets_GenMatch_"+name+"_nbtag").c_str(),
					      ("WJets_GenMatch_"+name+"_nbtag").c_str(),
					      5,
					      0.0,
					      5.0);

  TH1F* GenMatch_WJetsRegion_ZMass = new TH1F(("WJets_GenMatch_"+name+"_ZMass").c_str(),
					      ("WJets_GenMatch_"+name+"_ZMass").c_str(),
					      100,
					      0.0,
					      200.0);

  TH1F* GenMatch_WJetsRegion_ZPT = new TH1F(("WJets_GenMatch_"+name+"_ZPT").c_str(),
					    ("WJets_GenMatch_"+name+"_ZPT").c_str(),
					    100,
					    0.0,
					    500.0);
  TH1F* GenMatch_WJetsRegion_MT = new TH1F(("WJets_GenMatch_"+name+"_MT").c_str(),
					   ("WJets_GenMatch_"+name+"_MT").c_str(),
					   100,
					   0.0,
					   200.0);  

  TH1F* LowGenMatch_WJetsRegion_MuPt = new TH1F(("WJets_LowGenMatch_"+name+"_MuPt").c_str(),
						("WJets_LowGenMatch_"+name+"_MuPt").c_str(),
						100,
						0.0,
						200.0);
  
  TH1F* LowGenMatch_WJetsRegion_TauPt = new TH1F(("WJets_LowGenMatch_"+name+"_TauPt").c_str(),
						 ("WJets_LowGenMatch_"+name+"_TauPt").c_str(),
						 100,
						 0.0,
						 200.0);
  
  TH1F* LowGenMatch_WJetsRegion_MuEta = new TH1F(("WJets_LowGenMatch_"+name+"_MuEta").c_str(),
						 ("WJets_LowGenMatch_"+name+"_MuEta").c_str(),
						 100,
						 -4.0,
						 4.0);
  
  TH1F* LowGenMatch_WJetsRegion_TauEta = new TH1F(("WJets_LowGenMatch_"+name+"_TauEta").c_str(),
						  ("WJets_LowGenMatch_"+name+"_TauEta").c_str(),
						  100,
						  -4.0,
						  4.0);
  
  TH1F* LowGenMatch_WJetsRegion_NJets = new TH1F(("WJets_LowGenMatch_"+name+"_njets").c_str(),
						 ("WJets_LowGenMatch_"+name+"_njets").c_str(),
						 5,
						 0.0,
						 5.0);
  
  TH1F* LowGenMatch_WJetsRegion_NBtag = new TH1F(("WJets_LowGenMatch_"+name+"_nbtag").c_str(),
						 ("WJets_LowGenMatch_"+name+"_nbtag").c_str(),
						 5,
						 0.0,
						 5.0);
  
  TH1F* LowGenMatch_WJetsRegion_ZMass = new TH1F(("WJets_LowGenMatch_"+name+"_ZMass").c_str(),
						 ("WJets_LowGenMatch_"+name+"_ZMass").c_str(),
						 100,
						 0.0,
						 200.0);
  
  TH1F* LowGenMatch_WJetsRegion_ZPT = new TH1F(("WJets_LowGenMatch_"+name+"_ZPT").c_str(),
					       ("WJets_LowGenMatch_"+name+"_ZPT").c_str(),
					       100,
					       0.0,
					       500.0);
  TH1F* LowGenMatch_WJetsRegion_MT = new TH1F(("WJets_LowGenMatch_"+name+"_MT").c_str(),
					      ("WJets_LowGenMatch_"+name+"_MT").c_str(),
					      100,
					      0.0,
					      200.0);

  TH1F* HighGenMatch_WJetsRegion_MuPt = new TH1F(("WJets_HighGenMatch_"+name+"_MuPt").c_str(),
						 ("WJets_HighGenMatch_"+name+"_MuPt").c_str(),
						 100,
						 0.0,
						 200.0);
  
  TH1F* HighGenMatch_WJetsRegion_TauPt = new TH1F(("WJets_HighGenMatch_"+name+"_TauPt").c_str(),
						  ("WJets_HighGenMatch_"+name+"_TauPt").c_str(),
						  100,
						  0.0,
						  200.0);
  
  TH1F* HighGenMatch_WJetsRegion_MuEta = new TH1F(("WJets_HighGenMatch_"+name+"_MuEta").c_str(),
						  ("WJets_HighGenMatch_"+name+"_MuEta").c_str(),
						  100,
						  -4.0,
						  4.0);
  
  TH1F* HighGenMatch_WJetsRegion_TauEta = new TH1F(("WJets_HighGenMatch_"+name+"_TauEta").c_str(),
						   ("WJets_HighGenMatch_"+name+"_TauEta").c_str(),
						   100,
						   -4.0,
						   4.0);
  
  TH1F* HighGenMatch_WJetsRegion_NJets = new TH1F(("WJets_HighGenMatch_"+name+"_njets").c_str(),
						  ("WJets_HighGenMatch_"+name+"_njets").c_str(),
						  5,
						  0.0,
						  5.0);
  
  TH1F* HighGenMatch_WJetsRegion_NBtag = new TH1F(("WJets_HighGenMatch_"+name+"_nbtag").c_str(),
						  ("WJets_HighGenMatch_"+name+"_nbtag").c_str(),
						  5,
						  0.0,
						  5.0);
  
  TH1F* HighGenMatch_WJetsRegion_ZMass = new TH1F(("WJets_HighGenMatch_"+name+"_ZMass").c_str(),
						  ("WJets_HighGenMatch_"+name+"_ZMass").c_str(),
						  100,
						  0.0,
						  200.0);
  
  TH1F* HighGenMatch_WJetsRegion_ZPT = new TH1F(("WJets_HighGenMatch_"+name+"_ZPT").c_str(),
						("WJets_HighGenMatch_"+name+"_ZPT").c_str(),
						100,
						0.0,
						500.0);
  TH1F* HighGenMatch_WJetsRegion_MT = new TH1F(("WJets_HighGenMatch_"+name+"_MT").c_str(),
					       ("WJets_HighGenMatch_"+name+"_MT").c_str(),
					       100,
					       0.0,
					       200.0);  

  //QCD Region Control Plots  
  TH1F* QCDRegion_MuPt = new TH1F(("QCD_"+name+"_MuPt").c_str(),
				  ("QCD_"+name+"_MuPt").c_str(),
				  100,
				  0.0,
				  200.0);
  
  TH1F* QCDRegion_TauPt = new TH1F(("QCD_"+name+"_TauPt").c_str(),
				   ("QCD_"+name+"_TauPt").c_str(),
				   100,
				   0.0,
				   200.0);
  
  TH1F* QCDRegion_MuEta = new TH1F(("QCD_"+name+"_MuEta").c_str(),
				   ("QCD_"+name+"_MuEta").c_str(),
				   100,
				   -4.0,
				   4.0);
  
  TH1F* QCDRegion_TauEta = new TH1F(("QCD_"+name+"_TauEta").c_str(),
				    ("QCD_"+name+"_TauEta").c_str(),
				    100,
				    -4.0,
				    4.0);

  TH1F* QCDRegion_NJets = new TH1F(("QCD_"+name+"_njets").c_str(),
				   ("QCD_"+name+"_njets").c_str(),
				   5,
				   0.0,
				   5.0);

  TH1F* QCDRegion_NBtag = new TH1F(("QCD_"+name+"_nbtag").c_str(),
				   ("QCD_"+name+"_nbtag").c_str(),
				   5,
				   0.0,
				   5.0);

  TH1F* QCDRegion_ZMass = new TH1F(("QCD_"+name+"_ZMass").c_str(),
				   ("QCD_"+name+"_ZMass").c_str(),
				   100,
				   0.0,
				   200.0);

  TH1F* QCDRegion_ZPT = new TH1F(("QCD_"+name+"_ZPT").c_str(),
				 ("QCD_"+name+"_ZPT").c_str(),
				 100,
				 0.0,
				 500.0);
  
  TH1F* QCDRegion_MT = new TH1F(("QCD_"+name+"_MT").c_str(),
				("QCD_"+name+"_MT").c_str(),
				100,
				0.0,
				200.0);
  
  //do the genmatched version of these
  TH1F* GenMatch_QCDRegion_MuPt = new TH1F(("QCD_GenMatch_"+name+"_MuPt").c_str(),
					   ("QCD_GenMatch_"+name+"_MuPt").c_str(),
					   100,
					   0.0,
					   200.0);
  
  TH1F* GenMatch_QCDRegion_TauPt = new TH1F(("QCD_GenMatch_"+name+"_TauPt").c_str(),
					    ("QCD_GenMatch_"+name+"_TauPt").c_str(),
					    100,
					    0.0,
					    200.0);
  
  TH1F* GenMatch_QCDRegion_MuEta = new TH1F(("QCD_GenMatch_"+name+"_MuEta").c_str(),
					    ("QCD_GenMatch_"+name+"_MuEta").c_str(),
					    100,
					    -4.0,
					    4.0);
  
  TH1F* GenMatch_QCDRegion_TauEta = new TH1F(("QCD_GenMatch_"+name+"_TauEta").c_str(),
					     ("QCD_GenMatch_"+name+"_TauEta").c_str(),
					     100,
					     -4.0,
					     4.0);
  
  TH1F* GenMatch_QCDRegion_NJets = new TH1F(("QCD_GenMatch_"+name+"_njets").c_str(),
					    ("QCD_GenMatch_"+name+"_njets").c_str(),
					    5,
					    0.0,
					    5.0);
  
  TH1F* GenMatch_QCDRegion_NBtag = new TH1F(("QCD_GenMatch_"+name+"_nbtag").c_str(),
					    ("QCD_GenMatch_"+name+"_nbtag").c_str(),
					    5,
					    0.0,
					    5.0);

  TH1F* GenMatch_QCDRegion_ZMass = new TH1F(("QCD_GenMatch_"+name+"_ZMass").c_str(),
					    ("QCD_GenMatch_"+name+"_ZMass").c_str(),
					    100,
					    0.0,
					    200.0);

  TH1F* GenMatch_QCDRegion_ZPT = new TH1F(("QCD_GenMatch_"+name+"_ZPT").c_str(),
					  ("QCD_GenMatch_"+name+"_ZPT").c_str(),
					  100,
					  0.0,
					  500.0);
  TH1F* GenMatch_QCDRegion_MT = new TH1F(("QCD_GenMatch_"+name+"_MT").c_str(),
					 ("QCD_GenMatch_"+name+"_MT").c_str(),
					 100,
					 0.0,
					 200.0);  

  TH1F* LowGenMatch_QCDRegion_MuPt = new TH1F(("QCD_LowGenMatch_"+name+"_MuPt").c_str(),
					      ("QCD_LowGenMatch_"+name+"_MuPt").c_str(),
					      100,
					      0.0,
					      200.0);
  
  TH1F* LowGenMatch_QCDRegion_TauPt = new TH1F(("QCD_LowGenMatch_"+name+"_TauPt").c_str(),
					       ("QCD_LowGenMatch_"+name+"_TauPt").c_str(),
					       100,
					       0.0,
					       200.0);
  
  TH1F* LowGenMatch_QCDRegion_MuEta = new TH1F(("QCD_LowGenMatch_"+name+"_MuEta").c_str(),
					       ("QCD_LowGenMatch_"+name+"_MuEta").c_str(),
					       100,
					       -4.0,
					       4.0);
  
  TH1F* LowGenMatch_QCDRegion_TauEta = new TH1F(("QCD_LowGenMatch_"+name+"_TauEta").c_str(),
						("QCD_LowGenMatch_"+name+"_TauEta").c_str(),
						100,
						-4.0,
						4.0);
  
  TH1F* LowGenMatch_QCDRegion_NJets = new TH1F(("QCD_LowGenMatch_"+name+"_njets").c_str(),
					       ("QCD_LowGenMatch_"+name+"_njets").c_str(),
					       5,
					       0.0,
					       5.0);
  
  TH1F* LowGenMatch_QCDRegion_NBtag = new TH1F(("QCD_LowGenMatch_"+name+"_nbtag").c_str(),
					       ("QCD_LowGenMatch_"+name+"_nbtag").c_str(),
					       5,
					       0.0,
					       5.0);
  
  TH1F* LowGenMatch_QCDRegion_ZMass = new TH1F(("QCD_LowGenMatch_"+name+"_ZMass").c_str(),
					       ("QCD_LowGenMatch_"+name+"_ZMass").c_str(),
					       100,
					       0.0,
					       200.0);
  
  TH1F* LowGenMatch_QCDRegion_ZPT = new TH1F(("QCD_LowGenMatch_"+name+"_ZPT").c_str(),
					     ("QCD_LowGenMatch_"+name+"_ZPT").c_str(),
					     100,
					     0.0,
					     500.0);
  TH1F* LowGenMatch_QCDRegion_MT = new TH1F(("QCD_LowGenMatch_"+name+"_MT").c_str(),
					    ("QCD_LowGenMatch_"+name+"_MT").c_str(),
					    100,
					    0.0,
					    200.0);

  TH1F* HighGenMatch_QCDRegion_MuPt = new TH1F(("QCD_HighGenMatch_"+name+"_MuPt").c_str(),
					       ("QCD_HighGenMatch_"+name+"_MuPt").c_str(),
					       100,
					       0.0,
					       200.0);
  
  TH1F* HighGenMatch_QCDRegion_TauPt = new TH1F(("QCD_HighGenMatch_"+name+"_TauPt").c_str(),
						("QCD_HighGenMatch_"+name+"_TauPt").c_str(),
						100,
						0.0,
						200.0);
  
  TH1F* HighGenMatch_QCDRegion_MuEta = new TH1F(("QCD_HighGenMatch_"+name+"_MuEta").c_str(),
						("QCD_HighGenMatch_"+name+"_MuEta").c_str(),
						100,
						-4.0,
						4.0);
  
  TH1F* HighGenMatch_QCDRegion_TauEta = new TH1F(("QCD_HighGenMatch_"+name+"_TauEta").c_str(),
						 ("QCD_HighGenMatch_"+name+"_TauEta").c_str(),
						 100,
						 -4.0,
						 4.0);
  
  TH1F* HighGenMatch_QCDRegion_NJets = new TH1F(("QCD_HighGenMatch_"+name+"_njets").c_str(),
						("QCD_HighGenMatch_"+name+"_njets").c_str(),
						5,
						0.0,
						5.0);
  
  TH1F* HighGenMatch_QCDRegion_NBtag = new TH1F(("QCD_HighGenMatch_"+name+"_nbtag").c_str(),
						("QCD_HighGenMatch_"+name+"_nbtag").c_str(),
						5,
						0.0,
						5.0);
  
  TH1F* HighGenMatch_QCDRegion_ZMass = new TH1F(("QCD_HighGenMatch_"+name+"_ZMass").c_str(),
						("QCD_HighGenMatch_"+name+"_ZMass").c_str(),
						100,
						0.0,
						200.0);
  
  TH1F* HighGenMatch_QCDRegion_ZPT = new TH1F(("QCD_HighGenMatch_"+name+"_ZPT").c_str(),
					      ("QCD_HighGenMatch_"+name+"_ZPT").c_str(),
					      100,
					      0.0,
					      500.0);
  TH1F* HighGenMatch_QCDRegion_MT = new TH1F(("QCD_HighGenMatch_"+name+"_MT").c_str(),
					     ("QCD_HighGenMatch_"+name+"_MT").c_str(),
					     100,
					     0.0,
					     200.0);

  //QCD/WJets Mixed area
  TH1F* QCDinWJets_MuPt = new TH1F(("WJets_QCD_"+name+"_MuPt").c_str(),
				   ("WJets_QCD_"+name+"_MuPt").c_str(),
				   100,
				   0.0,
				   200.0);
  
  TH1F* QCDinWJets_TauPt = new TH1F(("WJets_QCD_"+name+"_TauPt").c_str(),
				    ("WJets_QCD_"+name+"_TauPt").c_str(),
				    100,
				    0.0,
				    200.0);
  
  TH1F* QCDinWJets_MuEta = new TH1F(("WJets_QCD_"+name+"_MuEta").c_str(),
				    ("WJets_QCD_"+name+"_MuEta").c_str(),
				    100,
				    -4.0,
				    4.0);
  
  TH1F* QCDinWJets_TauEta = new TH1F(("WJets_QCD_"+name+"_TauEta").c_str(),
				     ("WJets_QCD_"+name+"_TauEta").c_str(),
				     100,
				     -4.0,
				     4.0);
  
  TH1F* QCDinWJets_NJets = new TH1F(("WJets_QCD_"+name+"_njets").c_str(),
				    ("WJets_QCD_"+name+"_njets").c_str(),
				    5,
				    0.0,
				    5.0);
  
  TH1F* QCDinWJets_NBtag = new TH1F(("WJets_QCD_"+name+"_nbtag").c_str(),
				    ("WJets_QCD_"+name+"_nbtag").c_str(),
				    5,
				    0.0,
				    5.0);

  TH1F* QCDinWJets_ZMass = new TH1F(("WJets_QCD_"+name+"_ZMass").c_str(),
				    ("WJets_QCD_"+name+"_ZMass").c_str(),
				    100,
				    0.0,
				    200.0);

  TH1F* QCDinWJets_ZPT = new TH1F(("WJets_QCD_"+name+"_ZPT").c_str(),
				  ("WJets_QCD_"+name+"_ZPT").c_str(),
				  100,
				  0.0,
				  500.0);
  TH1F* QCDinWJets_MT = new TH1F(("WJets_QCD_"+name+"_MT").c_str(),
				 ("WJets_QCD_"+name+"_MT").c_str(),
				 100,
				 0.0,
				 200.0);
  
  //do the genmatched version of these
  TH1F* GenMatch_QCDinWJets_MuPt = new TH1F(("WJets_QCD_GenMatch_"+name+"_MuPt").c_str(),
					    ("WJets_QCD_GenMatch_"+name+"_MuPt").c_str(),
					    100,
					    0.0,
					    200.0);
  
  TH1F* GenMatch_QCDinWJets_TauPt = new TH1F(("WJets_QCD_GenMatch_"+name+"_TauPt").c_str(),
					     ("WJets_QCD_GenMatch_"+name+"_TauPt").c_str(),
					     100,
					     0.0,
					     200.0);
  
  TH1F* GenMatch_QCDinWJets_MuEta = new TH1F(("WJets_QCD_GenMatch_"+name+"_MuEta").c_str(),
					     ("WJets_QCD_GenMatch_"+name+"_MuEta").c_str(),
					     100,
					     -4.0,
					     4.0);
  
  TH1F* GenMatch_QCDinWJets_TauEta = new TH1F(("WJets_QCD_GenMatch_"+name+"_TauEta").c_str(),
					      ("WJets_QCD_GenMatch_"+name+"_TauEta").c_str(),
					      100,
					      -4.0,
					      4.0);
  
  TH1F* GenMatch_QCDinWJets_NJets = new TH1F(("WJets_QCD_GenMatch_"+name+"_njets").c_str(),
					     ("WJets_QCD_GenMatch_"+name+"_njets").c_str(),
					     5,
					     0.0,
					     5.0);
  
  TH1F* GenMatch_QCDinWJets_NBtag = new TH1F(("WJets_QCD_GenMatch_"+name+"_nbtag").c_str(),
					     ("WJets_QCD_GenMatch_"+name+"_nbtag").c_str(),
					     5,
					     0.0,
					     5.0);

  TH1F* GenMatch_QCDinWJets_ZMass = new TH1F(("WJets_QCD_GenMatch_"+name+"_ZMass").c_str(),
					     ("WJets_QCD_GenMatch_"+name+"_ZMass").c_str(),
					     100,
					     0.0,
					     200.0);

  TH1F* GenMatch_QCDinWJets_ZPT = new TH1F(("WJets_QCD_GenMatch_"+name+"_ZPT").c_str(),
					   ("WJets_QCD_GenMatch_"+name+"_ZPT").c_str(),
					   100,
					   0.0,
					   500.0);
  TH1F* GenMatch_QCDinWJets_MT = new TH1F(("WJets_QCD_GenMatch_"+name+"_MT").c_str(),
					  ("WJets_QCD_GenMatch_"+name+"_MT").c_str(),
					  100,
					  0.0,
					  200.0);  

  TH1F* LowGenMatch_QCDinWJets_MuPt = new TH1F(("WJets_QCD_LowGenMatch_"+name+"_MuPt").c_str(),
					       ("WJets_QCD_LowGenMatch_"+name+"_MuPt").c_str(),
					       100,
					       0.0,
					       200.0);
  
  TH1F* LowGenMatch_QCDinWJets_TauPt = new TH1F(("WJets_QCD_LowGenMatch_"+name+"_TauPt").c_str(),
						("WJets_QCD_LowGenMatch_"+name+"_TauPt").c_str(),
						100,
						0.0,
						200.0);
  
  TH1F* LowGenMatch_QCDinWJets_MuEta = new TH1F(("WJets_QCD_LowGenMatch_"+name+"_MuEta").c_str(),
						("WJets_QCD_LowGenMatch_"+name+"_MuEta").c_str(),
						100,
						-4.0,
						4.0);
  
  TH1F* LowGenMatch_QCDinWJets_TauEta = new TH1F(("WJets_QCD_LowGenMatch_"+name+"_TauEta").c_str(),
						 ("WJets_QCD_LowGenMatch_"+name+"_TauEta").c_str(),
						 100,
						 -4.0,
						 4.0);
  
  TH1F* LowGenMatch_QCDinWJets_NJets = new TH1F(("WJets_QCD_LowGenMatch_"+name+"_njets").c_str(),
						("WJets_QCD_LowGenMatch_"+name+"_njets").c_str(),
						5,
						0.0,
						5.0);
  
  TH1F* LowGenMatch_QCDinWJets_NBtag = new TH1F(("WJets_QCD_LowGenMatch_"+name+"_nbtag").c_str(),
						("WJets_QCD_LowGenMatch_"+name+"_nbtag").c_str(),
						5,
						0.0,
						5.0);
  
  TH1F* LowGenMatch_QCDinWJets_ZMass = new TH1F(("WJets_QCD_LowGenMatch_"+name+"_ZMass").c_str(),
						("WJets_QCD_LowGenMatch_"+name+"_ZMass").c_str(),
						100,
						0.0,
						200.0);
  
  TH1F* LowGenMatch_QCDinWJets_ZPT = new TH1F(("WJets_QCD_LowGenMatch_"+name+"_ZPT").c_str(),
					      ("WJets_QCD_LowGenMatch_"+name+"_ZPT").c_str(),
					      100,
					      0.0,
					      500.0);
  TH1F* LowGenMatch_QCDinWJets_MT = new TH1F(("WJets_QCD_LowGenMatch_"+name+"_MT").c_str(),
					     ("WJets_QCD_LowGenMatch_"+name+"_MT").c_str(),
					     100,
					     0.0,
					     200.0);

  TH1F* HighGenMatch_QCDinWJets_MuPt = new TH1F(("WJets_QCD_HighGenMatch_"+name+"_MuPt").c_str(),
						("WJets_QCD_HighGenMatch_"+name+"_MuPt").c_str(),
						100,
						0.0,
						200.0);
  
  TH1F* HighGenMatch_QCDinWJets_TauPt = new TH1F(("WJets_QCD_HighGenMatch_"+name+"_TauPt").c_str(),
						 ("WJets_QCD_HighGenMatch_"+name+"_TauPt").c_str(),
						 100,
						 0.0,
						 200.0);
  
  TH1F* HighGenMatch_QCDinWJets_MuEta = new TH1F(("WJets_QCD_HighGenMatch_"+name+"_MuEta").c_str(),
						 ("WJets_QCD_HighGenMatch_"+name+"_MuEta").c_str(),
						 100,
						 -4.0,
						 4.0);
  
  TH1F* HighGenMatch_QCDinWJets_TauEta = new TH1F(("WJets_QCD_HighGenMatch_"+name+"_TauEta").c_str(),
						  ("WJets_QCD_HighGenMatch_"+name+"_TauEta").c_str(),
						  100,
						  -4.0,
						  4.0);
  
  TH1F* HighGenMatch_QCDinWJets_NJets = new TH1F(("WJets_QCD_HighGenMatch_"+name+"_njets").c_str(),
						 ("WJets_QCD_HighGenMatch_"+name+"_njets").c_str(),
						 5,
						 0.0,
						 5.0);
  
  TH1F* HighGenMatch_QCDinWJets_NBtag = new TH1F(("WJets_QCD_HighGenMatch_"+name+"_nbtag").c_str(),
						 ("WJets_QCD_HighGenMatch_"+name+"_nbtag").c_str(),
						 5,
						 0.0,
						 5.0);
  
  TH1F* HighGenMatch_QCDinWJets_ZMass = new TH1F(("WJets_QCD_HighGenMatch_"+name+"_ZMass").c_str(),
						 ("WJets_QCD_HighGenMatch_"+name+"_ZMass").c_str(),
						 100,
						 0.0,
						 200.0);
  
  TH1F* HighGenMatch_QCDinWJets_ZPT = new TH1F(("WJets_QCD_HighGenMatch_"+name+"_ZPT").c_str(),
					       ("WJets_QCD_HighGenMatch_"+name+"_ZPT").c_str(),
					       100,
					       0.0,
					       500.0);
  TH1F* HighGenMatch_QCDinWJets_MT = new TH1F(("WJets_QCD_HighGenMatch_"+name+"_MT").c_str(),
					      ("WJets_QCD_HighGenMatch_"+name+"_MT").c_str(),
					      100,
					      0.0,
					      200.0);

  //Determine the relevant cross section or normalization
  float LHCLumi = 41.370e15;
  float NormalizationWeight;
  float XSecWeight; 
  if(input == "WW")XSecWeight = LHCLumi * 118.7e-12 / TotalNumberOfEvents;
  else if(input == "WZ") XSecWeight = LHCLumi * 47.13e-12 / TotalNumberOfEvents;
  else if(input == "ZZ") XSecWeight = LHCLumi * 16.523e-12 / TotalNumberOfEvents;
  else if(input == "W") XSecWeight = LHCLumi * 61526.7e-12 / TotalNumberOfEvents;
  else if(input == "TTTo2L2Nu") XSecWeight = LHCLumi * 88.34e-12/ TotalNumberOfEvents;
  else if(input == "TTToHadronic") XSecWeight = LHCLumi * 377.96e-12 / TotalNumberOfEvents;
  else if(input == "TTToSemiLeptonic") XSecWeight = LHCLumi * 365.45e-12 / TotalNumberOfEvents;
  else if(input == "DY") XSecWeight = LHCLumi * 6225.42e-12 / TotalNumberOfEvents;
  else if(input == "Data") XSecWeight = 1.0;
  //additional cross section weights taken from the excel file.
  else if(input == "DY1") XSecWeight = LHCLumi * 1178.29e-12 /TotalNumberOfEvents;
  else if(input == "DY2") XSecWeight = LHCLumi * 387.34e-12 /TotalNumberOfEvents;
  else if(input == "DY3") XSecWeight = LHCLumi * 118.429e-12 /TotalNumberOfEvents;
  else if(input == "DY4") XSecWeight = LHCLumi * 63.73e-12 /TotalNumberOfEvents;
  else if(input == "ST_top") XSecWeight = LHCLumi * 113.3e-12 /TotalNumberOfEvents;
  else if(input == "ST_antitop") XSecWeight = LHCLumi * 67.91e-12 /TotalNumberOfEvents;
  else if(input == "ST_tW_top") XSecWeight = LHCLumi * 34.91e-12 /TotalNumberOfEvents;
  else if(input == "ST_tW_antitop") XSecWeight = LHCLumi * 34.91e-12 /TotalNumberOfEvents;
  else if(input == "W1") XSecWeight = LHCLumi * 11778.36e-12 /TotalNumberOfEvents;
  else if(input == "W2") XSecWeight = LHCLumi * 3840.22e-12 /TotalNumberOfEvents;
  else if(input == "W3") XSecWeight = LHCLumi * 1166.05e-12 /TotalNumberOfEvents;
  else if(input == "W4") XSecWeight = LHCLumi * 593.055e-12 /TotalNumberOfEvents;
  else
    {
      std::cout<<"ERROR! Unrecognized Sample! Defaulting to no cross section weighting!"<<std::endl;
      XSecWeight = 1.0;
    }

  std::cout<<"Lumi: "<<LHCLumi<<std::endl;
  std::cout<<"TotalNumberOfEvents: "<<TotalNumberOfEvents<<std::endl;
  //std::cout<<"NormalizationWeight: "<<NormalizationWeight<<std::endl;

  reweight::LumiReWeighting* LumiWeights_12;
  LumiWeights_12 = new reweight::LumiReWeighting(("/data/aloeliger/CMSSW_9_4_0/src/SMHTTAnalysis/SkimmedNtuples/TauID2017/"+input+".root").c_str(),
						 "Weightings/MyDataPileupHistogram.root",
						 "pileup_mc",
						 "pileup");

  TFile* TriggerFile = new TFile("Weightings/EfficienciesAndSF_RunBtoF_Nov17Nov2017.root");
  TDirectoryFile* TriggerMuDirectory = (TDirectoryFile* )TriggerFile->Get("IsoMu27_PtEtaBins");
  TH2F* TriggerWeightings = (TH2F*) TriggerMuDirectory->Get("abseta_pt_ratio");

  TFile* IDFile = new TFile("Weightings/RunBCDEF_SF_ID.root");
  TH2F* IDWeightings = (TH2F*) IDFile->Get("NUM_MediumID_DEN_genTracks_pt_abseta");
  
  TFile* ISOFile = new TFile("Weightings/RunBCDEF_SF_ISO.root");
  TH2F* ISOWeightings = (TH2F*) ISOFile->Get("NUM_TightRelIso_DEN_MediumID_pt_abseta");  
  
  int AcceptedSignalEvents = 0;
  int AcceptedWJetsEvents = 0;
  int AcceptedQCDEvents = 0;
  int AcceptedQCDWJetsEvents = 0;
  float AverageWeight = 0.0;
  float AcceptedEvents = 0.0;

  for(int i =0;i < NumberOfEntries; i++)
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
      
      //make the necessary 4 vectors      
      TLorentzVector l1; l1.SetPtEtaPhiM(pt_1, eta_1, phi_1, m_1); //muon
      TLorentzVector l2; l2.SetPtEtaPhiM(pt_2, eta_2, phi_2, m_2); //tau
      //Handle the TES and Muon shape uncertainty
      l2 = l2*ShapeUncertainty;
      TLorentzVector l2_DM0Mod = l2;
      TLorentzVector l2_DM1Mod = l2;
      TLorentzVector l2_DM10Mod = l2;
      if(ShapeUncertainty != 1.0)
	{
	  if(l2_decayMode == 0)
	    {
	      l2_DM0Mod = l2_DM0Mod * ShapeUncertainty;
	    }
	  else if(l2_decayMode == 1)
	    {
	      l2_DM1Mod = l2_DM1Mod * ShapeUncertainty;
	    }
	  else if(l2_decayMode == 10)
	    {
	      l2_DM10Mod = l2_DM10Mod * ShapeUncertainty;
	    }
	}

      //Event selection
      //muon criteria     
      //CHanged to Match Diego's pt > 30 cut, as opposed to my original > 29 cut      
      if(pt_1 < 30.0 or std::abs(eta_1) > 2.4 or !id_m_medium_1 or iso_1 > 0.15 or std::abs(dZ_1) > 0.2 or std::abs(d0_1) > 0.045 or !matchIsoMu27_1) continue;      
      
      //tau criteria
      //
      if(pt_2 < 20.0  or std::abs(eta_2) > 2.3 or againstElectronVLooseMVA6_2 != 1 or againstMuonTight3_2 != 1 or !decayModeFinding_2 or std::abs(dZ_2) > 0.2 or std::abs(q_2) > 1) continue;
      //EventsPassingTauSelection+=1.0;            

      //comment this if using old method
      //if(input != "Data" && gen_match_2 == 6) continue;

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
      // from the excel file.
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
      else if(input == "Data") NormalizationWeight = 1.0;          
      else
	{
	  std::cout<<"ERROR! Unrecognized Sample! Defaulting to unweighted events!"<<std::endl;
	  NormalizationWeight = 1.0;
	}
      NormalizationWeight = NormalizationWeight*amcatNLO_weight;      
      if(input == "Data") NormalizationWeight = 1.0;

      AverageWeight += NormalizationWeight;
      AcceptedEvents += 1.0;

      //Data Selection
      float Var = (l1+l2).M();                              
      float Var_DM0Mod = (l1+l2_DM0Mod).M();
      float Var_DM1Mod = (l1+l2_DM1Mod).M();
      float Var_DM10Mod = (l1+l2_DM10Mod).M();
      //float Var = TransverseMass;
      //float Var_DM0Mod = TransverseMass;
      //float Var_DM1Mod = TransverseMass;
      //float Var_DM10Mod = TransverseMass;
      //float Var = njets;
      //float Var_DM0Mod = njets;
      //float Var_DM1Mod = njets;
      //float Var_DM10Mod = njets;
      //float Var = l2.Eta();
      //float Var = l1.Eta();
      /*
      float Var = l1.Pt();
      float Var_DM0Mod = l1.Pt();
      float Var_DM1Mod = l1.Pt();
      float Var_DM10Mod = l1.Pt();
      */
      /*
      float Var = l2.Pt();
      float Var_DM0Mod = l2.Pt();
      float Var_DM1Mod = l2.Pt();
      float Var_DM10Mod = l2.Pt();
      */
      //float Var = npv;
    
      bool TauIsoDiscrim;
      assert( IsoWorkingPoint == "VLoose" ||
	     IsoWorkingPoint == "Loose" ||
	      IsoWorkingPoint == "Medium" ||
	      IsoWorkingPoint == "Tight" ||
	      IsoWorkingPoint == "VTight" ||
	      IsoWorkingPoint == "VVTight");
      
      if(IsoWorkingPoint == "VLoose")
	{
	  TauIsoDiscrim = (bool) byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2;
	}
      else if(IsoWorkingPoint == "Loose")
	{
	  TauIsoDiscrim = (bool) byLooseIsolationRerunMVArun2v2DBoldDMwLT_2;
	}
      else if(IsoWorkingPoint == "Medium")
	{
	  TauIsoDiscrim = (bool) byMediumIsolationRerunMVArun2v2DBoldDMwLT_2;
	}
      else if(IsoWorkingPoint == "Tight")
	{
	  TauIsoDiscrim = (bool) byTightIsolationRerunMVArun2v2DBoldDMwLT_2;
	}
      else if(IsoWorkingPoint == "VTight")
	{
	  TauIsoDiscrim = (bool) byVTightIsolationRerunMVArun2v2DBoldDMwLT_2;
	}
      else if(IsoWorkingPoint == "VVTight")
	{
	  TauIsoDiscrim = (bool) byVVTightIsolationRerunMVArun2v2DBoldDMwLT_2;
	}
            

      //we check four things at the same time. Signal region checks, W+Jets region checks, QCD in the signal region, and QCD in the W+Jets Region.
      //check the tau iso discriminants, and divide these our events by pass/fail
      if(q_1 * q_2 < 0.0)
	{
	  //Signal contribution
	  //changed the mt cut to 50 to match diego, instead of my original 40
	  if(TransverseMass < 50.0 and PZeta > -25.0)
	    {
	      //match Diego's sync tree style, do it regardless of which isolation discriminant we're working with
	      SyncTree->Fill();

	      if(TauIsoDiscrim)
		{		  
		  //in the passing region now.		  		  
		  AcceptedSignalEvents++;
		  //seperate out our signal region in the drell yan histos
		  if(input == "DY"
		     or input == "DY1"
		     or input == "DY2"
		     or input == "DY3"
		     or input == "DY4")
		    {
		      if(gen_match_2 < 5 ) 
			{
			  LowGenMatch_SignalRegion_Pass->Fill(Var,NormalizationWeight);    
			  
			  LowGenMatch_SignalRegion_MuPt->Fill(l1.Pt(),NormalizationWeight);
			  LowGenMatch_SignalRegion_TauPt->Fill(l2.Pt(),NormalizationWeight);
			  LowGenMatch_SignalRegion_MuEta->Fill(l1.Eta(),NormalizationWeight);
			  LowGenMatch_SignalRegion_TauEta->Fill(l2.Eta(),NormalizationWeight);
			  LowGenMatch_SignalRegion_NJets->Fill(njets,NormalizationWeight);
			  LowGenMatch_SignalRegion_NBtag->Fill(nbtag,NormalizationWeight);
			  LowGenMatch_SignalRegion_ZMass->Fill((l1+l2).M(),NormalizationWeight);
			  LowGenMatch_SignalRegion_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
			  LowGenMatch_SignalRegion_MT->Fill(TransverseMass,NormalizationWeight);
			}
		      if(gen_match_2 == 5) 
			{
			  GenMatch_SignalRegion_Pass->Fill(Var,NormalizationWeight);    
			  GenMatch_SignalRegion_DM0Mod_Pass->Fill(Var_DM0Mod, NormalizationWeight);
			  GenMatch_SignalRegion_DM1Mod_Pass->Fill(Var_DM1Mod, NormalizationWeight);
			  GenMatch_SignalRegion_DM10Mod_Pass->Fill(Var_DM10Mod, NormalizationWeight);
			  
			  GenMatch_SignalRegion_MuPt->Fill(l1.Pt(),NormalizationWeight);
			  GenMatch_SignalRegion_TauPt->Fill(l2.Pt(),NormalizationWeight);
			  GenMatch_SignalRegion_MuEta->Fill(l1.Eta(),NormalizationWeight);
			  GenMatch_SignalRegion_TauEta->Fill(l2.Eta(),NormalizationWeight);
			  GenMatch_SignalRegion_NJets->Fill(njets,NormalizationWeight);
			  GenMatch_SignalRegion_NBtag->Fill(nbtag,NormalizationWeight);
			  GenMatch_SignalRegion_ZMass->Fill((l1+l2).M(),NormalizationWeight);
			  GenMatch_SignalRegion_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
			  GenMatch_SignalRegion_MT->Fill(TransverseMass,NormalizationWeight);
			}
		      if(gen_match_2 == 6)
			{
			  HighGenMatch_SignalRegion_Pass->Fill(Var,NormalizationWeight);    		      
			  
			  HighGenMatch_SignalRegion_MuPt->Fill(l1.Pt(),NormalizationWeight);
			  HighGenMatch_SignalRegion_TauPt->Fill(l2.Pt(),NormalizationWeight);
			  HighGenMatch_SignalRegion_MuEta->Fill(l1.Eta(),NormalizationWeight);
			  HighGenMatch_SignalRegion_TauEta->Fill(l2.Eta(),NormalizationWeight);
			  HighGenMatch_SignalRegion_NJets->Fill(njets,NormalizationWeight);
			  HighGenMatch_SignalRegion_NBtag->Fill(nbtag,NormalizationWeight);
			  HighGenMatch_SignalRegion_ZMass->Fill((l1+l2).M(),NormalizationWeight);
			  HighGenMatch_SignalRegion_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
			  HighGenMatch_SignalRegion_MT->Fill(TransverseMass,NormalizationWeight);
			}
		    }
		  //Literally everything else
		  else
		    {

		      SignalRegion_Pass->Fill(Var,NormalizationWeight);    		      
		      
		      SignalRegion_MuPt->Fill(l1.Pt(),NormalizationWeight);
		      SignalRegion_TauPt->Fill(l2.Pt(),NormalizationWeight);
		      SignalRegion_MuEta->Fill(l1.Eta(),NormalizationWeight);
		      SignalRegion_TauEta->Fill(l2.Eta(),NormalizationWeight);
		      SignalRegion_NJets->Fill(njets,NormalizationWeight);
		      SignalRegion_NBtag->Fill(nbtag,NormalizationWeight);
		      SignalRegion_ZMass->Fill((l1+l2).M(),NormalizationWeight);
		      SignalRegion_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
		      SignalRegion_MT->Fill(TransverseMass,NormalizationWeight);
		    }
		}
	      else
		{		  
		  //seperate out the Z->tautau stuff
		  if(input == "DY"
		     or input == "DY1"
		     or input == "DY2"
		     or input == "DY3"
		     or input == "DY4")
		    {
		      if(gen_match_2 < 5) LowGenMatch_SignalRegion_Fail->Fill(Var,NormalizationWeight);
		      if(gen_match_2 == 5) GenMatch_SignalRegion_Fail->Fill(Var,NormalizationWeight);
		      if(gen_match_2 == 6) HighGenMatch_SignalRegion_Fail->Fill(Var,NormalizationWeight);
		    }
		  //Literally everything else
		  else
		    {
		      SignalRegion_Fail->Fill(Var,NormalizationWeight);
		    }
		}
	    }
	  //WJets Contribution
	  if(TransverseMass > 80.0)
	    {
	      if(TauIsoDiscrim)
		{		  
		  //WJets region
		  AcceptedWJetsEvents++;
		  //seperate out the Z->tau tau stuff
		  if(input == "DY"
		     or input == "DY1"
		     or input == "DY2"
		     or input == "DY3"
		     or input == "DY4")
		    {
		      if(gen_match_2 < 5)  
			{
			  LowGenMatch_WJetsRegion_Pass->Fill(Var,NormalizationWeight);
			  
			  LowGenMatch_WJetsRegion_MuPt->Fill(l1.Pt(),NormalizationWeight);
			  LowGenMatch_WJetsRegion_TauPt->Fill(l2.Pt(),NormalizationWeight);
			  LowGenMatch_WJetsRegion_MuEta->Fill(l1.Eta(),NormalizationWeight);
			  LowGenMatch_WJetsRegion_TauEta->Fill(l2.Eta(),NormalizationWeight);
			  LowGenMatch_WJetsRegion_NJets->Fill(njets,NormalizationWeight);
			  LowGenMatch_WJetsRegion_NBtag->Fill(nbtag,NormalizationWeight);
			  LowGenMatch_WJetsRegion_ZMass->Fill((l1+l2).M(),NormalizationWeight);
			  LowGenMatch_WJetsRegion_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
			  LowGenMatch_WJetsRegion_MT->Fill(TransverseMass,NormalizationWeight);
			}
		      if(gen_match_2 == 5)
			{
			  GenMatch_WJetsRegion_Pass->Fill(Var,NormalizationWeight);

			  GenMatch_WJetsRegion_MuPt->Fill(l1.Pt(),NormalizationWeight);
			  GenMatch_WJetsRegion_TauPt->Fill(l2.Pt(),NormalizationWeight);
			  GenMatch_WJetsRegion_MuEta->Fill(l1.Eta(),NormalizationWeight);
			  GenMatch_WJetsRegion_TauEta->Fill(l2.Eta(),NormalizationWeight);
			  GenMatch_WJetsRegion_NJets->Fill(njets,NormalizationWeight);
			  GenMatch_WJetsRegion_NBtag->Fill(nbtag,NormalizationWeight);
			  GenMatch_WJetsRegion_ZMass->Fill((l1+l2).M(),NormalizationWeight);
			  GenMatch_WJetsRegion_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
			  GenMatch_WJetsRegion_MT->Fill(TransverseMass,NormalizationWeight);
			}
		      if(gen_match_2 == 6) 
			{
			  HighGenMatch_WJetsRegion_Pass->Fill(Var,NormalizationWeight);

			  HighGenMatch_WJetsRegion_MuPt->Fill(l1.Pt(),NormalizationWeight);
			  HighGenMatch_WJetsRegion_TauPt->Fill(l2.Pt(),NormalizationWeight);
			  HighGenMatch_WJetsRegion_MuEta->Fill(l1.Eta(),NormalizationWeight);
			  HighGenMatch_WJetsRegion_TauEta->Fill(l2.Eta(),NormalizationWeight);
			  HighGenMatch_WJetsRegion_NJets->Fill(njets,NormalizationWeight);
			  HighGenMatch_WJetsRegion_NBtag->Fill(nbtag,NormalizationWeight);
			  HighGenMatch_WJetsRegion_ZMass->Fill((l1+l2).M(),NormalizationWeight);
			  HighGenMatch_WJetsRegion_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
			  HighGenMatch_WJetsRegion_MT->Fill(TransverseMass,NormalizationWeight);
			}
		    }
		  //Literally everything else
		  {
		    WJetsRegion_Pass->Fill(Var,NormalizationWeight);
		    
		    WJetsRegion_MuPt->Fill(l1.Pt(),NormalizationWeight);
		    WJetsRegion_TauPt->Fill(l2.Pt(),NormalizationWeight);
		    WJetsRegion_MuEta->Fill(l1.Eta(),NormalizationWeight);
		    WJetsRegion_TauEta->Fill(l2.Eta(),NormalizationWeight);
		    WJetsRegion_NJets->Fill(njets,NormalizationWeight);
		    WJetsRegion_NBtag->Fill(nbtag,NormalizationWeight);
		    WJetsRegion_ZMass->Fill((l1+l2).M(),NormalizationWeight);
		    WJetsRegion_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
		    WJetsRegion_MT->Fill(TransverseMass,NormalizationWeight);
		  }
		}
	      else
		{		  
		  //seperate out the Z->tau tau stuff
		  if(input == "DY"
		     or input == "DY1"
		     or input == "DY2"
		     or input == "DY3"
		     or input == "DY4")
		    {
		      if(gen_match_2 < 5) LowGenMatch_WJetsRegion_Fail->Fill(Var,NormalizationWeight);
		      if(gen_match_2 == 5) GenMatch_WJetsRegion_Fail->Fill(Var,NormalizationWeight);
		      if(gen_match_2 == 6) HighGenMatch_WJetsRegion_Fail->Fill(Var,NormalizationWeight);
		    }
		  //Literally everything else
		  else
		    {
		      WJetsRegion_Fail->Fill(Var,NormalizationWeight);
		    }
		}
	    }
	}
      //same sign is QCD
      else if(q_1 * q_2 > 0.0)
	{
	  //QCD in the signal region
	  //changed the mt cut to 50 to match diego, instead of my original 40	  
	  if(TransverseMass < 50.0 and PZeta > -25.0)
	    {
	      if(TauIsoDiscrim)
		{		  
		  AcceptedQCDEvents++;
		  //seperate out the Z->tautau stuff
		  if(input == "DY"
		     or input == "DY1"
		     or input == "DY2"
		     or input == "DY3"
		     or input == "DY4")
		    {
		      if(gen_match_2 < 5) 
			{
			  LowGenMatch_QCDRegion_Pass->Fill(Var,NormalizationWeight);
			  
			  LowGenMatch_QCDRegion_MuPt->Fill(l1.Pt(),NormalizationWeight);
			  LowGenMatch_QCDRegion_TauPt->Fill(l2.Pt(),NormalizationWeight);
			  LowGenMatch_QCDRegion_MuEta->Fill(l1.Eta(),NormalizationWeight);
			  LowGenMatch_QCDRegion_TauEta->Fill(l2.Eta(),NormalizationWeight);
			  LowGenMatch_QCDRegion_NJets->Fill(njets,NormalizationWeight);
			  LowGenMatch_QCDRegion_NBtag->Fill(nbtag,NormalizationWeight);
			  LowGenMatch_QCDRegion_ZMass->Fill((l1+l2).M(),NormalizationWeight);
			  LowGenMatch_QCDRegion_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
			  LowGenMatch_QCDRegion_MT->Fill(TransverseMass,NormalizationWeight);
			}
		      if(gen_match_2 == 5)
			{
			  GenMatch_QCDRegion_Pass->Fill(Var,NormalizationWeight);
			  
			  GenMatch_QCDRegion_MuPt->Fill(l1.Pt(),NormalizationWeight);
			  GenMatch_QCDRegion_TauPt->Fill(l2.Pt(),NormalizationWeight);
			  GenMatch_QCDRegion_MuEta->Fill(l1.Eta(),NormalizationWeight);
			  GenMatch_QCDRegion_TauEta->Fill(l2.Eta(),NormalizationWeight);
			  GenMatch_QCDRegion_NJets->Fill(njets,NormalizationWeight);
			  GenMatch_QCDRegion_NBtag->Fill(nbtag,NormalizationWeight);
			  GenMatch_QCDRegion_ZMass->Fill((l1+l2).M(),NormalizationWeight);
			  GenMatch_QCDRegion_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
			  GenMatch_QCDRegion_MT->Fill(TransverseMass,NormalizationWeight);
			}
		      if(gen_match_2 == 6) 
			{
			  HighGenMatch_QCDRegion_Pass->Fill(Var,NormalizationWeight);
			  
			  HighGenMatch_QCDRegion_MuPt->Fill(l1.Pt(),NormalizationWeight);
			  HighGenMatch_QCDRegion_TauPt->Fill(l2.Pt(),NormalizationWeight);
			  HighGenMatch_QCDRegion_MuEta->Fill(l1.Eta(),NormalizationWeight);
			  HighGenMatch_QCDRegion_TauEta->Fill(l2.Eta(),NormalizationWeight);
			  HighGenMatch_QCDRegion_NJets->Fill(njets,NormalizationWeight);
			  HighGenMatch_QCDRegion_NBtag->Fill(nbtag,NormalizationWeight);
			  HighGenMatch_QCDRegion_ZMass->Fill((l1+l2).M(),NormalizationWeight);
			  HighGenMatch_QCDRegion_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
			  HighGenMatch_QCDRegion_MT->Fill(TransverseMass,NormalizationWeight);
			}
		    }
		  else
		    {
		      QCDRegion_Pass->Fill(Var,NormalizationWeight);
		      
		      QCDRegion_MuPt->Fill(l1.Pt(),NormalizationWeight);
		      QCDRegion_TauPt->Fill(l2.Pt(),NormalizationWeight);
		      QCDRegion_MuEta->Fill(l1.Eta(),NormalizationWeight);
		      QCDRegion_TauEta->Fill(l2.Eta(),NormalizationWeight);
		      QCDRegion_NJets->Fill(njets,NormalizationWeight);
		      QCDRegion_NBtag->Fill(nbtag,NormalizationWeight);
		      QCDRegion_ZMass->Fill((l1+l2).M(),NormalizationWeight);
		      QCDRegion_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
		      QCDRegion_MT->Fill(TransverseMass,NormalizationWeight);
		    }
		}
	      else
		{		  
		  //seperate out the Z->tau tau stuff
		  if((input == "DY"
		      or input == "DY1"
		      or input == "DY2"
		      or input == "DY3"
		      or input == "DY4") and gen_match_2 <= 6)
		    {
		      if(gen_match_2 < 5) LowGenMatch_QCDRegion_Fail->Fill(Var,NormalizationWeight);
		      if(gen_match_2 == 5) GenMatch_QCDRegion_Fail->Fill(Var,NormalizationWeight);
		      if(gen_match_2 == 6) HighGenMatch_QCDRegion_Fail->Fill(Var,NormalizationWeight);
		    }
		  //Literally Everything Else
		  else
		    {
		      QCDRegion_Fail->Fill(Var,NormalizationWeight);
		    }
		}
	    }
	  //QCD present in the W+Jets estimation region
	  if(TransverseMass > 80.0)
	    {
	      if(TauIsoDiscrim)
		{	
		  //QCD WJets mixed region
		  AcceptedQCDWJetsEvents++;
		  //Seperate out the Z->tautau stuff
		  if(input == "DY"
		     or input == "DY1"
		     or input == "DY2"
		     or input == "DY3"
		     or input == "DY4")
		    {
		      if(gen_match_2 < 5) 
			{
			  LowGenMatch_QCDinWJets_Pass->Fill(Var,NormalizationWeight);    

			  LowGenMatch_QCDinWJets_MuPt->Fill(l1.Pt(),NormalizationWeight);
			  LowGenMatch_QCDinWJets_TauPt->Fill(l2.Pt(),NormalizationWeight);
			  LowGenMatch_QCDinWJets_MuEta->Fill(l1.Eta(),NormalizationWeight);
			  LowGenMatch_QCDinWJets_TauEta->Fill(l2.Eta(),NormalizationWeight);
			  LowGenMatch_QCDinWJets_NJets->Fill(njets,NormalizationWeight);
			  LowGenMatch_QCDinWJets_NBtag->Fill(nbtag,NormalizationWeight);
			  LowGenMatch_QCDinWJets_ZMass->Fill((l1+l2).M(),NormalizationWeight);
			  LowGenMatch_QCDinWJets_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
			  LowGenMatch_QCDinWJets_MT->Fill(TransverseMass,NormalizationWeight);
			}
		      if(gen_match_2 == 5) 
			{
			  GenMatch_QCDinWJets_Pass->Fill(Var,NormalizationWeight);    

			  GenMatch_QCDinWJets_MuPt->Fill(l1.Pt(),NormalizationWeight);
			  GenMatch_QCDinWJets_TauPt->Fill(l2.Pt(),NormalizationWeight);
			  GenMatch_QCDinWJets_MuEta->Fill(l1.Eta(),NormalizationWeight);
			  GenMatch_QCDinWJets_TauEta->Fill(l2.Eta(),NormalizationWeight);
			  GenMatch_QCDinWJets_NJets->Fill(njets,NormalizationWeight);
			  GenMatch_QCDinWJets_NBtag->Fill(nbtag,NormalizationWeight);
			  GenMatch_QCDinWJets_ZMass->Fill((l1+l2).M(),NormalizationWeight);
			  GenMatch_QCDinWJets_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
			  GenMatch_QCDinWJets_MT->Fill(TransverseMass,NormalizationWeight);
			}
		      if(gen_match_2 == 6) 
			{
			  HighGenMatch_QCDinWJets_Pass->Fill(Var,NormalizationWeight);    
			  
			  HighGenMatch_QCDinWJets_MuPt->Fill(l1.Pt(),NormalizationWeight);
			  HighGenMatch_QCDinWJets_TauPt->Fill(l2.Pt(),NormalizationWeight);
			  HighGenMatch_QCDinWJets_MuEta->Fill(l1.Eta(),NormalizationWeight);
			  HighGenMatch_QCDinWJets_TauEta->Fill(l2.Eta(),NormalizationWeight);
			  HighGenMatch_QCDinWJets_NJets->Fill(njets,NormalizationWeight);
			  HighGenMatch_QCDinWJets_NBtag->Fill(nbtag,NormalizationWeight);
			  HighGenMatch_QCDinWJets_ZMass->Fill((l1+l2).M(),NormalizationWeight);
			  HighGenMatch_QCDinWJets_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
			  HighGenMatch_QCDinWJets_MT->Fill(TransverseMass,NormalizationWeight);
			}
		    }
		  //Literally everything else
		  else
		    {
		      QCDinWJets_Pass->Fill(Var,NormalizationWeight);    

		      QCDinWJets_MuPt->Fill(l1.Pt(),NormalizationWeight);
		      QCDinWJets_TauPt->Fill(l2.Pt(),NormalizationWeight);
		      QCDinWJets_MuEta->Fill(l1.Eta(),NormalizationWeight);
		      QCDinWJets_TauEta->Fill(l2.Eta(),NormalizationWeight);
		      QCDinWJets_NJets->Fill(njets,NormalizationWeight);
		      QCDinWJets_NBtag->Fill(nbtag,NormalizationWeight);
		      QCDinWJets_ZMass->Fill((l1+l2).M(),NormalizationWeight);
		      QCDinWJets_ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
		      QCDinWJets_MT->Fill(TransverseMass,NormalizationWeight);
		    }
		}
	      else
		{
		  //Seperate out the Z->tautau signal
		  if(input == "DY"
		     or input == "DY1"
		     or input == "DY2"
		     or input == "DY3"
		     or input == "DY4")
		    {
		      if(gen_match_2 < 5) LowGenMatch_QCDinWJets_Fail->Fill(Var,NormalizationWeight);
		      if(gen_match_2 == 5) GenMatch_QCDinWJets_Fail->Fill(Var,NormalizationWeight);
		      if(gen_match_2 == 6) HighGenMatch_QCDinWJets_Fail->Fill(Var,NormalizationWeight);
		    }
		  //Literally everything else
		  else
		    {
		      QCDinWJets_Fail->Fill(Var,NormalizationWeight);
		    }
		} 
	    }
	}            
    }
  
  std::cout<<std::endl;    
  std::cout<<"Accepted Signal Events: "<<AcceptedSignalEvents<<std::endl;
  std::cout<<"Accepted WJets Events: "<<AcceptedWJetsEvents<<std::endl;
  std::cout<<"Accepted QCD Events: "<<AcceptedQCDEvents<<std::endl;
  std::cout<<"Accepted WJets/QCD Events: "<<AcceptedQCDWJetsEvents<<std::endl;
  std::cout<<"Average Weight: "<<AverageWeight/AcceptedEvents<<std::endl;

  //save signal distributions
  TFile* SignalOutFile = new TFile(("TemporaryFiles/Signal_"+name+"_PassFail.root").c_str(),"RECREATE");

  TDirectory *SignalPassDir = SignalOutFile->mkdir("pass");
  SignalPassDir->cd();
  SignalRegion_Pass->Write();

  TDirectory *SignalFailDir = SignalOutFile->mkdir("fail");
  SignalFailDir->cd();
  SignalRegion_Fail->Write();
  
  //add in a control directory
  TDirectory * SignalControlDir = SignalOutFile->mkdir("control");
  SignalControlDir->cd();
  SignalRegion_MuPt->Write();
  SignalRegion_TauPt->Write();
  SignalRegion_MuEta->Write();
  SignalRegion_TauEta->Write();
  SignalRegion_NJets->Write();
  SignalRegion_NBtag->Write();
  SignalRegion_ZMass->Write();
  SignalRegion_ZPT->Write();
  SignalRegion_MT->Write();

  SignalOutFile->Close();

  //save WJets distributions
  TFile* WJetsOutFile = new TFile(("TemporaryFiles/WJets_"+name+"_PassFail.root").c_str(),"RECREATE");

  TDirectory *WJetsPassDir = WJetsOutFile->mkdir("pass");
  WJetsPassDir->cd();
  WJetsRegion_Pass->Write();

  TDirectory *WJetsFailDir = WJetsOutFile->mkdir("fail");
  WJetsFailDir->cd();
  WJetsRegion_Fail->Write();

  TDirectory * WJetsControlDir = WJetsOutFile->mkdir("control");
  WJetsControlDir->cd();
  WJetsRegion_MuPt->Write();
  WJetsRegion_TauPt->Write();
  WJetsRegion_MuEta->Write();
  WJetsRegion_TauEta->Write();
  WJetsRegion_NJets->Write();
  WJetsRegion_NBtag->Write();
  WJetsRegion_ZMass->Write();
  WJetsRegion_ZPT->Write();
  WJetsRegion_MT->Write();

  WJetsOutFile->Close();

  //save QCD distributions
  TFile* QCDOutFile = new TFile(("TemporaryFiles/QCD_"+name+"_PassFail.root").c_str(),"RECREATE");

  TDirectory *QCDPassDir = QCDOutFile->mkdir("pass");
  QCDPassDir->cd();
  QCDRegion_Pass->Write();

  TDirectory *QCDFailDir = QCDOutFile->mkdir("fail");
  QCDFailDir->cd();
  QCDRegion_Fail->Write();

  TDirectory * QCDRegionControlDir = QCDOutFile->mkdir("control");
  QCDRegionControlDir->cd();
  QCDRegion_MuPt->Write();
  QCDRegion_TauPt->Write();
  QCDRegion_MuEta->Write();
  QCDRegion_TauEta->Write();
  QCDRegion_NJets->Write();
  QCDRegion_NBtag->Write();
  QCDRegion_ZMass->Write();
  QCDRegion_ZPT->Write();
  QCDRegion_MT->Write();
  
  QCDOutFile->Close();

  //save the QCD Wjets contribution
  TFile* QCDinWJetsOutFile = new TFile(("TemporaryFiles/QCDinWJets_"+name+"PassFail.root").c_str(),"RECREATE");

  TDirectory *QCDinWJetsPassDir = QCDinWJetsOutFile->mkdir("pass");
  QCDinWJetsPassDir->cd();
  QCDinWJets_Pass->Write();

  TDirectory *QCDinWJetsFailDir = QCDinWJetsOutFile->mkdir("fail");
  QCDinWJetsFailDir->cd();
  QCDinWJets_Fail->Write();

  TDirectory * QCDinWJetsControlDir = QCDinWJetsOutFile->mkdir("control");
  QCDinWJetsControlDir->cd();
  QCDinWJets_MuPt->Write();
  QCDinWJets_TauPt->Write();
  QCDinWJets_MuEta->Write();
  QCDinWJets_TauEta->Write();
  QCDinWJets_NJets->Write();
  QCDinWJets_NBtag->Write();
  QCDinWJets_ZMass->Write();
  QCDinWJets_ZPT->Write();
  QCDinWJets_MT->Write();
  
  QCDinWJetsOutFile->Close();

  //if we are in the drell yan we need to write out the signal files also.
  if(input == "DY"
      or input == "DY1"
      or input == "DY2"
      or input == "DY3"
      or input == "DY4")
    {
      //for genmatch == 5
      TFile* GenMatchedSignalOutFile = new TFile(("TemporaryFiles/Signal_GenMatch_"+name+"_Passfail.root").c_str(),"RECREATE");
      
      TDirectory *GenMatchSignalPassDir = GenMatchedSignalOutFile->mkdir("pass");
      GenMatchSignalPassDir->cd();
      GenMatch_SignalRegion_Pass->Write();
      GenMatch_SignalRegion_DM0Mod_Pass->Write();
      GenMatch_SignalRegion_DM1Mod_Pass->Write();
      GenMatch_SignalRegion_DM10Mod_Pass->Write();
      
      TDirectory *GenMatchSignalFailDir = GenMatchedSignalOutFile->mkdir("fail");
      GenMatchSignalFailDir->cd();
      GenMatch_SignalRegion_Fail->Write();

      //add in a control region
      TDirectory * GenMatchControlDir = GenMatchedSignalOutFile->mkdir("control");
      GenMatchControlDir->cd();
      GenMatch_SignalRegion_MuPt->Write();
      GenMatch_SignalRegion_TauPt->Write();
      GenMatch_SignalRegion_MuEta->Write();
      GenMatch_SignalRegion_TauEta->Write();
      GenMatch_SignalRegion_NJets->Write();
      GenMatch_SignalRegion_NBtag->Write();
      GenMatch_SignalRegion_ZMass->Write();
      GenMatch_SignalRegion_ZPT->Write();
      GenMatch_SignalRegion_MT->Write();
      
      GenMatchedSignalOutFile->Close();
      
      //save WJets distributions
      TFile* GenMatchedWJetsOutFile = new TFile(("TemporaryFiles/WJets_GenMatch_"+name+"_PassFail.root").c_str(),"RECREATE");
      
      TDirectory *GenMatchWJetsPassDir = GenMatchedWJetsOutFile->mkdir("pass");
      GenMatchWJetsPassDir->cd();
      GenMatch_WJetsRegion_Pass->Write();
      
      TDirectory *GenMatchWJetsFailDir = GenMatchedWJetsOutFile->mkdir("fail");
      GenMatchWJetsFailDir->cd();
      GenMatch_WJetsRegion_Fail->Write();
      
      TDirectory * GenMatchWJetsControlDir = GenMatchedWJetsOutFile->mkdir("control");
      GenMatchWJetsControlDir->cd();
      GenMatch_WJetsRegion_MuPt->Write();
      GenMatch_WJetsRegion_TauPt->Write();
      GenMatch_WJetsRegion_MuEta->Write();
      GenMatch_WJetsRegion_TauEta->Write();
      GenMatch_WJetsRegion_NJets->Write();
      GenMatch_WJetsRegion_NBtag->Write();
      GenMatch_WJetsRegion_ZMass->Write();
      GenMatch_WJetsRegion_ZPT->Write();
      GenMatch_WJetsRegion_MT->Write();

      GenMatchedWJetsOutFile->Close();
      
      //save QCD distributions
      TFile* GenMatchedQCDOutFile = new TFile(("TemporaryFiles/QCD_GenMatch_"+name+"_PassFail.root").c_str(),"RECREATE");
      
      TDirectory *GenMatchQCDPassDir = GenMatchedQCDOutFile->mkdir("pass");
      GenMatchQCDPassDir->cd();
      GenMatch_QCDRegion_Pass->Write();
      
      TDirectory *GenMatchQCDFailDir = GenMatchedQCDOutFile->mkdir("fail");
      GenMatchQCDFailDir->cd();
      GenMatch_QCDRegion_Fail->Write();

      TDirectory *GenMatchQCDControlDir = GenMatchedQCDOutFile->mkdir("control");
      GenMatchQCDControlDir->cd();
      GenMatch_QCDRegion_MuPt->Write();
      GenMatch_QCDRegion_TauPt->Write();
      GenMatch_QCDRegion_MuEta->Write();
      GenMatch_QCDRegion_TauEta->Write();
      GenMatch_QCDRegion_NJets->Write();
      GenMatch_QCDRegion_NBtag->Write();
      GenMatch_QCDRegion_ZMass->Write();
      GenMatch_QCDRegion_ZPT->Write();
      GenMatch_QCDRegion_MT->Write();
      
      GenMatchedQCDOutFile->Close();
      
      //save the QCD Wjets contribution
      TFile* GenMatchedQCDinWJetsOutFile = new TFile(("TemporaryFiles/QCDinWJets_GenMatch_"+name+"PassFail.root").c_str(),"RECREATE");
      
      TDirectory *GenMatchQCDinWJetsPassDir = GenMatchedQCDinWJetsOutFile->mkdir("pass");
      GenMatchQCDinWJetsPassDir->cd();
      GenMatch_QCDinWJets_Pass->Write();
      
      TDirectory *GenMatchQCDinWJetsFailDir = GenMatchedQCDinWJetsOutFile->mkdir("fail");
      GenMatchQCDinWJetsFailDir->cd();
      GenMatch_QCDinWJets_Fail->Write();

      TDirectory *GenMatchQCDinWJetsControlDir = GenMatchedQCDinWJetsOutFile->mkdir("control");
      GenMatchQCDinWJetsControlDir->cd();
      GenMatch_QCDinWJets_MuPt->Write();
      GenMatch_QCDinWJets_TauPt->Write();
      GenMatch_QCDinWJets_MuEta->Write();
      GenMatch_QCDinWJets_TauEta->Write();
      GenMatch_QCDinWJets_NJets->Write();
      GenMatch_QCDinWJets_NBtag->Write();
      GenMatch_QCDinWJets_ZMass->Write();
      GenMatch_QCDinWJets_ZPT->Write();
      GenMatch_QCDinWJets_MT->Write();
      
      GenMatchedQCDinWJetsOutFile->Close();

      //For genmatch < 5
      TFile* LowGenMatchedSignalOutFile = new TFile(("TemporaryFiles/Signal_LowGenMatch_"+name+"_Passfail.root").c_str(),"RECREATE");
      
      TDirectory *LowGenMatchSignalPassDir = LowGenMatchedSignalOutFile->mkdir("pass");
      LowGenMatchSignalPassDir->cd();
      LowGenMatch_SignalRegion_Pass->Write();
      
      TDirectory *LowGenMatchSignalFailDir = LowGenMatchedSignalOutFile->mkdir("fail");
      LowGenMatchSignalFailDir->cd();
      LowGenMatch_SignalRegion_Fail->Write();

      //add in a control region
      TDirectory * LowGenMatchControlDir = LowGenMatchedSignalOutFile->mkdir("control");
      LowGenMatchControlDir->cd();
      LowGenMatch_SignalRegion_MuPt->Write();
      LowGenMatch_SignalRegion_TauPt->Write();
      LowGenMatch_SignalRegion_MuEta->Write();
      LowGenMatch_SignalRegion_TauEta->Write();
      LowGenMatch_SignalRegion_NJets->Write();
      LowGenMatch_SignalRegion_NBtag->Write();
      LowGenMatch_SignalRegion_ZMass->Write();
      LowGenMatch_SignalRegion_ZPT->Write();
      LowGenMatch_SignalRegion_MT->Write();
      
      LowGenMatchedSignalOutFile->Close();
      
      //save WJets distributions
      TFile* LowGenMatchedWJetsOutFile = new TFile(("TemporaryFiles/WJets_LowGenMatch_"+name+"_PassFail.root").c_str(),"RECREATE");
      
      TDirectory *LowGenMatchWJetsPassDir = LowGenMatchedWJetsOutFile->mkdir("pass");
      LowGenMatchWJetsPassDir->cd();
      LowGenMatch_WJetsRegion_Pass->Write();
      
      TDirectory *LowGenMatchWJetsFailDir = LowGenMatchedWJetsOutFile->mkdir("fail");
      LowGenMatchWJetsFailDir->cd();
      LowGenMatch_WJetsRegion_Fail->Write();

      TDirectory * LowGenMatchWJetsControlDir = LowGenMatchedWJetsOutFile->mkdir("control");
      LowGenMatchWJetsControlDir->cd();
      LowGenMatch_WJetsRegion_MuPt->Write();
      LowGenMatch_WJetsRegion_TauPt->Write();
      LowGenMatch_WJetsRegion_MuEta->Write();
      LowGenMatch_WJetsRegion_TauEta->Write();
      LowGenMatch_WJetsRegion_NJets->Write();
      LowGenMatch_WJetsRegion_NBtag->Write();
      LowGenMatch_WJetsRegion_ZMass->Write();
      LowGenMatch_WJetsRegion_ZPT->Write();
      LowGenMatch_WJetsRegion_MT->Write();
      
      LowGenMatchedWJetsOutFile->Close();
      
      //save QCD distributions
      TFile* LowGenMatchedQCDOutFile = new TFile(("TemporaryFiles/QCD_LowGenMatch_"+name+"_PassFail.root").c_str(),"RECREATE");
      
      TDirectory *LowGenMatchQCDPassDir = LowGenMatchedQCDOutFile->mkdir("pass");
      LowGenMatchQCDPassDir->cd();
      LowGenMatch_QCDRegion_Pass->Write();
      
      TDirectory *LowGenMatchQCDFailDir = LowGenMatchedQCDOutFile->mkdir("fail");
      LowGenMatchQCDFailDir->cd();
      LowGenMatch_QCDRegion_Fail->Write();

      TDirectory * LowGenMatchQCDControlDir = LowGenMatchedQCDOutFile->mkdir("control");
      LowGenMatchQCDControlDir->cd();
      LowGenMatch_QCDRegion_MuPt->Write();
      LowGenMatch_QCDRegion_TauPt->Write();
      LowGenMatch_QCDRegion_MuEta->Write();
      LowGenMatch_QCDRegion_TauEta->Write();
      LowGenMatch_QCDRegion_NJets->Write();
      LowGenMatch_QCDRegion_NBtag->Write();
      LowGenMatch_QCDRegion_ZMass->Write();
      LowGenMatch_QCDRegion_ZPT->Write();
      LowGenMatch_QCDRegion_MT->Write();
      
      LowGenMatchedQCDOutFile->Close();
      
      //save the QCD Wjets contribution
      TFile* LowGenMatchedQCDinWJetsOutFile = new TFile(("TemporaryFiles/QCDinWJets_LowGenMatch_"+name+"PassFail.root").c_str(),"RECREATE");
      
      TDirectory *LowGenMatchQCDinWJetsPassDir = LowGenMatchedQCDinWJetsOutFile->mkdir("pass");
      LowGenMatchQCDinWJetsPassDir->cd();
      LowGenMatch_QCDinWJets_Pass->Write();
      
      TDirectory *LowGenMatchQCDinWJetsFailDir = LowGenMatchedQCDinWJetsOutFile->mkdir("fail");
      LowGenMatchQCDinWJetsFailDir->cd();
      LowGenMatch_QCDinWJets_Fail->Write();

      TDirectory * LowGenMatchQCDinWJetsControlDir = LowGenMatchedQCDinWJetsOutFile->mkdir("control");
      LowGenMatchQCDinWJetsControlDir->cd();
      LowGenMatch_QCDinWJets_MuPt->Write();
      LowGenMatch_QCDinWJets_TauPt->Write();
      LowGenMatch_QCDinWJets_MuEta->Write();
      LowGenMatch_QCDinWJets_TauEta->Write();
      LowGenMatch_QCDinWJets_NJets->Write();
      LowGenMatch_QCDinWJets_NBtag->Write();
      LowGenMatch_QCDinWJets_ZMass->Write();
      LowGenMatch_QCDinWJets_ZPT->Write();
      LowGenMatch_QCDinWJets_MT->Write();
      
      LowGenMatchedQCDinWJetsOutFile->Close();

      //For genmatch == 6
      TFile* HighGenMatchedSignalOutFile = new TFile(("TemporaryFiles/Signal_HighGenMatch_"+name+"_Passfail.root").c_str(),"RECREATE");
      
      TDirectory *HighGenMatchSignalPassDir = HighGenMatchedSignalOutFile->mkdir("pass");
      HighGenMatchSignalPassDir->cd();
      HighGenMatch_SignalRegion_Pass->Write();
      
      TDirectory *HighGenMatchSignalFailDir = HighGenMatchedSignalOutFile->mkdir("fail");
      HighGenMatchSignalFailDir->cd();
      HighGenMatch_SignalRegion_Fail->Write();

      //add in a control region
      TDirectory * HighGenMatchControlDir = HighGenMatchedSignalOutFile->mkdir("control");
      HighGenMatchControlDir->cd();
      HighGenMatch_SignalRegion_MuPt->Write();
      HighGenMatch_SignalRegion_TauPt->Write();
      HighGenMatch_SignalRegion_MuEta->Write();
      HighGenMatch_SignalRegion_TauEta->Write();
      HighGenMatch_SignalRegion_NJets->Write();
      HighGenMatch_SignalRegion_NBtag->Write();
      HighGenMatch_SignalRegion_ZMass->Write();
      HighGenMatch_SignalRegion_ZPT->Write();
      HighGenMatch_SignalRegion_MT->Write();
      
      HighGenMatchedSignalOutFile->Close();
      
      //save WJets distributions
      TFile* HighGenMatchedWJetsOutFile = new TFile(("TemporaryFiles/WJets_HighGenMatch_"+name+"_PassFail.root").c_str(),"RECREATE");
      
      TDirectory *HighGenMatchWJetsPassDir = HighGenMatchedWJetsOutFile->mkdir("pass");
      HighGenMatchWJetsPassDir->cd();
      HighGenMatch_WJetsRegion_Pass->Write();
      
      TDirectory *HighGenMatchWJetsFailDir = HighGenMatchedWJetsOutFile->mkdir("fail");
      HighGenMatchWJetsFailDir->cd();
      HighGenMatch_WJetsRegion_Fail->Write();
      
      TDirectory * HighGenMatchWJetsControlDir = HighGenMatchedWJetsOutFile->mkdir("control");
      HighGenMatchWJetsControlDir->cd();
      HighGenMatch_WJetsRegion_MuPt->Write();
      HighGenMatch_WJetsRegion_TauPt->Write();
      HighGenMatch_WJetsRegion_MuEta->Write();
      HighGenMatch_WJetsRegion_TauEta->Write();
      HighGenMatch_WJetsRegion_NJets->Write();
      HighGenMatch_WJetsRegion_NBtag->Write();
      HighGenMatch_WJetsRegion_ZMass->Write();
      HighGenMatch_WJetsRegion_ZPT->Write();
      HighGenMatch_WJetsRegion_MT->Write();

      HighGenMatchedWJetsOutFile->Close();
      
      //save QCD distributions
      TFile* HighGenMatchedQCDOutFile = new TFile(("TemporaryFiles/QCD_HighGenMatch_"+name+"_PassFail.root").c_str(),"RECREATE");
      
      TDirectory *HighGenMatchQCDPassDir = HighGenMatchedQCDOutFile->mkdir("pass");
      HighGenMatchQCDPassDir->cd();
      HighGenMatch_QCDRegion_Pass->Write();
      
      TDirectory *HighGenMatchQCDFailDir = HighGenMatchedQCDOutFile->mkdir("fail");
      HighGenMatchQCDFailDir->cd();
      HighGenMatch_QCDRegion_Fail->Write();

      TDirectory * HighGenMatchQCDControlDir = HighGenMatchedQCDOutFile->mkdir("control");
      HighGenMatchQCDControlDir->cd();
      HighGenMatch_QCDRegion_MuPt->Write();
      HighGenMatch_QCDRegion_TauPt->Write();
      HighGenMatch_QCDRegion_MuEta->Write();
      HighGenMatch_QCDRegion_TauEta->Write();
      HighGenMatch_QCDRegion_NJets->Write();
      HighGenMatch_QCDRegion_NBtag->Write();
      HighGenMatch_QCDRegion_ZMass->Write();
      HighGenMatch_QCDRegion_ZPT->Write();
      HighGenMatch_QCDRegion_MT->Write();
      
      HighGenMatchedQCDOutFile->Close();
      
      //save the QCD Wjets contribution
      TFile* HighGenMatchedQCDinWJetsOutFile = new TFile(("TemporaryFiles/QCDinWJets_HighGenMatch_"+name+"PassFail.root").c_str(),"RECREATE");
      
      TDirectory *HighGenMatchQCDinWJetsPassDir = HighGenMatchedQCDinWJetsOutFile->mkdir("pass");
      HighGenMatchQCDinWJetsPassDir->cd();
      HighGenMatch_QCDinWJets_Pass->Write();
      
      TDirectory *HighGenMatchQCDinWJetsFailDir = HighGenMatchedQCDinWJetsOutFile->mkdir("fail");
      HighGenMatchQCDinWJetsFailDir->cd();
      HighGenMatch_QCDinWJets_Fail->Write();

      TDirectory * HighGenMatchQCDinWJetsControlDir = HighGenMatchedQCDinWJetsOutFile->mkdir("control");
      HighGenMatchQCDinWJetsControlDir->cd();
      HighGenMatch_QCDinWJets_MuPt->Write();
      HighGenMatch_QCDinWJets_TauPt->Write();
      HighGenMatch_QCDinWJets_MuEta->Write();
      HighGenMatch_QCDinWJets_TauEta->Write();
      HighGenMatch_QCDinWJets_NJets->Write();
      HighGenMatch_QCDinWJets_NBtag->Write();
      HighGenMatch_QCDinWJets_ZMass->Write();
      HighGenMatch_QCDinWJets_ZPT->Write();
      HighGenMatch_QCDinWJets_MT->Write();
      
      HighGenMatchedQCDinWJetsOutFile->Close();
    }

  

  SyncFile->cd();
  SyncTree->Write();
  SyncFile->Write();
  SyncFile->Close();
  
}
