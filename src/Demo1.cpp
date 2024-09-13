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

    double mh=mh_ref;
    double mA;
    double mH;
    double mC;
    double lambda_6=0;
    double lambda_7=0;

    double tb=20.0;
    double sba=1.0;
    
    double m12_2=0;



//      double yukawa = 1;
//      for ( int tbi=1; tbi<=25; tbi++ )
//      {
//      for ( int mHi=0; mHi<=35; mHi++ )
//      { 
	int counter=0;

     double yukawa =1;
     for ( int tbi=1; tbi<=20; tbi++ )
     {
 
     for ( int mHi=0; mHi<=20; mHi++ )
     {

		if (yukawa==1)	mH=mA=mC=150.0+mHi*25.0;
		if (yukawa==2)	mH=mA=mC=500.0+mHi*25.0;

		tb=tbi*2.0;
    	counter=0;

    	for ( int m12=0; m12<=360000; m12++ )
    	{
    
			m12_2=m12*1;

        	bool pset = model.set_param_phys(mh,mH,mA,mC,sba,lambda_6,lambda_7,m12_2, tb);

	        model.set_yukawas_type(yukawa);

			if (!pset) {
            	cerr << "The specified parameters are not valid\n";
            	return -1;
        	}

        	// Prepare to calculate observables
        	Constraints constr(model);
        	double S,T,U,V,W,X;
        	constr.oblique_param(mh_ref,S,T,U,V,W,X);

        	//if (m12==1) cout << mH << "\t" << tb << "\t";

        	if ( constr.check_stability() && constr.check_unitarity() && constr.check_perturbativity() )
        	{
        	
			cout << mH << "\t" << tb << "\t" <<  m12_2 << endl;     
			counter++;
			}
			
			if (counter==30) break;
			//cout << "1  ";
        	//else cout << "0   ";
    
        	// Prepare to calculate decay widths
        	// DecayTable table(model);

        	// Print total widths of Higgs bosons
        	// table.print_width(1);
        	// table.print_width(2);
        	//table.print_width(3);
        	table.print_width(4);
        
        }
        
        //cout << endl;
        
    }
	}
}
