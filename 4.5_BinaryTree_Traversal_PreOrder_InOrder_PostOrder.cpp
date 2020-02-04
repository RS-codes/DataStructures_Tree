/* 4.5 preorder,inorder,post order traversal   */

/*  Preorder(DLR), Inorder (LDR), Postorder(LRD)*/


#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int x){
    Node* temp=new Node;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

Node* Insert(Node* root,int x){
    if(root==NULL){
        root=GetNewNode(x);
    }
    else if(x<root->data){
        root->left=Insert(root->left,x);
    }
    else{
        root->right=Insert(root->right,x);
    }
    return root;
}

//Preorder DLR
void PreOrder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}


//Inorder LDR
void Inorder (Node* root){
    if(root==NULL) return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

//PostOrder LRD
void PostOrder(Node* root){
    if(root==NULL)return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    Node * root= NULL;  //keeping root as local variable
    int range,x;
    cout<<"how many elements :";
    cin>>range;
    for(int i=0;i<range;i++){
        cout<<"enter element: ";
        cin>>x;
        root=Insert(root,x);
    }
    cout<<"Preorder: ";
    PreOrder(root);
    cout<<endl<<"Inorder: ";
    Inorder(root);
    cout<<endl<<"Postorder: ";
    PostOrder(root);
    return 0;
}


