//Author: Taimur Moolji
//Date: Jun 22 2022
//Exercise from : https://www.quantstart.com/articles/C-Explicit-Euler-Finite-Difference-Method-for-Black-Scholes/

#ifndef __PAY_OFF_CPP
#define __PAY_OFF_CPP

#include "payoff.h"

PayOff::PayOff() {}

// Define call class


//Call Constructor
//param: _K - Strike
PayOffCall::PayOffCall(const double& _K) {
  K = _K;
}

//Overridden operator() - returns payoff
//param S - Stock Price
double PayOffCall::operator()(const double& S) const {
  return std::max(S-K, 0.0);
}

//Put Constructor
//param: _K - Strike
PayOffPut::PayOffPut(const double& _K) {
  K = _K;
}

//Overridden operator() - returns payoff
//param S - Stock Price
double PayOffPut::operator()(const double& S) const {
  return std::max(K-S, 0.0);
}

#endif
