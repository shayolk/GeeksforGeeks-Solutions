// User Fuction template for C++

class Solution {
    const int INF=1e9+5;
    map<Node*, int> mt, mo;
    
    int findOne(Node* root) {
        if(!root) return -INF;
        if(mo.count(root)) return mo[root];
        return mo[root]=max({
           root->data,
           root->data+findOne(root->left),
           root->data+findOne(root->right)
        });
    }
    
  public:
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        if(!root) return -INF;
        if(mt.count(root)) return mt[root];
        return mt[root]=max({
            root->data+max(0, findOne(root->left))+max(0, findOne(root->right)),
            findMaxSum(root->left),
            findMaxSum(root->right)
        });
    }
};
