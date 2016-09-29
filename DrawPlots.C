#include "TString.h"
#include <vector>

void DrawPlots(TString sample){
	TString dir_loc = "/nfs-7/userdata/bobak/MassWindowStudies/"

	vector<TFile*> files;
	if (sample == "edge"){
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_Base_EdgeZ.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_med_EdgeZ.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_tight_EdgeZ.root"), "READ"));

		files.push_back(TFile::Open(dir_loc+TString("ct_Z_Base_EdgeZ.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_Z_med_EdgeZ.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_Z_tight_EdgeZ.root"), "READ"));
	}

	else{
		exit(1);
	}

	TH1D * tt_met_loose = (TH1D*) ((TH1D*) files[0]->Get("TT_Base_type1MET_widebin"))->Clone("tt_met_loose");
	TH1D * tt_met_med = (TH1D*) ((TH1D*) files[1]->Get("TT_med_type1MET_widebin"))->Clone("tt_met_med");
	TH1D * tt_met_tight = (TH1D*) ((TH1D*) files[2]->Get("TT_tight_type1MET_widebin"))->Clone("tt_met_tight");

	TH1D * z_met_loose = (TH1D*) ((TH1D*) files[3]->Get("zjets_type1MET_widebin"))->Clone("z_met_loose");
	TH1D * z_met_med = (TH1D*) ((TH1D*) files[4]->Get("zjets_type1MET_widebin"))->Clone("z_met_med");
	TH1D * z_met_tight = (TH1D*) ((TH1D*) files[5]->Get("zjets_type1MET_widebin"))->Clone("z_met_tight");

	z_met_tight->SetLineColor(kRed);
	z_met_med->SetLineColor(kRed);
	z_met_loose->SetLineColor(kRed);

	tt_met_tight->SetLineColor(kBlue);
	tt_met_med->SetLineColor(kBlue);
	tt_met_loose->SetLineColor(kBlue);

	TH1D * tt_dilmass_loose = (TH1D*) ((TH1D*) files[0]->Get("TT_Base_dilmass"))->Clone("tt_dilmass_loose");
	TH1D * tt_dilmass_med = (TH1D*) ((TH1D*) files[1]->Get("TT_med_dilmass"))->Clone("tt_dilmass_med");
	TH1D * tt_dilmass_tight = (TH1D*) ((TH1D*) files[2]->Get("TT_tight_dilmass"))->Clone("tt_dilmass_tight");

	TH1D * z_dilmass_loose = (TH1D*) ((TH1D*) files[3]->Get("zjets_dilmass"))->Clone("z_dilmass_loose");
	TH1D * z_dilmass_med = (TH1D*) ((TH1D*) files[4]->Get("zjets_dilmass"))->Clone("z_dilmass_med");
	TH1D * z_dilmass_tight = (TH1D*) ((TH1D*) files[5]->Get("zjets_dilmass"))->Clone("z_dilmass_tight");	

	z_dilmass_tight->SetLineColor(kRed);
	z_dilmass_med->SetLineColor(kRed);
	z_dilmass_loose->SetLineColor(kRed);

	tt_dilmass_tight->SetLineColor(kBlue);
	tt_dilmass_med->SetLineColor(kBlue);
	tt_dilmass_loose->SetLineColor(kBlue);

	gPad->SetLogy(1);
	gStyle->SetOptStat(kFALSE);

//===============================
//Draw Loose Plots
//===============================

	TCanvas *c1 = new TCanvas("MET_loose", "", 2000, 2000);
	c1->cd();

	z_met_loose->SetTitle("E^{miss}_{T} for 10 GeV Window");
	z_met_loose->Draw("HIST");
	tt_met_loose->Draw("HIST SAME");
	
	TLegend *l1;
	l1 = new TLegend(0.73, 0.73, 0.88, 0.88);
	  
	l1->SetLineColor(kWhite);  
	l1->SetShadowColor(kWhite);
	l1->SetFillColor(kWhite);
	l1->AddEntry(z_met_loose, "DY MC", "f");
	l1->AddEntry(tt_met_loose, "TTBar MC", "f");
	  
	l1->Draw("same");

	c1->SaveAs("loose_MET.png");


}