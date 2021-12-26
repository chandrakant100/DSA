#include "BinaryTreeNode.h"
#include <queue>
using namespace std;
class BST
{
    private:
    BinaryTreeNode<int> *root;
    
    public:
     BST(){root = nullptr;}
     ~BST(){delete root;}
    
    private:
    bool hasDataHelper(int data,BinaryTreeNode<int> * root)
    {
        if (root == nullptr)
            return false;
        if (root->data == data)
            return false;
        if (data < root->data)
            return hasDataHelper(data,root->left);
        
        return hasDataHelper(data,root->right);
    }
    BinaryTreeNode<int>* insertDataHelper(BinaryTreeNode<int> *root,int data)
    {
        if (root == nullptr)
        {
            BinaryTreeNode<int> *val = new BinaryTreeNode<int> (data);
            return val;
        }

        if (data < root->data)
        {
            root->left = insertDataHelper(root->left,data);
        }
        else
        {
            root->right = insertDataHelper(root->right,data);
        }

        return root;
    }
    BinaryTreeNode<int>* deleteHelper(BinaryTreeNode<int> *root,int data)
    {

        if (root == nullptr)
        {
            return nullptr;
        }

        if (data < root->data)
        {
            root->left = deleteHelper(root->left,data);
            return root;
        }
        else if(data > root->data)
        {
            root->right = deleteHelper(root->right,data);
            return root;
        }
        else
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            else if(root->left == nullptr)
            {
                BinaryTreeNode<int> *temp = root->right;
                root->right = nullptr;
                delete root;
                return temp;
            }
            else if(root->right == nullptr)
            {
                BinaryTreeNode<int> *temp = root->left;
                root->left = nullptr;
                delete root;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minimum = root->right;
                
                while(minimum->left != nullptr)
                    minimum = minimum->left;
                
                int rightmin = minimum->data;
                root->data = rightmin;
                root->right = deleteHelper(root->right,rightmin);
                return root;
            }
        }
    }
    void printTree(BinaryTreeNode<int> *root)
    {
        if (root == nullptr)
            return;
        
        cout<<root->data<<":";
        if (root->left != nullptr)
        {
            cout<<"L"<<root->left->data;
        }
        if (root->right != nullptr)
        {
            cout<<"R"<<root->right->data;
        }
        cout<<endl;
        printTree(root->left);
        printTree(root->right);
    }
    public:
        bool search(int data)
        {
            return hasDataHelper(data,root);
        }
        void insert(int data)
        {
            this->root = insertDataHelper(root,data);
        } 
        void remove(int data)
        {
            this->root = deleteHelper(root,data);
        }
        void print()
        {
            printTree(root);
        }
};