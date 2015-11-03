//This program it is another integration method described in "Condens. Matter 22(2010) 176001"
//Author: MSc. Razvan Vasile Ababei, York University
//email address: rva502@york.ac.uk
//for any queries and suggestions please contact the author
//this program it's free and can be redistribuite but without any warranty
//
//
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

//ASMS headers
#include "create.h"
#include "storage.h"
#include "mat.h"
#include "times.h"
#include "integrator.h"
#include "fields.h"
#include "template.h"
namespace integrator{

    //defining the coeficients
    double dt = times::loop_times_step;
    std::vector<template_t::atom> S_prime;
    std::vector<template_t::atom> DS_prime; 
    std::vector<template_t::atom> S_new;
    std::vector<template_t::atom> S_initial;

    void SISB(){
        //resize the vectors




}
