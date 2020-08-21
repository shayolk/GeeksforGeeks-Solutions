#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<long long> a(n), ans(n);
        for(long long& i:a) {
            scanf("%lld", &i);
        }
        stack<long long> s;
        for(int i=n-1; i>=0; --i) {
            while(!s.empty() && s.top()<=a[i]) s.pop();
            ans[i]=s.empty()?-1:s.top();
            s.push(a[i]);
        }
        for(long long i:ans) {
            printf("%lld ", i);
        }
        printf("\n");
    }
    
    return 0;
}
