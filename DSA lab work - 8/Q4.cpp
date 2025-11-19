#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x){
    Node* n=new Node;
    n->data=x;
    n->left=n->right=NULL;
    return n;
}

Node* insertNode(Node* root,int x){
    if(root==NULL) return newNode(x);
    if(x<root->data) root->left=insertNode(root->left,x);
    else root->right=insertNode(root->right,x);
    return root;
}

bool isBST(Node* root,int minv,int maxv){
    if(root==NULL) return true;
    if(root->data<=minv || root->data>=maxv) return false;
    return isBST(root->left,minv,root->data) && isBST(root->right,root->data,maxv);
}

int main(){
    int n,x;
    cin>>n;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        root=insertNode(root,x);
    }
    cout<<isBST(root,-1000000000,1000000000);
}
