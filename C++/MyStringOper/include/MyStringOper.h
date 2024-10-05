#include <iostream>
using namespace std;
//acest fisier contine definitia clasei!
//fara implementarea metodelor
//se utilizeaza directivele #ifndef si #define
//pentru a evitarea declararea multipla a clasei in cadrul
//aceluiasi proiect!

//daca se include de mai multe ori cu #include "MyStringOper.h",
//intrucat efectul acestei includeri este pur si simplu copierea codului
//fisierul .h in fisierul curent, pot aparea declarari multiple!

#ifndef MYSTRINGOPER_H
#define MYSTRINGOPER_H

class MyStringOper
{
    public:
        MyStringOper();
        MyStringOper(char*);
        MyStringOper(const MyStringOper& other);

        virtual ~MyStringOper();
        //operator de atribuire
        MyStringOper& operator=(const MyStringOper& other);

        friend istream& operator>>(istream&, MyStringOper&);
        friend ostream& operator<<(ostream&, MyStringOper&);

        //alti operatori!
        MyStringOper operator+(const MyStringOper&)const;
        MyStringOper operator+(char ch)const;
        friend MyStringOper operator+(char ch, const MyStringOper&);
        MyStringOper operator+(int value)const;
        MyStringOper operator+(double value)const;
        friend MyStringOper operator+(int value, const MyStringOper&);
        friend MyStringOper operator+(double value, const MyStringOper&);
        bool operator==(const MyStringOper&)const;
        //relatie de ordine lexicografica
        bool operator<(const MyStringOper&)const;
        //reverse
        MyStringOper& operator!(); //se modifica *this (obiectul curent)
        char operator[](int position)const; //obtine caracterul de la position

    private:
        char* _elem;
        int _size;
};

#endif // MYSTRINGOPER_H
