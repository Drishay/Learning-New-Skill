/*
========================================================
LeetCode 34 — Find First and Last Position of Element
========================================================

Problem:
Given a sorted array nums and a target value,
return the first and last index of target.

If target is not present → return {-1, -1}

Array is sorted → binary search is the key.

--------------------------------------------------------
CORE IDEA
--------------------------------------------------------

We want a range:
[first occurrence, last occurrence]

Because array is sorted,
all occurrences of target are contiguous.

So we can:
1. Scan linearly (brute)
2. Binary search left boundary
3. Binary search right boundary

--------------------------------------------------------
APPROACH 1 — Linear Scan (Brute Force)
--------------------------------------------------------

Idea:
Traverse entire array and track:

first = index of first match
last  = index of last match

Whenever target found:
- update last
- if first not set → set it

Time  : O(n)
Space : O(1)

Simple but not optimal.

--------------------------------------------------------
CODE (Linear Scan)
--------------------------------------------------------


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int first = -1;
        int last  = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (first == -1)
                    first = i;
                last = i;
            }
        }

        return {first, last};
    }
};


--------------------------------------------------------
APPROACH 2 — Binary Search Twice (Optimal)
--------------------------------------------------------

Idea:
Run binary search twice:

1. findFirst  → left boundary
2. findLast   → right boundary

When target found:
- keep searching left for first
- keep searching right for last

Time  : O(log n)
Space : O(1)

Interview preferred solution.

--------------------------------------------------------
CODE (Binary Search)
--------------------------------------------------------


class Solution {
public:

    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                ans = mid;
                high = mid - 1;   // move left
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                ans = mid;
                low = mid + 1;    // move right
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};

--------------------------------------------------------
APPROACH 3 — STL lower_bound / upper_bound
--------------------------------------------------------

Idea:
Use built-in binary search utilities.

lower_bound → first index >= target
upper_bound → first index > target

If target exists:
first = lower_bound
last  = upper_bound - 1

Time  : O(log n)
Space : O(1)

Shortest clean implementation.

--------------------------------------------------------
CODE (STL)
--------------------------------------------------------

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        auto left  = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);

        if (left == nums.end() || *left != target)
            return {-1, -1};

        int first = left - nums.begin();
        int last  = right - nums.begin() - 1;

        return {first, last};
    }
};

/*
--------------------------------------------------------
EDGE CASES
--------------------------------------------------------

✓ empty array
✓ single element
✓ target not present
✓ target at boundaries
✓ all elements same
✓ large input

--------------------------------------------------------
CORRECTNESS INVARIANT
--------------------------------------------------------

Binary search maintains:

left side < target
right side > target

We shrink search space until
boundary is isolated.

--------------------------------------------------------
COMPLEXITY SUMMARY
--------------------------------------------------------

Approach 1:
Time  O(n)
Space O(1)

Approach 2:
Time  O(log n)   ← optimal
Space O(1)

Approach 3:
Time  O(log n)
Space O(1)

--------------------------------------------------------
INTERVIEW TAKEAWAY
--------------------------------------------------------

Sorted array → binary search mindset.

This problem tests:
- boundary search
- range detection
- modified binary search

Pattern appears in:
- first/last occurrence
- lower/upper bound
- search insert position
- count occurrences

Master boundary binary search
→ many problems become trivial.

========================================================
END OF NOTES
========================================================
*/
