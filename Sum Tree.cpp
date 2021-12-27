/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    pair<bool,int> sum(Node* root) {
        if(!root) return {true, 0};
        if(!root->left && !root->right) return {true, root->data};
        pair<bool,int> left=sum(root->left), right=sum(root->right);
        return {left.first && right.first && (left.second+right.second==root->data), left.second+right.second+root->data};
    }
    public:
    bool isSumTree(Node* root)
    {
        return sum(root).first;
    }
};
