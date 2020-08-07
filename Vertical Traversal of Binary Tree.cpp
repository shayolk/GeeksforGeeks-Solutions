/* A binary tree node has data, pointer to left child
   and a pointer to right child 
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

// root: root node of the tree
void dfs(Node* root, int dist, int depth, map<int,set<pair<int,int>>>& m) {
    if(!root) return;
    m[dist].insert({depth,root->data});
    dfs(root->left,dist-1,depth+1,m);
    dfs(root->right,dist+1,depth+1,m);
}

vector<int> verticalOrder(Node *root) {
    // map<int,set<pair<int,int>>> m;
    // dfs(root,0,1,m);
    // vector<int> ret;
    // for(auto i:m) {
    //     for(auto j:i.second) {
    //         ret.push_back(j.second);
    //     }
    // }
    map<int,vector<int>> m;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()) {
        pair<Node*,int> p=q.front();
        q.pop();
        if(!p.first) continue;
        m[p.second].push_back(p.first->data);
        q.push({p.first->left,p.second-1});
        q.push({p.first->right,p.second+1});
    }
    vector<int> ret;
    for(auto i:m) {
        for(auto j:i.second) {
            ret.push_back(j);
        }
    }
    return ret;
}
