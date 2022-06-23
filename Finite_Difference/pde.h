//Author: Taimur Moolji
//Date: Jun 22 2022
//Exercise from : https://www.quantstart.com/articles/C-Explicit-Euler-Finite-Difference-Method-for-Black-Scholes/

#ifndef __PDE_H
#define __PDE_H

#include "option.h"

//2nd order PDE aka "Convection Diffusion PDE"
class ConvectionDiffusionPDE {
  public:
    //PDE coefficients
    virtual double diff_coeff(double t, double x) const = 0;
    virtual double conv_coeff(double t, double x) const = 0;
    virtual double zero_coeff(double t, double x) const = 0;
    virtual double source_coeff(double t, double x) const = 0;

    //Boundary + initial conditions
    virtual double boundary_left(double t, double x) const = 0;
    virtual double boundary_right(double t, double x) const = 0;
    virtual double init_cond(double x) const = 0;

}

// Black Scholes subclass
class BlackScholesPDE : public ConvectionDiffusionPDE {
  public:
    VanillaOption* option;
    BlackScholesPDE(VanillaOption* _option);

    double diff_coeff(double t, double x) const = 0;
    double conv_coeff(double t, double x) const = 0;
    double zero_coeff(double t, double x) const = 0;
    double source_coeff(double t, double x) const = 0;

    double boundary_left(double t, double x) const = 0;
    double boundary_right(double t, double x) const = 0;
    double init_cond(double x) const = 0;

}

#endif
