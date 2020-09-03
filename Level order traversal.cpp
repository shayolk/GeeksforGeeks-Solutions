/* A binary tree Node

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

//You are required to complete this method
vector<int> levelOrder(Node* node) {
    vector<int> level;
    queue<Node*> q;
    q.push(node);
    while(!q.empty()) {
        Node* t=q.front();
        q.pop();
        if(!t) continue;
        level.push_back(t->data);
        q.push(t->left);
        q.push(t->right);
    }
    return level;
}
