/*
========================================================
LeetCode 219 — Contains Duplicate II
========================================================

Problem
--------------------------------------------------------
Given an integer array nums and an integer k.

Return TRUE if there exist two indices i and j such that:

nums[i] == nums[j]
AND
|i - j| <= k

Otherwise return FALSE.

Example
--------------------------------------------------------
nums = [1,2,3,1]
k = 3

index 0 = 1
index 3 = 1

|3 - 0| = 3 <= k

Answer → TRUE


--------------------------------------------------------
CORE OBSERVATION
--------------------------------------------------------

We are NOT just checking duplicates.

We are checking duplicates within a DISTANCE constraint.

So the condition becomes:

Duplicate inside a window of size k.


This turns the problem into:

SLIDING WINDOW + HASHING


--------------------------------------------------------
APPROACH 1 — Brute Force
--------------------------------------------------------

Idea

For every element i,
check the next k elements.

If any element equals nums[i],
return true.

Example

nums = [1,2,3,1], k = 3

Check:

i = 0
compare with indices 1,2,3

Time Complexity
--------------------------------------------------------
Outer loop : n
Inner loop : k

Time = O(n * k)

Worst case:
n = 100000
k = 100000

10^10 operations → TLE


Space
--------------------------------------------------------
O(1)


--------------------------------------------------------
CODE (Brute Force)
--------------------------------------------------------

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        for (int i = 0; i < nums.size(); i++) {

            for (int j = i + 1; j <= i + k && j < nums.size(); j++) {

                if (nums[i] == nums[j])
                    return true;
            }
        }

        return false;
    }
};


--------------------------------------------------------
APPROACH 2 — Hash Map (Store Last Seen Index)
--------------------------------------------------------

Idea

Store the last index where each number appeared.

If we see the same number again,
check the index difference.

If difference <= k → return true.

Example

nums = [1,2,3,1]
k = 3

map

1 → 0
2 → 1
3 → 2

When we see 1 again at index 3:

3 - 0 = 3 <= k

Answer → TRUE


Time Complexity
--------------------------------------------------------

Each element processed once

Time = O(n)


Space Complexity
--------------------------------------------------------

Worst case all elements unique

Space = O(n)


--------------------------------------------------------
CODE (HashMap)
--------------------------------------------------------

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int,int> lastIndex;

        for (int i = 0; i < nums.size(); i++) {

            if (lastIndex.count(nums[i])) {

                if (i - lastIndex[nums[i]] <= k)
                    return true;
            }

            lastIndex[nums[i]] = i;
        }

        return false;
    }
};


--------------------------------------------------------
APPROACH 3 — Sliding Window + HashSet (Optimal)
--------------------------------------------------------

Key Idea

We only care about the LAST k elements.

If duplicate exists inside that window,
the condition |i - j| <= k is automatically satisfied.


Maintain a sliding window of size k.

Use a HashSet for O(1) lookup.


Window Example

nums = [1,2,3,1,4]
k = 3


Window movement:

i=0   [1]

i=1   [1,2]

i=2   [1,2,3]

i=3   [1,2,3] → 1 found → return true


If window exceeds size k:

remove the oldest element.


Why Remove nums[i-k] ?

Because that element is now outside the valid distance range.


--------------------------------------------------------
Time Complexity
--------------------------------------------------------

Insert  : O(1)
Delete  : O(1)
Search  : O(1)

Total = O(n)


--------------------------------------------------------
Space Complexity
--------------------------------------------------------

Window stores at most k elements

Space = O(k)


--------------------------------------------------------
CODE (Sliding Window Set)
--------------------------------------------------------

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {

            if (window.find(nums[i]) != window.end())
                return true;

            window.insert(nums[i]);

            if (window.size() > k)
                window.erase(nums[i - k]);
        }

        return false;
    }
};


--------------------------------------------------------
EDGE CASES
--------------------------------------------------------

nums = [1]
k = 1

Only one element → false


nums = [1,1]
k = 0

Distance must be <= 0
But indices cannot be same

Answer → false


nums = [1,2,3,1]
k = 3

Duplicate within window

Answer → true


--------------------------------------------------------
COMPLEXITY SUMMARY
--------------------------------------------------------

Approach        Time        Space
---------------------------------
Brute Force     O(n*k)      O(1)

Hash Map        O(n)        O(n)

Sliding Window  O(n)        O(k)  ← Best


--------------------------------------------------------
INTERVIEW INSIGHT
--------------------------------------------------------

This problem tests the pattern:

Sliding Window + HashSet


Whenever the problem says:

"distance"
"within k"
"nearby"
"window"

Think:

Sliding Window


--------------------------------------------------------
SIMILAR PROBLEMS
--------------------------------------------------------

LeetCode 3
Longest Substring Without Repeating Characters

LeetCode 220
Contains Duplicate III

LeetCode 187
Repeated DNA Sequences


--------------------------------------------------------
KEY LEARNING
--------------------------------------------------------

Distance constraints in arrays
often convert problems into

SLIDING WINDOW problems.


HashSet provides O(1) duplicate detection.

========================================================
END OF NOTES
========================================================
*/