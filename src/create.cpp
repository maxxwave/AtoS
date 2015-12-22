#include <iostream>
#include <vector>
#include "../hdr/create.h"
#include "../hdr/mat.h"
#include "../hdr/storage.h"

namespace  create{
    int index=0;
    void single_spin();
    void create_sc();
    void create_bcc();
    //so on
//case 0    
        void single_spin(){
        index = 1;
        st::atom.resize(index);
        //initializing the spin
        for (int i=0; i<index; i++ ){
	st::atom[i].sx = 0.1;
	st::atom[i].sy = 0.2;
	st::atom[i].sz = 0.87;
	st::atom[i].cx = index;
	st::atom[i].cy = index;
	st::atom[i].cz = index;
        }//end of for loop

            std::cout << "The single spin has been created!";
        }// end of single spin

//case 1
        void create_sc(){
	int  A = int (mat::x_size*10/mat::a);
	int  B = int (mat::y_size*10/mat::b);
        int  C = int (mat::z_size*10/mat::c);
	//calcuating no of atoms
        mat::N = A * B * C;
        //std::cout<<N;
	//std::vector <mat::atoms::atom_t> st::atom(N);
  	st::atom.resize(mat::N);
        // int st::index=0;
	for (int i=0; i < A; i++){
		for (int j=0; j < B; j++){
			for (int k=0; k < C; k++){
			st::atom[index].sx = 0.1;
			st::atom[index].sy = 0.02;
			st::atom[index].sz = 0.9;
			st::atom[index].cx = mat::a * i;
			st::atom[index].cy = mat::b * j;
			st::atom[index].cz = mat::c * k;
		        index++;
			}// end of k for
		}//end of j for
	}//end of i for

        std::cout << "The system contains " <<"\t"<< index <<"\t"<<"atoms"<<std::endl;
        } // end of void create
}//end of create namespace

