#include <iostream>
using namespace std;

int factorial_recursive(int number){
    if (number == 0){
        return 1;
    }
    else{
        return number * factorial_recursive(number - 1);
    }
}

int factorial_iterative(int number){
    int answer = 1;
    for (int i = 1; i <= number; i++){
        answer = answer * i;
    }
    return answer;
}

int main(){
    cout << "Enter the number whose factorial you want to find : " << endl;
    int number;
    cin >> number;
    cout << "The factorial is recursive method is : " << factorial_recursive(number) << " and the factorial by iterative method is : " << factorial_iterative(number);
}