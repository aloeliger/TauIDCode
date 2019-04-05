#!/usr/bin.bash

#Do the Tau Energy Scale Uncertainties.
#right now the combine code seems to only want TES on TT, QCD, and Diboson distributions
#TT and VV are easy.
#root -b -q -l TauID.cc\(\"TTTo2L2Nu\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"TTToHadronic\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"TTToSemiLeptonic\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"TTTo2L2Nu\",\"$1\",0.97,$2,$3\)
#root -b -q -l TauID.cc\(\"TTToHadronic\",\"$1\",0.97,$2,$3\)
#root -b -q -l TauID.cc\(\"TTToSemiLeptonic\",\"$1\",0.97,$2,$3\)

#root -b -q -l TauID.cc\(\"WW\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"WZ\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"ZZ\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"WW\",\"$1\",0.97,$2,$3\)
#root -b -q -l TauID.cc\(\"WZ\",\"$1\",0.97,$2,$3\)
#root -b -q -l TauID.cc\(\"ZZ\",\"$1\",0.97,$2,$3\)

#How do we Handle the TES for QCD regions?
#Best Guess? simply run all other distributions in up or down, then do the QCD 
#generation with those samples.

#W
#root -b -q -l TauID.cc\(\"W\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"W1\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"W2\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"W3\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"W4\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"W\",\"$1\",0.97,$2,$3\)
#root -b -q -l TauID.cc\(\"W1\",\"$1\",0.97,$2,$3\)
#root -b -q -l TauID.cc\(\"W2\",\"$1\",0.97,$2,$3\)
#root -b -q -l TauID.cc\(\"W3\",\"$1\",0.97,$2,$3\)
#root -b -q -l TauID.cc\(\"W4\",\"$1\",0.97,$2,$3\)

#DY
#root -b -q -l TauID.cc\(\"DY\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"DY1\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"DY2\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"DY3\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"DY4\",\"$1\",1.03,$2,$3\)
#root -b -q -l TauID.cc\(\"DY\",\"$1\",0.97,$2,$3\)
#root -b -q -l TauID.cc\(\"DY1\",\"$1\",0.97,$2,$3\)
#root -b -q -l TauID.cc\(\"DY2\",\"$1\",0.97,$2,$3\)
#root -b -q -l TauID.cc\(\"DY3\",\"$1\",0.97,$2,$3\)
#root -b -q -l TauID.cc\(\"DY4\",\"$1\",0.97,$2,$3\)

#New Split DY TES Uncertainties
#DM 0 and 1 shift by 0.8 percent (scale 1.008, 0.992)
root -b -q -l TauID.cc\(\"DY\",\"$1\",1.008,$2,$3\)
root -b -q -l TauID.cc\(\"DY1\",\"$1\",1.008,$2,$3\)
root -b -q -l TauID.cc\(\"DY2\",\"$1\",1.008,$2,$3\)
root -b -q -l TauID.cc\(\"DY3\",\"$1\",1.008,$2,$3\)
root -b -q -l TauID.cc\(\"DY4\",\"$1\",1.008,$2,$3\)
root -b -q -l TauID.cc\(\"DY\",\"$1\",0.992,$2,$3\)
root -b -q -l TauID.cc\(\"DY1\",\"$1\",0.992,$2,$3\)
root -b -q -l TauID.cc\(\"DY2\",\"$1\",0.992,$2,$3\)
root -b -q -l TauID.cc\(\"DY3\",\"$1\",0.992,$2,$3\)
root -b -q -l TauID.cc\(\"DY4\",\"$1\",0.992,$2,$3\)

#DM10 goes by 0.9 %, (scale 1.009, 0.991)
root -b -q -l TauID.cc\(\"DY\",\"$1\",1.009,$2,$3\)
root -b -q -l TauID.cc\(\"DY1\",\"$1\",1.009,$2,$3\)
root -b -q -l TauID.cc\(\"DY2\",\"$1\",1.009,$2,$3\)
root -b -q -l TauID.cc\(\"DY3\",\"$1\",1.009,$2,$3\)
root -b -q -l TauID.cc\(\"DY4\",\"$1\",1.009,$2,$3\)
root -b -q -l TauID.cc\(\"DY\",\"$1\",0.991,$2,$3\)
root -b -q -l TauID.cc\(\"DY1\",\"$1\",0.991,$2,$3\)
root -b -q -l TauID.cc\(\"DY2\",\"$1\",0.991,$2,$3\)
root -b -q -l TauID.cc\(\"DY3\",\"$1\",0.991,$2,$3\)
root -b -q -l TauID.cc\(\"DY4\",\"$1\",0.991,$2,$3\)

#Do the Mu To Tau Misidentification shape uncertainty?
root -b -q -l TauID.cc\(\"DY\",\"$1\",1.10,$2,$3\)
root -b -q -l TauID.cc\(\"DY1\",\"$1\",1.10,$2,$3\)
root -b -q -l TauID.cc\(\"DY2\",\"$1\",1.10,$2,$3\)
root -b -q -l TauID.cc\(\"DY3\",\"$1\",1.10,$2,$3\)
root -b -q -l TauID.cc\(\"DY4\",\"$1\",1.10,$2,$3\)
root -b -q -l TauID.cc\(\"DY\",\"$1\",0.90,$2,$3\)
root -b -q -l TauID.cc\(\"DY1\",\"$1\",0.90,$2,$3\)
root -b -q -l TauID.cc\(\"DY2\",\"$1\",0.90,$2,$3\)
root -b -q -l TauID.cc\(\"DY3\",\"$1\",0.90,$2,$3\)
root -b -q -l TauID.cc\(\"DY4\",\"$1\",0.90,$2,$3\)