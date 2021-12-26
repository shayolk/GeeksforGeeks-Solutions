void push(stack<int>& s, int a){
    if(s.empty()) {
        s.push(a);
        s.push(a);
        return;
    }
    int mn=min(s.top(), a);
    s.push(a);
    s.push(mn);
}

bool isFull(stack<int>& s,int n){
    return s.size()/2>=n;
}

bool isEmpty(stack<int>& s){
    return s.empty();
}

int pop(stack<int>& s){
    if(s.empty()) {
        return -1;
    }
    s.pop();
    int t=s.top();
    s.pop();
    return t;
}

int getMin(stack<int>& s){
    if(s.empty()) {
        return -1;
    }
    return s.top();
}
