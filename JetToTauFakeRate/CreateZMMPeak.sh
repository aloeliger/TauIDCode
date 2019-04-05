root -b -l -q ZMuMuRegion.cc\(\"Data\"\)
root -b -l -q ZMuMuRegion.cc\(\"DY\"\)
root -b -l -q ZMuMuRegion.cc\(\"DY1\"\)
root -b -l -q ZMuMuRegion.cc\(\"DY2\"\)
root -b -l -q ZMuMuRegion.cc\(\"DY3\"\)
root -b -l -q ZMuMuRegion.cc\(\"DY4\"\)
root -b -l -q ZMuMuRegion.cc\(\"ST_top\"\)
root -b -l -q ZMuMuRegion.cc\(\"ST_antitop\"\)
root -b -l -q ZMuMuRegion.cc\(\"ST_tW_top\"\)
root -b -l -q ZMuMuRegion.cc\(\"ST_tW_antitop\"\)
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

#root -b -l -q GenerateMuMuQCD.cc
root -l -b -q CompileMuMuHistograms.cc
#root -l CompileMuMuHistograms.cc