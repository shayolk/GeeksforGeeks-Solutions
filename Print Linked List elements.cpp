/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     Node *next;
  }
*/
void display(Node *head)
{
  for(Node *p=head; p!=NULL; p=p->next) {
      printf("%d ", p->data);
  }
}