/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

// Should reverse list and return new head.

Node* tail;

void reverse(Node* t) {
    if(!t->next) {
        tail=t;
        return;
    }
    reverse(t->next);
    t->next->next=t;
    t->next=NULL;
}

struct Node* reverseList(struct Node *head) {
    if(!head) return head;
    reverse(head);
    return tail;
    // Node *prev=NULL, *curr=head, *next;
    // while(curr) {
    //     next=curr->next;
    //     curr->next=prev;
    //     prev=curr;
    //     curr=next;
    // }
    // return prev;
}
