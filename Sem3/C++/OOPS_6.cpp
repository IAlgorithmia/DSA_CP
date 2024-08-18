#include <iostream>
using namespace std;

class Complex; //Taki compiler calculator class ko dekhte hue jaanta ho ki koi complex class bhi hai and error na de, maujodgi ka pata ho
class Calculator{
    public : 
        int add(int a, int b){
            return a + b;
        }
    int sumRealComplex(Complex, Complex);
    int sumCompComplex(Complex, Complex);
};

class Complex{
    int a, b;
    friend class Calculator;
    public:
        int setNumber(int x, int y){
            a = x;
            b = y;
        }
        int getNumber(){
            cout << "The complex number is : " << a << " + " << b << "i" << endl;
        }
};

int Calculator :: sumRealComplex(Complex a1, Complex a2){
    return (a1.a + a2.a);
} 
int Calculator :: sumCompComplex(Complex a1, Complex a2){
    return (a1.b + a2.b);
} 

int main(){
    cout << "Hey there!" << endl;
}