#include <iostream>
using namespace std;

class C
{
    public:
        C(int var_x)
         {
            x=var_x;
         }
        static int get_m()
        {
            static int s=0;
            return ++s;
        }
    private:
        int x;
};


int main()
{
    C c1(10),c2(20);
    c1.get_m();
    c2.get_m();
    cout << C::get_m() << endl;
    return 0;
}



