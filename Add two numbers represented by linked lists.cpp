#warning Method-1

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node* add(Node* a, Node* b, int& c, int k) {
        if(!a && !b) {
            return NULL;
        }
        Node* t=new Node(0);
        t->next=add(a->next, k?b:b->next, c, k?k-1:k);
        int sum=c+(a->data)+(k?0:b->data);
        t->data=sum%10;
        c=sum/10;
        return t;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        auto len=[&](Node* t) {
            int l=0;
            while(t) {
                ++l;
                t=t->next;
            }
            return l;
        };
        int a=len(first), b=len(second);
        int c=0;
        Node* head=add(a>b?first:second, a>b?second:first, c, abs(a-b));
        if(c) {
            Node* t=new Node(c);
            t->next=head;
            head=t;
        }
        return head;
    }
};



#warning Method-2

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

Node* reverse(Node* head) {
    if(!head || !head->next) return head;
    Node* tail=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return tail;
}

int size(Node* head) {
    if(!head) return 0;
    return 1+size(head->next);
}

struct Node* addTwoLists(struct Node* first, struct Node* second) {
    if(!first) return second;
    if(!second) return first;
    first=reverse(first);
    second=reverse(second);
    if(size(second)>size(first)) swap(first, second);
    int carry=0, x;
    Node *head=NULL, *t;
    while(first && second) {
        x=first->data+second->data+carry;
        carry=x/10;
        if(!head) {
            head=new Node(x%10);
            t=head;
        }
        else {
            t->next=new Node(x%10);
            t=t->next;
        }
        first=first->next;
        second=second->next;
    }
    while(first) {
        x=first->data+carry;
        carry=x/10;
        t->next=new Node(x%10);
        t=t->next;
        first=first->next;
    }
    if(carry) t->next=new Node(carry);
    head=reverse(head);
    return head;
}
