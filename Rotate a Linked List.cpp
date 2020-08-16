/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function should rotate list counter-clockwise
// by k and return new head (if changed)

Node* rotate(Node* head, int k) {
    Node* t=head;
    for(int cnt=1; cnt<k && t; ++cnt, t=t->next);
    if(!t || !t->next) return head;
    Node *s, *ret=t->next;
    for(s=t->next; s->next; s=s->next);
    s->next=head;
    t->next=NULL;
    return ret;
}
