/*
========================================================
LeetCode 8 — String to Integer (atoi)
========================================================

Problem:
Convert a string to a 32-bit signed integer.

Rules:
1. Ignore leading whitespace.
2. Optional '+' or '-' sign.
3. Read digits until non-digit appears.
4. Clamp result within INT range.

Range:
INT_MIN = -2147483648
INT_MAX = 2147483647

Example:
Input  : "   -42"
Output : -42

Input  : "4193 with words"
Output : 4193

Input  : "words and 987"
Output : 0

--------------------------------------------------------
APPROACH 1 — Brute Force Character Parsing (Your Logic)
--------------------------------------------------------

Idea:

Manually simulate number parsing.

Steps:

1. Skip leading spaces.
2. Detect sign (+ or -).
3. If next char not digit → return 0.
4. Read digits and build number.
5. Stop when non-digit appears.

Number construction formula:

result = result * 10 + digit

Example:

"123"

0 → 1
1 → 12
12 → 123

Time  : O(n)
Space : O(1)

Problem:
Integer overflow not handled.

--------------------------------------------------------
CODE (Basic Parsing)
--------------------------------------------------------

class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.length();
        int sign = 1;
        long long result = 0;

        // skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // next must be digit
        if (i >= n || !isdigit(s[i]))
            return 0;

        // parse digits
        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';
            result = result * 10 + digit;

            i++;
        }

        return sign * result;
    }
};

--------------------------------------------------------
WHY THIS FAILS ON LEETCODE
--------------------------------------------------------

Overflow cases.

Example:

Input:
"91283472332"

Correct output:
2147483647

But result exceeds INT range.

Therefore we must clamp values.

--------------------------------------------------------
APPROACH 2 — Optimal Parsing with Overflow Guard
--------------------------------------------------------

Key Idea:

Before multiplying result by 10,
check if it will overflow.

Overflow condition:

result > INT_MAX / 10
OR

result == INT_MAX / 10 AND digit > 7

Why 7?

Because:

INT_MAX = 2147483647

Last digit = 7

For negative side:

INT_MIN = -2147483648

--------------------------------------------------------
CODE (Optimal Solution)
--------------------------------------------------------

class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.length();
        int sign = 1;
        long long result = 0;

        // skip spaces
        while (i < n && s[i] == ' ')
            i++;

        // detect sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // overflow check
            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && digit > 7)) {

                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};

--------------------------------------------------------
EDGE CASES
--------------------------------------------------------

✓ Empty string
✓ Only spaces
✓ "+" only
✓ "-" only
✓ "+-12"
✓ "000123"
✓ "4193 with words"
✓ "words 123"
✓ Overflow numbers
✓ INT_MIN edge

--------------------------------------------------------
COMPLEXITY
--------------------------------------------------------

Time  : O(n)
Space : O(1)

Single pass parsing.

--------------------------------------------------------
KEY LEARNING
--------------------------------------------------------

Important interview pattern:

Character → Number conversion

digit = s[i] - '0'

Number construction:

result = result * 10 + digit

Overflow prevention:

Check BEFORE multiplying.

--------------------------------------------------------
INTERVIEW INSIGHT
--------------------------------------------------------

This question tests:

✓ String parsing
✓ Edge case handling
✓ Integer overflow
✓ Manual number construction

This pattern appears in:

• Calculator problems
• Expression evaluators
• Custom parsers
• Compiler tokenizers

Understanding atoi parsing
builds foundation for parsing problems.

========================================================
END OF NOTES
========================================================
*/