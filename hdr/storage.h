#include <iostream>
#include <vector>
#include "template.h"
#ifndef __STORAGE
#define __STORAGE
namespace st{
   extern std::vector <template_t::H_internal> H_int;
   extern std::vector <template_t::H_internal> H_ani;
   extern std::vector <template_t::H_internal> H_ex;
   extern std::vector <template_t::H_internal> H_dip;
   extern std::vector <template_t::H_internal> H_i;
   extern std::vector <template_t::H_internal> H_k;
   extern std::vector <double> H_applied;
   extern std::vector <template_t::H_internal> H_total;
   extern std::vector <template_t::atom> atom;
   extern std::vector <template_t::atom> atom_k;
}
#endif 
