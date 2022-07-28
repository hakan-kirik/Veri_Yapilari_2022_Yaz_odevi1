
/* 
 * File:   factorial.hpp
 * Author: HAKAN KIRIK
 *
 * Created on July 27, 2022, 10:52 PM
 */
#include "bigDecimal.hpp"

#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP

class Factorial{
public:
    Factorial(int);
    BigDecimal* getResult();
    ~Factorial();
private:
    void calculateFact(int num);//factorial hesaplar
    BigDecimal * result;
};


#endif /* FACTORIAL_HPP */

