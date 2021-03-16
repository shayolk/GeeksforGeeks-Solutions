/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution
{
    public:
    int getCount(struct Node* head){
        if(!head) {
            return 0;
        }
        return 1+getCount(head->next);
    }
};