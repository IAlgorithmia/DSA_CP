#include <iostream>
using namespace std;


class binary{
    string s; // s is now private
    public :
    void read_binary();
    void check_binary();
    void display_binary();
    void one_s_complement_binary();
};

void binary :: read_binary(){
    cout << "Enter the binary number : ";
    cin >> s;
}

void binary :: check_binary(){
    for (int i = 0; i < s.length(); i++){
        if (s.at(i) != '0' && s.at(i) != '1'){
            cout << endl << "The entered number is not binary!" << i;
            exit(0);
        }
    }
}

void binary :: display_binary(){
    cout << "The binary number is :" << s << endl;
}

void binary :: one_s_complement_binary(){
    cout << endl << "Initiating the one s complement feature!" << endl;
    for (int i = 0; i < s.length(); i++){
        if (s.at(i) == '0'){
            s.at(i) = '1';
        }
        else
        {
            s.at(i) = '0';
        }
    }
}

int main(){
    cout << "Hey there!" << endl;
    binary the_number;
    the_number.read_binary();
    the_number.check_binary();
    the_number.display_binary();
    the_number.one_s_complement_binary();
    the_number.display_binary();
}