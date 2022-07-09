//Author: Taimur Moolji
//Date: Jun 22 2022
//Exercise from : https://www.quantstart.com/articles/C-Explicit-Euler-Finite-Difference-Method-for-Black-Scholes/

#ifndef __PAY_OFF_CPP
#define __PAY_OFF_CPP

#include "payoff.h"

PayOff::PayOff() {}

// Constructor with single strike parameter
PayOffCall::PayOffCall(const double& _K) { K = _K; }

// Over-ridden operator() method, which turns PayOffCall into a function object
double PayOffCall::operator() (const double& S) const {
  return std::max(S-K, 0.0); // Standard European call pay-off
}

// Constructor with single strike parameter
PayOffPut::PayOffPut(const double& _K) {
  K = _K;
}

// Over-ridden operator() method, which turns PayOffPut into a function object
double PayOffPut::operator() (const double& S) const {
  return std::max(K-S, 0.0); // Standard European put pay-off
}

#endif
