#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<long long> a(n), b(n);
        for(long long& i: a) {
            scanf("%lld", &i);
        }
        for(long long& i: b) {
            scanf("%lld", &i);
        }
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        long long res=0;
        for(int i=0; i<n; ++i) {
            res+=a[i]*b[i];
        }
        printf("%lld\n", res);
    }
    
    return 0;
}
