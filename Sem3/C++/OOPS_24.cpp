#include <iostream>
using namespace std;
class A
{
public:
    void say()
    {
        cout << "Hello world" << endl;
    }
};
class B : public virtual A
{
};
class C : public virtual A
{
};
class D : public B, public C
{
};
//HEre the virtual  base class is A, not B or C. Virtual base class means that if anytime in the future, if any of it's attributes are passed down to it's children, which are then derived into a new class, only one instance of variables of class A will be passed, not multiple.