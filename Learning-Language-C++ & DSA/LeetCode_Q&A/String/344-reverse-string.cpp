/*
========================================================
LeetCode 344 — Reverse String
Pattern: Two Pointers (Opposite Direction)
========================================================

PROBLEM:
Given a vector<char> s, reverse the array in-place.
No extra space allowed.

--------------------------------------------------------
APPROACH 1: Brute Force (Extra Array) ❌ Not Allowed
--------------------------------------------------------

Idea:
Create a new array and copy elements in reverse order.

Code:

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        vector<char> temp(n);

        for(int i = 0; i < n; i++){
            temp[i] = s[n - 1 - i];
        }

        s = temp;
    }
};

Time Complexity: O(n)
Space Complexity: O(n)
Problem: Not in-place → violates constraints.

--------------------------------------------------------
APPROACH 2: Two Pointer (For Loop)
--------------------------------------------------------

Idea:
Left pointer from start.
Right pointer from end.
Swap and move inward.

Code:

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int right = n - 1;

        for(int left = 0; left < right; left++){
            swap(s[left], s[right]);
            right--;
        }
    }
};

Time Complexity: O(n)
Space Complexity: O(1)

--------------------------------------------------------
APPROACH 3: Two Pointer (While Loop) ✅ Optimal
--------------------------------------------------------

Idea:
Classic opposite-direction two pointer template.

Code:

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

Time Complexity: O(n)
Space Complexity: O(1)

--------------------------------------------------------
EDGE CASES
--------------------------------------------------------

1) Empty array → no swap
2) Single element → no swap
3) Even length
4) Odd length
5) Large input (10^5 elements)

Important:
Use while(left < right) instead of <=
Avoid unnecessary self-swap.

--------------------------------------------------------
COMMON MISTAKES
--------------------------------------------------------

1) Using <= instead of <
2) Missing {} in loops
3) Off-by-one errors
4) Using extra array
5) Using wrong data type for temp

--------------------------------------------------------
KEY LEARNINGS
--------------------------------------------------------

✔ Classic Two Pointer Pattern
✔ Opposite direction movement
✔ In-place modification
✔ Off-by-one boundary control
✔ swap() is cleaner than manual temp
✔ Most array reverse / palindrome problems use this template

--------------------------------------------------------
MASTER TEMPLATE
--------------------------------------------------------

int left = 0;
int right = n - 1;

while(left < right){
    swap(arr[left], arr[right]);
    left++;
    right--;
}

--------------------------------------------------------
WHEN TO USE THIS PATTERN?
--------------------------------------------------------

• Reverse array/string
• Palindrome check
• Sorted array two sum
• Compare from both ends
• Symmetric problems

========================================================
END OF NOTES
========================================================
*/