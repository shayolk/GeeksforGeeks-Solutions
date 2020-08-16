/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
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

struct node *reverse (struct node *head, int k) {
    if(!head) return NULL;
    int cnt=0;
    node *prev=NULL, *curr=head, *next;
    while(cnt<k && curr) {
        ++cnt;
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head->next=reverse(curr,k);
    return prev;
}
