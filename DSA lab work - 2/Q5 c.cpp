#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int lt[500];
    for(int i = 0; i < n * (n + 1) / 2; i++)
        cin >> lt[i];
    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j)
                cout << lt[k++] << " ";
            else
                cout << 0 << " ";
        }
        cout << "\n";
    }
}
