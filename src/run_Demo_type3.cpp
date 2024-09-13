/*******************************************************************************
 2HDMC - two-Higgs-doublet model calculator
 Demo program
 
 http://2hdmc.hepforge.org
*******************************************************************************/
#include "THDM.h"
#include "SM.h"
#include "Constraints.h"
#include "DecayTable.h"
#include <iostream>

/*
#include <TSystem.h>
#include <TROOT.h>
#include <TFile.h>
#include <TH1D.h>
#include <TF1.h>
#include "TCanvas.h"
#include "TStyle.h"
//#include "/Users/nsonmez/root/macros/tdrStyle.C"
#include <string>
*/

using namespace std;

int main(int argc, char* argv[]) 
{


	/*
	string outputFileName = "jet_run2010b_174347_v2.root";
	TFile *outf = new TFile(outputFileName.c_str(),"RECREATE");
	TH1F * h_mass70 = new TH1F("h_mass70","Width of H+ distr.",100,0,10);
	char h_name[100];
	char h_title[100];
	
	TH1F * h_mass[7];	
	
	for (int i=0;i<7; i++)
	{
		sprintf( h_name, "h_name_%i", HCMass[i]);
		sprintf( h_title, "Width of H+ distribution for mass(H+) %i GeV", HCMass[i]);
		h_mass[i] = new TH1F(h_name, h_title, 100,0,10 );
	}
	*/
	
  // Reference SM Higgs mass for EW precision observables
  double mh_ref = 125.;

  // Create SM and set parameters
  SM sm;
  sm.set_qmass_pole(6, 172.5);		
  sm.set_qmass_pole(5, 4.75);		
  sm.set_qmass_pole(4, 1.42);	
  sm.set_lmass_pole(3, 1.77684);	
  sm.set_alpha(1./127.934);
  sm.set_alpha0(1./137.0359997);
  sm.set_alpha_s(0.119);
  sm.set_MZ(91.15349);
  sm.set_MW(80.36951);
  sm.set_gamma_Z(2.49581);
  sm.set_gamma_W(2.08856);
  sm.set_GF(1.16637E-5);

  // Create 2HDM and set SM parameters
  THDM model;
  model.set_SM(sm);
	    
  // Set parameters of the 2HDM in the 'physical' basis
  double mh       = 125.;
  double mH       = 400.;
  double mA       = 400.;
  double mC       = 80;
  double sba      = 0.999;
  double lambda_6 = 0.;
  double lambda_7 = 0.;
  double m12_2    = 15800.; 
  double tb       = 2.0;

  double lamda1       = 1;
  double lamda2       = 1;
  double lamda3       = 1;
  double lamda4       = 0;
  double lamda5       = 0;
  double lamda6       = 0;
  double lamda7       = 0;
  double masshp       = 300;
  
  int HCMass[7]={80,85,90,100,110,120,130};


	//cout.width(5);
 
	char h_name[100];
	
	for(int j =0; j<7; j++)
	{

		mC=HCMass[j];
		bool pset = model.set_param_phys(mh,mH,mA,mC,sba,lambda_6,lambda_7,m12_2,tb);
		//bool pset = model.set_param_higgs(lamda1,lamda2,lamda3,lamda4,lamda5,lamda6,lamda7,);
  
		if (!pset) {
			cerr << "The specified parameters are not valid\n";
			return -1;
		}

		// Set Yukawa couplings to type II
		model.set_yukawas_type(3);

		// Print the parameters in different parametrizations
		//model.print_param_phys();
		//model.print_param_gen();
		//model.print_param_higgs();
		//model.print_param_H2();
		// Prepare to calculate observables
		//Constraints constr(model);

		//double S,T,U,V,W,X;
		//constr.oblique_param(mh_ref,S,T,U,V,W,X);
		// Prepare to calculate decay widths
		DecayTable table(model);

		// Print total widths of Higgs bosons
		//table.print_width(1);
		//table.print_width(2);
		//table.print_width(4);

		//table.print_top_decays();
  
		//table.print_decays(1);  
		//table.print_decays(2);
		//table.print_decays(3);
		//table.print_decays(4);
  
		// Write output to LesHouches file
		sprintf( h_name, "param_card_typ3_mHc%.0f_tb%.0f.lha", mC, tb);
		model.write_LesHouches(h_name, true, true, false);
	}
}

