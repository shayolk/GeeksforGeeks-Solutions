/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node * mergeKLists(Node *a[], int n) {
    Node* head=NULL;
    Node *t, *temp;
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> p;
    for(int i=0; i<n; ++i) {
        if(a[i]) p.push({a[i]->data,a[i]});
    }
    while(!p.empty()) {
        temp=p.top().second;
        p.pop();
        if(head) {
            t->next=temp;
            t=t->next;
        }
        else {
            t=temp;
            head=t;
        }
        if(temp->next) p.push({temp->next->data, temp->next});
    }
    return head;
}
