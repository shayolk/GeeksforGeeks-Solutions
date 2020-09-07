/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// function should print the nodes at k distance from root
void find(Node* root, int dist, int k, vector<int>& ans) {
    if(!root) return;
    if(dist==k) {
        ans.push_back(root->data);
        return;
    }
    find(root->left,dist+1,k,ans);
    find(root->right,dist+1,k,ans);
}

vector<int> Kdistance(struct Node *root, int k) {
    vector<int> ans;
    find(root,0,k,ans);
    return ans;
}
