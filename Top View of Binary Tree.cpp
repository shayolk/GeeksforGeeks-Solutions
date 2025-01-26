/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        map<int,int> level;
        queue<pair<Node*,int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            pair<Node*,int> p = q.front();
            q.pop();
            if(!level.count(p.second)) {
                level[p.second] = p.first->data;
            }
            if(p.first->left) q.push({p.first->left, p.second - 1});
            if(p.first->right) q.push({p.first->right, p.second + 1});
        }
        vector<int> view;
        for(auto l: level) {
            view.push_back(l.second);
        }
        return view;
    }
};
