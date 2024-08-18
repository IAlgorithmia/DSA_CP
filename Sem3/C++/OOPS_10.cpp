#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex() //Default constructor
    {
        a = 0;
        b = 0;
    }

    Complex(int x, int y) //Parameterised constructor
    {
        a = x;
        b = y;
    }

    Complex(int x)
    {
        a = x;
        b = 0;
    }
    //A class can have multiple constructors, whichever matches the way of defining the object, that constructor will be used.
    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

int main()
{
    Complex c1(4, 6);
    c1.printNumber();

    Complex c2(5);
    c2.printNumber();

    Complex c3;
    c3.printNumber();

    //All work since multiple constructors have been defined accordingly. This is called as constructor overloading
    return 0;
}
