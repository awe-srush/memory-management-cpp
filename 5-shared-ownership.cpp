#include <iostream>
using namespace std;

class SharedCopy
{
private:
    int *val;
    static int cnt;

public:
    SharedCopy(int src);
    ~SharedCopy();
    SharedCopy(SharedCopy &source);
};

int SharedCopy::cnt = 0; //gives error if no int is written.

SharedCopy::SharedCopy(int src)
{
    val = (int *)malloc(sizeof(int));
    *val = src;
    cnt++;
    cout << "Count increased to : " << cnt << endl;
}
SharedCopy::~SharedCopy()
{
    cnt--;
    cout << "Count decreased to : " << cnt << endl;
    if (cnt == 0)
    {
        cout << "Inside dtor freeing val" << endl;
        free(val);
    }
}
SharedCopy::SharedCopy(SharedCopy &source)
{
    val = source.val;
    cnt++;
    cout << "Count increased to : " << cnt << endl;
}

int main()
{
    SharedCopy obj1(12);
    SharedCopy obj2(obj1);
    SharedCopy obj3(obj2);
    return 0;
}

/*
SharedCopy policy --> Heap object's pointer is shared amongst all objects and a count is maintained.
When count reaches 0, heap memory is freed.
Static int weirdness.
*/