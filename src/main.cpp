#include <iostream>
#include <fstream>
#include <vector>

//ASMS headers
#include "../hdr/create.h"
#include "../hdr/mat.h"
//#include "../hdr/template.h"
#include "../hdr/storage.h"
#include "../hdr/fields.h"
#include "../hdr/integrator.h"
#include "../hdr/hysteresis.h"
int main(){
     create::create_sc();
     fields_t::H_an();
     fields_t::H_ex();
     fields_t::H_total();
     program::hysteresis();
    return 0;
}
