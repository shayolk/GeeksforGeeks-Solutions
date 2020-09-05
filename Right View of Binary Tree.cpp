/* A binary tree node has data, pointer to left child
   and a pointer to right child 
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

// Should print right view of tree
void print(Node* root, int dep, map<int,bool>& m) {
    if(!root) return;
    if(!m[dep]) {
        printf("%d ", root->data);
        m[dep]=true;
    }
    print(root->right,dep+1,m);
    print(root->left,dep+1,m);
}

void rightView(Node *root) {
    map<int,bool> m;
    print(root,0,m);
}
