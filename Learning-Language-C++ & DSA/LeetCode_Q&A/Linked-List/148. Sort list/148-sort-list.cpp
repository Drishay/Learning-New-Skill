/*
LeetCode 148 – Sort List
------------------------

Problem:
Sort a linked list in ascending order.

Constraints:
- Must be O(n log n) time
- Prefer O(1) extra space
- Cannot convert to array ideally

--------------------------------------------------
CORE INSIGHT
--------------------------------------------------

Linked lists are bad at random access,
so quicksort / heap sort are not natural fits.

Merge sort is perfect for linked lists.

Why?

Because merging lists is pointer-only work.

No shifting. No copying.

--------------------------------------------------
APPROACH 1: Brute Force (Array Conversion)
--------------------------------------------------

Idea:
1. Copy list values into array
2. Sort array
3. Build new linked list

Steps:
- Traverse list → store values
- sort()
- create new nodes

Time:
O(n) copy + O(n log n) sort + O(n) rebuild
= O(n log n)

Space:
O(n) extra array + new list

Simple but not memory optimal.

--------------------------------------------------
CODE (Array Brute Force)
--------------------------------------------------
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;

        vector<int> vals;
        ListNode* curr = head;

        while (curr) {
            vals.push_back(curr->val);
            curr = curr->next;
        }

        sort(vals.begin(), vals.end());

        ListNode* newHead = new ListNode(vals[0]);
        curr = newHead;

        for (int i = 1; i < vals.size(); i++) {
            curr->next = new ListNode(vals[i]);
            curr = curr->next;
        }

        return newHead;
    }
};

--------------------------------------------------
APPROACH 2: BST Idea (Conceptual but Weak)
--------------------------------------------------

Idea (student intuition):
Insert nodes into a Binary Search Tree
then perform inorder traversal.

Why inorder?
Because BST inorder gives sorted order.

Problems:

1. Worst case becomes O(n²)
   if tree becomes skewed

2. Extra memory O(n)
   for tree nodes

3. Overengineering for sorting

So this is NOT interview-optimal.

It works conceptually,
but fails worst-case guarantees.

--------------------------------------------------
APPROACH 3: Merge Sort (Optimal)
--------------------------------------------------

Idea:
Classic divide-and-conquer merge sort
adapted for linked list.

Steps:

1. Find middle using slow/fast pointer
2. Split list into 2 halves
3. Recursively sort both halves
4. Merge sorted halves

Key trick:
Splitting is O(n)
Merging is O(n)

Recursion depth = log n

Time:  O(n log n)
Space: O(log n) recursion stack

This is the intended solution.

--------------------------------------------------
CODE (Merge Sort)
--------------------------------------------------
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = a ? a : b;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Split
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // 3. Sort halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // 4. Merge
        return merge(left, right);
    }
};

--------------------------------------------------
APPROACH 4: Bottom-Up Iterative Merge Sort
--------------------------------------------------

Idea:
Avoid recursion stack.

Iteratively merge blocks of size:
1, 2, 4, 8, 16...

Same merge sort,
but iterative.

Time:  O(n log n)
Space: O(1)

This is the most memory-efficient
professional implementation.

(Advanced version rarely required in interviews.)

--------------------------------------------------
EDGE CASES
--------------------------------------------------

- empty list
- single node
- already sorted
- reverse sorted
- duplicates
- negative numbers

Merge sort handles all naturally.

--------------------------------------------------
COMPARISON OF APPROACHES
--------------------------------------------------

Approach 1 (Array):
✔ simple
✔ fast in practice
✘ O(n) extra memory
Approach 2 (BST):
✔ conceptually interesting
✘ O(n²) worst case
✘ unnecessary memory
✘ not interview safe

Approach 3 (Merge Sort):
✔ guaranteed O(n log n)
✔ pointer-based
✔ optimal for linked list
✔ interview favorite

Approach 4 (Bottom-up):
✔ O(1) extra memory
✔ industrial strength
✔ advanced version

--------------------------------------------------
INTERVIEW SUMMARY
--------------------------------------------------

“Linked lists are sorted optimally using merge sort.
We split with slow/fast pointer,
recursively sort,
and merge using pointer rewiring.
This guarantees O(n log n) time
without array copying.”

--------------------------------------------------
PATTERN RECOGNITION
--------------------------------------------------

Whenever you see:

- sort linked list
- no random access
- pointer structure

→ think merge sort.

Arrays → quicksort
Linked lists → merge sort

--------------------------------------------------
FINAL TAKEAWAY
--------------------------------------------------

This problem tests:

- divide and conquer
- pointer splitting
- merge logic
- recursion understanding
- invariant preservation

Mastering this = mastering linked list sorting.

*/
