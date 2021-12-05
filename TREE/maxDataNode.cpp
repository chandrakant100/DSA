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
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
   	queue<TreeNode<int> *> q;
    q.push(root);
    
    TreeNode<int> *max{root};
    
    while(!q.empty())
    {
        TreeNode<int> *val = q.front();
        q.pop();
    	int size = val->children.size(); 
        
        for (int i{0}; i < size; i++)
        {
            if (max->data < val->children[i]->data)
                max = val->children[i];
            
            q.push(val->children[i]);
        }
    }
    return max;
}
int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxDataNode(root);

    if (root != NULL) {
        cout << ans->data;
    }
}