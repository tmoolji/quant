//Author: Taimur Moolji
//Date: Jun 22 2022
//Exercise from : https://www.quantstart.com/articles/C-Explicit-Euler-Finite-Difference-Method-for-Black-Scholes/

#ifndef __PDE_CPP
#define __PDE_CPP

#include "pde.h"
#include <math.h>

BlackScholesPDE::BlackScholesPDE(VanillaOption* _option){
  option = _option;
}


//Diffusion coefficient
//Coeff on gamma
double BlackScholesPDE::diff_coeff(double t, double x) const {
  double vol = option->sigma;
  return 0.5*vol*vol*x*x; // \frac{1}{2} \ sigma^2 S^2
}

//Diffusion coefficient
//Coeff on delta
double BlackScholesPDE::conv_coeff(double t, double x) const {
  return (option->r)*x; //rS
}

//Zero-term coefficient
//Coefficient for discounting
double BlackScholesPDE::zero_coeff(double t, double x) const {
  return -(option->r); // -r
}

//Source coefficient
double BlackScholesPDE::source_coeff(double t, double x) const {
  return 0.0;
}

double BlackScholesPDE::boundary_left(double t, double x) const {
  return 0.0; // this is for a call
}

double BlackScholesPDE::boundary_right(double t, double x) const {
  //difference between spot and option strike discounted for T - t (call)
  return (x-(option->K)*exp(-(option->r)*((option->T) - t)));
}

double BlackScholesPDE::init_cond(double x) const {
  return option->pay_off->operator()(x); //initial condition for a vanilla call
}

#endif
