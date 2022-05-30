#include <iostream>
#include <memory>

using namespace std;

class CircularRef
{
public:
    weak_ptr<CircularRef> _member;
    ~CircularRef()
    {
        cout << "D'tor of CircularRef called" << endl;
    }
};

int main()
{
    shared_ptr<CircularRef> obj1(new CircularRef());
    shared_ptr<CircularRef> obj2(new CircularRef());

    obj1->_member = obj2;
    obj2->_member = obj1;

    cout << "size of obj = " << sizeof(obj1) << endl ;

    cout << "ref count for obj1 = " << obj1.use_count() << endl;
    cout << "ref count for obj2 = " << obj2.use_count() << endl;

    return 0;
}

/*
Reference count of both objects decreases to 1 when execution goes out of scope of main. Pointers to each other are lost and d'tor is
never called as count never reaches 0.

*/