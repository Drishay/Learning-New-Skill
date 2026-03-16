/*
========================================================
LeetCode 1295 — Find Numbers with Even Number of Digits
Pattern: Digit Manipulation / Simulation / Math
========================================================

PROBLEM:
Given an integer array nums,
Return how many numbers contain EVEN number of digits.

Example:
Input: [12,345,2,6,7896]
Output: 2

--------------------------------------------------------
APPROACH 1: Brute Force (Digit Counting via Division)
--------------------------------------------------------

Idea:
For each number:
    Count digits by dividing by 10.
    If digit count % 2 == 0 → increment answer.

Code:

class Solution {
public:
    bool hasEvenDigits(int num) {
        int count = 0;

        while(num > 0) {
            num /= 10;
            count++;
        }

        return count % 2 == 0;
    }

    int findNumbers(vector<int>& nums) {
        int evenCount = 0;

        for(int num : nums) {
            if(hasEvenDigits(num))
                evenCount++;
        }

        return evenCount;
    }
};

Time Complexity:
O(n * d)
Where d = number of digits (max 5)
Since d ≤ 5 → effectively O(n)

Space Complexity:
O(1)

--------------------------------------------------------
APPROACH 2: Range-Based Mathematical Optimization
--------------------------------------------------------

Observation:
Constraints:
1 <= nums[i] <= 10^5

Max digits = 5

Even digit numbers exist only in:
10–99        (2 digits)
1000–9999    (4 digits)

So we can directly check ranges.

Code:

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;

        for(int num : nums) {
            if((num >= 10 && num <= 99) ||
               (num >= 1000 && num <= 9999)) {
                count++;
            }
        }

        return count;
    }
};

Time Complexity:
O(n)

Space Complexity:
O(1)

Faster because:
No division
No digit loop
Only comparisons

--------------------------------------------------------
APPROACH 3: Using Logarithm
--------------------------------------------------------

Digits formula:
digits = floor(log10(num)) + 1

Code:

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;

        for(int num : nums) {
            int digits = floor(log10(num)) + 1;
            if(digits % 2 == 0)
                count++;
        }

        return count;
    }
};

Time Complexity:
O(n)

Space Complexity:
O(1)

Note:
Be careful with num = 0 (log undefined).
Floating precision issues possible.
Less preferred in interviews.

--------------------------------------------------------
EDGE CASES
--------------------------------------------------------

1) nums contains single digit numbers only → return 0
2) nums contains 0 (if allowed) → 0 has 1 digit
3) Very large array size
4) Max value = 100000 (5 digits)

--------------------------------------------------------
COMMON MISTAKES
--------------------------------------------------------

1) Using while(num >= 0) → infinite loop
2) Forgetting num > 0 condition
3) Not handling 0 case (if present)
4) Using string conversion unnecessarily
5) Misunderstanding digit boundaries

--------------------------------------------------------
KEY LEARNINGS
--------------------------------------------------------

✔ Digit extraction using division by 10
✔ Counting digits efficiently
✔ Using constraints to optimize logic
✔ Recognizing fixed digit range problems
✔ Mathematical reasoning > brute iteration

--------------------------------------------------------
INTERVIEW STRATEGY
--------------------------------------------------------

Best Answer in Interview:
→ Division method (clean + general)
OR
→ Range method (shows optimization thinking)

Avoid:
→ log10 unless interviewer hints toward math

--------------------------------------------------------
MASTER DIGIT TEMPLATE
--------------------------------------------------------

int countDigits(int num) {
    int count = 0;
    while(num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

========================================================
END OF NOTES
========================================================
*/