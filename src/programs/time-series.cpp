//author: Razvan Vasile Ababei
//York University
//3.11.2015


#include <iostream>
#include <vector>
#include <vector>
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
    double H_app;
    int time=0;
    void time_series(){
    std::cout<<"Insert the magnitude of the applied field: ..T"<<std::endl;
    std::cin>> H_app;

        st::H_applied[2]=H_app;
        
            while(time < times::equilibration_time){
                integrator::LLG();
                time++;
                magnetization::magnetization_out();
                }//end of while loop
    

    }//end of function
}//end of namespace
