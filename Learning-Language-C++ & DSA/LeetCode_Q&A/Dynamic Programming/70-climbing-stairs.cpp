// Recursion
/*
class Solution {
public:
    int climbStairs(int n) {
        if (n<=2)
            return n;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};
// time complexity: O(2^n) - exponential, space complexity: O(n) - recursive stack
*/

// Space Optimized Dynamic Programming
/*
class Solution {
public:
    int climbStairs(int n) {
    if (n <= 2) return n;

    int prev2 = 1; // dp[1]
    int prev1 = 2; // dp[2]

    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
    }
};
// time complexity: O(n), space complexity: O(1)
*/