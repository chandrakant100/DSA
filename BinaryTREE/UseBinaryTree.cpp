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
    
    delete root;
    return 0;
}