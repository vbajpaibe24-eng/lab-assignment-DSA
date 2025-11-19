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

Node* searchRec(Node* root,int x){
    if(root==NULL || root->data==x) return root;
    if(x<root->data) return searchRec(root->left,x);
    else return searchRec(root->right,x);
}

Node* searchIter(Node* root,int x){
    while(root && root->data!=x){
        if(x<root->data) root=root->left;
        else root=root->right;
    }
    return root;
}

Node* maxNode(Node* root){
    while(root->right) root=root->right;
    return root;
}

Node* minNode(Node* root){
    while(root->left) root=root->left;
    return root;
}

Node* inorderSuccessor(Node* root,Node* n){
    if(n->right) return minNode(n->right);
    Node* s=NULL;
    while(root){
        if(n->data<root->data){
            s=root;
            root=root->left;
        } else if(n->data>root->data){
            root=root->right;
        } else break;
    }
    return s;
}

Node* inorderPredecessor(Node* root,Node* n){
    if(n->left) return maxNode(n->left);
    Node* p=NULL;
    while(root){
        if(n->data>root->data){
            p=root;
            root=root->right;
        } else if(n->data<root->data){
            root=root->left;
        } else break;
    }
    return p;
}

int main(){
    int n,x;
    cin>>n;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        root=insertNode(root,x);
    }
    int key; cin>>key;
    Node* f=searchRec(root,key);
    if(f) cout<<f->data<<endl;

    f=searchIter(root,key);
    if(f) cout<<f->data<<endl;

    cout<<maxNode(root)->data<<endl;
    cout<<minNode(root)->data<<endl;

    Node* s=inorderSuccessor(root,searchRec(root,key));
    if(s) cout<<s->data<<endl;

    Node* p=inorderPredecessor(root,searchRec(root,key));
    if(p) cout<<p->data;
}
