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

    int getData(){
        return *_data;
    }
};

MyMovableClass createObject(int size)
{
    MyMovableClass obj(size); // regular constructor
    return obj;               // return MyMovableClass object by value or returns rvalue
}

int main()
{
    //MyMovableClass obj1(10); // regular constructor
    //MyMovableClass obj3 = obj1;
    // MyMovableClass obj4 = createObject(10);
    MyMovableClass obj4(createObject(10));
    std::cout << "obj4 :  " << obj4.getData() << std::endl;


    return 0;
}