import ROOT

PassFailFile = ROOT.TFile("/Distributions/PassFailOut.root")

DataHisto = PassFailFile.pass.Get("Data_Pass")

DY_S_Histo = PassFailFile.pass.Get("GenMatch_DY_Pass")
DY1_S_Histo = PassFailFile.pass.Get("GenMatch_DY1_Pass")
DY2_S_Histo = PassFailFile.pass.Get("GenMatch_DY2_Pass")
DY3_S_Histo = PassFailFile.pass.Get("GenMatch_DY3_Pass")
DY4_S_Histo = PassFailFile.pass.Get("GenMatch_DY4_Pass")

DY_B_Histo = PassFailFile.pass.Get("LowGenMatch_DY_Pass")
DY1_B_Histo = PassFailFile.pass.Get("LowGenMatch_DY1_Pass")
DY2_B_Histo = PassFailFile.pass.Get("LowGenMatch_DY2_Pass")
DY3_B_Histo = PassFailFile.pass.Get("LowGenMatch_DY3_Pass")
DY4_B_Histo = PassFailFile.pass.Get("LowGenMatch_DY4_Pass")

DY_J_Histo = PassFailFile.pass.Get("HighGenMatch_DY_Pass")
DY1_J_Histo = PassFailFile.pass.Get("HighGenMatch_DY1_Pass")
DY2_J_Histo = PassFailFile.pass.Get("HighGenMatch_DY2_Pass")
DY3_J_Histo = PassFailFile.pass.Get("HighGenMatch_DY3_Pass")
DY4_J_Histo = PassFailFile.pass.Get("HighGenMatch_DY4_Pass")

TTTo2L2Nu_S_Histo = PassFailFile.pass.Get("GenMatch_TTTo2L2Nu_Pass")
TTToHadronic_S_Histo = PassFailFile.pass.Get("GenMatch_TTToHadronic_Pass")
TTToSemiLeptonic_S_Histo = PassFailFile.pass.Get("GenMatch_TTToSemiLeptonic_Pass")

TT_S_Histo = TTTo2L2Nu_S_Histo.Clone()
TT_S_Histo.Add(TTToHadronic_S_Histo)
TT_S_Histo.Add(TTToSemiLeptonic_S_Histo)

TTTo2L2Nu_B_Histo = PassFailFile.pass.Get("LowGenMatch_TTTo2L2Nu_Pass")
TTToHadronic_B_Histo = PassFailFile.pass.Get("LowGenMatch_TTToHadronic_Pass")
TTToSemiLeptonic_B_Histo = PassFailFile.pass.Get("LowGenMatch_TTToSemiLeptonic_Pass")

TT_B_Histo = TTTo2L2Nu_B_Histo.Clone()
TT_B_Histo.Add(TTToHadronic_B_Histo)
TT_B_Histo.Add(TTToSemiLeptonic_B_Histo)

TTTo2L2Nu_J_Histo = PassFailFile.pass.Get("HighGenMatch_TTTo2L2Nu_Pass")
TTToHadronic_J_Histo = PassFailFile.pass.Get("HighGenMatch_TTToHadronic_Pass")
TTToSemiLeptonic_J_Histo = PassFailFile.pass.Get("HighGenMatch_TTToSemiLeptonic_Pass")

TT_J_Histo = TTTo2L2Nu_J_Histo.Clone()
TT_J_Histo.Add(TTToHadronic_J_Histo)
TT_J_Histo.Add(TTToSemiLeptonic_J_Histo)

WW_S_Histo = PassFailFile.pass.Get("GenMatch_WW_Pass")
WZ_S_Histo = PassFailFile.pass.Get("GenMatch_WZ_Pass")
ZZ_S_Histo = PassFailFile.pass.Get("GenMatch_ZZ_Pass")

ST_top_S_Histo = PassFailFile.pass.Get("GenMatch_ST_top_Pass")
ST_antitop_S_Histo = PassFailFile.pass.Get("GenMatch_ST_antitop_Pass")
ST_tW_top_S_Histo = PassFailFile.pass.Get("GenMatch_ST_tW_top_Pass")
ST_tW_antitop_S_Histo = PassFailFile.pass.Get("GenMatch_ST_tW_antitop_Pass")

DiBoson_S_Histo = WW_S_Histo.Clone()
DiBoson_S_Histo.Add(WZ_S_Histo)
DiBoson_S_Histo.Add(ZZ_S_Histo)
DiBoson_S_Histo.Add(ST_top_S_Histo)
DiBoson_S_Histo.Add(ST_antitop_S_Histo)
DiBoson_S_Histo.Add(ST_tW_top_S_Histo)
DiBoson_S_Histo.Add(ST_tW_antitop_S_Histo)

WW_B_Histo = PassFailFile.pass.Get("LowGenMatch_WW_Pass")
WZ_B_Histo = PassFailFile.pass.Get("LowGenMatch_WZ_Pass")
ZZ_B_Histo = PassFailFile.pass.Get("LowGenMatch_ZZ_Pass")

ST_top_B_Histo = PassFailFile.pass.Get("LowGenMatch_ST_top_Pass")
ST_antitop_B_Histo = PassFailFile.pass.Get("LowGenMatch_ST_antitop_Pass")
ST_tW_top_B_Histo = PassFailFile.pass.Get("LowGenMatch_ST_tW_top_Pass")
ST_tW_antitop_B_Histo = PassFailFile.pass.Get("LowGenMatch_ST_tW_antitop_Pass")

DiBoson_B_Histo = WW_B_Histo.Clone()
DiBoson_B_Histo.Add(WZ_B_Histo)
DiBoson_B_Histo.Add(ZZ_B_Histo)
DiBoson_B_Histo.Add(ST_top_B_Histo)
DiBoson_B_Histo.Add(ST_antitop_B_Histo)
DiBoson_B_Histo.Add(ST_tW_top_B_Histo)
DiBoson_B_Histo.Add(ST_tW_antitop_B_Histo)

WW_J_Histo = PassFailFile.pass.Get("HighGenMatch_WW_Pass")
WZ_J_Histo = PassFailFile.pass.Get("HighGenMatch_WZ_Pass")
ZZ_J_Histo = PassFailFile.pass.Get("HighGenMatch_ZZ_Pass")

ST_top_J_Histo = PassFailFile.pass.Get("HighGenMatch_ST_top_Pass")
ST_antitop_J_Histo = PassFailFile.pass.Get("HighGenMatch_ST_antitop_Pass")
ST_tW_top_J_Histo = PassFailFile.pass.Get("HighGenMatch_ST_tW_top_Pass")
ST_tW_antitop_J_Histo = PassFailFile.pass.Get("HighGenMatch_ST_tW_antitop_Pass")

DiBoson_J_Histo = WW_J_Histo.Clone()
DiBoson_J_Histo.Add(WZ_J_Histo)
DiBoson_J_Histo.Add(ZZ_J_Histo)
DiBoson_J_Histo.Add(ST_top_J_Histo)
DiBoson_J_Histo.Add(ST_antitop_J_Histo)
DiBoson_J_Histo.Add(ST_tW_top_J_Histo)
DiBoson_J_Histo.Add(ST_tW_antitop_J_Histo)

W_Histo = PassFailFile.pass.Get("Rescaled_WJets_Pass")
QCD_Histo = PassFailFile.pass.Get("QCD_Pass")

DY_S_DM0_TES_UP_Histo = PassFailFile.pass.Get("Genmatch_DY_1.008000_DM0Mod_Pass")
DY1_S_DM0_TES_UP_Histo = PassFailFile.pass.Get("Genmatch_DY1_1.008000_DM0Mod_Pass")
DY2_S_DM0_TES_UP_Histo = PassFailFile.pass.Get("Genmatch_DY2_1.008000_DM0Mod_Pass")
DY3_S_DM0_TES_UP_Histo = PassFailFile.pass.Get("Genmatch_DY3_1.008000_DM0Mod_Pass")
DY4_S_DM0_TES_UP_Histo = PassFailFile.pass.Get("Genmatch_DY4_1.008000_DM0Mod_Pass")
DY_S_DM0_TES_DOWN_Histo = PassFailFile.pass.Get("Genmatch_DY_0.992000_DM0Mod_Pass")
DY1_S_DM0_TES_DOWN_Histo = PassFailFile.pass.Get("Genmatch_DY1_0.992000_DM0Mod_Pass")
DY2_S_DM0_TES_DOWN_Histo = PassFailFile.pass.Get("Genmatch_DY2_0.992000_DM0Mod_Pass")
DY3_S_DM0_TES_DOWN_Histo = PassFailFile.pass.Get("Genmatch_DY3_0.992000_DM0Mod_Pass")
DY4_S_DM0_TES_DOWN_Histo = PassFailFile.pass.Get("Genmatch_DY4_0.992000_DM0Mod_Pass")

DY_S_DM1_TES_UP_Histo = PassFailFile.pass.Get("GenMatch_DY_1.008000_DM1Mod_Pass")
DY1_S_DM1_TES_UP_Histo = PassFailFile.pass.Get("GenMatch_DY1_1.008000_DM1Mod_Pass")
DY2_S_DM1_TES_UP_Histo = PassFailFile.pass.Get("GenMatch_DY2_1.008000_DM1Mod_Pass")
DY3_S_DM1_TES_UP_Histo = PassFailFile.pass.Get("GenMatch_DY3_1.008000_DM1Mod_Pass")
DY4_S_DM1_TES_UP_Histo = PassFailFile.pass.Get("GenMatch_DY4_1.008000_DM1Mod_Pass")
DY_S_DM1_TES_DOWN_Histo = PassFailFile.pass.Get("GenMatch_DY_0.992000_DM1Mod_Pass")
DY1_S_DM1_TES_DOWN_Histo = PassFailFile.pass.Get("GenMatch_DY1_0.992000_DM1Mod_Pass")
DY2_S_DM1_TES_DOWN_Histo = PassFailFile.pass.Get("GenMatch_DY2_0.992000_DM1Mod_Pass")
DY3_S_DM1_TES_DOWN_Histo = PassFailFile.pass.Get("GenMatch_DY3_0.992000_DM1Mod_Pass")
DY4_S_DM1_TES_DOWN_Histo = PassFailFile.pass.Get("GenMatch_DY4_0.992000_DM1Mod_Pass")
