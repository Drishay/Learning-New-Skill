/*
========================================================
LeetCode 643 — Maximum Average Subarray I
========================================================

Problem
--------------------------------------------------------
Given an integer array nums and an integer k,
find the contiguous subarray of length k
that has the maximum average value.

Return that maximum average.

Example:
nums = [1,12,-5,-6,50,3], k = 4

Subarrays of size 4:
[1,12,-5,-6]  -> avg = 0.5
[12,-5,-6,50] -> avg = 12.75
[-5,-6,50,3]  -> avg = 10.5

Answer = 12.75

--------------------------------------------------------
KEY OBSERVATION
--------------------------------------------------------

We only need subarrays of fixed size k.

Instead of recomputing the sum every time,
we can reuse the previous window sum.

This leads to the Sliding Window technique.

--------------------------------------------------------
APPROACH 1 — Brute Force (Recompute Every Window)
--------------------------------------------------------

Idea:

For each window:
    compute the sum of k elements
    compute average
    update max average

Time Complexity:
O(n * k)

Space Complexity:
O(1)

This will pass small cases but
TLE for large constraints.

--------------------------------------------------------
CODE (Brute Force)
--------------------------------------------------------

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double maxAvg = numeric_limits<double>::lowest();

        for(int i = 0; i <= nums.size() - k; i++) {

            int sum = 0;

            for(int j = i; j < i + k; j++) {
                sum += nums[j];
            }

            double avg = (double)sum / k;
            maxAvg = max(maxAvg, avg);
        }

        return maxAvg;
    }
};

--------------------------------------------------------
My Code - Kind of Brute Force - fails due to TLE
--------------------------------------------------------
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = numeric_limits<double>::lowest();
        int left = 0;
        int right = k-1;
        
        
        while(right<nums.size()){
            int sum = 0;
            for(int i = left; i<=right; i++ ){
                sum += nums[i];
            }
            double currAvg = (double)sum / k; //this should be float
            // if(currAvg>avg){
            //     avg = currAvg;
            // }
            avg = max(avg, currAvg);
            sum = 0;
            left++;
            right++;
        }
        return avg;
    }
};

--------------------------------------------------------
APPROACH 2 — Sliding Window (Optimal)
--------------------------------------------------------

Idea:

First compute the sum of the first window.

Example:
Window1 = A B C

Next window:
Window2 = B C D

Instead of recomputing:

newSum = oldSum - outgoing + incoming

This avoids recomputing k elements.

--------------------------------------------------------
WINDOW TRANSITION
--------------------------------------------------------

Initial window:
sum = nums[0] + nums[1] + ... + nums[k-1]

Next window:

sum = sum - nums[i-k] + nums[i]

--------------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(1)

--------------------------------------------------------
CODE (Sliding Window)
--------------------------------------------------------

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int sum = 0;

        // first window
        for(int i = 0; i < k; i++)
            sum += nums[i];

        int maxSum = sum;

        for(int i = k; i < nums.size(); i++) {

            sum += nums[i];      // add new element
            sum -= nums[i-k];    // remove old element

            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};

--------------------------------------------------------
APPROACH 3 — Prefix Sum
--------------------------------------------------------

Idea:

Build prefix sum array.

prefix[i] = sum of elements from 0 to i-1

Subarray sum:

sum(i,j) = prefix[j+1] - prefix[i]

Then check every window.

--------------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(n)

Less optimal due to extra space.

--------------------------------------------------------
CODE (Prefix Sum)
--------------------------------------------------------

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> prefix(n+1, 0);

        for(int i = 0; i < n; i++)
            prefix[i+1] = prefix[i] + nums[i];

        int maxSum = INT_MIN;

        for(int i = 0; i <= n-k; i++) {

            int sum = prefix[i+k] - prefix[i];
            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};

--------------------------------------------------------
EDGE CASES
--------------------------------------------------------

✓ n = 1
✓ k = 1
✓ all numbers negative
✓ very large array
✓ large positive and negative mix

Important bug case:

nums = [-1], k = 1

Answer = -1

Incorrect initialization like:

double avg = -1

may fail for negative averages.

Better initialization:

numeric_limits<double>::lowest()

OR

initialize from first window (best practice).

--------------------------------------------------------
COMPLEXITY SUMMARY
--------------------------------------------------------

Brute Force
Time  : O(n * k)
Space : O(1)

Sliding Window (Optimal)
Time  : O(n)
Space : O(1)

Prefix Sum
Time  : O(n)
Space : O(n)

--------------------------------------------------------
INTERVIEW INSIGHT
--------------------------------------------------------

This problem tests:

✓ recognition of fixed-size window
✓ sliding window optimization
✓ avoiding redundant computation

Key interview line:

"When the window size is fixed,
we should reuse the previous window sum
instead of recomputing it."

--------------------------------------------------------
PATTERN RECOGNITION
--------------------------------------------------------

Whenever you see:

• contiguous subarray
• fixed size window
• maximum / minimum

Think:

SLIDING WINDOW

--------------------------------------------------------
SIMILAR PROBLEMS
--------------------------------------------------------

LeetCode 209  — Minimum Size Subarray Sum
LeetCode 3    — Longest Substring Without Repeating
LeetCode 1004 — Max Consecutive Ones III
LeetCode 424  — Longest Repeating Character Replacement
LeetCode 1493 — Longest Subarray of 1s After Deleting One

Sliding window is one of the
most important DSA patterns.

========================================================
END OF NOTES
========================================================
*/