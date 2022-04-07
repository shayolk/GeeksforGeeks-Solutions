/* Structure for tree and linked list

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

// This function should return head to the DLL
class Solution
{
    pair<Node*,Node*> build(Node* root) {
        if(!root) return {NULL, NULL};
        pair<Node*,Node*> l=build(root->left), r=build(root->right);
        root->left=l.second;
        if(l.second) l.second->right=root;
        root->right=r.first;
        if(r.first) r.first->left=root;
        Node* left=l.first?l.first:root;
        Node* right=r.second?r.second:root;
        return {left, right};
    }
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        return build(root).first;
    }
};
