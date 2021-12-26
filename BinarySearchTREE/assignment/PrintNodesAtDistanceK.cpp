#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void printdistanceHelper(BinaryTreeNode<int> *root,int k)
{
    if (root == nullptr || k < 0) return;
    
    if (k == 0)
    {
        cout<<root->data<<endl;
        return;
    }
    printdistanceHelper(root->left,k-1);
    printdistanceHelper(root->right,k-1);
}
int NodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    if (root == nullptr) return -1;
    
    if (root->data == node)
    {
        printdistanceHelper(root,k);
        return 0;
    }
    
    int dl = NodesAtDistanceK(root->left,node,k);
    
    if (dl != -1)
    {
        if (dl+1 == k)
            cout<<root->data<<endl;
        else
    		printdistanceHelper(root->right,k-dl-2);
        
        return dl+1;
    }
    
    int dr = NodesAtDistanceK(root->right,node,k);
    
    if (dr != -1)
    {
        if (dr+1 == k)
            cout<<root->data<<endl;
        else
    		printdistanceHelper(root->left,k-dr-2);
        
        return dr+1;
    }
    
    return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    int x = NodesAtDistanceK(root,node,k);
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}