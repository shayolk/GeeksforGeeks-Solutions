/* Structure for tree and linked list

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

// This function should return head to the DLL
Node *head,*r;

void in(Node* t) {
    if(!t) return;
    in(t->left);
    Node* temp=new Node;
    temp->data=t->data;
    temp->left=r;
    temp->right=NULL;
    if(r) r->right=temp;
    r=temp;
    if(!head) head=r;
    in(t->right);
}

Node* bToDLL(Node* root) {
    head=r=NULL;
    in(root);
    return head;
}
