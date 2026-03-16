/*
=========================================================
LeetCode 387. First Unique Character in a String
=========================================================

Problem Summary:
Given a string s, return the index of the first non-repeating character.
If no such character exists, return -1.

Goal:
Find the first character whose total frequency in the string is exactly 1.

=========================================================
Constraints Insight:
=========================================================

- 1 <= s.length <= 10^5
- s consists of lowercase English letters

Implications:
- O(n^2) may cause TLE for n = 10^5.
- Since only 26 lowercase letters exist, we can use a fixed-size array.
- Space can be O(1) using vector<int>(26).

=========================================================
Approach 1: Brute Force (Double Loop)
=========================================================

Idea:
For each character, scan entire string to check if it appears elsewhere.

Time Complexity: O(n^2)
Space Complexity: O(1)

---------------------------------------------------------
Code:
---------------------------------------------------------

class Solution {
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.length(); i++) {
            bool nonRepeating = true;

            for (int j = 0; j < s.length(); j++) {
                if (i != j && s[i] == s[j]) {
                    nonRepeating = false;
                    break;
                }
            }

            if (nonRepeating)
                return i;
        }

        return -1;
    }
};

Why It Fails:
- Works logically.
- But O(n^2) → TLE for large input (10^5).

=========================================================
Approach 2: HashMap Frequency Counting
=========================================================

Idea:
1. Count frequency using unordered_map.
2. Scan string again to find first character with frequency 1.

Time Complexity: O(n)
Space Complexity: O(n) (worst case unique characters)

---------------------------------------------------------
Code:
---------------------------------------------------------

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]] == 1)
                return i;
        }

        return -1;
    }
};

=========================================================
Approach 3: Frequency Array (Optimal)
=========================================================

Since only lowercase letters exist:
Use vector<int>(26).

Index mapping:
    s[i] - 'a'

Time Complexity: O(n)
Space Complexity: O(1) (26 fixed)

---------------------------------------------------------
Code:
---------------------------------------------------------

class Solution {
public:
    int firstUniqChar(string s) {

        vector<int> freq(26, 0);

        // First pass: count frequency
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Second pass: find first unique
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

=========================================================
Complexity Summary:
=========================================================

Brute Force        → O(n^2)   | O(1)
HashMap Approach   → O(n)     | O(n)
Frequency Array    → O(n)     | O(1)   (Optimal)

=========================================================
Edge Cases:
=========================================================

1. Single character string
2. All characters repeating
3. All characters unique
4. Large string (10^5 length)

=========================================================
Pattern Recognition:
=========================================================

Pattern: Frequency Counting

Trigger Signals:
- "First unique"
- "Non-repeating"
- "Count occurrences"
- Fixed character set mentioned

Commonly Seen In:
- Ransom Note
- Valid Anagram
- Majority Element
- Character frequency problems

=========================================================
Interview Insights:
=========================================================

What Interviewer Tests:
- Can you reduce O(n^2) to O(n)?
- Do you recognize frequency pattern?
- Do you choose array over unordered_map when alphabet is fixed?

Common Mistakes:
- Only checking right side of string
- Forgetting to reset boolean flag
- Using unordered_map unnecessarily

Follow-up Questions:
- What if string contains Unicode?
- What if we want the character, not index?
- Can this be done in one pass?

=========================================================
Key Learnings:
=========================================================

1. Always check constraints before choosing approach.
2. Fixed alphabet → use array instead of map.
3. Two-pass frequency counting is a common pattern.
4. Optimize constant factors in interviews.
5. Recognize frequency-based problems quickly.

=========================================================
*/