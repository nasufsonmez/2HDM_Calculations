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


 double tb= 2.0000000   ;
 double lambda_1= 8.61950035; 
 double lambda_2= 0.651845914;
 double lambda_3= -2.30640690;
 double lambda_4= 2.73321532;
 double lambda_5= -1.98764301;
 double lambda_6= 0.00000000;
 double lambda_7= 0.00000000;
 double m32=15800;

  	
  	bool pset = model.set_param_gen(lambda_1,lambda_2,lambda_3,lambda_4,lambda_5,lambda_6,lambda_7,m32,tb);
 
  	//bool pset = model.set_param_hybrid( mh_HYBRID, mH_HYBRID, cba, Z_4_HYBRID, Z_5_HYBRID, Z_7_HYBRID, tb_HYBRID);
  
	if (!pset) {
		cerr << "The specified parameters are not valid\n";
		return -1;
	}

#if defined HiggsBounds
  HB_init();
  HS_init();
#endif

  // Set Yukawa couplings to type II
  model.set_yukawas_type(1);
  
  // Print the parameters in different parametrizations
  model.print_param_phys();
  model.print_param_gen();
  //model.print_param_higgs();
 // model.print_param_hybrid();

  // Prepare to calculate observables
   Constraints constr(model);
// 
   double S,T,U,V,W,X;   
// 
   constr.oblique_param(mh_ref,S,T,U,V,W,X);
   
   printf("\nConstraints:\n");
    printf("  Potential stability: %s\n", (constr.check_stability() ? "OK" : "Not OK"));
    printf(" Tree-level unitarity: %s\n", (constr.check_unitarity() ? "OK" : "Not OK"));
    printf("       Perturbativity: %s\n", (constr.check_perturbativity() ? "OK" : "Not OK"));


  // Write output to LesHouches file
  //model.write_LesHouches("Demo_out.lha", 1, 1, 1, 1);

}

