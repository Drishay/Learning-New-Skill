/*
LeetCode 203 – Remove Linked List Elements
-------------------------------------------

Problem:
Remove all nodes from the linked list
that have value = val.

Return the new head.

We must delete nodes, not just skip values.

--------------------------------------------------
CORE IDEA
--------------------------------------------------

We are filtering a linked list.

Every node equal to val must disappear.

Difficulty:
Deleting the head is tricky because
head has no previous node.

Solution:
Use a dummy node.

Dummy guarantees every node has a parent.

--------------------------------------------------
APPROACH 1: Rebuild List (Brute Force)
--------------------------------------------------

Idea:
1. Traverse original list
2. Copy only valid values into a new list
3. Return new list

We avoid deletion complexity
by building fresh nodes.

Time:  O(n)
Space: O(n)

Simple but wasteful.

--------------------------------------------------
CODE (Rebuild List)
--------------------------------------------------
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (head) {
            if (head->val != val) {
                tail->next = new ListNode(head->val);
                tail = tail->next;
            }
            head = head->next;
        }

        return dummy.next;
    }
};

--------------------------------------------------
APPROACH 2: Recursive Filtering
--------------------------------------------------

Idea:
Recursively process rest of list,
then decide whether to keep current node.

Elegant but recursion-heavy.

Time:  O(n)
Space: O(n) recursion stack

--------------------------------------------------
CODE (Recursion)
--------------------------------------------------
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;

        head->next = removeElements(head->next, val);

        if (head->val == val) {
            ListNode* temp = head->next;
            delete head;
            return temp;
        }

        return head;
    }
};

--------------------------------------------------
APPROACH 3: Dummy Node + In-place Deletion (Optimal)
--------------------------------------------------

Idea:
Use dummy to unify deletion logic.

We always inspect curr->next,
never curr itself.

Invariant:
curr is safe
curr->next may be deleted

If deletion happens → curr stays
Else → move curr forward

Time:  O(n)
Space: O(1)

Interview favorite.

--------------------------------------------------
CODE (Optimal)
--------------------------------------------------
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);
        dummy.next = head;

        ListNode* curr = &dummy;

        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; // prevent memory leak
            } else {
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};

--------------------------------------------------
WHY DUMMY NODE IS NECESSARY
--------------------------------------------------

Case:
6 -> 6 -> 6 -> 1

Without dummy:
head keeps changing
logic becomes messy

With dummy:
dummy -> 6 -> 6 -> 6 -> 1

Deletion is uniform.

No special head case.

--------------------------------------------------
EDGE CASES
--------------------------------------------------

- empty list
- all nodes removed
- no nodes removed
- consecutive matches
- head matches
- tail matches

Dummy handles all automatically.

--------------------------------------------------
MEMORY LEAK WARNING
--------------------------------------------------

Wrong:

curr->next = curr->next->next;

This loses reference to removed node.

Memory still allocated → leak.

Correct:

ListNode* temp = curr->next;
curr->next = curr->next->next;
delete temp;

Always delete removed nodes in C++.

LeetCode may ignore leaks,
real systems cannot.

--------------------------------------------------
COMPARISON
--------------------------------------------------

Rebuild list:
✔ simple
✘ extra memory

Recursion:
✔ elegant
✘ stack heavy

Dummy in-place:
✔ O(1) space
✔ safe deletion
✔ industry style

Optimal choice: dummy method

--------------------------------------------------
PATTERN RECOGNITION
--------------------------------------------------

This is linked list filtering.

Same pattern appears in:

- remove duplicates
- delete nth node
- partition list
- conditional deletion
- stable filtering

Whenever deleting nodes:
→ use dummy

--------------------------------------------------
INTERVIEW SUMMARY
--------------------------------------------------

“We use a dummy node to safely delete
nodes including the head.
We traverse once and unlink matching nodes,
ensuring O(n) time and O(1) space.”

--------------------------------------------------
FINAL TAKEAWAY
--------------------------------------------------

This problem tests:

- pointer discipline
- safe deletion
- head edge cases
- memory management

Dummy node is a universal
linked-list weapon.

*/
