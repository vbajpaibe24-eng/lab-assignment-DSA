#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a={64,34,25,12,22,11,90};
    int n=a.size();
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
    for(int x:a) cout<<x<<" ";
}
