import ROOT
import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description = "Generate Plots of the fake rate region")
    parser.add_argument('HistogramName',nargs="?",help="Histogram to draw")

    args = parser.parse_args()

    MCInJetsFile = ROOT.TFile("../Distributions/MCInJetsRegion.root")
    FakeRateDeterminedDistributions = ROOT.TFile("../Distributions/FakeRateDeterminedDistributions.root")

    print("Retrieving DY..")
    DY_AntiIso = MCInJetsFile.Get("DY_"+args.HistogramName)
    DY1_AntiIso = MCInJetsFile.Get("DY1_"+args.HistogramName)
    DY2_AntiIso = MCInJetsFile.Get("DY2_"+args.HistogramName)
    DY3_AntiIso = MCInJetsFile.Get("DY3_"+args.HistogramName)
    DY4_AntiIso = MCInJetsFile.Get("DY4_"+args.HistogramName)
    DY_AntiIso.Add(DY1_AntiIso)
    DY_AntiIso.Add(DY2_AntiIso)
    DY_AntiIso.Add(DY3_AntiIso)
    DY_AntiIso.Add(DY4_AntiIso)
    
    print("Retrieving ttbar...")
    TTTo2L2Nu_AntiIso = MCInJetsFile.Get("TTTo2L2Nu_"+args.HistogramName)
    TTToHadronic_AntiIso = MCInJetsFile.Get("TTToHadronic_"+args.HistogramName)
    TTToSemiLeptonic_AntiIso = MCInJetsFile.Get("TTToSemiLeptonic_"+args.HistogramName)

    TT_AntiIso = TTTo2L2Nu_AntiIso.Clone()
    TT_AntiIso.Add(TTToHadronic_AntiIso)
    TT_AntiIso.Add(TTToSemiLeptonic_AntiIso)

    print("Retrieving Diboson...")
    WW_AntiIso = MCInJetsFile.Get("WW_"+args.HistogramName)
    WZ_AntiIso = MCInJetsFile.Get("WZ_"+args.HistogramName)
    ZZ_AntiIso = MCInJetsFile.Get("ZZ_"+args.HistogramName)

    print("Retireving ST...")
    ST_top_AntiIso = MCInJetsFile.Get("ST_top_"+args.HistogramName)
    ST_antitop_AntiIso = MCInJetsFile.Get("ST_antitop_"+args.HistogramName)
    ST_tW_top_AntiIso = MCInJetsFile.Get("ST_tW_top_"+args.HistogramName)
    ST_tW_antitop_AntiIso = MCInJetsFile.Get("ST_tW_antitop_"+args.HistogramName)
    
    Diboson_AntiIso = WW_AntiIso.Clone()
    Diboson_AntiIso.Add(WZ_AntiIso)
    Diboson_AntiIso.Add(ZZ_AntiIso)
    Diboson_AntiIso.Add(ST_top_AntiIso)
    Diboson_AntiIso.Add(ST_antitop_AntiIso)
    Diboson_AntiIso.Add(ST_tW_top_AntiIso)
    Diboson_AntiIso.Add(ST_tW_antitop_AntiIso)

    print("Getting the Data histogram")
    Data_AntiIso = FakeRateDeterminedDistributions.Get("Jet_"+args.HistogramName)

    #draw the stuff, set the colors, do the whatever.
    Data_AntiIso.SetMarkerStyle(20)

    DY_AntiIso.SetLineColor(ROOT.kBlack)
    DY_AntiIso.SetFillColor(ROOT.TColor.GetColor("#ffcc66"))

    Diboson_AntiIso.SetLineColor(ROOT.kBlack)
    Diboson_AntiIso.SetFillColor(ROOT.TColor.GetColor("#12cadd"))

    TT_AntiIso.SetLineColor(ROOT.kBlack)
    TT_AntiIso.SetFillColor(ROOT.TColor.GetColor("#9999cc"))

    #Draw the subtraction Canvas
    FirstCanvas = ROOT.TCanvas("FirstCanvas","FirstCanvas")
    SubtractionStack = ROOT.THStack("SubtractionStack","SubtractionStack")
    SubtractionStack.Add(DY_AntiIso,"hist")
    SubtractionStack.Add(TT_AntiIso,"hist")
    SubtractionStack.Add(Diboson_AntiIso,"hist")
    
    Data_AntiIso.Draw("e1")
    Data_AntiIso.SetTitle("Jet Fakes Creation "+args.HistogramName)
    SubtractionStack.Draw("SAME")

    SubtractionLegend = ROOT.TLegend(0.7,0.5,0.88,0.68)
    SubtractionLegend.AddEntry(Data_AntiIso,"Data","EP")
    SubtractionLegend.AddEntry(Diboson_AntiIso,"VV+ST","f")
    SubtractionLegend.AddEntry(TT_AntiIso,"t#bar{t}","f")
    SubtractionLegend.AddEntry(DY_AntiIso,"All DY","f")
    SubtractionLegend.Draw()

    FirstCanvas.Draw()
    FirstCanvas.SaveAs("../Histos/AntiIso_Subtraction_"+args.HistogramName+".png")

    #okay, now we make the WJets and QCD histograms
    print("Retrieving WJets...")
    W_AntiIso = MCInJetsFile.Get("W_"+args.HistogramName)
    W1_AntiIso = MCInJetsFile.Get("W1_"+args.HistogramName)
    W2_AntiIso = MCInJetsFile.Get("W2_"+args.HistogramName)
    W3_AntiIso = MCInJetsFile.Get("W3_"+args.HistogramName)
    W4_AntiIso = MCInJetsFile.Get("W4_"+args.HistogramName)
    W_AntiIso.Add(W1_AntiIso)
    W_AntiIso.Add(W2_AntiIso)
    W_AntiIso.Add(W3_AntiIso)
    W_AntiIso.Add(W4_AntiIso)    

    print("Retrieving QCD relevant histograms")
    print("\tRetrieving DY..")
    DY_AntiIso_SS = MCInJetsFile.Get("DY_"+args.HistogramName+"_SS")
    DY1_AntiIso_SS = MCInJetsFile.Get("DY1_"+args.HistogramName+"_SS")
    DY2_AntiIso_SS = MCInJetsFile.Get("DY2_"+args.HistogramName+"_SS")
    DY3_AntiIso_SS = MCInJetsFile.Get("DY3_"+args.HistogramName+"_SS")
    DY4_AntiIso_SS = MCInJetsFile.Get("DY4_"+args.HistogramName+"_SS")
    DY_AntiIso_SS.Add(DY1_AntiIso)
    DY_AntiIso_SS.Add(DY2_AntiIso)
    DY_AntiIso_SS.Add(DY3_AntiIso)
    DY_AntiIso_SS.Add(DY4_AntiIso)
    
    print("\tRetrieving ttbar...")
    TTTo2L2Nu_AntiIso_SS = MCInJetsFile.Get("TTTo2L2Nu_"+args.HistogramName+"_SS")
    TTToHadronic_AntiIso_SS = MCInJetsFile.Get("TTToHadronic_"+args.HistogramName+"_SS")
    TTToSemiLeptonic_AntiIso_SS = MCInJetsFile.Get("TTToSemiLeptonic_"+args.HistogramName+"_SS")

    TT_AntiIso_SS = TTTo2L2Nu_AntiIso_SS.Clone()
    TT_AntiIso_SS.Add(TTToHadronic_AntiIso_SS)
    TT_AntiIso_SS.Add(TTToSemiLeptonic_AntiIso_SS)

    print("\tRetrieving Diboson...")
    WW_AntiIso_SS = MCInJetsFile.Get("WW_"+args.HistogramName+"_SS")
    WZ_AntiIso_SS = MCInJetsFile.Get("WZ_"+args.HistogramName+"_SS")
    ZZ_AntiIso_SS = MCInJetsFile.Get("ZZ_"+args.HistogramName+"_SS")

    print("\tRetireving ST...")
    ST_top_AntiIso_SS = MCInJetsFile.Get("ST_top_"+args.HistogramName+"_SS")
    ST_antitop_AntiIso_SS = MCInJetsFile.Get("ST_antitop_"+args.HistogramName+"_SS")
    ST_tW_top_AntiIso_SS = MCInJetsFile.Get("ST_tW_top_"+args.HistogramName+"_SS")
    ST_tW_antitop_AntiIso_SS = MCInJetsFile.Get("ST_tW_antitop_"+args.HistogramName+"_SS")
    
    Diboson_AntiIso_SS = WW_AntiIso_SS.Clone()
    Diboson_AntiIso_SS.Add(WZ_AntiIso_SS)
    Diboson_AntiIso_SS.Add(ZZ_AntiIso_SS)
    Diboson_AntiIso_SS.Add(ST_top_AntiIso_SS)
    Diboson_AntiIso_SS.Add(ST_antitop_AntiIso_SS)
    Diboson_AntiIso_SS.Add(ST_tW_top_AntiIso_SS)
    Diboson_AntiIso_SS.Add(ST_tW_antitop_AntiIso_SS)

    print("\tRetrieving WJets...")
    W_AntiIso_SS = MCInJetsFile.Get("W_"+args.HistogramName+"_SS")
    W1_AntiIso_SS = MCInJetsFile.Get("W1_"+args.HistogramName+"_SS")
    W2_AntiIso_SS = MCInJetsFile.Get("W2_"+args.HistogramName+"_SS")
    W3_AntiIso_SS = MCInJetsFile.Get("W3_"+args.HistogramName+"_SS")
    W4_AntiIso_SS = MCInJetsFile.Get("W4_"+args.HistogramName+"_SS")
    W_AntiIso_SS.Add(W1_AntiIso_SS)
    W_AntiIso_SS.Add(W2_AntiIso_SS)
    W_AntiIso_SS.Add(W3_AntiIso_SS)
    W_AntiIso_SS.Add(W4_AntiIso_SS)

    print("\tGetting the Data histogram")
    Data_AntiIso_SS = FakeRateDeterminedDistributions.Get("Jet_"+args.HistogramName+"_SS")
    
    print("Creating the QCD histogram")
    Data_AntiIso_SS.Add(DY_AntiIso_SS,-1.0)
    Data_AntiIso_SS.Add(TT_AntiIso_SS,-1.0)
    Data_AntiIso_SS.Add(Diboson_AntiIso_SS,-1.0)
    Data_AntiIso_SS.Add(W_AntiIso_SS,-1.0)
    Data_AntiIso_SS.Scale(1.12)

    #Now create the other whatsits
    W_AntiIso.SetLineColor(ROOT.kBlack)
    W_AntiIso.SetFillColor(ROOT.TColor.GetColor("#a53db8"))
    
    Data_AntiIso_SS.SetLineColor(ROOT.kBlack)
    Data_AntiIso_SS.SetFillColor(ROOT.TColor.GetColor("#ffccff"))

    SecondCanvas = ROOT.TCanvas("SecondCanvas","SecondCanvas")
    TotalStack = ROOT.THStack("TotalStack","TotalStack")
    #TotalStack.Add(Data_AntiIso_SS,"hist")
    TotalStack.Add(W_AntiIso,"hist")
    TotalStack.Add(DY_AntiIso,"hist")
    TotalStack.Add(TT_AntiIso,"hist")
    TotalStack.Add(Diboson_AntiIso,"hist")

    Data_AntiIso.SetMaximum(max(Data_AntiIso.GetMaximum(),TotalStack.GetMaximum())*1.05)

    Data_AntiIso.Draw("e1")
    Data_AntiIso.SetTitle("All Backgrounds "+args.HistogramName)
    TotalStack.Draw("SAME")
    Data_AntiIso.Draw("SAME e1")

    TotalLegend = ROOT.TLegend(0.7,0.5,0.88,0.68)
    TotalLegend.AddEntry(Data_AntiIso,"Data","EP")
    #TotalLegend.AddEntry(Data_AntiIso_SS,"QCD","f")
    TotalLegend.AddEntry(W_AntiIso,"W+Jets (Genuine jets included)","f")
    TotalLegend.AddEntry(Diboson_AntiIso,"VV+ST","f")
    TotalLegend.AddEntry(TT_AntiIso,"t#bar{t}","f")
    TotalLegend.AddEntry(DY_AntiIso,"All DY","f")
    TotalLegend.Draw()

    SecondCanvas.Draw()
    SecondCanvas.SaveAs("../Histos/AntiIso_Total_"+args.HistogramName+".png")
    
