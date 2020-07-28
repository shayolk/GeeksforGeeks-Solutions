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
        vector<vector<int>> dp(n, vector<int> (n));
        for(int i=1; i<n; ++i) {
            if(a[i]-a[i-1]>k) {
                dp[i-1][i]=min(a[i-1], a[i]-(a[i-1]+k));
            }
        }
        for(int gap=2; gap<n; ++gap) {
            for(int i=0; i+gap<n; ++i) {
                int j=i+gap;
                if(a[j]-a[i]>k) {
                    dp[i][j]=min(a[i]+dp[i+1][j], a[j]-(a[i]+k)+dp[i][j-1]);
                }
            }
        }
        printf("%d\n", dp[0][n-1]);
        // int ans=0, i=0, j=n-1;
        // while(i<n && j>=0 && i<j && a[j]-a[i]>k) {
        //     int x=0, y=0, l=j, m=i;
        //     while(m<n && m<j && a[j]-a[m]>k) {
        //         x+=a[m];
        //         ++m;
        //     }
        //     while(l>=0 && l>i && a[l]>a[i]+k) {
        //         y+=a[l]-(a[i]+k);
        //         --l;
        //     }
        //     if(x<y) {
        //         ans+=x;
        //         i=m;
        //     }
        //     else {
        //         ans+=y;
        //         j=l;
        //     }
        // }
        // printf("%d\n", ans);
    }
    
    return 0;
}
