/*
// structure of the node is as follows

struct node
{
	int data;
	struct node* next;
	
	node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    set<int> s;
    while(head1) {
        s.insert(head1->data);
        head1=head1->next;
    }
    while(head2) {
        s.insert(head2->data);
        head2=head2->next;
    }
    Node *head=NULL, *t;
    for(int i: s) {
        if(!head) {
            head=new Node(i);
            t=head;
        }
        else {
            t->next=new Node(i);
            t=t->next;
        }
    }
    return head;
}
