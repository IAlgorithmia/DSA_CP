#include <iostream>
using namespace std;
class A
{
    int a;

public:
    A & setData(int a)
    {
        this->a = a; //this is just an implicit pointer that helps is to (below line)
        return *this; //Jo object is function ko invoke kar raha hai, uska reference hum aise return kara sakte hain function se  
    }

    void getData()
    {
        cout << "The value of a is " << a << endl;
    }
};
int main()
{
    A a;
    a.setData(4).getData();
    return 0;
}
