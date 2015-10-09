#include <iostream>
#include <vector>

#ifndef __MAT
#define __MAT

namespace mat{
    //dimensions
    extern double x_size;
    extern double y_size;
    extern double z_size;
    //lattice parameters
    extern double a;
    extern double b;
    extern double c;
    
    extern unsigned int N; //no of atoms
    extern unsigned int n; //sorts of atoms
    //material constants
    extern double ku;
    extern double mu_s;
    //damping constant
    extern double alpha;
    extern double gyro;
}

namespace Ex{
    //case 0: Jij-scalar; isotropic case
    extern double Jij;
    

   //case 1: Jij-vector
   //case 2: Jij-tensor
}//end of namespace Exchange 
#endif 
