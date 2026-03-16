/*
=========================================================
LeetCode 3 — Longest Substring Without Repeating Characters
=========================================================

Problem
-------
Given a string s, find the length of the longest substring
without repeating characters.

A substring must be continuous.

Example
-------
Input  : "abcabcbb"
Output : 3
Explanation: "abc"

Characters can be from full ASCII (0–255).

=========================================================
APPROACH 1 — My Brute Force Idea (Reduce Window Size)
=========================================================

Idea
----
1. Assume the whole string could be the answer.
2. Use two pointers:
       left = 0
       right = n-1
3. Check if substring [left,right] has unique characters.
4. If duplicates exist:
       shrink the window by reducing right.
5. Repeat until a valid substring is found.

Problem With This Approach
--------------------------
This approach misses many substrings.

Example:
"abcabcbb"

Correct answer = "abc"

But shrinking only from the right means we never explore
all possible substrings starting at different positions.

Therefore this approach fails logically.

Time Complexity
---------------
O(N^3) worst case

Space Complexity
---------------
O(256)

Code (Your Idea Representation)
--------------------------------


class Solution {
public:

    bool isUnique(string &s, int l, int r){
        unordered_set<char> st;

        for(int i = l; i <= r; i++){
            if(st.count(s[i])) return false;
            st.insert(s[i]);
        }

        return true;
    }

    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int right = s.size() - 1;

        while(right >= left){

            if(isUnique(s,left,right)){
                return right-left+1;
            }

            right--;   // shrink window
        }

        return 0;
    }
};


Key Learning
------------
Shrinking only from the right does NOT explore
all substrings.

For substring problems we must move BOTH pointers.

=========================================================
APPROACH 2 — Brute Force (Check Every Substring)
=========================================================

Idea
----
Generate all substrings and check if unique.

Steps
-----
for left in 0..n
   for right in left..n
       check if substring unique

Time Complexity
---------------
O(N^3)

Space Complexity
---------------
O(256)

Code
----

class Solution {
public:

    bool isUnique(string &s, int l, int r){

        unordered_set<char> st;

        for(int i = l; i <= r; i++){
            if(st.count(s[i])) return false;
            st.insert(s[i]);
        }

        return true;
    }

    int lengthOfLongestSubstring(string s) {

        int maxLen = 0;

        for(int left = 0; left < s.size(); left++){

            for(int right = left; right < s.size(); right++){

                if(isUnique(s,left,right)){
                    maxLen = max(maxLen,right-left+1);
                }

            }
        }

        return maxLen;
    }
};


=========================================================
APPROACH 3 — Better (Sliding Window + HashSet)
=========================================================

Idea
----
Use sliding window.

Window maintains unique characters.

Steps
-----
Expand window with right pointer.

If duplicate appears:
    shrink window from left until duplicate removed.

Window always remains valid.

Time Complexity
---------------
O(2N) ≈ O(N)

Space Complexity
---------------
O(256)

Code
----


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> window;

        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++){

            while(window.count(s[right])){

                window.erase(s[left]);
                left++;

            }

            window.insert(s[right]);

            maxLen = max(maxLen,right-left+1);
        }

        return maxLen;
    }
};



=========================================================
APPROACH 4 — Optimal (Last Seen Index Jump)
=========================================================

Idea
----
Instead of shrinking one-by-one,
jump left pointer directly.

Store last index of characters.

If duplicate appears inside window:

left = lastSeen[c] + 1

Time Complexity
---------------
O(N)

Space Complexity
---------------
O(256)

Code
----


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> lastSeen(256,-1);

        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++){

            if(lastSeen[s[right]] >= left){
                left = lastSeen[s[right]] + 1;
            }

            lastSeen[s[right]] = right;

            maxLen = max(maxLen,right-left+1);
        }

        return maxLen;
    }
};



=========================================================
Edge Cases
=========================================================

s = "bbbbbb"
answer = 1

s = "abcdef"
answer = 6

s = "pwwkew"
answer = 3 ("wke")

s = ""
answer = 0

=========================================================
Key Pattern Learned
=========================================================

This problem teaches the core Sliding Window template.

while(window invalid)
      shrink left

expand right
update answer

=========================================================
Complexity Summary
=========================================================

Approach 1 (Your Idea)        : Incorrect logic
Approach 2 (Full Brute)       : O(N^3)
Approach 3 (Sliding Window)   : O(N)
Approach 4 (Optimal Jump)     : O(N)

=========================================================
Interview Insight
=========================================================

Interviewers expect:

1) brute force explanation
2) sliding window discovery
3) optimized hashmap solution

This question is one of the
MOST IMPORTANT sliding window problems.

=========================================================
Related Problems
=========================================================

159  Longest Substring with At Most 2 Distinct Characters
340  Longest Substring with K Distinct Characters
424  Longest Repeating Character Replacement
76   Minimum Window Substring

All follow sliding window pattern.

=========================================================
*/