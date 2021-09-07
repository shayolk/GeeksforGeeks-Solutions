/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        if(!head || !head->next) return head;
        Node* h=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return h;
    }
    
};
