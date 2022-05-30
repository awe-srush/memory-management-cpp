#include <iostream>
#include <memory>

using namespace std;

class UniqueClass
{
private:
    string _text;

public:
    UniqueClass(string text)
    {
        _text = text;
    }
    ~UniqueClass()
    {
        cout << "D'tor call for UniqueClass" << endl;
    }
    void setText(string text)
    {
        _text = text;
    }
    string getText()
    {
        return _text;
    }
};

int main()
{
    unique_ptr<UniqueClass> objptr1(new UniqueClass(""));
    unique_ptr<UniqueClass> objptr2(new UniqueClass("srushti"));

    objptr1->setText("winner");

    *objptr1 = *objptr2;

    cout << "Object at address : " << objptr1.get() << " has text = " << objptr1->getText() << endl;
    cout << "Object at address : " << objptr2.get() << " has text = " << objptr2->getText() << endl;

    return 0;
}

/*
$ ./a.exe
Object at address : 0x298e89962d0 has text = srushti
Object at address : 0x298e8996640 has text = srushti
D'tor call for UniqueClass
D'tor call for UniqueClass
*/