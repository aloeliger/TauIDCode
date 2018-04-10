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
hadd -f PassFailOut.root TemporaryFiles/*PassFail*

root -b -q "WJetsDistributionCreation.cc(\"Data\")"
root -b -q "WJetsDistributionCreation.cc(\"WW\")"
root -b -q "WJetsDistributionCreation.cc(\"WZ\")"
root -b -q "WJetsDistributionCreation.cc(\"ZZ\")"
root -b -q "WJetsDistributionCreation.cc(\"W\")"
root -b -q "WJetsDistributionCreation.cc(\"TTTo2L2Nu\")"
root -b -q "WJetsDistributionCreation.cc(\"TTToHadronic\")"
root -b -q "WJetsDistributionCreation.cc(\"TTToSemiLeptonic\")"
root -b -q "WJetsDistributionCreation.cc(\"DY\")"
hadd -f WJetsDistributions.root TemporaryFiles/*WJets*

root -b -q WJetsSimToData.cc

root -b -q "QCDDistributionCreation.cc(\"Data\")"
root -b -q "QCDDistributionCreation.cc(\"WW\")"
root -b -q "QCDDistributionCreation.cc(\"WZ\")"
root -b -q "QCDDistributionCreation.cc(\"ZZ\")"
root -b -q "QCDDistributionCreation.cc(\"W\")"
root -b -q "QCDDistributionCreation.cc(\"TTTo2L2Nu\")"
root -b -q "QCDDistributionCreation.cc(\"TTToHadronic\")"
root -b -q "QCDDistributionCreation.cc(\"TTToSemiLeptonic\")"
root -b -q "QCDDistributionCreation.cc(\"DY\")"
hadd -f QCDDistributions.root TemporaryFiles/*QCD*

root -b -q FinalizeQCDBackground.cc

root -b -q CompileHistograms.cc