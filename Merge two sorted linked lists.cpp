/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node* sortedMerge(Node* head_A, Node* head_B) {
    if(!head_A) return head_B;
    if(!head_B) return head_A;
    Node* ret;
    if(head_A->data < head_B->data) {
        ret=head_A;
        ret->next=sortedMerge(head_A->next, head_B);
    }
    else {
        ret=head_B;
        ret->next=sortedMerge(head_A, head_B->next);
    }
    return ret;
}
