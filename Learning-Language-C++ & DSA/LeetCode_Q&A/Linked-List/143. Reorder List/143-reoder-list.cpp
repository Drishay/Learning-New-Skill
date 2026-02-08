/*
LeetCode 143 – Reorder List
----------------------------------

Problem:
Reorder a linked list from:

L0 → L1 → L2 → … → Ln

into:

L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

Constraints:
- Cannot modify node values
- Must reorder by changing pointers
- In-place solution required

--------------------------------------------------
CORE IDEA
--------------------------------------------------

This problem is a combination of 3 classic patterns:

1. Find middle of linked list
2. Reverse second half
3. Merge two lists alternately

This is a common interview pattern:
"Split + Reverse + Merge"

--------------------------------------------------
APPROACH: Middle → Reverse → Merge
--------------------------------------------------

Steps:

1. Find middle using slow & fast pointer
   - slow moves 1 step
   - fast moves 2 steps
   - when fast reaches end → slow is middle

2. Split into two lists
   second = slow->next
   slow->next = NULL

   first half:  head → ... → slow
   second half: second → end

3. Reverse the second half

4. Merge alternately:
   first → second → first → second...

Why it works:
- First half stays in order
- Second half reversed gives correct pairing
- Alternating merge produces required sequence

Time:  O(n)
Space: O(1)

--------------------------------------------------
VISUAL DRY RUN
--------------------------------------------------

Input:
1 → 2 → 3 → 4 → 5

Middle split:
1 → 2 → 3
4 → 5

Reverse second:
5 → 4

Merge:
1 → 5 → 2 → 4 → 3

--------------------------------------------------
COMMON MISTAKES
--------------------------------------------------
- Forgetting to cut at middle (creates cycle)
- Losing next pointer during merge
- Reversing wrong half
- Not handling small lists (0,1,2 nodes)

--------------------------------------------------
CODE
--------------------------------------------------
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* second = slow->next;
        slow->next = NULL;   // split list

        ListNode* prev = NULL;
        while (second) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // prev is head of reversed second half
        ListNode* first = head;
        second = prev;

        // 3. Merge alternately
        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};

--------------------------------------------------
INTERVIEW NOTES
--------------------------------------------------
- This problem tests multiple linked list skills
- Recognize pattern: split + reverse + weave
- Always draw pointer diagram while coding
- O(1) space is key requirement

Pattern reuse problems:
- Palindrome Linked List
- Reverse List
- Merge Two Lists
- Split List in Parts

*/
