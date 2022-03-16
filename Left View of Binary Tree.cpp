/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    map<int,int> view;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            pair<Node*, int> p=q.front();
            q.pop();
            if(!p.first) continue;
            if(!view.count(p.second)) view[p.second]=p.first->data;
            q.push({p.first->left, p.second+1});
            q.push({p.first->right, p.second+1});
        }
        vector<int> ans;
        for(auto v: view) {
            ans.push_back(v.second);
        }
        return ans;
}
