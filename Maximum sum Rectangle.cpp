#include <bits/stdc++.h>
using namespace std;

#define fr first
#define sc second
 
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d%d", &n,&m);
        vector<vector<int>> a(n, vector<int> (m)), pref(n, vector<int> (m+1));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                scanf("%d", &a[i][j]);
                pref[i][j+1]=pref[i][j]+a[i][j];
            }
        }
        int ans=-2e9;
        for(int gap=0; gap<m; ++gap) {
            for(int i=1; i+gap<=m; ++i) {
                int j=i+gap;
                int so=0;
                for(int row=0; row<n; ++row) {
                    so=max(so+pref[row][j]-pref[row][i-1], pref[row][j]-pref[row][i-1]);
                    ans=max(ans, so);
                }
            }
        }
        printf("%d\n", ans);
    }
 
    return 0;
}