#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            head = NULL;
        }
        
    void insertatEnd(int value){ //insert at end with tiem complexity of O(n)
        Node* newNode = new Node(value);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertatBeginning(int value){ //insert at beginning with time complexity of O(1)
        Node* newNode = new Node(value);
        if(head == NULL){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    
    void insertatPosition(int value, int position){ //insert at given position with time complexity of O(n)
        Node* newNode = new Node(value);
        if(position == 0){
            newNode->next = head;
            head = newNode;
            return; //or insert at beginning 
        }
        Node* temp = head;
        for(int i = 0; i < position - 1 && temp != NULL; i++){
            temp = temp->next;
        }
        if(temp == NULL){
            cout << "Position out of bounds" << endl;
            delete newNode; // Free the allocated memory
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void insertatValue(int valueToFind, int valueToInsert){ //insert after a given value with time complexity of O(n)
        Node* newNode = new Node(valueToInsert);
        if(head == NULL){
            cout << "List is empty" << endl;
            delete newNode; // Free the allocated memory
            return;
        }
        Node* temp = head;
        while(temp != NULL && temp->data != valueToFind){
            temp = temp->next;
        }
        if(temp == NULL){
            cout << "Value not found in the list" << endl;
            delete newNode; // Free the allocated memory
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void displayList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteHead(){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteTail() {
        // Case 1: Empty list
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        // Case 2: Only one node
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        // Case 3: More than one node
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    void deleteatPosition(int position){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        if(position == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        for(int i = 0; i < position - 1 && temp != NULL; i++){
            temp = temp->next;
        }
        if(temp == NULL || temp->next == NULL){
            cout << "Position out of bounds" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void deleteByValue(int value){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        if(head->data == value){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL && temp->next->data != value){
            temp = temp->next;
        }
        if(temp->next == NULL){
            cout << "Value not found in the list" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

};




int main() {
    LinkedList list;
    list.insertatEnd(10);
    list.insertatEnd(20);
    list.insertatEnd(30);

    // Display the linked list
    list.displayList();// Output: 10 -> 20 -> 30 -> NULL
    list.insertatBeginning(5);
    list.displayList(); // Output: 5 -> 10 -> 20 -> 30 -> NULL

    return 0;
}