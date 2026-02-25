/*
LeetCode 83 – Remove Duplicates from Sorted List
-------------------------------------------------

Problem:
Given a sorted linked list,
delete all duplicates such that
each element appears only once.

Return the head.

Important:
The list is already sorted.

Duplicates are adjacent.

--------------------------------------------------
CORE IDEA
--------------------------------------------------

Because the list is sorted,
duplicates always appear next to each other.

We only need to compare:

current node
vs
current->next

If equal → delete next
Else → move forward

We never delete the first occurrence.

So head never changes.

Dummy node is NOT required.

--------------------------------------------------
APPROACH 1: Rebuild List (Brute Force)
--------------------------------------------------

Idea:
Traverse and copy unique values
into a new list.

Easy but wastes memory.

Time:  O(n)
Space: O(n)

--------------------------------------------------
CODE (Rebuild List)
--------------------------------------------------
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        int last = head->val - 1; // safe init

        while (head) {
            if (tail == &dummy || head->val != last) {
                tail->next = new ListNode(head->val);
                tail = tail->next;
                last = head->val;
            }
            head = head->next;
        }

        return dummy.next;
    }
};

--------------------------------------------------
APPROACH 2: In-place Collapse (Optimal)
--------------------------------------------------

Idea:
Walk once and remove duplicates in-place.

Invariant:
curr is always valid
curr->next may be deleted

We only move curr when values differ.

Time:  O(n)
Space: O(1)

--------------------------------------------------
CODE (Optimal)
--------------------------------------------------
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* curr = head;

        while (curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; // prevent memory leak
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};

--------------------------------------------------
WHY DUMMY NODE IS NOT NEEDED
--------------------------------------------------

In problem 203:
head might be deleted

In problem 83:
we always keep the first node

So head never changes.

Deletion is always on curr->next.

No special head handling needed.

--------------------------------------------------
EDGE CASES
--------------------------------------------------

- empty list
- single node
- all duplicates
- no duplicates
- long duplicate streaks
- duplicates at end

Handled naturally.

--------------------------------------------------
MEMORY SAFETY NOTE
--------------------------------------------------

Wrong:

curr->next = curr->next->next;

This leaks memory.

Correct:

ListNode* temp = curr->next;
curr->next = curr->next->next;
delete temp;

Always delete removed nodes in C++.

--------------------------------------------------
COMPARISON
--------------------------------------------------

Rebuild list:
✔ simple
✘ extra memory

In-place:
✔ O(1) space
✔ faster
✔ industry style

Optimal choice: in-place collapse

--------------------------------------------------
PATTERN RECOGNITION
--------------------------------------------------

This is adjacent duplicate compression.

Similar patterns:

- array duplicate removal
- string compression
- run-length encoding
- stable filtering

Sorted structure simplifies logic.

--------------------------------------------------
INTERVIEW SUMMARY
--------------------------------------------------

“Because the list is sorted,
duplicates are adjacent.
We walk once and delete equal neighbors
in-place, keeping the first occurrence.”

--------------------------------------------------
FINAL TAKEAWAY
--------------------------------------------------

This problem tests:

- pointer discipline
- safe in-place deletion
- sorted structure reasoning
- memory management

Simple logic + careful pointers.

*/
