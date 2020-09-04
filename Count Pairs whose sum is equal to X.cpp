/*
Structure of the node of the linked list is as
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
// your task is to complete this function
int countPairs(struct Node* head1, struct Node* head2, int x) {
    unordered_set<int> s;
    while(head1) {
        s.insert(head1->data);
        head1=head1->next;
    }
    int ans=0;
    while(head2) {
        ans+=s.count(x-head2->data);
        head2=head2->next;
    }
    return ans;
}
