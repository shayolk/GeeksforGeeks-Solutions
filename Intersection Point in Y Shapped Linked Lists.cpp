#include <bits/stdc++.h>

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */

// Node* dfs(Node* head, unordered_map<Node*,bool>& m) {
//     stack<Node*> s;
//     s.push(head);
//     if(m.count(head) && m[head]) return head;
//     m[head]=true;
//     while(!s.empty()) {
//         Node* t=s.top();
//         s.pop();
//         if(t->next) {
//             if(m.count(t->next) && m[t->next]) return t->next;
//             if(!m.count(t->next)) {
//                 m[t->next]=true;
//                 s.push(t->next);
//             }
//         }
//     }
//     return NULL;
// }

int count(Node* head) {
    if(!head) return 0;
    return 1+count(head->next);
}

int intersectPoint(Node* head1, Node* head2) {
    int x=count(head1), y=count(head2);
    if(y>x) swap(head1, head2);
    int cnt=abs(x-y);
    while(cnt--) head1=head1->next;
    while(head1) {
        if(head1==head2) return head1->data;
        head1=head1->next;
        head2=head2->next;
    }
    return -1;
    // unordered_map<Node*,bool> m;
    // dfs(head1, m);
    // Node* t=dfs(head2, m);
    // if(t) return t->data;
    // return -1;
}
