#include <iostream>

using namespace std;
bool egal(int v1[], int v2[], int l)
{
    for(int i=0; i<l; i++)
        if(v1[i]!=v2[i])
            return false;
    return true;
}
int S[]={4,3,2,2},d[]={4,3,2,2};
int main()
{
    if(egal(S,d,4))
        cout<<"da";
    else
        cout<<"nu";
    return 0;
}
