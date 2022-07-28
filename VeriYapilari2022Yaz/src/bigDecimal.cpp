

#define CHARTOINT 48    //'0' in ascii karsiligi
#define INTTOCHAR 48
#include "bigDecimal.hpp"

#include <iostream>

BigDecimal::BigDecimal(string number) {//parametreli constructor
    bigNumber = new Arraylist();

    for (int i = 0; i < number.length(); i++) {
        bigNumber->add(number[i]);
    }
}

BigDecimal::BigDecimal(int times, string number) {//terarli sayi constructori
    bigNumber = new Arraylist();

    for (int i = 0; i < times; i++) {
        for (int j = 0; j < number.length(); j++) {
            bigNumber->add(number[j]);
        }

    }
}

BigDecimal::BigDecimal() { //parametresiz constructor
    bigNumber = new Arraylist();

}

BigDecimal BigDecimal::operator+(BigDecimal &otherNum) {
    //bu fonsiyon odevden bagimsiz olarak yazilmistir
    //iki BigDecimal sayiyi toplar
    //sadece toplama yapar eksili sayilari toplamaz

    BigDecimal tmp;
    BigDecimal bigSumNum; //toplanacaklarin en buyugu


    int minDigit = 0; //toplayacagimiz sayilardaki en dusuk basakli sayi
    int carry = 0; //elde 

    if (bigNumber->size() > otherNum.bigNumber->size()) {
        bigSumNum.bigNumber = bigNumber;
        minDigit = otherNum.bigNumber->size();
    } else {
        bigSumNum.bigNumber = (otherNum.bigNumber);
        minDigit = bigNumber->size();
    }

    int i = 1;
    int j = bigSumNum.bigNumber->size();

    for (; j > 0 || carry != 0; i++, j--) {//eldeli toplama yapar
        if (i <= minDigit) {

            int tmpNum1 = bigNumber->elementAt(bigNumber->size() - i) - CHARTOINT; //char olan sayiyi int yapar
            int tmpNum2 = otherNum.bigNumber->elementAt(otherNum.bigNumber->size() - i) - CHARTOINT; //diger sayiyi int yapar


            tmp.bigNumber->insert(0, ((((tmpNum1 + tmpNum2) % 10) + carry) % 10) + INTTOCHAR); //int olan sayiyi char olarak tmp ye aktarir
            carry = (tmpNum1 + tmpNum2 + carry) / 10; //elde 


        } else if (i <= bigSumNum.bigNumber->size()) {

            int tmpNum1 = bigSumNum.bigNumber->elementAt(bigSumNum.bigNumber->size() - i) - CHARTOINT;

            tmp.bigNumber->insert(0, ((((tmpNum1) % 10) + carry) % 10) + INTTOCHAR);
            carry = (tmpNum1 + carry) / 10;

        } else {

            tmp.bigNumber->insert(0, carry + INTTOCHAR);
            carry = 0;

        }

    }
    return tmp;
}

BigDecimal* BigDecimal::operator*=(BigDecimal& num1) {
    //iki buyuk sayiyi odeve gore carpar
    //bu fonksiyon geeksforgeeks.org tan esinlenerek yazilmistir

    //sayilarin uzunluklari
    int len1 = num1.bigNumber->size();
    int len2 = this->bigNumber->size();


    //sonuc degiskeninin tanimlasi
    BigDecimal *result = new BigDecimal(len1 + len2, "0");

    if (len1 == 0 || len2 == 0) {//bos sayi gelirse sifir dondurur
        delete result;
        result = new BigDecimal("0");
        return result;
    }

    //carpim sayilarinin kaydirilmasi icin kullanilan degiskenler
    int i_n1 = 0;
    int i_n2 = 0;

    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0; //elde
        int n1 = num1.bigNumber->elementAt(i) - CHARTOINT; //sayinin basmaginin n1 e atanmasi

        i_n2 = 0;

        for (int j = len2 - 1; j >= 0; j--) {

            int n2 = this->bigNumber->elementAt(j) - CHARTOINT; //sayinin basamagi n1 e atanmasi

            int sum = (n1 * n2) + (result->bigNumber->elementAt(i_n1 + i_n2) - CHARTOINT) + carry; //eldeli bir sekilde basamaklarin toplanmasi

            carry = sum / 10; //elde kisminin ayrilmasi

            result->bigNumber->putAt(i_n1 + i_n2, (sum % 10) + INTTOCHAR); //degerin sonucun icine konmasi
            i_n2++; //diger basamaga gecer

        }
        //elde 0 degilse onuda sayiya ekler
        if (carry > 0) {
            int num = result->bigNumber->elementAt(i_n1 + i_n2) - CHARTOINT;
            result->bigNumber->putAt(i_n1 + i_n2, (num + carry) + CHARTOINT);
        }
        //i_n1++;//  komutu acildiginda gercek bir carpma yapar
        //yukaridaki komut carpma islemindeki bir sola kaydirma islemine denk gelir 

    }

    //sonucu tersine cevirme
    result->bigNumber->reverseArr();
    //sonucun icindeki sifirlardan arinma
    //faktoriyal hesaplarken bellek tasmalarina sebep oldugundan
    //sifirdan arindirma kodu kaldirilip factoriyal class'inda yapildi
    /*int count1 = 0;
    int z = 0;
    while (z < result->bigNumber->size()) {

        if (result->bigNumber->elementAt(z) - 48 != 0) {


            count1 = z;
            break;

        }
        z++;
    }
    if (count1 == result->bigNumber->size()) {
        delete result;
        result = new BigDecimal("0");
        count1 = -1;
    }

    while (count1 > 0) {
        result->bigNumber->removeAt(0);
        count1--;
    }*/
     

    return result;
}

BigDecimal::~BigDecimal() {

    if (this->bigNumber != NULL) {
        delete this->bigNumber;
    }
}

ofstream& operator<<(ofstream& myfile, BigDecimal& right) {//dosyaya yazma fonksiyonu

    for (int i = 0; i < right.bigNumber->size(); i++) {
        myfile << right.bigNumber->elementAt(i);

    }
    return myfile;
}
