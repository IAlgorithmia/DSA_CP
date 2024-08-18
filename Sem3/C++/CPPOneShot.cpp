#include <iostream>  //Preprocessor COmmand
#include <string>
using namespace std; // Without this we have to write std::cout everytime

// cout << ______ - understand like jo bhi likha hai, vo cout mein daldo
// cin >> ______ - understand like  o bhi cin se aa raha hai, use jo bhi likha hai usme daldo

int adder(int a, int b)
{
     return (a + b);
}

class Employee//Classes are kind of our own variables, our own data structures
{
     public : //Public, private, protected are called as access modifiers - Public : Can be accessed from anywhere, Private : Can't be accessed from outside the class, only from methods inside the class, Protected : Accessible from a subclass only
     string name;
     int salary;
     
     Employee(int s, string n, int p)
     {
          this->name = n;
          this->salary = s;
          this->secretpassword = p;
     }
     void printmood() //This is a class method and can be called from outside
     {
          cout << "The god " << this->name << " is not satisfied with his/her salary of " << this->salary << " and he/she is giving up her secret password which is : "<< this->secretpassword << endl;
          //"this" is like "self" in python, further, . ki jagah -> is being used         
     }
     private : 
     int secretpassword;
};

class Programmer : public Employee
{
     //In this way we can inherit the properties of all the classes
     public:
     int mistakes;
};

int main()
{
     cout << "Hello World\n"
          << endl; // Two ways for entering next line

     cout << "This is a next line";

     // Variables can start with an underscore or a letter, not with a number

     short _sa = 69;

     cout << endl
          << _sa; // <<endl is just a character that can pe put anywhere for entering into the next line

     int marksinmaths = 98;
     cout << endl
          << "Marks in naths are : " << marksinmaths;

     // Types of int
     short a;
     int b;
     long c;
     long long d;

     // Precision increases as we go down
     float e;
     double f;
     long double g;

     // We can reassign variables, but can't redeclare them

     float const width = 15.5;
     cout << endl
          << "The width is : " << width;

     // We can neither reassign nor redeclare width variable since its const

     int firstnum, secondnum;
     cout << endl
          << "Enter the two numbers : ";
     cin >> firstnum >> secondnum; //This is how we take two inputs at the same time
     cout << "The first number is " << firstnum << endl << "The second number is " << secondnum << endl << "Their sum is " << (firstnum + secondnum) << endl << "Their product is " << (firstnum * secondnum) << endl << "Their difference is " << (firstnum - secondnum) << endl << "Their quotient is " << (firstnum / secondnum) << endl << "Their real quotient is " << ( (float)firstnum / secondnum);
     
     int age;
     cout <<endl << "Enter your age my child : " << endl;
     cin >> age;
     if (age >= 18)
     {
          cout << "You can now vote!";
     }
     else if (age > 150 || age < 1)
     {
          cout << "Japanese bc";
     }
     else
     {
          cout << "You can't vote yet";
     }

     int favouritenum;
     cout << endl << "Enter your faourite number : ";
     cin >> favouritenum;
     switch (favouritenum)
     {
          case 55 :
               cout << "Your favourite number is : " << favouritenum;
               break;
          default : 
               cout << "Your favourite number is not 55";
               break;
     }

     int index = 0;
     while (index <= 50)
     {
          cout << "The current index value is " << index << endl;
          index++;
     }
     index = 0;
     do 
     {
          cout << "The current index value is " << index << endl;
     } while (index > 43432);
     for (int jason = 0; jason <= 69; jason++)
     {
          cout << "The jason is " << jason << endl;
     }

     cout << "Enter the two inputs for the adder function : ";
     int inp1, inp2;
     cin >> inp1 >> inp2;
     cout << "The function returned : " << adder(inp1, inp2);

     int array[] = {1, 2, 6, 12, 0};
     for (int i = 0; i < 5; i++)
     {
          cout << "The array item at "<< i <<" is "<< array[i] << endl;
     }
     int size = 5;
     cout << "Enter the marks of " << size << " students : " << endl;
     int marks[size];
     for (int i = 0; i < size; i++)
     {
          cout << "Enter the marks of the student " << i + 1 << endl;
          cin >> marks[i]; 
     }
     cout << "The marks of the students are : " << endl;
     for (int i = 0; i < size; i++)
     {
          cout << marks[i] << " "; 
     }
   
     cout << "Enter the number of rows and columns of the matrix : ";
     int rows, columns;
     cin >> rows >> columns;
     int array2d[rows][columns];
     for (int i = 0; i < rows; i++)
     {
          for (int j = 0; j < columns; j++)
          {
               cout << "Enter the value at position [" << i << "] [" << j << "] : ";
               cin >> array2d[i][j];
          }
     }
     cout << endl << "The entered matrix is : ";
     for (int i = 0; i < rows; i++)
     {
          for (int j = 0; j < columns; j++)
          {
               cout << array2d[i][j] << " ";
          }
          cout << endl;
     }
     int another2darray[2][3] = {{12, 42, 0}, {234, 12 , 441}}; //Arrays are delared using {} and not []

     string name = "Vaibhav Sharma"; //In C++, string is an official datatype
     cout << "The name is : " << name << endl;
     cout << "The length of the name is : " << name.length() << endl;
     cout << "A substring of the name string is : " << name.substr(0, 5) << endl;
     cout << "Another substring of the name string is : " << name.substr(1, 10) << endl;

     //Mind it, in C and C++, *(pointer_name) means dereferencing the pointer and (*pointer_name) means specifiying grouping of operators
     int number = 69;
     int *pointer = &number;
     cout << "The value stored at the address " << pointer << " is " << number;

     Employee god(12000, "Jesus", 9896980);
     cout << "The name of the god is " << god.name << " and the salary of the god is " << god.salary << endl;
     god.printmood();
     // cout << god.secretpassword; this is wrong since the variable being accessed is private
     return 0;
}