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
//generates a pt based fake rate with the bins flipped about the flat fake rate
float GenerateFlippedFakeRate(float NominalFakeRate, float FlatFakeRate)
{
  return 2.0*FlatFakeRate-NominalFakeRate;
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
  
  //now get the pt based fake rates
  TH1F* VLoosePTFR = (TH1F*)FakeRateFile->Get("VLooseFakeRates");
  TH1F* LoosePTFR = (TH1F*)FakeRateFile->Get("LooseFakeRates");
  TH1F* MediumPTFR = (TH1F*)FakeRateFile->Get("MediumFakeRates");
  TH1F* TightPTFR = (TH1F*)FakeRateFile->Get("TightFakeRates");
  TH1F* VTightPTFR = (TH1F*)FakeRateFile->Get("VTightFakeRates");
  TH1F* VVTightPTFR = (TH1F*)FakeRateFile->Get("VVTightFakeRates");
  
  
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

      if(pt_1 < 29.0 or std::abs(eta_1) > 2.1 or !id_m_medium_1 or iso_1 > 0.15 or std::abs(dZ_1) > 0.2 or std::abs(d0_1) > 0.045 or !matchIsoMu27_1) continue;
      //tau criteria
      //added the decaymodefinding_2 which catches the old decay mode finding.
      if(pt_2 < 20.0  or std::abs(eta_2) > 2.3 or againstElectronLooseMVA6_2 != 1 or againstMuonTight3_2 != 1 or !decayModeFinding_2) continue;
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
      
      //Okay, according to cecile, we sort of ignore the fail regions for now?
      // should we look in the same sign region to be assured that we're working with Jets?
      // out of curiosity, what happens when we look in the W+Jets Regions and/or the QCD region
      if(q_1 * q_2 < 0.0 and TransverseMass < 40.0 and PZeta > -25.0)      
	{
	  //alright, now we look at each of the indivudal MVA working points and find the
	  // we find the ones that fail, and we reweight them, and record the visible mass
	  float PTFakeRate = 0.0;
	  float PTWeighting = 0.0;
	  float ExacerbatedFakeRate = 0.0;
	  float ExacerbatedWeighting = 0.0;
	  float FlippedFakeRate = 0.0;
	  float FlippedWeighting = 0.0;
	  if(!byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {
	      PTFakeRate = VLoosePTFR->GetBinContent(VLoosePTFR->FindBin(l2.Pt()));
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, VLooseFakeRate);
	      ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
	      FlippedFakeRate = GenerateFlippedFakeRate(PTFakeRate, VLooseFakeRate);
	      FlippedWeighting = FlippedFakeRate/(1.0- FlippedFakeRate);
	      
	      VLooseLowJetDistribution->Fill(Var,ExacerbatedWeighting);
	      VLoosePTFRJetDistribution->Fill(Var,PTWeighting);		      
	      VLooseHighJetDistribution->Fill(Var,VLooseFakeRate/(1.0-VLooseFakeRate));   	      
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byLooseIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	      
	      PTFakeRate = LoosePTFR->GetBinContent(LoosePTFR->FindBin(l2.Pt()));
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, LooseFakeRate);
	      ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
	      FlippedFakeRate = GenerateFlippedFakeRate(PTFakeRate, LooseFakeRate);
	      FlippedWeighting = FlippedFakeRate/(1.0- FlippedFakeRate);
	     
	      LooseLowJetDistribution->Fill(Var,ExacerbatedWeighting);
	      LoosePTFRJetDistribution->Fill(Var,PTWeighting);	      
	      LooseHighJetDistribution->Fill(Var,LooseFakeRate/(1.0-LooseFakeRate));
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byMediumIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	      
	      PTFakeRate = MediumPTFR->GetBinContent(MediumPTFR->FindBin(l2.Pt()));
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, MediumFakeRate);
	      ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
	      FlippedFakeRate = GenerateFlippedFakeRate(PTFakeRate, MediumFakeRate);
	      FlippedWeighting = FlippedFakeRate/(1.0- FlippedFakeRate);
	      
	      MediumLowJetDistribution->Fill(Var,ExacerbatedWeighting);
	      MediumPTFRJetDistribution->Fill(Var,PTWeighting);	 
	      MediumHighJetDistribution->Fill(Var,MediumFakeRate/(1.0-MediumFakeRate));
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	      
	      PTFakeRate = TightPTFR->GetBinContent(TightPTFR->FindBin(l2.Pt()));
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);
	      ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, TightFakeRate);
	      ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
	      FlippedFakeRate = GenerateFlippedFakeRate(PTFakeRate, TightFakeRate);
	      FlippedWeighting = FlippedFakeRate/(1.0- FlippedFakeRate);
	      
	      TightLowJetDistribution->Fill(Var,ExacerbatedWeighting);
	      TightPTFRJetDistribution->Fill(Var,PTWeighting);
	      TightHighJetDistribution->Fill(Var,TightFakeRate/(1.0-TightFakeRate));
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	      
	      PTFakeRate = VTightPTFR->GetBinContent(VTightPTFR->FindBin(l2.Pt()));
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);	      
	      ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, VTightFakeRate);
	      ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
	      FlippedFakeRate = GenerateFlippedFakeRate(PTFakeRate, VTightFakeRate);
	      FlippedWeighting = FlippedFakeRate/(1.0- FlippedFakeRate);

	      VTightLowJetDistribution->Fill(Var,ExacerbatedWeighting);
	      VTightPTFRJetDistribution->Fill(Var,PTWeighting);
	      VTightHighJetDistribution->Fill(Var,VTightFakeRate/(1.0-VTightFakeRate));
	    }
	  if(byVLooseIsolationRerunMVArun2v2DBoldDMwLT_2 and !byVVTightIsolationRerunMVArun2v2DBoldDMwLT_2)
	    {	      
	      PTFakeRate = VVTightPTFR->GetBinContent(VVTightPTFR->FindBin(l2.Pt()));
	      PTWeighting = PTFakeRate/(1.0-PTFakeRate);	      
	      ExacerbatedFakeRate = GenerateExacerbatedFakeRate(PTFakeRate, VVTightFakeRate);
	      ExacerbatedWeighting = ExacerbatedFakeRate/(1.0-ExacerbatedFakeRate);
	      FlippedFakeRate = GenerateFlippedFakeRate(PTFakeRate, VVTightFakeRate);
	      FlippedWeighting = FlippedFakeRate/(1.0- FlippedFakeRate);

	      VVTightLowJetDistribution->Fill(Var,ExacerbatedWeighting);
	      VVTightPTFRJetDistribution->Fill(Var,PTWeighting);
	      VVTightHighJetDistribution->Fill(Var,VVTightFakeRate/(1.0-VVTightFakeRate));
	    }
	} //end of checking for signal region
    } //end of for loop

  std::cout<<std::endl;

  //Alrightm let's right this out and get the heck out of here.
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
