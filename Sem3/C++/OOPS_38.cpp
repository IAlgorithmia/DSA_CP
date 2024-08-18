#include <iostream>
using namespace std;

template <class T> //Templates are just parameterized classes. I use templates because I follow DRY principle (Do not repeat yourself), and I can do generic programming
//Jahan jahan T likhenge, it means data type will br specified while passing the values
class vector
{
    T *arr; //T can be int, char, float, etc... 
    int size;

public:
    vector(T *arr){}
        // code
    // and many other methods
};

//What class is to object, template is to class. 

int main()
{
    vector<int> myVec1();
    vector<float> myVec2();
    return 0;
}
