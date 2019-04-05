import ROOT
import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description = "Generate plots of the same sign region")
    parser.add_argument('HistogramName',nargs="?",help="Histogram to draw")
    
    args = parser.parse_args()

    QCDFile = ROOT.TFile("Distributions/QCDDistributions.root")
    
    QCD_Control = QCDFile.control.Get("QCD_Data_"+args.HistogramName)
    
    ZTauTau_Control = QCDFile.control.Get("QCD_GenMatch_DY_"+args.HistogramName)
    ZTauTau1_Control = QCDFile.control.Get("QCD_GenMatch_DY1_"+args.HistogramName)
    ZTauTau2_Control = QCDFile.control.Get("QCD_GenMatch_DY2_"+args.HistogramName)
    ZTauTau3_Control = QCDFile.control.Get("QCD_GenMatch_DY3_"+args.HistogramName)
    ZTauTau4_Control = QCDFile.control.Get("QCD_GenMatch_DY4_"+args.HistogramName)
    LowGenMatch_DY_Control = QCDFile.control.Get("QCD_LowGenMatch_DY_"+args.HistogramName)
    LowGenMatch_DY1_Control = QCDFile.control.Get("QCD_LowGenMatch_DY1_"+args.HistogramName)
    LowGenMatch_DY2_Control = QCDFile.control.Get("QCD_LowGenMatch_DY2_"+args.HistogramName)
    LowGenMatch_DY3_Control = QCDFile.control.Get("QCD_LowGenMatch_DY3_"+args.HistogramName)
    LowGenMatch_DY4_Control = QCDFile.control.Get("QCD_LowGenMatch_DY4_"+args.HistogramName)
    HighGenMatch_DY_Control = QCDFile.control.Get("QCD_HighGenMatch_DY_"+args.HistogramName)
    HighGenMatch_DY1_Control = QCDFile.control.Get("QCD_HighGenMatch_DY1_"+args.HistogramName)
    HighGenMatch_DY2_Control = QCDFile.control.Get("QCD_HighGenMatch_DY2_"+args.HistogramName)
    HighGenMatch_DY3_Control = QCDFile.control.Get("QCD_HighGenMatch_DY3_"+args.HistogramName)
    HighGenMatch_DY4_Control = QCDFile.control.Get("QCD_HighGenMatch_DY4_"+args.HistogramName)

    TTTo2L2Nu_Control = QCDFile.control.Get("QCD_TTTo2L2Nu_"+args.HistogramName)
    TTToHadronic_Control = QCDFile.control.Get("QCD_TTToHadronic_"+args.HistogramName)
    TTToSemiLeptonic_Control = QCDFile.control.Get("QCD_TTToSemiLeptonic_"+args.HistogramName)

    W_Control = QCDFile.control.Get("QCD_W_"+args.HistogramName)
    W1_Control = QCDFile.control.Get("QCD_W1_"+args.HistogramName)
    W2_Control = QCDFile.control.Get("QCD_W2_"+args.HistogramName)
    W3_Control = QCDFile.control.Get("QCD_W3_"+args.HistogramName)
    W4_Control = QCDFile.control.Get("QCD_W4_"+args.HistogramName)

    WW_Control = QCDFile.control.Get("QCD_WW_"+args.HistogramName)
    WZ_Control = QCDFile.control.Get("QCD_WZ_"+args.HistogramName)
    ZZ_Control = QCDFile.control.Get("QCD_ZZ_"+args.HistogramName)

    #ST_top_Control = QCDFile.control.Get("ST_top_"+args.HistogramName)
    #ST_antitop_Control = QCDFile.control.Get("ST_antitop_"+args.HistogramName)
    #ST_tW_top_Control = QCDFile.control.Get("ST_tW_top_"+args.HistogramName)
    #ST_tW_antitop_Control = QCDFile.control.Get("ST_tW_antitop_"+args.HistogramName)

    W_Control.Add(W1_Control)
    W_Control.Add(W2_Control)
    W_Control.Add(W3_Control)
    W_Control.Add(W4_Control)

    ZTauTau_Control.Add(ZTauTau1_Control)
    ZTauTau_Control.Add(ZTauTau2_Control)
    ZTauTau_Control.Add(ZTauTau3_Control)
    ZTauTau_Control.Add(ZTauTau4_Control)
    
    LowGenMatch_DY_Control.Add(LowGenMatch_DY1_Control)
    LowGenMatch_DY_Control.Add(LowGenMatch_DY2_Control)
    LowGenMatch_DY_Control.Add(LowGenMatch_DY3_Control)
    LowGenMatch_DY_Control.Add(LowGenMatch_DY4_Control)
    LowGenMatch_DY_Control.Add(HighGenMatch_DY1_Control)
    LowGenMatch_DY_Control.Add(HighGenMatch_DY2_Control)
    LowGenMatch_DY_Control.Add(HighGenMatch_DY3_Control)
    LowGenMatch_DY_Control.Add(HighGenMatch_DY4_Control)

    TT_Control = TTToHadronic_Control.Clone()
    TT_Control.Add(TTToSemiLeptonic_Control)
    TT_Control.Add(TTTo2L2Nu_Control)

    Diboson_Control = WW_Control.Clone()
    Diboson_Control.Add(WZ_Control)
    Diboson_Control.Add(ZZ_Control)
    #Diboson_Control.Add(ST_top_Control)
    #Diboson_Control.Add(ST_antitop_Control)
    #Diboson_Control.Add(ST_tW_top_Control)
    #Diboson_Control.Add(ST_tW_antitop_Control)

    QCD_Control.SetMarkerStyle(20)
    
    ZTauTau_Control.SetLineColor(ROOT.kBlack)
    ZTauTau_Control.SetFillColor(ROOT.TColor.GetColor("#ffcc66"))

    LowGenMatch_DY_Control.SetLineColor(ROOT.kBlack)
    LowGenMatch_DY_Control.SetFillColor(ROOT.TColor.GetColor("#4496c8"))
    
    Diboson_Control.SetLineColor(ROOT.kBlack)
    Diboson_Control.SetFillColor(ROOT.TColor.GetColor("#12cadd"))

    TT_Control.SetLineColor(ROOT.kBlack)
    TT_Control.SetFillColor(ROOT.TColor.GetColor("#9999cc"))

    W_Control.SetLineColor(ROOT.kBlack)
    W_Control.SetFillColor(ROOT.TColor.GetColor("#a53db8"))

    
    BackgroundStack = ROOT.THStack("BackgroundStack","BackgroundStack")
    BackgroundStack.Add(W_Control,"hist")
    BackgroundStack.Add(ZTauTau_Control,"hist")
    BackgroundStack.Add(LowGenMatch_DY_Control,"hist")
    BackgroundStack.Add(TT_Control,"hist")
    BackgroundStack.Add(Diboson_Control,"hist")

    TheCanvas = ROOT.TCanvas("TheCanvas","TheCanvas")

    BackgroundStack.SetMaximum(max(BackgroundStack.GetMaximum(),QCD_Control.GetMaximum())*1.1)
    BackgroundStack.Draw()
    BackgroundStack.SetTitle("SS "+args.HistogramName)
    QCD_Control.Draw("SAME e1")
    
    TheLegend = ROOT.TLegend(0.7,0.5,0.88,0.68)
    TheLegend.AddEntry(QCD_Control,"Data","EP")
    TheLegend.AddEntry(ZTauTau_Control,"Z #rightarrow #tau#tau","f")
    TheLegend.AddEntry(LowGenMatch_DY_Control,"Other DY","f")
    TheLegend.AddEntry(Diboson_Control, "VV", "f")
    TheLegend.AddEntry(TT_Control,"t#bar{t}", "f")
    TheLegend.AddEntry(W_Control,"W+Jets","f")

    TheLegend.Draw()
    TheCanvas.Draw()

    raw_input("Press Enter to continue...")
    TheCanvas.SaveAs("Histos/SS_Control_"+args.HistogramName+".png")
