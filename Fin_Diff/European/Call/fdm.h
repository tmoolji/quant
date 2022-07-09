//Author: Taimur Moolji
//Date: Jun 23 2022
//Exercise from : https://www.quantstart.com/articles/C-Explicit-Euler-Finite-Difference-Method-for-Black-Scholes/

#ifndef __FDM_H
#define __FDM_H

#include "pde.h"
#include <vector>

//Finite difference Method - Abstract Base Class
class FDMBase{
protected:
  ConvectionDiffusionPDE* pde;

  //Space discretisation
  double x_dom; // Spatial extent - ranges from 0.0 to x_dom inclusive
  unsigned long J; // Number of spatial differencing points (how many breaks)
  double dx; //step size (x_dom / J)
  std::vector<double> x_values; //coordinates of the x values


  //time discretisation
  double t_dom; //temporal extent
  unsigned long N; // breaks
  double dt; // step size (t_dom / N)

  //Time marching
  double prev_t, cur_t;

  //Differencing coefficients
  double alpha, beta, gamma;

  //Storage
  std::vector<double> new_result; //New solution (becomes N+1)
  std::vector<double> old_result; //Old soluton (becomes N)

  //Constructor
  FDMBase(double _x_dom, unsigned long _J, double _t_dom,
     unsigned long _N, ConvectionDiffusionPDE* _pde);

  //Override for specific techniques
  virtual void calculate_step_sizes() = 0;
  virtual void set_initial_conditions() = 0;
  virtual void calculate_boundary_conditions() = 0;
  virtual void calculate_inner_domain() = 0;

public:
  virtual void step_march() = 0;
};


class FDMEulerExplicit : public FDMBase {
protected:
  void calculate_step_sizes();
  void set_initial_conditions();
  void calculate_boundary_conditions();
  void calculate_inner_domain();

public:
  FDMEulerExplicit(double _x_dom, unsigned long _J, double _t_dom,
     unsigned long _N, ConvectionDiffusionPDE* _pde);

  void step_march();
};

#endif
