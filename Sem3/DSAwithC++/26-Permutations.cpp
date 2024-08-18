#include <bits/stdc++.h>
using namespace std;

void print_permutations(string the_str, int i = 0)
{
    if (i == the_str.length() - 1) //Matlab ab saare fix kar diye hain humne, last pe aa gaye now we wanna print the string
    {
        cout << the_str << endl;
        return;
    }
    for (int j = i; j < the_str.length(); j++) //ek ek karke all will be fixed inside this, jab saari permutations of that fixation are over, we will move on to the next fixation in order
    {
        swap(the_str[i], the_str[j]); //this is the stuff jo aage lekar jaata hai fixation ko, pehle 1st ko 1st se, then 2nd se, then 3rd se, ...
        print_permutations(the_str, i + 1); //1st fix kardia ab uske aage vale dekho, 2nd fix kardia uske aage dekho, ...
        swap(the_str[i], the_str[j]); //fixation print karali, next pe jaane ke liye jo original thi usi pe le jaao for the previous call
    }
}


int main(){
    cout << "Enter the string : " << endl;
    string my_str;
    cin >> my_str;
    print_permutations(my_str);
}