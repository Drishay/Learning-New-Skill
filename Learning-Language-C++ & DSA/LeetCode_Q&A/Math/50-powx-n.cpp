/*
=========================================================
LeetCode 50. Pow(x, n)
=========================================================

Problem:
Implement pow(x, n), which calculates x raised to the power n.
- x is double
- n is integer (range: [-2^31, 2^31 - 1])
- If n is negative → result = 1 / (x^|n|)

=========================================================
Approach 1: Brute Force (Linear Multiplication)
=========================================================

Logic:
- If n >= 0 → multiply x, n times.
- If n < 0  → multiply (1/x), |n| times.
- Convert n to long long to avoid overflow.

Time Complexity: O(n)
Space Complexity: O(1)
⚠ Will cause TLE for large n.

---------------------------------------------------------
Code:
---------------------------------------------------------

class Solution {
public:
    double myPow(double x, int n) {
        
        long long N = n;   // prevent overflow
        double powerProduct = 1;

        if (N >= 0) {
            for (long long i = 1; i <= N; i++) {
                powerProduct *= x;
            }
        } 
        else {
            N = -N;
            for (long long i = 1; i <= N; i++) {
                powerProduct /= x;
            }
        }

        return powerProduct;
    }
};

=========================================================
Approach 2: Recursive Fast Power (Divide & Conquer)
=========================================================

Mathematical Insight:

If n is even:
    x^n = (x^2)^(n/2)

If n is odd:
    x^n = x * (x^2)^((n-1)/2)

Time Complexity: O(log n)
Space Complexity: O(log n) (recursion stack)

---------------------------------------------------------
Code:
---------------------------------------------------------

class Solution {
public:
    
    double fastPow(double x, long long n) {
        if (n == 0) return 1;

        double half = fastPow(x, n / 2);

        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }

    double myPow(double x, int n) {

        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return fastPow(x, N);
    }
};

=========================================================
Approach 3: Binary Exponentiation (Iterative) [Optimal]
=========================================================

Core Idea:
Use binary representation of exponent.

Example:
n = 13
Binary: 1101

x^13 = x^8 * x^4 * x^1

Algorithm:
1. Convert n to long long.
2. If negative:
       x = 1/x
       N = -N
3. While N > 0:
       If N is odd → multiply answer by x
       Square x
       Divide N by 2

Time Complexity: O(log n)
Space Complexity: O(1)

---------------------------------------------------------
Code:
---------------------------------------------------------

class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double ans = 1;

        while (N > 0) {

            if (N % 2 == 1) {
                ans *= x;
            }

            x *= x;
            N /= 2;
        }

        return ans;
    }
};

=========================================================
Edge Cases:
=========================================================
1. n = 0 → return 1
2. x = 0 and n > 0 → return 0
3. n = INT_MIN → must convert to long long first
4. Large n → brute force causes TLE

=========================================================
Key Learnings:
=========================================================
1. Always check integer limits (INT_MIN issue).
2. When exponent is large → think Binary Exponentiation.
3. If problem reduces size by half → likely O(log n).
4. Mathematical transformation > brute force loops.

=========================================================
*/

/*
Why NOT use built-in pow() in interviews / CP?

1. Precision Issues
   - pow() works using floating point.
   - Large powers can introduce rounding errors.

2. No Modular Support
   - pow(a, b) % mod is unsafe.
   - Overflow happens before modulo.
   - Modular exponentiation requires manual binary exponentiation.

3. No Overflow Control
   - Cannot control INT_MIN handling.
   - Cannot control intermediate multiplication behavior.

4. Interview Expectation
   - Interviewers test understanding of:
       → Divide & Conquer
       → Binary Exponentiation
       → O(log n) optimization
   - Writing pow(x, n) hides algorithmic thinking.

5. Performance Awareness
   - Manual fast power = O(log n)
   - Brute multiplication = O(n)

-------------------------------------------------
Key Pattern to Remember:

If exponent is large → Think Binary Exponentiation.

Reduce:
    x^n
Into:
    square base
    halve exponent

Time becomes O(log n).
-------------------------------------------------
*/