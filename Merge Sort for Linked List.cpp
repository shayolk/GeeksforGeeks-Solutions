/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */
   
Node* split(Node* head) {
    Node *slow=head, *fast=head, *cur=head;
    while(fast && fast->next) {
        cur=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    cur->next=NULL;
    return slow;
}

Node* sortedMerge(Node* head_A, Node* head_B)  
{
    if(!head_A) {
        return head_B;
    }
    if(!head_B) {
        return head_A;
    }
    if(head_A->data<head_B->data) {
        head_A->next=sortedMerge(head_A->next, head_B);
        return head_A;
    }
    head_B->next=sortedMerge(head_A, head_B->next);
    return head_B;
}   
   
Node* mergeSort(Node* head) {
    if(!head || !head->next) {
        return head;
    }
    Node* mid=split(head);
    Node* a=mergeSort(head);
    Node* b=mergeSort(mid);
    return sortedMerge(a,b);
}