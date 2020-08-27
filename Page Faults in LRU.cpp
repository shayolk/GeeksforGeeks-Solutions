#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for(int& i:a) {
            scanf("%d", &i);
        }
        int k;
        scanf("%d", &k);
        queue<int> q;
        unordered_map<int,bool> m;
        int fault=0;
        for(int i=0; i<n; ++i) {
            if(!m[a[i]]) {
                ++fault;
                m[a[i]]=true;
                q.push(a[i]);
            }
            else {
                queue<int> q1;
                while(!q.empty()) {
                    if(q.front()!=a[i]) q1.push(q.front());
                    q.pop();
                }
                while(!q1.empty()) {
                    q.push(q1.front());
                    q1.pop();
                }
                q.push(a[i]);
            }
            if((int)q.size()==k+1) {
                m[q.front()]=false;
                q.pop();
            }
        }
        printf("%d\n", fault);
    }
    
    return 0;
}
