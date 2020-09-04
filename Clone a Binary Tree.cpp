/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

/* The function should clone the passed tree and return 
   root of the cloned tree */

Node* cloneTree(Node* tree) {
    if(!tree) return tree;
    Node* t=new Node(tree->data);
    t->left=cloneTree(tree->left);
    t->right=cloneTree(tree->right);
    t->random=NULL;
    return t;
}
