#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class TradesPerson
{
    public:
        virtual void sayHi() { cout << "Just Hi!" << endl; }
};

class Tinker:public TradesPerson
{
    public:
        void sayHi() { cout << "Hi, this is Tinker!" << endl; }
};

class Tailor:public TradesPerson
{
    public:
        void sayHi() { cout << "Hi, this is Tailor!" << endl; }
};

int main()
{
    srand(time(0));
    TradesPerson *ptrs[10];
    unsigned which,i;
    // set
    for (i=0;i<10;i++)
    {
        which=1+rand() % 3;
        switch(which)
        {
            case 1:
                ptrs[i]=new TradesPerson;
                break;
            case 2:
                ptrs[i]=new Tinker;
                break;
            case 3:
                ptrs[i]=new Tailor;
                break;
        }
    }
    // delete
    for (i=0;i<10;i++)
    {
        ptrs[i]->sayHi();
        delete ptrs[i];
    }

    return 0;
}