/* first approach: hash set to store visited nodes - detect cycle if a node is revisited  - brute force
First Approach: Using Hashing (My Logic)
Idea

I traverse the linked list node by node and store the address (pointer) of each visited node in a hash data structure 
(unordered_map / unordered_set). If during traversal the same node address appears again, it means the linked list 
contains a cycle.

Time Complexity: O(n)
Space Complexity: O(n) (extra space for storing node addresses)


bool hasCycle(ListNode* head) {
    unordered_set<ListNode*> visited;
    ListNode* current = head;
    while (current != nullptr) {
        if (visited.count(current)) {
            return true;  // cycle detected
        }
        visited.insert(current);
        current = current->next;
    }
    return false;
}


*/


/*
second approach: Floyd’s Cycle-Finding Algorithm (Tortoise and Hare Algorithm) - optimized
bool hasCycle(ListNode* head) {
    if (head == NULL) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}
Time Complexity: O(n)
Space Complexity: O(1)
*/