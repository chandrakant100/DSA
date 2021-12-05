#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;

TreeNode<int> *InsertInOrder()
{
    int root;
    cout<<"Enter the root data: ";
    cin>>root;
    TreeNode<int> *rootNode = new TreeNode<int> (root);

    queue<TreeNode<int> *> q;
    q.push(rootNode);

    while(!q.empty())
    {
        TreeNode<int> *getval = q.front();
        q.pop();

        int child;
        cout<<"Enter the number of child in "<<getval->data<<" : ";
        cin>>child;

        for (int i{0}; i<child; i++)
        {
            int val;
            cout<<"Enter the "<<i<<"th value of node" <<getval->data<<": ";
            cin >>val;

            TreeNode<int> *data = new TreeNode<int> (val);
            getval->children.push_back(data);
            q.push(data);
        }
    }
    return rootNode;
}
TreeNode<int> *Insertdata()
{
    int data, child;
    cout<<"Enter Data: ";
    cin>>data;

    TreeNode<int>  *root = new TreeNode<int>(data);
    
    cout<<"Enter Number of child of "<<data<<" :";
    cin>>child;

    for (int i{0}; i<child; i++)
    {
        TreeNode<int> *child = Insertdata();
        root->children.push_back(child);
    }

    return root;
}
void printTree(TreeNode<int> *root)
{
    if (root == nullptr)
        return;

    cout<<root->data<<" : ";
    for (int i{0}; i < root->children.size(); i++)
    {
        cout<<root->children[i]->data<<" , ";
    }
    cout<<endl;
    for (int i{0}; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
    return ;
}
int main()
{   /*
    TreeNode<int> *root = new TreeNode<int> (1);
    TreeNode<int> *node1 = new TreeNode<int> (2);
    TreeNode<int> *node2 = new TreeNode<int> (3);
    
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    TreeNode<int> *root = InsertInOrder();    
    printTree(root);
    return 0;
}