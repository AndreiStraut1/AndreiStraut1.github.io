#include <iostream>
#include <cstring>

using namespace std;

//sa se implementeze o clasa MyString pentru lucrul cu siruri de caractere
class MyString
{
public:
    //constructori
    MyString();
    MyString(char*); //aici se va calcula si size!
    MyString(const MyString&);

    void DisplayInfo();
    friend istream& operator>>(istream&, MyString&);

    MyString Concat(const MyString&) const; //nu se modifica obiectul curent

    MyString& ToUpper(); //modifica obiectul curent
    MyString& ToLower();
    MyString& OnlyFirstUpper();

    MyString& Reverse(); //rasturnare sir

    ~MyString();

private:
    char* _elem; //elementele (alocare dinamica in constructori)
    int _size; //lungimea (fara terminatorul de sir)
};

MyString::MyString()
{
    _elem = NULL;
    _size = 0;
}

MyString::MyString(char* str)
{
    _size = strlen(str);
    _elem = new char[_size+1];
    strcpy(_elem, str);
}

MyString::MyString(const MyString& other)
{
    _size = other._size;
    _elem = new char[_size+1];
    strcpy(_elem, other._elem);
}

MyString::~MyString()
{
    delete[] _elem;
    _elem = nullptr;
}

void MyString::DisplayInfo()
{
    cout<<_elem<<endl;
}

istream& operator>>(istream& CIN, MyString& str)
{
    string s;
    CIN>>s;
    str._size = s.size();
    str._elem = new char[str._size+1];
    strcpy(str._elem, s.c_str());
    cin.get();//pentru enter-ul din buffer
    return CIN;
}

MyString MyString::Concat(const MyString& other) const
{
    MyString result;
    result._size = _size + other._size;
    result._elem = new char[result._size + 1];
    strcpy(result._elem, _elem);
    strcat(result._elem, other._elem);
    return result;
}

MyString& MyString::ToUpper()
{
    for(int i = 0; i < _size; i++)
    {
        _elem[i] = toupper(_elem[i]);
    }
    return *this;
}

MyString& MyString::ToLower()
{
    for(int i = 0; i < _size; i++)
    {
        _elem[i] = tolower(_elem[i]);
    }
    return *this;
}

MyString& MyString::OnlyFirstUpper()
{
    _elem[0] = toupper(_elem[0]);
    return *this;
}

MyString& MyString::Reverse()
{
    for(int i=0; i<_size/2; i++)
        swap(_elem[i], _elem[_size-1-i]);
    return *this;
}

int main()
{
    MyString str;
    cin>>str;
    str.ToUpper().DisplayInfo();
    str.ToLower().DisplayInfo();
    str.OnlyFirstUpper().DisplayInfo();
    str.Reverse().DisplayInfo();


    char input[100];
    cin.get(input, 100);
    MyString str2(input);

    MyString str3 = str.Concat(str2);
    str3.DisplayInfo();


    return 0;
}
