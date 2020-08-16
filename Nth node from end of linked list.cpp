/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/

// int count(Node* head) {
//     if(!head) return 0;
//     return 1+count(head->next);
// }

int getNthFromLast(Node *head, int n) {
    Node *slow=head, *fast=head;
    for(int i=0; i<n; ++i) {
        if(!fast) return -1;
        fast=fast->next;
    }
    while(fast) {
        slow=slow->next;
        fast=fast->next;
    }
    return slow->data;
    // int cnt=count(head);
    // if(n>cnt) return -1;
    // cnt-=n;
    // Node* t=head;
    // while(cnt--) t=t->next;
    // return t->data;
}
