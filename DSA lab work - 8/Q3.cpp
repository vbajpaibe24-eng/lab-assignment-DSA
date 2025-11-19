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
    else if(x>root->data) root->right=insertNode(root->right,x);
    return root;
}

Node* minNode(Node* root){
    while(root->left) root=root->left;
    return root;
}

Node* deleteNode(Node* root,int x){
    if(root==NULL) return root;
    if(x<root->data) root->left=deleteNode(root->left,x);
    else if(x>root->data) root->right=deleteNode(root->right,x);
    else{
        if(root->left==NULL){
            Node* t=root->right;
            delete root;
            return t;
        }
        else if(root->right==NULL){
            Node* t=root->left;
            delete root;
            return t;
        }
        Node* t=minNode(root->right);
        root->data=t->data;
        root->right=deleteNode(root->right,t->data);
    }
    return root;
}

int maxDepth(Node* root){
    if(root==NULL) return 0;
    int l=maxDepth(root->left);
    int r=maxDepth(root->right);
    return 1+(l>r?l:r);
}

int minDepth(Node* root){
    if(root==NULL) return 0;
    int l=minDepth(root->left);
    int r=minDepth(root->right);
    if(!root->left || !root->right) return 1+l+r;
    return 1+(l<r?l:r);
}

int main(){
    int n,x;
    cin>>n;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        root=insertNode(root,x);
    }
    int del; cin>>del;
    root=deleteNode(root,del);
    cout<<maxDepth(root)<<" "<<minDepth(root);
}
