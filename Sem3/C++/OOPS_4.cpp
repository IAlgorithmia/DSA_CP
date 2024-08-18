#include<iostream>
using namespace std;

class complex{
    int a;
    int b;
    // It is a good practice to create variables as global in the class and then assign them values using another function
    public: 
        void setData(int v1, int v2){
            a = v1;
            b = v2;
        } // Is se hoga ye that jo vlaues humne input karin hain they will be vailable for all the functions in this class

        void setDataBySum(complex o1, complex o2){
            a = o1.a + o2.a;
            b = o1.b + o2.b;
        }

        void printNumber(){
            cout<<"Your complex number is "<<a<<" + "<<b<<"i"<<endl;
        }
};

int main(){
    complex c1, c2, c3;
    c1.setData(1, 2);
    c1.printNumber();

    c2.setData(3, 4);
    c2.printNumber();

    c3.setDataBySum(c1, c2);
    c3.printNumber();
    return 0;
}
