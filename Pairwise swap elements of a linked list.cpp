/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/

Node* pairWiseSwap(struct Node* head) {
    if(!head || !head->next) return head;
    Node* temp=head->next->next, *t=head->next;
    head->next->next=head;
    head->next=pairWiseSwap(temp);
    return t;
}
