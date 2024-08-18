#include <iostream>
#include <string>
using namespace std;

class Employee{
    private : 
    string name;
    long long phone_number;
    public : 
    int ID;
    int salary;
    void setData(string, long long); //Banaunga baad mein
    void getData(){
        cout << "The Employee Data is : " << name << " " << phone_number << " " << salary << " " << ID << endl;
    }
};

void Employee :: setData(string a, long long b){
    name = a;
    phone_number = b;
}

int main(){
    cout << "Hey there!" << endl;
    Employee Jack;
    Jack.ID = 1;
    Jack.salary = 50000;
    Jack.setData("Jack", 7027271549);
    Jack.getData();
}