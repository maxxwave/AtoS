#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include "../../hdr/storage.h"
#include "../../hdr/mat.h"
#include "../../hdr/template.h"
#include "../../hdr/create.h"
#include "../../hdr/magnetization_out.h"
namespace magnetization{
    void magnetization_out(){
        double Mx=0;
        double My=0;
        double Mz=0;
         std::ofstream output;
         output.open("output.dat");
       for(int i=0; i < create::index; i++){
           Mx += st::atom[i].sx;
           My += st::atom[i].sy;
           Mz += st::atom[i].sz;
       }
       output << Mx << "\t" << My << "\t" << Mz << std::endl;
       //std::cout << Mx/create::index<<"\t"<< My/create::index << Mz/create::index << st::H_applied<<std::endl;
       output.close();
    }//end of void
}//end of namespace
