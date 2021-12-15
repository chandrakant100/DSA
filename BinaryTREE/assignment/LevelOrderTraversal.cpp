#include <iostream>
#include <queue>
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
void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
    if (root == nullptr)
        return;
    
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(nullptr);
    
    while(!q.empty())
    {
        BinaryTreeNode<int> *Nodeval = q.front();
        
        if (Nodeval == nullptr)
        {
            q.pop();
            
            if (q.empty() == true)
                break;
            
            cout<<endl;
            q.push(nullptr);
            continue;
        }
        
        if (Nodeval->left != nullptr)
            q.push(Nodeval->left);
        
        if (Nodeval->right != nullptr)
            q.push(Nodeval->right);
        
        cout<<Nodeval->data<<" ";
        q.pop();
    }
    
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}