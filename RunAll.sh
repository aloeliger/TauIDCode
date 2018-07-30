#!/usr/bin/bash

#Until I sort out what the issue is with the cnsenv root setup
# we have the two old lines in this script
sh GoofyRootSetup.sh

#run the ID code over all the available distributions.
#these the "basic" distributions
root -b -q "TauID.cc(\"Data\")"
root -b -q -l "TauID.cc(\"WW\")"
root -b -q -l "TauID.cc(\"WZ\")"
root -b -q -l "TauID.cc(\"ZZ\")"
root -b -q -l "TauID.cc(\"W\")"
root -b -q -l "TauID.cc(\"W1\")"
root -b -q -l "TauID.cc(\"W2\")"
root -b -q -l "TauID.cc(\"W3\")"
root -b -q -l "TauID.cc(\"W4\")"
root -b -q -l "TauID.cc(\"TTTo2L2Nu\")"
root -b -q -l "TauID.cc(\"TTToHadronic\")"
root -b -q -l "TauID.cc(\"TTToSemiLeptonic\")"
root -b -q -l "TauID.cc(\"DY\")"
root -b -q -l "TauID.cc(\"DY1\")"
root -b -q -l "TauID.cc(\"DY2\")"
root -b -q -l "TauID.cc(\"DY3\")"
root -b -q -l "TauID.cc(\"DY4\")"

#Do the Tau Energy Scale Uncertainties.
#right now the combine code seems to only want TES on TT, QCD, and Diboson distributions
#TT and VV are easy.
root -b -q -l "TauID.cc(\"TTTo2L2Nu\",1.03)"
root -b -q -l "TauID.cc(\"TTToHadronic\",1.03)"
root -b -q -l "TauID.cc(\"TTToSemiLeptonic\",1.03)"
root -b -q -l "TauID.cc(\"TTTo2L2Nu\",0.97)"
root -b -q -l "TauID.cc(\"TTToHadronic\",0.97)"
root -b -q -l "TauID.cc(\"TTToSemiLeptonic\",0.97)"

root -b -q -l "TauID.cc(\"WW\",1.03)"
root -b -q -l "TauID.cc(\"WZ\",1.03)"
root -b -q -l "TauID.cc(\"ZZ\",1.03)"
root -b -q -l "TauID.cc(\"WW\",0.97)"
root -b -q -l "TauID.cc(\"WZ\",0.97)"
root -b -q -l "TauID.cc(\"ZZ\",0.97)"

#How do we Handle the TES for QCD regions?
#Best Guess? simply run all other distributions in up or down, then do the QCD 
#generation with those samples.

#W
root -b -q -l "TauID.cc(\"W\",1.03)"
root -b -q -l "TauID.cc(\"W1\",1.03)"
root -b -q -l "TauID.cc(\"W2\",1.03)"
root -b -q -l "TauID.cc(\"W3\",1.03)"
root -b -q -l "TauID.cc(\"W4\",1.03)"
root -b -q -l "TauID.cc(\"W\",0.97)"
root -b -q -l "TauID.cc(\"W1\",0.97)"
root -b -q -l "TauID.cc(\"W2\",0.97)"
root -b -q -l "TauID.cc(\"W3\",0.97)"
root -b -q -l "TauID.cc(\"W4\",0.97)"

#DY
root -b -q -l "TauID.cc(\"DY\",1.03)"
root -b -q -l "TauID.cc(\"DY1\",1.03)"
root -b -q -l "TauID.cc(\"DY2\",1.03)"
root -b -q -l "TauID.cc(\"DY3\",1.03)"
root -b -q -l "TauID.cc(\"DY4\",1.03)"
root -b -q -l "TauID.cc(\"DY\",0.97)"
root -b -q -l "TauID.cc(\"DY1\",0.97)"
root -b -q -l "TauID.cc(\"DY2\",0.97)"
root -b -q -l "TauID.cc(\"DY3\",0.97)"
root -b -q -l "TauID.cc(\"DY4\",0.97)"

#Do the Mu To Tau Misidentification shape uncertainty?
root -b -q -l "TauID.cc(\"DY\",1.10)"
root -b -q -l "TauID.cc(\"DY1\",1.10)"
root -b -q -l "TauID.cc(\"DY2\",1.10)"
root -b -q -l "TauID.cc(\"DY3\",1.10)"
root -b -q -l "TauID.cc(\"DY4\",1.10)"
root -b -q -l "TauID.cc(\"DY\",0.90)"
root -b -q -l "TauID.cc(\"DY1\",0.90)"
root -b -q -l "TauID.cc(\"DY2\",0.90)"
root -b -q -l "TauID.cc(\"DY3\",0.90)"
root -b -q -l "TauID.cc(\"DY4\",0.90)"

hadd -f Distributions/PassFailOut.root TemporaryFiles/Signal*.root
hadd -f Distributions/WJetsDistributions.root TemporaryFiles/WJets_*.root
hadd -f Distributions/QCDDistributions.root TemporaryFiles/QCD_*.root
hadd -f Distributions/WJetsQCDContributions.root TemporaryFiles/QCDinWJets_*.root

root -b -q -l EstimateQCDinWJets.cc
root -b -q -l WJetsSimToData.cc
root -b -q -l FinalizeQCDBackground.cc

#This script now handles the running of all jet to tau fake rate stuff.
cd JetToTauFakeRate/
sh RunJetToTauFake.sh
cd ../

root -l CompileHistograms.cc
root -b -q -l PrepForCombine.cc
#because I can't get combine to compile properly on the lxplus servers
# we now turn this over to the Wiscosin computers.
cp Distributions/CombineFile.root /afs/cern.ch/user/a/aloelige/public/
