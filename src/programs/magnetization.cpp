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
         std::ofstream output("output", std::ios_base::app | std::ios_base::out);
       for(int i=0; i < create::index; i++){
           Mx += st::atom[i].sx;
           My += st::atom[i].sy;
           Mz += st::atom[i].sz;
       //output << Mx/sqrt(Mx*Mx + My*My + Mz*Mz) << "\t" << My/sqrt(Mx*Mx + My*My + Mz*Mz)  << "\t" << Mz/sqrt(Mx*Mx + My*My + Mz*Mz)  << "\t" << st::H_applied[2] << "\n";
       }
      output << Mx/sqrt(Mx*Mx + My*My + Mz*Mz) << "\t" << My/sqrt(Mx*Mx + My*My + Mz*Mz)  << "\t"
             << Mz/sqrt(Mx*Mx + My*My + Mz*Mz) << "\t" << sqrt(Mx*Mx + My*My + Mz*Mz) <<"\t"<<st::H_applied[2] << std::endl;
      std::cout << Mx/sqrt(Mx*Mx + My*My + Mz*Mz) << "\t" << My/sqrt(Mx*Mx + My*My + Mz*Mz)  << "\t" << Mz/sqrt(Mx*Mx + My*My + Mz*Mz)  << "\t" << st::H_applied[2] << "\n";
       output.close();
    }//end of void
}//end of namespace
