
/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    if(!head) {
        return head;
    }
    if(x==1) {
        Node* t=head->next;
        free(head);
        return t;
    }
    head->next=deleteNode(head->next, x-1);
    return head;
}
