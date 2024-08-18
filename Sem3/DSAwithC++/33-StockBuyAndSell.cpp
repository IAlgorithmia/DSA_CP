#include <bits/stdc++.h>
using namespace std;

//Efficient Solution
int maxProfit(vector<int> the_vector)
{
    //The main idea is to identify crests and troughs : The trick is that as long as the stock price is going up, we aim to make profit from it. Kisi bhi way se karlenge, but possible hai isiliye we just need to sum the difference between consecutive values in the 'going up' part
    int profit = 0;
    for (int i = 1; i < the_vector.size(); i++)
    {
        if (the_vector[i] > the_vector[i - 1])
        {
            profit += the_vector[i] - the_vector[i - 1];
        }
    }
    return profit;
}

//Naive Solution
// int maxProfit(vector<int> the_vector, int start, int end)
// {
//     if (end <= start)
//     {
//         return 0;
//     }
//     int profit = 0, current_profit;
//     for (int i = start; i < end; i++)
//     {
//         current_profit = 0;
//         for (int j = i + 1; j <= end; j++)
//         {
//             if (the_vector[i] < the_vector[j])
//             {
//                 current_profit = the_vector[j] - the_vector[i] + maxProfit(the_vector, start, i - 1) + maxProfit(the_vector, j + 1, end);
//                 //This accomodates the part behind the starting index, and after the ending index
//                 profit = max(profit, current_profit);
//             }


//         }
//     }
//     return profit;
// }

// Lamba, Ganda, Unnecessarily hard, but mine <3 :)
// int maxInVect(vector<int>& the_vector, int from, int to)
// {
//     int max = the_vector[from];
//     for (int i = from; i <= to; i++)
//     {
//         if (the_vector[i] > max)
//         {
//             max = the_vector[i];
//         }
//     }
//     return max;
// }

// int maxProfit(vector<int>& the_vector)
// {
//     vector<vector<int>> mega_vect;
//     int n = the_vector.size();
//     for (int i = n - 1; i >= 0; i--)
//     {
//         vector<int> each_row;
//         for (int j = i; j >= 0; j--)
//         {
//             each_row.push_back(the_vector[i] - the_vector[j]);
//         }
//         reverse(each_row.begin(), each_row.end());
//         mega_vect.push_back(each_row);
//     }

//     int total = INT_MIN;
//     int max_total = maxInVect(mega_vect[0], 0, n - 1);
//     for (int i = 0; i < n - 1; i++)
//     {
//         total = maxInVect(mega_vect[n - 1 - i], 0, i) + maxInVect(mega_vect[0], i + 1, n - 1);
//         if (total > max_total)
//         {
//             max_total = total;
//         }
//     }
//     return max_total;
// }



int main(){
    cout << "Enter the array length" << endl;
    int n;
    cin >> n;
    cout << "Enter the elements" << endl;
    int elem;
    vector<int> my_vect;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        my_vect.push_back(elem);
    }
    cout << maxProfit(my_vect);
}