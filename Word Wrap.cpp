#include <bits/stdc++.h>
using namespace std;

#define INF 2e9

void print(vector<int> p, int n) {  
    if(p[n]!=1) {
        print(p, p[n]-1); 
    }
    printf("%d %d ", p[n], n);
}
 
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n), pref(n+1);
        for(int i=0; i<n; ++i) {
            scanf("%d", &a[i]);
            pref[i+1]=pref[i]+a[i];
        }
        int per;
        scanf("%d", &per);
        vector<vector<int>> lc(n+1, vector<int> (n+1));
        for(int i=1; i<=n; ++i) {
            for(int j=i; j<=n; ++j) {
                if(lc[i][j-1]==INF) {
                    lc[i][j]=INF;
                    continue;
                }
                int len=pref[j]-pref[i-1]+j-i;
                int space=per-len;
                if(j==n && len<=per) {
                    lc[i][j]=0;
                    continue;
                }
                lc[i][j]=len>per?INF:space*space;
            }
        }
        vector<int> c(n+1), ans(n+1);
        for(int j=1; j<=n; ++j) {
            c[j]=INF;
            for(int i=1; i<=j; ++i) {
                if(lc[i][j]!=INF && c[i-1]+lc[i][j]<c[j]) {
                    c[j]=c[i-1]+lc[i][j];
                    ans[j]=i;
                }
            }
        }
        print(ans,n);
       // int ind=0, done=ind;
       // while(ind<n) {
       //     while(ind<=n && ans[ind]!=done+1) {
       //       ++ind;
       //     }
       //     printf("%d %d ", ans[ind], ind);
       //     done=ind;
       // }
        printf("\n");
    }
 
    return 0;
}