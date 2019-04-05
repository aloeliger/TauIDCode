root -b -l -q GenerateJetSamples.cc\($2,$3\)

#new thing to handle the potential non jets that ends up in 
#the jet region

root -b -l -q GenerateMCInJetsRegion.cc\(\"DY\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"DY1\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"DY2\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"DY3\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"DY4\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"TTTo2L2Nu\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"TTToHadronic\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"TTToSemiLeptonic\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"ST_top\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"ST_antitop\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"ST_tW_top\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"ST_tW_antitop\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"WW\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"WZ\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"ZZ\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"W\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"W1\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"W2\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"W3\",$2,$3\)
root -b -l -q GenerateMCInJetsRegion.cc\(\"W4\",$2,$3\)
hadd -f ../Distributions/MCInJetsRegion.root ../TemporaryFiles/*InJetsRegion.root

root -b -l -q RemoveMCFromJets.cc\(\"$1\"\)