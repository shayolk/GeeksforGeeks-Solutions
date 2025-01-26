/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    vector<vector<int>> paths;

    bool traverse(Node* root, vector<int>& path) {
        if(!root) {
            return true;
        }
        path.push_back(root->data);
        bool left = traverse(root->left, path);
        bool right = traverse(root->right, path);
        if(left && right) {
            paths.push_back(path);
        }
        path.pop_back();
        return false;
    }

  public:
    vector<vector<int>> Paths(Node* root) {
        vector<int> path;
        traverse(root, path);
        return paths;
    }
};
