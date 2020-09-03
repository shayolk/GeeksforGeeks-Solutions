/* The structure of a BST Node is as follows:

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

// returns an array of node values in the BST (rooted at 'root')
// that lie in the given range [low, high]

void find(Node* root, int lo, int hi, vector<int>& ret) {
    if(!root) return;
    if(root->data>hi) {
        find(root->left,lo,hi,ret);
        return;
    }
    if(root->data<lo) {
        find(root->right,lo,hi,ret);
        return;
    }
    find(root->left,lo,hi,ret);
    ret.push_back(root->data);
    find(root->right,lo,hi,ret);
}

vector<int> printNearNodes(Node *root, int low, int high) {
    vector<int> ret;
    find(root,low,high,ret);
    return ret;
}
