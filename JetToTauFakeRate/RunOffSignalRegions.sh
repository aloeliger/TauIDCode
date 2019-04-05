#!/usr/bin/bash
#argument taken is the tua iso working point VLoose to VVTight

sh RunJets.sh $1 $2 $3

#cd ../TemporaryCode/
#root -l CompareFakeRateDistributionsToMC.cc
#cd ../JetToTauFakeRate/

sh CreateZMMPeak.sh

sh RunFakeRatePostProcessing.sh $1 $2 $3