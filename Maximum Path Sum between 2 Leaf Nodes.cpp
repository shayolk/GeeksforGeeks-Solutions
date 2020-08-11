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

int find(Node* root, int& ans) {
    if(!root) return (int)(-2e9);
    if(!root->left && !root->right) return root->data;
    int l=find(root->left, ans), r=find(root->right, ans);
    if(root->left && root->right) ans=max(ans, root->data+l+r);
    return root->data+max(l,r);
}

int maxPathSum(Node* root) {
    int ans=-2e9;
    find(root,ans);
    return ans;
}

// int dist(Node* root) {
//     if(!root) return (int)(-2e9);
//     if(!root->left && !root->right) return root->data;
//     if(!root->left) return root->data+dist(root->right);
//     if(!root->right) return root->data+dist(root->left);
//     return root->data+max(dist(root->left), dist(root->right));
// }

// int maxPathSum(Node* root) {
//     if(!root) return 0;
//     if(!root->left && !root->right) return (int)(-2e9);
//     if(!root->left) return maxPathSum(root->right);
//     if(!root->right) return maxPathSum(root->left);
//     return max({root->data+dist(root->left)+dist(root->right), 
//                 maxPathSum(root->left), 
//                 maxPathSum(root->right)});
// }
