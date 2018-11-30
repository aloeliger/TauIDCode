#include "TROOT.h"
#include <string>
#include "/data/aloeliger/CMSSW_9_4_0/src/PhysicsTools/Utilities/interface/LumiReweightingStandAlone.h"
//just for the helper functions
//this is sorta overkill
#include "GenerateJetSamples.cc"

void GenerateMCInJetsRegion(std::string input)
{
  TFile *MyFile = new TFile(("/data/ccaillol/tauid_20june_mt/"+input+".root").c_str());
  TTree *Tree = (TTree*) MyFile->Get("mutau_tree");
  TH1F* nevents = (TH1F*) MyFile->Get("nevents");
  float TotalNumberOfEvents = nevents->GetBinContent(1);
  
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
  else if(input == "DY") XSecWeight = LHCLumi * 5765.4e-12 / TotalNumberOfEvents;
  else if(input == "DY1") XSecWeight = LHCLumi * 1178.29e-12 /TotalNumberOfEvents;
  else if(input == "DY2") XSecWeight = LHCLumi * 387.34e-12 /TotalNumberOfEvents;
  else if(input == "DY3") XSecWeight = LHCLumi * 118.429e-12 /TotalNumberOfEvents;
  else if(input == "DY4") XSecWeight = LHCLumi * 63.73e-12 /TotalNumberOfEvents;
  
  reweight::LumiReWeighting* LumiWeights_12;
  LumiWeights_12 = new reweight::LumiReWeighting(("/data/ccaillol/tauid_20june_mt/"+input+".root").c_str(),
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
  
      //match diegos pt > 30 cut as opposed to my original 29.0 cut
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
      //method(s) below seems to ffer worse agreement?
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
      //float Var = npv;
      //Create the weighting
      float PileupWeight = LumiWeights_12->weight(npu);
      
      float muTriggerSF = TriggerWeightings->GetBinContent(TriggerWeightings->FindBin(fabs(l1.Eta()),l1.Pt()));
      float muIDSF =  IDWeightings->GetBinContent(IDWeightings->FindBin(l1.Pt(),fabs(l1.Eta())));
      float muISOSF =  ISOWeightings->GetBinContent(ISOWeightings->FindBin(l1.Pt(),fabs(l1.Eta())));

      if(input == "WW")NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(input == "WZ") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;
      else if(input == "ZZ") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF*muIDSF*muISOSF;            
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

      //alright now we start examining MC in the same region as the jets
      //changed the mt cut to 50 to match diego, instead of my original 40
      if(q_1 * q_2 < 0.0 and TransverseMass < 50.0 and PZeta > -25.0)      
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
		  PTFakeRate = VLooseDecayMode0PTFakeRates->GetBinContent(VLooseDecayMode0PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  VLooseResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = VLooseDecayMode1PTFakeRates->GetBinContent(VLooseDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  VLooseResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = VLooseDecayMode0PTFakeRates->GetBinContent(VLooseDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  VLooseResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = LooseDecayMode0PTFakeRates->GetBinContent(LooseDecayMode0PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  LooseResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = LooseDecayMode1PTFakeRates->GetBinContent(LooseDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  LooseResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = LooseDecayMode0PTFakeRates->GetBinContent(LooseDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  LooseResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = MediumDecayMode0PTFakeRates->GetBinContent(MediumDecayMode0PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  MediumResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = MediumDecayMode1PTFakeRates->GetBinContent(MediumDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  MediumResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = MediumDecayMode0PTFakeRates->GetBinContent(MediumDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  MediumResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = TightDecayMode0PTFakeRates->GetBinContent(TightDecayMode0PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  TightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = TightDecayMode1PTFakeRates->GetBinContent(TightDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  TightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = TightDecayMode0PTFakeRates->GetBinContent(TightDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  TightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = VTightDecayMode0PTFakeRates->GetBinContent(VTightDecayMode0PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  VTightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = VTightDecayMode1PTFakeRates->GetBinContent(VTightDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  VTightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = VTightDecayMode0PTFakeRates->GetBinContent(VTightDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  VTightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = VVTightDecayMode0PTFakeRates->GetBinContent(VVTightDecayMode0PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  VVTightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = VVTightDecayMode1PTFakeRates->GetBinContent(VVTightDecayMode1PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  VVTightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
		  PTFakeRate = VVTightDecayMode0PTFakeRates->GetBinContent(VVTightDecayMode10PTFakeRates->FindBin(l2.Pt()));
		  PTWeighting = PTFakeRate/(1.0-PTFakeRate);

		  VVTightResultHisto->Fill(Var,NormalizationWeight*PTWeighting);
		  
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
    }// end of for loop.
  TFile* OutFile = new TFile(("../TemporaryFiles/"+input+"_InJetsRegion.root").c_str(),"RECREATE");
  VLooseResultHisto->Write();
  LooseResultHisto->Write();
  MediumResultHisto->Write();
  TightResultHisto->Write();
  VTightResultHisto->Write();
  VVTightResultHisto->Write();  

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
