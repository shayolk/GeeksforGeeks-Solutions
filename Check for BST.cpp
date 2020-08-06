/* A binary tree node has data, pointer to left child
   and a pointer to right child  
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

// return true if the given tree is a BST, else return false
bool bst(Node* root, int mn, int mx) {
    if(!root) return true;
    if(root->data <= mn || root->data >= mx) return false;
    return bst(root->left,mn,root->data) && bst(root->right,root->data,mx);
}

bool isBST(Node* root) {
    return bst(root,-2e9,2e9);
}
