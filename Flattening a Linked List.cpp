/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node* merge(Node* x, Node* y) {
    if(!x) return y;
    if(!y) return x;
    Node* res;
    if(x->data<y->data) {
        res=x;
        res->bottom=merge(x->bottom, y);
    }
    else {
        res=y;
        res->bottom=merge(x, y->bottom);
    }
    res->next=NULL;
    return res;
}


Node *flatten(Node *root) {
    if(!root) return root;
    return merge(root, flatten(root->next));
}
