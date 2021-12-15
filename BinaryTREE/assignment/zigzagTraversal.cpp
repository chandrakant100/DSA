#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void zigZagOrder(BinaryTreeNode<int> *root) {
    
   stack<BinaryTreeNode<int>*> s1;  
   stack<BinaryTreeNode<int>*> s2;
    
    int CLR=1,NLC=0;
    bool flag=true;
    
    s1.push(root);
    
    while(!s1.empty() || !s2.empty() )
    {    
        if(flag)
        {
             BinaryTreeNode<int> * T = s1.top();
             s1.pop();
            
             cout<<T->data<<" ";
            
             if(T->left!=NULL)
              {
                s2.push(T->left);
                NLC++;
              }
            
              if(T->right!=NULL)
              {
                s2.push(T->right);
                NLC++;
              }
            
              CLR--;
              if(CLR==0)
               {
                cout<<endl;
                CLR=NLC;
                NLC=0;
                flag=false;
                }
            }
        
      else
      {
          BinaryTreeNode<int> * T = s2.top();
             s2.pop();
            
             cout<<T->data<<" ";
            
             if(T->right)
              {
                s1.push(T->right);
                NLC++;
              }
            
              if(T->left)
              {
                s1.push(T->left);
                NLC++;
              }
            
              CLR--;
              if(CLR==0)
               {
                cout<<endl;
                CLR=NLC;
                NLC=0;
                flag=true;
                }   
      }
        
    }
    
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}