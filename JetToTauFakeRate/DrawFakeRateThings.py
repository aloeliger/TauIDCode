import ROOT
import argparse
import GenerateFinalFakeRate

TheFile = ROOT.TFile("../Distributions/FinalFakeRateEventsDistributions.root")

def MakeThePlot(args):
    UncorrectedDataHisto = TheFile.Data.Get("Data_"+args.HistogramName)
    CorrectedDataHisto = GenerateFinalFakeRate.GetTrueEventsHisto(args.HistogramName)

    UncorrectedDenominator = TheFile.Data.Get("Data_"+args.DenominatorHistogramName)
    CorrectedDenominator = GenerateFinalFakeRate.GetTrueEventsHisto(args.DenominatorHistogramName)

    UncorrectedDataHisto.SetLineColor(ROOT.kRed)
    CorrectedDataHisto.SetLineColor(ROOT.kBlue)
    
    UncorrectedDenominator.SetLineColor(ROOT.kRed)
    CorrectedDenominator.SetLineColor(ROOT.kBlue)

    UncorrectedFakeRatePlot = UncorrectedDataHisto.Clone()
    CorrectedFakeRatePlot = CorrectedDataHisto.Clone()
    UncorrectedFakeRatePlot.Divide(UncorrectedDenominator)
    CorrectedFakeRatePlot.Divide(CorrectedDenominator)

    Legend = ROOT.TLegend(0.6,0.6,0.8,0.8)
    Legend.AddEntry(UncorrectedDataHisto,"Uncorrected","l")
    Legend.AddEntry(CorrectedDataHisto,"Corrected","l")
    
    FirstCanvas = ROOT.TCanvas("FirstCanvas")
    #FirstCanvas.SetLogy()
    UncorrectedDataHisto.SetTitle("Numerator")
    UncorrectedDataHisto.GetXaxis().SetTitle("pt")
    UncorrectedDataHisto.Draw()
    CorrectedDataHisto.Draw("SAME")

    Legend.Draw()

    SecondCanvas = ROOT.TCanvas("SecondCanvas")
    #SecondCanvas.SetLogy()
    UncorrectedDenominator.SetTitle("Denominator")
    UncorrectedDenominator.GetXaxis().SetTitle("pt")
    UncorrectedDenominator.Draw()
    CorrectedDenominator.Draw("SAME")

    Legend.Draw()

    ThirdCanvas = ROOT.TCanvas("ThirdCanvas")    
    UncorrectedFakeRatePlot.SetTitle("FakeRatePlot")
    UncorrectedFakeRatePlot.GetXaxis().SetTitle("pt")
    UncorrectedFakeRatePlot.Draw()
    CorrectedFakeRatePlot.Draw("SAME")

    Legend.Draw()

    FirstCanvas.SaveAs("../Histos/FakeRateNumerator_"+args.HistogramName+".png")
    SecondCanvas.SaveAs("../Histos/FakeRateDenominator_"+args.HistogramName+".png")
    ThirdCanvas.SaveAs("../Histos/FakeRatePlot_"+args.HistogramName+".png")
    raw_input("Press Enter to continue...")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate some fake rate plots")
    parser.add_argument('HistogramName',nargs="?",help="Histogram to draw")
    parser.add_argument('DenominatorHistogramName',nargs="?",help="Denominator Histogram Specification")

    args = parser.parse_args()
    
    MakeThePlot(args)
    
