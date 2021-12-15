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
pair<int,bool> isBalancedhelper(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        pair<int,bool> p;
        p.first = 0;
        p.second = true;
        
        return p;
    }
    pair<int,bool> lans = isBalancedhelper(root->left);
    pair<int,bool> rans = isBalancedhelper(root->right);
    
    int height1 = lans.first;
    int height2 = rans.first;
    
    bool isbalanced1 = lans.second;
    bool isbalanced2 = rans.second;
    
    pair<int,bool> finalpair;
    
    if ( (abs(height1 - height2) <= 1) && (isbalanced1 && isbalanced2))
    {
        finalpair.first = max(height1,height2) + 1;
        finalpair.second = true;
    }
    else
    {
        finalpair.first = max(height1,height2) + 1;
        finalpair.second = false;
    }
    
    return finalpair;
}
bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
	if (root == nullptr)
        return true;
    
    pair<int,bool> checkPair = isBalancedhelper(root);
    
    return checkPair.second;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");
}