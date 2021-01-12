#include <iostream>
using namespace std;

class BC
{
    public:
        void set_x(float a) { x=a; }
    private:
        float x;
};

class DC:public BC
{
    public:
        void set_y(float b) { y=b; }
        float return_y() const { return y; }
    private:
        float y;
        using BC::set_x; // 使用using将set_x函数对象变为dc类中的私有对象
};

int main()
{
    DC d1,d2;
    // d1.set_x(1.5); // 错误
    d2.set_y(10.1);
    cout << d2.return_y() << endl;
    return 0;
}