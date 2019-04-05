#!/usr/bin/bash

hadd -f Distributions/PassFailOut.root TemporaryFiles/Signal*.root
hadd -f Distributions/WJetsDistributions.root TemporaryFiles/WJets_*.root
hadd -f Distributions/QCDDistributions.root TemporaryFiles/QCD_*.root
hadd -f Distributions/WJetsQCDContributions.root TemporaryFiles/QCDinWJets_*.root

root -b -q -l EstimateQCDinWJets.cc
root -b -q -l WJetsSimToData.cc
root -b -q -l FinalizeQCDBackground.cc