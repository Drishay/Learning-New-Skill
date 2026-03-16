/*
brute force approach using hash set to store the visited nodes
and if we encounter a node which is already present in the map
then we return that node as the starting point of the cycle

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;

        unordered_set<ListNode*> visited;
        ListNode* temp = head;

        while (temp != NULL) {
            if (visited.find(temp) != visited.end()) {
                // cycle entry point
                return temp;
            }
            visited.insert(temp);
            temp = temp->next;
        }

        return NULL; // no cycle
    }
};

time complexity: O(N)
space complexity: O(N) (for the hash set as we may store all nodes in the worst case)
*/

/*
Optimal Approach: Floyd’s Tortoise and Hare Algorithm
# Problem Statement
    Given the head of a linked list, determine the node where the cycle begins.
    If there is no cycle, return nullptr.

# Approach Overview

    We use Floyd’s Cycle Detection Algorithm, which works in two phases:
    Cycle Detection
    Use two pointers:
        slow → moves 1 step at a time
        fast → moves 2 steps at a time
    If a cycle exists, they will eventually meet inside the cycle.
    Finding the Entry Point of the Cycle
    After detection, place a new pointer entry at the head.
    Move both entry and fast one step at a time.
    The node where they meet is the starting point of the cycle.

# Why Phase 2 Works (Intuition / Math)
    Let:
    a = distance from head to cycle start
    b = distance from cycle start to meeting point
    c = remaining length of the cycle
    When slow and fast meet:
        2(a + b) = a + b + c + b
        ⇒ a = c
        
    This means:
        The distance from head to cycle start
        Equals the distance from meeting point to cycle start (moving forward)
        So, moving both pointers one step at a time guarantees they meet at the cycle entry.

# Code Implementation
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Edge case: empty list or single node
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // Cycle detected
                // Phase 2: Find entry point of the cycle
                ListNode* entry = head;
                while (entry != fast) {
                    entry = entry->next;
                    fast = fast->next;
                }
                return entry; // Cycle entry node
            }
        }

        return nullptr; // No cycle
    }
};

# Complexity Analysis

Time Complexity: O(N)

Space Complexity: O(1) (no extra data structures used)

*/