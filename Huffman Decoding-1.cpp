/*Complete the function below 
Which contains 2 arguments 
1) root of the tree formed while encoding
2) Encoded String*/
string decode_file(struct MinHeapNode* root, string s) {
    if(s.empty()) return "";
    string dec;
    MinHeapNode* t=root;
    for(int i=0; i<(int)s.size(); ++i) {
        if(s[i]=='0') {
            if(!t->left) {
                dec+=t->data;
                t=root;
                --i;
                continue;
            }
            t=t->left;
        }
        else {
            if(!t->right) {
                dec+=t->data;
                t=root;
                --i;
                continue;
            }
            t=t->right;
        }
    }
    dec+=t->data;
    return dec;
}
