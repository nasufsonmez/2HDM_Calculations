/*******************************************************************************
 2HDMC - two-Higgs-doublet model calculator
 Demo program
 
 http://2hdmc.hepforge.org
*******************************************************************************/
#include "THDM.h"
#include "SM.h"
#include "HBHS.h"
#include "Constraints.h"
#include "DecayTable.h"
#include <iostream>
double pi=3.14159265358979323846264338;

using namespace std;

int main(int argc, char* argv[]) {

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
	//NON-align Higgs scenario
/*	  double mh_HYBRID  = 125.;
	  double mH_HYBRID  = 425.;
	  double cba        = 1.0;
	  double Z_4_HYBRID = -2;
	  double Z_5_HYBRID = -2;
	  double Z_7_HYBRID = +0;
	  double tb_HYBRID  = 45;
  */
  /*
//LOW mh mass scenario
  double mh_HYBRID  = 125.;
  double mH_HYBRID  = 425.;
  double cba        = 1.0;
  double Z_4_HYBRID = -2;
  double Z_5_HYBRID = -2;
  double Z_7_HYBRID = +0;
  double tb_HYBRID  = 45;
*/
//flavour scenario
  //double mh=125;
  //double mH=175;
  //double mA=175;
  //double mC=175;
  //double sba= 1;
  //double lambda_6=0;
  //double lambda_7=0;
  //double m12_2=24642.524206250659;
  //double tb=10;

//figure 6a
//    double mh=120;
//    double mH=240;
//    double mA=300;
//    double mC=140;
//    double tb=10;
//    double sa=0.8;
//    double sba= sin(atan(tb)-asin(sa)); 
//    double lambda_6=0;
//    double lambda_7=0;
//    double m12_2=0;

//figure 7
  
 //  double mh=120.0;
//   double mH=370.0;
//   double mA=150.0;
//   double mC=250.0;
//   double tb=5.0;
//   double sa=0.6;
//   double sba= sin(atan(tb)-asin(sa)); 
//   double lambda_6=0.0;
//   double lambda_7=0.0;
//   double m12_2=46*46;


//    double lambda_1=27.6658769;
//    double lambda_2=0.894691509;
//    double lambda_3=31.5895826;
//    double lambda_4=-1.9330947;
//    double lambda_5=-1.9330947;
//    double lambda_6=0;
//    double lambda_7=0;
//    double m12_2=7971.93779;
//    double sba=0.866030000;
//    double tb=20;
/*
  for (int a=1; a<300; a++)
  for (int b=1; b<420; b++)
  {
  
  	m12_2=pow(a*0.5,2);
  	tb=b*0.166666666666;

  	//m12_2=pow(a,2);
  	//tb=b;
  	
  	bool pset = model.set_param_phys(mh,mH,mA,mC,sba,lambda_6,lambda_7,m12_2,tb);
 
  	//bool pset = model.set_param_hybrid( mh_HYBRID, mH_HYBRID, cba, Z_4_HYBRID, Z_5_HYBRID, Z_7_HYBRID, tb_HYBRID);
  
	if (!pset) {
		cerr << "The specified parameters are not valid\n";
		return -1;
	}


  // Set Yukawa couplings to type II
  model.set_yukawas_type(1);
  
  // Print the parameters in different parametrizations
  //model.print_param_phys();
  //model.print_param_gen();
  //model.print_param_higgs();
 // model.print_param_hybrid();

  // Prepare to calculate observables
   Constraints constr(model);
// 
   double S,T,U,V,W,X;   
// 
   constr.oblique_param(mh_ref,S,T,U,V,W,X);
//   
   //printf("\nConstraints:\n");
//    printf("  Potential stability: %s\n", (constr.check_stability() ? "OK" : "Not OK"));
//    printf(" Tree-level unitarity: %s\n", (constr.check_unitarity() ? "OK" : "Not OK"));
//    printf("       Perturbativity: %s\n", (constr.check_perturbativity() ? "OK" : "Not OK"));

	if (	
		    constr.check_stability() 
		&& constr.check_perturbativity(8*pi) 
		&& constr.check_unitarity(8*pi)  
		)
	cout << sqrt(m12_2) << "\t" << tb << endl;


 
//    printf("\n");
//    printf(" Oblique S: %12.5e\n", S);  
//    printf(" Oblique T: %12.5e\n", T);
//    printf(" Oblique U: %12.5e\n", U);  
//    printf(" Oblique V: %12.5e\n", V);
//    printf(" Oblique W: %12.5e\n", W);  
//    printf(" Oblique X: %12.5e\n", X);
//    printf(" Delta_rho: %12.5e\n", constr.delta_rho(mh_ref));
//    printf("\n");
//    printf(" Delta_amu: %12.5e\n\n", constr.delta_amu());


  // Prepare to calculate decay widths
//   DecayTable table(model);
// 
//   // Print total widths of Higgs bosons
//   table.print_width(1);
//   table.print_width(2);
//   table.print_width(3);
//   table.print_width(4);	
// 
//   table.print_decays(1);
//   table.print_decays(2);
//   table.print_decays(3);
//   table.print_decays(4);

}
  // Write output to LesHouches file
  //model.write_LesHouches("Demo_out.lha", 1, 1, 1, 1);
  
  */
    	
  //flavour scenario
 double mh=125;
 double mH=1700.87654;
 double mA=175;
 double mC=175.87654;
 double sba= 0.868645678;
 double lambda_6=0;
 double lambda_7=0;
 double m12_2=2948.11936;
 double tb=100;


//flavour scenario
// double mh=125;
// double mH=175;
// double mA=175;
// double mC=175;
// double sba= 1;
// double lambda_6=0;
// double lambda_7=0;
// double m12_2=2948.11936;
// double tb=10;

  	bool pset = model.set_param_phys(mh,mH,mA,mC,sba,lambda_6,lambda_7,m12_2,tb);
   
	if (!pset) {
		cerr << "The specified parameters are not valid\n";
		return -1;
	}

  model.print_param_higgs();
  model.print_param_gen();

  // Set Yukawa couplings to type II
  model.set_yukawas_type(1);
  

  // Prepare to calculate observables
  
   Constraints constr(model);
   printf("\nConstraints:\n");
   printf("  Potential stability: %s\n", (constr.check_stability() ? "OK" : "Not OK"));
   printf(" Tree-level unitarity: %s\n", (constr.check_unitarity() ? "OK" : "Not OK"));
   printf("       Perturbativity: %s\n", (constr.check_perturbativity() ? "OK" : "Not OK"));
  // Write output to LesHouches file
  model.write_LesHouches("Demo_Ahrib.lha", 1, 1, 1, 1);

}

