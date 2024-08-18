#include <iostream>
#include <vector>
using namespace std;

/*see all numbers under n have divisors in pair, the smaller of those 
divisor will be before underroot that number, hence for all numbers 
less than n, at least one divisor will be there before underroot n  
and those divisors can be prime or not, anyhow, we will mark their 
multiples as false (not prime) if they themselves have not been 
marked false previously
and obviously if ith element is not marked as false, means none of the 
previous elemnts divide it hence it is prime
*/

//O(nloglogn) time complexity

void sieve(int n){
    vector<int> isPrime(n + 1, true);
    //we dont care about 0 or 1 because they are certainly not prime
    for (int i = 2; i < n; i++){
        if (isPrime[i]){
            cout << i <<  " ";
            for (int j = i * i; j < n; j = j + i){
                isPrime[j] = false;
            }
        }
    }
}
//for a prime detected mark all its multiples as false
//we go from j = i square because j = 2 * i then 3 * i will already have been marked false before.

int main(){
    cout << "Enter the number less than which prime numbers should be printed : " << endl;
    int number;
    cin >> number;
    sieve(number);
}