/* A binary tree node structure

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

// This function should return tree if passed  tree 
// is balanced, else false. 

int bal(Node* root, bool& flag) {
    if(!root) return 0;
    int l=bal(root->left,flag), r=bal(root->right,flag);
    flag&=abs(l-r)<=1;
    return 1+max(l,r);
}

bool isBalanced(Node *root) {
    bool flag=true;
    bal(root,flag);
    return flag;
}
