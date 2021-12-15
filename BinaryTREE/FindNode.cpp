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
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    if (root == nullptr)
        return false;
    if (root->data == x)
        return true;
    
    return isNodePresent(root->left,x) || isNodePresent(root->right,x);
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
    cout << isNodePresent(root,3)<<endl;
    delete root;
    return 0;
}