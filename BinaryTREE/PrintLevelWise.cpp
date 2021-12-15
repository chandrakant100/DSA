#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"

using namespace std;
BinaryTreeNode<int> *takeInputLevelWise()
{
    int data;
    cout<<"Enter Data of root(Enter 0 to give no value): ";
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
        cout <<"Enter Left Node of "<<value->data<<"(Enter 0 to give no value) :";
        cin>>val;
        
        if (val != 0)
        {
            BinaryTreeNode<int> *leftdata = new BinaryTreeNode<int> (val);
            value->left = leftdata;
            q.push(leftdata); 
        }
        cout <<"Enter Right Node of "<<value->data<<"(Enter 0 to give no value) :";
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
void printTree(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    cout<<root->data<<": ";
    if (root->left != nullptr)
        cout<<"L"<<root->left->data;
    if (root->right != nullptr)
        cout<<", R"<<root->right->data;
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
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
        	cout<<"L:-1,";
        }
        if(val->right != nullptr)
        {
            cout<<"R:"<<val->right->data<<endl;
            q.push(val->right);
        }
        else
        {
        	cout<<"R:-1"<<endl;
        }
    }
}
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
    printTree(root);
    printLevelWise(root);
    delete root;
    return 0;
}