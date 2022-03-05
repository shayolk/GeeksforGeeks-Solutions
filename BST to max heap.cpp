//User function Template for C++

class Solution{
    vector<int> nodes;
    int ind;
    
    void traverse(Node* root, bool order) {
        if(!root) return;
        if(order) {
            traverse(root->left, order);
            traverse(root->right, order);
            root->data=nodes[ind++];
        }
        else {
            traverse(root->left, order);
            nodes.push_back(root->data);
            traverse(root->right, order);
        }
    }
    
  public:
    void convertToMaxHeapUtil(Node* root)
    {
        traverse(root, false);
        ind=0;
        traverse(root, true);
    }    
};
