#include <iostream>
#include <memory>

using namespace std;

class MyClass
{
private:
    int _mem;

public:
    MyClass(int val) : _mem{val} {}
    void PrintVal()
    {
        cout << ", object address " << this << " and mem val is " << _mem << endl;
    }
};

void f(unique_ptr<MyClass> p)
{
    cout << "unique ptr in f address on stack : " << &p;
    p->PrintVal();
}
int main()
{
    unique_ptr<MyClass> ptr = make_unique<MyClass>(44);
    cout << "unique ptr in main address on stack : " << &ptr;
    ptr->PrintVal();
    f(move(ptr));
    if (ptr)
        ptr->PrintVal();
    return 0;
}

/*
$ ./a.exe 
unique ptr in main address on stack : 0x635b9ff9f8, object address 0x19c8afa62d0 and mem val is 44
unique ptr in f address on stack : 0x635b9ffa08, object address 0x19c8afa62d0 and mem val is 44
*/