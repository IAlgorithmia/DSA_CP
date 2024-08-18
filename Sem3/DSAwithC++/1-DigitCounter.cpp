#include <iostream>
#include <cmath>
using namespace std;

int recursion_counter(long n){
    if (n == 0){
        return 0;
    }
    else{
        return (1 + recursion_counter(n/10));
    }
}

int counter(long n){
    string answer_1 = "The answer using logarithm is : ";
    string answer_2 = "The answer using count variable is : ";
    string answer_3 = "The answer using recursion is : ";
    int copy_n = n;
    cout << answer_1 << floor(log10(n)) + 1 << endl << endl;
    int count = 0;
    while (copy_n > 0){
        count++;
        copy_n = copy_n / 10;
    }
    cout << answer_2 << count << endl << endl;
    cout << answer_3 << recursion_counter(n) << endl << endl;
}

int main(){
    cout << "Enter the value of the digit : " << endl;
    int number;
    cin >> number;
    counter(number);
}