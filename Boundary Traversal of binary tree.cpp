/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    vector<int> ans;
    
    void left(Node* root) {
        if(!root || (!root->left && !root->right)) return;
        ans.push_back(root->data);
        if(root->left) left(root->left);
        else left(root->right);
    }
    
    void leaf(Node* root) {
        if(!root) return;
        leaf(root->left);
        if(!root->left && !root->right) ans.push_back(root->data);
        leaf(root->right);
    }
    
    void right(Node* root) {
        if(!root || (!root->left && !root->right)) return;
        if(root->right) right(root->right);
        else right(root->left);
        ans.push_back(root->data);
    }
    
public:
    vector <int> boundary(Node *root)
    {
        if(!root) return ans;
        ans.push_back(root->data);
        if(root->left) left(root->left);
        if(root->left || root->right) leaf(root);
        if(root->right) right(root->right);
        return ans;
    }
};
