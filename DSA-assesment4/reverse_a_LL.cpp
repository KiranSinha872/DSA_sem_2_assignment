#include <bits/stdc++.h>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Linked List class
class Linklist {
public:
    Node* head;

    Linklist() {
        head = NULL;
    }

    // Insert at front
    void insF(int x) {
        Node* newnode = new Node(x);

        newnode->next = head;
        head = newnode;
    }

    // Display linked list
    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }


//reverse a linked list
 void reversed(){

    //3 pointers
    Node* prev = NULL;
    Node* curr = head;
    Node* nextnode = NULL;

    while(curr!=NULL){
        // 4steps
        // stores the remaining list
        nextnode=curr->next;
        //curr points towards prev
        curr->next=prev;
        // ageh badhadiya
        prev=curr;
        curr=nextnode;
    }
    head=prev;
    //here prev became the head
 }
 
};

int main() {

    Linklist l;

    int n;
    cin >> n;

    // Input n elements and insert at end
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        l.insF(val);
    }
    l.reversed();
    l.display();

    return 0;
}