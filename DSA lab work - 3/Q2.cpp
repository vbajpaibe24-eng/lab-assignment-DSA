#include <iostream>
#include <string>
using namespace std;

#define MAX 100

string reverseString(string str) {
    char stack[MAX];
    int top = -1;

    for (char c : str) {
        stack[top+1] = c;
    }

    string reversed = "";
    while (top >= 0) {
        reversed += stack[top--];
    }
    return reversed;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Reversed: " << reverseString(str) << endl;

    return 0;
}
