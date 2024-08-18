#include<iostream>
using namespace std;

class Base{
    protected: //Accessible na ho bahar se but inheritable ho
        int a; 
    private:
        int b;

};

class Derived: protected Base{
   
};

int main(){
    Base b;
    Derived d;
    // cout<<d.a; // Will not work since a is protected in both base as well as derived class
    return 0;
}

/*
As shown in the table,

    If the class is inherited in public mode then its private members cannot be inherited in child class.
    If the class is inherited in public mode then its protected members are protected and can be accessed in child class.
    If the class is inherited in public mode then its public members are public and can be accessed inside child class and outside the class.
    If the class is inherited in private mode then its private members cannot be inherited in child class.
    If the class is inherited in private mode then its protected members are private and cannot be accessed in child class.
    If the class is inherited in private mode then its public members are private and cannot be accessed in child class.
    If the class is inherited in protected mode then its private members cannot be inherited in child class.
    If the class is inherited in protected mode then its protected members are protected and can be accessed in child class.
    If the class is inherited in protected mode then its public members are protected and can be accessed in child class.
*/