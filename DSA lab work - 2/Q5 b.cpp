#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    int td[300];
    for(int i = 0; i < 3 * n - 2; i++)
        cin >> td[i];
    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(abs(i - j) <= 1)
                cout << td[k++] << " ";
            else
                cout << 0 << " ";
        }
        cout << "\n";
    }
}
