#!/usr/bin/bash
#run the ID code over all the available distributions.
root -b -q "TauID.cc(\"Data\")"
root -b -q "TauID.cc(\"WW\")"
root -b -q "TauID.cc(\"WZ\")"
root -b -q "TauID.cc(\"ZZ\")"
root -b -q "TauID.cc(\"W\")" #is this the W+jets low Mt sample?
root -b -q "TauID.cc(\"TTTo2L2Nu\")"
root -b -q "TauID.cc(\"TTToHadronic\")"
root -b -q "TauID.cc(\"TTToSemiLeptonic\")"
root -b -q "TauID.cc(\"DY\")"
hadd -f PassFailOut.root TemporaryFiles/Signal*.root
hadd -f WJetsDistributions.root TemporaryFiles/WJets_*.root
hadd -f QCDDistributions.root TemporaryFiles/QCD_*.root
hadd -f WJetsQCDContributions.root TemporaryFiles/QCDinWJets_*.root

root -b -q EstimateQCDinWJets.cc
root -b -q WJetsSimToData.cc
root -b -q FinalizeQCDBackground.cc
root -b -q CompileHistograms.cc