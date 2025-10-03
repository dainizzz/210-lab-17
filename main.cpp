// COMSC-210 | Lab 17 | Dainiz Almazan
// IDE used: CLion

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

// addNodeToFront() adds a node with the value tmp_value to the front of the linked list
// arguments: a pointer to the head node of a linked list of type Node, a float value
// returns: nothing
void addNodeToFront(Node *&, float);

// addNodeToFront() adds a node with the value tmp_value to the end of the linked list
// arguments: a pointer to the head node of a linked list of type Node, a float value
// returns: nothing
void addNodeToTail(Node *&, float);

// insertNode() inserts a node with a value tmp_value at the position specified by the user
// arguments: a pointer to the head node of a linked list of type Node, a float value
// returns: nothing
void insertNode(Node *&, float);

// deleteNode() prompts the user to specify a linked list node to be deleted and then deletes that node
// arguments: a pointer to the head node of a linked list of type Node
// returns: nothing
void deleteNode(Node *&);

// deleteList() deletes all elements in a linked list
// arguments: a pointer to the head node of a linked list of type Node
// returns: nothing
void deleteList(Node *&);

int main() {
    Node *head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        // Explicitly converting from int to float
        auto tmp_val = static_cast<float>(rand() % 100);
        if (!head) { // if this is the first node, it's the new head
            addNodeToFront(head, tmp_val);
        }
        else { // it's a second or subsequent node; place at the head
            addNodeToTail(head, tmp_val);
        }
    }
    output(head);

    deleteNode(head);
    output(head);

    insertNode(head, 10000);
    output(head);

    deleteList(head);
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

// The below functions all use pass by reference because the nodes need to be directly modified
void addNodeToFront(Node *&head, float tmp_val) {
    Node *newVal = new Node;
    head = newVal;
    newVal->next = nullptr;
    newVal->value = tmp_val;
}

void addNodeToTail(Node *&head, float tmp_val) {
    Node *newVal = new Node;
    newVal->next = head;
    newVal->value = tmp_val;
    head = newVal;
}

void insertNode(Node *&head, float tmp_val) {
    int entry;
    cout << "After which node to insert " << tmp_val << "? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;

    Node *current = head;
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
    newnode->value = tmp_val;
    newnode->next = current;
    prev->next = newnode;
}

void deleteNode(Node *&head) {
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
}

void deleteList(Node *&head) {
    Node * current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}
