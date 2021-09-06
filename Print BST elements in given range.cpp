/* The structure of a BST Node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// returns an array of node values in the BST (rooted at 'root')
// that lie in the given range [low, high]

//User function template for C++

class Solution {
  public:
    vector<int> printNearNodes(Node *root, int low, int high) {
        if(!root) return {};
        if(root->data<low) return printNearNodes(root->right, low, high);
        if(root->data>high) return printNearNodes(root->left, low, high);
        vector<int> left=printNearNodes(root->left, low, high);
        left.push_back(root->data);
        vector<int> right=printNearNodes(root->right, low, high);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};
