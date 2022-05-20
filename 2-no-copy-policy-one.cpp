#include <iostream>

class NoCopyPolicy
{
private:
    NoCopyPolicy(const NoCopyPolicy &);
    NoCopyPolicy &operator=(const NoCopyPolicy &);

public:
    NoCopyPolicy() {}
    /*
    Another way to implement No Copy Policy
    NoCopyClass2(const NoCopyClass2 &) = delete;
    NoCopyClass2 &operator=(const NoCopyClass2 &) = delete;
    */
};

int main()
{
    NoCopyPolicy obj1;
    NoCopyPolicy obj2(obj1);
    return 0;
}

/*
No copy Policy 
The simplest policy of all is to forbid copying and assigning class instances all together. 
This can be achieved by declaring, but not defining a private copy constructor and 
assignment operator or alternatively by making both public 
and assigning the delete operator. The second choice is 
more explicit and makes it clearer to the programmer that copying has been actively forbidden.
*/