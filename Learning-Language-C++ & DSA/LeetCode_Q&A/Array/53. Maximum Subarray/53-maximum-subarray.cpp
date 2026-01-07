#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int current_sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // extend or restart window
            current_sum = max(nums[i], current_sum + nums[i]);

            // update global max
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
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
    print.printSingle(sol.maxSubArray(n));


    return 0;
}

/* Leetcode first approached, it runs in O(n³) time, thus time limit exceeded
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int max_sum = INT_MIN;
        int best_start = 0, best_end = 0;

        // window size loop
        for (int window = 1; window <= n; window++) {
            // slide the window
            for (int start = 0; start <= n - window; start++) {
                int end = start + window - 1;
                int sum = 0;

                // sum the current window
                for (int i = start; i <= end; i++) {
                    sum += nums[i];
                }

                // update max if needed
                if (sum > max_sum) {
                    max_sum = sum;
                    best_start = start;
                    best_end = end;
                }
            }
        }
        
        return max_sum;;
    }
};
*/

/* it runs in O(n^2) time, thus time limit exceeded
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        // prefix sum array
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int max_sum = INT_MIN;

        // window size loop
        for (int window = 1; window <= n; window++) {
            // slide the window
            for (int start = 0; start <= n - window; start++) {
                int end = start + window - 1;
                // calculate sum in O(1) using prefix sum
                int sum = prefix[end + 1] - prefix[start];

                max_sum = max(max_sum, sum);
            }
        }

        return max_sum;
    }
};
*/



/* this is the omtimised O(n) solution with tracking indices of the subarray, Kadane’s algorithm with my first logic
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0];
        int current_sum = nums[0];

        int start = 0;          // temp start index
        int best_start = 0;     // final best start
        int best_end = 0;       // final best end

        for (int i = 1; i < n; i++) {
            // If current_sum + nums[i] is worse than nums[i] alone,
            // start a new subarray here
            if (current_sum + nums[i] < nums[i]) {
                current_sum = nums[i];
                start = i; // reset start index
            } else {
                current_sum += nums[i];
            }

            // Update best range if we found a new max
            if (current_sum > max_sum) {
                max_sum = current_sum;
                best_start = start;
                best_end = i;
            }
        }

        cout << "Max Subarray Sum: " << max_sum << endl;
        cout << "Start Index: " << best_start << ", End Index: " << best_end << endl;

        return max_sum;
    }
};

*/