

/* 
 * File:   Arraylist.hpp
 * Author: HAKAN KIRIK
 *
 * Created on July 25, 2022, 10:06 PM
 */

#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP


class Arraylist{
public:
    Arraylist();
    void add( char item);//dizinin sonuna eleman ekler
    void insert(int i, char item);//dizin istelilen indisine eleman ekler
    int size() const;//dizini boyutunu verir
    bool isEmpty() const;//diziyi bos mu diye kontrol eder
    char elementAt(int i) ;//belirtilen indisteki elemani verir
    void removeAt(int i);//belirtilen indisteki elemani siler 
    void clear();//diziyi sifirlar
    void putAt(int ,char);//dizinin istenilen yerine eleman koyar  insertten farki indisteki elemanin uzerine yaziliyor olmasi
    void reverseArr();//diziyi tersine cevirir
    ~Arraylist();
    
private:
    char *items;
    int length;
    int capacity;
    void reverse(int);//yeni alan olusturur
};


#endif /* ARRAYLIST_HPP */

