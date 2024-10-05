#include <iostream>
using namespace std;

class Student
{
public:
    string Name;
    int Age;
    char Gender;
    virtual void Study() = 0;
};

class ProgrammingStudent:public Student
{
public:
    void Study()
    {
        cout<<"Learning Programming"<<endl;
    }
};
class ArtsStudent:public Student
{
public:
    void Study()
    {
        cout<<"Learning to paint"<<endl;
    }
};
class MusicStudent:public Student
{
public:
    void Study()
    {
        cout<<"Learning to sing"<<endl;
    }
};

int main()
{
    Student* students[3];
    students[0]=new ProgrammingStudent();
    students[1]=new ArtsStudent();
    students[2]=new MusicStudent();

    for(int i=0; i<=2; i++)
    {
        students[i]->Study();
    }
    return 0;
}
