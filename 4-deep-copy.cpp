#include <iostream>
using namespace std;
class DeepCopy
{
private:
    int *my_int;

public:
    DeepCopy(int val)
    {
        my_int = (int *)malloc(sizeof(int));
        *my_int = val;
        cout << "Inside constructor : my_int = "<< *my_int << std::endl;
    }
    ~DeepCopy()
    {
        cout << "Inside dtor" << std::endl;
        free(my_int);
    }
    DeepCopy(DeepCopy &source)
    {
        my_int = (int *)malloc(sizeof(int));
        *my_int = *source.my_int;
        cout << "Inside copy constructor : my_int = "<< *my_int << std::endl;
    }

    DeepCopy &operator=(DeepCopy &source)
    {
        my_int = (int *)malloc(sizeof(int));
        *my_int = *source.my_int;
        cout << "Inside copy assignment operator : my_int = "<< *my_int << std::endl;
        return *this;
    }
};

int main()
{
    DeepCopy source(23);
    DeepCopy dest(source);
    DeepCopy dest2(65);
    dest2 = source;
    return 0;
}

/*
Deep Copy Policy --> The idea is to allocate proprietary memory in the destination object and then 
to copy the content to which the source object handle is pointing into the newly allocated block of memory.
Memory demands increase as deep copy is made.
*/