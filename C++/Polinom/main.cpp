#include <iostream>
#include <math.h>
using namespace std;

//sa se implementeze o clasa Polinom
//cu supraincarcare operatori

class Polinom
{
public:
    //constructori si destructor
    Polinom();
    Polinom(int, double*);
    Polinom(const Polinom&);
    ~Polinom();
    //expresii valide:
    //cout<<p1<<p2 - afisare
    friend ostream& operator<<(ostream&, Polinom&);
    //cin>>p1>>p2 - citire
    friend istream& operator>>(istream&, Polinom&);
    //p1+p2 - suma a doua polinoame
    Polinom operator+(const Polinom&) const;
    //p1+2.5 - suma Polinom + double
    Polinom operator+(const double&) const;
    //2.5+p1 - suma double + Polinom
    friend Polinom operator+(const double, const Polinom&);
    //p1*p2 - produsul a doua polinoame
    Polinom operator*(const Polinom&) const;
    //p1*2.5 (toti coeficientii sunt inmultiti cu acest scalar)
    Polinom operator*(const double) const;
    //2.5*p1
    friend Polinom operator*(const double, const Polinom&);
    //p1[2.5] - calculul valorii in punctul 2.5, adica P(2.5)
    double operator[](const double) const;
    // !p1 - derivata de ordin 1 a polinomului
    friend Polinom operator!(const Polinom&);
private:
    int _grad;
    double* _coef; //coeficienti alocare dinamica de dim. _grad+1
};

Polinom::Polinom()
{
    _grad=0;
    _coef=NULL;
}

Polinom::Polinom(int grad, double* coef)
{
    _grad=grad;
    _coef = new double[_grad+1];
    for(int i=_grad; i>=0; i--)
    {
        _coef[i] = coef[i];
    }
}
Polinom::Polinom(const Polinom& other)
{
    _grad = other._grad;
    _coef = new double[_grad+1];
    for(int i=_grad; i>=0; i--)
    {
        _coef[i] = other._coef[i];
    }
}
Polinom::~Polinom()
{
    delete [] _coef;
    _coef = nullptr;
}

ostream& operator<<(ostream& COUT, Polinom& p)
{
    for(int i=p._grad; i>=1; i--)
    {
        if(p._coef[i] != 0)
            COUT<<p._coef[i]<<"*X^"<<i;
        if(p._coef[i-1] > 0)
            COUT<<"+";
    }
    if(p._coef[0] != 0)
        COUT<<p._coef[0];
    COUT<<endl;
    return COUT;
}

istream& operator>>(istream& CIN, Polinom& p)
{
    cout<<"Introduceti gradul: ";
    CIN>>p._grad;
    while(p._grad < 0)
    {
        cout<<"Grad invalid! Introduceti alt grad: ";
        CIN>>p._grad;
    }
    p._coef = new double[p._grad + 1];
    cout<<"Introduceti coeficientii: ";
    for(int i=p._grad; i>=0; i--)
        CIN>>p._coef[i];
    return CIN;
}

Polinom Polinom::operator+(const Polinom& p) const
{
    Polinom result;
    result._grad = max(_grad, p._grad);
    result._coef = new double[result._grad + 1];
    for(int i = result._grad; i>=0; i--)
    {
        if(i<=_grad && i<=p._grad)
            result._coef[i] = _coef[i] + p._coef[i];
        else if(p._grad > _grad)
            result._coef[i] = p._coef[i];
        else
            result._coef[i] = _coef[i];
    }
    return result;
}

Polinom Polinom::operator+(const double& db) const
{
    Polinom result(*this);
    result._coef[0] += db;
    return result;
}

Polinom operator+(const double db, const Polinom& p)
{
    Polinom result(p);
    result._coef[0] += db;
    return result;
}

Polinom Polinom::operator*(const Polinom& p) const
{
    Polinom result;
    result._grad = _grad + p._grad;
    result._coef = new double[result._grad+1];
    for (int i = 0; i <= result._grad; ++i)
    {
        result._coef[i] = 0;
    }
    for(int i=_grad; i>=0; i--)
    {
        for(int j=p._grad; j>=0; j--)
            result._coef[i+j]+=_coef[i]*p._coef[j];
    }
    return result;
}

Polinom Polinom::operator*(const double db) const
{
    Polinom result(*this);
    for(int i=_grad; i>=0; i--)
        result._coef[i] *= db;
    return result;
}

Polinom operator*(const double db, const Polinom& p)
{
    Polinom result(p);
    for(int i=p._grad; i>=0; i--)
        result._coef[i] *= db;
    return result;
}

double Polinom::operator[](const double db) const
{
    double result=0;
    for(int i=_grad; i>=0; i--)
        result += _coef[i]*pow(db,i);
    return result;
}

Polinom operator!(const Polinom& p)
{
    Polinom result;
    result._grad = p._grad - 1;
    result._coef = new double[result._grad + 1];
    for(int i = result._grad; i >= 0; i--)
    {
        result._coef[i] = p._coef[i+1]*(i+1);
    }
    return result;
}

int main()
{
    Polinom p1;
    cin>>p1;
    Polinom p2 = !p1;
    cout<<p2;
    return 0;
}
