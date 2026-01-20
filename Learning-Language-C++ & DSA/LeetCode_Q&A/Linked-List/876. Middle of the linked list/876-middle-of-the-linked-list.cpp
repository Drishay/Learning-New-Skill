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

/* time complexity: O(n) space complexity: O(1), brute force approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }

        int k = size/2 + 1;
        cout<<k;
        temp = head;
        int count = 0;
        while(count<k-1){
            count++;
            temp = temp->next;
        }
        return temp;
    }
};

*/

/*

// time complexity: O(n) space complexity: O(1), optimal approach (two pointer approach), fast and slow pointer.
// it is better to use the above optimal approach for this problem. It is more efficient in terms of time complexity.
// tortoise and hare algorithm
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            // move slow pointer one step
            slow = slow->next; 
            // move fast pointer two steps, when fast pointer reaches the end, slow pointer will be at the middle. For even length linked list, it will be at the second middle node, exactly as required.
            fast = fast->next->next; 
        }
        return slow;
    }
};
*/