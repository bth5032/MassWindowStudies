#include "TString.h"
#include <vector>

void processSample(TString sample){
	TString dir_loc = "/nfs-7/userdata/bobak/MassWindowStudies/";

//=================
// Define Files
//=================

	vector<TFile*> files;
	if (sample == "edge"){
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_Base_EdgeZ.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_med_EdgeZ.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_tight_EdgeZ.root"), "READ"));

		files.push_back(TFile::Open(dir_loc+TString("ct_Z_Base_EdgeZ.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_Z_med_EdgeZ.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_Z_tight_EdgeZ.root"), "READ"));
	}
	else if (sample=="A_Btag"){
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_Base_A_btag.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_med_A_btag.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_tight_A_btag.root"), "READ"));

		files.push_back(TFile::Open(dir_loc+TString("ct_Z_Base_A_btag.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_Z_med_A_btag.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_Z_tight_A_btag.root"), "READ"));
	}
	else if (sample=="A_Bveto"){
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_Base_A_bveto.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_med_A_bveto.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_tight_A_bveto.root"), "READ"));

		files.push_back(TFile::Open(dir_loc+TString("ct_Z_Base_A_bveto.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_Z_med_A_bveto.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_Z_tight_A_bveto.root"), "READ"));
	}
	else if (sample=="B_Btag"){
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_Base_B_btag.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_med_B_btag.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_tight_B_btag.root"), "READ"));

		files.push_back(TFile::Open(dir_loc+TString("ct_Z_Base_B_btag.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_Z_med_B_btag.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_Z_tight_B_btag.root"), "READ"));
	}
	else if (sample=="B_Bveto"){
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_Base_B_bveto.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_med_B_bveto.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_tight_B_bveto.root"), "READ"));

		files.push_back(TFile::Open(dir_loc+TString("ct_Z_Base_B_bveto.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_Z_med_B_bveto.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_Z_tight_B_bveto.root"), "READ"));
	}
	else if (sample=="ATLAS"){
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_Base_ATLAS.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_med_ATLAS.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_TT_tight_ATLAS.root"), "READ"));

		files.push_back(TFile::Open(dir_loc+TString("ct_Z_Base_ATLAS.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_Z_med_ATLAS.root"), "READ"));
		files.push_back(TFile::Open(dir_loc+TString("ct_Z_tight_ATLAS.root"), "READ"));
	}
	else{
		cout<<"Unrecognized sample: "<<sample<<endl;
		exit(1);
	}

	
	//cout<<__LINE__<<endl;

//===========================
// Get histograms from file:
//===========================

	//TTBar MET Plots
	TH1D * tt_met_loose = (TH1D*) ((TH1D*) files[0]->Get("TT_Base_type1MET_widebin"))->Clone("tt_met_loose");
	TH1D * tt_met_med = (TH1D*) ((TH1D*) files[1]->Get("TT_med_type1MET_widebin"))->Clone("tt_met_med");
	TH1D * tt_met_tight = (TH1D*) ((TH1D*) files[2]->Get("TT_tight_type1MET_widebin"))->Clone("tt_met_tight");

	//cout<<__LINE__<<endl;

	tt_met_tight->SetLineColor(kBlue);
	tt_met_med->SetLineColor(kBlue);
	tt_met_loose->SetLineColor(kBlue);

	
	//TTBar dPHI Plots
	TH1D * tt_dphi_loose_150_200 = (TH1D*) ((TH1D*) files[0]->Get("TT_Base_DeltaPhi_lep_met_150_200"))->Clone("tt_dphi_loose_150_200");
	TH1D * tt_dphi_loose_200_300 = (TH1D*) ((TH1D*) files[0]->Get("TT_Base_DeltaPhi_lep_met_200_300"))->Clone("tt_dphi_loose_200_300");
	TH1D * tt_dphi_loose_300 = (TH1D*) ((TH1D*) files[0]->Get("TT_Base_DeltaPhi_lep_met_300"))->Clone("tt_dphi_loose_300");

	//cout<<__LINE__<<endl;

	TH1D * tt_dphi_med_150_200 = (TH1D*) ((TH1D*) files[1]->Get("TT_med_DeltaPhi_lep_met_150_200"))->Clone("tt_dphi_med_150_200");
	TH1D * tt_dphi_med_200_300 = (TH1D*) ((TH1D*) files[1]->Get("TT_med_DeltaPhi_lep_met_200_300"))->Clone("tt_dphi_med_200_300");
	TH1D * tt_dphi_med_300 = (TH1D*) ((TH1D*) files[1]->Get("TT_med_DeltaPhi_lep_met_300"))->Clone("tt_dphi_med_300");

	//cout<<__LINE__<<endl;

	TH1D * tt_dphi_tight_150_200 = (TH1D*) ((TH1D*) files[2]->Get("TT_tight_DeltaPhi_lep_met_150_200"))->Clone("tt_dphi_tight_150_200");
	TH1D * tt_dphi_tight_200_300 = (TH1D*) ((TH1D*) files[2]->Get("TT_tight_DeltaPhi_lep_met_200_300"))->Clone("tt_dphi_tight_200_300");
	TH1D * tt_dphi_tight_300 = (TH1D*) ((TH1D*) files[2]->Get("TT_tight_DeltaPhi_lep_met_300"))->Clone("tt_dphi_tight_300");

	//cout<<__LINE__<<endl;

	tt_dphi_loose_150_200->SetLineColor(46);
	tt_dphi_loose_150_200->SetFillColor(46);
	tt_dphi_loose_200_300->SetLineColor(8);
	tt_dphi_loose_200_300->SetFillColor(8);
	tt_dphi_loose_300->SetLineColor(9);
	tt_dphi_loose_300->SetFillColor(9);

	tt_dphi_med_150_200->SetLineColor(46);
	tt_dphi_med_200_300->SetLineColor(8);
	tt_dphi_med_300->SetLineColor(9);

	tt_dphi_tight_150_200->SetLineColor(46);
	tt_dphi_tight_200_300->SetLineColor(8);
	tt_dphi_tight_300->SetLineColor(9);

	//cout<<__LINE__<<endl;

	// Z MET Plots
	TH1D * z_met_loose = (TH1D*) ((TH1D*) files[3]->Get("zjets_type1MET_widebin"))->Clone("z_met_loose");
	TH1D * z_met_med = (TH1D*) ((TH1D*) files[4]->Get("zjets_type1MET_widebin"))->Clone("z_met_med");
	TH1D * z_met_tight = (TH1D*) ((TH1D*) files[5]->Get("zjets_type1MET_widebin"))->Clone("z_met_tight");

	z_met_tight->SetLineColor(kRed);
	z_met_med->SetLineColor(kRed);
	z_met_loose->SetLineColor(kRed);

	//cout<<__LINE__<<endl;

	// Z dPHI Plots
	TH1D * z_dphi_loose_150_200 = (TH1D*) ((TH1D*) files[3]->Get("zjets_DeltaPhi_lep_met_150_200"))->Clone("z_dphi_loose_150_200");
	TH1D * z_dphi_loose_200_300 = (TH1D*) ((TH1D*) files[3]->Get("zjets_DeltaPhi_lep_met_200_300"))->Clone("z_dphi_loose_200_300");
	TH1D * z_dphi_loose_300 = (TH1D*) ((TH1D*) files[3]->Get("zjets_DeltaPhi_lep_met_300"))->Clone("z_dphi_loose_300");

	//cout<<__LINE__<<endl;

	TH1D * z_dphi_med_150_200 = (TH1D*) ((TH1D*) files[4]->Get("zjets_DeltaPhi_lep_met_150_200"))->Clone("z_dphi_med_150_200");
	TH1D * z_dphi_med_200_300 = (TH1D*) ((TH1D*) files[4]->Get("zjets_DeltaPhi_lep_met_200_300"))->Clone("z_dphi_med_200_300");
	TH1D * z_dphi_med_300 = (TH1D*) ((TH1D*) files[4]->Get("zjets_DeltaPhi_lep_met_300"))->Clone("z_dphi_med_300");

	//cout<<__LINE__<<endl;

	TH1D * z_dphi_tight_150_200 = (TH1D*) ((TH1D*) files[5]->Get("zjets_DeltaPhi_lep_met_150_200"))->Clone("z_dphi_tight_150_200");
	TH1D * z_dphi_tight_200_300 = (TH1D*) ((TH1D*) files[5]->Get("zjets_DeltaPhi_lep_met_200_300"))->Clone("z_dphi_tight_200_300");
	TH1D * z_dphi_tight_300 = (TH1D*) ((TH1D*) files[5]->Get("zjets_DeltaPhi_lep_met_300"))->Clone("z_dphi_tight_300");

	//cout<<__LINE__<<endl;

	z_dphi_loose_150_200->SetLineColor(46);
	z_dphi_loose_200_300->SetLineColor(8);
	z_dphi_loose_300->SetLineColor(9);

	z_dphi_med_150_200->SetLineColor(46);
	z_dphi_med_200_300->SetLineColor(8);
	z_dphi_med_300->SetLineColor(9);

	z_dphi_tight_150_200->SetLineColor(46);
	z_dphi_tight_200_300->SetLineColor(8);
	z_dphi_tight_300->SetLineColor(9);

	//cout<<__LINE__<<endl;

	/*z_met_tight->SetMinimum(0);
	z_met_med->SetMinimum(0);
	z_met_loose->SetMinimum(0);*/

	//cout<<__LINE__<<endl;

	TH1D * tt_dilmass_loose = (TH1D*) ((TH1D*) files[0]->Get("TT_Base_dilmass"))->Clone("tt_dilmass_loose");
	TH1D * tt_dilmass_med = (TH1D*) ((TH1D*) files[1]->Get("TT_med_dilmass"))->Clone("tt_dilmass_med");
	TH1D * tt_dilmass_tight = (TH1D*) ((TH1D*) files[2]->Get("TT_tight_dilmass"))->Clone("tt_dilmass_tight");

	//cout<<__LINE__<<endl;

	TH1D * z_dilmass_loose = (TH1D*) ((TH1D*) files[3]->Get("zjets_dilmass"))->Clone("z_dilmass_loose");
	TH1D * z_dilmass_med = (TH1D*) ((TH1D*) files[4]->Get("zjets_dilmass"))->Clone("z_dilmass_med");
	TH1D * z_dilmass_tight = (TH1D*) ((TH1D*) files[5]->Get("zjets_dilmass"))->Clone("z_dilmass_tight");	

	//cout<<__LINE__<<endl;

	z_dilmass_tight->SetLineColor(kRed);
	z_dilmass_med->SetLineColor(kRed);
	z_dilmass_loose->SetLineColor(kRed);

	/*z_dilmass_tight->SetMinimum(0);
	z_dilmass_med->SetMinimum(0);
	z_dilmass_loose->SetMinimum(0);*/

	tt_dilmass_tight->SetLineColor(kBlue);
	tt_dilmass_med->SetLineColor(kBlue);
	tt_dilmass_loose->SetLineColor(kBlue);

	//cout<<__LINE__<<endl;

//===============================
//Draw Loose Plots
//===============================

	//-------------
	//MET
	//-------------
	TCanvas *c1 = new TCanvas("MET_loose", "", 2000, 2000);
	c1->cd();

	//cout<<__LINE__<<endl;

	gPad->SetLogy(1);
	gStyle->SetOptStat(kFALSE);

	z_met_loose->SetTitle("E^{miss}_{T} for 10 GeV Window");
	z_met_loose->Draw("HIST");
	tt_met_loose->Draw("HIST SAME");

	//cout<<__LINE__<<endl;
	
	TLegend *l1;
	l1 = new TLegend(0.73, 0.73, 0.88, 0.88);
	  
	l1->SetLineColor(kWhite);  
	l1->SetShadowColor(kWhite);
	l1->SetFillColor(kWhite);
	l1->AddEntry(z_met_loose, "DY MC", "f");
	l1->AddEntry(tt_met_loose, "TTBar MC", "f");
	  
	l1->Draw("same");

	//cout<<__LINE__<<endl;

	c1->SaveAs("plots/"+sample+"_loose_MET.png");

	//-------------
	//Dilepton Mass
	//-------------

	TCanvas *c2 = new TCanvas("dilmass_loose", "", 2000, 2000);
	c2->cd();

	//cout<<__LINE__<<endl;

	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	z_dilmass_loose->SetTitle("Dilepton Mass for 10 GeV Window");
	z_dilmass_loose->Draw("HIST");
	tt_dilmass_loose->Draw("HIST SAME");

	//cout<<__LINE__<<endl;
	
	TLegend *l2;
	l2 = new TLegend(0.73, 0.73, 0.88, 0.88);
	  
	l2->SetLineColor(kWhite);  
	l2->SetShadowColor(kWhite);
	l2->SetFillColor(kWhite);
	l2->AddEntry(z_dilmass_loose, "DY MC", "f");
	l2->AddEntry(tt_dilmass_loose, "TTBar MC", "f");
	  
	l2->Draw("same");

	//cout<<__LINE__<<endl;

	c2->SaveAs("plots/"+sample+"_loose_dilmass.png");

	//cout<<__LINE__<<endl;

	//------------------
	// Delta Phi TTBar
	//------------------

	TCanvas *ctt_loose_dPhi = new TCanvas("tt_loose_dPhi", "", 2000, 2000);
	ctt_loose_dPhi->cd();

	ctt_loose_dPhi->Divide(1,3);	

	//cout<<__LINE__<<endl;

	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	ctt_loose_dPhi->cd(1);
	tt_dphi_loose_150_200->SetTitle("#Delta#Phi(E^{miss}_{T}, ll) for t#bar{t} events with 10 GeV Mass Window; E^{miss}_{T} #in [150,200)");
	//tt_dphi_loose_150_200->Scale(1/tt_dphi_loose_150_200->Integral());
	tt_dphi_loose_150_200->Draw("HIST");

	ctt_loose_dPhi->cd(2);
	tt_dphi_loose_200_300->SetTitle("#Delta#Phi(E^{miss}_{T}, ll) for t#bar{t} events with 10 GeV Mass Window; E^{miss}_{T} #in [200,300)");
	//tt_dphi_loose_200_300->Scale(1/tt_dphi_loose_200_300->Integral());
	tt_dphi_loose_200_300->Draw("HIST");
	
	ctt_loose_dPhi->cd(3);
	tt_dphi_loose_300->SetTitle("#Delta#Phi(E^{miss}_{T}, ll) for t#bar{t} events with 10 GeV Mass Window; ; E^{miss}_{T} #geq 300");
	//tt_dphi_loose_300->Scale(1/tt_dphi_loose_300->Integral());
	tt_dphi_loose_300->Draw("HIST");

	//cout<<__LINE__<<endl;

	ctt_loose_dPhi->SaveAs("plots/"+sample+"_tt_loose_dPhi.png");

	//cout<<__LINE__<<endl;

	//------------------
	// Delta Phi Z
	//------------------

	TCanvas *cz_loose_dPhi = new TCanvas("z_loose_dPhi", "", 2000, 2000);
	cz_loose_dPhi->cd();

	//cout<<__LINE__<<endl;

	gPad->SetLogy(1);
	gStyle->SetOptStat(kFALSE);

	z_dphi_loose_150_200->SetMinimum(0.001);

	z_dphi_loose_150_200->SetTitle("#Delta#Phi(E^{miss}_{T}, ll) for Zjets events with 10 GeV Mass Window");
	z_dphi_loose_150_200->Draw("HIST");
	z_dphi_loose_200_300->Draw("HIST SAME");
	z_dphi_loose_300->Draw("HIST SAME");

	//cout<<__LINE__<<endl;
	
	TLegend *lz_loose_phi;
	lz_loose_phi = new TLegend(0.73, 0.53, 0.88, 0.58);
	  
	lz_loose_phi->SetLineColor(kWhite);  
	lz_loose_phi->SetShadowColor(kWhite);
	lz_loose_phi->SetFillColor(kWhite);
	lz_loose_phi->AddEntry(z_dphi_loose_150_200, "E^{miss}_{T} #in [150, 200)", "f");
	lz_loose_phi->AddEntry(z_dphi_loose_200_300, "E^{miss}_{T} #in [200,300)", "f");
	lz_loose_phi->AddEntry(z_dphi_loose_300, "E^{miss}_{T} #geq 300", "f");
	  
	lz_loose_phi->Draw("same");

	//cout<<__LINE__<<endl;

	cz_loose_dPhi->SaveAs("plots/"+sample+"_z_loose_dPhi.png");

	//cout<<__LINE__<<endl;

//===============================
//Draw Medium Plots
//===============================

	//-------------
	//MET
	//-------------
	TCanvas *c3 = new TCanvas("MET_med", "", 2000, 2000);
	c3->cd();

	//cout<<__LINE__<<endl;

	gPad->SetLogy(1);
	gStyle->SetOptStat(kFALSE);

	z_met_med->SetTitle("E^{miss}_{T} for 5 GeV Window");
	z_met_med->Draw("HIST");
	tt_met_med->Draw("HIST SAME");

	//cout<<__LINE__<<endl;
	
	TLegend *l3;
	l3 = new TLegend(0.73, 0.73, 0.88, 0.88);
	  
	l3->SetLineColor(kWhite);  
	l3->SetShadowColor(kWhite);
	l3->SetFillColor(kWhite);
	l3->AddEntry(z_met_med, "DY MC", "f");
	l3->AddEntry(tt_met_med, "TTBar MC", "f");
	  
	l3->Draw("same");

	//cout<<__LINE__<<endl;

	c3->SaveAs("plots/"+sample+"_med_MET.png");

	//-------------
	//Dilepton Mass
	//-------------

	TCanvas *c4 = new TCanvas("dilmass_med", "", 2000, 2000);
	c4->cd();

	//cout<<__LINE__<<endl;

	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	z_dilmass_med->SetTitle("Dilepton Mass for 5 GeV Window");
	z_dilmass_med->Draw("HIST");
	tt_dilmass_med->Draw("HIST SAME");

	//cout<<__LINE__<<endl;
	
	TLegend *l4;
	l4 = new TLegend(0.73, 0.73, 0.88, 0.88);
	  
	l4->SetLineColor(kWhite);  
	l4->SetShadowColor(kWhite);
	l4->SetFillColor(kWhite);
	l4->AddEntry(z_dilmass_med, "DY MC", "f");
	l4->AddEntry(tt_dilmass_med, "TTBar MC", "f");
	  
	l1->Draw("same");

	//cout<<__LINE__<<endl;

	c4->SaveAs("plots/"+sample+"_med_dilmass.png");

	//cout<<__LINE__<<endl;

	//-------------
	//TTBar Delta Phi
	//-------------

	TCanvas *ctt_med_dPhi = new TCanvas("tt_med_dPhi", "", 2000, 2000);
	ctt_med_dPhi->cd();

	//cout<<__LINE__<<endl;

	gPad->SetLogy(1);
	gStyle->SetOptStat(kFALSE);

	tt_dphi_med_150_200->SetMinimum(0.001);

	tt_dphi_med_150_200->SetTitle("#Delta#Phi(E^{miss}_{T}, ll) for t#bar{t} events with 10 GeV Mass Window");
	tt_dphi_med_150_200->Draw("HIST");
	tt_dphi_med_200_300->Draw("HIST SAME");
	tt_dphi_med_300->Draw("HIST SAME");

	//cout<<__LINE__<<endl;
	
	TLegend *ltt_med_phi;
	ltt_med_phi = new TLegend(0.73, 0.33, 0.88, 0.38);
	  
	ltt_med_phi->SetLineColor(kWhite);  
	ltt_med_phi->SetShadowColor(kWhite);
	ltt_med_phi->SetFillColor(kWhite);
	ltt_med_phi->AddEntry(tt_dphi_med_150_200, "E^{miss}_{T} #in [150,200)", "f");
	ltt_med_phi->AddEntry(tt_dphi_med_200_300, "E^{miss}_{T} #in [200,300)", "f");
	ltt_med_phi->AddEntry(tt_dphi_med_300, "E^{miss}_{T} #geq 300", "f");
	  
	ltt_med_phi->Draw("same");

	//cout<<__LINE__<<endl;

	ctt_med_dPhi->SaveAs("plots/"+sample+"_tt_med_dPhi.png");

	//cout<<__LINE__<<endl;

	//-------------
	//Z Delta Phi
	//-------------

	TCanvas *cz_med_dPhi = new TCanvas("z_med_dPhi", "", 2000, 2000);
	cz_med_dPhi->cd();

	//cout<<__LINE__<<endl;

	gPad->SetLogy(1);
	gStyle->SetOptStat(kFALSE);

	z_dphi_med_150_200->SetMinimum(0.001);

	z_dphi_med_150_200->SetTitle("#Delta#Phi(E^{miss}_{T}, ll) for Zjets events with 10 GeV Mass Window");
	z_dphi_med_150_200->Draw("HIST");
	z_dphi_med_200_300->Draw("HIST SAME");
	z_dphi_med_300->Draw("HIST SAME");

	//cout<<__LINE__<<endl;
	
	TLegend *lz_med_phi;
	lz_med_phi = new TLegend(0.73, 0.53, 0.88, 0.58);
	  
	lz_med_phi->SetLineColor(kWhite);  
	lz_med_phi->SetShadowColor(kWhite);
	lz_med_phi->SetFillColor(kWhite);
	lz_med_phi->AddEntry(z_dphi_med_150_200, "E^{miss}_{T} #in [150,200)", "f");
	lz_med_phi->AddEntry(z_dphi_med_200_300, "E^{miss}_{T} #in [200,300)", "f");
	lz_med_phi->AddEntry(z_dphi_med_300, "E^{miss}_{T} #geq 300", "f");
	  
	lz_med_phi->Draw("same");

	//cout<<__LINE__<<endl;

	cz_med_dPhi->SaveAs("plots/"+sample+"_z_med_dPhi.png");

	//cout<<__LINE__<<endl;

//===============================
//Draw Tight Plots
//===============================

	//-------------
	//MET
	//-------------

	TCanvas *c5 = new TCanvas("MET_tight", "", 2000, 2000);
	c5->cd();

	//cout<<__LINE__<<endl;

	gPad->SetLogy(1);
	gStyle->SetOptStat(kFALSE);

	z_met_tight->SetTitle("E^{miss}_{T} for 2.5 GeV Window");
	z_met_tight->Draw("HIST");
	tt_met_tight->Draw("HIST SAME");

	//cout<<__LINE__<<endl;
	
	TLegend *l5;
	l5 = new TLegend(0.73, 0.73, 0.88, 0.88);
	  
	l5->SetLineColor(kWhite);  
	l5->SetShadowColor(kWhite);
	l5->SetFillColor(kWhite);
	l5->AddEntry(z_met_tight, "DY MC", "f");
	l5->AddEntry(tt_met_tight, "TTBar MC", "f");
	  
	l5->Draw("same");

	//cout<<__LINE__<<endl;

	c5->SaveAs("plots/"+sample+"_tight_MET.png");

	//-------------
	//Dilepton Mass
	//-------------

	TCanvas *c6 = new TCanvas("dilmass_tight", "", 2000, 2000);
	c6->cd();

	//cout<<__LINE__<<endl;

	gPad->SetLogy(0);
	gStyle->SetOptStat(kFALSE);

	z_dilmass_tight->SetTitle("Dilepton Mass for 2.5 GeV Window");
	z_dilmass_tight->Draw("HIST");
	tt_dilmass_tight->Draw("HIST SAME");

	//cout<<__LINE__<<endl;
	
	TLegend *l6;
	l6 = new TLegend(0.73, 0.73, 0.88, 0.88);
	  
	l6->SetLineColor(kWhite);  
	l6->SetShadowColor(kWhite);
	l6->SetFillColor(kWhite);
	l6->AddEntry(z_dilmass_tight, "DY MC", "f");
	l6->AddEntry(tt_dilmass_tight, "TTBar MC", "f");
	  
	l6->Draw("same");

	//cout<<__LINE__<<endl;

	c6->SaveAs("plots/"+sample+"_tight_dilmass.png");

	//cout<<__LINE__<<endl;

	//-------------
	//TTBar Dilepton Mass
	//-------------

	TCanvas *ctt_tight_dPhi = new TCanvas("tt_tight_dPhi", "", 2000, 2000);
	ctt_tight_dPhi->cd();

	//cout<<__LINE__<<endl;

	gPad->SetLogy(1);
	gStyle->SetOptStat(kFALSE);

	tt_dphi_tight_150_200->SetMinimum(0.001);

	tt_dphi_tight_150_200->SetTitle("#Delta#Phi(E^{miss}_{T}, ll) for t#bar{t} events with 10 GeV Mass Window");
	tt_dphi_tight_150_200->Draw("HIST");
	tt_dphi_tight_200_300->Draw("HIST SAME");
	tt_dphi_tight_300->Draw("HIST SAME");

	//cout<<__LINE__<<endl;
	
	TLegend *ltt_tight_phi;
	ltt_tight_phi = new TLegend(0.73, 0.33, 0.88, 0.38);
	  
	ltt_tight_phi->SetLineColor(kWhite);  
	ltt_tight_phi->SetShadowColor(kWhite);
	ltt_tight_phi->SetFillColor(kWhite);
	ltt_tight_phi->AddEntry(tt_dphi_tight_150_200, "E^{miss}_{T} #in [150, 200)", "f");
	ltt_tight_phi->AddEntry(tt_dphi_tight_200_300, "E^{miss}_{T} #in [200,300)", "f");
	ltt_tight_phi->AddEntry(tt_dphi_tight_300, "E^{miss}_{T} #geq 300", "f");
	  
	ltt_tight_phi->Draw("same");

	//cout<<__LINE__<<endl;

	ctt_tight_dPhi->SaveAs("plots/"+sample+"_tt_tight_dPhi.png");

	//cout<<__LINE__<<endl;

	//-------------
	//Z Dilepton Mass
	//-------------

	TCanvas *cz_tight_dPhi = new TCanvas("z_tight_dPhi", "", 2000, 2000);
	cz_tight_dPhi->cd();

	//cout<<__LINE__<<endl;

	gPad->SetLogy(1);
	gStyle->SetOptStat(kFALSE);

	z_dphi_tight_150_200->SetMinimum(0.001);

	z_dphi_tight_150_200->SetTitle("#Delta#Phi(E^{miss}_{T}, ll) for Zjets events with 10 GeV Mass Window");
	z_dphi_tight_150_200->Draw("HIST");
	z_dphi_tight_200_300->Draw("HIST SAME");
	z_dphi_tight_300->Draw("HIST SAME");

	//cout<<__LINE__<<endl;
	
	TLegend *lz_tight_phi;
	lz_tight_phi = new TLegend(0.73, 0.53, 0.88, 0.58);
	  
	lz_tight_phi->SetLineColor(kWhite);  
	lz_tight_phi->SetShadowColor(kWhite);
	lz_tight_phi->SetFillColor(kWhite);
	lz_tight_phi->AddEntry(z_dphi_tight_150_200, "E^{miss}_{T} #in [150,200)", "f");
	lz_tight_phi->AddEntry(z_dphi_tight_200_300, "E^{miss}_{T} #in [200,300)", "f");
	lz_tight_phi->AddEntry(z_dphi_tight_300, "E^{miss}_{T} #geq 300", "f");
	  
	lz_tight_phi->Draw("same");

	//cout<<__LINE__<<endl;

	cz_tight_dPhi->SaveAs("plots/"+sample+"_z_tight_dPhi.png");

	//cout<<__LINE__<<endl;

}

void DrawPlots(TString sample=""){
	if (sample != ""){
		processSample(sample);
	}
	else{
		processSample("edge");
		processSample("A_Btag");
		processSample("A_Bveto");
		processSample("B_Btag");
		processSample("B_Bveto");
		processSample("ATLAS");
	}
}