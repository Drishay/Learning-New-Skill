/*
LeetCode 24 — Swap Nodes in Pairs
-----------------------------------

Problem:
Given the head of a singly linked list, swap every two adjacent nodes
and return the new head. Nodes must be swapped by changing links,
not values.

Example:
Input:  1 -> 2 -> 3 -> 4
Output: 2 -> 1 -> 4 -> 3

Key Idea:
For every pair:
    prev -> first -> second -> nextPair

After swap:
    prev -> second -> first -> nextPair

Steps per iteration:
1. Save next pair.
2. Swap first and second.
3. Connect previous part to swapped pair.
4. Move pointers forward.

Complexity:
Time  : O(n)  (each node visited once)
Space : O(1)  (constant extra pointers)

This is the optimal iterative solution.
*/

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // No swap possible
        if (!head || !head->next)
            return head;

        // Dummy node helps handle head swap easily
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* current = head;

        while (current && current->next) {
            ListNode* first = current;
            ListNode* second = current->next;

            // Save start of next pair
            ListNode* nextPair = second->next;

            // Perform swap
            second->next = first;
            first->next = nextPair;
            prev->next = second;

            // Move pointers forward
            prev = first;
            current = nextPair;
        }

        return dummy.next;
    }
};
