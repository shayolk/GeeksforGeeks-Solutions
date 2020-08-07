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

// Method that returns the bottom view.
void dfs(Node* root, map<int,pair<int,int>>& m, int dist, int height) {
    if(!root) return;
    if(!m.count(dist)) m[dist]={root->data,height};
    else if(height>m[dist].second) m[dist]={root->data,height};
    dfs(root->left,m,dist-1,height+1);
    dfs(root->right,m,dist+1,height+1);
}

vector <int> bottomView(Node *root) {
    // map<int,pair<int,int>> m;
    // dfs(root,m,0,1);
    map<int,int> m;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()) {
        pair<Node*,int> p=q.front();
        q.pop();
        if(!p.first) continue;
        m[p.second]=p.first->data;
        q.push({p.first->left,p.second-1});
        q.push({p.first->right,p.second+1});
    }
    vector<int> bottom;
    for(auto i:m) {
        bottom.push_back(i.second);
    }
    return bottom;
}
