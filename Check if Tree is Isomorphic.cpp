/*Complete the function below
Node is as follows:
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

class Solution{
    string convert(Node* root) {
        if(!root) {
            return "";
        }
        string a[2]={convert(root->left), convert(root->right)};
        sort(a, a+2);
        return "("+a[0]+to_string(root->data)+a[1]+")";
    }
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1, Node *root2)
    {
        return convert(root1)==convert(root2);
    }
};
