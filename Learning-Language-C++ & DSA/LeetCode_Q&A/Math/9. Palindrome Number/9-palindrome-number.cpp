/*
========================================================
LeetCode 9 — Palindrome Number
========================================================

Problem:
Given an integer x, return true if x is a palindrome,
otherwise return false.

A palindrome reads the same forward and backward.

Example:
121  → true
-121 → false
10   → false

--------------------------------------------------------
CORE OBSERVATION
--------------------------------------------------------

Negative numbers are NOT palindrome.

If number ends with 0 but is not 0:
Not palindrome.

Example:
10 → 01 (invalid)

We can solve using:
1. Brute force (store digits)
2. Reverse full number
3. Reverse half number (optimal)

--------------------------------------------------------
APPROACH 1 — Store Digits (Brute Force)
--------------------------------------------------------

Idea:

1. Extract digits using mod 10
2. Store in vector
3. Use two pointers to compare

Important Fix:

Loop condition must be:

while (x > 0)

NOT while (x >= 0)
Otherwise infinite loop when x becomes 0.

Time  : O(log n)
Space : O(log n)

--------------------------------------------------------
CODE (Brute Force)
--------------------------------------------------------

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) return false;

        if (x == 0) return true;

        vector<int> digits;

        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }

        int left = 0;
        int right = digits.size() - 1;

        while (left < right) {
            if (digits[left] != digits[right])
                return false;
            left++;
            right--;
        }

        return true;
    }
};

--------------------------------------------------------
APPROACH 2 — Reverse Full Number
--------------------------------------------------------

Idea:

Reverse entire number and compare with original.

Careful about overflow.

Time  : O(log n)
Space : O(1)

--------------------------------------------------------
APPROACH 3 — Reverse Half (Optimal)
--------------------------------------------------------

Key Insight:

We do NOT need to reverse entire number.
Reverse only half of digits.

Stop when:
reversedHalf >= remaining half.

For even digits:
x == reversedHalf

For odd digits:
x == reversedHalf / 10

Time  : O(log n)
Space : O(1)

--------------------------------------------------------
CODE (Optimal Half Reverse)
--------------------------------------------------------

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        return (x == reversedHalf || x == reversedHalf / 10);
    }
};

--------------------------------------------------------
EDGE CASES
--------------------------------------------------------

✓ x < 0
✓ x = 0
✓ single digit
✓ even number of digits
✓ odd number of digits
✓ trailing zero case

--------------------------------------------------------
INVARIANT THINKING
--------------------------------------------------------

We compare symmetric digits.

Half reversal guarantees:

left half == reversed right half

We never risk overflow of full reversal.

--------------------------------------------------------
COMPLEXITY SUMMARY
--------------------------------------------------------

Brute:
Time  : O(log n)
Space : O(log n)

Optimal:
Time  : O(log n)
Space : O(1)

--------------------------------------------------------
INTERVIEW TAKEAWAY
--------------------------------------------------------

Tests:

- digit extraction logic
- loop termination reasoning
- edge case handling
- overflow awareness
- mathematical symmetry insight

Half reversal approach is the interview gold solution.

========================================================
END OF NOTES
========================================================
*/