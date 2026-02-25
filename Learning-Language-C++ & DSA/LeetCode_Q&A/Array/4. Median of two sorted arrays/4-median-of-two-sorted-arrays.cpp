/*
LeetCode 4 – Median of Two Sorted Arrays
-----------------------------------------

Problem:
Given two sorted arrays nums1 and nums2,
return the median of the combined array.

Constraint:
Must run in O(log (m+n))

--------------------------------------------------
CORE IDEA
--------------------------------------------------

We want the median of a virtual merged array
without actually merging.

Median splits array into:

left half | right half

All elements on left <= right.

We binary search a partition.

--------------------------------------------------
APPROACH 1: Merge + Sort (Brute Force)
--------------------------------------------------

Idea:
1. Append nums2 into nums1
2. Sort
3. Compute median

Simple but ignores sorted property.

Time:  O((m+n) log(m+n))
Space: O(1) extra (in-place sort)

--------------------------------------------------
CODE (Merge + Sort)
--------------------------------------------------
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int x : nums2)
            nums1.push_back(x);

        sort(nums1.begin(), nums1.end());

        int n = nums1.size();

        if (n % 2)
            return nums1[n / 2];

        return (nums1[n/2 - 1] + nums1[n/2]) / 2.0; //2.0 to return float or double
    }
};

--------------------------------------------------
APPROACH 2: Two-pointer Merge (Better)
--------------------------------------------------

Idea:
Simulate merge of two sorted arrays
like merge sort,
but only until median index.

No full sorting needed.

Time:  O(m+n)
Space: O(1)

--------------------------------------------------
CODE (Two-pointer Merge)
--------------------------------------------------
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        int total = m + n;
        int i = 0, j = 0;

        int prev = 0, curr = 0;

        for (int k = 0; k <= total/2; k++) {
            prev = curr;

            if (i < m && (j >= n || a[i] <= b[j]))
                curr = a[i++];
            else
                curr = b[j++];
        }

        if (total % 2)
            return curr;

        return (prev + curr) / 2.0;
    }
};

--------------------------------------------------
APPROACH 3: Binary Search Partition (Optimal)
--------------------------------------------------

Idea:
Partition arrays such that:

left side size = right side size
and
max(left) <= min(right)

We binary search partition on smaller array.

Time:  O(log(min(m,n)))
Space: O(1)

This is the famous interview solution.

--------------------------------------------------
CODE (Binary Search)
--------------------------------------------------
class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size())
            return findMedianSortedArrays(B, A);

        int m = A.size(), n = B.size();
        int low = 0, high = m;

        while (low <= high) {
            int cutA = (low + high) / 2;
            int cutB = (m + n + 1) / 2 - cutA;

            int leftA  = (cutA == 0) ? INT_MIN : A[cutA - 1];
            int rightA = (cutA == m) ? INT_MAX : A[cutA];

            int leftB  = (cutB == 0) ? INT_MIN : B[cutB - 1];
            int rightB = (cutB == n) ? INT_MAX : B[cutB];

            if (leftA <= rightB && leftB <= rightA) {
                if ((m + n) % 2 == 0)
                    return (max(leftA, leftB) +
                            min(rightA, rightB)) / 2.0;
                else
                    return max(leftA, leftB);
            }
            else if (leftA > rightB)
                high = cutA - 1;
            else
                low = cutA + 1;
        }

        return 0.0;
    }
};

--------------------------------------------------
COMPARISON
--------------------------------------------------

Merge + sort:
✔ easiest
✘ ignores sorted input

Two-pointer:
✔ linear
✔ clean

Binary search:
✔ optimal
✔ interview gold

--------------------------------------------------
INTERVIEW SUMMARY
--------------------------------------------------

“We binary search a partition so that
both arrays contribute equally to the median.
We check boundary values to maintain ordering.”

--------------------------------------------------
FINAL TAKEAWAY
--------------------------------------------------

This problem tests:

- binary search on answer
- partition reasoning
- edge handling
- math correctness

Classic FAANG favorite.

*/
