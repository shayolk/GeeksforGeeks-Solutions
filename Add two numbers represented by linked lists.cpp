/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

Node* reverse(Node* head) {
    if(!head || !head->next) return head;
    Node* tail=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return tail;
}

int size(Node* head) {
    if(!head) return 0;
    return 1+size(head->next);
}

struct Node* addTwoLists(struct Node* first, struct Node* second) {
    if(!first) return second;
    if(!second) return first;
    first=reverse(first);
    second=reverse(second);
    if(size(second)>size(first)) swap(first, second);
    int carry=0, x;
    Node *head=NULL, *t;
    while(first && second) {
        x=first->data+second->data+carry;
        carry=x/10;
        if(!head) {
            head=new Node(x%10);
            t=head;
        }
        else {
            t->next=new Node(x%10);
            t=t->next;
        }
        first=first->next;
        second=second->next;
    }
    while(first) {
        x=first->data+carry;
        carry=x/10;
        t->next=new Node(x%10);
        t=t->next;
        first=first->next;
    }
    if(carry) t->next=new Node(carry);
    head=reverse(head);
    return head;
}
