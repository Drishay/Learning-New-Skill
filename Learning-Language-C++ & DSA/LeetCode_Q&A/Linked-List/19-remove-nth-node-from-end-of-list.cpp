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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;

        // 1. Reverse list
        head = reverseList(head);

        // 2. Remove nth node from start
        if(n == 1){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        } else {
            ListNode* temp = head;
            int count = 1;

            while(temp->next != NULL){
                if(count == n-1){
                    ListNode* del = temp->next;
                    temp->next = del->next;
                    delete del;
                    break;
                }
                temp = temp->next;
                count++;
            }
        }

        // 3. Reverse back
        head = reverseList(head);
        return head;
    }
};
