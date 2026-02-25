/*
========================================================
LeetCode 66 — Plus One
========================================================

Problem:
Given a non-empty array of digits representing a non-negative integer,
increment the integer by one.

Digits are stored such that the most significant digit is at index 0.

Example:
[1,2,3] → [1,2,4]
[4,3,2,1] → [4,3,2,2]
[9,9,9] → [1,0,0,0]

--------------------------------------------------------
CORE OBSERVATION
--------------------------------------------------------

This is NOT a big integer conversion problem.

Constraints allow up to 100 digits.

So converting to int / long long will cause overflow.

This is a carry propagation problem.

Think like manual addition.

--------------------------------------------------------
APPROACH 1 — Convert to Integer (NOT SAFE)
--------------------------------------------------------

Idea:
1. Convert vector into integer using pow()
2. Add 1
3. Convert back to vector

Problems:
✗ Integer overflow for large inputs
✗ pow() uses double → precision loss
✗ Unnecessary conversion

Time  : O(n)
Space : O(1)
Not interview recommended.

--------------------------------------------------------
APPROACH 2 — Carry Propagation (Optimal)
--------------------------------------------------------

Idea:

Start from last digit.

Case 1:
Digit < 9
→ increment and stop.

Case 2:
Digit == 9
→ make it 0
→ carry continues.

If all digits were 9:
Insert 1 at beginning.

Example:

1299
+   1
------
1300

999
+  1
------
1000

Time  : O(n)
Space : O(1)

--------------------------------------------------------
CODE (Optimal)
--------------------------------------------------------

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {

            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        // All digits were 9
        digits.insert(digits.begin(), 1);

        return digits;
    }
};

--------------------------------------------------------
EDGE CASES
--------------------------------------------------------

✓ Single digit
✓ Ends with 9
✓ All digits are 9
✓ Large input size (100 digits)
✓ Leading digit carry creation

--------------------------------------------------------
INVARIANT THINKING
--------------------------------------------------------

At each step:

Suffix to the right of i
is already processed and correct.

Carry only moves left.

We stop as soon as carry resolves.

--------------------------------------------------------
COMPLEXITY SUMMARY
--------------------------------------------------------

Time  : O(n)
Space : O(1)

Worst case:
All digits are 9 → full traversal.

--------------------------------------------------------
INTERVIEW TAKEAWAY
--------------------------------------------------------

This problem tests:

- Carry handling
- Avoiding overflow traps
- Thinking in digit space
- Recognizing big number constraints

Never convert when constraints suggest big integers.

Think digit-wise.

========================================================
END OF NOTES
========================================================
*/