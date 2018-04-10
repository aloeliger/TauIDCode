// getting the w + jets shape is pretty similar to the overall distribution
// method, I should probably find a way to condense this into the tauIDcode.cc

#include "TROOT.h"

void WJetsDistributionCreation(std::string input)
{
  //Documentation says that what we do is define a sample the way we have, and then subtract off contributions from other distributions based on 
  // expected cross sections. 
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
  
  float chargedIsoPtSum_2,decayModeFinding_2,decayModeFindingNewDMs_2,neutralIsoPtSum_2,puCorrPtSum_2,chargedIso_2,neutralIso_2,puIso_2,photonIso_2,trackpt_2;
  float numGenJets,jetPt_2,charged_signalCone_2,charged_isoCone_2;
  float matchIsoMu27_1,passIsoMu27,pt_top1,pt_top2,genweight,gen_match_2;
  float met,metphi;
  int nbtag,njets;

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
  TFile* PassFailFile = new TH1F("PassFailOut.root");
  TH1F* ReferenceHisto = (TH1F*)((TDirectory*)(PassFailFile->Get("PassRegion")))->Get("Data_Pass");
  TH1F* MuTauInvariantMass_Pass = new TH1F((input+"_Pass").c_str(),"MuTauInvariantMass_Pass", ReferenceHisto->GetSize()-2, ReferenceHisto->GetXaxis()->GetXmin(),ReferenceHisto->GetXaxis()->GetXmax());
  TH1F* MuTauInvariantMass_Fail = new TH1F((input+"_Fail").c_str(),"MuTauInvariantMass_Fail",ReferenceHisto->GetSize()-2, ReferenceHisto->GetXaxis()->GetXmin(), ReferenceHisto->GetXaxis()->GetXmin());

  for(int i =0;i < NumberOfEntries; i++)
    {
      Tree->GetEntry(i);
      if(i % 10000 == 0) fprintf(stdout, "\rProcessed through event: %d of %d", i, NumberOfEntries);
      fflush(stdout);

      TLorentzVector l1; l1.SetPtEtaPhiE(pt_1, eta_1, phi_1, e_1); //muon
      TLorentzVector l2; l2.SetPtEtaPhiE(pt_2, eta_2, phi_2, e_2); //tau
      
      //event selection is similar to the the other distributions but we nix
      // the Dzeta requirement and change the transverse mass requirement
      if(pt_1 < 23.0 or std::abs(eta_1) > 2.1 or !id_m_medium_1 or iso_1 > 0.15) continue;
      if(pt_2 < 20.0  or std::abs(eta_2) > 2.3 or againstElectronLooseMVA6_2 != 1 or againstMuonTight3_2 != 1.0) continue;
      float DeltaR = std::sqrt((eta_1-eta_2)*(eta_1-eta_2)+(phi_1-phi_2)*(phi_1-phi_2));
      if(DeltaR < 0.5 or q_1*q_2 > 0.0) continue;
      
      TLorentzVector MissingP;
      MissingP.SetPtEtaPhiM(met,0,metphi,0);
      
      float TransverseMass = std::sqrt(2.0*l1.Pt()*MissingP.Pt()*(1.0-std::cos(l1.DeltaPhi(MissingP))));
      if(TransverseMass < 80.0) continue;
      
      TVector3 ZetaUnit = l1.Vect()*(1.0/l1.Vect().Mag())+l2.Vect()*(1.0/l2.Vect().Mag());//get a bisector of the angle between mu and tau
      ZetaUnit = ZetaUnit*(1.0/ZetaUnit.Mag()); //unitize it

      float PZetaVis = (l1.Vect()+l2.Vect()).Dot(ZetaUnit);
      float PZetaAll = (l1.Vect()+l2.Vect()+MissingP.Vect()).Dot(ZetaUnit);
      float PZeta = PZetaAll - 0.85 * PZetaVis;

      if(iso_2 < 0.8)
	{
	  MuTauInvariantMass_Pass->Fill((l1+l2).M());	  
	}
      else
	{
	  MuTauInvariantMass_Fail->Fill((l1+l2).M());
	}
    }
  std::cout<<endl;
  std::cout<<"Accepted Passing Events: "<<MuTauInvariantMass_Pass->Integral()<<std::endl;
  std::cout<<"Accepted Failing Events: "<<MuTauInvariantMass_Fail->Integral()<<std::endl;
  std::cout<<std::endl;
  
  TFile* OutFile = new TFile(("TemporaryFiles/"+input+"_WJetsContribution.root").c_str(),"RECREATE");

  TDirectory *PassDir = OutFile->mkdir("PassRegion");
  PassDir->cd();
  MuTauInvariantMass_Pass->Write();

  TDirectory *FailDir = OutFile->mkdir("FailRegion");
  FailDir->cd();
  MuTauInvariantMass_Fail->Write();
  
  OutFile->Close();
}
