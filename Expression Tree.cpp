/*The structure of node is as follows
struct node{
    string data;
    node *left;
    node *right;
};
*/

/*You are required to complete below method */
int evalTree(node* root) {
    if(!root) return 0;
    string s=root->data;
    if(s=="+") return evalTree(root->left)+evalTree(root->right);
    if(s=="-") return evalTree(root->left)-evalTree(root->right);
    if(s=="*") return evalTree(root->left)*evalTree(root->right);
    if(s=="/") return evalTree(root->left)/evalTree(root->right);
    return stoi(s);
}
