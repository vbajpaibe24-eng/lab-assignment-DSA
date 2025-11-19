#include <iostream>
using namespace std;

int heapArr[1000], heapSize=0;

void pushPQ(int x){
    heapArr[heapSize]=x;
    int i=heapSize;
    heapSize++;
    while(i>0 && heapArr[(i-1)/2]<heapArr[i]){
        int t=heapArr[i];
        heapArr[i]=heapArr[(i-1)/2];
        heapArr[(i-1)/2]=t;
        i=(i-1)/2;
    }
}

int popPQ(){
    int r=heapArr[0];
    heapSize--;
    heapArr[0]=heapArr[heapSize];
    int i=0;
    while(true){
        int l=2*i+1,r2=2*i+2,m=i;
        if(l<heapSize && heapArr[l]>heapArr[m]) m=l;
        if(r2<heapSize && heapArr[r2]>heapArr[m]) m=r2;
        if(m==i) break;
        int t=heapArr[i]; heapArr[i]=heapArr[m]; heapArr[m]=t;
        i=m;
    }
    return r;
}

int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        pushPQ(x);
    }
    while(heapSize){
        cout<<popPQ()<<" ";
    }
}
