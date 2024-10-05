#include <iostream>

using namespace std;

class User
{
public:
    string FirstName;
    string LastName;
    int Age;
    string Email;

//    User(){}
//default constructor
    User()
    {
        FirstName="nn";
        LastName="nln";
        Age=0;
        Email="not set";
    }
//    parametrized ctor
    User(string fName, string lName, int age)
    {
        FirstName=fName;
        LastName=lName;
        Age=age;
        Email=fName+"."+lName+"@mail.com";
    }
};

ostream& operator<<(ostream& COUT, User& user)
{
    COUT<<user.FirstName<<endl;
    COUT<<user.LastName<<endl;
    COUT<<user.Age<<endl;
    COUT<<user.Email<<endl;
    return COUT;
}
istream& operator>>(istream& CIN, User& user)
{
    cout<<"first name: ";
    CIN>>user.FirstName;
    cout<<"last name: ";
    CIN>>user.LastName;
    cout<<"age: ";
    CIN>>user.Age;
    user.Email=user.FirstName+"."+user.LastName+"@mail.com";

}
int main()
{
    User user1("saldina", "nurak", 27);
    User user2("gogo", "nox, foxpro", 12);
    User user3;
    //cout<<user1<<user2;
    cin>>user3;
    cout<<user3;
    return 0;
}
