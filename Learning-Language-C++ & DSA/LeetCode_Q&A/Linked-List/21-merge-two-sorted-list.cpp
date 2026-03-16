/* //first approach (using extra space)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(list1 != NULL || list2 != NULL){
            if(list1 == NULL){
                ListNode* newNode = new ListNode(list2->val);
                if(head == NULL){
                    head = newNode;
                    tail = newNode;
                }
                else{
                    tail->next = newNode;
                    tail = newNode;
                }
                list2 = list2->next;
            }
            else if(list2 == NULL){
                ListNode* newNode = new ListNode(list1->val);
                if(head == NULL){
                    head = newNode;
                    tail = newNode;
                }
                else{
                    tail->next = newNode;
                    tail = newNode;
                }
                list1 = list1->next;
            }

            else if(list1->val < list2->val){
                ListNode* newNode = new ListNode(list1->val);
                if(head == NULL){
                    head = newNode;
                    tail = newNode;
                }
                else{
                    tail->next = newNode;
                    tail = newNode;
                }
                list1 = list1->next;
            }

            else if(list1->val > list2->val){
                ListNode* newNode = new ListNode(list2->val);
                if(head == NULL){
                    head = newNode;
                    tail = newNode;
                }
                else{
                    tail->next = newNode;
                    tail = newNode;
                }
                list2 = list2->next;
            }
            else{
                ListNode* newNode = new ListNode(list2->val);
                if(head == NULL){
                    head = newNode;
                    tail = newNode;
                }
                else{
                    tail->next = newNode;
                    tail = newNode;
                }

                ListNode* newNode1 = new ListNode(list1->val);
                if(head == NULL){
                    head = newNode1;
                    tail = newNode1;
                }
                else{
                    tail->next = newNode1;
                    tail = newNode1;
                }

                list2 = list2->next;
                list1 = list1->next;
            }

        }
        return head;
    }
};

*/


/* adding modularity to reduce code duplication

class Solution {
private:
    void appendNode(ListNode*& head, ListNode*& tail, int value) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                appendNode(head, tail, list2->val);
                list2 = list2->next;
            }
            else if (list2 == nullptr) {
                appendNode(head, tail, list1->val);
                list1 = list1->next;
            }
            else if (list1->val < list2->val) {
                appendNode(head, tail, list1->val);
                list1 = list1->next;
            }
            else if (list1->val > list2->val) {
                appendNode(head, tail, list2->val);
                list2 = list2->next;
            }
            else { // equal values
                appendNode(head, tail, list1->val);
                appendNode(head, tail, list2->val);
                list1 = list1->next;
                list2 = list2->next;
            }
        }

        return head;
    }
};

*/


/* dummy node approach
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

*/


/* in-place merging without extra space
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        // Initialize head
        if (list1->val <= list2->val) {
            head = tail = list1;
            list1 = list1->next;
        } else {
            head = tail = list2;
            list2 = list2->next;
        }

        // Merge in-place
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes
        tail->next = list1 ? list1 : list2;

        return head;
    }
};


*/