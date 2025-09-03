#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int d[100];
    for(int i = 0; i < n; i++)
        cin >> d[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << (i == j ? d[i] : 0) << " ";
        cout << "\n";
    }
}
