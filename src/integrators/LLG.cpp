//author: Razvan-Vasile Ababei, York University
//last update: 12 September 2015

#include <iostream>
#include <vector>
#include <cmath>
#include "../../hdr/storage.h"
#include "../../hdr/fields.h"
#include "../../hdr/mat.h"
#include "../../hdr/create.h"
#include "../../hdr/integrator.h"
#include "../../hdr/times.h"
#include "../../hdr/template.h"
namespace integrator{

     //defining the coeficients =|> DS = B1 (S X H) + B2 (S X S X H)
     double B1 = - mat::gyro / (1 + mat::alpha * mat::alpha);
     double B2 = - (mat::alpha * mat::gyro) / (1 + mat::alpha * mat::alpha);
     double dt = times::time_step; //times::time_step;
     double time = times::loop_time_steps;// times::loop_time_steps;
     //defining the euler step
     std::vector<template_t::atom> DS;
     std::vector<template_t::atom> DS_prime;
     //intermediate step
     std::vector<template_t::atom> S_prime;
     std::vector<template_t::atom> S_par;
     std::vector<template_t::atom> S_initial;
     //normalized spin
     std::vector<template_t::atom>  S_tot;
void LLG(){
	//defining the coeficients ==> DS = -B1 (S X H) - B2 (S X S X H)
/*	double B1 = - mat::gyro / (1 + mat::alpha * mat::alpha);
	double B2 =  -(mat::alpha * mat::gyro) / (1 + mat::alpha * mat::alpha);
	double dt = times::time_step; //times::time_step;
	double time = times::loop_time_steps;// times::loop_time_steps;
	//defining the euler step
	std::vector <template_t::atom>  DS;
	std::vector <template_t::atom>  DS_prime;
	//intermediate step
	std::vector <template_t::atom>  S_prime;
	std::vector <template_t::atom>  S_par;
        std::vector <template_t::atom> S_initial;
	//normalized spin
	std::vector <template_t::atom>  S_tot;*/

        //resize the vectors
	DS.resize(create::index);
	DS_prime.resize(create::index);
	S_par.resize(create::index);
	S_tot.resize(create::index);
	S_prime.resize(create::index);
        S_initial.resize(create::index);

      //for (int t=0; t < time; t++){
          //  fields_t::H_ex();
            //fields_t::H_an();
            fields_t::H_total(); 
                  


            for (int i=0; i<create::index; i++){


                S_initial[i].sx = st::atom[i].sx;
                S_initial[i].sy = st::atom[i].sy;
                S_initial[i].sz = st::atom[i].sz;

    		DS[i].sx = B1*( S_initial[i].sy * st::H_total[i].z - S_initial[i].sz * st::H_total[i].y) + B2*(
				S_initial[i].sy * S_initial[i].sx * st::H_total[i].y -
				S_initial[i].sy * S_initial[i].sy * st::H_total[i].x +
				S_initial[i].sz * S_initial[i].sx * st::H_total[i].z -
				S_initial[i].sz * S_initial[i].sz * st::H_total[i].x );

	      	DS[i].sy =  B1*( -S_initial[i].sx * st::H_total[i].z + S_initial[i].sz * st::H_total[i].x) + B2*(
			       -S_initial[i].sx * S_initial[i].sx * st::H_total[i].y +
				S_initial[i].sx * S_initial[i].sy * st::H_total[i].x +
				S_initial[i].sz * S_initial[i].sy * st::H_total[i].z -
				S_initial[i].sz * S_initial[i].sz * st::H_total[i].y );

		DS[i].sz = B1*( S_initial[i].sx * st::H_total[i].y - S_initial[i].sy * st::H_total[i].x) + B2*(
			       -S_initial[i].sx * S_initial[i].sx * st::H_total[i].z +
				S_initial[i].sx * S_initial[i].sz * st::H_total[i].x -
				S_initial[i].sy * S_initial[i].sy * st::H_total[i].z +
				S_initial[i].sy * S_initial[i].sz * st::H_total[i].y );

		S_par[i].sx = S_initial[i].sx + dt * DS[i].sx;
		S_par[i].sy = S_initial[i].sy + dt * DS[i].sy;
		S_par[i].sz = S_initial[i].sz + dt * DS[i].sz;


		S_prime[i].sx = S_par[i].sx / sqrt(S_par[i].sx * S_par[i].sx +
                                S_par[i].sy * S_par[i].sy + S_par[i].sz * S_par[i].sz);

		S_prime[i].sy = S_par[i].sy / sqrt(S_par[i].sx * S_par[i].sx +
                                S_par[i].sy * S_par[i].sy + S_par[i].sz * S_par[i].sz);

		S_prime[i].sz = S_par[i].sz / sqrt(S_par[i].sx * S_par[i].sx +
                                S_par[i].sy * S_par[i].sy + S_par[i].sz * S_par[i].sz);

                       st::atom[i].sx = S_prime[i].sx;
                       st::atom[i].sy = S_prime[i].sy;
                       st::atom[i].sz = S_prime[i].sz;}
            
//==========================================================================================================================================================
//                             Updating the fields
//==========================================================================================================================================================
                                     // fields_t::H_an();
                                    //  fields_t::H_ex();
                                      fields_t::H_total();
//==========================================================================================================================================================
                    for (int k=0; k<create::index;k++){

			 DS_prime[k].sx =  B1*( S_prime[k].sy *st::H_total[k].z - S_prime[k].sz * st::H_total[k].y) + B2*(
                                S_prime[k].sy * S_prime[k].sx *st::H_total[k].y -
                                S_prime[k].sy * S_prime[k].sy *st::H_total[k].x +
                                S_prime[k].sz * S_prime[k].sx *st::H_total[k].z -
                                S_prime[k].sz * S_prime[k].sz *st::H_total[k].x );

			 DS_prime[k].sy =  B1*( -S_prime[k].sx *st::H_total[k].z + S_prime[k].sz * st::H_total[k].x) + B2*(
                               -S_prime[k].sx * S_prime[k].sx *st::H_total[k].y +
                                S_prime[k].sx * S_prime[k].sy *st::H_total[k].x +
                                S_prime[k].sz * S_prime[k].sy *st::H_total[k].z -
                                S_prime[k].sz * S_prime[k].sz *st::H_total[k].y );

			 DS_prime[k].sz =  B1*( S_prime[k].sx *st::H_total[k].y - S_prime[k].sy * st::H_total[k].x) + B2*(
                               -S_prime[k].sx * S_prime[k].sx *st::H_total[k].z +
                                S_prime[k].sx * S_prime[k].sz *st::H_total[k].x -
                                S_prime[k].sy * S_prime[k].sy *st::H_total[k].z +
                                S_prime[k].sy * S_prime[k].sz *st::H_total[k].y );

                        S_tot[k].sx = S_initial[k].sx + 0.5*(DS[k].sx + DS_prime[k].sx)*dt;
                        S_tot[k].sy = S_initial[k].sy + 0.5*(DS[k].sy + DS_prime[k].sy)*dt;
                        S_tot[k].sz = S_initial[k].sz + 0.5*(DS[k].sz + DS_prime[k].sz)*dt;

                         //updating normalized spins
                         S_tot[k].sx /= sqrt(S_tot[k].sx*S_tot[k].sx + S_tot[k].sy*S_tot[k].sy + S_tot[k].sz*S_tot[k].sz);
                         S_tot[k].sy /= sqrt(S_tot[k].sx*S_tot[k].sx + S_tot[k].sy*S_tot[k].sy + S_tot[k].sz*S_tot[k].sz);
                         S_tot[k].sz /= sqrt(S_tot[k].sx*S_tot[k].sx + S_tot[k].sy*S_tot[k].sy + S_tot[k].sz*S_tot[k].sz);

//================================================================================================================================================================
                        

                        st::atom[k].sx = S_tot[k].sx;
                        st::atom[k].sy = S_tot[k].sy;
                        st::atom[k].sz = S_tot[k].sz;
                    }
                    //fields_t::H_ex();
                   // fields_t::H_an();
        	   // fields_t::H_total(); 

       }//end of LLG function

}//end of namespace
