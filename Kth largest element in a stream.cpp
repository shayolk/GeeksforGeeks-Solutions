#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d%d", &k,&n);
        priority_queue<int,vector<int>,greater<int>> left;
        priority_queue<int> right;
        for(int i=0; i<n; ++i) {
            int x;
            scanf("%d", &x);
            if((int)left.size()<k-1) {
                left.push(x);
                printf("-1 ");
            }
            else {
                left.push(x);
                right.push(left.top());
                left.pop();
                printf("%d ", right.top());
            }
        }
        printf("\n");
    }
    
    return 0;
}
