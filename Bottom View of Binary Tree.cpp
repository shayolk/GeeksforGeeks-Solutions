/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int,int> level;
        queue<pair<Node*,int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            pair<Node*,int> p = q.front();
            q.pop();
            level[p.second] = p.first->data;
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
