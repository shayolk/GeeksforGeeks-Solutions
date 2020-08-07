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

void printSpiral(Node *root) {
    stack<Node*> lr,rl;
    rl.push(root);
    while(!lr.empty() || !rl.empty()) {
        while(!rl.empty()) {
            Node* t=rl.top();
            rl.pop();
            if(!t) continue;
            printf("%d ", t->data);
            lr.push(t->right);
            lr.push(t->left);
        }
        while(!lr.empty()) {
            Node* t=lr.top();
            lr.pop();
            if(!t) continue;
            printf("%d ", t->data);
            rl.push(t->left);
            rl.push(t->right);
        }
    }
}
