#!/usr/bin/nash
#root -l -q CompareJetsToWAndQCD.cc\(\"$1\"\)
#root -b -l -q CompileSameSignHistograms.cc\(\"$1\"\)
root -b -l -q PrepareFakeRateForCombine.cc\(\"$1\",$2,$3\)

cp ../Distributions/$1*FakeRateCombineFile.root /afs/cern.ch/user/a/aloelige/public/