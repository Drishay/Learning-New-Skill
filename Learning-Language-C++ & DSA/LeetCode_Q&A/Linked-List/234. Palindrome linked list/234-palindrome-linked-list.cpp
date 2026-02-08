/*
LeetCode 234 – Palindrome Linked List
----------------------------------

Problem:
Check if a singly linked list is a palindrome.

A palindrome reads the same forward and backward.

Constraints:
- O(n) time required
- O(1) extra space preferred
- Cannot copy into array

--------------------------------------------------
CORE IDEA
--------------------------------------------------

Palindrome check = compare first half with reversed second half.

Pattern:
Find middle → Reverse second half → Compare

This is a classic linked list symmetry problem.

--------------------------------------------------
APPROACH: Split → Reverse → Compare
--------------------------------------------------

Steps:

1. Find middle using slow & fast pointers
   - slow moves 1 step
   - fast moves 2 steps
   - when fast ends → slow is middle

Odd size example (9 nodes):
L1 = 5 nodes
L2 = 4 nodes
(middle node ignored in comparison)

Even size example (8 nodes):
L1 = 4 nodes
L2 = 4 nodes

2. Reverse the second half

3. Compare node-by-node
   If mismatch → return false

4. If all equal → return true

Time:  O(n)
Space: O(1)

--------------------------------------------------
VISUAL DRY RUN
--------------------------------------------------

Input:
1 → 2 → 3 → 2 → 1

Split:
1 → 2 → 3
2 → 1

Reverse second:
1 → 2

Compare:
1==1 ✓
2==2 ✓
Palindrome

--------------------------------------------------
COMMON MISTAKES
--------------------------------------------------
- Comparing middle node in odd length
- Forgetting to reverse
- Losing pointer during reverse
- Not handling 1-node edge case

Optional improvement:
- Restore original list after check

--------------------------------------------------
CODE
--------------------------------------------------
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;
        while (second) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // 3. Compare halves
        ListNode* first = head;
        second = prev;

        while (second) {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};

--------------------------------------------------
INTERVIEW NOTES
--------------------------------------------------
- Same skeleton as Reorder List
- Only difference = compare instead of merge
- Recognize reusable pattern:
  split + reverse + operate

Related problems:
- Reorder List (143)
- Reverse List (206)
- Twin Sum Linked List
- Palindrome String (two-pointer symmetry)

Key takeaway:
Most linked list problems are variations of
"cut → reverse → reuse structure"

*/
