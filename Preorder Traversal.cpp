/* A binary tree node has data, pointer to left child
   and a pointer to right child  

/*
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

void trav(Node* root, vector<int>& ret) {
    if(!root) return;
    ret.push_back(root->data);
    trav(root->left,ret);
    trav(root->right,ret);
}

vector<int> preorder(Node* root) {
    vector<int> ret;
    trav(root,ret);
    return ret;
}
