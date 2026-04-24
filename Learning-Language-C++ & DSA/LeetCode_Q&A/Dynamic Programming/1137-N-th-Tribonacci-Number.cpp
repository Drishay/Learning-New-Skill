//recursion
/*
class Solution {
public:
    int tribonacci(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        if (n==2) return 1;
        
        return tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
    }
};
//time complexity: O(3^n)
//space complexity: O(n)
*/

//memoization
/*
class Solution {
public:
    int tribonacciDp(int n, vector<int> &dp) { //recursion
        if (n==0) return 0;
        if (n==1 || n==2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n]= tribonacciDp(n-3, dp) + tribonacciDp(n-2, dp) + tribonacciDp(n-1, dp);
    }
    int tribonacci(int n){
        vector <int> dp(n+1, -1);
        return tribonacciDp(n, dp);
    }
};
//time complexity: O(n)
//space complexity: O(n) + O(n) for recursion stack
*/

//tabulation
/*
class Solution {
public:
    int tribonacci(int n){  //tabulation
        vector <int> dp(n+1, -1);
        if (n==0) return 0;
        if (n==1 || n==2) return 1;
        dp[0] = 0; dp[1] = 1; dp[2] = 1;

        for(int i = 3; i<=n; i++){
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};
//time complexity: O(n)
//space complexity: O(n)
*/

//space optimization
/*
class Solution {
public:
    int tribonacci(int n){  //Space optimized
        if(n==0) return 0;
        if(n==1) return 1;
        int prev3 = 0, prev2 = 1, prev1 = 1, curr = -1;
        for(int i = 3; i<=n; i++){
            curr = prev3+ prev2 + prev1;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

//time complexity: O(n)
//space complexity: O(1)
*/