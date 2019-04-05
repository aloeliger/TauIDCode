#!/usr/bin/bash
#Takes the isolation working point in as it's first argument
#That is: VLoose all the way up to VVTight. Spelled that way.

#run the ID code over all the available distributions.
#these the "basic" distributions
root -b -q TauID.cc\(\"Data\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"WW\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"WZ\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"ZZ\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"W\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"W1\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"W2\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"W3\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"W4\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"TTTo2L2Nu\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"TTToHadronic\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"TTToSemiLeptonic\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"ST_top\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"ST_antitop\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"ST_tW_top\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"ST_tW_antitop\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"DY\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"DY1\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"DY2\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"DY3\",\"$1\",1.0,$2,$3\)
root -b -q -l TauID.cc\(\"DY4\",\"$1\",1.0,$2,$3\)