#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
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
    std::cout << "ASMS code has been developed by MSc Razvan V Ababei according to Atomistic spin model simulations of magnetic nanomaterials"<<std::endl;
    std::cout << "========================================================================================================================================="<<std::endl;
    std::cout << "\n";
    std::cout << "This code is free but no warranty! For any queries or suggestions please contact the author!"<<std::endl;
    std::cout << "email address: rva502@york.ac.uk"<<std::endl;
    std::cout << "========================================================================================================================================="<<std::endl;
    std::cout << "ASMS HAS STARTED TO RUN" <<std::endl;
     create::create_sc();
    std::cout << "ASMS has been initialized succesfully"<<std::endl;
     fields_t::H_an();
     fields_t::H_ex();
     fields_t::H_total();
     program::hysteresis();

    return 0;
}
