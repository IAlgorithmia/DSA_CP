#include <bits/stdc++.h>
using namespace std;

template <class T> //Har function ke upar ek alag template define karna hoga, we can't write template <class T, class T1, class T2> in the top and use them anywhere we like
float swapper(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <class T1, class T2> 
float funcAverage(T1 a, T2 b)
{
    float avg = (a + b) / 2.0;
    return avg;
}
int main()
{
    float a;
    a = funcAverage(5, 2);
    printf("The average of these numbers is %f", a);
    a = funcAverage(5, 2.8);
    printf("The average of these numbers is %f", a);
    int x = 7;
    int y = 10;
    swapper(x, y);
    return 0;
}
