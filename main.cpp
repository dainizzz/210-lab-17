#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// output() outputs the values of the elements of a linked list and numbers them
// arguments: a pointer to the head node of a linked list of type Node
// returns: nothing
void output(Node *);

// <description>
// arguments:
// returns:
void addNodeToFront(Node *);

// <description>
// arguments:
// returns:
void addNodeToTail(Node *);

// <description>
// arguments:
// returns:
void insertNode(Node *, Node *);

// deleteNode() prompts the user for the number of the linked list item to be deleted and deletes the node
// arguments: a pointer to the head node of a linked list of type Node
// returns: nothing
void deleteNode(Node *);

// <description>
// arguments:
// returns:
void deleteList(Node *);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    deleteNode(head);

    // // deleting a node
    // Node * current = head;
    // cout << "Which node to delete? " << endl;
    // output(head);
    // int entry;
    // cout << "Choice --> ";
    // cin >> entry;
    //
    // // traverse that many times and delete that node
    // current = head;
    // Node *prev = head;
    // for (int i = 0; i < (entry-1); i++)
    //     if (i == 0)
    //         current = current->next;
    //     else {
    //         current = current->next;
    //         prev = prev->next;
    //     }
    // // at this point, delete current and reroute pointers
    // if (current) {  // checks for current to be valid before deleting the node
    //     prev->next = current->next;
    //     delete current;
    //     current = nullptr;
    // }
    // output(head);

    // insert a node
    Node *current = head;
    int entry;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addNodeToFront(Node *) {
}

void addNodeToTail(Node *) {
}

void insertNode(Node *, Node *) {
}

void deleteNode(Node *head) {
    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node * current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);
}

void deleteList(Node *) {
}
