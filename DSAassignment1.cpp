#include <bits/stdc++.h>
using namespace std;

// Class blueprint for a single Node
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function for printing linked list
void printlist(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Insert from front
void insF(Node*& x, Node*& head) {
    x->next = head;
    head = x;
}

// Delete from front
void delf(Node*& head) {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Insert from back
void insE(Node*& x, Node*& head) {
    if (head == NULL) {
        head = x;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = x;
}

// Delete from back
void delb(Node*& head) {
    if (head == NULL) return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Insert at any position
void ip(Node*& x, Node*& head, int pos) {
    if (pos == 1) {
        x->next = head;
        head = x;
        return;
    }

    int cnt = 1;
    Node* temp = head;

    while (temp != NULL && cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) return;

    x->next = temp->next;
    temp->next = x;
}

// Delete from any position
void dfp(Node*& head, int posn) {
    if (head == NULL) return;

    if (posn == 1) {
        delf(head);
        return;
    }

    int cnt = 1;
    Node* temp = head;

    while (temp != NULL && cnt < posn - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL || temp->next == NULL) return;

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// Searching a key
bool search(Node*& head, int key) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

// Finding position of a key (1-based indexing)
int index(Node*& head, int key) {
    int posn = 1;

    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            return posn;
        }

        posn++;
        temp = temp->next;
    }

    return -1;
}

// Finding length of linked list
int len(Node* head) {
    int cnt = 0;

    Node* temp = head;

    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    // Creating initial linked list
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        Node* newnode = new Node(val);

        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    cout << "Original List:" << endl;
    printlist(head);

    // Insert Front
    Node* newn = new Node(11);
    insF(newn, head);
    cout << "After Insert Front:" << endl;
    printlist(head);

    // Insert End
    Node* newn2 = new Node(60);
    insE(newn2, head);
    cout << "After Insert End:" << endl;
    printlist(head);

    // Insert Position
    Node* new3 = new Node(25);
    ip(new3, head, 4);
    cout << "After Insert at Position 4:" << endl;
    printlist(head);

    // Delete Front
    delf(head);
    cout << "After Delete Front:" << endl;
    printlist(head);

    // Delete Back
    delb(head);
    cout << "After Delete Back:" << endl;
    printlist(head);

    // Delete Position
    dfp(head, 3);
    cout << "After Delete Position 3:" << endl;
    printlist(head);

    // Search key
    cout << "Search 30: " << search(head, 30) << endl;

    // Length
    cout << "Length: " << len(head) << endl;

    // Position of key
    cout << "Position of 21: " << index(head, 21) << endl;

    return 0;
}