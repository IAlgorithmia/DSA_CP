#include <iostream>
#include <string>
using namespace std;

class Base1
{
protected:
    int base1int;

public:
    void set_base1int(int a)
    {
        base1int = a;
    }
};

class Base2
{
protected:
    int base2int;

public:
    void set_base2int(int a)
    {
        base2int = a;
    }
};

class Base3
{
protected:
    int base3int;

public:
    void set_base3int(int a)
    {
        base3int = a;
    }
};
class Derived : public Base1, public Base2, public Base3
{
public:
    void show()
    {
        cout << "The value of Base1 is " << base1int << endl;
        cout << "The value of Base2 is " << base2int << endl;
        cout << "The value of Base3 is " << base3int << endl;
        cout << "The sum of these values is " << base1int + base2int + base3int << endl;
    }
};
int main()
{
    Derived harry;
    harry.set_base1int(25);
    harry.set_base2int(5);
    harry.set_base3int(15);
    harry.show();

    return 0;
}
/*
When an object of derived class is created, the constructors are invoked in the order of derivation : base class constructor is called first and then the derived class constructor. This is done because of the following reason : In-order to construct the derived class object the base class object needs to be constructed first
The derived class object also contains objects from the base class
When the object for derived class is created, the control first reaches the base class constructor and then the derived class constructor
If a base class and a derived class define a function of the same name, then, when a derived class object invokes the function, the function in the derived class will be called first and when an object of base class calls the function, the function of the base class will be called first.*/