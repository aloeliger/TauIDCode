root -b -l -q JetToTauFakesMeasurement.cc\(\"Data\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"DY\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"DY1\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"DY2\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"DY3\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"DY4\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"TTTo2L2Nu\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"TTToHadronic\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"TTToSemiLeptonic\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"ST_top\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"ST_antitop\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"ST_tW_top\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"ST_tW_antitop\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"WW\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"WZ\"\)
root -b -l -q JetToTauFakesMeasurement.cc\(\"ZZ\"\)
hadd -f ../Distributions/FinalFakeRateEventsDistributions.root ../Distributions/FakeRate*EventsDistributions.root

python GenerateFinalFakeRate.py