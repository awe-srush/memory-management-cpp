#include <stdlib.h>
#include <iostream>

class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    MyMovableClass(size_t size) // constructor
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size * sizeof(int) << " bytes" << std::endl;
    }

    ~MyMovableClass() // 1 : destructor
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }

    MyMovableClass(const MyMovableClass &source) // 2 : copy constructor
    {
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }

    MyMovableClass &operator=(const MyMovableClass &source) // 3 : copy assignment operator
    {
        std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
        if (this == &source)
            return *this; // to protect from self assignment
        delete[] _data; // this obj has lived previously so delete previous data.
        _data = new int[source._size];
        *_data = *source._data;
        _size = source._size;
        return *this;
    }

    MyMovableClass(MyMovableClass &&source){
        //move data handles from source to destination
        std::cout << "MOVING content of instance " << &source << " to instance " << this << std::endl;
        _data = source._data;
        _size = source._size;
        source._data = nullptr;
        source._size = 0;
        
    }

    MyMovableClass &operator=(MyMovableClass &&source){
        // delete old data of dest then move handles from src to dest
        if(this == &source)
            return *this;
        std::cout << "MOVING (assign) content of instance " << &source << " to instance " << this << std::endl;
        delete[] _data;
        _data = source._data;
        _size = source._size;
        source._data = nullptr;
        source._size = 0;
        return *this;
    }
};

MyMovableClass createObject(int size)
{
    MyMovableClass obj(size); // regular constructor
    return obj;               // return MyMovableClass object by value or returns rvalue
}

void useObject(MyMovableClass obj)
{
    std::cout << "using object : " << &obj << std::endl;
}

int main()
{
    // calling move constructor
    MyMovableClass obj4(MyMovableClass(7));
    useObject(obj4);
    MyMovableClass obj1(5);
    obj1 = createObject(10);
    useObject(std::move(obj1));
    return 0;
}

/*
Srushti@DANGER-ZONE MINGW64  (main)
$ g++ -fno-elide-constructors -std=c++11 7-rule-of-5.cpp 

Srushti@DANGER-ZONE MINGW64  (main)
$ ./a.exe 
CREATING instance of MyMovableClass at 0x55ff1ffad0 allocated with size = 28 bytes
MOVING content of instance 0x55ff1ffad0 to instance 0x55ff1ffac0
DELETING instance of MyMovableClass at 0x55ff1ffad0
COPYING content of instance 0x55ff1ffac0 to instance 0x55ff1ffae0
using object : 0x55ff1ffae0
DELETING instance of MyMovableClass at 0x55ff1ffae0
CREATING instance of MyMovableClass at 0x55ff1ffab0 allocated with size = 20 bytes
CREATING instance of MyMovableClass at 0x55ff1ffa60 allocated with size = 40 bytes
MOVING content of instance 0x55ff1ffa60 to instance 0x55ff1ffaf0
DELETING instance of MyMovableClass at 0x55ff1ffa60
MOVING (assign) content of instance 0x55ff1ffaf0 to instance 0x55ff1ffab0
DELETING instance of MyMovableClass at 0x55ff1ffaf0
MOVING content of instance 0x55ff1ffab0 to instance 0x55ff1ffb00
using object : 0x55ff1ffb00
DELETING instance of MyMovableClass at 0x55ff1ffb00
DELETING instance of MyMovableClass at 0x55ff1ffab0
DELETING instance of MyMovableClass at 0x55ff1ffac0

*/