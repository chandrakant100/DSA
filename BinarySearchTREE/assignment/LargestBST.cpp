#include <iostream>
#include <queue>
#include <limits.h>
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
class BSTCheck
{
    public:
    int size;
    int min;
    int max;
    bool isBst;
    int maxHeightBst;
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
BSTCheck largestBSTSubtreeHelper(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
        return {0,INT_MAX,INT_MIN,true,0};
    
    if (root->left == nullptr && root->right == nullptr)
        return {1,root->data,root->data,true,1};
    
    BSTCheck lobj = largestBSTSubtreeHelper(root->left);
    BSTCheck robj = largestBSTSubtreeHelper(root->right);
    
    BSTCheck finalobj;
    
    finalobj.size = 1 + max(lobj.size,robj.size);
    
    if ((lobj.isBst && robj.isBst) && (lobj.max < root->data && robj.min > root->data))
    {
        finalobj.isBst = true;
        
        finalobj.min = min(lobj.min,min(robj.min,root->data));
        finalobj.max = max(lobj.max,max(robj.max,root->data));
        
        finalobj.maxHeightBst = finalobj.size;
        
        return finalobj;
    }
    
    finalobj.isBst = false;
    finalobj.maxHeightBst = max(lobj.maxHeightBst,robj.maxHeightBst);
       
    return finalobj;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    
    BSTCheck obj = largestBSTSubtreeHelper(root);
    
    return obj.maxHeightBst;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}