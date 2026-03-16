/*
========================================================
LeetCode 82 — Remove Duplicates from Sorted List II
========================================================

Problem:
Given a sorted linked list,
delete ALL nodes that have duplicates.

Only unique numbers should remain.

Example:
1 → 2 → 2 → 3 → 4 → 4 → 5
result:
1 → 3 → 5

This is different from problem 83.
Here duplicates are removed entirely.

--------------------------------------------------------
CORE IDEA
--------------------------------------------------------

We must detect duplicate blocks and skip them.

Two states exist:

1. Duplicate block → skip everything
2. Unique node → keep it

We build a clean result list using a dummy node.

--------------------------------------------------------
APPROACH — One Pass Pointer Filtering
--------------------------------------------------------

Pointers used:

prev → last safe node in result
curr → scanning pointer

When duplicates found:
skip entire block

When unique:
attach to result

Time  : O(n)
Space : O(1)

--------------------------------------------------------
CODE (Optimal)
--------------------------------------------------------

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {

            // detect duplicate block
            if (curr->next && curr->val == curr->next->val) {

                int dup = curr->val;

                // skip entire block
                while (curr && curr->val == dup) {
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete temp;
                }

                prev->next = curr;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};

--------------------------------------------------------
EDGE CASES
--------------------------------------------------------

✓ empty list
✓ single node
✓ all nodes duplicate
✓ duplicates at head
✓ duplicates at tail
✓ long duplicate block

--------------------------------------------------------
POINTER SAFETY PATTERNS (CRITICAL)
--------------------------------------------------------

Golden rule:

Never dereference before guarding.

Whenever accessing:

node->next
node->val

ALWAYS guard first.

--------------------------------------------------------
SAFE PATTERNS TO MEMORIZE
--------------------------------------------------------

Traversal:

while (curr && curr->next)

Duplicate detection:

if (curr->next && curr->val == curr->next->val)

Skip loop:

while (curr && curr->val == dup)

General rule:

if (A && A->B && A->B->C)

Validate left → right.

C++ evaluates left to right.
Wrong order causes crash.

--------------------------------------------------------
COMMON BUGS
--------------------------------------------------------

✗ accessing curr->next when curr is NULL
✗ partial deletion of duplicate block
✗ forgetting to reconnect prev
✗ dangling pointers after delete
✗ losing head without dummy node

Most linked list crashes are null dereference.

--------------------------------------------------------
INVARIANT THINKING
--------------------------------------------------------

Each iteration guarantees:

prefix is clean (no duplicates)
curr points to unexplored suffix
list remains connected

We only mutate duplicate block.

--------------------------------------------------------
COMPLEXITY
--------------------------------------------------------

Each node visited once.

Time  : O(n)
Space : O(1)

--------------------------------------------------------
INTERVIEW TAKEAWAY
--------------------------------------------------------

This problem tests:

- pointer discipline
- duplicate detection
- safe deletion
- invariant maintenance
- null guarding

Mastering this prevents 90% of linked list bugs.

========================================================
END OF NOTES
========================================================
*/
