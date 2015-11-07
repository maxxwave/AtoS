#include <iostream>
#include <vector>
#include "../hdr/mat.h"

namespace mat{
    //dimensions in nm
     double x_size =1;
     double y_size =1;
     double z_size =1;
    //lattice parameters in A
     double a=3.429;
     double b=3.429;
     double c=3.429;

     unsigned int N; //no of atoms
     unsigned int n; //sorts of atoms
    //material constants
     double ku = 2.2e-22;//Joules
     double mu_s = 1.9; //muB
    //damping
    double alpha = 0.01;
    double gyro = 1.760859708*1e11;
}
//exchange matrix values
namespace  Ex{
    // case 1: Jij-scalar-isotropic case
    double Jij = 7.05e-27; //Joules/link 
    //other cases
}

