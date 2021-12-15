#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"

using namespace std;
BinaryTreeNode<int> *takeInputLevelWise()
{
    int data;
    cout<<"Enter Data of root(Enter 0 to give no value): "<<endl;
    cin>>data;

    if (data == 0)
        return nullptr;
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (data);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *value = q.front();
        q.pop();
        int val;
        cout <<"Enter Left Node of "<<value->data<<"(Enter 0 to give no value) :"<<endl;
        cin>>val;
        
        if (val != 0)
        {
            BinaryTreeNode<int> *leftdata = new BinaryTreeNode<int> (val);
            value->left = leftdata;
            q.push(leftdata); 
        }
        cout <<"Enter Right Node of "<<value->data<<"(Enter 0 to give no value) :"<<endl;
        cin>>val;
        if (val != 0)
        {
            BinaryTreeNode<int> *rightdata = new BinaryTreeNode<int> (val);
            value->right = rightdata;
            q.push(rightdata); 
        }
        
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    if (root == nullptr)
        return;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    
    while(!q.empty())
    {
        BinaryTreeNode<int> *val = q.front();
        q.pop();
        
        cout<<val->data<<":";
        
        if (val->left != nullptr)
        {
            cout<<"L:"<<val->left->data<<",";
            q.push(val->left);
        }
        else
        {
        	cout<<"L:0,";
        }
        if(val->right != nullptr)
        {
            cout<<"R:"<<val->right->data<<endl;
            q.push(val->right);
        }
        else
        {
        	cout<<"R:0"<<endl;
        }
    }
}
void preOrder(BinaryTreeNode<int> *root) {
    if (root == nullptr)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
//input
// 1 2 3 4 5 6 7 0 0 0 0 8 9 0 0 0 0 0 0 
int main()
{
    /*
    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int> (2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int> (3);
    BinaryTreeNode<int> *node3 = new BinaryTreeNode<int> (4);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    */
    BinaryTreeNode<int> *root = takeInputLevelWise();
    if (root == nullptr)
        cout<<"NoTree"<<endl;
    printLevelWise(root);
    
    cout<<"\nPre-Order Traversal:"<<endl;
    preOrder(root);

    cout<<"\nIn-Order Traversal:"<<endl;
    inOrder(root);

    cout<<"\nPost-Order Traversal:"<<endl;
    postOrder(root);
    delete root;
    return 0;
}