/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode;
        while (curr != NULL) {
            nextNode = curr->next; // next save karo
            curr->next = prev;               // link reverse
            prev = curr;                     // prev aage badhao
            curr = nextNode;                 // curr aage badhao
        }
        return prev; // naya head
    }
};


/* reccursive approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // base case
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};

*/