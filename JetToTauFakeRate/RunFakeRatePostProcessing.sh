#!/usr/bin/nash
root -l -q CompareJetsToWAndQCD.cc\(\"$1\"\)
root -b -l -q PrepareFakeRateForCombine.cc\(\"$1\"\)

cp ../Distributions/$1FakeRateCombineFile.root /afs/cern.ch/user/a/aloelige/public/