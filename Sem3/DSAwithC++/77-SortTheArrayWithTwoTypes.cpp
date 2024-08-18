#include <bits/stdc++.h>
using namespace std;

/*
Explanation : This problem is asked in many ways such as : Segeregate +ve and -ve, Segeregate even and odd, Sort a binary array
Segerate ka synonyms kya h? Partition and partition hum 2 tariko se kar sakte hain! Gottem.
*/

/*
Hoarse Partition : 

void segregatePosAndNeg(vector<int> nums){
    int low = -1;
    int high = nums.size();
    while (true){
        do{
            low++;
        } while (nums[low] < 0);
        do{
            high--;
        } while (nums[high] >= 0);
        if (low >= high){
            return;
        }
        swap(nums[low], nums[high]);
    }
}
left se find karo +ve elements and right se find karo -ve elements, jab dono mil jaye to swap karo, jab low high se bada ho to return karo

void segregateEvenAndOdd(vector<int> nums){
    int low = -1;
    int high = nums.size();
    while (true){
        do{
            low++;
        } while (nums[low] % 2 == 0);
        do{
            high--;
        } while (nums[high] % 2 != 0);
        if (low >= high){
            return;
        }
        swap(nums[low], nums[high]);
    }
}
left se find karo odd elements and right se find karo even elements, jab dono mil jaye to swap karo, jab low high se bada ho to return karo

void segregate0And1(vector<int> nums){
    int low = -1;
    int high = nums.size();
    while (true){
        do{
            low++;
        } while (nums[low] == 0);
        do{
            high--;
        } while (nums[high] == 1);
        if (low >= high){
            return;
        }
        swap(nums[low], nums[high]);
    }
}
left se find karo 1 elements and right se find karo 0 elements, jab dono mil jaye to swap karo, jab low high se bada ho to return karo

*/

int segeregatePAndN(vector<int> &original){
    //A tad modified Lomuto partition
    int high = original.size() - 1;
    int left = -1;
    for (int right = left; right < high; right++){
        if (original[right] < 0){
            left++;
            swap(original[left], original[right]);
        }
    }
    left++;
    swap(original[left], original[high]);
    return left;
}

int segeregateEAndO(vector<int> &original){
    //A tad modified Lomuto partition
    int high = original.size() - 1;
    int left = -1;
    for (int right = left; right < high; right++){
        if (original[right] % 2 == 0){
            left++;
            swap(original[left], original[right]);
        }
    }
    left++;
    swap(original[left], original[high]);
    return left;
}

int segeregateBinaryArray(vector<int> &original){
    //A tad modified Lomuto partition
    int high = original.size() - 1;
    int left = -1;
    for (int right = left; right < high; right++){
        if (original[right] == 0){
            left++;
            swap(original[left], original[right]);
        }
    }
    left++;
    swap(original[left], original[high]);
    return left;
}

int main(){
    cout << "Enter the array length : " << endl;
    int n;
    cin >> n;
    cout << "Enter the elements : " << endl;
    int elem;
    vector<int> my_vect;
    for (int i = 0; i < n; i++){
        cin >> elem;
        my_vect.push_back(elem);
    }
    segeregatePAndN(my_vect);
    cout << "The final array is : " << endl;
    for (auto i : my_vect){
        cout << i << " ";
    }
    cout << endl;
}