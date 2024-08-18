#include <iostream>
using namespace std;

int sum(int a, int b){
    return a + b;
}

int main(){
    int x, y;
    cin >> x >> y;
    cout << "The sum of a and b is : " << sum(x, y) << endl;
    cout << "Hey there!" << endl;
}