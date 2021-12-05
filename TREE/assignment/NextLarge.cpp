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
TreeNode<int>* getNextLargerElement(TreeNode<int>* root,TreeNode<int>* val, int x, int max, int diff)
{
    if(root->data > x)
    {
        int temp = root->data - x;
        if (diff > temp)
        {
            max = root->data;
            diff = temp;
    		val = root;  	
        }
    }
    
    for (int i{0}; i<root->children.size(); i++)
    {
        val = getNextLargerElement(root->children[i],val,x,max,diff);
    }
    
    return val;
}
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
    if (root == nullptr)
        return nullptr;
    
    return getNextLargerElement(root,nullptr,x,0,10);
}
int main() {
    TreeNode<int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
}