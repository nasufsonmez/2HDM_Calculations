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

using namespace std;

double pi=3.14159265358979323846264338;

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
	double mh_HYBRID  =  120.0;
	double mH_HYBRID  =  125.;
	double cba        =  1.0;
	double Z_4_HYBRID = -1;
	double Z_5_HYBRID = -1;
	double Z_7_HYBRID =  0;
	double tb_HYBRID  =  5;
	
/*	double yukawa =1;
	for ( int tbi=0; tbi<=50; tbi++ )
	{
		int counter=1;

     	for ( int mHi=0; mHi<=50; mHi++ )
     	{
			tb_HYBRID=2.00+(50.0-2.0)/50.0*tbi;
			mh_HYBRID=65.0+(120.0-65.0)/50.0*mHi;


			bool pset = model.set_param_hybrid( mh_HYBRID, mH_HYBRID, cba, Z_4_HYBRID, Z_5_HYBRID, Z_7_HYBRID, tb_HYBRID);

			model.set_yukawas_type(yukawa);

			if (!pset) {
            		cerr << "The specified parameters are not valid\n";
            		return -1;
			}

			// Prepare to calculate observables
			Constraints constr(model);
			double S,T,U,V,W,X;
			constr.oblique_param(mh_ref,S,T,U,V,W,X);


    		if ( constr.check_stability() && constr.check_unitarity() && constr.check_perturbativity() )
    		{
    			cout << counter++ << "\t"<< mh_HYBRID<< "\t"<< mH_HYBRID << "\t" << tb_HYBRID<< "\t" << tb_HYBRID << endl;     
			}
   			// Prepare to calculate decay widths
   			DecayTable table(model);

   			// Print total widths of Higgs bosons
   			//table.print_width(1);
   			//table.print_width(2);
   			//table.print_width(3);
    		//table.print_width(4);

    		table.print_decays(1);
    		table.print_decays(2);
    		table.print_decays(4);
    	
		}
		cout << endl;
	}
*/	



	mh_HYBRID  =  125.0;
	mH_HYBRID  =  400.;
	cba        =  0.01;
	Z_4_HYBRID = -2;
	Z_5_HYBRID = -2;
	Z_7_HYBRID =  0;
	tb_HYBRID  =  2;

	bool pset = model.set_param_hybrid( mh_HYBRID, mH_HYBRID, cba, Z_4_HYBRID, Z_5_HYBRID, Z_7_HYBRID, tb_HYBRID);

	if (!pset) {	cerr << "The specified parameters are not valid\n";
            		return -1;
	}
	
	
	model.print_param_higgs();
	model.print_param_gen();
	model.print_param_phys();
	
			Constraints constr(model);
			double S,T,U,V,W,X;
			constr.oblique_param(mh_ref,S,T,U,V,W,X);
   printf("\nConstraints:\n");
   printf("  Potential stability: %s\n", (constr.check_stability() ? "OK" : "Not OK"));
   printf(" Tree-level unitarity: %s\n", (constr.check_unitarity() ? "OK" : "Not OK"));
   printf("       Perturbativity: %s\n", (constr.check_perturbativity() ? "OK" : "Not OK"));
 
   printf("\n");
   printf(" Oblique S: %12.5e\n", S);  
   printf(" Oblique T: %12.5e\n", T);
   printf(" Oblique U: %12.5e\n", U);  
   printf(" Oblique V: %12.5e\n", V);
   printf(" Oblique W: %12.5e\n", W);  
   printf(" Oblique X: %12.5e\n", X);
   printf(" Delta_rho: %12.5e\n", constr.delta_rho(mh_ref));
   printf("\n");
   printf(" Delta_amu: %12.5e\n\n", constr.delta_amu());



}



