//author: Razvan V Ababei, York University
//email address: rva502@york.ac.uk
//
//
//This program makes part of ASMScode. For any queries or suggestions please contact the author
//
//
#include <iostream>
#include <vector>
#include <cmath>
//ASMS headers
#include "../../hdr/create.h"
#include "../../hdr/times.h"
#include "../../hdr/storage.h"
#include "../../hdr/fields.h"
#include "../../hdr/mat.h"
#include "../../hdr/integrator.h"
#include "../../hdr/hysteresis.h"
#include "../../hdr/magnetization_out.h"
namespace program{
    int H_max=28;
    int DH=1;
    int H_min=-H_max;
    int H;
    int branch;
    void hysteresis(){

        for(branch = -1; branch<2; branch +=2) {

        for (H=H_min; H<=H_max; H += DH){

                st::H_applied[2] = branch * H;

                int time=0;
                while(time <= times::loop_time_steps){

                    integrator::LLG();
                    time++;
               }
              // std::cout<<st::H_ani[0].z<<"\t"<<st::H_ex[0].z<< "\t"<< st::H_total[0].z<<"\t"<<st::atom[0].sz<<std::endl;
               magnetization::magnetization_out();

            }

              //  std::cout<<st::H_ani[5].z<<"\t"<<st::H_ex[5].z<< "\t"<< st::H_total[5].z<<"\t"<<st::atom[5].sz<<std::endl;
        }
    }//end of void
}//end of namespace
