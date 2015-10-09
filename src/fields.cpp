//author: Razvan V. Ababei
//date: azi
//////////////////////////
#include <iostream>
#include <vector>
#include <cmath>
#include <fftw3.h>
#include <stdio.h>
#include <cstdlib>

//include ASMS headers
#include "../hdr/storage.h"
#include "../hdr/template.h"
#include "../hdr/mat.h"
#include "../hdr/create.h"
#include "../hdr/fields.h"
#include "../hdr/integrator.h"

namespace fields_t{
struct Wij_t{
      double xx;
      double xy;
      double xz;
      double yx;
      double yy;
      double yz;
      double zx;
      double zy;
      double zz;};





int  H_an(){
	//we leave from assumption that the anisotropy is perpendicular, therefore easy axis it is along z direction
	//defining local anisotropy field
	st::H_ani.resize(create::index);

	for (int i=0; i<create::index; i++){
	    st::H_ani[i].x=0.0;
	    st::H_ani[i].y=0.0;
	    st::H_ani[i].z =- 2.0 * mat::ku * st::atom[i].sz/9.274e-24;
        } //end of for loop
	return 0;
	}

int H_ex(){
	//we have 3 cases
	// first of all is isotropic, Jij -constant
	//case 1
        st::H_ex.resize(create::index);
	for (int i=0; i<create::index; i++){
            st::H_ex[i].x -= Ex::Jij * st::atom[i].sx;
            st::H_ex[i].y -= Ex::Jij * st::atom[i].sy;
            st::H_ex[i].z -= Ex::Jij * st::atom[i].sz;
        }//end of for loop
	// We need to update for other cases
	return 0;
	}
/*
int H_app(){
	std::vector <fields::H_applied> H_app(0.0);
}*/
/*
int H_dip(){

        int no_rad=1;
       fftw_complex std::vector<fields_t::Wij_t> Wij, std::vector<fields_t::Wij_t> Wk;
        //calcuate the distances between atoms in real space
        double rij[create::index][cretae::index]={};
        for (int i,j=0; i,j<create::index; i,j++){
            if(i!=j){
            rij[i][j] = sqrt( (st::atom[i].cx - st::atom[j].cx)*(st::atom[i].cx - st::atom[j].cx) +
                              (st::atom[i].cy - st::atom[j].cz)*(st::atom[i].cy - st::atom[j].cy) +
                              (st::atom[i].cz - st::atom[j].cz)*(st::atom[i].cz - st::atom[j].cz))

             Wij[no_rad].xx.push_back(-1/rij[i][j]);
             Wij[no_rad].xy.push_back(0);
             Wij[no_rad].xz.push_back(0);
             Wij[no_rad].yx.push_back(0;
             Wij[no_rad].yy.push_back(-1/rij[i][j]);
             Wij[no_rad].yz.push_back(0);
             Wij[no_rad].zx.push_back(0);
             Wij[no_rad].zy.push_back(0);
             Wij[no_rad].zz.push_back(-2/rij[i][j]);

             no_rad++;
            }//end of if
        }//end of for


}//end of H_dip()
*/
int H_total(){
    st::H_applied.resize(3,0);
    st::H_total.resize(create::index);
    for  (int i=0; i<create::index; i++){
        st::H_total[i].x = st::H_ani[i].x + st::H_ex[i].x + st::H_applied[0];//create::index; // + others
        st::H_total[i].y = st::H_ani[i].z + st::H_ex[i].y + st::H_applied[1];//create::index; // + others
        st::H_total[i].z = st::H_ani[i].z + st::H_ex[i].z + st::H_applied[2];//create::index; // + others
    }
    return 0;
}//end of H_total

}//end of fields_t namespace

