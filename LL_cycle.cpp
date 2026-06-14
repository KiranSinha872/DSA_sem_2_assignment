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

    bool iscyclic(){
        //slow and fast pointer
        Node* slow=head;
        Node* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                return true;
            }
        }
        return false;
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


    l.display();
    if(l.iscyclic()==true){
        cout<<"cyclic";
    }
    else{
        cout<<"no";
    }
    

    return 0;
}