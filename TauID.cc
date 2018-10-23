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

void TauID(std::string input, string IsoWorkingPoint,float ShapeUncertainty = 1.0)
{
  //get the tree that we're going to run
  TFile *MyFile = new TFile(("/data/ccaillol/tauid_20june_mt/"+input+".root").c_str());
  TTree *Tree = (TTree*) MyFile->Get("mutau_tree");
  TH1F* nevents = (TH1F*) MyFile->Get("nevents");
  float TotalNumberOfEvents = nevents->GetBinContent(1);
  
  //Variables for the tree branches
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
				     20,
				     50.0,
				     150.0);
  TH1F* GenMatch_SignalRegion_Fail = new TH1F(("GenMatch_"+name+"_Fail").c_str(),
				     "Signal_Fail",
				     20,
				     50.0,
				     150.0);

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
				     20,
				     50.0,
				     150.0);
  TH1F* LowGenMatch_SignalRegion_Fail = new TH1F(("LowGenMatch_"+name+"_Fail").c_str(),
				     "Signal_Fail",
				     20,
				     50.0,
				     150.0);

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
				     20,
				     50.0,
				     150.0);
  TH1F* HighGenMatch_SignalRegion_Fail = new TH1F(("HighGenMatch_"+name+"_Fail").c_str(),
				     "Signal_Fail",
				     20,
				     50.0,
				     150.0);

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
  else if(input == "DY") XSecWeight = LHCLumi * 5765.4e-12 / TotalNumberOfEvents;
  else if(input == "Data") XSecWeight = 1.0;
  //additional cross section weights taken from the excel file.
  else if(input == "DY1") XSecWeight = LHCLumi * 1178.29e-12 /TotalNumberOfEvents;
  else if(input == "DY2") XSecWeight = LHCLumi * 387.34e-12 /TotalNumberOfEvents;
  else if(input == "DY3") XSecWeight = LHCLumi * 118.429e-12 /TotalNumberOfEvents;
  else if(input == "DY4") XSecWeight = LHCLumi * 63.73e-12 /TotalNumberOfEvents;
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
  LumiWeights_12 = new reweight::LumiReWeighting(("/data/ccaillol/tauid_20june_mt/"+input+".root").c_str(),
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
      TLorentzVector l1; l1.SetPtEtaPhiE(pt_1, eta_1, phi_1, e_1); //muon
      TLorentzVector l2; l2.SetPtEtaPhiE(pt_2, eta_2, phi_2, e_2); //tau
      //Handle the TES and Muon shape uncertainty
      l2 = l2*ShapeUncertainty;

      //Event selection
      //muon criteria     
      //CHanged to Match Diego's pt > 30 cut, as opposed to my original > 29 cut
      if(pt_1 < 30.0 or std::abs(eta_1) > 2.4 or !id_m_medium_1 or iso_1 > 0.15 or std::abs(dZ_1) > 0.2 or std::abs(d0_1) > 0.045 or !matchIsoMu27_1) continue;      
      
      //tau criteria
      //
      if(pt_2 < 20.0  or std::abs(eta_2) > 2.3 or againstElectronVLooseMVA6_2 != 1 or againstMuonTight3_2 != 1 or !decayModeFinding_2 /*or std::abs(dZ_2) > 0.2*/) continue;
      //EventsPassingTauSelection+=1.0;            

      //hacked in brief way to examine pt/eta brackets.
      //if( pt_2 < 50.0) continue;

      //pair criteria            
      float deltaphi = std::abs(phi_1-phi_2);
      if (deltaphi > M_PI) deltaphi-=2.0*M_PI;
      float DeltaR = std::sqrt((eta_1-eta_2)*(eta_1-eta_2)+deltaphi*deltaphi);
      if(DeltaR <= 0.5)  continue;      

      TLorentzVector MissingP;
      MissingP.SetPtEtaPhiM(met,0,metphi,0);
      
      float TransverseMass = std::sqrt(2.0*l1.Pt()*MissingP.Pt()*(1.0-std::cos(l1.DeltaPhi(MissingP))));      
      
      //look at this, the AN says specifically that zeta is defined to be the bisector of the momenta IN THE TRANSVERSE PLANE of the visible decay products.
      //TVector3 ZetaUnit = l1.Vect()*l2.Vect().Mag()+l2.Vect()*l1.Vect().Mag();//get a bisector of the angle between mu and tau

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

      //Create the weighting
      float PileupWeight = LumiWeights_12->weight(npu);
      
      float muTriggerSF = TriggerWeightings->GetBinContent(TriggerWeightings->FindBin(fabs(l1.Eta()),l1.Pt()));
      float muIDSF =  IDWeightings->GetBinContent(IDWeightings->FindBin(l1.Pt(),fabs(l1.Eta())));
      float muISOSF =  ISOWeightings->GetBinContent(ISOWeightings->FindBin(l1.Pt(),fabs(l1.Eta())));

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
	  
	  if(numGenJets==0) NormalizationWeight = NormalizationWeight*110.1887;
	  if(numGenJets==1) NormalizationWeight = NormalizationWeight*14.1549;
	  if(numGenJets==2) NormalizationWeight = NormalizationWeight*7.42847;
	  if(numGenJets==3) NormalizationWeight = NormalizationWeight*2.40205;
	  if(numGenJets==4) NormalizationWeight = NormalizationWeight*2.140756;
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
	  
	  if(numGenJets==0) NormalizationWeight = NormalizationWeight*3.009;
	  if(numGenJets==1) NormalizationWeight = NormalizationWeight*0.589;
	  if(numGenJets==2) NormalizationWeight = NormalizationWeight*0.612;
	  if(numGenJets==3) NormalizationWeight = NormalizationWeight*0.767;
	  if(numGenJets==4) NormalizationWeight = NormalizationWeight*0.690;
	}
      else if(input == "Data") NormalizationWeight = 1.0;          
      else
	{
	  std::cout<<"ERROR! Unrecognized Sample! Defaulting to unweighted events!"<<std::endl;
	  NormalizationWeight = 1.0;
	}

      //Data Selection
      float Var = (l1+l2).M();                              
            
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
	      if(TauIsoDiscrim)
		{		  
		  //seperate out our signal region in the drell yan histos
		  if(input == "DY"
		     or input == "DY1"
		     or input == "DY2"
		     or input == "DY3"
		     or input == "DY4")
		    {
		      if(gen_match_2 < 5 ) LowGenMatch_SignalRegion_Pass->Fill(Var,NormalizationWeight);    
		      if(gen_match_2 == 5) GenMatch_SignalRegion_Pass->Fill(Var,NormalizationWeight);    
		      if(gen_match_2 == 6) HighGenMatch_SignalRegion_Pass->Fill(Var,NormalizationWeight);    
		    }
		  //Literally everything else
		  else
		    {
		      SignalRegion_Pass->Fill(Var,NormalizationWeight);    
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
	  else if(TransverseMass > 80.0)
	    {
	      if(TauIsoDiscrim)
		{		  
		  //seperate out the Z->tau tau stuff
		  if(input == "DY"
		     or input == "DY1"
		     or input == "DY2"
		     or input == "DY3"
		     or input == "DY4")
		    {
		      if(gen_match_2 < 5)  LowGenMatch_WJetsRegion_Pass->Fill(Var,NormalizationWeight);
		      if(gen_match_2 == 5) GenMatch_WJetsRegion_Pass->Fill(Var,NormalizationWeight);
		      if(gen_match_2 == 6) HighGenMatch_WJetsRegion_Pass->Fill(Var,NormalizationWeight);
		    }
		  //Literally everything else
		  {
		    WJetsRegion_Pass->Fill(Var,NormalizationWeight);
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
		  //seperate out the Z->tautau stuff
		  if(input == "DY"
		     or input == "DY1"
		     or input == "DY2"
		     or input == "DY3"
		     or input == "DY4")
		    {
		      if(gen_match_2 < 5) LowGenMatch_QCDRegion_Pass->Fill(Var,NormalizationWeight);
		      if(gen_match_2 == 5) GenMatch_QCDRegion_Pass->Fill(Var,NormalizationWeight);
		      if(gen_match_2 == 6) HighGenMatch_QCDRegion_Pass->Fill(Var,NormalizationWeight);
		    }
		  else
		    {
		      QCDRegion_Pass->Fill(Var,NormalizationWeight);
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
	  else if(TransverseMass > 80.0)
	    {
	      if(TauIsoDiscrim)
		{		  
		  //Seperate out the Z->tautau stuff
		  if(input == "DY"
		     or input == "DY1"
		     or input == "DY2"
		     or input == "DY3"
		     or input == "DY4")
		    {
		      if(gen_match_2 < 5) LowGenMatch_QCDinWJets_Pass->Fill(Var,NormalizationWeight);    
		      if(gen_match_2 == 5) GenMatch_QCDinWJets_Pass->Fill(Var,NormalizationWeight);    
		      if(gen_match_2 == 6) HighGenMatch_QCDinWJets_Pass->Fill(Var,NormalizationWeight);    
		    }
		  //Literally everything else
		  else
		    {
		      QCDinWJets_Pass->Fill(Var,NormalizationWeight);    
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

  //save signal distributions
  TFile* SignalOutFile = new TFile(("TemporaryFiles/Signal_"+name+"_PassFail.root").c_str(),"RECREATE");

  TDirectory *SignalPassDir = SignalOutFile->mkdir("pass");
  SignalPassDir->cd();
  SignalRegion_Pass->Write();

  TDirectory *SignalFailDir = SignalOutFile->mkdir("fail");
  SignalFailDir->cd();
  SignalRegion_Fail->Write();
  
  SignalOutFile->Close();

  //save WJets distributions
  TFile* WJetsOutFile = new TFile(("TemporaryFiles/WJets_"+name+"_PassFail.root").c_str(),"RECREATE");

  TDirectory *WJetsPassDir = WJetsOutFile->mkdir("pass");
  WJetsPassDir->cd();
  WJetsRegion_Pass->Write();

  TDirectory *WJetsFailDir = WJetsOutFile->mkdir("fail");
  WJetsFailDir->cd();
  WJetsRegion_Fail->Write();
  
  WJetsOutFile->Close();

  //save QCD distributions
  TFile* QCDOutFile = new TFile(("TemporaryFiles/QCD_"+name+"_PassFail.root").c_str(),"RECREATE");

  TDirectory *QCDPassDir = QCDOutFile->mkdir("pass");
  QCDPassDir->cd();
  QCDRegion_Pass->Write();

  TDirectory *QCDFailDir = QCDOutFile->mkdir("fail");
  QCDFailDir->cd();
  QCDRegion_Fail->Write();
  
  QCDOutFile->Close();

  //save the QCD Wjets contribution
  TFile* QCDinWJetsOutFile = new TFile(("TemporaryFiles/QCDinWJets_"+name+"PassFail.root").c_str(),"RECREATE");

  TDirectory *QCDinWJetsPassDir = QCDinWJetsOutFile->mkdir("pass");
  QCDinWJetsPassDir->cd();
  QCDinWJets_Pass->Write();

  TDirectory *QCDinWJetsFailDir = QCDinWJetsOutFile->mkdir("fail");
  QCDinWJetsFailDir->cd();
  QCDinWJets_Fail->Write();
  
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
      
      TDirectory *GenMatchSignalFailDir = GenMatchedSignalOutFile->mkdir("fail");
      GenMatchSignalFailDir->cd();
      GenMatch_SignalRegion_Fail->Write();
      
      GenMatchedSignalOutFile->Close();
      
      //save WJets distributions
      TFile* GenMatchedWJetsOutFile = new TFile(("TemporaryFiles/WJets_GenMatch_"+name+"_PassFail.root").c_str(),"RECREATE");
      
      TDirectory *GenMatchWJetsPassDir = GenMatchedWJetsOutFile->mkdir("pass");
      GenMatchWJetsPassDir->cd();
      GenMatch_WJetsRegion_Pass->Write();
      
      TDirectory *GenMatchWJetsFailDir = GenMatchedWJetsOutFile->mkdir("fail");
      GenMatchWJetsFailDir->cd();
      GenMatch_WJetsRegion_Fail->Write();
      
      GenMatchedWJetsOutFile->Close();
      
      //save QCD distributions
      TFile* GenMatchedQCDOutFile = new TFile(("TemporaryFiles/QCD_GenMatch_"+name+"_PassFail.root").c_str(),"RECREATE");
      
      TDirectory *GenMatchQCDPassDir = GenMatchedQCDOutFile->mkdir("pass");
      GenMatchQCDPassDir->cd();
      GenMatch_QCDRegion_Pass->Write();
      
      TDirectory *GenMatchQCDFailDir = GenMatchedQCDOutFile->mkdir("fail");
      GenMatchQCDFailDir->cd();
      GenMatch_QCDRegion_Fail->Write();
      
      GenMatchedQCDOutFile->Close();
      
      //save the QCD Wjets contribution
      TFile* GenMatchedQCDinWJetsOutFile = new TFile(("TemporaryFiles/QCDinWJets_GenMatch_"+name+"PassFail.root").c_str(),"RECREATE");
      
      TDirectory *GenMatchQCDinWJetsPassDir = GenMatchedQCDinWJetsOutFile->mkdir("pass");
      GenMatchQCDinWJetsPassDir->cd();
      GenMatch_QCDinWJets_Pass->Write();
      
      TDirectory *GenMatchQCDinWJetsFailDir = GenMatchedQCDinWJetsOutFile->mkdir("fail");
      GenMatchQCDinWJetsFailDir->cd();
      GenMatch_QCDinWJets_Fail->Write();
      
      GenMatchedQCDinWJetsOutFile->Close();

      //For genmatch < 5
      TFile* LowGenMatchedSignalOutFile = new TFile(("TemporaryFiles/Signal_LowGenMatch_"+name+"_Passfail.root").c_str(),"RECREATE");
      
      TDirectory *LowGenMatchSignalPassDir = LowGenMatchedSignalOutFile->mkdir("pass");
      LowGenMatchSignalPassDir->cd();
      LowGenMatch_SignalRegion_Pass->Write();
      
      TDirectory *LowGenMatchSignalFailDir = LowGenMatchedSignalOutFile->mkdir("fail");
      LowGenMatchSignalFailDir->cd();
      LowGenMatch_SignalRegion_Fail->Write();
      
      LowGenMatchedSignalOutFile->Close();
      
      //save WJets distributions
      TFile* LowGenMatchedWJetsOutFile = new TFile(("TemporaryFiles/WJets_LowGenMatch_"+name+"_PassFail.root").c_str(),"RECREATE");
      
      TDirectory *LowGenMatchWJetsPassDir = LowGenMatchedWJetsOutFile->mkdir("pass");
      LowGenMatchWJetsPassDir->cd();
      LowGenMatch_WJetsRegion_Pass->Write();
      
      TDirectory *LowGenMatchWJetsFailDir = LowGenMatchedWJetsOutFile->mkdir("fail");
      LowGenMatchWJetsFailDir->cd();
      LowGenMatch_WJetsRegion_Fail->Write();
      
      LowGenMatchedWJetsOutFile->Close();
      
      //save QCD distributions
      TFile* LowGenMatchedQCDOutFile = new TFile(("TemporaryFiles/QCD_LowGenMatch_"+name+"_PassFail.root").c_str(),"RECREATE");
      
      TDirectory *LowGenMatchQCDPassDir = LowGenMatchedQCDOutFile->mkdir("pass");
      LowGenMatchQCDPassDir->cd();
      LowGenMatch_QCDRegion_Pass->Write();
      
      TDirectory *LowGenMatchQCDFailDir = LowGenMatchedQCDOutFile->mkdir("fail");
      LowGenMatchQCDFailDir->cd();
      LowGenMatch_QCDRegion_Fail->Write();
      
      LowGenMatchedQCDOutFile->Close();
      
      //save the QCD Wjets contribution
      TFile* LowGenMatchedQCDinWJetsOutFile = new TFile(("TemporaryFiles/QCDinWJets_LowGenMatch_"+name+"PassFail.root").c_str(),"RECREATE");
      
      TDirectory *LowGenMatchQCDinWJetsPassDir = LowGenMatchedQCDinWJetsOutFile->mkdir("pass");
      LowGenMatchQCDinWJetsPassDir->cd();
      LowGenMatch_QCDinWJets_Pass->Write();
      
      TDirectory *LowGenMatchQCDinWJetsFailDir = LowGenMatchedQCDinWJetsOutFile->mkdir("fail");
      LowGenMatchQCDinWJetsFailDir->cd();
      LowGenMatch_QCDinWJets_Fail->Write();
      
      LowGenMatchedQCDinWJetsOutFile->Close();

      //For genmatch == 6
      TFile* HighGenMatchedSignalOutFile = new TFile(("TemporaryFiles/Signal_HighGenMatch_"+name+"_Passfail.root").c_str(),"RECREATE");
      
      TDirectory *HighGenMatchSignalPassDir = HighGenMatchedSignalOutFile->mkdir("pass");
      HighGenMatchSignalPassDir->cd();
      HighGenMatch_SignalRegion_Pass->Write();
      
      TDirectory *HighGenMatchSignalFailDir = HighGenMatchedSignalOutFile->mkdir("fail");
      HighGenMatchSignalFailDir->cd();
      HighGenMatch_SignalRegion_Fail->Write();
      
      HighGenMatchedSignalOutFile->Close();
      
      //save WJets distributions
      TFile* HighGenMatchedWJetsOutFile = new TFile(("TemporaryFiles/WJets_HighGenMatch_"+name+"_PassFail.root").c_str(),"RECREATE");
      
      TDirectory *HighGenMatchWJetsPassDir = HighGenMatchedWJetsOutFile->mkdir("pass");
      HighGenMatchWJetsPassDir->cd();
      HighGenMatch_WJetsRegion_Pass->Write();
      
      TDirectory *HighGenMatchWJetsFailDir = HighGenMatchedWJetsOutFile->mkdir("fail");
      HighGenMatchWJetsFailDir->cd();
      HighGenMatch_WJetsRegion_Fail->Write();
      
      HighGenMatchedWJetsOutFile->Close();
      
      //save QCD distributions
      TFile* HighGenMatchedQCDOutFile = new TFile(("TemporaryFiles/QCD_HighGenMatch_"+name+"_PassFail.root").c_str(),"RECREATE");
      
      TDirectory *HighGenMatchQCDPassDir = HighGenMatchedQCDOutFile->mkdir("pass");
      HighGenMatchQCDPassDir->cd();
      HighGenMatch_QCDRegion_Pass->Write();
      
      TDirectory *HighGenMatchQCDFailDir = HighGenMatchedQCDOutFile->mkdir("fail");
      HighGenMatchQCDFailDir->cd();
      HighGenMatch_QCDRegion_Fail->Write();
      
      HighGenMatchedQCDOutFile->Close();
      
      //save the QCD Wjets contribution
      TFile* HighGenMatchedQCDinWJetsOutFile = new TFile(("TemporaryFiles/QCDinWJets_HighGenMatch_"+name+"PassFail.root").c_str(),"RECREATE");
      
      TDirectory *HighGenMatchQCDinWJetsPassDir = HighGenMatchedQCDinWJetsOutFile->mkdir("pass");
      HighGenMatchQCDinWJetsPassDir->cd();
      HighGenMatch_QCDinWJets_Pass->Write();
      
      TDirectory *HighGenMatchQCDinWJetsFailDir = HighGenMatchedQCDinWJetsOutFile->mkdir("fail");
      HighGenMatchQCDinWJetsFailDir->cd();
      HighGenMatch_QCDinWJets_Fail->Write();
      
      HighGenMatchedQCDinWJetsOutFile->Close();
    }
  
}
