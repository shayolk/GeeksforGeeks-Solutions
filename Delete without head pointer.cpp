/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/

// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node) {
    Node* t=node;
    while(t && t->next && t->next->next) {
        t->data=t->next->data;
        t=t->next;
    }
    t->data=t->next->data;
    t->next=NULL;
    // if(head && head==node) head=head->next;
    // Node* t=head;
    // while(t && t->next) {
    //     if(t->next==node) {
    //         t->next=t->next->next;
    //         return;
    //     }
    //     t=t->next;
    // }
}
