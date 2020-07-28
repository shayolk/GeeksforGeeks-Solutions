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
        int d;
        scanf("%d", &d);
        d%=n;
        for(int i=d,cnt=0; cnt<n; i=(i+1)%n,++cnt) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    
    return 0;
}
