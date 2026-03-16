#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> NUMS = nums;
        for(int i = 0; i<nums.size(); i++){
            int x = 1;
            for(int j = 0; j<nums.size(); j++){
                if(i!=j){
                    x*=NUMS[j];
                }
            }
            nums[i]=x;
        }
        return nums;
    }
};

class Print{
public:
    void printSingle(bool value){
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
    vector<int> n = {1,2,3,4};

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printVector(sol.productExceptSelf(n));


    return 0;
}

/* Leetcode optimized solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }
        
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= nums[i];
        }
        
        return res;
    }
};
*/