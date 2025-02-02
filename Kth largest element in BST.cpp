/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
    void find(Node* root, int& k, int& ans) {
        if(!root || ans != -1) {
            return;
        }
        find(root->right, k, ans);
        --k;
        if(k == 0) {
            ans = root->data;
            return;
        }
        find(root->left, k, ans);
    }

  public:
    int kthLargest(Node *root, int k) {
        int ans = -1;
        find(root, k, ans);
        return ans;
    }
};
