#include <iostream>
using namespace std;

void heapify(int a[],int n,int i){
    int l=2*i+1, r=2*i+2, mx=i;
    if(l<n && a[l]>a[mx]) mx=l;
    if(r<n && a[r]>a[mx]) mx=r;
    if(mx!=i){
        int t=a[i]; a[i]=a[mx]; a[mx]=t;
        heapify(a,n,mx);
    }
}

void heapSort(int a[],int n){
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>=0;i--){
        int t=a[0]; a[0]=a[i]; a[i]=t;
        heapify(a,i,0);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    heapSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
