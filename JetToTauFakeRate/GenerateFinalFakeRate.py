import ROOT

TheFile = ROOT.TFile("../Distributions/FinalFakeRateEventsDistributions.root")

def GetTrueEventsHisto(HistogramName):    
    DataHisto = TheFile.Data.Get("Data_"+HistogramName)
    DYHisto = TheFile.DY.Get("DY_"+HistogramName)
    DY1Histo = TheFile.DY1.Get("DY1_"+HistogramName)
    DY2Histo = TheFile.DY2.Get("DY2_"+HistogramName)
    DY3Histo = TheFile.DY3.Get("DY3_"+HistogramName)
    DY4Histo = TheFile.DY4.Get("DY4_"+HistogramName)
    TTTo2L2NuHisto = TheFile.TTTo2L2Nu.Get("TTTo2L2Nu_"+HistogramName)
    TTToHadronicHisto = TheFile.TTToHadronic.Get("TTToHadronic_"+HistogramName)
    TTToSemiLeptonicHisto = TheFile.TTToSemiLeptonic.Get("TTToSemiLeptonic_"+HistogramName)
    ST_topHisto = TheFile.ST_top.Get("ST_top_"+HistogramName)
    ST_antitopHisto = TheFile.ST_antitop.Get("ST_antitop_"+HistogramName)
    ST_tW_topHisto = TheFile.ST_tW_top.Get("ST_tW_top_"+HistogramName)
    ST_tW_antitopHisto = TheFile.ST_tW_antitop.Get("ST_tW_antitop_"+HistogramName)
    WWHisto = TheFile.WW.Get("WW_"+HistogramName)
    WZHisto = TheFile.WZ.Get("WZ_"+HistogramName)
    ZZHisto = TheFile.ZZ.Get("ZZ_"+HistogramName)

    DataHisto.Add(DYHisto,-1.0)
    DataHisto.Add(DY1Histo,-1.0)
    DataHisto.Add(DY2Histo,-1.0)
    DataHisto.Add(DY3Histo,-1.0)
    DataHisto.Add(DY4Histo,-1.0)
    DataHisto.Add(TTTo2L2NuHisto,-1.0)
    DataHisto.Add(TTToHadronicHisto,-1.0)
    DataHisto.Add(TTToSemiLeptonicHisto,-1.0)
    DataHisto.Add(ST_topHisto,-1.0)
    DataHisto.Add(ST_antitopHisto,-1.0)
    DataHisto.Add(ST_tW_topHisto,-1.0)
    DataHisto.Add(ST_tW_antitopHisto,-1.0)
    DataHisto.Add(WWHisto,-1.0)
    DataHisto.Add(WZHisto,-1.0)
    DataHisto.Add(ZZHisto,-1.0)

    return DataHisto

if __name__ == "__main__":
    #barrel
    BaselineDecayMode0PTBarrelFakeRates = GetTrueEventsHisto("BaselineDecayMode0PTBarrelEvents")
    BaselineDecayMode1PTBarrelFakeRates = GetTrueEventsHisto("BaselineDecayMode1PTBarrelEvents")
    BaselineDecayMode10PTBarrelFakeRates = GetTrueEventsHisto("BaselineDecayMode10PTBarrelEvents")

    VLooseDecayMode0PTBarrelFakeRates = GetTrueEventsHisto("VLooseDecayMode0PTBarrelEvents")
    VLooseDecayMode1PTBarrelFakeRates = GetTrueEventsHisto("VLooseDecayMode1PTBarrelEvents")
    VLooseDecayMode10PTBarrelFakeRates = GetTrueEventsHisto("VLooseDecayMode10PTBarrelEvents")
    
    LooseDecayMode0PTBarrelFakeRates = GetTrueEventsHisto("LooseDecayMode0PTBarrelEvents")
    LooseDecayMode1PTBarrelFakeRates = GetTrueEventsHisto("LooseDecayMode1PTBarrelEvents")
    LooseDecayMode10PTBarrelFakeRates = GetTrueEventsHisto("LooseDecayMode10PTBarrelEvents")

    MediumDecayMode0PTBarrelFakeRates = GetTrueEventsHisto("MediumDecayMode0PTBarrelEvents")
    MediumDecayMode1PTBarrelFakeRates = GetTrueEventsHisto("MediumDecayMode1PTBarrelEvents")
    MediumDecayMode10PTBarrelFakeRates = GetTrueEventsHisto("MediumDecayMode10PTBarrelEvents")

    TightDecayMode0PTBarrelFakeRates = GetTrueEventsHisto("TightDecayMode0PTBarrelEvents")
    TightDecayMode1PTBarrelFakeRates = GetTrueEventsHisto("TightDecayMode1PTBarrelEvents")
    TightDecayMode10PTBarrelFakeRates = GetTrueEventsHisto("TightDecayMode10PTBarrelEvents")

    VTightDecayMode0PTBarrelFakeRates = GetTrueEventsHisto("VTightDecayMode0PTBarrelEvents")
    VTightDecayMode1PTBarrelFakeRates = GetTrueEventsHisto("VTightDecayMode1PTBarrelEvents")
    VTightDecayMode10PTBarrelFakeRates = GetTrueEventsHisto("VTightDecayMode10PTBarrelEvents")

    VVTightDecayMode0PTBarrelFakeRates = GetTrueEventsHisto("VVTightDecayMode0PTBarrelEvents")
    VVTightDecayMode1PTBarrelFakeRates = GetTrueEventsHisto("VVTightDecayMode1PTBarrelEvents")
    VVTightDecayMode10PTBarrelFakeRates = GetTrueEventsHisto("VVTightDecayMode10PTBarrelEvents")

    #endcap
    BaselineDecayMode0PTEndcapFakeRates = GetTrueEventsHisto("BaselineDecayMode0PTEndcapEvents")
    BaselineDecayMode1PTEndcapFakeRates = GetTrueEventsHisto("BaselineDecayMode1PTEndcapEvents")
    BaselineDecayMode10PTEndcapFakeRates = GetTrueEventsHisto("BaselineDecayMode10PTEndcapEvents")

    VLooseDecayMode0PTEndcapFakeRates = GetTrueEventsHisto("VLooseDecayMode0PTEndcapEvents")
    VLooseDecayMode1PTEndcapFakeRates = GetTrueEventsHisto("VLooseDecayMode1PTEndcapEvents")
    VLooseDecayMode10PTEndcapFakeRates = GetTrueEventsHisto("VLooseDecayMode10PTEndcapEvents")
    
    LooseDecayMode0PTEndcapFakeRates = GetTrueEventsHisto("LooseDecayMode0PTEndcapEvents")
    LooseDecayMode1PTEndcapFakeRates = GetTrueEventsHisto("LooseDecayMode1PTEndcapEvents")
    LooseDecayMode10PTEndcapFakeRates = GetTrueEventsHisto("LooseDecayMode10PTEndcapEvents")

    MediumDecayMode0PTEndcapFakeRates = GetTrueEventsHisto("MediumDecayMode0PTEndcapEvents")
    MediumDecayMode1PTEndcapFakeRates = GetTrueEventsHisto("MediumDecayMode1PTEndcapEvents")
    MediumDecayMode10PTEndcapFakeRates = GetTrueEventsHisto("MediumDecayMode10PTEndcapEvents")

    TightDecayMode0PTEndcapFakeRates = GetTrueEventsHisto("TightDecayMode0PTEndcapEvents")
    TightDecayMode1PTEndcapFakeRates = GetTrueEventsHisto("TightDecayMode1PTEndcapEvents")
    TightDecayMode10PTEndcapFakeRates = GetTrueEventsHisto("TightDecayMode10PTEndcapEvents")

    VTightDecayMode0PTEndcapFakeRates = GetTrueEventsHisto("VTightDecayMode0PTEndcapEvents")
    VTightDecayMode1PTEndcapFakeRates = GetTrueEventsHisto("VTightDecayMode1PTEndcapEvents")
    VTightDecayMode10PTEndcapFakeRates = GetTrueEventsHisto("VTightDecayMode10PTEndcapEvents")

    VVTightDecayMode0PTEndcapFakeRates = GetTrueEventsHisto("VVTightDecayMode0PTEndcapEvents")
    VVTightDecayMode1PTEndcapFakeRates = GetTrueEventsHisto("VVTightDecayMode1PTEndcapEvents")
    VVTightDecayMode10PTEndcapFakeRates = GetTrueEventsHisto("VVTightDecayMode10PTEndcapEvents")

    #get the general fake rates used in the uncertainties
    OverallDecayMode0FakeEvents = GetTrueEventsHisto("OverallDecayMode0Events")
    OverallDecayMode1FakeEvents = GetTrueEventsHisto("OverallDecayMode1Events")
    OverallDecayMode10FakeEvents = GetTrueEventsHisto("OverallDecayMode10Events")
    #divide everything        
    #barrel
    VVTightDecayMode0PTBarrelFakeRates.Divide(VLooseDecayMode0PTBarrelFakeRates)
    VVTightDecayMode1PTBarrelFakeRates.Divide(VLooseDecayMode1PTBarrelFakeRates)
    VVTightDecayMode10PTBarrelFakeRates.Divide(VLooseDecayMode10PTBarrelFakeRates)

    VTightDecayMode0PTBarrelFakeRates.Divide(VLooseDecayMode0PTBarrelFakeRates)
    VTightDecayMode1PTBarrelFakeRates.Divide(VLooseDecayMode1PTBarrelFakeRates)
    VTightDecayMode10PTBarrelFakeRates.Divide(VLooseDecayMode10PTBarrelFakeRates)

    TightDecayMode0PTBarrelFakeRates.Divide(VLooseDecayMode0PTBarrelFakeRates)
    TightDecayMode1PTBarrelFakeRates.Divide(VLooseDecayMode1PTBarrelFakeRates)
    TightDecayMode10PTBarrelFakeRates.Divide(VLooseDecayMode10PTBarrelFakeRates)

    MediumDecayMode0PTBarrelFakeRates.Divide(VLooseDecayMode0PTBarrelFakeRates)
    MediumDecayMode1PTBarrelFakeRates.Divide(VLooseDecayMode1PTBarrelFakeRates)
    MediumDecayMode10PTBarrelFakeRates.Divide(VLooseDecayMode10PTBarrelFakeRates)

    LooseDecayMode0PTBarrelFakeRates.Divide(VLooseDecayMode0PTBarrelFakeRates)
    LooseDecayMode1PTBarrelFakeRates.Divide(VLooseDecayMode1PTBarrelFakeRates)
    LooseDecayMode10PTBarrelFakeRates.Divide(VLooseDecayMode10PTBarrelFakeRates)

    VLooseDecayMode0PTBarrelFakeRates.Divide(BaselineDecayMode0PTBarrelFakeRates)
    VLooseDecayMode1PTBarrelFakeRates.Divide(BaselineDecayMode1PTBarrelFakeRates)
    VLooseDecayMode10PTBarrelFakeRates.Divide(BaselineDecayMode10PTBarrelFakeRates)

    #endcap
    VVTightDecayMode0PTEndcapFakeRates.Divide(VLooseDecayMode0PTEndcapFakeRates)
    VVTightDecayMode1PTEndcapFakeRates.Divide(VLooseDecayMode1PTEndcapFakeRates)
    VVTightDecayMode10PTEndcapFakeRates.Divide(VLooseDecayMode10PTEndcapFakeRates)

    VTightDecayMode0PTEndcapFakeRates.Divide(VLooseDecayMode0PTEndcapFakeRates)
    VTightDecayMode1PTEndcapFakeRates.Divide(VLooseDecayMode1PTEndcapFakeRates)
    VTightDecayMode10PTEndcapFakeRates.Divide(VLooseDecayMode10PTEndcapFakeRates)

    TightDecayMode0PTEndcapFakeRates.Divide(VLooseDecayMode0PTEndcapFakeRates)
    TightDecayMode1PTEndcapFakeRates.Divide(VLooseDecayMode1PTEndcapFakeRates)
    TightDecayMode10PTEndcapFakeRates.Divide(VLooseDecayMode10PTEndcapFakeRates)

    MediumDecayMode0PTEndcapFakeRates.Divide(VLooseDecayMode0PTEndcapFakeRates)
    MediumDecayMode1PTEndcapFakeRates.Divide(VLooseDecayMode1PTEndcapFakeRates)
    MediumDecayMode10PTEndcapFakeRates.Divide(VLooseDecayMode10PTEndcapFakeRates)

    LooseDecayMode0PTEndcapFakeRates.Divide(VLooseDecayMode0PTEndcapFakeRates)
    LooseDecayMode1PTEndcapFakeRates.Divide(VLooseDecayMode1PTEndcapFakeRates)
    LooseDecayMode10PTEndcapFakeRates.Divide(VLooseDecayMode10PTEndcapFakeRates)

    VLooseDecayMode0PTEndcapFakeRates.Divide(BaselineDecayMode0PTEndcapFakeRates)
    VLooseDecayMode1PTEndcapFakeRates.Divide(BaselineDecayMode1PTEndcapFakeRates)
    VLooseDecayMode10PTEndcapFakeRates.Divide(BaselineDecayMode10PTEndcapFakeRates)

    #handle the renaming    
    VLooseDecayMode0PTBarrelFakeRates.SetNameTitle("VLooseDecayMode0PTBarrelFakeRates","VLooseDecayMode0PTBarrelFakeRates")
    VLooseDecayMode1PTBarrelFakeRates.SetNameTitle("VLooseDecayMode1PTBarrelFakeRates","VLooseDecayMode1PTBarrelFakeRates")
    VLooseDecayMode10PTBarrelFakeRates.SetNameTitle("VLooseDecayMode10PTBarrelFakeRates","VLooseDecayMode10PTBarrelFakeRates")
    
    LooseDecayMode0PTBarrelFakeRates.SetNameTitle("LooseDecayMode0PTBarrelFakeRates","LooseDecayMode0PTBarrelFakeRates")
    LooseDecayMode1PTBarrelFakeRates.SetNameTitle("LooseDecayMode1PTBarrelFakeRates","LooseDecayMode1PTBarrelFakeRates")
    LooseDecayMode10PTBarrelFakeRates.SetNameTitle("LooseDecayMode10PTBarrelFakeRates","LooseDecayMode10PTBarrelFakeRates")

    MediumDecayMode0PTBarrelFakeRates.SetNameTitle("MediumDecayMode0PTBarrelFakeRates","MediumDecayMode0PTBarrelFakeRates")
    MediumDecayMode1PTBarrelFakeRates.SetNameTitle("MediumDecayMode1PTBarrelFakeRates","MediumDecayMode1PTBarrelFakeRates")
    MediumDecayMode10PTBarrelFakeRates.SetNameTitle("MediumDecayMode10PTBarrelFakeRates","MediumDecayMode10PTBarrelFakeRates")

    TightDecayMode0PTBarrelFakeRates.SetNameTitle("TightDecayMode0PTBarrelFakeRates","TightDecayMode0PTBarrelFakeRates")
    TightDecayMode1PTBarrelFakeRates.SetNameTitle("TightDecayMode1PTBarrelFakeRates","TightDecayMode1PTBarrelFakeRates")
    TightDecayMode10PTBarrelFakeRates.SetNameTitle("TightDecayMode10PTBarrelFakeRates","TightDecayMode10PTBarrelFakeRates")

    VTightDecayMode0PTBarrelFakeRates.SetNameTitle("VTightDecayMode0PTBarrelFakeRates","VTightDecayMode0PTBarrelFakeRates")
    VTightDecayMode1PTBarrelFakeRates.SetNameTitle("VTightDecayMode1PTBarrelFakeRates","VTightDecayMode1PTBarrelFakeRates")
    VTightDecayMode10PTBarrelFakeRates.SetNameTitle("VTightDecayMode10PTBarrelFakeRates","VTightDecayMode10PTBarrelFakeRates")

    VVTightDecayMode0PTBarrelFakeRates.SetNameTitle("VVTightDecayMode0PTBarrelFakeRates","VVTightDecayMode0PTBarrelFakeRates")
    VVTightDecayMode1PTBarrelFakeRates.SetNameTitle("VVTightDecayMode1PTBarrelFakeRates","VVTightDecayMode1PTBarrelFakeRates")
    VVTightDecayMode10PTBarrelFakeRates.SetNameTitle("VVTightDecayMode10PTBarrelFakeRates","VVTightDecayMode10PTBarrelFakeRates")

    #endcap
    VLooseDecayMode0PTEndcapFakeRates.SetNameTitle("VLooseDecayMode0PTEndcapFakeRates","VLooseDecayMode0PTEndcapFakeRates")
    VLooseDecayMode1PTEndcapFakeRates.SetNameTitle("VLooseDecayMode1PTEndcapFakeRates","VLooseDecayMode1PTEndcapFakeRates")
    VLooseDecayMode10PTEndcapFakeRates.SetNameTitle("VLooseDecayMode10PTEndcapFakeRates","VLooseDecayMode10PTEndcapFakeRates")
    
    LooseDecayMode0PTEndcapFakeRates.SetNameTitle("LooseDecayMode0PTEndcapFakeRates","LooseDecayMode0PTEndcapFakeRates")
    LooseDecayMode1PTEndcapFakeRates.SetNameTitle("LooseDecayMode1PTEndcapFakeRates","LooseDecayMode1PTEndcapFakeRates")
    LooseDecayMode10PTEndcapFakeRates.SetNameTitle("LooseDecayMode10PTEndcapFakeRates","LooseDecayMode10PTEndcapFakeRates")

    MediumDecayMode0PTEndcapFakeRates.SetNameTitle("MediumDecayMode0PTEndcapFakeRates","MediumDecayMode0PTEndcapFakeRates")
    MediumDecayMode1PTEndcapFakeRates.SetNameTitle("MediumDecayMode1PTEndcapFakeRates","MediumDecayMode1PTEndcapFakeRates")
    MediumDecayMode10PTEndcapFakeRates.SetNameTitle("MediumDecayMode10PTEndcapFakeRates","MediumDecayMode10PTEndcapFakeRates")

    TightDecayMode0PTEndcapFakeRates.SetNameTitle("TightDecayMode0PTEndcapFakeRates","TightDecayMode0PTEndcapFakeRates")
    TightDecayMode1PTEndcapFakeRates.SetNameTitle("TightDecayMode1PTEndcapFakeRates","TightDecayMode1PTEndcapFakeRates")
    TightDecayMode10PTEndcapFakeRates.SetNameTitle("TightDecayMode10PTEndcapFakeRates","TightDecayMode10PTEndcapFakeRates")

    VTightDecayMode0PTEndcapFakeRates.SetNameTitle("VTightDecayMode0PTEndcapFakeRates","VTightDecayMode0PTEndcapFakeRates")
    VTightDecayMode1PTEndcapFakeRates.SetNameTitle("VTightDecayMode1PTEndcapFakeRates","VTightDecayMode1PTEndcapFakeRates")
    VTightDecayMode10PTEndcapFakeRates.SetNameTitle("VTightDecayMode10PTEndcapFakeRates","VTightDecayMode10PTEndcapFakeRates")

    VVTightDecayMode0PTEndcapFakeRates.SetNameTitle("VVTightDecayMode0PTEndcapFakeRates","VVTightDecayMode0PTEndcapFakeRates")
    VVTightDecayMode1PTEndcapFakeRates.SetNameTitle("VVTightDecayMode1PTEndcapFakeRates","VVTightDecayMode1PTEndcapFakeRates")
    VVTightDecayMode10PTEndcapFakeRates.SetNameTitle("VVTightDecayMode10PTEndcapFakeRates","VVTightDecayMode10PTEndcapFakeRates")

    #create the overall fake rates
    OverallDecayMode0FakeRates = ROOT.TH1F("OverallDecayMode0FakeRates","OverallDecayMode0FakeRates",6,0.0,6.0)
    OverallDecayMode1FakeRates = ROOT.TH1F("OverallDecayMode1FakeRates","OverallDecayMode1FakeRates",6,0.0,6.0)
    OverallDecayMode10FakeRates = ROOT.TH1F("OverallDecayMode10FakeRates","OverallDecayMode10FakeRates",6,0.0,6.0)

    OverallDecayMode0FakeRates.SetBinContent(1,OverallDecayMode0FakeEvents.GetBinContent(2)/OverallDecayMode0FakeEvents.GetBinContent(1))
    OverallDecayMode0FakeRates.SetBinContent(2,OverallDecayMode0FakeEvents.GetBinContent(3)/OverallDecayMode0FakeEvents.GetBinContent(2))
    OverallDecayMode0FakeRates.SetBinContent(3,OverallDecayMode0FakeEvents.GetBinContent(4)/OverallDecayMode0FakeEvents.GetBinContent(2))
    OverallDecayMode0FakeRates.SetBinContent(4,OverallDecayMode0FakeEvents.GetBinContent(5)/OverallDecayMode0FakeEvents.GetBinContent(2))
    OverallDecayMode0FakeRates.SetBinContent(5,OverallDecayMode0FakeEvents.GetBinContent(6)/OverallDecayMode0FakeEvents.GetBinContent(2))
    OverallDecayMode0FakeRates.SetBinContent(6,OverallDecayMode0FakeEvents.GetBinContent(7)/OverallDecayMode0FakeEvents.GetBinContent(2))

    OverallDecayMode1FakeRates.SetBinContent(1,OverallDecayMode1FakeEvents.GetBinContent(2)/OverallDecayMode1FakeEvents.GetBinContent(1))
    OverallDecayMode1FakeRates.SetBinContent(2,OverallDecayMode1FakeEvents.GetBinContent(3)/OverallDecayMode1FakeEvents.GetBinContent(2))
    OverallDecayMode1FakeRates.SetBinContent(3,OverallDecayMode1FakeEvents.GetBinContent(4)/OverallDecayMode1FakeEvents.GetBinContent(2))
    OverallDecayMode1FakeRates.SetBinContent(4,OverallDecayMode1FakeEvents.GetBinContent(5)/OverallDecayMode1FakeEvents.GetBinContent(2))
    OverallDecayMode1FakeRates.SetBinContent(5,OverallDecayMode1FakeEvents.GetBinContent(6)/OverallDecayMode1FakeEvents.GetBinContent(2))
    OverallDecayMode1FakeRates.SetBinContent(6,OverallDecayMode1FakeEvents.GetBinContent(7)/OverallDecayMode1FakeEvents.GetBinContent(2))

    OverallDecayMode10FakeRates.SetBinContent(1,OverallDecayMode10FakeEvents.GetBinContent(2)/OverallDecayMode10FakeEvents.GetBinContent(1))
    OverallDecayMode10FakeRates.SetBinContent(2,OverallDecayMode10FakeEvents.GetBinContent(3)/OverallDecayMode10FakeEvents.GetBinContent(2))
    OverallDecayMode10FakeRates.SetBinContent(3,OverallDecayMode10FakeEvents.GetBinContent(4)/OverallDecayMode10FakeEvents.GetBinContent(2))
    OverallDecayMode10FakeRates.SetBinContent(4,OverallDecayMode10FakeEvents.GetBinContent(5)/OverallDecayMode10FakeEvents.GetBinContent(2))
    OverallDecayMode10FakeRates.SetBinContent(5,OverallDecayMode10FakeEvents.GetBinContent(6)/OverallDecayMode10FakeEvents.GetBinContent(2))
    OverallDecayMode10FakeRates.SetBinContent(6,OverallDecayMode10FakeEvents.GetBinContent(7)/OverallDecayMode10FakeEvents.GetBinContent(2))

    #write everything out to file.
    FakeRateFile = ROOT.TFile("../Distributions/FakeRateDistributions.root","RECREATE")
    OverallDecayMode0FakeRates.Write()
    OverallDecayMode1FakeRates.Write()
    OverallDecayMode10FakeRates.Write()

    #barrel    
    VLooseDecayMode0PTBarrelFakeRates.Write()
    VLooseDecayMode1PTBarrelFakeRates.Write()
    VLooseDecayMode10PTBarrelFakeRates.Write()
    
    LooseDecayMode0PTBarrelFakeRates.Write()
    LooseDecayMode1PTBarrelFakeRates.Write()
    LooseDecayMode10PTBarrelFakeRates.Write()

    MediumDecayMode0PTBarrelFakeRates.Write()
    MediumDecayMode1PTBarrelFakeRates.Write()
    MediumDecayMode10PTBarrelFakeRates.Write()

    TightDecayMode0PTBarrelFakeRates.Write()
    TightDecayMode1PTBarrelFakeRates.Write()
    TightDecayMode10PTBarrelFakeRates.Write()

    VTightDecayMode0PTBarrelFakeRates.Write()
    VTightDecayMode1PTBarrelFakeRates.Write()
    VTightDecayMode10PTBarrelFakeRates.Write()

    VVTightDecayMode0PTBarrelFakeRates.Write()
    VVTightDecayMode1PTBarrelFakeRates.Write()
    VVTightDecayMode10PTBarrelFakeRates.Write()

    #endcap    
    VLooseDecayMode0PTEndcapFakeRates.Write()
    VLooseDecayMode1PTEndcapFakeRates.Write()
    VLooseDecayMode10PTEndcapFakeRates.Write()
    
    LooseDecayMode0PTEndcapFakeRates.Write()
    LooseDecayMode1PTEndcapFakeRates.Write()
    LooseDecayMode10PTEndcapFakeRates.Write()

    MediumDecayMode0PTEndcapFakeRates.Write()
    MediumDecayMode1PTEndcapFakeRates.Write()
    MediumDecayMode10PTEndcapFakeRates.Write()

    TightDecayMode0PTEndcapFakeRates.Write()
    TightDecayMode1PTEndcapFakeRates.Write()
    TightDecayMode10PTEndcapFakeRates.Write()

    VTightDecayMode0PTEndcapFakeRates.Write()
    VTightDecayMode1PTEndcapFakeRates.Write()
    VTightDecayMode10PTEndcapFakeRates.Write()

    VVTightDecayMode0PTEndcapFakeRates.Write()
    VVTightDecayMode1PTEndcapFakeRates.Write()
    VVTightDecayMode10PTEndcapFakeRates.Write()
