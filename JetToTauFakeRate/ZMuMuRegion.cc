#include "TROOT.h"
//#include "/afs/cern.ch/user/a/aloelige/private/RootMacros/LumiReweightingStandAlone.h"
#include "/data/aloeliger/CMSSW_9_4_0/src/PhysicsTools/Utilities/interface/LumiReweightingStandAlone.h"
#include <string>

void ZMuMuRegion(std::string input)
{
  TFile *MyFile = new TFile(("/data/ccaillol/tauid_20june_mm/"+input+".root").c_str());
  TTree *Tree = (TTree*) MyFile->Get("mutau_tree");
  TH1F* nevents = (TH1F*) MyFile->Get("nevents");
  float TotalNumberOfEvents = nevents->GetBinContent(1);
  
  //Variables for the tree branches
  int run,lumi,evt,NUP;
  float npv,npu,numGenJets,amcatNLO_weight;
  float pt_1,phi_1,eta_1,m_1,e_1,q_1,d0_1,dZ_1,iso_1,id_m_medium_1,id_m_tight_1;
  float pt_2,phi_2,eta_2,m_2,e_2,q_2,d0_2,dZ_2,iso_2,id_m_medium_2,id_m_tight_2;
  float matchIsoMu27_1,matchIsoMu27_2;
  float pt_top1,pt_top2,genweight,gen_match_2,gen_match_1,met,metphi;
  int nbtag,njets;
  Tree->SetBranchAddress("run",&run);
  Tree->SetBranchAddress("lumi",&lumi);
  Tree->SetBranchAddress("evt",&evt);
  Tree->SetBranchAddress("NUP",&NUP);
  Tree->SetBranchAddress("npv",&npv);
  Tree->SetBranchAddress("npu",&npu);
  Tree->SetBranchAddress("numGenJets", &numGenJets);
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
  Tree->SetBranchAddress("id_m_medium_2",&id_m_medium_2);
  Tree->SetBranchAddress("id_m_tight_2",&id_m_tight_2);
  Tree->SetBranchAddress("matchIsoMu27_1", &matchIsoMu27_1);
  Tree->SetBranchAddress("matchIsoMu27_2", &matchIsoMu27_2);
  Tree->SetBranchAddress("pt_top1", &pt_top1);
  Tree->SetBranchAddress("pt_top2", &pt_top2);
  Tree->SetBranchAddress("genweight", &genweight);
  Tree->SetBranchAddress("gen_match_2", &gen_match_2);
  Tree->SetBranchAddress("gen_match_1", &gen_match_1);
  Tree->SetBranchAddress("met", &met);
  Tree->SetBranchAddress("metphi", &metphi);
  Tree->SetBranchAddress("nbtag", &nbtag);
  Tree->SetBranchAddress("njets", &njets);
  
  int NumberOfEntries = (int) Tree->GetEntries();
  
  TH1F* SignalRegion = new TH1F(input.c_str(),
				input.c_str(),
				20,
				60.0,
				120.0);
  // for processing drell yan events
  TH1F* GenMatchSignalRegion = new TH1F(("GenMatch_"+input).c_str(),
					("GenMatch_"+input).c_str(),
					20,
					60.0,
					120.0);
  TH1F* LowGenMatchSignalRegion = new TH1F(("LowGenMatch_"+input).c_str(),
					   ("LowGenMatch_"+input).c_str(),
					   20,
					   60.0,
					   120.0);
  TH1F* HighGenMatchSignalRegion = new TH1F(("HighGenMatch_"+input).c_str(),
					    ("HighGenMatch_"+input).c_str(),
					    20,
					    60.0,
					    120.0);

  //QCD
  TH1F* QCDRegion= new TH1F((input+"_QCD").c_str(),
			    (input+"_QCD").c_str(),
			    20,
			    60.0,
			    120.0);
  

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
  LumiWeights_12 = new reweight::LumiReWeighting(("/data/ccaillol/tauid_20june_mm/"+input+".root").c_str(),
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

      TLorentzVector l1; l1.SetPtEtaPhiE(pt_1, eta_1, phi_1, e_1); //muon
      TLorentzVector l2; l2.SetPtEtaPhiE(pt_2, eta_2, phi_2, e_2); //tau

      if(pt_1 < 29.0 or std::abs(eta_1) > 2.1 or !id_m_medium_1 or iso_1 > 0.15 or std::abs(dZ_1) > 0.2 or std::abs(d0_1) > 0.045 or !matchIsoMu27_1) continue;
      if(pt_2 < 29.0 or std::abs(eta_2) > 2.1 or !id_m_medium_2 or iso_2 > 0.15 or std::abs(dZ_2) > 0.2 or std::abs(d0_2) > 0.045 or !matchIsoMu27_2) continue;

      //pair criteria
      if(q_1*q_2 >= 0.0 or (l1+l2).M() >= 120.0 or (l1+l2).M() <= 60.0) continue;

      float deltaphi = std::abs(phi_1-phi_2);
      if (deltaphi > M_PI) deltaphi-=2.0*M_PI;
      float DeltaR = std::sqrt((eta_1-eta_2)*(eta_1-eta_2)+deltaphi*deltaphi);
      if(DeltaR <= 0.5)  continue;
      
      //We can sort of still do the transverse mass and zeta criteria?
      TLorentzVector MissingP;
      MissingP.SetPtEtaPhiM(met,0,metphi,0);
      
      float TransverseMass = std::sqrt(2.0*l1.Pt()*MissingP.Pt()*(1.0-std::cos(l1.DeltaPhi(MissingP))));      
            
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
      
      float PZetaVis = (l1.Vect()+l2.Vect()).Dot(ZetaUnit);
      float PZetaAll = (l1.Vect()+l2.Vect()+MissingP.Vect()).Dot(ZetaUnit);
      float PZeta = PZetaAll - 0.85 * PZetaVis;      

      //Create the weighting
      float PileupWeight = LumiWeights_12->weight(npu);
      
      float muTriggerSF_1 = TriggerWeightings->GetBinContent(TriggerWeightings->FindBin(fabs(l1.Eta()),l1.Pt()));
      float muIDSF_1 =  IDWeightings->GetBinContent(IDWeightings->FindBin(l1.Pt(),fabs(l1.Eta())));
      float muISOSF_1 =  ISOWeightings->GetBinContent(ISOWeightings->FindBin(l1.Pt(),fabs(l1.Eta())));

      float muTriggerSF_2 = TriggerWeightings->GetBinContent(TriggerWeightings->FindBin(fabs(l2.Eta()),l2.Pt()));
      float muIDSF_2 =  IDWeightings->GetBinContent(IDWeightings->FindBin(l2.Pt(),fabs(l2.Eta())));
      float muISOSF_2 =  ISOWeightings->GetBinContent(ISOWeightings->FindBin(l2.Pt(),fabs(l2.Eta())));

      if(input == "WW")NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF_1*muIDSF_1*muISOSF_1*muTriggerSF_2*muIDSF_2*muISOSF_2;
      else if(input == "WZ") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF_1*muIDSF_1*muISOSF_1*muTriggerSF_2*muIDSF_2*muISOSF_2;
      else if(input == "ZZ") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF_1*muIDSF_1*muISOSF_1*muTriggerSF_2*muIDSF_2*muISOSF_2;            
      // from the excel file.
      else if(input == "W"
	      or input == "W1"
	      or input == "W2"
	      or input == "W3"
	      or input == "W4") 
	{
	  NormalizationWeight = PileupWeight*muTriggerSF_1*muIDSF_1*muISOSF_1*muTriggerSF_2*muIDSF_2*muISOSF_2;	  
	  
	  if(numGenJets==0) NormalizationWeight = NormalizationWeight*110.1887;
	  if(numGenJets==1) NormalizationWeight = NormalizationWeight*14.1549;
	  if(numGenJets==2) NormalizationWeight = NormalizationWeight*7.42847;
	  if(numGenJets==3) NormalizationWeight = NormalizationWeight*2.40205;
	  if(numGenJets==4) NormalizationWeight = NormalizationWeight*2.140756;
	}
      else if(input == "TTTo2L2Nu") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF_1*muIDSF_1*muISOSF_1*muTriggerSF_2*muIDSF_2*muISOSF_2;
      else if(input == "TTToHadronic") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF_1*muIDSF_1*muISOSF_1*muTriggerSF_2*muIDSF_2*muISOSF_2;
      else if(input == "TTToSemiLeptonic") NormalizationWeight = XSecWeight*PileupWeight*muTriggerSF_1*muIDSF_1*muISOSF_1*muTriggerSF_2*muIDSF_2*muISOSF_2;

      else if(input == "DY"
	      or input == "DY1"
	      or input == "DY2"
	      or input == "DY3"
	      or input == "DY4")
	{	  
	  NormalizationWeight = PileupWeight*muTriggerSF_1*muIDSF_1*muISOSF_1*muTriggerSF_2*muIDSF_2*muISOSF_2;
	  
	  if(numGenJets==0) NormalizationWeight = NormalizationWeight*3.009;
	  if(numGenJets==1) NormalizationWeight = NormalizationWeight*0.589;
	  if(numGenJets==2) NormalizationWeight = NormalizationWeight*0.621;
	  if(numGenJets==3) NormalizationWeight = NormalizationWeight*0.764;
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
      
      if(q_1 * q_2 < 0.0 /*and TransverseMass < 40.0 and PZeta > -25.0*/)
	{	  
	  SignalRegion->Fill(Var,NormalizationWeight);
	}
      else if(q_1 * q_2 > 0.0 /*and TransverseMass < 40.0 and PZeta > -25.0*/)
	{
	  QCDRegion->Fill(Var,NormalizationWeight);
	}
    }
  std::cout<<std::endl;

  TFile* OutFile = new TFile(("../TemporaryFiles/"+input+"_MuMu.root").c_str(),"RECREATE");
  SignalRegion->Write();
  QCDRegion->Write();
  OutFile->Close();
}
