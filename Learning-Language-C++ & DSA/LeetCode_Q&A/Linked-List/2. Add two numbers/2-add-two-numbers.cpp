#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * Solution class (OOP)
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        return head;
    }
};

/**
 * Helper function to insert node at end
 */
void insertAtTail(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/**
 * Helper function to print linked list
 */
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/**
 * Main function
 */
int main() {
    // Create first number: 342 (stored as 2 -> 4 -> 3)
    ListNode* l1 = nullptr;
    insertAtTail(l1, 2);
    insertAtTail(l1, 4);
    insertAtTail(l1, 3);

    // Create second number: 465 (stored as 5 -> 6 -> 4)
    ListNode* l2 = nullptr;
    insertAtTail(l2, 5);
    insertAtTail(l2, 6);
    insertAtTail(l2, 4);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    // Add two numbers
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}
