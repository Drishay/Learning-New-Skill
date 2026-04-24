// Recursion
/*
class Solution {
public:
    int fib(int n) {
        if (n<=1)
            return n;
        return fib(n-1) + fib(n-2);
    }
};
//time complexity: O(2^n)
//space complexity: O(n)
*/

// Memoization
/*
class Solution {
public:
    int fibDp(int n, vector<int>&dp){
        if(n<=1){
            return dp[n] = n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        
        dp[n] = fibDp(n-1, dp) + fibDp(n-2,dp);
        return dp[n];
    }

    int fib(int n) {
        vector <int> dp(n+1,-1);
        return fibDp(n, dp);
    }
};

//time complexity: O(n)
//space complexity: O(n) + O(n) for recursion stack
*/

// Tabulation
/*
class Solution {
public:

    int fib(int n) {
        vector <int> dp(n+1,-1);
        if(n<0) return -1;
        if(n==0) return 0;
        if(n==1) return 1;
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
//time complexity: O(n)
//space complexity: O(n)
*/

// Space Optimization
/*
class Solution {
public:

    int fib(int n) {
        if (n==0) return 0;
        int prev2= 0;
        int prev1 = 1;
        int curr = -1;
        for(int i = 2; i<=n; i++){
            curr = prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
//time complexity: O(n)
//space complexity: O(1)
*/