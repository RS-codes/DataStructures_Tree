/* 4.1 Binary Search Tree - BST implementation  */ 

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

bool Search(Node* root,int x){
    if(root==NULL) return false;
    if(root->data==x) return true;
    else if(x<=root->data)
        return Search(root->left,x);
    else return Search(root->right,x);

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
   
    int num;
    cout<<"Enter number to search: ";
    cin>>num;
    if(Search(root,num)==true)
        cout<<num<<" found"<<endl;
    else cout<<num<<" Not found"<<endl;
    return 0;
}

