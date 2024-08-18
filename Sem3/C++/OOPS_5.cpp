#include <iostream>
using namespace std;

class Complex{
    int a, b;
    public:
        void set_data(int x, int y){
            a = x;
            b = y;
        }
        void add_data(Complex, Complex);
        friend Complex summation(Complex l, Complex m); //Declaring that summation function is a frined and can access the provate variables that are a and b
        void get_data(){
            cout << "The complex number is : " << a << " + " << b << "i" << endl;
        }
        
};

Complex summation(Complex a1, Complex a2){
    Complex their_sum;
    their_sum.set_data((a1.a + a2.a), (a1.b + a2.b));
    return their_sum;
}

// Ya to humaise kar sakte hain
void Complex :: add_data(Complex n1, Complex n2){ 
    Complex c;
    c.set_data((n1.a + n2.a), (n1.b + n2.b));
    cout << "The sum is : ";
    c.get_data();
}

//Ya hum ek friend function ka use kar sakte hain

int main(){
    Complex mynum1, mynum2, sum, another_sum;
    mynum1.set_data(5, 7);
    mynum2.set_data(9, 1);
    mynum1.get_data();
    mynum2.get_data();
    sum.add_data(mynum1, mynum2);
    another_sum = summation(mynum1, mynum2);
    another_sum.get_data();
    cout << "Hey there!" << endl;
}

/* Properties of friend functions : 
1. Not a part of the class
2. Can't be called using the object of the class by dot notation
3. Usually contains the objects as arguments
4. Can be invoked without the help of any object
5. friend declaration can be placed anywhere inside the class
7. Directly a access nahi kar sakte, have to use object_name.member_name
*/