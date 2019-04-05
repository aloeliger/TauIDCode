#!/usr/bin/bash

#root -l -q CompileHistograms.cc\(\"$1\"\)
root -b -q -l PrepForCombine.cc\(\"$1\",$2,$3\)
#because I can't get combine to compile properly on the lxplus servers
# we now turn this over to the Wiscosin computers.
cp Distributions/$1*CombineFile.root /afs/cern.ch/user/a/aloelige/public/