#include "TString.h"
#include <vector>
#include <iostream>
#include <iomanip>    

void DPhiPlots(TString sample){
	TString dir_loc = "/nfs-7/userdata/bobak/DPhiStudies/";
	TString output_dir = "/home/users/bhashemi/public_html/DPhiStudies/";

//=================
// Define Files
//=================

	TFile * tt_file = TFile::Open(dir_loc+TString("ct_TT_Base_EdgeZ.root"), "READ");
		
	TFile * z_file = TFile::Open(dir_loc+TString("ct_Z_Base_EdgeZ.root"), "READ");
	
	//cout<<__LINE__<<endl;

//===========================
// Get histograms from file:
//===========================
	
	//TTBar dPHI Plots
	TH1D * tt_dphi_loose_0_50 = (TH1D*) ((TH1D*) tt_file->Get("ttbar_DeltaPhi_lep_met_150_200"))->Clone("tt_dphi_loose_150_200");
	TH1D * tt_dphi_loose_50_100 = (TH1D*) ((TH1D*) tt_file->Get("ttbar_DeltaPhi_lep_met_150_200"))->Clone("tt_dphi_loose_150_200");
	TH1D * tt_dphi_loose_100_150 = (TH1D*) ((TH1D*) tt_file->Get("ttbar_DeltaPhi_lep_met_150_200"))->Clone("tt_dphi_loose_150_200");
	TH1D * tt_dphi_loose_150_225 = (TH1D*) ((TH1D*) tt_file->Get("ttbar_DeltaPhi_lep_met_150_200"))->Clone("tt_dphi_loose_150_200");
	TH1D * tt_dphi_loose_225_300 = (TH1D*) ((TH1D*) tt_file->Get("ttbar_DeltaPhi_lep_met_200_300"))->Clone("tt_dphi_loose_200_300");
	TH1D * tt_dphi_loose_300 = (TH1D*) ((TH1D*) tt_file->Get("ttbar_DeltaPhi_lep_met_300"))->Clone("tt_dphi_loose_300");

	//cout<<__LINE__<<endl;

	tt_dphi_loose_150_200->SetLineColor(46);
	tt_dphi_loose_150_200->SetFillColor(46);
	tt_dphi_loose_200_300->SetLineColor(8);
	tt_dphi_loose_200_300->SetFillColor(8);
	tt_dphi_loose_300->SetLineColor(9);
	tt_dphi_loose_300->SetFillColor(9);

	//cout<<__LINE__<<endl;

	// Z dPHI Plots
	TH1D * z_dphi_loose_0_50 = (TH1D*) ((TH1D*) z_file->Get("zjets_DeltaPhi_lep_met_0_50"))->Clone("z_dphi_loose_0_50");
	TH1D * z_dphi_loose_50_100 = (TH1D*) ((TH1D*) z_file->Get("zjets_DeltaPhi_lep_met_50_100"))->Clone("z_dphi_loose_50_100");
	TH1D * z_dphi_loose_100_150 = (TH1D*) ((TH1D*) z_file->Get("zjets_DeltaPhi_lep_met_100_150"))->Clone("z_dphi_loose_100_150");
	TH1D * z_dphi_loose_150_225 = (TH1D*) ((TH1D*) z_file->Get("zjets_DeltaPhi_lep_met_150_225"))->Clone("z_dphi_loose_150_225");
	TH1D * z_dphi_loose_225_300 = (TH1D*) ((TH1D*) z_file->Get("zjets_DeltaPhi_lep_met_225_300"))->Clone("z_dphi_loose_225_300");
	TH1D * z_dphi_loose_300 = (TH1D*) ((TH1D*) z_file->Get("zjets_DeltaPhi_lep_met_300"))->Clone("z_dphi_loose_300");

	z_dphi_loose_150_200->SetLineColor(46);
	z_dphi_loose_150_200->SetFillColor(46);
	z_dphi_loose_200_300->SetLineColor(8);
	z_dphi_loose_200_300->SetFillColor(8);
	z_dphi_loose_300->SetLineColor(9);
	z_dphi_loose_300->SetFillColor(9);

//===============================
//Add Overflow to MET Plots
//===============================

	double bc, of; //bin content and overflow

	bc = z_met_loose->GetBinContent(z_met_loose->FindBin(450));
	of = z_met_loose->GetBinContent(z_met_loose->FindBin(501));
	z_met_loose->SetBinContent(z_met_loose->FindBin(450), bc+of);

	bc = z_met_med->GetBinContent(z_met_med->FindBin(450));
	of = z_met_med->GetBinContent(z_met_med->FindBin(501));
	z_met_med->SetBinContent(z_met_med->FindBin(450), bc+of);

	bc = z_met_tight->GetBinContent(z_met_tight->FindBin(450));
	of = z_met_tight->GetBinContent(z_met_tight->FindBin(501));
	z_met_tight->SetBinContent(z_met_tight->FindBin(450), bc+of);

	bc = tt_met_loose->GetBinContent(tt_met_loose->FindBin(450));
	of = tt_met_loose->GetBinContent(tt_met_loose->FindBin(501));
	tt_met_loose->SetBinContent(tt_met_loose->FindBin(450), bc+of);

	bc = tt_met_med->GetBinContent(tt_met_med->FindBin(450));
	of = tt_met_med->GetBinContent(tt_met_med->FindBin(501));
	tt_met_med->SetBinContent(tt_met_med->FindBin(450), bc+of);

	bc = tt_met_tight->GetBinContent(tt_met_tight->FindBin(450));
	of = tt_met_tight->GetBinContent(tt_met_tight->FindBin(501));
	tt_met_tight->SetBinContent(tt_met_tight->FindBin(450), bc+of);


	double integral, error;
	
	integral = tt_dilmass_tight->IntegralAndError(1,tt_dilmass_tight->GetNbinsX(), error);
	cout<<"88.5-93.5 GeV: TTBar="<<integral<<"+/-"<<error;
	integral = z_dilmass_tight->IntegralAndError(1,z_dilmass_tight->GetNbinsX(), error);
	cout<<" Drell-Yan="<<integral<<"+/-"<<error<<endl;

	integral = tt_dilmass_med->IntegralAndError(1,tt_dilmass_med->GetNbinsX(), error);
	cout<<"86-96 GeV: TTBar="<<integral<<"+/-"<<error;
	integral = z_dilmass_med->IntegralAndError(1,z_dilmass_med->GetNbinsX(), error);
	cout<<" Drell-Yan="<<integral<<"+/-"<<error<<endl;
	
	integral = tt_dilmass_loose->IntegralAndError(1,tt_dilmass_loose->GetNbinsX(), error);
	cout<<"81-101 GeV: TTBar="<<integral<<"+/-"<<error;
	integral = z_dilmass_loose->IntegralAndError(1,z_dilmass_loose->GetNbinsX(), error);
	cout<<" Drell-Yan="<<integral<<"+/-"<<error<<endl;
	cout<<endl;


//===============================
//Draw Plots
//===============================
	//------------------
	// Delta Phi TTBar
	//------------------

	TCanvas *ctt_lowMET = new TCanvas("tt_lowMET", "", 2000, 2000);
	ctt_lowMET->cd();

	ctt_lowMET->Divide(1,3);	

	//cout<<__LINE__<<endl;

	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	ctt_lowMET->cd(1);
	tt_dphi_loose_0_50->SetTitle("#Delta#Phi(E^{miss}_{T}, dilepton) for t#bar{t} events with 10 GeV Mass Window: E^{miss}_{T} #in [0,50) GeV");
	//tt_dphi_loose_150_200->Scale(1/tt_dphi_loose_150_200->Integral());
	tt_dphi_loose_0_50->Draw("HIST");

	ctt_lowMET->cd(2);
	tt_dphi_loose_50_100->SetTitle("#Delta#Phi(E^{miss}_{T}, dilepton) for t#bar{t} events with 10 GeV Mass Window: E^{miss}_{T} #in [50,100) GeV");
	//tt_dphi_loose_200_300->Scale(1/tt_dphi_loose_200_300->Integral());
	tt_dphi_loose_50_100->Draw("HIST");
	
	ctt_lowMET->cd(3);
	tt_dphi_loose_100_150->SetTitle("#Delta#Phi(E^{miss}_{T}, dilepton) for t#bar{t} events with 10 GeV Mass Window: E^{miss}_{T} #in [100,150) GeV");
	//tt_dphi_loose_300->Scale(1/tt_dphi_loose_300->Integral());
	tt_dphi_loose_100_150->Draw("HIST");

	//cout<<__LINE__<<endl;
	ctt_lowMET->cd();
	ctt_lowMET->SaveAs(output_dir+sample+"_tt_lowMet_dPhi.png");

	TCanvas *ctt_HighMET = new TCanvas("tt_HighMET", "", 2000, 2000);
	ctt_HighMET->cd();

	ctt_HighMET->Divide(1,3);	

	//cout<<__LINE__<<endl;

	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	ctt_HighMET->cd(1);
	tt_dphi_loose_150_225->SetTitle("#Delta#Phi(E^{miss}_{T}, dilepton) for t#bar{t} events with 10 GeV Mass Window: E^{miss}_{T} #in [150,225)");
	//tt_dphi_loose_150_200->Scale(1/tt_dphi_loose_150_200->Integral());
	tt_dphi_loose_150_225->Draw("HIST");

	ctt_HighMET->cd(2);
	tt_dphi_loose_225_300->SetTitle("#Delta#Phi(E^{miss}_{T}, dilepton) for t#bar{t} events with 10 GeV Mass Window: E^{miss}_{T} #in [225,300)");
	//tt_dphi_loose_200_300->Scale(1/tt_dphi_loose_200_300->Integral());
	tt_dphi_loose_225_300->Draw("HIST");
	
	ctt_HighMET->cd(3);
	tt_dphi_loose_300->SetTitle("#Delta#Phi(E^{miss}_{T}, dilepton) for t#bar{t} events with 10 GeV Mass Window: E^{miss}_{T} #geq 300");
	//tt_dphi_loose_300->Scale(1/tt_dphi_loose_300->Integral());
	tt_dphi_loose_300->Draw("HIST");

	//cout<<__LINE__<<endl;

	ctt_HighMET->SaveAs(output_dir+sample+"_tt_HighMET_dPhi.png");

	//cout<<__LINE__<<endl;

	//------------------
	// Delta Phi Z
	//------------------

	TCanvas *cz_lowMET = new TCanvas("z_lowMET", "", 2000, 2000);
	cz_lowMET->cd();

	cz_lowMET->Divide(1,3);	

	//cout<<__LINE__<<endl;

	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	cz_lowMET->cd(1);
	z_dphi_loose_0_50->SetTitle("#Delta#Phi(E^{miss}_{T}, dilepton) for Z events with 10 GeV Mass Window: E^{miss}_{T} #in [0,50) GeV");
	//tt_dphi_loose_150_200->Scale(1/tt_dphi_loose_150_200->Integral());
	z_dphi_loose_0_50->Draw("HIST");

	cz_lowMET->cd(2);
	z_dphi_loose_50_100->SetTitle("#Delta#Phi(E^{miss}_{T}, dilepton) for Z events with 10 GeV Mass Window: E^{miss}_{T} #in [50,100) GeV");
	//tt_dphi_loose_200_300->Scale(1/tt_dphi_loose_200_300->Integral());
	z_dphi_loose_50_100->Draw("HIST");
	
	cz_lowMET->cd(3);
	z_dphi_loose_100_150->SetTitle("#Delta#Phi(E^{miss}_{T}, dilepton) for Z events with 10 GeV Mass Window: E^{miss}_{T} #in [100,150) GeV");
	//tt_dphi_loose_300->Scale(1/tt_dphi_loose_300->Integral());
	z_dphi_loose_100_150->Draw("HIST");

	//cout<<__LINE__<<endl;
	cz_lowMET->cd();
	cz_lowMET->SaveAs(output_dir+sample+"_z_lowMET_dPhi.png");

	TCanvas *cz_HighMET = new TCanvas("z_HighMET", "", 2000, 2000);
	cz_HighMET->cd();

	cz_HighMET->Divide(1,3);	

	//cout<<__LINE__<<endl;

	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	cz_HighMET->cd(1);
	z_dphi_loose_150_225->SetTitle("#Delta#Phi(E^{miss}_{T}, dilepton) for Z events with 10 GeV Mass Window: E^{miss}_{T} #in [150,225)");
	//tt_dphi_loose_150_200->Scale(1/tt_dphi_loose_150_200->Integral());
	z_dphi_loose_150_225->Draw("HIST");

	cz_HighMET->cd(2);
	z_dphi_loose_225_300->SetTitle("#Delta#Phi(E^{miss}_{T}, dilepton) for Z events with 10 GeV Mass Window: E^{miss}_{T} #in [225,300)");
	//tt_dphi_loose_200_300->Scale(1/tt_dphi_loose_200_300->Integral());
	z_dphi_loose_225_300->Draw("HIST");
	
	cz_HighMET->cd(3);
	z_dphi_loose_300->SetTitle("#Delta#Phi(E^{miss}_{T}, dilepton) for Z events with 10 GeV Mass Window: E^{miss}_{T} #geq 300");
	//tt_dphi_loose_300->Scale(1/tt_dphi_loose_300->Integral());
	z_dphi_loose_300->Draw("HIST");

	//cout<<__LINE__<<endl;
	cz_HighMET->cd();
	cz_HighMET->SaveAs(output_dir+sample+"_z_HighMET_dPhi.png");

	//cout<<__LINE__<<endl;



cz_lowMET->~TCanvas();
cz_HighMET->~TCanvas();
ctt_lowMET->~TCanvas();
ctt_HighMET->~TCanvas();


}

