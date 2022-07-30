

#include "factorial.hpp"
#include <string>

Factorial::Factorial(int num) {
    calculateFact(num);
}

BigDecimal * Factorial::getResult() {
    return result;
}

void Factorial::calculateFact(int num) {//faktoriyal hesaplar

    BigDecimal *factorial = new BigDecimal(std::to_string(num));
    BigDecimal *oldValue;

    if (num <= 0) {
        delete factorial ;
        factorial=new BigDecimal("1");
        result =factorial;
        return;

    } else {
        for (int i = num-1; i >=1 ; --i) {
            BigDecimal * tmpNum = new BigDecimal(std::to_string(i)); //bir sonraki sayi 
            oldValue = factorial;
            factorial =*oldValue*=*tmpNum;
            delete oldValue; //cop olusmamasi icin eski deger silinir

            delete tmpNum; //sayinin silinmesi
        }



    }
    

    int count1 = 0; //sonucun basindaki 0 sayisi

    for (int z = 0; z < factorial->bigNumber->size(); z++) { //sonucun basindaki 0 sayisini bulur

        if (factorial->bigNumber->elementAt(z) != '0') {
            count1 = z;
            break;

        }

    }
    if (count1 == factorial->bigNumber->size()) {//sonuc sifir ise tek sifir yapar
        delete factorial;
        factorial = new BigDecimal("0");
        count1 = -1;
    }

    while (count1 > 0) {//sayinin basindaki sifirlari temizler
        factorial->bigNumber->removeAt(0);
        count1--;
    }

    result = factorial;
}

Factorial::~Factorial(){
	if(result!=NULL) delete result;
}
