#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>
//ASMS headers
#include "../hdr/create.h"
#include "../hdr/mat.h"
//#include "../hdr/template.h"
#include "../hdr/storage.h"
#include "../hdr/fields.h"
#include "../hdr/integrator.h"
#include "../hdr/hysteresis.h"
#include "../hdr/magnetization_out.h"

int main(){
    std::cout << "========================================================================================================================================="<<std::endl;
    std::cout << "ASMS code has been developed by MSc Razvan V Ababei according to Atomistic Spin Model simulations of magnetic nanomaterials"<<std::endl;
    std::cout << "========================================================================================================================================="<<std::endl;
    std::cout << "\n";
    std::cout << "This code is free but no warranty! For any queries or suggestions please contact the author!"<<std::endl;
    std::cout << "email address: rva502@york.ac.uk"<<std::endl;
    std::cout << "========================================================================================================================================="<<std::endl;
    std::cout << "ASMS HAS STARTED TO RUN" <<std::endl;
    std::cout << "Insert the type of structure:" <<"\n";
    std::cout << "press 0 for single spin, 1 for simple cubic (sc), 2 for bcc "<< std::endl;
    int option_A;
    std::cin >> option_A;
    if(option_A==0){
            create::single_spin();
    } else
    if(option_A==1){
            create::create_sc();
    } else
    {   std::cout << "Invalid option!"<< std::endl;}
    //std::cout << "ASMS has been initialized succesfully"<<std::endl;
     fields_t::H_an();
     fields_t::H_ex();
     fields_t::H_total();

     std::cout << "ASMS has been initialized succesfully"<<std::endl;

     int program;
     std::cout<<"Chose the program:"<<"\n";
     std::cout<<"press 1 for hysteresis loop, 2 for time series, 3 for laser pulse  "<<std::endl;
     std::cin>>program;

     if (program == 1){
     program::hysteresis();}

     else if(program == 2){
     program::time_series();}

     else {std::cout << "Invalid program!"<< std::endl;}
    
    return 0;
}
