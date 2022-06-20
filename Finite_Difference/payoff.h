//Author: Taimur Moolji
//Date: Jun 20 2022
//Exercise from : https://www.quantstart.com/articles/C-Explicit-Euler-Finite-Difference-Method-for-Black-Scholes/

#ifndef __PAY_OFF_HPP
#define __PAY_OFF_HPP

#include <algorithm>

class PayOff {
    public:
        PayOff();
        virtual ~PayOff() {} ;

        virtual double operator()(const double& S) const = 0; // overloading the () operator

};

class PayOffCall : public PayOff {
    private:
        double K; //Strike
    
    public:
        PayOffCall(const double& _K);
        virtual ~PayOffCall() {};
        virtual double operator() (const double& S) const;
}

class PayOffPut : public PayOff {
    private:
        double K; //Strike
    
    public:
        PayOffPut(const double& _K);
        virtual ~PayOffPut() {};
        virtual double operator() (const double& S) const;
}


#endif