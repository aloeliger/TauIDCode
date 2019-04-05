import ROOT
import argparse

ROOT.gStyle.SetOptStat(0)

parser = argparse.ArgumentParser(description = "Generate WJets Anti Isolation plots")
parser.add_argument('HistogramName',nargs="?",help="Histogram to draw")

args=parser.parse_args()

TheFile = ROOT.TFile("../Distributions/MCInJetsRegion.root")
W_Plus = TheFile.Get("W_"+args.HistogramName+"_WPlus")
W1_Plus = TheFile.Get("W1_"+args.HistogramName+"_WPlus")
W2_Plus = TheFile.Get("W2_"+args.HistogramName+"_WPlus")
W3_Plus = TheFile.Get("W3_"+args.HistogramName+"_WPlus")
W4_Plus = TheFile.Get("W4_"+args.HistogramName+"_WPlus")

W_Minus = TheFile.Get("W_"+args.HistogramName+"_WMinus")
W1_Minus = TheFile.Get("W1_"+args.HistogramName+"_WMinus")
W2_Minus = TheFile.Get("W2_"+args.HistogramName+"_WMinus")
W3_Minus = TheFile.Get("W3_"+args.HistogramName+"_WMinus")
W4_Minus = TheFile.Get("W4_"+args.HistogramName+"_WMinus")

W_Plus.Add(W1_Plus)
W_Plus.Add(W2_Plus)
W_Plus.Add(W3_Plus)
W_Plus.Add(W4_Plus)

W_Minus.Add(W1_Minus)
W_Minus.Add(W2_Minus)
W_Minus.Add(W3_Minus)
W_Minus.Add(W4_Minus)

W_Plus.SetMarkerStyle(21)
W_Plus.SetMarkerColor(ROOT.kRed)

W_Minus.SetMarkerStyle(22)
W_Minus.SetMarkerColor(ROOT.kBlue)

TheCanvas = ROOT.TCanvas("TheCanvas","TheCanvas")
W_Plus.SetTitle("AntiIso W")
W_Plus.Draw("e1 ")
W_Minus.Draw("e1 SAME")

TheLegend = ROOT.TLegend(0.6,0.6,0.8,0.8)
TheLegend.AddEntry(W_Plus,"W+","p")
TheLegend.AddEntry(W_Minus,"W-","p")
TheLegend.Draw()
TheCanvas.SaveAs("../Histos/WAntiIsoComparison.png")

raw_input("Press Enter to continue...")
