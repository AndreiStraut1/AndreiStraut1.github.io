#include <iostream>

#include <string.h>

using namespace std;

class Person{

public:

    Person(char *n, int a){

        name=new char (strlen(n)+1);

        strcpy(name,n);

        age=a;

    }

protected:

    char *name;

    int age;

};

class PersonSpec : public Person {
public:
    PersonSpec(char *n, int a) : Person(n, a) {}

    friend ostream& operator<<(ostream& os, const PersonSpec& ps) {
        os << ps.name << ", " << ps.age;
        return os;
    }

    PersonSpec operator+(int nr) {
        (*this).age += nr;
        return *this;
    }

    friend PersonSpec operator+(int nr, const PersonSpec& ps) {
        PersonSpec result(ps);
        result.age += nr;
        return result;
    }
};

int main()

{

    cout << "Operator Overloading" << endl;

    PersonSpec ps("Stefan", 20);

    cout<<ps<<endl;     //Stefan, 20

    cout<<ps+5<<endl;   //Stefan, 25

    cout<<5+ps<<endl;   //Stefan, 30

}
