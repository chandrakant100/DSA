#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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
pair<Node<int> *,Node<int> *> helper(BinaryTreeNode<int>* root)
{
    if (root == nullptr)
    {
        pair<Node<int> *,Node<int> *> pair;
        pair.first = nullptr;
        pair.second = nullptr;
        return pair;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        Node<int> *newnode = new Node<int> (root->data);
        pair<Node<int> *,Node<int> *> pair;
        pair.first = newnode;
        pair.second = newnode;
        
        return pair;
    }
    
    pair<Node<int> *,Node<int> *> pair1 = helper(root->left);
    pair<Node<int> *,Node<int> *> pair2 = helper(root->right);
    
    Node<int> *newnode = new Node<int>(root->data);
    pair<Node<int> *,Node<int> *> finalpair;
    
    if (pair1.first == nullptr && pair1.second == nullptr)
    {
        finalpair.first = newnode;
        newnode->next = pair2.first;
        if (pair2.first != nullptr)
            finalpair.second = pair2.first;
        else
            finalpair.second = newnode;
        
        return finalpair;
    }
    finalpair.first = pair1.first;
    pair1.second->next = newnode;
    newnode->next = pair2.first;
    
    if (pair2.second == nullptr)
        finalpair.second = newnode;
    else
    	finalpair.second = pair2.second;
    
    return finalpair;
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    if (root == nullptr)
        return nullptr;
    pair<Node<int> *,Node<int> *> finalpair = helper(root);
    
    return finalpair.first;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}