#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr1 [4] = {-1,-100,3,99};

    int k = 2;
    for(int i = 1; i<=k; i++){
        int x = arr1[(sizeof(arr1)/4)-1];
        for(int j = (sizeof(arr1)/4)-1; j>=1; j--){
            arr1[j] = arr1[j-1];
        }
        arr1[0]= x;
        
    }

    for(int i = 0; i < sizeof(arr1)/4; i++){
        cout<< arr1[i] << " ";
    }
    cout << "\n" << k;
}



// leetcode submitted
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // In case k > n

        // Step 1: Reverse the whole array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the rest
        reverse(nums.begin() + k, nums.end());
    }
};

// leetcode - code was not that good, coz of brute force, thus got Time Limit Exceeded
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 1; i <= k; i++) {
            int x = nums[n - 1];
            for (int j = n - 1; j >= 1; j--) {
                nums[j] = nums[j - 1];
            }
            nums[0] = x;
        }
    }
};
*/