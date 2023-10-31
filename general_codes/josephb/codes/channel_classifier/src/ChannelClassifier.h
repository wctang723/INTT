#ifndef CHANNEL_CLASSIFIER_H
#define CHANNEL_CLASSIFIER_H

#include <intt/InttMapping.h>

#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>

#include <filesystem>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include <TCanvas.h>
#include <TF1.h>
#include <TFile.h>
#include <TH1.h>
#include <TH1D.h>
#include <TTree.h>

//#include <RooAddPdf.h>
//#include <RooArgList.h>
//#include <RooDataSet.h>
//#include <RooFit.h>
//#include <RooPoisson.h>
//#include <RooPlot.h>
//#include <RooRealVar.h>

class ChannelClassifier
{
public:
	ChannelClassifier();
	~ChannelClassifier();

	Int_t constexpr static NUM_CHANNELS = 56 * 52 * 128;
	Int_t const static NUM_SIG = 5;
	Int_t const static NUM_BINS = 100;

	void Reset();

	Intt::Online_s static struct_from_hash(Int_t);
	Int_t static hash_from_struct(struct Intt::Online_s const&);
	Int_t static hash_from_struct(struct Intt::Offline_s const&);
	Int_t static hash_from_struct(struct Intt::RawData_s const&);

	void static print(Intt::Online_s const&);

	Double_t static SumGauss(Double_t* x, Double_t* par)
	{
		Double_t d = 0;

		for(std::size_t s = 0; s < par[0]; ++s)
		{
			d += par[3 * s + 3] * TMath::Gaus(*x, par[3 * s + 1], par[3 * s + 2], kTRUE);
		}

		return d;
	}

	int AppendFile(std::string const&);
	int OutputHits(std::string const&);
	int PoissonFit(std::string const&);

protected:
	std::string i_treename = "prdf_tree";
	std::string o_treename = "channel_tree";

	Long64_t* hits;
};

#endif//CHANNEL_CLASSIFIER_H