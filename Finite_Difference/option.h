//Author: Taimur Moolji
//Date: Jun 22 2022
//Exercise from : https://www.quantstart.com/articles/C-Explicit-Euler-Finite-Difference-Method-for-Black-Scholes/

#ifndef __VANILLA_OPTION_H
#define __VANILLA_OPTION_H

#include "payoff.h"

class VanillaOption{
public:
  PayOff* pay_off;

  double K; //Strike
  double r; //interest rate
  double T; //Time
  double sigma; //Volatility

  VanillaOption();
  VanillaOption(double _K, double _r, double _T, double _sigma, PayOff* _pay_off)

};

#endif
