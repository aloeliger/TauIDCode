#include "TROOT.h"

void TauID(std::string input)
{
  //get the tree that we're going to run
  TFile *MyFile = new TFile(("/data/ccaillol/tauid_3mar_mt/"+input+".root").c_str());
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
  
  //there's a huge whack of these variables in the three I don't recognize and am not going to bother with right now
  // to entry 45 they are declared but commented out below
  // we pick back up at entry 71
  /*
  float byLooseCombinedIsolationDeltaBetaCorr3Hits_2,byMediumCombinedIsolationDeltaBetaCorr3Hits_2, byTightCombinedIsolationDeltaBetaCorr3Hits_2,byCombinedIsolationDeltaBetaCorrRaw3Hits_2,byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_2,byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_2,byTightCombinedIsolationDeltaBetaCorr3HitsdR03_2,byVLooseIsolationMVArun2v1DBnewDMwLT_2,byVLooseIsolationMVArun2v1DBoldDMwLT_2,byVLooseIsolationMVArun2v1DBdR03oldDMwLT_2,byLooseIsolationMVArun2v1DBnewDMwLT_2;
  */

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
  Tree->SetBranchAddress("e_2",&q_2);
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

  //System mvis for data to simulation scale factors
  TH1F* MuTauInvariantMass_Pass = new TH1F((input+"_Pass").c_str(),"VisMass_Pass",10,0.0,100.0);
  TH1F* MuTauInvariantMass_Fail = new TH1F((input+"_Fail").c_str(),"VisMass_Fail",10,0.0,100.0);

  //Determine the relevant cross section or normalization
  float LHCLumi = 46.062e15;
  float NormalizationWeight;
  if(input == "WW")NormalizationWeight = LHCLumi * 118.7e-12 / TotalNumberOfEvents;
  else if(input == "WZ") NormalizationWeight = LHCLumi * 47.13e-12 / TotalNumberOfEvents;
  else if(input == "ZZ") NormalizationWeight = LHCLumi * 16.523e-12 / TotalNumberOfEvents;
  else if(input == "W") NormalizationWeight = LHCLumi * 61526.7e-12 / TotalNumberOfEvents;
  else if(input == "TTTo2L2Nu") NormalizationWeight = LHCLumi * 88.34e-12/ TotalNumberOfEvents;
  else if(input == "TTToHadronic") NormalizationWeight = LHCLumi * 377.96e-12 / TotalNumberOfEvents;
  else if(input == "TTToSemiLeptonic") NormalizationWeight = LHCLumi * 365.45e-12 / TotalNumberOfEvents;
  else if(input == "DY") NormalizationWeight = LHCLumi * 5765.4e-12 / TotalNumberOfEvents;
  else if(input == "Data") NormalizationWeight = 1.0;
  else
    {
      std::cout<<"ERROR! Unrecognized Sample! Defaulting to unweighted events!"<<std::endl;
      NormalizationWeight = 1.0;
    }

  std::cout<<"Lumi: "<<LHCLumi<<std::endl;
  std::cout<<"TotalNumberOfEvents: "<<TotalNumberOfEvents<<std::endl;
  std::cout<<"NormalizationWeight: "<<NormalizationWeight<<std::endl;
  
  for(int i =0;i < NumberOfEntries; i++)
    {
      Tree->GetEntry(i);
      if(i % 10000 == 0) fprintf(stdout, "\rProcessed through event: %d of %d", i, NumberOfEntries);
      fflush(stdout);

      //make the necessary 4 vectors      
      TLorentzVector l1; l1.SetPtEtaPhiE(pt_1, eta_1, phi_1, e_1); //muon
      TLorentzVector l2; l2.SetPtEtaPhiM(pt_2, eta_2, phi_2, m_2); //tau

      //Event selection
      //muon criteria
      if(pt_1 < 23.0 or std::abs(eta_1) > 2.1 or !id_m_medium_1 or iso_1 > 0.15) continue;
      //tau criteria
      if(pt_2 < 20.0  or std::abs(eta_2) > 2.3 or againstElectronLooseMVA6_2 != 1 or againstMuonTight3_2 != 1.0) continue;
      //pair criteria
      float DeltaR = std::sqrt((eta_1-eta_2)*(eta_1-eta_2)+(phi_1-phi_2)*(phi_1-phi_2));
      if(DeltaR < 0.5 or q_1*q_2 > 0.0) continue;

      //How do we construct the missing momentum vector?
      TLorentzVector MissingP;
      MissingP.SetPtEtaPhiM(met,0,metphi,0);
      
      float TransverseMass = std::sqrt(2.0*l1.Pt()*MissingP.Pt()*(1.0-std::cos(l1.DeltaPhi(MissingP))));
      if(TransverseMass > 40.0) continue;      

      TVector3 ZetaUnit = l1.Vect()*(1.0/l1.Vect().Mag())+l2.Vect()*(1.0/l2.Vect().Mag());//get a bisector of the angle between mu and tau
      ZetaUnit = ZetaUnit*(1.0/ZetaUnit.Mag()); //unitize it

      float PZetaVis = (l1.Vect()+l2.Vect()).Dot(ZetaUnit);
      float PZetaAll = (l1.Vect()+l2.Vect()+MissingP.Vect()).Dot(ZetaUnit);
      float PZeta = PZetaAll - 0.85 * PZetaVis;
      //float DZeta = PZetaVis+PZeta;
      if(PZeta < -25.0)	continue;     

      //check the tau iso discriminants, and divide these our events by pass/fail
      //according to 5.2.1 iso discriminants on the tau are loose: < 2.5 (GeV), medium: < 1.5 (GeV), tight: < 0.8 (GeV)
      if(iso_2 < 0.8)
	{
	  MuTauInvariantMass_Pass->Fill((l1+l2).M(),NormalizationWeight);    
	}
      else
	{
	  MuTauInvariantMass_Fail->Fill((l1+l2).M(),NormalizationWeight);
	}
    }
  
  std::cout<<std::endl;
  TFile* OutFile = new TFile(("TemporaryFiles/"+input+"PassFail.root").c_str(),"RECREATE");

  TDirectory *PassDir = OutFile->mkdir("PassRegion");
  PassDir->cd();
  MuTauInvariantMass_Pass->Write();

  TDirectory *FailDir = OutFile->mkdir("FailRegion");
  FailDir->cd();
  MuTauInvariantMass_Fail->Write();
  
  OutFile->Close();

}
