/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

/* The method push to push element into the queue*/
void MyQueue:: push(int x) {
    QueueNode* temp=new QueueNode(x);
    if(!rear) {
        rear=temp;
        front=temp;
    }
    else {
        rear->next=temp;
        rear=temp;
    }
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop() {
    if(!front) return -1;
    int ret=front->data;
    if(front==rear) rear=NULL;
    front=front->next;
    return ret;
}
