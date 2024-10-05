#include <iostream>

using namespace std;

class Smartphone
{
public:
    virtual void TakeASelfie() = 0;
    virtual void MakeACall() = 0;
};

class Android:public Smartphone
{
public:
    void TakeASelfie()
    {
        cout<<"Android selfie\n";
    }
    void MakeACall()
    {
        cout<<"Android calling \n";
    }
};

class IPhone:public Smartphone
{
public:
    void TakeASelfie()
    {
        cout<<"IOS selfie\n";
    }
    void MakeACall()
    {
        cout<<"IOS calling \n";
    }
};

int main()
{
    Smartphone* s1 = new Android();
    s1->TakeASelfie();
    s1->MakeACall();

    Smartphone* s2 = new IPhone();
    s2->TakeASelfie();
    s2->MakeACall();
    return 0;
}
