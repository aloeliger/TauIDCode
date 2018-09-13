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
  float FailsReconstructionTaus = 0.0;
  float TausPassVLooseMVAIso = 0.0;
  float TausPassLooseMVAIso = 0.0;
  float TausPassMediumMVAIso = 0.0;
  float TausPassTightMVAIso = 0.0;
  float TausPassVTightMVAIso = 0.0;
  float TausPassVVTightMVAIso = 0.0;

  
  float binning[] = {0.0, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0, 110.0, 120.0,
		     160.0, 200.0};
  int binnumber = sizeof(binning)/sizeof(float) - 1;

  TH1F* OverallFakeRates = new TH1F("OverallFakeRates","OverallFakeRates",6,0.0,6.0);
  TH1F* FailsReconstructionByPT = new TH1F("FailsReconstructionByPT","FailsReconstructionsByPT",binnumber,binning);
  TH1F* BaselineSelectedTauPT = new TH1F("BasicSelectedTauPT","BasicSlsectedTauPT",binnumber,binning);
  TH1F* VLoosePTFakeRates = new TH1F("VLooseFakeRates","VLooseFakeRates",binnumber,binning);
  TH1F* LoosePTFakeRates = new TH1F("LooseFakeRates","LooseFakeRates",binnumber,binning);
  TH1F* MediumPTFakeRates = new TH1F("MediumFakeRates","MediumFakeRates",binnumber,binning);
  TH1F* TightPTFakeRates = new TH1F("TightFakeRates","TightFakeRates",binnumber,binning);
  TH1F* VTightPTFakeRates = new TH1F("VTightFakeRates","VTightFakeRates",binnumber,binning);
  TH1F* VVTightPTFakeRates = new TH1F("VVTightFakeRates","VVTightFakeRates",binnumber,binning);
  
  /*
  TH1F* OverallFakeRates = new TH1F("OverallFakeRates","OverallFakeRates",6,0.0,6.0);
  TH1F* FailsReconstructionByPT = new TH1F("FailsReconstructionByPT","FailsReconstructionsByPT",20,0.0,200.0);
  TH1F* BaselineSelectedTauPT = new TH1F("BasicSelectedTauPT","BasicSlsectedTauPT",20,0.0,200.0);
  TH1F* VLoosePTFakeRates = new TH1F("VLooseFakeRates","VLooseFakeRates",20,0.0,200.0);
  TH1F* LoosePTFakeRates = new TH1F("LooseFakeRates","LooseFakeRates",20,0.0,200.0);
  TH1F* MediumPTFakeRates = new TH1F("MediumFakeRates","MediumFakeRates",20,0.0,200.0);
  TH1F* TightPTFakeRates = new TH1F("TightFakeRates","TightFakeRates",20,0.0,200.0);
  TH1F* VTightPTFakeRates = new TH1F("VTightFakeRates","VTightFakeRates",20,0.0,200.0);
  TH1F* VVTightPTFakeRates = new TH1F("VVTightFakeRates","VVTightFakeRates",20,0.0,200.0);
  */
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
      if(pt_1 < 29.0 or std::abs(eta_1) > 2.1 or !id_m_medium_1 or iso_1 > 0.15 or std::abs(dZ_1) > 0.2 or std::abs(d0_1) > 0.045 or !matchIsoMu27_1) continue;
      
      if(pt_2 < 29.0 or std::abs(eta_2) > 2.1 or !id_m_medium_2 or iso_2 > 0.15 or std::abs(dZ_2) > 0.2 or std::abs(d0_2) > 0.045 or !matchIsoMu27_2) continue;
      
      //We'll do some loose selection of tau stuff, saving the  
      if(pt_3 < 20.0 or std::abs(eta_3) > 2.3 or againstElectronLooseMVA6_3 != 1 or againstMuonTight3_3 != 1 /*or !decayModeFinding_3*/) continue;      
      
      // the only sort of other criteria we'll require is stringent selection of a Z mass
      // should we also require opposite sign mu's to ensure the Z decay?
      // may as well?
      if((l1+l2).M() <= 80.0 or (l1+l2).M() >= 100.0 or q_1*q_2 > 0) continue;      

      // okay we should now be working witha Z decay to mu's and what is nominally a tau
      BaselineSelectedTaus += 1.0;
      BaselineSelectedTauPT->Fill(pt_3);
      // These taus form our denominator
      if(!byVLooseIsolationRerunMVArun2v2DBoldDMwLT_3)
	{
	  FailsReconstructionTaus+=1.0;
	  FailsReconstructionByPT->Fill(pt_3);
	}
      if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_3) 
	{
	  TausPassVLooseMVAIso+=1.0;
	  VLoosePTFakeRates->Fill(pt_3);
	}
      if(byLooseIsolationRerunMVArun2v2DBoldDMwLT_3)
	{ 
	  TausPassLooseMVAIso+=1.0;
	  LoosePTFakeRates->Fill(pt_3);
	}
      if(byMediumIsolationRerunMVArun2v2DBoldDMwLT_3)
	{ 
	  TausPassMediumMVAIso+=1.0;
	  MediumPTFakeRates->Fill(pt_3);
	}
      if(byTightIsolationRerunMVArun2v2DBoldDMwLT_3) 
	{
	  TausPassTightMVAIso+=1.0;
	  TightPTFakeRates->Fill(pt_3);
	}
      if(byVTightIsolationRerunMVArun2v2DBoldDMwLT_3) 
	{
	  TausPassVTightMVAIso+=1.0;
	  VTightPTFakeRates->Fill(pt_3);
	}
      if(byVVTightIsolationRerunMVArun2v2DBoldDMwLT_3) 
	{
	  TausPassVVTightMVAIso+=1.0;
	  VVTightPTFakeRates->Fill(pt_3);
	}

    }

  std::cout<<"BaselineSelectedTaus: "<<BaselineSelectedTaus<<std::endl;
  std::cout<<"FailsReconstructionTaus: "<<FailsReconstructionTaus<<std::endl;
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

  OverallFakeRates->GetXaxis()->SetBinLabel(1,"VLooseFakeRate");
  OverallFakeRates->GetXaxis()->SetBinLabel(2,"LooseFakeRates");
  OverallFakeRates->GetXaxis()->SetBinLabel(3,"MediumFakeRates");
  OverallFakeRates->GetXaxis()->SetBinLabel(4,"TightFakeRates");
  OverallFakeRates->GetXaxis()->SetBinLabel(5,"VTightFakeRates");
  OverallFakeRates->GetXaxis()->SetBinLabel(6,"VVTightFakeRates");
  
  //create the pt distributions fake rate distributions
  VVTightPTFakeRates->Divide(VLoosePTFakeRates);
  VTightPTFakeRates->Divide(VLoosePTFakeRates);
  TightPTFakeRates->Divide(VLoosePTFakeRates);
  MediumPTFakeRates->Divide(VLoosePTFakeRates);
  LoosePTFakeRates->Divide(VLoosePTFakeRates);
  VLoosePTFakeRates->Divide(BaselineSelectedTauPT);
  
  TFile* FakeRateFile = new TFile("../Distributions/FakeRateDistributions.root","RECREATE");
  OverallFakeRates->Write();
  VLoosePTFakeRates->Write();
  LoosePTFakeRates->Write();
  MediumPTFakeRates->Write();
  TightPTFakeRates->Write();
  VTightPTFakeRates->Write();
  VVTightPTFakeRates->Write();

  FakeRateFile->Close();
}
