/* //first brute force approach but gives TLE and pointer error, no edge cases handled
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int rotate = 0;
        ListNode* temp = head;
        ListNode* add = NULL;
        while(rotate != k){
            rotate++;
            while(temp ->next ->next !=NULL){
                temp = temp->next;
            }
            add = temp->next;
            temp->next = NULL;

            add->next = head;
            head = add;
            temp = head;
        }
        return head;
    }
};
*/


/* //optimized approach, handles edge cases as well, make the list circular and then break at the right point
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length and tail
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // Step 2: Reduce k
        k = k % len;
        if (k == 0) return head;

        // Step 3: Make it circular
        tail->next = head;

        // Step 4: Find new tail
        int steps = len - k;
        ListNode* newTail = head;
        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // Step 5: Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};


*/