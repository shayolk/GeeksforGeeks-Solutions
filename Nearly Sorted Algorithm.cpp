#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d%d", &n, &k);
        priority_queue<int, vector<int>, greater<int>> p;
        for(int i=0; i<min(n, k+1); ++i) {
            int x;
            scanf("%d", &x);
            p.push(x);
        }
        for(int i=k+1; i<n; ++i) {
            printf("%d ", p.top());
            p.pop();
            int x;
            scanf("%d", &x);
            p.push(x);
        }
        while(!p.empty()) {
            printf("%d ", p.top());
            p.pop();
        }
        printf("\n");
    }
    
    return 0;
}
