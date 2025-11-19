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

void preorder(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    int n,x;
    cin>>n;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        root=insertNode(root,x);
    }
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
}
