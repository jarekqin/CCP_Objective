#include <iostream>
using namespace std;

class Person
{
    public:
        Person(){}
        Person(string &name,int &age):myname(name),myage(age){}
        ~Person() {}
        virtual string get_name() const 
        { 
        }
        virtual int get_age() const
        { 
        }
    private:
        string myname;
        int myage;
};

class JarekQin:public Person
{
    public:
        JarekQin(string &name,int age):Person(name,age)
        {
            jname=name;
            jage=age;
        }
        int get_age() const
        {
            return jage;
        }
        string get_name() const
        {
            return jname;
        }
    
    private:
        string jname;
        int jage;
};

int main()
{
    string name="qinhaipeng";
    int age=32;
    Person *p;
    p=new Person(name,age);
    JarekQin *j;
    j=new JarekQin(name,age);
    int ans= j->get_age() ;
    cout <<ans << endl;

    return 0;
}