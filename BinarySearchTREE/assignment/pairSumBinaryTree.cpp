#include <iostream>
#include <queue>
#include <bits/stdc++.h>
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
void pairsumHelper(BinaryTreeNode<int> *root,vector<int> &vec)
{
    if (root == nullptr)
        return;
    
    vec.push_back(root->data);
    pairsumHelper(root->left,vec);
    pairsumHelper(root->right,vec);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    vector<int> vec;
	pairsumHelper(root,vec);
    
    sort(vec.begin(),vec.end());
    
    int i{0};
    int j = vec.size() - 1;
    
    while (i < j)
    {
        int temp = vec.at(i) + vec.at(j);
        if (temp == sum)
        {
            cout<<vec[i]<<" "<<vec[j]<<endl;
            i++;
            j--;
            continue;
        }
        if (temp > sum)
            j--;
        else
            i++;
    }
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}