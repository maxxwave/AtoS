#include <iostream>
#include <vector>
#include <cstdlib>
#include "template.h"
#include "times.h"
#ifndef __INTEGRATOR__
#define __INTEGRATOR__
namespace integrator{
    extern double B1;
    extern double B2;
    extern std::vector<template_t::atom> DS;
    extern std::vector<template_t::atom> DS_prime;
    extern std::vector<template_t::atom> S_prime;
    extern std::vector<template_t::atom> S_par;
    extern std::vector<template_t::atom> S_initial;
    extern std::vector<template_t::atom> S_tot;
    extern void LLG();
    //extern void Cayley_method();
    extern void LLB();
    extern void MonteCarlo();
    
}
#endif


