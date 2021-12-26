#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

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

BinaryTreeNode<int> *takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}
void inputInVector(BinaryTreeNode<int> *root,vector<int> &vec)
{
    if (root == nullptr)
        return;
    vec.push_back(root->data);
    inputInVector(root->left,vec);
    inputInVector(root->right,vec);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    if (root == nullptr)
        return;
    
    vector<int> vec;
    inputInVector(root,vec);
	
    sort(vec.begin(),vec.end());
    
    int i{0},j{vec.size()-1};
    
    while(i<j)
    {
        int temp = vec[i] + vec[j];
        if (temp == s)
        {
            cout<<vec[i]<<" "<<vec[j]<<endl;
            i++;
            j--;
            continue;
        }
        if (temp < s)
            i++;
        else
            j--;
    }
}
int main() {
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}