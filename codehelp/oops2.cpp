#include<iostream>
using namespace std;

class A{
    public:
    int a;
    int b;

    // operator overriding
    void operator+ (A obj)
    {
        cout << "operator+ -> "<< this->a - obj.a << endl;
    }

    void operator () (){
        cout << " This is bracket of obj"<<this->a << endl;
    }
};

int main()
{
    A obj1, obj2;
    obj1.a = 1;
    obj2.a = 8;

    // this will call operator+
    obj2 + obj1;

    obj1();

}