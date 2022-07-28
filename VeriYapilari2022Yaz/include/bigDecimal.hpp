

/* 
 * File:   bigDecimal.hpp
 * Author: HAKAN KIRIK
 *
 * Created on July 26, 2022, 2:00 PM
 */

#ifndef BIGDECIMAL_HPP
#define BIGDECIMAL_HPP

#include <string>
#include <fstream>
#include "Arraylist.hpp"
using namespace std;
class BigDecimal{
    
public:
    //bigDecimal kurucu fonksiyonlar
    BigDecimal(string number);
    BigDecimal();
    BigDecimal(int,string);
    
    BigDecimal operator +(BigDecimal  &otherNum);//iki BigDecimali toplar
    BigDecimal* operator *=(BigDecimal&);//iki BigDecimali odevde belirtildigi gibi carpar
    friend ofstream& operator<<(ofstream& myfile,BigDecimal& right);//dosyaya yazma arkadas fonksiyonu
    
    Arraylist *bigNumber;
    ~BigDecimal();

    
};


#endif /* BIGDECIMAL_HPP */

