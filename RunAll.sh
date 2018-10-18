#!/usr/bin/bash
#Takes the isolation working point in as it's first argument
#That is: VLoose all the way up to VVTight. Spelled that way.
#Until I sort out what the issue is with the cnsenv root setup
# we have the two old lines in this script
sh GoofyRootSetup.sh

#run the ID code over all the available distributions.
#these the "basic" distributions
root -b -q TauID.cc\(\"Data\",\"$1\"\)
root -b -q -l TauID.cc\(\"WW\",\"$1\"\)
root -b -q -l TauID.cc\(\"WZ\",\"$1\"\)
root -b -q -l TauID.cc\(\"ZZ\",\"$1\"\)
root -b -q -l TauID.cc\(\"W\",\"$1\"\)
root -b -q -l TauID.cc\(\"W1\",\"$1\"\)
root -b -q -l TauID.cc\(\"W2\",\"$1\"\)
root -b -q -l TauID.cc\(\"W3\",\"$1\"\)
root -b -q -l TauID.cc\(\"W4\",\"$1\"\)
root -b -q -l TauID.cc\(\"TTTo2L2Nu\",\"$1\"\)
root -b -q -l TauID.cc\(\"TTToHadronic\",\"$1\"\)
root -b -q -l TauID.cc\(\"TTToSemiLeptonic\",\"$1\"\)
root -b -q -l TauID.cc\(\"DY\",\"$1\"\)
root -b -q -l TauID.cc\(\"DY1\",\"$1\"\)
root -b -q -l TauID.cc\(\"DY2\",\"$1\"\)
root -b -q -l TauID.cc\(\"DY3\",\"$1\"\)
root -b -q -l TauID.cc\(\"DY4\",\"$1\"\)

#Do the Tau Energy Scale Uncertainties.
#right now the combine code seems to only want TES on TT, QCD, and Diboson distributions
#TT and VV are easy.
root -b -q -l TauID.cc\(\"TTTo2L2Nu\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"TTToHadronic\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"TTToSemiLeptonic\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"TTTo2L2Nu\",\"$1\",0.97\)
root -b -q -l TauID.cc\(\"TTToHadronic\",\"$1\",0.97\)
root -b -q -l TauID.cc\(\"TTToSemiLeptonic\",\"$1\",0.97\)

root -b -q -l TauID.cc\(\"WW\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"WZ\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"ZZ\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"WW\",\"$1\",0.97\)
root -b -q -l TauID.cc\(\"WZ\",\"$1\",0.97\)
root -b -q -l TauID.cc\(\"ZZ\",\"$1\",0.97\)

#How do we Handle the TES for QCD regions?
#Best Guess? simply run all other distributions in up or down, then do the QCD 
#generation with those samples.

#W
root -b -q -l TauID.cc\(\"W\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"W1\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"W2\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"W3\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"W4\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"W\",\"$1\",0.97\)
root -b -q -l TauID.cc\(\"W1\",\"$1\",0.97\)
root -b -q -l TauID.cc\(\"W2\",\"$1\",0.97\)
root -b -q -l TauID.cc\(\"W3\",\"$1\",0.97\)
root -b -q -l TauID.cc\(\"W4\",\"$1\",0.97\)

#DY
root -b -q -l TauID.cc\(\"DY\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"DY1\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"DY2\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"DY3\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"DY4\",\"$1\",1.03\)
root -b -q -l TauID.cc\(\"DY\",\"$1\",0.97\)
root -b -q -l TauID.cc\(\"DY1\",\"$1\",0.97\)
root -b -q -l TauID.cc\(\"DY2\",\"$1\",0.97\)
root -b -q -l TauID.cc\(\"DY3\",\"$1\",0.97\)
root -b -q -l TauID.cc\(\"DY4\",\"$1\",0.97\)

#Do the Mu To Tau Misidentification shape uncertainty?
root -b -q -l TauID.cc\(\"DY\",\"$1\",1.10\)
root -b -q -l TauID.cc\(\"DY1\",\"$1\",1.10\)
root -b -q -l TauID.cc\(\"DY2\",\"$1\",1.10\)
root -b -q -l TauID.cc\(\"DY3\",\"$1\",1.10\)
root -b -q -l TauID.cc\(\"DY4\",\"$1\",1.10\)
root -b -q -l TauID.cc\(\"DY\",\"$1\",0.90\)
root -b -q -l TauID.cc\(\"DY1\",\"$1\",0.90\)
root -b -q -l TauID.cc\(\"DY2\",\"$1\",0.90\)
root -b -q -l TauID.cc\(\"DY3\",\"$1\",0.90\)
root -b -q -l TauID.cc\(\"DY4\",\"$1\",0.90\)

hadd -f Distributions/PassFailOut.root TemporaryFiles/Signal*.root
hadd -f Distributions/WJetsDistributions.root TemporaryFiles/WJets_*.root
hadd -f Distributions/QCDDistributions.root TemporaryFiles/QCD_*.root
hadd -f Distributions/WJetsQCDContributions.root TemporaryFiles/QCDinWJets_*.root

root -b -q -l EstimateQCDinWJets.cc
root -b -q -l WJetsSimToData.cc
root -b -q -l FinalizeQCDBackground.cc

#This script now handles the running of all jet to tau fake rate stuff.
cd JetToTauFakeRate/
sh RunJetToTauFake.sh $1
cd ../

sh DoPostProcessing.sh $1
