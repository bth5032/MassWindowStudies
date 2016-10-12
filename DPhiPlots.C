#include "TString.h"
#include <vector>
#include <iostream>
#include <iomanip>    

void DPhiPlots(TString files){

	TString dir_loc, output_dir;
	if (files.Contains("nojm") && ! files.Contains("v2"))
	{
		dir_loc = "/nfs-7/userdata/bobak/DPhiStudies/noJetMET/";
		output_dir = "/home/users/bhashemi/public_html/DPhiStudies/noJetMET/";
	}
	else if (files.Contains("nojm") && files.Contains("v2")){
		dir_loc = "/nfs-7/userdata/bobak/DPhiStudiesV2/noJetMET/";
		output_dir = "/home/users/bhashemi/public_html/DPhiStudiesV2/noJetMET/";

	}
	else if (files.Contains("v2")){
		dir_loc = "/nfs-7/userdata/bobak/DPhiStudiesV2/";
		output_dir = "/home/users/bhashemi/public_html/DPhiStudiesV2/";
	}
	else{
		dir_loc = "/nfs-7/userdata/bobak/DPhiStudies/";
		output_dir = "/home/users/bhashemi/public_html/DPhiStudies/";
	}

	cout<<"Reading From "<<dir_loc<<endl;
	
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
	TH1D * tt_dphi_loose_0_50 = (TH1D*) ((TH1D*) tt_file->Get("ttbar_DeltaPhi_lep_met_0_50"))->Clone("tt_dphi_loose_150_200");
	TH1D * tt_dphi_loose_50_100 = (TH1D*) ((TH1D*) tt_file->Get("ttbar_DeltaPhi_lep_met_50_100"))->Clone("tt_dphi_loose_150_200");
	TH1D * tt_dphi_loose_100_150 = (TH1D*) ((TH1D*) tt_file->Get("ttbar_DeltaPhi_lep_met_100_150"))->Clone("tt_dphi_loose_150_200");
	TH1D * tt_dphi_loose_150_225 = (TH1D*) ((TH1D*) tt_file->Get("ttbar_DeltaPhi_lep_met_150_225"))->Clone("tt_dphi_loose_150_200");
	TH1D * tt_dphi_loose_225_300 = (TH1D*) ((TH1D*) tt_file->Get("ttbar_DeltaPhi_lep_met_225_300"))->Clone("tt_dphi_loose_200_300");
	TH1D * tt_dphi_loose_300 = (TH1D*) ((TH1D*) tt_file->Get("ttbar_DeltaPhi_lep_met_300"))->Clone("tt_dphi_loose_300");

	//cout<<__LINE__<<endl;

	tt_dphi_loose_0_50->SetLineColor(46);
	tt_dphi_loose_0_50->SetFillColor(46);
	tt_dphi_loose_50_100->SetLineColor(8);
	tt_dphi_loose_50_100->SetFillColor(8);
	tt_dphi_loose_100_150->SetLineColor(9);
	tt_dphi_loose_100_150->SetFillColor(9);

	tt_dphi_loose_150_225->SetLineColor(46);
	tt_dphi_loose_150_225->SetFillColor(46);
	tt_dphi_loose_225_300->SetLineColor(8);
	tt_dphi_loose_225_300->SetFillColor(8);
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

	z_dphi_loose_0_50->SetLineColor(46);
	z_dphi_loose_0_50->SetFillColor(46);
	z_dphi_loose_50_100->SetLineColor(8);
	z_dphi_loose_50_100->SetFillColor(8);
	z_dphi_loose_100_150->SetLineColor(9);
	z_dphi_loose_100_150->SetFillColor(9);

	z_dphi_loose_150_225->SetLineColor(46);
	z_dphi_loose_150_225->SetFillColor(46);
	z_dphi_loose_225_300->SetLineColor(8);
	z_dphi_loose_225_300->SetFillColor(8);
	z_dphi_loose_300->SetLineColor(9);
	z_dphi_loose_300->SetFillColor(9);

	TH1D * z_met = (TH1D*) ((TH1D*) z_file->Get("zjets_type1MET_widebin"))->Clone("z_met");
	TH1D * tt_met = (TH1D*) ((TH1D*) tt_file->Get("ttbar_type1MET_widebin"))->Clone("tt_met");

	z_met->SetLineColor(kRed);
	z_met->SetLineWidth(6);
	tt_met->SetLineColor(kBlue);
	tt_met->SetLineWidth(6);

	//Lepton/MET plots

	TH1D * tt_leading_lepmet = (TH1D*) ((TH1D*) tt_file->Get("ttbar_DeltaPhi_leading_lep_met"))->Clone("tt_leading_lepmet");
	TH1D * tt_subleading_lepmet = (TH1D*) ((TH1D*) tt_file->Get("ttbar_DeltaPhi_subleading_lep_met"))->Clone("tt_subleading_lepmet");
	TH1D * z_leading_lepmet = (TH1D*) ((TH1D*) z_file->Get("zjets_DeltaPhi_leading_lep_met"))->Clone("z_leading_lepmet");
	TH1D * z_subleading_lepmet = (TH1D*) ((TH1D*) z_file->Get("zjets_DeltaPhi_subleading_lep_met"))->Clone("z_subleading_lepmet");

	tt_leading_lepmet->SetLineColor(46);
	tt_leading_lepmet->SetFillColor(46);
	tt_subleading_lepmet->SetLineColor(9);
	tt_subleading_lepmet->SetFillColor(9);

	z_leading_lepmet->SetLineColor(46);
	z_leading_lepmet->SetFillColor(46);
	z_subleading_lepmet->SetLineColor(9);
	z_subleading_lepmet->SetFillColor(9);
//===============================
//Draw Plots
//===============================
	//------------------
	// MET Distributions
	//------------------

	TCanvas * met = new TCanvas("canvas_met", "", 2000, 2000);

	gPad->SetLogy(1);
	gStyle->SetOptStat(kFALSE);

	TLegend *l1;
	l1 = new TLegend(0.73, 0.73, 0.88, 0.88);
	  
	l1->SetLineColor(kWhite);  
	l1->SetShadowColor(kWhite);
	l1->SetFillColor(kWhite);
	l1->AddEntry(z_met, "DY MC", "f");
	l1->AddEntry(tt_met, "TTBar MC", "f");
	  
	
	z_met->Draw("HIST");
	tt_met->Draw("HIST SAME");
	l1->Draw("same");
	
	met->SaveAs(output_dir+"met.png");

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
	ctt_lowMET->SaveAs(output_dir+"tt_lowMet_dPhi.png");

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

	ctt_HighMET->SaveAs(output_dir+"tt_HighMET_dPhi.png");

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
	cz_lowMET->SaveAs(output_dir+"z_lowMET_dPhi.png");

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
	cz_HighMET->SaveAs(output_dir+"z_HighMET_dPhi.png");

	//cout<<__LINE__<<endl;


	//------------------
	// DPhi Lep/MET
	//------------------

	TCanvas *c_z_lepmet = new TCanvas("c_z_lepmet", "", 2000, 2000);
	c_z_lepmet->Divide(1,2);


	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	c_z_lepmet->cd(1);
	z_leading_lepmet->SetTitle("#Delta#Phi(E^{miss}_{T}, leading lepton) for Z Events");
	z_leading_lepmet->Draw("HIST");
	c_z_lepmet->cd(2);
	z_subleading_lepmet->SetTitle("#Delta#Phi(E^{miss}_{T}, leading lepton) for Z Events");
	z_subleading_lepmet->Draw("HIST");


	c_z_lepmet->cd();
	c_z_lepmet->SaveAs(output_dir+"z_lepmet_met50.png");

	TCanvas *c_tt_lepmet = new TCanvas("c_tt_lepmet", "", 2000, 2000);
	c_tt_lepmet->Divide(1,2);


	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	c_tt_lepmet->cd(1);
	tt_leading_lepmet->SetTitle("#Delta#Phi(E^{miss}_{T}, leading lepton) for T#bar{T} Events");
	tt_leading_lepmet->Draw("HIST");

	c_tt_lepmet->cd(2);
	tt_leading_lepmet->SetTitle("#Delta#Phi(E^{miss}_{T}, subleading lepton) for T#bar{T} Events");
	tt_subleading_lepmet->Draw("HIST");


	c_tt_lepmet->cd();
	c_tt_lepmet->SaveAs(output_dir+"tt_lepmet_met50.png");

//==============
// HT Checking
//==============

	TCanvas *c_Ht_check = new TCanvas("c_Ht_check", "", 2000, 2000);

	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	TH1D * z_genht = (TH1D*) ((TH1D*) z_file->Get("zjets_genht"))->Clone("z_genht");
	TH1D * z_ht = (TH1D*) ((TH1D*) z_file->Get("zjets_ht"))->Clone("z_ht");

	//cout<<__LINE__<<endl;


	z_ht->SetLineColor(9);
	z_ht->SetLineWidth(6);
	z_ht->SetTitle("Gen Level H_{T} Vs. Measured H_{T} for Z Events");
	z_ht->SetAxisRange(0,1000);
	z_ht->Draw("HIST");

	z_genht->SetLineColor(46);
	z_genht->SetLineWidth(6);
	z_genht->Draw("HIST SAME");
	
	TLegend *l_ht;
	l_ht = new TLegend(0.73, 0.73, 0.88, 0.88);
	  
	l_ht->SetLineColor(kWhite);  
	l_ht->SetShadowColor(kWhite);
	l_ht->SetFillColor(kWhite);
	l_ht->AddEntry(z_genht, "Gen Level H_{T}", "f");
	l_ht->AddEntry(z_ht, "Measured H_{T}", "f");
	  
	l_ht->Draw("same");

	//Delta HT

	c_Ht_check->cd();
	c_Ht_check->SaveAs(output_dir+"Ht_check.png");

	TCanvas *c_Dht = new TCanvas("c_Dht", "", 2000, 2000);

	c_Dht->Divide(1,2);
	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	TH1D * z_dht_lowphi = (TH1D*) ((TH1D*) z_file->Get("zjets_Dht_lowphi"))->Clone("z_dht_lowphi");
	TH1D * z_dht_highphi = (TH1D*) ((TH1D*) z_file->Get("zjets_Dht_highphi"))->Clone("z_dht_highphi");

	//cout<<__LINE__<<endl;

	c_Dht->cd(1);
	z_dht_lowphi->SetLineColor(9);
	z_dht_lowphi->SetFillColor(9);
	z_dht_lowphi->SetTitle("Gen Level H_{T} - Measured H_{T} for Z Events with #Delta#Phi(E^{miss}_{T}, dilepton) #leq 1");
	z_dht_lowphi->SetAxisRange(-300,300);
	z_dht_lowphi->Draw("HIST");

	c_Dht->cd(2);
	z_dht_highphi->SetLineColor(46);
	z_dht_highphi->SetFillColor(46);
	z_dht_highphi->SetTitle("Gen Level H_{T} - Measured H_{T} for Z Events with #Delta#Phi(E^{miss}_{T}, dilepton) #geq 2");
	z_dht_highphi->SetAxisRange(-300,300);
	z_dht_highphi->Draw("HIST");


	c_Dht->cd();
	c_Dht->SaveAs(output_dir+"Z_Dht.png");



met->~TCanvas();
cz_lowMET->~TCanvas();
cz_HighMET->~TCanvas();
ctt_lowMET->~TCanvas();
ctt_HighMET->~TCanvas();

c_tt_lepmet->~TCanvas();
c_z_lepmet->~TCanvas();

c_Ht_check->~TCanvas();
c_Dht->~TCanvas();

}

