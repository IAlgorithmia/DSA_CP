//The class being inherited is called as base class and the new class formed after inheritance is called as derived class
//Types - Multiple (Multiple base classes), Multilevel (Deriving a class from an already deried class), Hierarchal (Multiple derived calsses), Hybrid (Multiple and Multilevel), Single

#include <iostream>
using namespace std;

// Base Class
class Employee
{
public:
    int id;
    float salary;
    Employee(int inpId)
    {
        id = inpId;
        salary = 34.0;
    }
    Employee() {}
};

// Creating a Programmer class derived from Employee Base class
class Programmer : public Employee //This is the syntax, the public here refers to the mode in which the parents class is being derived
{
public:
    int languageCode;
    Programmer(int inpId)
    {
        id = inpId;
        languageCode = 9;
    }
    void getData()
    {
        cout << id << endl;
    }
};

int main()
{
    Employee harry(1), rohan(2);
    cout << harry.salary << endl;
    cout << rohan.salary << endl;
    Programmer skillF(10);
    cout << skillF.languageCode << endl;
    cout << skillF.id << endl;
    skillF.getData();
    return 0;
}

// Note:

//     Default visibility mode is private
//     Public Visibility Mode: Public members of the base class becomes Public members of the derived class
//     Private Visibility Mode: Public members of the base class become private members of the derived class
//     Private members are never inherited in any case
