/*
========================================================
LeetCode 33 — Search in Rotated Sorted Array
========================================================

Problem:
Search target in a sorted array that has been rotated.

Return index if found, else -1.

Example:
[4 5 6 7 0 1 2]

Sorted but rotated once.

--------------------------------------------------------
CORE OBSERVATION
--------------------------------------------------------

In a rotated sorted array:

At least ONE half is always sorted.

We use this invariant during binary search.

--------------------------------------------------------
APPROACH 1 — Linear Scan (Brute Force)
--------------------------------------------------------

Idea:
Traverse entire array and compare.

Time  : O(n)
Space : O(1)

Not interview optimal.

--------------------------------------------------------
CODE (Linear)
--------------------------------------------------------


class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }
};

--------------------------------------------------------
APPROACH 2 — Find Pivot + Binary Search
--------------------------------------------------------

Idea:

Step 1:
Find index of smallest element (pivot).
This is rotation point.

Step 2:
Decide which sorted half contains target.

Step 3:
Run normal binary search on that half.

Time  : O(log n)
Space : O(1)

Clean logical separation.

--------------------------------------------------------
CODE (Pivot + Binary Search)
--------------------------------------------------------

class Solution {
public:

    int findPivot(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = (low + high) / 2;

            if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }

    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {

        int pivot = findPivot(nums);

        if (target >= nums[pivot] && target <= nums.back())
            return binarySearch(nums, pivot, nums.size()-1, target);

        return binarySearch(nums, 0, pivot-1, target);
    }
};


--------------------------------------------------------
APPROACH 3 — One-Pass Rotated Binary Search (Optimal)
--------------------------------------------------------

Idea:

During binary search:

Check which side is sorted.

If left half sorted:
    target must lie in that range

Else right half sorted:
    search right

We never explicitly find pivot.

Single binary search pass.

Time  : O(log n)
Space : O(1)

This is the interview gold solution.

--------------------------------------------------------
CODE (One-Pass)
--------------------------------------------------------

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0, high = nums.size() - 1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (nums[mid] == target)
                return mid;

            // left half sorted
            if (nums[low] <= nums[mid]) {

                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            // right half sorted
            else {

                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};

--------------------------------------------------------
EDGE CASES
--------------------------------------------------------

✓ array size 1
✓ no rotation
✓ full rotation
✓ target absent
✓ pivot at index 0
✓ pivot at last index

--------------------------------------------------------
INVARIANT THINKING
--------------------------------------------------------

Each iteration guarantees:

One half is sorted.

We discard half safely
without losing target.

--------------------------------------------------------
COMPLEXITY SUMMARY
--------------------------------------------------------

Approach 1:
O(n)

Approach 2:
O(log n)

Approach 3:
O(log n)  ← optimal

--------------------------------------------------------
INTERVIEW TAKEAWAY
--------------------------------------------------------

This is a template for:

"Binary search on rotated structure"

Pattern appears in:

- rotated array search
- find minimum in rotated array
- search with duplicates
- peak element problems

Mastering rotated binary search
is a major interview milestone.

========================================================
END OF NOTES
========================================================
*/
