#include <iostream>
using namespace std;

int main(){
    cout << "Enter the desired number : " << endl;
    int num, digit;
    cin >> num;
    int copy_num = num, temp_num = 0;
    while (copy_num > 0){
        digit = copy_num % 10;
        copy_num = copy_num / 10;
        temp_num = (temp_num * 10) + digit;
    }
    if (temp_num == num){
        cout << "The number is a palindrome!" << endl;
    }
    else{
        cout << "The number is not a palindrome!" << endl;
    }
}