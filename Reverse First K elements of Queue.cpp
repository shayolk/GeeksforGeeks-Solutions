//User function Template for C++

queue<ll> modifyQueue(queue<ll> q, int k) {
    stack<ll> s;
    while(k--) {
        s.push(q.front());
        q.pop();
    }
    queue<ll> ret;
    while(!s.empty()) {
        ret.push(s.top());
        s.pop();
    }
    while(!q.empty()) {
        ret.push(q.front());
        q.pop();
    }
    return ret;
}
