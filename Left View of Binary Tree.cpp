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

class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> view;
        if(!root) {
            return view;
        }
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            if(!front) {
                if(!q.empty()) {
                    q.push(NULL);
                }
                continue;
            }
            view.push_back(front->data);
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            while(!q.empty() && q.front()) {
                front = q.front();
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
        return view;
    }
};
