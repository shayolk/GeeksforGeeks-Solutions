/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */
int size(Node* head) {
    if(!head) return 0;
    return 1+size(head->next);
}

bool isPalindrome(Node *head) {
    int n=size(head);
    stack<int> s;
    for(int i=0; i<n/2; ++i) {
        s.push(head->data);
        head=head->next;
    }
    if(n%2) head=head->next;
    while(head) {
        if(head->data != s.top()) return false;
        s.pop();
        head=head->next;
    }
    return true;
}
