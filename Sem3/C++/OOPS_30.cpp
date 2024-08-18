#include <iostream>
using namespace std;

class Complex
{
    int real, imaginary;

public:
    void getData()
    {
        cout << "The real part is " << real << endl;
        cout << "The imaginary part is " << imaginary << endl;
    }

    void setData(int a, int b)
    {
        real = a;
        imaginary = b;
    }
};
int main()
{
    Complex *ptr = new Complex;
    (*ptr).setData(1, 54); // yAHAN BRACKET LAGANA BOHOT IMPORTANT HAI BECAUSE THE RPECEDENCE OF . OPERATOR IS HIGHER THAN * OPERATOR
    (*ptr).getData();
    ptr->setData(1, 54);
    ptr->getData();

    // Array of Objects
    Complex *ptr1 = new Complex[4]; //These are actually 4 objects, contained inside an array. Each object has different values of the attributes!
    ptr1->setData(1, 4); // Arrow matlab is pointer ko dereference karo, this points to Complex[0]
    ptr1->getData();
    (ptr1 + 1)->setData(4,1); //This points to Complex[1]
    (ptr1 + 1)->getData();
    return 0;
}
