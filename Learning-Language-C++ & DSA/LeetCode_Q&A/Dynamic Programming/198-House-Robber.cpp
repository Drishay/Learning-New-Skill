/*
class Solution {
public:
    int solve(int i, vector<int>& nums) {
        if (i < 0) return 0;
        if (i == 0) return nums[0];

        int take = nums[i] + solve(i - 2, nums);
        int skip = solve(i - 1, nums);

        return max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(n - 1, nums);
    }
};

*/

/*
class Solution {
public:
    int robber(int n, vector <int>&nums){  // recursion
        if(n==0) return nums[0];
        if(n<1) return 0;
        return nums[n] + max(robber(n-2, nums), robber(n-3, nums));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(robber(n-1, nums), robber(n-2, nums));
    }
};
*/

/*
class Solution {
public:
    int robber(int n, vector <int>&nums, vector<int>& dp){  // memoisation
        if(n==0) return dp[n] = nums[0];
        if(n<1) return 0;
        if(dp[n] != -1) return dp[n];
        else{
            dp[n] = nums[n] + max(robber(n-2, nums, dp), robber(n-3, nums, dp));
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n, -1);
        return max(robber(n-1, nums, dp), robber(n-2, nums, dp));
    }
};

*/