// 4.6 Check if a given tree is BST

#include<iostream>
using namespace std; 

struct Node
{
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

// Returns true if given tree is BST.
bool isBST(Node* root, Node* l=NULL, Node* r=NULL)
{
    // Base condition
    if (root == NULL)
        return true;
 
    // if left node exist then check it has
    // correct data or not
    if (l != NULL && root->data < l->data)
        return false;
 
    // if right node exist then check it has
    // correct data or not
    if (r != NULL && root->data > r->data)
        return false;
 
    // check recursively for every node.
    return isBST(root->left, l, root) &&
           isBST(root->right, root, r);
}
 
 
/* Driver program to test above functions*/
int main()
{   
	Node * root= NULL; 
    int range,x;
    cout<<"how many elements :";
    cin>>range;
    for(int i=0;i<range;i++){
        cout<<"enter element: ";
        cin>>x;
        root=Insert(root,x);
    }

    if (isBST(root))
        cout << " Above binary tree is a BST...\n";
    else
        cout << "Above binary tree is not a BST..!\n";
 
    return 0;
}

