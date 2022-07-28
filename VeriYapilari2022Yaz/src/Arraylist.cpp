

#include "Arraylist.hpp"
#include <iostream>

Arraylist::Arraylist() {

    length = 0;
    capacity = 0;
    items = 0;



}

void Arraylist::reverse(int newCapacity) {
    if (capacity >= newCapacity) return; //yeni kapasite eskisinden kucukse hicbirsey yapmaz
    char *tmp = new char[newCapacity]; //tmp degiskenine daha buyuk kapasiteli dizi olusturulur
    for (int i = 0; i < length; i++) { //items 'in icindeki veri tmp dizisine kopyalanir
        tmp[i] = items[i];
    }
    if (items != 0) { //items dizisi degil ise silinir heap bellekte cop olusmamasi icin
        delete[] items;
    }
    items = tmp; //gecici dizinin adresi items degikenine atanir
    capacity = newCapacity; //kapasite bilgisi yenilenir


}

void Arraylist::add(char item) { //dizinin sonuna ekleme yapar

    insert(length, item);
}

void Arraylist::putAt(int i, char item) {//diziye eleman koyar
    if (items == NULL) {
        throw "hata";
    }
    if (i < 0 || i > length) throw "hata";

    items[i] = item;
}

void Arraylist::insert(int i, char item) {//dizi icine ekme yapar

    if (i < 0 || i > length) throw "hata";
    if (length >= capacity)

        if (capacity) { //capacity sifirsa birden baslatiyor
            reverse(2 * capacity);
        } else {

            reverse(1);
        }
    for (int j = length - 1; j >= i; j--) {
        items[j + 1] = items[j]; //dizi i den itibaren bir saga kaydirilir
    }
    items[i] = item;
    length++;
}

int Arraylist::size() const //dizini boyutunu verir
{
    return length;
}

bool Arraylist::isEmpty() const //diziyi bos mu diye kontorl eder
{
    return size() == 0;
}

char Arraylist::elementAt(int i) {//indisteki elemani getirir
    if (i < 0 || i >= length) {
        throw "indeks disinda";
    }
    return items[i];
}

void Arraylist::removeAt(int i) {//belirtilen indisteki elemani siler
    if (i < 0 || i >= length) {
        throw "indeks disinda";
    }

    for (int j = i + 1; j < length; j++) items[j - 1] = items[j];
    length--;
}

void Arraylist::clear() {//diziyi sifirlar
    length = 0;
}

void Arraylist::reverseArr() {//diziyi tersine cevirir
    int temp;
    for (int i = 0; i < length / 2; i++) {
        temp = items[i];
        items[i] = items[length - i - 1];
        items[length - i - 1] = temp;
    }

}

Arraylist::~Arraylist() {

    if (items != NULL) {

        delete[] items;
    }
}
