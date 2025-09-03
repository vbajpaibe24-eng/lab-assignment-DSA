#include <iostream>
using namespace std;

// Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion
// if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number
// of inversions in an array.

int main() {
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int count = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                count++;
            }
        }
    }
    cout << count;
}
