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

    double tb=2.0;
    double sba=1.0;
    
    double m12_2=0;

     int yukawa=1;
     
     
     /*
     for ( int tbi=10; tbi<=10; tbi++ )
     {
     	int counter=1;
		
     	for ( int mHi=0; mHi<=0; mHi++ )
     	{
			if (yukawa==1)	
			{
				tb=0.000+((40.0-6.0)/34.0)*tbi;
				tb=tbi;
				mH=mA=mC=150.0+((1000-150)/50.0)*mHi;

				m12_2=pow(-4. + tb,-4)*pow(
				-99987.33753640487 + 77598.68957891017*tb 
				- 26494.826275634856*pow(tb,2) + 5282.412862412227*pow(tb,3) 
				- 688.225107181552*pow(tb,4) + 62.04849936436649*pow(tb,5) 
				- 3.9925263251497887*pow(tb,6) + 0.1860450627275701*pow(tb,7) 
				- 0.006290046858366562*pow(tb,8) + 0.00015263173042590113*pow(tb,9) 
				- 2.5871217293025866e-6*pow(tb,10) + 2.9035981946091617e-8*pow(tb,11) 
				- 1.9352895936055624e-10*pow(tb,12) 
				+ mH*(
				207.88193606103624 - 157.97250923713995*tb 
				+ 52.391957425919415*pow(tb,2) - 10.136566552638147*pow(tb,3) 
				+ 1.2863283347824388*pow(tb,4) - 0.11267491520360959*pow(tb,5) 
				+ 0.00701121732486905*pow(tb,6) - 0.00031391035077722837*pow(tb,7) 
				+ 0.000010110231528057614*pow(tb,8) - 2.310533291973951e-7*pow(tb,9) 
				+ 3.631322367452047e-9*pow(tb,10) - 3.695866964815274e-11*pow(tb,11) 
				+ 2.1603029996648365e-13*pow(tb,12) - 5.362571204074182e-16*pow(tb,13)) 
				+ pow(mH,2)*(
				- 0.12861330549570116 + 0.09838249810892293*tb 
				- 0.033055396558504056*pow(tb,2) + 0.006469060300237847*pow(tb,3) 
				- 0.0008245148257392634*pow(tb,4) + 0.0000724057170903514*pow(tb,5) 
				- 4.513127215394508e-6*pow(tb,6) + 2.02305862545101e-7*pow(tb,7) 
				- 6.520839190637537e-9*pow(tb,8) + 1.4907437106824571e-10*pow(tb,9) 
				- 2.342355345495539e-12*pow(tb,10) + 2.3813286127488092e-14*pow(tb,11) 
				- 1.3882730127012803e-16*pow(tb,12) + 3.4267660655571026e-19*pow(tb,13)
				) + 5.787132716521154e-13*pow(tb,13),2);
       
       			}
			
			if (yukawa==2)
			{
				tb=0.000+((40.0-6.0)/34.0)*tbi;
				
				mH=mA=mC=500.0+(1000-500)/50.0*mHi;
				
							
				m12_2=pow(-4. + tb,-2)*pow(
				181.1921189210085 - 149.61829953125607*tb 
				+ 50.65224353042219*pow(tb,2) - 9.629507089754735*pow(tb,3) 
				+ 1.1488709979129266*pow(tb,4) - 0.0910501094516894*pow(tb,5) 
				+ 0.004958439619304997*pow(tb,6) - 0.00018940998511035424*pow(tb,7) 
				+ 5.124614341848987e-6*pow(tb,8) - 9.775727672285644e-8*pow(tb,9) 
				+ 1.2739254980850442e-9*pow(tb,10) - 1.0332787899165817e-11*pow(tb,11) 
				+ mH*(
				- 3.8034863887937846 + 1.8194691901069302*tb - 0.37012286432672964*pow(tb,2) 
				+ 0.056576346989722553*pow(tb,3) - 0.005995043601950982*pow(tb,4) 
				+ 0.00044358567058433283*pow(tb,5) - 0.000023181261857230954*pow(tb,6) 
				+ 8.615223764711788e-7*pow(tb,7) - 2.2746592065906016e-8*pow(tb,8) 
				+ 4.2072622313329457e-10*pow(tb,9) - 5.244569165095813e-12*pow(tb,10) 
				+ 4.006985767354069e-14*pow(tb,11) - 1.431243261537634e-16*pow(tb,12)) 
				+ pow(mH,2)*(
				+ 0.0004607327529490264 - 0.0003623144911035905*tb 
				+ 0.00011967535942985455*pow(tb,2) - 0.000022177330259595694*pow(tb,3) 
				+ 2.5726203077181796e-6*pow(tb,4) - 1.9731238485279592e-7*pow(tb,5) 
				+ 1.0304246349210081e-8*pow(tb,6) - 3.7153192267023893e-10*pow(tb,7) 
				+ 9.264315303728948e-12*pow(tb,8) - 1.5799116639905317e-13*pow(tb,9) 
				+ 1.7866914154662156e-15*pow(tb,10) - 1.2392606248563181e-17*pow(tb,11) 
				+ 4.119977127207138e-20*pow(tb,12)) + 3.9592563722008046e-14*pow(tb,12),2);	
			}	
			
		mH=mA=mC=175.0;
	     for ( int m12=1; m12<=350; m12++ )
	     {

			m12_2=m12*m12;
			
			bool pset = model.set_param_phys(mh,mH,mA,mC,sba,lambda_6,lambda_7,m12_2, tb);

			model.set_yukawas_type(yukawa);

			if (!pset) {
            		cerr   << "The specified parameters are not valid\n";
            		return -1;
			}

			// Prepare to calculate observables
			Constraints constr(model);
			double S,T,U,V,W,X;
			constr.oblique_param(mh_ref,S,T,U,V,W,X);


    		if ( constr.check_stability() && constr.check_unitarity() && constr.check_perturbativity() )
    		{
    			cout << counter++ << "\t"<< mH << "\t" << tb << "\t" <<  m12 << endl;     
			}
			//else cout <<  counter++  << "\t" << mH  << "\t"<< tb << "\t ----------------not " <<endl;
   			// Prepare to calculate decay widths
   			//DecayTable table(model);

   			// Print total widths of Higgs bosons
   			//table.print_width(4);
   			
   			//table.print_decays(2);
   			//table.print_decays(3);
    		//table.print_decays(4);

    		//table.print_decays(1);
    		//table.print_decays(4);
		}

		}
	}
	
	*/
	
	
	int counter=0;
	
     for ( int tbi=0; tbi<=320; tbi++ )
     {
	     for ( int m12=1; m12<=700; m12++ )
     {
     
     		tb=2.0+(50.0-2.0)/320.0*tbi;
     		
			m12_2=pow((100.0/700.0)*m12,2);
	
			mH=mA=mC=175.0;
			bool pset = model.set_param_phys(mh,mH,mA,mC,sba,lambda_6,lambda_7,m12_2, tb);

			model.set_yukawas_type(yukawa);

			if (!pset) {
            		cerr   << "The specified parameters are not valid\n";
            		return -1;
			}

			// Prepare to calculate observables
			Constraints constr(model);

    		if ( constr.check_stability() && constr.check_unitarity() && constr.check_perturbativity() )
    		{
    			cout << counter++ << "\t"<< mH << "\t" << tb << "\t" <<  m12 << endl;     
    			// Prepare to calculate decay widths
   				DecayTable table(model);
   				table.print_decays(1);
   				table.print_decays(2);
    			table.print_decays(3);

			}
/*    		if ( constr.check_stability() || constr.check_unitarity() || constr.check_perturbativity() )
    		{
    			cout << counter++ << "\t"<< mH << "\t" << tb << "\t" <<  m12 << endl;     
			}
*/
	}
	}
	
}



