#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n; vector<int>a(n-1);
    for(int i=0;i<n-1;i++)cin>>a[i];
    int total=n*(n+1)/2, sum=accumulate(a.begin(),a.end(),0);
    cout<<total-sum;
}
