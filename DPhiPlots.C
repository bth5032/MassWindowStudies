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
	else if (files.Contains("monojet")){
		dir_loc = "/nfs-7/userdata/bobak/DPhiStudiesV2/monojet/";
		output_dir = "/home/users/bhashemi/public_html/DPhiStudiesV2/monojet/";	
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

	z_leading_lepmet->SetLineColor(9);
	z_leading_lepmet->SetFillColor(9);
	z_subleading_lepmet->SetLineColor(46);
	z_subleading_lepmet->SetFillColor(46);

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
	z_subleading_lepmet->SetTitle("#Delta#Phi(E^{miss}_{T}, subleading lepton) for Z Events");
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

//------------------
// DPhi Lep/MET ee/mm
//------------------

	TH1D * z_leading_lepmet_ee = (TH1D*) ((TH1D*) z_file->Get("zjets_DeltaPhi_leading_lep_met_ee"))->Clone("z_leading_lepmet_ee");
	TH1D * z_subleading_lepmet_ee = (TH1D*) ((TH1D*) z_file->Get("zjets_DeltaPhi_subleading_lep_met_ee"))->Clone("z_subleading_lepmet_ee");


	TCanvas *c_z_lepmet_ee = new TCanvas("c_z_lepmet_ee", "", 2000, 2000);
	c_z_lepmet_ee->Divide(1,2);


	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	c_z_lepmet_ee->cd(1);
	z_leading_lepmet_ee->SetLineColor(9);
	z_leading_lepmet_ee->SetFillColor(9);
	//z_leading_lepmet_ee->SetLineWidth(6);
	z_leading_lepmet_ee->SetTitle("#Delta#Phi(E^{miss}_{T}, leading lepton) for Z #rightarrow e #bar{e} Events");
	z_leading_lepmet_ee->Draw("HIST");
	c_z_lepmet_ee->cd(2);
	z_subleading_lepmet_ee->SetLineColor(46);
	z_subleading_lepmet_ee->SetFillColor(46);
	//z_subleading_lepmet_ee->SetLineWidth(6);
	z_subleading_lepmet_ee->SetTitle("#Delta#Phi(E^{miss}_{T}, subleading lepton) for Z #rightarrow e #bar{e} Events");
	z_subleading_lepmet_ee->Draw("HIST");

	c_z_lepmet_ee->cd();
	c_z_lepmet_ee->SaveAs(output_dir+"z_lepmet_met50_ee.png");
	
	//------------
	//Mu Mu
	//------------
	
	TH1D * z_leading_lepmet_mm = (TH1D*) ((TH1D*) z_file->Get("zjets_DeltaPhi_leading_lep_met_mm"))->Clone("z_leading_lepmet_mm");
	TH1D * z_subleading_lepmet_mm = (TH1D*) ((TH1D*) z_file->Get("zjets_DeltaPhi_subleading_lep_met_mm"))->Clone("z_subleading_lepmet_mm");

	TCanvas *c_z_lepmet_mm = new TCanvas("c_z_lepmet_mm", "", 2000, 2000);
	c_z_lepmet_mm->Divide(1,2);


	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	c_z_lepmet_mm->cd(1);
	z_leading_lepmet_mm->SetLineColor(9);
	z_leading_lepmet_mm->SetFillColor(9);
	//z_leading_lepmet_mm->SetLineWidth(6);
	z_leading_lepmet_mm->SetTitle("#Delta#Phi(E^{miss}_{T}, leading lepton) for Z #rightarrow #mu #bar{#mu} Events");
	z_leading_lepmet_mm->Draw("HIST");

	c_z_lepmet_mm->cd(2);
	z_subleading_lepmet_mm->SetLineColor(46);
	z_subleading_lepmet_mm->SetFillColor(46);
	//z_subleading_lepmet_mm->SetLineWidth(6);
	z_subleading_lepmet_mm->SetTitle("#Delta#Phi(E^{miss}_{T}, subleading lepton) for Z #rightarrow #mu #bar{#mu} Events");
	z_subleading_lepmet_mm->Draw("HIST");


	c_z_lepmet_mm->cd();
	c_z_lepmet_mm->SaveAs(output_dir+"z_lepmet_met50_mm.png");

//------------------
// HT Checking
//------------------

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

	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	TH1D * z_dht_lowphi = (TH1D*) ((TH1D*) z_file->Get("zjets_Dht_lowphi"))->Clone("z_dht_lowphi");
	TH1D * z_dht_highphi = (TH1D*) ((TH1D*) z_file->Get("zjets_Dht_highphi"))->Clone("z_dht_highphi");

	//cout<<__LINE__<<endl;

	z_dht_highphi->Scale(1/z_dht_highphi->Integral());
	z_dht_lowphi->Scale(1/z_dht_lowphi->Integral());

	z_dht_lowphi->SetLineColor(9);
	z_dht_lowphi->SetLineWidth(6);
	z_dht_lowphi->SetTitle("Percent Gen H_{T} reconstructed for Z Events with #Delta#Phi(E^{miss}_{T}, dilepton)");
	z_dht_lowphi->SetXTitle("(Gen H_{T} - Reco H_{T})/Gen H_{T}");
	//z_dht_lowphi->SetYTitle("Events");
	z_dht_lowphi->SetAxisRange(-1,1);
	z_dht_lowphi->Draw("HIST");

	z_dht_highphi->SetLineColor(46);
	z_dht_highphi->SetLineWidth(6);
	//z_dht_highphi->SetYTitle("Events");
	z_dht_highphi->SetTitle("Percent Gen H_{T} reconstructed for Z Events with #Delta#Phi(E^{miss}_{T}, dilepton)");
	z_dht_highphi->SetAxisRange(-1,1);
	z_dht_highphi->Draw("HIST SAME");

	TLegend *l_Dht;
	l_Dht = new TLegend(0.73, 0.73, 0.88, 0.88);
	  
	l_Dht->SetLineColor(kWhite);  
	l_Dht->SetShadowColor(kWhite);
	l_Dht->SetFillColor(kWhite);
	l_Dht->AddEntry(z_dht_lowphi, "#Delta#Phi(E^{miss}_{T}, dilepton) #leq 1", "f");
	l_Dht->AddEntry(z_dht_highphi, "#Delta#Phi(E^{miss}_{T}, dilepton) #geq 2", "f");
	  
	l_Dht->Draw("same");

	c_Dht->cd();
	c_Dht->SaveAs(output_dir+"Z_Dht_met50.png");

	TCanvas *c_Dht_unscaled = new TCanvas("c_Dht_unscaled", "", 2000, 2000);

	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	TH1D * z_dht_lowphi_unscaled = (TH1D*) ((TH1D*) z_file->Get("zjets_Dht_lowphi_unscaled"))->Clone("z_dht_lowphi_unscaled");
	TH1D * z_dht_highphi_unscaled = (TH1D*) ((TH1D*) z_file->Get("zjets_Dht_highphi_unscaled"))->Clone("z_dht_highphi_unscaled");

	//cout<<__LINE__<<endl;

	z_dht_highphi_unscaled->Scale(1/z_dht_highphi_unscaled->Integral());
	z_dht_lowphi_unscaled->Scale(1/z_dht_lowphi_unscaled->Integral());

	z_dht_lowphi_unscaled->SetLineColor(9);
	z_dht_lowphi_unscaled->SetLineWidth(6);
	z_dht_lowphi_unscaled->SetTitle("Percent Gen H_{T} reconstructed for Z Events with #Delta#Phi(E^{miss}_{T}, dilepton)");
	z_dht_lowphi_unscaled->SetXTitle("(Gen H_{T} - Reco H_{T})");
	//z_dht_lowphi->SetYTitle("Events");
	z_dht_lowphi_unscaled->SetAxisRange(-300,300);
	z_dht_lowphi_unscaled->Draw("HIST");

	z_dht_highphi_unscaled->SetLineColor(46);
	z_dht_highphi_unscaled->SetLineWidth(6);
	//z_dht_highphi->SetYTitle("Events");
	z_dht_highphi_unscaled->SetTitle("Percent Gen H_{T} reconstructed for Z Events with #Delta#Phi(E^{miss}_{T}, dilepton)");
	z_dht_highphi_unscaled->SetAxisRange(-300,300);
	z_dht_highphi_unscaled->Draw("HIST SAME");

	TLegend *l_Dht_unscaled;
	l_Dht_unscaled = new TLegend(0.73, 0.73, 0.88, 0.88);
	  
	l_Dht_unscaled->SetLineColor(kWhite);  
	l_Dht_unscaled->SetShadowColor(kWhite);
	l_Dht_unscaled->SetFillColor(kWhite);
	l_Dht_unscaled->AddEntry(z_dht_lowphi_unscaled, "#Delta#Phi(E^{miss}_{T}, dilepton) #leq 1", "f");
	l_Dht_unscaled->AddEntry(z_dht_highphi_unscaled, "#Delta#Phi(E^{miss}_{T}, dilepton) #geq 2", "f");
	  
	l_Dht_unscaled->Draw("same");

	c_Dht_unscaled->cd();
	c_Dht_unscaled->SaveAs(output_dir+"Z_Dht_met50_unscaled.png");

//------------------
// nVert Check
//------------------

	TCanvas *c_nvert_check = new TCanvas("c_nvert_check", "", 2000, 2000);

	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	TH1D * z_nvert_highphi = (TH1D*) ((TH1D*) z_file->Get("zjets_nVert_highphi"))->Clone("zjets_nVert_highphi");
	TH1D * z_nvert_lowphi = (TH1D*) ((TH1D*) z_file->Get("zjets_nVert_lowphi"))->Clone("zjets_nVert_lowphi");

	z_nvert_highphi->Scale(1/z_nvert_highphi->Integral());
	z_nvert_lowphi->Scale(1/z_nvert_lowphi->Integral());

	//cout<<__LINE__<<endl;


	z_nvert_lowphi->SetLineColor(9);
	z_nvert_lowphi->SetLineWidth(6);
	z_nvert_lowphi->SetTitle("Number of Vertcies in Head and Tail of #Delta#Phi(E^{miss}_{T}, dilepton)");
	z_nvert_lowphi->SetXTitle("Number of Vertcies");
	z_nvert_lowphi->SetYTitle("Count");
	z_nvert_lowphi->SetAxisRange(0,50);
	z_nvert_lowphi->Draw("HIST");

	z_nvert_highphi->SetLineColor(46);
	z_nvert_highphi->SetLineWidth(6);
	z_nvert_highphi->Draw("HIST SAME");
	
	TLegend *l_nvert;
	l_nvert = new TLegend(0.73, 0.73, 0.88, 0.88);
	  
	l_nvert->SetLineColor(kWhite);  
	l_nvert->SetShadowColor(kWhite);
	l_nvert->SetFillColor(kWhite);
	l_nvert->AddEntry(z_nvert_highphi, "#Delta#Phi(E^{miss}_{T}, dilepton) #geq 2", "f");
	l_nvert->AddEntry(z_nvert_lowphi, "#Delta#Phi(E^{miss}_{T}, dilepton) #leq 1", "f");
	  
	l_nvert->Draw("same");

	//Delta HT

	c_nvert_check->cd();
	c_nvert_check->SaveAs(output_dir+"nvert.png");

//------------------
// njets Check
//------------------

	TCanvas *c_njets_check = new TCanvas("c_njets_check", "", 2000, 2000);

	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	TH1D * z_njets_highphi = (TH1D*) ((TH1D*) z_file->Get("zjets_njets_highphi"))->Clone("z_njets_highphi");
	TH1D * z_njets_lowphi = (TH1D*) ((TH1D*) z_file->Get("zjets_njets_lowphi"))->Clone("z_njets_lowphi");

	z_njets_highphi->Scale(1/z_njets_highphi->Integral());
	z_njets_lowphi->Scale(1/z_njets_lowphi->Integral());

	//cout<<__LINE__<<endl;


	z_njets_lowphi->SetLineColor(9);
	z_njets_lowphi->SetLineWidth(6);
	z_njets_lowphi->SetTitle("Number of Vertcies in Head and Tail of #Delta#Phi(E^{miss}_{T}, dilepton)");
	z_njets_lowphi->SetXTitle("Number of Jets");
	z_njets_lowphi->SetYTitle("Count");
	z_njets_lowphi->SetAxisRange(0,7);
	z_njets_lowphi->Draw("HIST");

	z_njets_highphi->SetLineColor(46);
	z_njets_highphi->SetLineWidth(6);
	z_njets_highphi->Draw("HIST SAME");
	
	TLegend *l_njets;
	l_njets = new TLegend(0.73, 0.73, 0.88, 0.88);
	  
	l_njets->SetLineColor(kWhite);  
	l_njets->SetShadowColor(kWhite);
	l_njets->SetFillColor(kWhite);
	l_njets->AddEntry(z_njets_highphi, "#Delta#Phi(E^{miss}_{T}, dilepton) #geq 2", "f");
	l_njets->AddEntry(z_njets_lowphi, "#Delta#Phi(E^{miss}_{T}, dilepton) #leq 1", "f");
	  
	l_njets->Draw("same");

	//Delta HT

	c_njets_check->cd();
	c_njets_check->SaveAs(output_dir+"njets.png");

//------------------
// Δ(HT,MET) Checking
//------------------

	TCanvas *c_D_Ht_MET = new TCanvas("c_D_Ht_MET", "", 2000, 2000);

	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	TH1D * z_dht_MET_lowphi = (TH1D*) ((TH1D*) z_file->Get("zjets_Dht_MET_lowphi"))->Clone("z_dht_MET_lowphi");
	TH1D * z_dht_MET_highphi = (TH1D*) ((TH1D*) z_file->Get("zjets_Dht_MET_highphi"))->Clone("z_dht_MET_highphi");

	//cout<<__LINE__<<endl;

	if (z_dht_MET_lowphi->GetMaximum() < z_dht_MET_highphi->GetMaximum()){
		z_dht_MET_lowphi->SetMaximum(z_dht_MET_highphi->GetMaximum());
	}

	z_dht_MET_lowphi->SetLineColor(9);
	z_dht_MET_lowphi->SetLineWidth(6);
	z_dht_MET_lowphi->SetTitle("Gen Level H_{T} - Measured H_{T} #pm E^{miss}_{T} for Z Events");
	z_dht_MET_lowphi->Draw("HIST");

	z_dht_MET_highphi->SetLineColor(46);
	z_dht_MET_highphi->SetLineWidth(6);
	z_dht_MET_highphi->Draw("HIST SAME");
	
	TLegend *l_Dht_MET;
	l_Dht_MET = new TLegend(0.73, 0.73, 0.88, 0.88);
	  
	l_Dht_MET->SetLineColor(kWhite);  
	l_Dht_MET->SetShadowColor(kWhite);
	l_Dht_MET->SetFillColor(kWhite);
	l_Dht_MET->AddEntry(z_dht_MET_lowphi, "Z aligned with E^{miss}_{T}", "f");
	l_Dht_MET->AddEntry(z_dht_MET_highphi, "Z anti-aligned with E^{miss}_{T}", "f");
	  
	l_Dht_MET->Draw("same");

	//Delta HT

	c_D_Ht_MET->cd();
	c_D_Ht_MET->SaveAs(output_dir+"D_HT_MET.png");

	met->~TCanvas();
	cz_lowMET->~TCanvas();
	cz_HighMET->~TCanvas();
	ctt_lowMET->~TCanvas();
	ctt_HighMET->~TCanvas();

	c_tt_lepmet->~TCanvas();
	c_z_lepmet->~TCanvas();

	c_z_lepmet_ee->~TCanvas();
	c_z_lepmet_mm->~TCanvas();

	c_Ht_check->~TCanvas();
	c_Dht->~TCanvas();

	c_nvert_check->~TCanvas();
	c_njets_check->~TCanvas();

}

