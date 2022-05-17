#include <iostream>
using namespace std;
class DefaultCopy
{
private:
    int *my_int;

public:
    DefaultCopy()
    {
        my_int = (int *)malloc(sizeof(int));
    }

    ~DefaultCopy()
    {
        free(my_int);
    }

    void PrintOwnAddress() { cout << "Address of this object is : " << this << "\n"; }
    void PrintHeapObjAddress() { cout << "Address of memory pointed at by my_int : " << my_int << "\n"; }
};

int main()
{
    DefaultCopy obj1;
    obj1.PrintOwnAddress();
    obj1.PrintHeapObjAddress();

    DefaultCopy obj2(obj1);
    obj2.PrintOwnAddress();
    obj2.PrintHeapObjAddress();
    return 0;
}

/*
Using default copying leads to shallow copy of object that is on heap.

./1-default-copying-perils.exe
Address of this object is : 0x210e9ff858
Address of memory pointed at by my_int : 0x14c6da56360
Address of this object is : 0x210e9ff850
Address of memory pointed at by my_int : 0x14c6da56360 --> points to same address as obj1, hence a shallow copy
*/