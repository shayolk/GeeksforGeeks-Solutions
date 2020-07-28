#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for(int i=0; i<n; ++i) {
            scanf("%d", &a[i]);
        }
        multiset<int> s;
        for(int i=n-1; i>=0; --i) {
            s.insert(a[i]);
            a[i]=distance(s.begin(), s.find(a[i]));
        }
        for(int i=0; i<n; ++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    
    return 0;
}
