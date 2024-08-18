#include <iostream>
using namespace std;

int main()
{
    // Basic Example
    int a = 4;
    int *ptr = &a;
    cout << "The value of a is " << *(ptr) << endl;

    float *p = new float(40.78); //This assigns a value to an address, makes a pointer pointing to that address, that address to which the pointer is pointing doesn't have a name. Dynamically allocated memory, 
    cout << "The value at address p is " << *(p) << endl;
    cout << "The address to which p is pointing is : " << (p) << endl;
    int *arr = new int[3];
    arr[0] = 10;
    *(arr + 1) = 20;
    arr[2] = 30;
    cout << "The value of arr[0] is " << arr[0] << endl;
    cout << "The value of arr[1] is " << arr[1] << endl;
    cout << "The value of arr[2] is " << arr[2] << endl;
    delete[] arr;
    cout << "The value of arr[0] is " << arr[0] << endl;
    cout << "The value of arr[1] is " << arr[1] << endl;
    cout << "The value of arr[2] is " << arr[2] << endl;
    return 0;
}
