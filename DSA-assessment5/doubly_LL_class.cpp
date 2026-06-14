// Implement Doubly Linked List Class
// Insert Front
// Insert End
// Delete Node
// Reverse DLL
// Traverse Circular Linked List



#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};


// Doubly Linked List Class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at Front
    void insertFront(int x) {

        Node* newNode = new Node(x);

        newNode->next = head;

        if(head != NULL)
            head->prev = newNode;

        head = newNode;
    }

    // Insert at End
    void insertEnd(int x) {

        Node* newNode = new Node(x);

        if(head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete First Occurrence of Value
    void deleteNode(int x) {

        if(head == NULL)
            return;

        Node* temp = head;

        while(temp != NULL && temp->data != x)
            temp = temp->next;

        if(temp == NULL) {
            cout << "Value not found\n";
            return;
        }

        // Delete head node
        if(temp == head) {

            head = head->next;

            if(head != NULL)
                head->prev = NULL;

            delete temp;
            return;
        }

        if(temp->prev)
            temp->prev->next = temp->next;

        if(temp->next)
            temp->next->prev = temp->prev;

        delete temp;
    }

    // Reverse Doubly Linked List
    void reverseDLL() {

        Node* curr = head;
        Node* temp = NULL;

        while(curr != NULL) {

            // Swap prev and next
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }

        if(temp != NULL)
            head = temp->prev;
    }

    // Traverse DLL
    void print() {

        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

// Circular Linked List Node
class CNode {
public:
    int data;
    CNode* next;

    CNode(int x) {
        data = x;
        next = NULL;
    }
};

// Traverse Circular Linked List
void printCircular(CNode* head) {

    if(head == NULL)
        return;

    CNode* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while(temp != head);

    cout << endl;
}

int main() {

    DoublyLinkedList dll;

    // Insert Front
    dll.insertFront(20);
    dll.insertFront(10);

    // Insert End
    dll.insertEnd(30);
    dll.insertEnd(40);

    cout << "Doubly Linked List: ";
    dll.print();

    // Delete Node
    dll.deleteNode(30);

    cout << "After deleting 30: ";
    dll.print();

    // Reverse DLL
    dll.reverseDLL();

    cout << "After reversing: ";
    dll.print();

    // Circular Linked List
    CNode* head = new CNode(1);
    CNode* second = new CNode(2);
    CNode* third = new CNode(3);
    CNode* fourth = new CNode(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head; // Makes list circular

    cout << "Circular Linked List: ";
    printCircular(head);

    return 0;
}