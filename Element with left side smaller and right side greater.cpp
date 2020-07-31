#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n), suf(n);
        for(int& i:a) {
            scanf("%d", &i);
        }
        suf[n-1]=a[n-1];
        for(int i=n-2; i>=0; --i) {
            suf[i]=min(a[i], suf[i+1]);
        }
        bool flag=true;
        int mx=a[0];
        for(int i=1; i<n-1; ++i) {
            if(mx<=a[i] && a[i]<=suf[i+1]) {
                flag=false;
                printf("%d\n", a[i]);
                break;
            }
            mx=max(mx,a[i]);
        }
        if(flag) printf("-1\n");
    }
    
    return 0;
}
