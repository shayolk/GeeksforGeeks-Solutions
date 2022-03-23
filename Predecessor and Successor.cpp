/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(!root) return;
    if(root->key<key) {
        pre=root;
        findPreSuc(root->right, pre, suc, key);
    }
    else if(root->key>key) {
        suc=root;
        findPreSuc(root->left, pre, suc, key);
    }
    else {
        findPreSuc(root->left, pre, suc, key);
        findPreSuc(root->right, pre, suc, key);
    }
}
