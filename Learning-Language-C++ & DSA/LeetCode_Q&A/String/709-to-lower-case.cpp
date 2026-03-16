/*
========================================================
LeetCode 709 — To Lower Case
Pattern: String Manipulation / ASCII Arithmetic
========================================================

PROBLEM:
Given a string s, return the string after converting
all uppercase letters to lowercase.

Example:
Input:  "Hello"
Output: "hello"

--------------------------------------------------------
APPROACH 1: Using Built-in Library Function
--------------------------------------------------------

Idea:
Use tolower() from <cctype> for each character.

Code:

class Solution {
public:
    string toLowerCase(string s) {
        for(int i = 0; i < s.size(); i++){
            s[i] = tolower(s[i]);
        }
        return s;
    }
};

Time Complexity:
O(n)

Space Complexity:
O(1)

Pros:
✔ Simple
✔ Clean
✔ Readable

Cons:
❌ Relies on library

--------------------------------------------------------
APPROACH 2: Manual ASCII Conversion (Optimal Thinking)
--------------------------------------------------------

ASCII Facts:

'A' = 65
'Z' = 90
'a' = 97
'z' = 122

Important:
'a' - 'A' = 32

So:
Lowercase = Uppercase + 32
Uppercase = Lowercase - 32

--------------------------------------------------------
LOWERCASE CONVERSION
--------------------------------------------------------

class Solution {
public:
    string toLowerCase(string s) {
        for(int i = 0; i < s.size(); i++){
            // If character is uppercase
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i] + 32;  // Convert to lowercase
            }
        }
        return s;
    }
};

--------------------------------------------------------
UPPERCASE CONVERSION (Reverse Logic)
--------------------------------------------------------

class Solution {
public:
    string toUpperCase(string s) {
        for(int i = 0; i < s.size(); i++){
            // If character is lowercase
            if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] = s[i] - 32;  // Convert to uppercase
            }
        }
        return s;
    }
};

--------------------------------------------------------
EDGE CASES
--------------------------------------------------------

1) Empty string → return as is
2) Already lowercase → unchanged
3) Already uppercase → unchanged
4) Digits & symbols → unchanged
5) Mixed characters → convert only letters

--------------------------------------------------------
COMMON MISTAKES
--------------------------------------------------------

1) Adding 32 without checking range
   → Corrupts digits/symbols

2) Forgetting ASCII boundaries

3) Confusing uppercase and lowercase ranges

4) Using unnecessary extra string

--------------------------------------------------------
KEY LEARNINGS
--------------------------------------------------------

✔ ASCII character arithmetic
✔ Difference between uppercase & lowercase ranges
✔ In-place string modification
✔ Importance of range checking
✔ Library vs manual implementation tradeoff

--------------------------------------------------------
WHEN TO USE ASCII APPROACH?
--------------------------------------------------------

• Case conversion problems
• Caesar cipher problems
• Character shifting problems
• Encoding/decoding problems
• Manual string manipulation interviews

--------------------------------------------------------
MASTER TEMPLATE
--------------------------------------------------------

for(int i = 0; i < s.size(); i++){
    if(s[i] >= 'A' && s[i] <= 'Z')
        s[i] += 32;   // to lower

    if(s[i] >= 'a' && s[i] <= 'z')
        s[i] -= 32;   // to upper
}

========================================================
END OF NOTES
========================================================
*/