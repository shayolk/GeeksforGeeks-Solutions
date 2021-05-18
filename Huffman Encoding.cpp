class Solution
{
    struct node {
        char c;
        int freq;
        node *left, *right;
        node(char c='#', int freq=0, node* left=NULL, node* right=NULL) {
            this->c=c;
            this->freq=freq;
            this->left=left;
            this->right=right;
        }
    };
    
    struct comp {
        bool operator()(node* a, node* b) {
            return a->freq>b->freq;
        }
    };
    
    void traverse(node* root, string s, vector<string>& ans) {
        if(!root) {
            return;
        }
        if(root->c!='#') {
            ans.push_back(s);
            return;
        }
        traverse(root->left, s+'0', ans);
        traverse(root->right, s+'1', ans);
    }
    
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<node*, vector<node*>, comp> p;
		    for(int i=0; i<N; ++i) {
		        p.push(new node(S[i], f[i]));
		    }
		    while(p.size()>1) {
		        node* l=p.top();
		        p.pop();
		        node* r=p.top();
		        p.pop();
		        p.push(new node('#', l->freq+r->freq, l, r));
		    }
		    node* root=p.top();
		    string s;
		    vector<string> ans;
		    traverse(root, s, ans);
		    return ans;
		}
};
