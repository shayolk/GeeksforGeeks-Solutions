/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed

Node* build(int& i, int n, int pre[], char preLN[]) {
    if(i==n) {
        return NULL;
    }
    Node* t=new Node(pre[i]);
    if(preLN[i]!='L') {
        t->left=build(++i, n, pre, preLN);
        t->right=build(++i, n, pre, preLN);
    }
    return t;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    int i=0;
    return build(i, n, pre, preLN);
}
