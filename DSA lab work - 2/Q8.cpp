#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        int unique = 1;
        for(int j = 0; j < i; j++) {
            if(a[i] == a[j]) {
                unique = 0;
                break;
            }
        }
        if(unique) {
            count++;
        }
    }
    cout << count;
}

