/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin() {
    if(s.empty()) return -1;
    return s.top();
}

/*returns poped element from stack*/
int _stack ::pop() {
    if(s.empty()) return -1;
    s.pop();
    int ret=s.top();
    s.pop();
    return ret;
}

/*push element x into the stack*/
void _stack::push(int x) {
    int mn=min(x, s.empty()?INT_MAX:s.top());
    s.push(x);
    s.push(mn);
}
