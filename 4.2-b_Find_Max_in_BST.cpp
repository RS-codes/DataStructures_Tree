/* 4.2-b find min and max element in a BST   */

/*To find max*/
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


//ftn to find maximum of BST
int FindMax(Node* root){
    if(root==NULL){
        cout<<"Empty"<<endl;
        return -1;
    }
    else if(root->right==NULL){
        return root->data;
    }
    else
        return FindMax(root->right); //recursively
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

    int maxVal=FindMax(root);
    cout<<"Maximum value is : "<<maxVal<<endl;

    return 0;
}
