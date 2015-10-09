#include <iostream>
#include "create.h"
#include "mat.h"
#include "template.h"
#ifndef __FIELDS
#define _FIELDS
namespace fields_t{
//    extern double rij[create::index][create::index];
/*    extern struct Wij_t{
                double xx;
                double xy;
                double xz;
                double yx;
                double yy;
                double yz;
                double zx;
                double zy;
                double zz;};
 //   extern std::vector <fields_t::Wij_t> Wij;*/
    extern int no_rad;
   // extern std::vector <fields_t::Wij_t> Wk;
    extern int H_an();
    extern int H_ex();
    extern int H_app();
    extern int H_dip();
    extern int H_total();
}
#endif
