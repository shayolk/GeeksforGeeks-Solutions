/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head) {
    if(!head || !head->next) return NULL;
    Node *slow=head, *fast=head->next;
    while(fast->next && fast->next->next) {
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=slow->next->next;
    return head;
}
