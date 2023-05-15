#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next = nullptr;
};

void insertIntoTop(Node*& oldHead, int val = 0) {
    Node* newHead = new Node;
    newHead->val = val;
    newHead->next = oldHead;
    oldHead = newHead;
}

void createList(Node*& head, int n) {
    head = new Node;
    n--;
    while (n--) {
        insertIntoTop(head);
    }
}

void enterList(Node* head) {
    for (auto i = head; i != nullptr; i = i->next) {
        if (i != nullptr) {
            int val;
            cin >> val;
            i->val = val;
        }
    }
}

void printList(Node* head) {
    for (auto i = head; i != nullptr; i = i->next) {
        cout << i->val << " ";
    }
}

void reverse(Node*& head, Node* cur = nullptr, Node* last = nullptr) {
    if (cur == nullptr) {
        cur = head;
    }
    if (cur->next == nullptr) {
        cur->next = last;
        head = cur;
        return;
    }
    reverse(head, cur->next, cur);
    cur->next = last;
}

void deleteNodesWithValue(Node*& head, int value) {
    if (head == nullptr) {
        return;
    }

    while (head != nullptr && head->val == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->val == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

void insertAfter(Node* head, int position, int value) {
    if (head == nullptr)
        return;

    Node* currentNode = head;
    int currentPosition = 1;

    while (currentNode != nullptr && currentPosition < position) {
        currentNode = currentNode->next;
        currentPosition++;
    }

    if (currentNode == nullptr)
        return;

    Node* newNode = new Node;
    newNode->val = value;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

int main()
{
    Node* head;
    cout << "Enter size of list: ";

    int n;
    cin >> n;
    createList(head, n);

    int mode, x, elem;

    do {
        cout << "Select action\n1 - Enter list\n2 - Print list\n3 - reverse list\n4 - delete elements with value\n5 - insert element after position\n6 - Quit\n";
        cin >> mode;

        switch (mode) {
        case 1:
            cout << "Enter " << n << " numbers: ";
            enterList(head);
            break;
        case 2:
            cout << "List of " << n << " numbers: ";
            printList(head);
            cout << '\n';
            break;
        case 3:
            reverse(head);
            break;
        case 4:
            cout << "Enter value: ";

            cin >> x;
            deleteNodesWithValue(head, x);
            break;
        case 5:
            cout << "Enter position: ";
            cin >> x;
            cout << "Enter element: ";
            cin >> elem;
            insertAfter(head, x, elem);
            break;
        default:
            break;
        }
        cout << "----------------------------------------\n";
    } while (mode != 6);
}
