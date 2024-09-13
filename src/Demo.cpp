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
  double mh_ref = 126.;

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
//  double mh       = 100.;
//  double mH       = 400.;
//  double mA       = 300.;
//  double mC       = 120.;
//  double sba      = 0.999;
//  double lambda_6 = 0.;
//  double lambda_7 = 0.;
//  double m12_2    = 15800.; 
//  double tb       = 10.;
 
    double lambda_6[]   = {
        0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,
        0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,
        0.0,0.0,0.0 // type-X noktalar
    };

    double lambda_7[]   = {
        0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,
        0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,
        0.0,0.0,0.0 // type-X noktalar

    };

    double mh[] = {
        100,
        126, 126, 126, 126, 126, 126, 126,
        126,
        126, 126, 126,126,
        126, 126, 126,126,
        126, 126, 126,126,
        126, 126, 126,
        126, 126, 126  // type-X noktalar

    };

    double mA[] = {
        305,
        441, 701, 350, 500, 500, 500, 500,
        700,
        383,444,502,619,
        337,361,350,491,
        319,350,350,634,
        300,400,600,
        10,30,40  // type-X noktalar
    };

    double mH[] = {
        150, 
        300, 700, 200, 200, 200, 500, 500,
        700,
        200,300,400,600,
        200,300,400,600,
        200,300,400,600,
        250,229,498,
        200,200,200  // type-X noktalar
    };

    double mC[] = {
        120, 442, 670, 350, 500, 500, 500, 500,
        670,
        383,445,503,579,
        337,365,407,600,
        320,347,404,587,
        307,399,601,
        200,200,200  // type-X noktalar
    };

    double tb[]   = {
        10., 
        1.75, 1.50, 2.22, 1.20, 20.0, 10.0, 10.0,
        1.5,
        2.52,2.23,1.73,1.74,
        2.22,1.88,1.49,1.25,
        2.78,2.17,1.85,2.40,
        5.34,4.90,6.45,
        50,80,100  // type-X noktalar
    };

    double sba[]  = {
        sin(pi/2),
        sin(atan(1.75) - (-0.1872)*pi),
        sin(atan(1.50) - (-0.2162)*pi),
        sin(atan(2.22) - (-0.1397)*pi),
        sin(atan(1.20) - (-0.1760)*pi),
        sin(atan(20.0) - (+0.0000)*pi),
        sin(atan(10.0) - (-0.0382)*pi),
        sin(atan(10.0) - (+0.0323)*pi),
        sin(0.529*pi),
        sin(0.511*pi), sin(0.525*pi), sin(0.533*pi), sin(0.533*pi),
        sin(0.505*pi), sin(0.509*pi), sin(0.518*pi), sin(0.522 *pi),
        sin(0.503*pi), sin(0.507*pi), sin(0.503*pi), sin(0.520*pi),
        sin(0.502*pi), sin(0.502*pi), sin(0.502 *pi),
        sin(pi/2), sin(pi/2), sin(pi/2) // type-X noktalar
    };

    double m12_2[]   = {
        15800.0,
        38300.0, 180000.0, 12000.0, -60000.0, 2000.0, 24746.0, 24762.0,
        180000,
        14300.,32700.,62900.,126000.,
        12000.,27800.,47100.,123000.,
        10400.,26500.,53100.,114000.,
        10700.,10300.,37500.,
        794.532, 499.54, 399.754   // type-X noktalar
    };

    int yukawa_type[]={
        2,
        2,2,1,1,2,2,2,
        2,
        2,2,2,2,
        2,2,2,2,
        2,2,2,2,
        2,2,2,
        4,4,4 // type-X noktalar
    };
    
    
    
    double Z_4_HYBRID[]   = {
        -2.0, -2.0, -2.0, -2.0,				//scenario A (non alignment)
        -5.0, -5.0, -5.0,					//scenario B (low-mH)
        -1.0, +2.0, +1.0, -1.0, 2.0, 1.0,	//scenario D (short cascade)
        -6.0, +1.0, -6.0, +1.0,				//scenario E (long cascade)
        -2.0								//scenario F (flipped yukawa)
    };
    
    double Z_5_HYBRID[]   = {
        -2.0, -2.0, -2.0, -2.0,				//scenario A (non alignment)
        -5.0, -5.0, -5.0,					//scenario B (low-mH)
        +1.0, +0.0, +1.0, +1.0, 0.0, 1.0,	//scenario D (short cascade)
        -2.0, -3.0, -2.0, -3.0,				//scenario E (long cascade)
        -2.0								//scenario F (flipped yukawa)
    };
    
    double Z_7_HYBRID[]   = {
        0.0, 0.0, 0.0, 0.0,					//scenario A (non alignment)
        0.0, 0.0, 0.0,						//scenario B (low-mH)
        -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,	//scenario D (short cascade)
        0.0, 0.0, 0.0, 0.0,					//scenario E (long cascade)
        0.0									//scenario F (flipped yukawa)
    };
    
    
    int yukawa_typeHYBRID[] = {
        1, 1, 2, 2,							//scenario A (non alignment)
        1, 1, 2,							//scenario B (low-mH)
        1, 1, 1, 2, 2, 2,					//scenario D (short cascade)
        1, 1, 2, 2,							//scenario E (long cascade)
        2									//scenario F (flipped yukawa)
    };
    
    double mh_HYBRID[] = {
        125, 125, 125, 125,					//scenario A (non alignment)
        65, 80, 65,                         //scenario B (low-mH)
        125, 125, 125, 125, 125, 125,		//scenario D (short cascade)
        125, 125, 125, 125,					//scenario E (long cascade)
        125									//scenario F (flipped yukawa)
    };

    double mH_HYBRID[] = {
        150, 200, 300, 500,					//scenario A (non alignment)
        125, 125, 125,						//scenario B (low-mH)
        250, 300, 400, 400, 500, 500,		//scenario D (short cascade)
        200, 225, 250, 300,					//scenario E (long cascade)
        200									//scenario F (flipped yukawa)
    };
    
    double tb_HYBRID[]   = {
        2, 5, 10, 30,                       //scenario A (non alignment)    1-50 arasinda degisiyor
        1.5, 1.5, 1.5,						//scenario B (low-mH)
        2, 2, 2, 2, 2, 2,					//scenario D (short cascade)
        2, 2, 2, 2,							//scenario E (long cascade)
        10									//scenario F (flipped yukawa)   5-50 arasinda degisiyor
    };
    
    
    double cba[]  = {
        0.1, 0.1*pow(150./mH_HYBRID[0],2), 0.01, 0.01*pow(150./mH_HYBRID[0],2),
        1.0, 0.9, 1.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0,
        0.19802
    };

    std::cout << "Length of array cba = "        << (sizeof(cba)/sizeof(*cba)) << std::endl;
    std::cout << "Length of array tb_HYBRID = "  << (sizeof(tb_HYBRID)/sizeof(*tb_HYBRID)) << std::endl;
    std::cout << "Length of array mH_HYBRID = "  << (sizeof(mH_HYBRID)/sizeof(*mH_HYBRID)) << std::endl;
    std::cout << "Length of array mh_HYBRID = "  << (sizeof(mh_HYBRID)/sizeof(*mh_HYBRID)) << std::endl;
    std::cout << "Length of array Z_4_HYBRID = " << (sizeof(Z_4_HYBRID)/sizeof(*Z_4_HYBRID)) << std::endl;
    std::cout << "Length of array Z_5_HYBRID = " << (sizeof(Z_5_HYBRID)/sizeof(*Z_5_HYBRID)) << std::endl;
    std::cout << "Length of array Z_7_HYBRID = " << (sizeof(Z_7_HYBRID)/sizeof(*Z_7_HYBRID)) << std::endl;
    std::cout << "Length of array yukawa_type = " << (sizeof(yukawa_typeHYBRID)/sizeof(*yukawa_typeHYBRID)) << std::endl;


    //char outputfilename[100];
    for ( int i=0; i<18; i++ )
    //for ( int i=1; i<24; i++ )
    {
    
        // Print the parameters in different parametrizations
        cout << "================================================================" << endl;

        //cout << "Benchmark Point : " << i + 1 << endl;
        //double yukawa = yukawa_type[i];
        //bool pset = model.set_param_phys(mh[i],mH[i],mA[i],mC[i],sba[i],lambda_6[i],lambda_7[i],m12_2[i], tb[i]);

        cout << "Benchmark Point for HYBRID base: " << i + 28 << endl;
        double yukawa = yukawa_typeHYBRID[i];
        bool pset = model.set_param_hybrid( mh_HYBRID[i], mH_HYBRID[i], cba[i], Z_4_HYBRID[i], Z_5_HYBRID[i], Z_7_HYBRID[i], tb_HYBRID[i]);

        // Set Yukawa couplings to type II
        model.set_yukawas_type(yukawa);

        if (!pset) {
            cerr << "The specified parameters are not valid\n";
            return -1;
        }



        cout << "Yukawa Coupling : " << yukawa << endl;
        model.print_param_phys();
        //model.print_param_gen();
        //model.print_param_higgs();
        //model.print_param_hybrid();

        // Prepare to calculate observables
        Constraints constr(model);

        double S,T,U,V,W,X;

        constr.oblique_param(mh_ref,S,T,U,V,W,X);
  
        printf("\n Constraints :\n");
        printf(" Potential stability : %s\n",  (constr.check_stability()      ? "OK\n" : "Not OK\n"));
        printf(" Tree-level unitarity : %s\n", (constr.check_unitarity()      ? "OK\n" : "Not OK\n"));
        printf(" Perturbativity : %s\n",       (constr.check_perturbativity() ? "OK\n" : "Not OK\n"));
        printf("     Mass constraints: %s\n", (constr.check_masses() ? "OK" : "Not OK"));
        printf("\n");
        
        if ( constr.check_stability() && constr.check_unitarity() && constr.check_perturbativity() )
        cout << i << " ******* ok ******* " << endl;
        printf(" Oblique S: %12.5e\n", S);
        printf(" Oblique T: %12.5e\n", T);
        printf(" Oblique U: %12.5e\n", U);
        printf(" Oblique V: %12.5e\n", V);
        printf(" Oblique W: %12.5e\n", W);
        printf(" Oblique X: %12.5e\n", X);
        printf(" Delta_rho: %12.5e\n", constr.delta_rho(mh_ref));
        printf("\n");
        printf(" Delta_amu: %12.5e\n\n", constr.delta_amu());
    
    cout << "Benchmark " << i + 1 << "\t&";
    cout << S << "\t&" ;
    cout << T << "\t&" ;
    cout << U << "\t&" ;
    cout << V << "\t&" ;
    cout << W << "\t&" ;
    cout << X << "\t &";
    cout << constr.delta_rho(mh_ref);
    cout << "\\hline" << endl;
    
        // Prepare to calculate decay widths
        DecayTable table(model);

        // Print total widths of Higgs bosons
        table.print_width(1);
        table.print_width(2);
        table.print_width(3);
        table.print_width(4);
        
        table.print_decays(1);
        table.print_decays(2);
        //table.print_decays(3);
        //table.print_decays(4);
        //Write output to LesHouches file
        

        //sprintf(outputfilename,"Demo_output_benchpoint%i.lha",i);
        //model.write_LesHouches(outputfilename, 1, 0);
    }
}
