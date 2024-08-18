#include <iostream>
using namespace std;

//Euclids Division Algorithm for finding GCD

// also lcm is (x * y / gcd(x, y));

int gcd_finder(int x, int y){
    while (x != y){
        if (x > y){
            x = x - y;
        }
        else{
            y = y - x;
        }
    }
    return x;
}
int gcd(int x, int y){
    // The above uses repeated subtraction, now we'll do modular division
    if (y == 0){
        return x;
    }
    else{
        return gcd(y, x % y); //The condition if x is smaller than y is automatically taken care of here
    }
}

int main(){
    cout << "Enter two numbers whose GCD you want to find : " << endl;
    int num1, num2;
    cin >> num1 >> num2;
    cout << "The answer from the GCD Finder and Optimized GCD Finder are : " << gcd_finder(num1, num2) << " and " << gcd_finder_optimized(num1, num2) << " respectively.";
}