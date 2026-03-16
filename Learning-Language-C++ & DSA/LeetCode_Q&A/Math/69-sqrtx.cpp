/*
=========================================================
LeetCode 69. Sqrt(x)
=========================================================

Problem:
Given a non-negative integer x, return the square root of x.
Since return type is integer, decimal part truncate karna hai.

---------------------------------------------------------
Approach 1: Brute Force (Linear Search)
---------------------------------------------------------

Logic:
- 0 se start karo.
- Har i ke liye check karo i*i <= x
- Jab i*i > x ho jaye, answer = i-1

Important:
- i*i overflow ho sakta hai.
- Isliye long long use karo OR
  compare using i <= x / i

Time Complexity: O(n)
Space Complexity: O(1)

---------------------------------------------------------
Approach 2: Binary Search (Optimal)
---------------------------------------------------------

Observation:
- sqrt(x) always lies between 0 and x.
- Sorted nature hai → Binary Search apply kar sakte hain.

Logic:
- low = 0, high = x
- mid = low + (high - low)/2
- if mid*mid == x → return mid
- if mid*mid < x → store ans = mid, move right
- if mid*mid > x → move left
- loop until low <= high

Important:
- mid*mid overflow ho sakta hai.
- Use long long OR compare mid <= x/mid

Time Complexity: O(log n)
Space Complexity: O(1)

---------------------------------------------------------
Edge Cases:
---------------------------------------------------------
x = 0 → return 0
x = 1 → return 1

---------------------------------------------------------
Key Learning:
---------------------------------------------------------
1. int * int overflow ho sakta hai.
2. Multiplication se pehle datatype check karo.
3. Binary Search tab use karo jab:
   - Answer range mein ho
   - Monotonic condition ho

=========================================================
*/