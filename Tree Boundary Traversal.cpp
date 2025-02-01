/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    bool isLeaf(Node *root) {
        return !root->left && !root->right;
    }

    void traverse(Node *root, vector<int>& order) {
        if(!root) {
            return;
        }
        if(isLeaf(root)) {
            order.push_back(root->data);
            return;
        }
        traverse(root->left, order);
        traverse(root->right, order);
    }

  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> order;
        if(root && !isLeaf(root)) {
            order.push_back(root->data);
        }
        Node* tmp = root->left;
        while(tmp && !isLeaf(tmp)) {
            order.push_back(tmp->data);
            if(tmp->left) {
                tmp = tmp->left;
            }
            else {
                tmp = tmp->right;
            }
        }
        traverse(root, order);
        int n = order.size();
        tmp = root->right;
        while(tmp && !isLeaf(tmp)) {
            order.push_back(tmp->data);
            if(tmp->right) {
                tmp = tmp->right;
            }
            else {
                tmp = tmp->left;
            }
        }
        reverse(order.begin() + n, order.end());
        return order;
    }
};
