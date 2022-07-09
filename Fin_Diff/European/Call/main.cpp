//Author: Taimur Moolji
//Date: Jun 22 2022
//Exercise from : https://www.quantstart.com/articles/C-Explicit-Euler-Finite-Difference-Method-for-Black-Scholes/

#include "payoff.h"
#include "option.h"
#include "pde.h"
#include "fdm.h"

int main(int argc, char ** argv) {
  double K = 0.5; //Strike
  double r = 0.05; //risk free rate
  double v = 0.2; //volatility
  double T = 1.00; //years

  //FDM paramters

  double x_dom = 1.0; //underlying price ranges from 0 to 1
  unsigned long J = 20;
  double t_dom = T;
  unsigned long N = 20;

  PayOff* pay_off_call = new PayOffCall(K);
  VanillaOption* call_option = new VanillaOption(K, r, T, v, pay_off_call);

  BlackScholesPDE* bs_pde = new BlackScholesPDE(call_option);
  FDMEulerExplicit* f = new FDMEulerExplicit(x_dom, J, t_dom, N, bs_pde);

  f->step_march();

  delete bs_pde;
  delete call_option;
  delete pay_off_call;

  return 0;

}
