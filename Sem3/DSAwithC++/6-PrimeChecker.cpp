#include <iostream>
using namespace std;

bool PrimeCheck(int number){
    if (number == 1){
        return false;
    }
    if (number == 2 || number == 3){
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0){
        return false;
    }
    for (int i = 5; i * i <= number; i = i + 6){ //Adding 6 because we need to check divisibility from only prime numbers (Krishan Sir method), all prime numbers greater than 6 are of the form 6k + 1 or 6k - 1. 5 + 6*n takes care of 6k - 1 and for 6k + 1 we check divisibility with i + 2 also.
        if (number % i == 0 || number % (i + 2) == 0){ 
            return false;
        }
    }
    return true;
}
/*
Every prime number can be represented as 6k +- 1, and we need to check 
only or primes since as we go forward, all non primes's divisors have 
already been checked before
The loop starts checking from 5 
(which is 6 × 1 − 1 6×1−1). For each iteration,
it checks divisibility by 𝑖 i (which is 6 𝑘 − 1 6k−1)
and 𝑖 + 2 i+2 (which is 6 𝑘 + 1 6k+1).
By incrementing 𝑖 i by 6, we are effectively checking the
next potential primes 6 ( 𝑘 + 1 ) − 1 6(k+1)−1 and
6 ( 𝑘 + 1 ) + 1 6(k+1)+1.
*/

int main(){
    cout << "Enter the number you want to be checked for prime/composite : " << endl;
    int number;
    cin >> number;
    cout << "The number is : " << PrimeCheck(number);
}