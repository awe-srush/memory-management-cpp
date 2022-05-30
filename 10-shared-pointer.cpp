#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> shared1(new int);
    cout << "shared pointer ref count : " << shared1.use_count() << endl;
    {
        shared_ptr<int> shared2 = shared1;
        cout << "shared pointer ref count : " << shared2.use_count() << endl;
    }
    cout << "shared pointer ref count : " << shared1.use_count() << endl;

    return 0;
}

// $ ./a.exe
// shared pointer ref count : 1
// shared pointer ref count : 2
// shared pointer ref count : 1