#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    priority_queue<int> mx;
    priority_queue<int,vector<int>,greater<int>> mn;
    for(int i=0; i<n; ++i) {
        int x;
        scanf("%d", &x);
        if((int)mx.size()>(int)mn.size()) {
            mx.push(x);
            mn.push(mx.top());
            mx.pop();
            printf("%d\n", (mx.top()+mn.top())/2);
        }
        else {
            mn.push(x);
            mx.push(mn.top());
            mn.pop();
            printf("%d\n", mx.top());
        }
    }
    
    return 0;
}
