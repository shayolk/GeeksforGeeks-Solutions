#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d%d", &n,&k);
        vector<int> a(n);
        for(int& i: a) {
            scanf("%d", &i);
        }
        sort(a.begin(), a.end());
        int i=0;
        while(i<n && k>=a[i]) {
            k-=a[i++];
        }
        printf("%d\n", i);
    }
    
    return 0;
}
