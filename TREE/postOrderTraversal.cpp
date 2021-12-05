#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};
TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}
void printPostOrder(TreeNode<int>* root) {
    // Write your code here
    if (root->children.size() == 0)
    {
        cout<<root->data<<" ";
        return;
    }
    
    for (int i{0}; i<root->children.size(); i++)
    {
        printPostOrder(root->children[i]);
    }
    
    cout<<root->data<<" ";
    
    return;
}
void deleteTree(TreeNode<int> *root)
{
    for (int i{0}; i<root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }

    delete root;
}
int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printPostOrder(root);
    
    // one way of deleteing root
    deleteTree(root);

    // effective way of deleteing node
    // we can do it by using ~destructor ()
    delete root;
}