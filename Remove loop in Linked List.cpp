/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

void removeLoop(Node* head) {
    Node *slow=head, *fast=head, *loop=NULL;
    while(fast->next && fast->next->next) {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) {
            loop=slow;
            break;
        }
    }
    if(!loop) return;
    int cnt=1;
    slow=slow->next;
    while(slow!=loop) {
        ++cnt;
        slow=slow->next;
    }
    slow=head;
    fast=head;
    while(cnt--) fast=fast->next;
    while(slow!=fast) {
        slow=slow->next;
        fast=fast->next;
    }
    while(slow->next!=fast) slow=slow->next;
    slow->next=NULL;
}
