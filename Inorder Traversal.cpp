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
}; */


// Return a vector containing the inorder traversal of the tree
void trav(Node* root, vector<int>& ret) {
    if(!root) return;
    trav(root->left,ret);
    ret.push_back(root->data);
    trav(root->right,ret);
}

vector<int> inOrder(Node* root) {
    vector<int> ret;
    trav(root,ret);
    return ret;
}
