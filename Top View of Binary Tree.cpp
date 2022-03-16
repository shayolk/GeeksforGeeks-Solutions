/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int,int> view;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            pair<Node*, int> p=q.front();
            q.pop();
            if(!p.first) continue;
            if(!view.count(p.second)) view[p.second]=p.first->data;
            q.push({p.first->left, p.second-1});
            q.push({p.first->right, p.second+1});
        }
        vector<int> ans;
        for(auto v: view) {
            ans.push_back(v.second);
        }
        return ans;
    }

};
