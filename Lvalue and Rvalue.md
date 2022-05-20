# Lvalue and Rvalue

# What is Lvalue and Rvalue?

- **Lvalues** have an address that can be accessed. They are expressions whose evaluation by the compiler determines the identity of objects or functions.
- **Rvalues** do not have an address that is accessible directly. They are temporary expressions used to initialize objects or compute the value of the operand of an operator.

In more general terms, an lvalue is an entity that points to a specific memory location. An rvalue is usually a short-lived object, which is only needed in a narrow local scope. To simplify things a little, one could think of lvalues as *named containers* for rvalues.

```cpp
((i < 42) ? i : j) = 23;
conditional operator returns lvalue
```

# Lvalue Reference

An lvalue reference can be considered as an alternative name for an object. It can be used as an alias for existing object.

```cpp
#include <iostream>

int main()
{
    int i = 1; 
    int &j = i; 
    ++i;
    ++j;

    std::cout << "i = " << i << ", j = " << j << std::endl;

    return 0;
}

OUTPUT : i=3, j=3
```

One of the primary use-cases for lvalue references is the pass-by-reference

# Rvalue Reference

Reference to temp memory where object is stored for short duration. Since C++11, there is a new type available called *rvalue reference*, which can be identified from the double ampersand `&&`
after a type name. With this operator, it is possible to store and even modify an rvalue, i.e. a temporary object which would otherwise be lost quickly.

```cpp
#include <iostream>

void myFunction(int &val)
{
    std::cout << "val = " << val << std::endl;
}

int main()
{
    int j = 42;
    myFunction(j); // CORRECT

    myFunction(42); // 42 is rvalue passed to func that takes l-value hence error

    int k = 23; 
    myFunction(j+k); // j+k is stored as rvalue so error 

    return 0; 
}
```

let us consider below example,

```cpp
#include <iostream>

int main()
{
    int i = 1; 
    int j = 2; 
/*
1 and 2 are rvalues, whose value is copied into the memory location of i and j
*/
    int k = i + j; 
/*
i+j is stored in temp memory, from temp memory value copied to k, temp memory deleted
*/
    int &&l = i + j; 
/*
i+j is stored in temp memory, l is reference to this temp memory so memory/time saved.
*/

    std::cout << "k = " << k << ", l = " << l << std::endl;

    return 0; 
}
```