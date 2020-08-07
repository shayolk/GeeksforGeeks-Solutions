/*The structure of a BST Node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Returns the LCA of the nodes with values n1 and n2
// in the BST rooted at 'root' 
Node* dfs(Node* root, int n1, int n2) {
    if(!root || (n1<=root->data && root->data<=n2)) return root;
    if(root->data>n2) return dfs(root->left,n1,n2);
    return dfs(root->right,n1,n2);
}

Node* LCA(Node *root, int n1, int n2) {
    return dfs(root,min(n1,n2),max(n1,n2));
}
