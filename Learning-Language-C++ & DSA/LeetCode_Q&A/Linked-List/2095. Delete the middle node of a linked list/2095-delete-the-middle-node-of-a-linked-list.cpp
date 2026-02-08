/*
LeetCode 2095 – Delete the Middle Node of a Linked List
-------------------------------------------------------

Problem:
Delete the middle node of a singly linked list
and return the head.

Middle definition:
index = floor(n / 2)
(0-based indexing)

If list has 1 node → return NULL

--------------------------------------------------
CORE IDEA
--------------------------------------------------

We want the node BEFORE the middle
so we can relink pointers.

Key trick:
Fast/slow pointer offset

slow stops just before the middle
fast jumps 2 steps

This avoids needing a prev pointer.

--------------------------------------------------
APPROACH 1: Length Counting (Two Pass)
--------------------------------------------------

Idea:
1. Count total nodes n
2. middle = n / 2
3. Traverse to node before middle
4. Delete

Simple and readable.

Time:  O(n)
Space: O(1)

--------------------------------------------------
CODE (Length Counting)
--------------------------------------------------
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next)
            return nullptr;

        int n = 0;
        ListNode* curr = head;

        while (curr) {
            n++;
            curr = curr->next;
        }

        int mid = n / 2;

        curr = head;
        for (int i = 1; i < mid; i++)
            curr = curr->next;

        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;

        return head;
    }
};

--------------------------------------------------
APPROACH 2: Fast & Slow Pointer (Optimal)
--------------------------------------------------

Idea:
Start fast 2 steps ahead.
slow will land before middle.

Then delete slow->next.

One pass solution.

Time:  O(n)
Space: O(1)

--------------------------------------------------
CODE (Fast / Slow)
--------------------------------------------------
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow->next;
        slow->next = slow->next->next;
        delete middle;

        return head;
    }
};

--------------------------------------------------
WHY FAST STARTS 2 STEPS AHEAD
--------------------------------------------------

We want slow to stop BEFORE middle.

Example (odd):
1 2 3 4 5
    ^
  delete 3

Example (even):
1 2 3 4
    ^
  delete 3

Offset ensures correct index.

Otherwise we'd need a prev pointer.

--------------------------------------------------
EDGE CASES
--------------------------------------------------

- empty list → NULL
- 1 node → NULL
- 2 nodes → delete 2nd
- odd length
- even length

Handled naturally.

--------------------------------------------------
COMPARISON
--------------------------------------------------

Length counting:
✔ easy to reason
✔ beginner friendly
✘ two passes

Fast/slow:
✔ one pass
✔ elegant
✔ interview favorite

Both O(n), but fast/slow preferred.

--------------------------------------------------
PATTERN RECOGNITION
--------------------------------------------------

This is a variant of:

“find middle of linked list”

Same technique used in:

- 876 middle of list
- 234 palindrome list
- 148 merge sort split
- 143 reorder list

Master fast/slow → unlocks many problems.

--------------------------------------------------
INTERVIEW SUMMARY
--------------------------------------------------

“We offset the fast pointer so the slow pointer
stops just before the middle.
Then we delete slow->next.
This gives O(n) time and O(1) space
in a single traversal.”

--------------------------------------------------
FINAL TAKEAWAY
--------------------------------------------------

This problem tests:

- pointer discipline
- middle detection
- edge-case handling
- safe node deletion

A clean fast/slow invariant prevents bugs.

*/
