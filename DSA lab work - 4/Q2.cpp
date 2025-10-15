#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int countAndDelete(Node*& head, int key) {
    int count = 0;
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        while (curr->next != NULL && curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        }
        curr = curr->next;
    }
    return count;
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);
    head->next->next->next->next->next = createNode(3);
    head->next->next->next->next->next->next = createNode(1);
    int key = 1;
    int count = countAndDelete(head, key);
    cout << "Count: " << count << " , Updated Linked List: ";
    printList(head);
    return 0;
}
