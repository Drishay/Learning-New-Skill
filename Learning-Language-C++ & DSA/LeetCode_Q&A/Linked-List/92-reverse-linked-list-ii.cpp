/*
LeetCode 92 – Reverse Linked List II
----------------------------------

Problem:
Reverse a linked list from position `left` to `right` (1-indexed) in one pass,
without changing node values.

Key Observations:
- Only pointers are allowed (no extra data structures).
- left can be 1 → always use a dummy node.
- Time must be O(n), space O(1).

--------------------------------------------------
APPROACH 1: Cut → Reverse → Join (Helper Function)
--------------------------------------------------

Steps:
1. Create a dummy node pointing to head (handles left = 1).
2. Move `prev` pointer to node just before `left` (left - 1).
3. Identify:
   - leftNode  = first node of sublist
   - rightNode = last node of sublist
   - rightNext = node after right
4. Cut the list:
   prev->next = NULL
   rightNode->next = NULL
5. Reverse the isolated sublist using standard reverse().
6. Join back:
   prev->next = reversedHead
   leftNode->next = rightNext
7. Return dummy.next.

Why it works:
- Sublist is fully isolated → safe to reverse normally.
- leftNode becomes tail after reversal.
- rightNode becomes new head of sublist.

Time:  O(n)
Space: O(1)

code ----
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 1. Setup
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // 2. Move prev to left-1
        for (int i = 1; i < left; i++)
            prev = prev->next;

        // 3. Identify boundaries
        ListNode* leftNode = prev->next;
        ListNode* rightNode = leftNode;
        for (int i = left; i < right; i++)
            rightNode = rightNode->next;

        ListNode* rightNext = rightNode->next;

        // 4. Cut
        prev->next = NULL;
        rightNode->next = NULL;

        // 5. Reverse isolated list
        ListNode* reversedHead = reverse(leftNode);

        // 6. Join
        prev->next = reversedHead;
        leftNode->next = rightNext;

        // 7. Return
        return dummy.next;

    }
};



--------------------------------------------------
APPROACH 2: In-place Head Insertion (Preferred)
--------------------------------------------------

Idea:
- Do NOT cut the list.
- Repeatedly move the node after `curr`
  and insert it right after `prev`.

Steps:
1. Use dummy node.
2. Move `prev` to left - 1.
3. Let `curr = prev->next`.
4. Repeat (right - left) times:
   - temp = curr->next
   - curr->next = temp->next
   - temp->next = prev->next
   - prev->next = temp

Why it works:
- Nodes are re-ordered within the range.
- No link is ever lost.
- Cleaner and pointer-safe.

Time:  O(n)
Space: O(1)

--------------------------------------------------
INTERVIEW NOTES
--------------------------------------------------
- No built-in reverse() exists in LeetCode.
- Helper reverse() is allowed if written by you.
- Both approaches are optimal.
- Head insertion is cleaner; cut+reverse is intuitive.

Common Mistakes:
- Forgetting dummy node (breaks left = 1).
- Losing rightNext before cutting.
- Not reconnecting tail properly.

code----
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++)
            prev = prev->next;

        ListNode* curr = prev->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy.next;
    }

};
*/



