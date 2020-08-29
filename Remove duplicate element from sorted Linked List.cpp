/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// root: head node
Node *removeDuplicates(Node *root) {
    if(!root || !root->next) return root;
    Node* t=root;
    while(t && root->data==t->data) t=t->next;
    root->next=removeDuplicates(t);
    return root;
}
