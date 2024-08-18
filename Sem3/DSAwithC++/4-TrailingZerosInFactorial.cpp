#include <iostream>
using namespace std;

int trailing_zeros_counter(int number){
    // Kids Method : 
    // int count_2 = 0, count_5 = 0;
    // for (int i = 1; i <= number; i++){
    //     if (i % 2 == 0 && i % 5 == 0){
    //         count_2++, count_5++;
    //     }
    //     else if (i % 2 == 0){
    //         count_2++;
    //     }
    //     else if (i % 5 == 0){
    //         count_5++;
    //     }
    // }
    // cout << count_2 << " " << count_5 << endl;
    // return min(count_2, count_5);

    // Men Method : 
    int count = 0;
    for (int i = 5; i <= number; i = i * 5){
        count = count + (number / i);
    }
    return count;
}

int main(){
    cout << "Enter the number in whose factorial you wish to count the number of trailing zeros : ";
    int number;
    cin >> number;
    cout << "The number of trailing zeros in its factorial are : " << trailing_zeros_counter(number);
}

//Efficiency : Since number of 5's will be lesser than the number of 2's, I only need to count the number of 5's