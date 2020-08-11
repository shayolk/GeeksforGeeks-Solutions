/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/* Computes the diameter of binary tree with given root.  */

int find(Node* root, int& ans) {
    if(!root) return 0;
    int l=find(root->left,ans), r=find(root->right,ans);
    ans=max(ans, 1+l+r);
    return 1+max(l,r);
}

int diameter(Node* root) {
    int ans=0;
    find(root,ans);
    return ans;
}

// int dist(Node* root) {
//     if(!root) return 0;
//     return 1+max(dist(root->left), dist(root->right));
// }

// int diameter(Node* root) {
//     if(!root) return 0;
//     return max({1+dist(root->left)+dist(root->right), diameter(root->left), diameter(root->right)});
// }
