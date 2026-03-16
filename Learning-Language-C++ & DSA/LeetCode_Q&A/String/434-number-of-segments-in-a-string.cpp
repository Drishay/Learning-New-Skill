/*
========================================================
LeetCode 434 — Number of Segments in a String
Pattern: String Traversal / Transition Counting
========================================================

PROBLEM:
Given a string s, return the number of segments in the string.
A segment is defined as a contiguous sequence of non-space characters.

Example:
Input:  "Hello, my name is John"
Output: 5

--------------------------------------------------------
IMPORTANT UNDERSTANDING
--------------------------------------------------------

Segment = Word
Word = Continuous non-space characters

Spaces can be:
• Leading
• Trailing
• Multiple between words

We must handle all cases.

--------------------------------------------------------
WRONG APPROACH (Common Mistake)
--------------------------------------------------------

Idea:
Count spaces and return count + 1.

Why wrong?
Fails when:
• Multiple spaces between words
• Leading spaces
• Trailing spaces

Example:
"Hello  world"
Two spaces → would incorrectly count 3 words.

--------------------------------------------------------
APPROACH 1: Using StringStream (Brute)
--------------------------------------------------------

#include <sstream>

class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string word;
        int count = 0;

        while(ss >> word) {
            count++;
        }

        return count;
    }
};

Time Complexity:
O(n)

Space Complexity:
O(n)  // extra space used by stringstream

--------------------------------------------------------
APPROACH 2: Optimal Transition Counting (Best)
--------------------------------------------------------

Core Idea:
Count the START of every word.

A word starts when:
1) Current character is NOT space
2) Either:
   - It is first character
   - Previous character is space

Condition:
s[i] != ' ' && (i == 0 || s[i-1] == ' ')

--------------------------------------------------------

class Solution {
public:
    int countSegments(string s) {
        int count = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ' && (i == 0 || s[i-1] == ' ')) {
                count++;
            }
        }

        return count;
    }
};

--------------------------------------------------------
WHY THIS WORKS
--------------------------------------------------------

We count only transitions:
SPACE → LETTER

We do NOT count:
LETTER → SPACE
LETTER → LETTER
SPACE → SPACE

So each word is counted exactly once.

--------------------------------------------------------
EDGE CASES
--------------------------------------------------------

1) Empty string "" → return 0
2) "     " → return 0
3) "Hello" → return 1
4) " Hello " → return 1
5) "Hello  world" → return 2
6) "a b c" → return 3

--------------------------------------------------------
TIME & SPACE COMPLEXITY
--------------------------------------------------------

Time Complexity:
O(n)

Space Complexity:
O(1)

Single pass.
No extra memory.
Optimal solution.

--------------------------------------------------------
COMMON MISTAKES
--------------------------------------------------------

1) Counting spaces directly
2) Returning count + 1 blindly
3) Not handling leading spaces
4) Not checking previous character
5) Using unnecessary extra string/vector

--------------------------------------------------------
PATTERN RECOGNITION
--------------------------------------------------------

Belongs to:
✔ Transition counting
✔ State tracking in string
✔ Delimiter-based segmentation

Similar problems:
• Count words in a sentence
• Split string by delimiter
• Reverse words in string
• Number of Islands (similar idea in grid)

--------------------------------------------------------
KEY LEARNINGS
--------------------------------------------------------

✔ Count transitions, not delimiters
✔ Handle leading/trailing spaces
✔ Always think about edge cases
✔ One-pass state tracking problems are common in interviews

========================================================
END OF NOTES
========================================================
*/