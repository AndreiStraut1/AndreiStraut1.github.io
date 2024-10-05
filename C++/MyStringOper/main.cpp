#include <iostream>
#include "MyStringOper.h"

using namespace std;




int main()
{
    MyStringOper m1, m2, m3;
    cin>>m1>>m2;
    m3=m1+m2;
    cout<<m3<<endl;

    char a = 'a';
    m3=a+m3;
    cout<<m3<<endl;

    m3=m3+a;
    cout<<m3<<endl;

    int x = 20;
    m3=x+m3;
    cout<<m3<<endl;
    m3=m3+x;
    cout<<m3<<endl;
    double d = 3.14;
    m3=d+m3;
    cout<<m3<<endl;
    m3=m3+d;
    cout<<m3<<endl;

    if(m1==m2)
        cout<<"sunt egale"<<endl;
    else if(m1<m2)
        cout<<"m1<m2"<<endl;


    cout<<!m1<<endl;
    cout<<m1[1];
    return 0;
}
