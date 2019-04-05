#!/usr/bin/bash
#take iso, and pt eta bins as arguments

sh RunSignalRegionSelection.sh $1 $2 $3
sh RunTES.sh $1 $2 $3
sh CombineEverything.sh $1 $2 $3

#This script now handles the running of all jet to tau fake rate stuff.
cd JetToTauFakeRate/
sh RunOffSignalRegions.sh $1 $2 $3
cd ../

sh DoPostProcessing.sh $1 $2 $3
