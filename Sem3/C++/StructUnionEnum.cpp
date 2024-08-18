#include <iostream>
#include <string>
using namespace std;

typedef struct Employee{
    int salary;
    string name;
    int ID;
} emp; 

int main(){
    struct Employee Jason;
    Jason.salary = 12000;
    Jason.name = "Jason";
    Jason.ID = 1;
    emp Carlos; //Typedef bhi kar sakte hain
    Carlos.salary = 16000;
    Carlos.name = "Carlos";
    Carlos.ID = 2;
    cout << "The name of our employee " << Jason.ID << " is " << Jason.name << " with a salary of " << Jason.salary << endl;
    cout << "The name of our employee " << Carlos.ID << " is " << Carlos.name << " with a salary of " << Carlos.salary << endl;
    cout << "Hey there!" << endl;
}