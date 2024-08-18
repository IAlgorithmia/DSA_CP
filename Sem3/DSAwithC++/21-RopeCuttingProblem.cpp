#include <bits/stdc++.h>
using namespace std;

int cuts(int remaining, int a, int b, int c)
{
    if (remaining == 0)
    {
        return 0;
    }
    else if (remaining < 0  )
    {
        return -1;
    }

    int res = max(cuts(remaining - a, a, b, c), cuts(remaining - b, a, b, c));

    res = max(res, cuts(remaining - c, a, b, c));

    if (res == -1)
    {
        return -1;
    }

    return (1 + res); //1 cut to humne kr dia yahin hi, aap ye batao bacha hua part kaise ho jayega?
}

int main(){
    cout << "Enter rope length and the three allowed cut lengths : " << endl;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << cuts(n, a, b ,c);
}