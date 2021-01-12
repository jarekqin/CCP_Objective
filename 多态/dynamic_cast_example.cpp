#include <iostream>
using namespace std;

class Book
{
    public:
        Book(string &t) {title=t;}
        virtual void printtitle() const
        {
            cout << "Title is : " << title << endl;
        }
    private:
        string title;
        Book();
};

class TextBook:public Book
{
    public:
        TextBook(string &t,int i): Book(t),level(i) {}
        void printtitle() const
        {
            cout << "TextBook ";
            Book::printtitle();
            cout  << endl;
        }
        void printlevel() const
        {
            cout << "Level is : " << level << endl;
        }
    private:
        int level;
        TextBook();
};
