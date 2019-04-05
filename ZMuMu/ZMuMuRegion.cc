#include "TROOT.h"
//#include "/afs/cern.ch/user/a/aloelige/private/RootMacros/LumiReweightingStandAlone.h"
#include "/data/aloeliger/CMSSW_9_4_0/src/PhysicsTools/Utilities/interface/LumiReweightingStandAlone.h"
#include <string>
#include "../Zpt/zptweight.C"

void ZMuMuRegion(std::string input)
{
  TFile *MyFile = new TFile(("/data/aloeliger/CMSSW_9_4_0/src/SMHTTAnalysis/SkimmedNtuples/TauID2017_mm/"+input+".root").c_str());
  //TFile *MyFile = new TFile(("/data/ccaillol/tauid_20june_mm/"+input+".root").c_str());
  TTree *Tree = (TTree*) MyFile->Get("mutau_tree");
  TH1F* nevents = (TH1F*) MyFile->Get("summedWeights");
  //TH1F* nevents = (TH1F*) MyFile->Get("nevents");
  float TotalNumberOfEvents = nevents->GetBinContent(1);

  readZptFile();
  
  //Variables for the tree branches
  UInt_t run,lumi;
  //Int_t run,lumi;
  Float_t evt;
  //Int_t evt;
  Float_t NUP;
  float npv,npu,numGenJets,amcatNLO_weight;
  float pt_1,phi_1,eta_1,m_1,e_1,q_1,d0_1,dZ_1,iso_1,id_m_medium_1,id_m_tight_1;
  float pt_2,phi_2,eta_2,m_2,e_2,q_2,d0_2,dZ_2,iso_2,id_m_medium_2,id_m_tight_2;
  float matchIsoMu27_1,matchIsoMu27_2;
  float pt_top1,pt_top2,genweight,gen_match_2,gen_match_1,met,metphi;
  Float_t nbtag,njets;
  Float_t PZeta;
  // needed for ZPT reweighting
  float genpT;
  float genM;

  //Int_t nbtag,njets;
  Tree->SetBranchAddress("run",&run);
  Tree->SetBranchAddress("lumi",&lumi);
  Tree->SetBranchAddress("evt",&evt);
  //Tree->SetBranchAddress("NUP",&NUP);
  Tree->SetBranchAddress("npv",&npv);
  Tree->SetBranchAddress("npu",&npu);
  Tree->SetBranchAddress("numGenJets", &numGenJets);
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
  Tree->SetBranchAddress("id_m_medium_2",&id_m_medium_2);
  Tree->SetBranchAddress("id_m_tight_2",&id_m_tight_2);
  Tree->SetBranchAddress("matchIsoMu27_1", &matchIsoMu27_1);
  Tree->SetBranchAddress("matchIsoMu27_2", &matchIsoMu27_2);
  Tree->SetBranchAddress("pt_top1", &pt_top1);
  Tree->SetBranchAddress("pt_top2", &pt_top2);
  //Tree->SetBranchAddress("genweight", &genweight);
  Tree->SetBranchAddress("gen_match_2", &gen_match_2);
  Tree->SetBranchAddress("gen_match_1", &gen_match_1);
  Tree->SetBranchAddress("met", &met);
  Tree->SetBranchAddress("metphi", &metphi);
  Tree->SetBranchAddress("nbtag", &nbtag);
  Tree->SetBranchAddress("njets", &njets);  
  Tree->SetBranchAddress("PZeta", &PZeta);
  //needed for ZPT reweighting
  Tree->SetBranchAddress("genpT", &genpT);
  Tree->SetBranchAddress("genM", &genM);

  int NumberOfEntries = (int) Tree->GetEntries();
  
  TH1D* SignalRegion = new TH1D(input.c_str(),
				input.c_str(),
				1,
				70.0,
				110.0);  

  //control plots
  TH1D* MuPt_One = new TH1D((input+"_MuPt_One").c_str(),
			    (input+"_MuPt_One").c_str(),
			    100,
			    0.0,
			    200.0);
  TH1D* MuPt_Two = new TH1D((input+"_MuPt_Two").c_str(),
			    (input+"_MuPt_Two").c_str(),
			    100,
			    0.0,
			    200.0);
  TH1D* MuEta_One = new TH1D((input+"_MuEta_One").c_str(),
			     (input+"_MuEta_One").c_str(),
			     100,
			     -4.0,
			     4.0);
  TH1D* MuEta_Two = new TH1D((input+"_MuEta_Two").c_str(),
			     (input+"_MuEta_Two").c_str(),
			     100,
			     -4.0,
			     4.0);
  TH1D* NJet_Control = new TH1D((input+"_njets").c_str(),
				(input+"_njets").c_str(),
				5,
				0.0,
				5.0);
  TH1D* NBtag_Control = new TH1D((input+"_nbtag").c_str(),
				 (input+"_nbtag").c_str(),
				 5,
				 0.0,
				 5.0);
  TH1D* ZMass = new TH1D((input+"_ZMass").c_str(),
			 (input+"_ZMass").c_str(),
			 120.0,
			 30.0,
			 150.0);
  TH1D* ZPT = new TH1D((input+"_ZPT").c_str(),
		       (input+"_ZPT").c_str(),
		       100.0,
		       0.0,
		       500.0);
  

  //QCD
  TH1D* QCDRegion= new TH1D((input+"_QCD").c_str(),
			    (input+"_QCD").c_str(),
			    SignalRegion->GetNbinsX(),
			    SignalRegion->GetXaxis()->GetXmin(),
			    SignalRegion->GetXaxis()->GetXmax());
  

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

  //28/2/19 EDIT: Changed path to look like our new one
  reweight::LumiReWeighting* LumiWeights_12;
  LumiWeights_12 = new reweight::LumiReWeighting(("/data/aloeliger/CMSSW_9_4_0/src/SMHTTAnalysis/SkimmedNtuples/TauID2017_mm/"+input+".root").c_str(),
						 //LumiWeights_12 = new reweight::LumiReWeighting(("/data/ccaillol/tauid_20june_mm/"+input+".root").c_str(),
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

  double AcceptedEvents = 0.0;
  long long AcceptedEvents_Two = 0;
  double NormWeights = 0.0;
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

      TLorentzVector l1; l1.SetPtEtaPhiM(pt_1, eta_1, phi_1, m_1); //muon
      TLorentzVector l2; l2.SetPtEtaPhiM(pt_2, eta_2, phi_2, m_2); //tau
      
      //These are cecile's criteria
      /*
	if (pt_1<29 && pt_2<29) continue;
	if (pt_1<20 or pt_2<20) continue;
	if (fabs(eta_1)>2.4) continue;
	if (fabs(eta_2)>2.4) continue;
	if (!(matchIsoMu27_1 && pt_1>29) && !(matchIsoMu27_2 && pt_2>29)) continue;
      */
      if(pt_1 < 20.0 or std::abs(eta_1) > 2.4 or !id_m_medium_1 or iso_1 > 0.15 or std::abs(dZ_1) > 0.2 or std::abs(d0_1) > 0.045 /*or !matchIsoMu27_1*/) continue;
      if(pt_2 < 20.0 or std::abs(eta_2) > 2.4 or !id_m_medium_2 or iso_2 > 0.15 or std::abs(dZ_2) > 0.2 or std::abs(d0_2) > 0.045 /*or !matchIsoMu27_2*/) continue;

      //if (!(matchIsoMu27_1 && pt_1>29) && !(matchIsoMu27_2 && pt_2>29)) continue;
      //just my own little test
      //match to diego's muon pt > 30 cut as opposed to my 29.0 cut.
      if(matchIsoMu27_1 && !matchIsoMu27_2 && !(pt_1 > 30.0)) continue;
      if(matchIsoMu27_2 && !matchIsoMu27_1 && !(pt_2 > 30.0)) continue;
      if(matchIsoMu27_1 && matchIsoMu27_2 && !(pt_1 >30.0 || pt_2 > 30.0)) continue;
      if(!matchIsoMu27_1 && !matchIsoMu27_2) continue;
      if(!(pt_1>30.0) && !(pt_2>30.0))continue;
      //experimental cut
      if(pt_1 < 30.0) continue;
      if(pt_2 < 30.0) continue;
      
      //pair criteria
      if(q_1*q_2 >= 0.0 or (l1+l2).M() >= 110.0 or (l1+l2).M() <= 70.0) continue;

      float deltaphi = std::abs(phi_1-phi_2);
      if (deltaphi > M_PI) deltaphi-=2.0*M_PI;
      float DeltaR = std::sqrt((eta_1-eta_2)*(eta_1-eta_2)+deltaphi*deltaphi);
      if(DeltaR <= 0.5)  continue;

      //We can sort of still do the transverse mass and zeta criteria?
      TLorentzVector MissingP;
      MissingP.SetPtEtaPhiM(met,0,metphi,0);
      
      float TransverseMass = std::sqrt(2.0*l1.Pt()*MissingP.Pt()*(1.0-std::cos(l1.DeltaPhi(MissingP))));

      //Create the weighting
      float PileupWeight = LumiWeights_12->weight(npu);

      float muTriggerSF_1 = TriggerWeightings->GetBinContent(TriggerWeightings->FindBin(fabs(l1.Eta()),l1.Pt()));
      float muIDSF_1;
      if(l1.Pt() < 120.0) muIDSF_1 =  IDWeightings->GetBinContent(IDWeightings->FindBin(l1.Pt(),fabs(l1.Eta())));
      else muIDSF_1 =  IDWeightings->GetBinContent(IDWeightings->FindBin(119.0,fabs(l1.Eta())));
      float muISOSF_1;
      if(l1.Pt() < 120.0) muISOSF_1 =  ISOWeightings->GetBinContent(ISOWeightings->FindBin(l1.Pt(),fabs(l1.Eta())));
      else muISOSF_1 =  ISOWeightings->GetBinContent(ISOWeightings->FindBin(119.0,fabs(l1.Eta())));

      float muTriggerSF_2 = TriggerWeightings->GetBinContent(TriggerWeightings->FindBin(fabs(l2.Eta()),l2.Pt()));
      float muIDSF_2;
      if(l2.Pt() < 120.0) muIDSF_2 =  IDWeightings->GetBinContent(IDWeightings->FindBin(l2.Pt(),fabs(l2.Eta())));
      else muIDSF_2 =  IDWeightings->GetBinContent(IDWeightings->FindBin(119.0,fabs(l2.Eta())));
      float muISOSF_2;
      if(l2.Pt() < 120.0) muISOSF_2 =  ISOWeightings->GetBinContent(ISOWeightings->FindBin(l2.Pt(),fabs(l2.Eta())));
      else muISOSF_2 =  ISOWeightings->GetBinContent(ISOWeightings->FindBin(119.0,fabs(l2.Eta())));

      if(input == "WW")NormalizationWeight = XSecWeight*PileupWeight*muIDSF_1*muISOSF_1*muIDSF_2*muISOSF_2;
      else if(input == "WZ") NormalizationWeight = XSecWeight*PileupWeight*muIDSF_1*muISOSF_1*muIDSF_2*muISOSF_2;
      else if(input == "ZZ") NormalizationWeight = XSecWeight*PileupWeight*muIDSF_1*muISOSF_1*muIDSF_2*muISOSF_2;            
      // from the excel file.
      else if(input == "W"
	      or input == "W1"
	      or input == "W2"
	      or input == "W3"
	      or input == "W4") 
	{
	  NormalizationWeight = PileupWeight*muIDSF_1*muISOSF_1*muIDSF_2*muISOSF_2;	  
	  
	  /*
	  if(numGenJets==0) NormalizationWeight = NormalizationWeight*110.1887;
	  if(numGenJets==1) NormalizationWeight = NormalizationWeight*14.1549;
	  if(numGenJets==2) NormalizationWeight = NormalizationWeight*7.42847;
	  if(numGenJets==3) NormalizationWeight = NormalizationWeight*2.40205;
	  if(numGenJets==4) NormalizationWeight = NormalizationWeight*2.140756;
	  */
	  
	  if(numGenJets==0) NormalizationWeight = NormalizationWeight*34.644;
	  if(numGenJets==1) NormalizationWeight = NormalizationWeight*4.2559;
	  if(numGenJets==2) NormalizationWeight = NormalizationWeight*17.668;
	  if(numGenJets==3) NormalizationWeight = NormalizationWeight*1.9254;
	  if(numGenJets==4) NormalizationWeight = NormalizationWeight*2.7165;
	}
      else if(input == "TTTo2L2Nu") NormalizationWeight = XSecWeight*PileupWeight*muIDSF_1*muISOSF_1*muIDSF_2*muISOSF_2;
      else if(input == "TTToHadronic") NormalizationWeight = XSecWeight*PileupWeight*muIDSF_1*muISOSF_1*muIDSF_2*muISOSF_2;
      else if(input == "TTToSemiLeptonic") NormalizationWeight = XSecWeight*PileupWeight*muIDSF_1*muISOSF_1*muIDSF_2*muISOSF_2;

      else if(input == "DY"
	      or input == "DY1"
	      or input == "DY2"
	      or input == "DY3"
	      or input == "DY4")
	{	  
	  NormalizationWeight = PileupWeight*muIDSF_1*muISOSF_1*muIDSF_2*muISOSF_2;
	  
	  /*
	  if(numGenJets==0) NormalizationWeight = NormalizationWeight*3.264;
	  if(numGenJets==1) NormalizationWeight = NormalizationWeight*0.638;
	  if(numGenJets==2) NormalizationWeight = NormalizationWeight*0.673;
	  if(numGenJets==3) NormalizationWeight = NormalizationWeight*0.829;
	  if(numGenJets==4) NormalizationWeight = NormalizationWeight*0.748;
	  */

	  
	  if(numGenJets==0) NormalizationWeight = NormalizationWeight*2.373;
	  if(numGenJets==1) NormalizationWeight = NormalizationWeight*0.804;
	  if(numGenJets==2) NormalizationWeight = NormalizationWeight*0.816;
	  if(numGenJets==3) NormalizationWeight = NormalizationWeight*0.546;
	  if(numGenJets==4) NormalizationWeight = NormalizationWeight*0.478;

	  //ZPT Reweighting
	  float ZPTWeight = getZpt_2017(genM,genpT);
	  NormalizationWeight = NormalizationWeight*ZPTWeight;	  
	}
      else if(input == "ST_top") NormalizationWeight = XSecWeight*PileupWeight*muIDSF_1*muISOSF_1*muIDSF_2*muISOSF_2;
      else if(input == "ST_antitop") NormalizationWeight = XSecWeight*PileupWeight*muIDSF_1*muISOSF_1*muIDSF_2*muISOSF_2;
      else if(input == "ST_tW_top") NormalizationWeight = XSecWeight*PileupWeight*muIDSF_1*muISOSF_1*muIDSF_2*muISOSF_2;
      else if(input == "ST_tW_antitop") NormalizationWeight = XSecWeight*PileupWeight*muIDSF_1*muISOSF_1*muIDSF_2*muISOSF_2;
      else if(input == "Data") NormalizationWeight = 1.0;          
      else
	{
	  std::cout<<"ERROR! Unrecognized Sample! Defaulting to unweighted events!"<<std::endl;
	  NormalizationWeight = 1.0;
	}
      if(matchIsoMu27_1) NormalizationWeight = NormalizationWeight * muTriggerSF_1;
      if(matchIsoMu27_2) NormalizationWeight = NormalizationWeight * muTriggerSF_2;

      NormalizationWeight = NormalizationWeight*amcatNLO_weight;      
      if(input == "Data") NormalizationWeight = 1.0;      

      //Data Selection
      float Var = (l1+l2).M();                  
      //float Var = njets;
      //float Var = (l1+l2).Pt();
      if(q_1 * q_2 < 0.0 /*and TransverseMass < 50.0 and PZeta > -25.0*/)
	{ 
	  AcceptedEvents+=1.0;
	  AcceptedEvents_Two++;
	  NormWeights+=NormalizationWeight;
	  SignalRegion->Fill(Var,NormalizationWeight);	  	  

	  //fill control plots
	  MuPt_One->Fill(l1.Pt(),NormalizationWeight);
	  MuPt_Two->Fill(l2.Pt(),NormalizationWeight);
	  MuEta_One->Fill(l1.Eta(),NormalizationWeight);
	  MuEta_Two->Fill(l2.Eta(),NormalizationWeight);
	  NJet_Control->Fill(njets,NormalizationWeight);
	  NBtag_Control->Fill(nbtag,NormalizationWeight);
	  ZMass->Fill((l1+l2).M(),NormalizationWeight);
	  ZPT->Fill((l1+l2).Pt(),NormalizationWeight);
	  
	}
      else if(q_1 * q_2 > 0.0 /*and TransverseMass < 40.0 and PZeta > -25.0*/)
	{
	  QCDRegion->Fill(Var,NormalizationWeight);
	}
    }
  std::cout<<std::endl;
  std::cout<<"AcceptedEvents: "<<AcceptedEvents<<std::endl;
  std::cout<<"AcceptedEvents_Two:"<<AcceptedEvents_Two<<std::endl;
  std::cout<<"SignalRegion->Integral(): "<<SignalRegion->Integral()<<std::endl;
  std::cout<<"Avg Norm Weight: "<<NormWeights/AcceptedEvents<<std::endl;

  TFile* OutFile = new TFile(("../TemporaryFiles/"+input+"_MuMu.root").c_str(),"RECREATE");
  SignalRegion->Write();
  QCDRegion->Write();  
  
  MuPt_One->Write();
  MuPt_Two->Write();
  MuEta_One->Write();
  MuEta_Two->Write();
  NJet_Control->Write();
  NBtag_Control->Write();
  ZMass->Write();
  ZPT->Write();

  OutFile->Close();
}
