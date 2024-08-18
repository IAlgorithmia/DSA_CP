#include <bits/stdc++.h>
using namespace std;

/*
template<class T1, class T2>
class nameOfClass{
    //body
}
*/

template <class T1, class T2>
class myClass //If we're calling a class jiske andar template use kara hai, we have to specify the data type that we're going to use for that instance while calling that class
{
public:
    T1 data1;
    T2 data2;
    myClass(T1 a, T2 b)
    {
        data1 = a;
        data2 = b;
    }
    void display()
    {
        cout << this->data1 << " " << this->data2;
    }
};
int main()
{
    myClass<int, char> obj(1, 'c');
    obj.display();
    myClass<int, float> obj(1, 1.8);
    obj.display();
}
