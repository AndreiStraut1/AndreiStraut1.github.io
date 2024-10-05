#include "MyStringOper.h"
#include <iostream>
#include <string.h>

using namespace std;

MyStringOper::MyStringOper()
{
    _elem = NULL;
    _size = 0;
}

MyStringOper::~MyStringOper()
{
    delete [] _elem;
    _elem = nullptr;
}

MyStringOper::MyStringOper(char* str)
{
    _size = strlen(str);
    _elem = new char[_size+1];
    strcpy(_elem, str);
}

MyStringOper::MyStringOper(const MyStringOper& other)
{
    _size = other._size;
    _elem = new char[_size+1];
    strcpy(_elem, other._elem);
}

istream& operator>>(istream& CIN, MyStringOper& str)
{
    string s;
    CIN>>s;
    str._size = s.size();
    str._elem = new char[str._size+1];
    strcpy(str._elem, s.c_str());
    cin.get(); //pentru enter-ul din buffer
    return CIN;
}

ostream& operator<<(ostream& COUT, MyStringOper& str)
{
    COUT<<str._elem<<endl;
    return COUT;
}

MyStringOper& MyStringOper::operator=(const MyStringOper& other)
{
    if (this == &other) return *this; // handle self assignment

    delete[] _elem;

    _size = other._size;
    _elem = new char[_size + 1];

    strcpy(_elem, other._elem);

    return *this;
}

MyStringOper MyStringOper::operator+(const MyStringOper& other)const
{
    MyStringOper result;
    result._size = _size + other._size;
    result._elem = new char[result._size + 1];
    strcpy(result._elem, _elem);
    strcat(result._elem, other._elem);
    return result;
}

MyStringOper MyStringOper::operator+(char ch)const
{
    MyStringOper result;
    char* str = new char[2];
    str[0] = ch;
    str[1] = '\0';

    result._size = _size + 1;
    result._elem = new char[result._size + 1];
    strcpy(result._elem, _elem);
    strcat(result._elem, str);

    return result;
}

MyStringOper operator+(char ch, const MyStringOper& other)
{
    MyStringOper result;
    char* str = new char[2];
    str[0] = ch;
    str[1] = '\0';

    result._size = other._size + 1;
    result._elem = new char[result._size + 1];
    strcpy(result._elem, str);
    strcat(result._elem, other._elem);

    return result;
}

MyStringOper MyStringOper::operator+(int value)const
{
    MyStringOper result;
    string str=to_string(value);

    result._size = _size + str.size();
    result._elem = new char[result._size + 1];
    strcpy(result._elem, _elem);
    strcat(result._elem, str.c_str());

    return result;
}

MyStringOper operator+(int value, const MyStringOper& other)
{
    MyStringOper result;
    string str=to_string(value);

    result._size = other._size + str.size();
    result._elem = new char[result._size + 1];
    strcpy(result._elem, str.c_str());
    strcat(result._elem, other._elem);

    return result;
}

MyStringOper MyStringOper::operator+(double value)const
{
    MyStringOper result;

    int maxLength = 50;
    char* str = new char[maxLength + 1];
    sprintf(str, "%.15g", value);

    result._size = _size + strlen(str);
    result._elem = new char[result._size + 1];
    strcpy(result._elem, _elem);
    strcat(result._elem, str);

    return result;
}

MyStringOper operator+(double value, const MyStringOper& other)
{
    MyStringOper result;

    int maxLength = 50;
    char* str = new char[maxLength + 1];
    sprintf(str, "%.15g", value);

    result._size = other._size + strlen(str);
    result._elem = new char[result._size + 1];
    strcpy(result._elem, str);
    strcat(result._elem, other._elem);

    return result;
}

bool MyStringOper::operator==(const MyStringOper& other)const
{
    if(_size != other._size)
        return 0;
    else if(strcmp(_elem, other._elem)==0)
        return 1;
    return 0;
}

bool MyStringOper::operator<(const MyStringOper& other)const
{
    if(strcmp(_elem, other._elem) < 0)
        return 1;
    return 0;
}

MyStringOper&  MyStringOper::operator!()
{
    for(int i=0; i<_size/2; i++)
        swap(_elem[i], _elem[_size-1-i]);
    return *this;
}

char MyStringOper::operator[](int position)const
{
    if(position < _size)
        return _elem[position];
}
