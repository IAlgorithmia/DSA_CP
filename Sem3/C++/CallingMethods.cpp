#include <iostream>
using namespace std;

void swapper(int* a, int* b){
    int temp;
    temp = *b ;
    *b = *a;
    *a = temp;
}

int & swapperbyreferencevar(int &m, int &n){ //This means that the function is returning and accepting a reference to data type int
    int temp;
    temp = m;
    m = n;
    n = temp;
}

int main(){
    int x = 10, y = 23;
    swapper(&x, &y);
    cout << "The values of x and y after swapping are : " << x << ", " << y << endl;
    int &p = x;
    int &q = y;
    swapperbyreferencevar(p, q);
    cout << "The values of x and y after swapping again are : " << x << ", " << y << endl;
    cout << "Hey there!" << endl;
}