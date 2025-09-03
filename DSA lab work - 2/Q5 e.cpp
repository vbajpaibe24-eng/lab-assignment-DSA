#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int sym[500];
    for(int i = 0; i < n * (n + 1) / 2; i++)
        cin >> sym[i];
    int k = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j)
                k = i * (i + 1) / 2 + j;
            else
                k = j * (j + 1) / 2 + i;
            cout << sym[k] << " ";
        }
        cout << "\n";
    }
}
