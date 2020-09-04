/*Complete the function below
Node is as follows:
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

// Return the root of the modified tree after removing all the half nodes.
Node *RemoveHalfNodes(Node *root) {
    if(!root) return NULL;
    if(!root->left && !root->right) return root;
    if(!root->left) return RemoveHalfNodes(root->right);
    if(!root->right) return RemoveHalfNodes(root->left);
    root->left=RemoveHalfNodes(root->left);
    root->right=RemoveHalfNodes(root->right);
    return root;
}
