#include<iostream>
using namespace std;
int *ptr;

class A
{
public:
    int a,b;

    //destructor
    ~A()
    {
        cout<<"defined destructor called"<<endl;
    }
};

void f()
{
    int var=10;
    A a0;
    a0.a=5;
    ptr=&a0.a;

    A *a1=new A;
    a1->b=6;
    cout<<a1->b<<endl;


    //explicitely destruct
    // a0.~A(); //Bad Practice
    // cout<<a0.a<<endl; //5
    delete a1; //a1->~A();
    cout<<a1->b<<endl;
}

int main()
{
    f();
    cout<<"Hi"<<endl;
    cout<<*ptr<<endl;
}