#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // brute fore, not optimized
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>arr = {0,0};   
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if ((nums[i] + nums[j]) == target){
                    arr[0] = i;
                    arr[1] = j;
                    return arr;
                }
            }
        }
        return arr;
        
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
    // Input vector
    vector<int> nums = {3,2,4}; 
    int target = 6;


    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printVector(sol.twoSum(nums, target));


    return 0;
}

//leet code

// submitted by me- in python first, brute force
/*
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
      for i in range(len(nums)-1):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]
      return []  # No solution 
*/

// python optimal solution- Chat gpt
/*
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_index = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_index:
                return [num_index[complement], i]
            num_index[num] = i
        return []

*/


// chat gpt- optimal solution, using hash maps
/*
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndex; // value -> index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numIndex.find(complement) != numIndex.end()) {
                return {numIndex[complement], i};
            }
            numIndex[nums[i]] = i;
        }

        return {}; // If no solution found
    }
*/