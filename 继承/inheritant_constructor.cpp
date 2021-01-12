#include <iostream>
using namespace std;

class Animal
{
    public:
        Animal() { species="Animal"; }
        Animal(const char *s) { species=s; }
    private:
        string species;
};

class Primate:public Animal
{
    public:
        // using Animal constructor directly
        Primate() :Animal("primate") {};
        Primate(int n) : Animal("Primate") { heart_charm=n; }
    private:
        int heart_charm;
};

int main()
{
    Animal m1;
    Animal tweety("canary");
    Primate godzilla;
    Primate human(4);

    return 0;
}