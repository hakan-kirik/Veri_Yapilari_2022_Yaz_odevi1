
/* 
 * File:   main.cpp
 * Author: HAKAN KIRIK
 *
 * Created on July 25, 2022, 10:06 PM
 */

#include <cstdlib>
#include <iostream>
#include "Arraylist.hpp"
#include "bigDecimal.hpp"
#include "factorial.hpp"

/*
 * 
 */
int main(int argc, char** argv) {


    ofstream MyFile("Sonuc.txt"); //Sonuc.txt dosyasini acilmasi yada olusturulmasi
    int num = 100;

    std::cout << "Lutfen faktoriyal sayisini giriniz:\n";

    std::cin>>num;

    Factorial * fact = new Factorial(num);
    MyFile << *fact->getResult(); //dosyaya factoriyal sonucunun yazilmasi

	delete fact;


    return 0;
}

