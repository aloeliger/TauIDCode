#!/usr/bin/nash

#argument taken is the tua iso working point VLoose to VVTight

#Until I sort out what the issue is with the cnsenv root setup
# we have the two old lines in this script
#sh ../GoofyRootSetup.sh


root -b -l -q JetToTauFakesMeasurement.cc
root -b -l -q GenerateJetSamples.cc

#new thing to handle the potential non jets that ends up in 
#the jet region

root -b -l -q GenerateMCInJetsRegion.cc\(\"DY\"\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"DY1\"\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"DY2\"\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"DY3\"\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"DY4\"\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"TTTo2L2Nu\"\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"TTToHadronic\"\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"TTToSemiLeptonic\"\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"WW\"\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"WZ\"\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"ZZ\"\)
hadd -f ../Distributions/MCInJetsRegion.root ../TemporaryFiles/*InJetsRegion.root

root -b -l -q RemoveMCFromJets.cc\(\"$1\"\)

#cd ../TemporaryCode/
#root -l CompareFakeRateDistributionsToMC.cc
#cd ../JetToTauFakeRate/
root -b -l -q ZMuMuRegion.cc\(\"Data\"\)
root -b -l -q ZMuMuRegion.cc\(\"DY\"\)
root -b -l -q ZMuMuRegion.cc\(\"DY1\"\)
root -b -l -q ZMuMuRegion.cc\(\"DY2\"\)
root -b -l -q ZMuMuRegion.cc\(\"DY3\"\)
root -b -l -q ZMuMuRegion.cc\(\"DY4\"\)
root -b -l -q ZMuMuRegion.cc\(\"TTTo2L2Nu\"\)
root -b -l -q ZMuMuRegion.cc\(\"TTToHadronic\"\)
root -b -l -q ZMuMuRegion.cc\(\"TTToSemiLeptonic\"\)
root -b -l -q ZMuMuRegion.cc\(\"W\"\)
root -b -l -q ZMuMuRegion.cc\(\"W1\"\)
root -b -l -q ZMuMuRegion.cc\(\"W2\"\)
root -b -l -q ZMuMuRegion.cc\(\"W3\"\)
root -b -l -q ZMuMuRegion.cc\(\"W4\"\)
root -b -l -q ZMuMuRegion.cc\(\"WW\"\)
root -b -l -q ZMuMuRegion.cc\(\"WZ\"\)
root -b -l -q ZMuMuRegion.cc\(\"ZZ\"\)

hadd -f ../Distributions/ZMuMu.root ../TemporaryFiles/*MuMu.root

sh RunFakeRatePostProcessing.sh $1