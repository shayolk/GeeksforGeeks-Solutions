/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes

void connect(Node *root) {
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node* t=q.front();
        q.pop();
        if(!t) continue;
        while(t) {
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            t->nextRight=q.front();
            t=q.front();
            q.pop();
        }
        q.push(NULL);
    }
}
