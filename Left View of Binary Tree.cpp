/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.
void visit(Node* root, int depth, map<int,bool>& done, vector<int>& ans) {
    if(!root) return;
    if(!done.count(depth)) {
        done[depth]=true;
        ans.push_back(root->data);
    }
    visit(root->left, depth+1, done, ans);
    visit(root->right, depth+1, done, ans);
    
}

vector<int> leftView(Node *root)
{
    map<int,bool> done;
    vector<int> ans;
    visit(root, 0, done, ans);
    return ans;
}
