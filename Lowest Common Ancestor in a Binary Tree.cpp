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


class Solution
{
    vector<int> depth;
    vector<Node*> node;
    map<Node*, int> last;
    int tot=0, a, b;
    Node *p=NULL, *q=NULL;
    
    void dfs(Node* root, int height) {
        if(!root) {
            return;
        }
        if(root->data==a) {
            p=root;
        }
        if(root->data==b) {
            q=root;
        }
        
        node.push_back(root);
        depth.push_back(height);
        last[root]=tot++;
        
        dfs(root->left, height+1);
        
        node.push_back(root);
        depth.push_back(height);
        last[root]=tot++;
        
        dfs(root->right, height+1);
        
        node.push_back(root);
        depth.push_back(height);
        last[root]=tot++;
    }
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root, int n1, int n2 )
    {
        a=n1;
        b=n2;
        dfs(root, 0);
        if(!root || !p || !q) {
            return NULL;
        }
        // for(int i=0; i<depth.size(); ++i) cout<<node[i]->val<<" "<<depth[i]<<"\n";
        int lastp=last[p], lastq=last[q];
        int st=min(lastp, lastq), ed=max(lastp, lastq);
        int ind=-1, mn=2e9+5;
        for(int i=st; i<=ed; ++i) {
            if(depth[i]<mn) {
                mn=depth[i];
                ind=i;
            }
        }
        return node[ind];
    }
};
