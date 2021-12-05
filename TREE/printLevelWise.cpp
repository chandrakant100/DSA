#include <iostream>
#include <vector>
#include <queue>
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
void printLevelWise(TreeNode<int>* root) {
    // Write your code here
	queue<TreeNode<int> *> q;
    q.push(root);
        
    while(!q.empty())
    {
        TreeNode<int> *val = q.front();
        q.pop();
    	int size = val->children.size(); 
        cout<<val->data<<":";
        for (int i{0}; i < size; i++)
        {
            cout<<val->children[i]->data;
            
            if (i != size-1)
                cout<<",";
            
            q.push(val->children[i]);
        }
        cout<<endl;
    }
}
int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}