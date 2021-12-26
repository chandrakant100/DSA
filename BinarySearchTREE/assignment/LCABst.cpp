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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
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
int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
    if (root == nullptr)
        return -1;
    if (root->data == val1)
        return root->data;
    if (root->data == val2)
        return root->data;
    
    int lval{-1},rval{-1};
    
    if (val1 < root->data)
        lval = getLCA(root->left,val1,val2);
    else
        rval = getLCA(root->right,val1,val2);
    
    if (val2 < root->data)
        lval = getLCA(root->left,val1,val2);
    else
        rval = getLCA(root->right,val1,val2);
    
    if (lval == -1 && rval == -1)
        return -1;
    else if (lval != -1 && rval == -1)
        return lval;
    else if (lval == -1 && rval != -1)
        return rval;

	return root->data;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}