#include "MyStringOper.h"
#include <iostream>
#include <string.h>

using namespace std;

MyStringOper::MyStringOper()
{
    //ctor
}

MyStringOper::~MyStringOper()
{
    //dtor
}

MyStringOper::MyStringOper(const MyStringOper& other)
{
    //copy ctor
}

MyStringOper& MyStringOper::operator=(const MyStringOper& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
