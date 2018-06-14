#!/usr/bin/bash
#run the ID code over all the available distributions.
root -b -q "TauID.cc(\"Data\")"
root -b -q "TauID.cc(\"WW\")"
root -b -q "TauID.cc(\"WZ\")"
root -b -q "TauID.cc(\"ZZ\")"
root -b -q "TauID.cc(\"W\")" #is this the W+jets low Mt sample?
root -b -q "TauID.cc(\"W1\")"
root -b -q "TauID.cc(\"W2\")"
root -b -q "TauID.cc(\"W3\")"
root -b -q "TauID.cc(\"W4\")"
root -b -q "TauID.cc(\"TTTo2L2Nu\")"
root -b -q "TauID.cc(\"TTToHadronic\")"
root -b -q "TauID.cc(\"TTToSemiLeptonic\")"
root -b -q "TauID.cc(\"DY\")"
root -b -q "TauID.cc(\"DY1\")"
root -b -q "TauID.cc(\"DY2\")"
root -b -q "TauID.cc(\"DY3\")"
root -b -q "TauID.cc(\"DY4\")"
root -b -q "TauID.cc(\"DY\",1.03)"
root -b -q "TauID.cc(\"DY1\",1.03)"
root -b -q "TauID.cc(\"DY2\",1.03)"
root -b -q "TauID.cc(\"DY3\",1.03)"
root -b -q "TauID.cc(\"DY4\",1.03)"
root -b -q "TauID.cc(\"DY\",1.10)"
root -b -q "TauID.cc(\"DY1\",1.10)"
root -b -q "TauID.cc(\"DY2\",1.10)"
root -b -q "TauID.cc(\"DY3\",1.10)"
root -b -q "TauID.cc(\"DY4\",1.10)"
root -b -q "TauID.cc(\"DY\",0.97)"
root -b -q "TauID.cc(\"DY1\",0.97)"
root -b -q "TauID.cc(\"DY2\",0.97)"
root -b -q "TauID.cc(\"DY3\",0.97)"
root -b -q "TauID.cc(\"DY4\",0.97)"
root -b -q "TauID.cc(\"DY\",0.90)"
root -b -q "TauID.cc(\"DY1\",0.90)"
root -b -q "TauID.cc(\"DY2\",0.90)"
root -b -q "TauID.cc(\"DY3\",0.90)"
root -b -q "TauID.cc(\"DY4\",0.90)"

hadd -f Distributions/PassFailOut.root TemporaryFiles/Signal*.root
hadd -f Distributions/WJetsDistributions.root TemporaryFiles/WJets_*.root
hadd -f Distributions/QCDDistributions.root TemporaryFiles/QCD_*.root
hadd -f Distributions/WJetsQCDContributions.root TemporaryFiles/QCDinWJets_*.root

root -b -q EstimateQCDinWJets.cc
root -b -q WJetsSimToData.cc
root -b -q FinalizeQCDBackground.cc
root -b -q CompileHistograms.cc
root -b -q PrepForCombine.cc
#because I can't get combine to compile properly on the lxplus servers
# we now turn this over to the Wiscosin computers.
cp Distributions/CombineFile.root /afs/cern.ch/user/a/aloelige/public/