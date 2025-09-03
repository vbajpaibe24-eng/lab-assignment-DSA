#include <iostream>
using namespace std;

void swapInt(int &a, int &b) {
    int t;
    t = a;
    a = b;
    b = t;
}

int main() {
    int r,c,n;
    cin >> r;
    cin >> c;
    cin >> n;
    int row[100];
    int col[100];
    int val[100];
    for(int i = 0; i < n; i++) {
        cin >> row[i];
        cin >> col[i];
        cin >> val[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(row[i] > row[j] || (row[i] == row[j] && col[i] > col[j])) {
                swapInt(row[i], row[j]);
                swapInt(col[i], col[j]);
                swapInt(val[i], val[j]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        swapInt(row[i], col[i]);
    }
    for(int i = 0; i < n; i++) {
        cout << row[i] << " " << col[i] << " " << val[i] << "\n";
    }
}
