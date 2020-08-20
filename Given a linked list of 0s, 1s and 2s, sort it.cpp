/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node* segregate(Node *head) {
    Node *zero=NULL, *one=NULL, *two=NULL;
    Node *h0=NULL, *h1=NULL, *h2=NULL;
    while(head) {
        if(head->data==0) {
            if(!zero) {
                zero=head;
                h0=zero;
            }
            else {
                zero->next=head;
                zero=head;
            }
        }
        else if(head->data==1) {
            if(!one) {
                one=head;
                h1=one;
            }
            else {
                one->next=head;
                one=head;
            }
        }
        else {
            if(!two) {
                two=head;
                h2=two;
            }
            else {
                two->next=head;
                two=head;
            }
        }
        head=head->next;
    }
    if(zero) zero->next=NULL;
    if(one) one->next=NULL;
    if(two) two->next=NULL;
    if(!h0) {
        if(!h1) return h2;
        one->next=h2;
        return h1;
    }
    if(!h1) {
        zero->next=h2;
        return h0;
    }
    zero->next=h1;
    one->next=h2;
    return h0;
}
