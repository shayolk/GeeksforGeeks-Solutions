#include <bits/stdc++.h>
using namespace std;

bool assign(vector<int> a, int cap, int k) {
    int cnt=1, sum=0;
    for(int i:a) {
        sum+=i;
        if(sum>cap) {
            sum=i;
            ++cnt;
        }
    }
    return cnt<=k;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int k,n;
        scanf("%d%d", &k,&n);
        vector<int> a(n), pref={0};
        int lo=0, hi=0;
        for(int& i: a) {
            scanf("%d", &i);
            // pref.push_back(pref.back()+i);
            lo=max(lo, i);
            hi+=i;
        }
        /* Binary Search Solution */
        while(lo<hi) {
            int mid=lo+(hi-lo)/2;
            if(assign(a, mid, k)) {
                hi=mid;
            }
            else {
                lo=mid+1;
            }
        }
        printf("%d\n", lo);
        /* DP solution */
        // vector<vector<int>> dp(k+1, vector<int> (n+1));
        // for(int j=1; j<=n; ++j) {
        // 	dp[1][j]=pref[j];
        // }
        // for(int i=2; i<=k; ++i) {
        //     for(int j=1; j<=n; ++j) {
        //         dp[i][j]=2e9;
        //         for(int l=0; l<=j; ++l) {
        //             dp[i][j]=min(dp[i][j], max(dp[i-1][l], pref[j]-pref[l]));
        //         }
        //     }
        // }
        // printf("%d\n", dp[k][n]);
    }
    
    return 0;
}
