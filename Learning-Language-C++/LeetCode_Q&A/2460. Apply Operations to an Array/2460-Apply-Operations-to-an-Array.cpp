#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[lastNonZero++], nums[i]);
            }
        }
    }

    void applyOperations(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++){
            if (nums[i] == nums[i + 1]){
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            else{
                continue;
            }
        }
        moveZeroes(nums);
    }
};

int main() {
    // Input vector
    vector<int> nums = {1,2,2,1,1,0};

    // Create object of Solution class
    Solution sol;

    // Call the moveZeroes function
    sol.applyOperations(nums);

    // Print the result
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// leetcode
/*
class Solution {
public:
    // This function moves all zeros to the end of the vector while keeping the order of non-zero elements
    void moveZeroes(vector<int>& nums) {
        int lastNonZero = 0;  // Index where the next non-zero element should be placed

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // Swap current non-zero element with the element at lastNonZero position
                swap(nums[lastNonZero++], nums[i]);
            }
        }
    }

    // This function applies the given operation and then moves zeros to the end
    vector<int> applyOperations(vector<int>& nums) {
        // Step 1: Apply operation as per the problem statement
        // For each pair of equal adjacent elements, double the first and set the second to zero
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;       // Double the current element
                nums[i + 1] = 0;    // Set the next element to zero
            }
            // else: do nothing, continue to next pair
        }

        // Step 2: Move all the zeros to the end
        moveZeroes(nums);

        // Step 3: Return the modified array
        return nums;
    }
};

*/