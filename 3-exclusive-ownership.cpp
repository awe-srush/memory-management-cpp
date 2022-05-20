#include <iostream>

using namespace std;

class ExclusiveOwnership
{
private:
    int* my_int;

public:
    ExclusiveOwnership()
    {
        my_int = (int *)malloc(sizeof(int));
        cout << "Inside constructor" << std::endl;
    }
    ~ExclusiveOwnership()
    {
        if (my_int != nullptr)
        {
            cout << "my_int of this " << this << "not a nullptr so free it." << std::endl;
            free(my_int);
        }
    }
    ExclusiveOwnership(ExclusiveOwnership &source)
    {
        my_int = source.my_int;
        source.my_int = nullptr;
        cout << "Inside copy constructor" << std::endl;
    }

    ExclusiveOwnership &operator=(ExclusiveOwnership &source)
    {
        my_int = source.my_int;
        source.my_int = nullptr;
        cout << "Inside copy assignment operator" << std::endl;
        return *this;
    }
};

int main (){
    ExclusiveOwnership obj1;
    ExclusiveOwnership obj2(obj1);
    ExclusiveOwnership obj3;
    obj3 = obj2;

    return 0;
}