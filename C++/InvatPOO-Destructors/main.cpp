#include <iostream>
using namespace std;

class Book
{
public:
    string Title;
    string Author;
    float* Rates;
    int RatesCounter;

    Book(string title, string author)
    {
        Title = title;
        Author = author;

        RatesCounter = 2;
        Rates = new float[RatesCounter];
        Rates[0] = 4;
        Rates[1] = 5;

    }

    ~Book()
    {
        delete [] Rates;
        Rates = nullptr;
    }
    Book(const Book& original)
    {
        Title = original.Title;
        Author = original.Author;
        RatesCounter = original.RatesCounter;

        Rates = new float [RatesCounter];
        for (int i=0; i<RatesCounter; i++)
        {
            Rates[i] = original.Rates[i];
        }
    }
};

void PrintBook(Book book)
{
    cout<< "title: " << book.Title<<endl;
    cout<< "author: " << book.Author<<endl;

    float sum=0;
    for (int i=0; i < book.RatesCounter; i++)
    {
        sum+=book.Rates[i];
    }
    cout<<"rate: " << sum/book.RatesCounter<<endl;
}

int main()
{
    Book book1("Millionaire Fastlane","M. J. DeMarco");
    Book book2("C++ Lambda Story","Bartek Filipek");

    Book book3(book1);
    PrintBook(book3);
    return 0;
}
