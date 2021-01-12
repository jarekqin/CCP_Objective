#include <iostream>
using namespace std;


class C
{
    public:
        C(int x_value) {x=x_value;}
        ~C() {x=0;}
        int get_x() const
        {
            return x;
        }
    private:
        int x;
};

int  f(C *a)
{
    return a->get_x();
}


int main()
{
    C c1(10);
    cout << f(&c1) << endl;
    return 0;
}