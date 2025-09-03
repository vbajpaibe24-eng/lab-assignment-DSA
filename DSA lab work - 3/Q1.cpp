#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    int isEmpty() const { return (top == -1) ? 1 : 0; }
    int isFull() const { return (top == MAX - 1) ? 1 : 0; }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = val;
        cout << "Pushed " << val << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void peek() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top -> ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << (i ? " | " : "");
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\n--- STACK MENU ---\n"
             << "1. Push\n"
             << "2. Pop\n"
             << "3. isEmpty\n"
             << "4. isFull\n"
             << "5. Display\n"
             << "6. Peek\n"
             << "7. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                cout << (s.isEmpty() ? "Stack is Empty\n" : "Stack is NOT Empty\n");
                break;

            case 4:
                cout << (s.isFull() ? "Stack is Full\n" : "Stack is NOT Full\n");
                break;

            case 5:
                s.display();
                break;

            case 6:
                s.peek();
                break;

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
