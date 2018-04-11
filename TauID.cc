#include "TROOT.h"
#include "/afs/cern.ch/user/a/aloelige/private/RootMacros/LumiReweightingStandAlone.h"

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
  //there's a huge whack of these variables in the tree I don't recognize
  //They are not included here
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

  //System mvis
  TH1F* SignalRegion_Pass = new TH1F((input+"_Pass").c_str(),
				     "Signal_Pass",
				     15,
				     0.0,
				     150.0);
  TH1F* SignalRegion_Fail = new TH1F((input+"_Fail").c_str(),
				     "Signal_Fail",
				     15,
				     0.0,
				     150.0);

  TH1F* WJetsRegion_Pass = new TH1F(("WJets_"+input+"_Pass").c_str(), 
				    "WJets_Pass", 
				    SignalRegion_Pass->GetSize()-2, 
				    SignalRegion_Pass->GetXaxis()->GetXmin(),
				    SignalRegion_Pass->GetXaxis()->GetXmax());
  TH1F* WJetsRegion_Fail = new TH1F(("WJets_"+input+"_Fail").c_str(), 
				    "WJets_Fail", 
				    SignalRegion_Fail->GetSize()-2, 
				    SignalRegion_Fail->GetXaxis()->GetXmin(),
				    SignalRegion_Fail->GetXaxis()->GetXmax());
  
  TH1F* QCDRegion_Pass = new TH1F(("QCD_"+input+"_Pass").c_str(), 
				  "QCD_Pass", 
				  SignalRegion_Pass->GetSize()-2, 
				  SignalRegion_Pass->GetXaxis()->GetXmin(),
				  SignalRegion_Pass->GetXaxis()->GetXmax());
  
  TH1F* QCDRegion_Fail = new TH1F(("QCD_"+input+"_Fail").c_str(), 
				  "QCD_Fail", 
				  SignalRegion_Fail->GetSize()-2, 
				  SignalRegion_Fail->GetXaxis()->GetXmin(),
				  SignalRegion_Fail->GetXaxis()->GetXmax());
  
  TH1F* QCDinWJets_Pass = new TH1F(("WJets_QCD_"+input+"_Pass").c_str(), 
				   "WJets_QCD_Pass", 
				   SignalRegion_Pass->GetSize()-2, 
				   SignalRegion_Pass->GetXaxis()->GetXmin(),
				   SignalRegion_Pass->GetXaxis()->GetXmax());

  TH1F* QCDinWJets_Fail = new TH1F(("WJets_QCD_"+input+"_Fail").c_str(), 
				   "WJets_QCD_Fail", 
				   SignalRegion_Fail->GetSize()-2, 
				   SignalRegion_Fail->GetXaxis()->GetXmin(),
				   SignalRegion_Fail->GetXaxis()->GetXmax());
  

  //Determine the relevant cross section or normalization
  float LHCLumi = 46.062e15;
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
  else
    {
      std::cout<<"ERROR! Unrecognized Sample! Defaulting to unweighted events!"<<std::endl;
      XSecWeight = 1.0;
    }

  std::cout<<"Lumi: "<<LHCLumi<<std::endl;
  std::cout<<"TotalNumberOfEvents: "<<TotalNumberOfEvents<<std::endl;
  //std::cout<<"NormalizationWeight: "<<NormalizationWeight<<std::endl;

  reweight::LumiReWeighting* LumiWeights_12;
  LumiWeights_12 = new reweight::LumiReWeighting(("/data/ccaillol/tauid_3mar_mt/"+input+".root").c_str(),
						 "Weightings/MyDataPileupHistogram.root",
						 "pileup_mc",
						 "pileup");

  TFile* IsoFile = new TFile("Weightings/EfficienciesAndSF_RunBtoF_Nov17Nov2017.root");
  TDirectoryFile* IsoMuDirectory = (TDirectoryFile* )IsoFile->Get("IsoMu27_PtEtaBins");
  TH2F* IsoWeightings = (TH2F*) IsoMuDirectory->Get("abseta_pt_ratio");
  
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
      if(DeltaR <= 0.5)  continue;
	 
      TLorentzVector MissingP;
      MissingP.SetPtEtaPhiM(met,0,metphi,0);
      
      float TransverseMass = std::sqrt(2.0*l1.Pt()*MissingP.Pt()*(1.0-std::cos(l1.DeltaPhi(MissingP))));      
      
      TVector3 ZetaUnit = l1.Vect()*(1.0/l1.Vect().Mag())+l2.Vect()*(1.0/l2.Vect().Mag());//get a bisector of the angle between mu and tau
      ZetaUnit = ZetaUnit*(1.0/ZetaUnit.Mag()); //unitize it
      
      float PZetaVis = (l1.Vect()+l2.Vect()).Dot(ZetaUnit);
      float PZetaAll = (l1.Vect()+l2.Vect()+MissingP.Vect()).Dot(ZetaUnit);
      float PZeta = PZetaAll - 0.85 * PZetaVis;      

      //Create the weighting
      float PileupWeight = LumiWeights_12->weight(npu);

      float muisoSF = IsoWeightings->GetBinContent(IsoWeightings->FindBin(fabs(l1.Eta()),l1.Pt()));

      if(input == "WW")NormalizationWeight = XSecWeight*PileupWeight*muisoSF;
      else if(input == "WZ") NormalizationWeight = XSecWeight*PileupWeight*muisoSF;
      else if(input == "ZZ") NormalizationWeight = XSecWeight*PileupWeight*muisoSF;
      else if(input == "W") NormalizationWeight = XSecWeight*PileupWeight*muisoSF;
      else if(input == "TTTo2L2Nu") NormalizationWeight = XSecWeight*PileupWeight*muisoSF;
      else if(input == "TTToHadronic") NormalizationWeight = XSecWeight*PileupWeight*muisoSF;
      else if(input == "TTToSemiLeptonic") NormalizationWeight = XSecWeight*PileupWeight*muisoSF;
      else if(input == "DY") NormalizationWeight = XSecWeight*PileupWeight*muisoSF;
      else if(input == "Data") NormalizationWeight = 1.0;
      else
	{
	  std::cout<<"ERROR! Unrecognized Sample! Defaulting to unweighted events!"<<std::endl;
	  NormalizationWeight = 1.0;
	}
      
      //check the tau iso discriminants, and divide these our events by pass/fail
      //according to 5.2.1 iso discriminants on the tau are loose: < 2.5 (GeV), medium: < 1.5 (GeV), tight: < 0.8 (GeV)
      
      //check signs if Opposite sign is signal contribution
      if(q_1*q_2 < 0.0)
	{
	  //Signal contribution
	  if(TransverseMass < 40.0 and PZeta > -25.0)
	    {
	      if(iso_2 < 0.8)
		{
		  SignalRegion_Pass->Fill((l1+l2).M(),NormalizationWeight);    
		}
	      else
		{
		  SignalRegion_Fail->Fill((l1+l2).M(),NormalizationWeight);
		}
	    }
	  //WJets Contribution
	  else if(TransverseMass > 80.0)
	    {
	      if(iso_2 < 0.8)
		{
		  WJetsRegion_Pass->Fill((l1+l2).M(),NormalizationWeight);    
		}
	      else
		{
		  WJetsRegion_Fail->Fill((l1+l2).M(),NormalizationWeight);
		}
	    }
	}
      //same sign is QCD
      else if(q_1*q_2 > 0.0)
	{
	  if(TransverseMass < 40.0 and PZeta > -25.0)
	    {
	      if(iso_2 < 0.8)
		{
		  QCDRegion_Pass->Fill((l1+l2).M(),NormalizationWeight);    
		}
	      else
		{
		  QCDRegion_Fail->Fill((l1+l2).M(),NormalizationWeight);
		}
	    }
	  else if(TransverseMass > 80.0)
	    {
	      if(iso_2 < 0.8)
		{
		  QCDinWJets_Pass->Fill((l1+l2).M(),NormalizationWeight);    
		}
	      else
		{
		  QCDinWJets_Fail->Fill((l1+l2).M(),NormalizationWeight);
		} 
	    }
	}            
    }
  
  std::cout<<std::endl;  

  //save signal distributions
  TFile* SignalOutFile = new TFile(("TemporaryFiles/Signal_"+input+"_PassFail.root").c_str(),"RECREATE");

  TDirectory *SignalPassDir = SignalOutFile->mkdir("pass");
  SignalPassDir->cd();
  SignalRegion_Pass->Write();

  TDirectory *SignalFailDir = SignalOutFile->mkdir("fail");
  SignalFailDir->cd();
  SignalRegion_Fail->Write();
  
  SignalOutFile->Close();

  //save WJets distributions
  TFile* WJetsOutFile = new TFile(("TemporaryFiles/WJets_"+input+"_PassFail.root").c_str(),"RECREATE");

  TDirectory *WJetsPassDir = WJetsOutFile->mkdir("pass");
  WJetsPassDir->cd();
  WJetsRegion_Pass->Write();

  TDirectory *WJetsFailDir = WJetsOutFile->mkdir("fail");
  WJetsFailDir->cd();
  WJetsRegion_Fail->Write();
  
  WJetsOutFile->Close();

  //save QCD distributions
  TFile* QCDOutFile = new TFile(("TemporaryFiles/QCD_"+input+"_PassFail.root").c_str(),"RECREATE");

  TDirectory *QCDPassDir = QCDOutFile->mkdir("pass");
  QCDPassDir->cd();
  QCDRegion_Pass->Write();

  TDirectory *QCDFailDir = QCDOutFile->mkdir("fail");
  QCDFailDir->cd();
  QCDRegion_Fail->Write();
  
  QCDOutFile->Close();

  //save the QCD Wjets contribution
  TFile* QCDinWJetsOutFile = new TFile(("TemporaryFiles/QCDinWJets_"+input+"PassFail.root").c_str(),"RECREATE");

  TDirectory *QCDinWJetsPassDir = QCDinWJetsOutFile->mkdir("pass");
  QCDinWJetsPassDir->cd();
  QCDinWJets_Pass->Write();

  TDirectory *QCDinWJetsFailDir = QCDinWJetsOutFile->mkdir("fail");
  QCDinWJetsFailDir->cd();
  QCDinWJets_Fail->Write();
  
  QCDinWJetsOutFile->Close();

}
