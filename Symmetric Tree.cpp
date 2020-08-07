/*
Structure of the node of the tree is as
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

// return true/false denoting whether the tree is Symmetric or not
bool check(Node* l, Node* r) {
    if(!l && !r) return true;
    if(!l || !r) return false;
    if(l->data != r->data) return false;
    return check(l->left,r->right) && check(l->right,r->left);
}

bool isSymmetric(struct Node* root) {
    return check(root,root);
}
