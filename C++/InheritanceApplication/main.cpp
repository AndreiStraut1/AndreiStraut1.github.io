#include <iostream>
#include <string.h>
using namespace std;

//mostenire / clase derivate in C++
class Person
{
  public:

    Person(int = 0, char* = 0);
    Person(const Person&);

    //getters; setters (ca tema)

    virtual ~Person();

    virtual void ConsoleWriteln();

  protected:
        char* _name;
        int _age;
};

Person::Person(int age, char* name)
{
    _age = age;

    if(name != 0){
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
    }
    else
    {
        _name = 0;
    }

    //scop didactic!
    cout<<"Person::Person(int age, char* name)"<<endl;
}

Person::Person(const Person& p)
{
    _age = p._age;

    _name = new char[strlen(p._name) + 1];
    strcpy(_name, p._name);
    //scop didactic!
    cout<<"Person::Person(const Person& p)"<<endl;
}

Person::~Person()
{
    cout<<"se va distruge person cu numele: "<<(_name == 0 ? "no name" : _name)<<endl;

    delete[] _name;
}

void Person::ConsoleWriteln()
{
    if(_name != 0)
    {
        cout<<"name: "<<_name<<endl;
    }
    else
    {
        cout<<"no name provided!"<<endl;
    }

    cout<<"age: "<<_age<<endl;
}


//clasa derivata din Person

class Student : public Person
{
    public:
        Student(int = 0, char* = 0, char* = 0);
        Student(const Student&);

        //gettter & setter

        ~Student();
        //suprascriem varianta mostenita! (aceeasi semnatura!)
        void ConsoleWriteln();
    private:
        char* _faculty;
};

Student::Student(int age, char* name, char* faculty):Person(age, name)
{
    //initializam doar campurile specifice clasei derivate!!
    //cele mostenite de la Person sunt initializate
    //prin constructorii din Person!!
    if(faculty != 0)
    {
        _faculty = new char[strlen(faculty) + 1];
        strcpy(_faculty, faculty);
    }

    cout<<"Student::Student(int age, char* name, char* faculty)"<<endl;
}

Student::Student(const Student& s):Person(s)
{
    if(s._faculty != 0)
    {
        _faculty = new char[strlen(s._faculty) + 1];
        strcpy(_faculty, s._faculty);
    }

    cout<<"Student::Student(const Student& s)"<<endl;
}

void Student::ConsoleWriteln()
{
    //reutilizare: apelam varianta mostenita!
    Person::ConsoleWriteln();
    if(_faculty != 0){
    cout<<"faculty: "<<_faculty<<endl;
    }
    else
    {
        cout<<"empty faculty!"<<endl;
    }
}

Student::~Student()
{
    cout<<"se va distruge student cu numele: "<<(_name == 0 ? "no name" : _name)<<endl;

    delete[] _faculty;
}

//regula generala: obiectele dintr-o ierarhie de clase
//se vor "manevra" prin intermediul unui pointer (sau referinta)
//catre clasa cea mai generala pentru
//a scrie aplicatii cu caracter general
void Process(Person* obj)
{
    obj->ConsoleWriteln(); //in acest caz,
    //acest apel se va numi apel polimorfic!
    //deoarce poate imbraca mai multe forme,
    //functie de obiectul efectiv care prefixeaza apelul!
}

//Ca tema si exercitiu la mostenire:
class Employee : public Person
{

};

int main()
{
    /*
        Person p1, p2(70, "ionescu");

        p1.ConsoleWriteln();
        p2.ConsoleWriteln();

        Student s1, s2(23, "popica", "info");
        s1.ConsoleWriteln();
        s2.ConsoleWriteln();
    */

    Person* p = new Student(25, "Cocolino", "Mate-info");

    p->ConsoleWriteln();

    //eliberare spatiu cu delete!!
    delete p; //aici se apeleaza destructorii

    //fara destructor declarat virtual in clasa de baza,
    //se va apela doar destructorul din clasa tipului
    //declarat al pointerului!! (clasa Person in cazul de fata)
    //prin urmare, memoria ramane ocupata pentru "portiunea" din Student!!!)

    //cu virtual, se apeleaza corect!!

    //prin urmare, ca regula generala, destructorul vor fi declarat
    //virtual!!!

    //ce se intampla in schimb la apelul "p->ConsoleWriteln();" ??
    //fara virtual in clasa de baza, se va selecta
    //intotdeauna versiunea din tipul declarat al pointerului!!!
    //cu virtual, se va selecta versiunea din tipul efectiv
    //al obiectului (Student in cazul de fata)!!

    //apare acest comportament deoarece am redefinit (cu aceeasi semnatura)
    //o metoda din clasa de baza; prin urmare, toate
    //obiectele din clasa derivata vor avea cate doua variante de
    //metoda "ConsoleWriteln()" !!
    //"Person::ConsoleWriteln()" si "Student::ConsoleWriteln()"!!



    cin.get();
    return 0;
}
