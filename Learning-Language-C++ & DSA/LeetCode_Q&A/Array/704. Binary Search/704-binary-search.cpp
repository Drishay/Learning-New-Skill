#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = (left + right)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if (nums[mid]<target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }
};

class Print{
public:
    void printSingle(int value){
        cout << "\n" << value;
    }

    void printVector(vector <int> nums){
         for (int num : nums) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
};

int main() {
    // Input
    vector <int> nums = {-1,0,3,5,9,12};
    int target = 9;

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printSingle(sol.search(nums, target));


    return 0;
}



//leetcode stl
/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        
        if (it != nums.end() && *it == target) {
            return it - nums.begin();  // index
        }
        return -1;
    }
};

*/