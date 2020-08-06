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

void dfs(Node* root, int level, vector<bool>& vis) {
    if(root==NULL) return;
    if(!vis[level]) {
        printf("%d ", root->data);
        vis[level]=true;
    }
    dfs(root->left,level+1,vis);
    dfs(root->right,level+1,vis);
}

void leftView(Node *root) {
    vector<bool> vis(105, false);
    dfs(root,1,vis);
}
