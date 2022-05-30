#include <iostream>

using namespace std;

class RAII
{
private:
    int *_p;

public:
    RAII(int *p)
    {
        _p = p;
        cout << "Enter c'tor \n";
    }
    ~RAII()
    {
        delete _p;
        cout << "Enter d'tor" << endl;
    }
    int &operator*() { return *_p; }
};

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    for (int i = 0; i <= 4; i++)
    {
        RAII obj = new int(i+1);
        cout << arr[i] << "/" << *obj << " = " << arr[i] / (*obj) << endl;
    }

    return 0;
}