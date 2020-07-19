#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for(int& i: a) {
            scanf("%d", &i);
        }
        vector<int> inc(n), dec(n), dp(n,1);
        inc[0]=1;
        for(int i=1; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                if(a[i]>a[j]) {
                    inc[i]=max(inc[i], inc[j]);
                }
            }
            ++inc[i];
        }
        dec[n-1]=1;
        for(int i=n-2; i>=0; --i) {
            for(int j=n-1; j>i; --j) {
                if(a[i]>a[j]) {
                    dec[i]=max(dec[i], dec[j]);
                }
            }
            ++dec[i];
        }
        for(int i=1; i<n-1; ++i) {
            int left=0, right=0;
            for(int j=0; j<i; ++j) {
                if(a[j]<a[i]) {
                    left=max(left, inc[j]);
                }
            }
            for(int j=n-1; j>i; --j) {
                if(a[i]>a[j]) {
                    right=max(right, dec[j]);
                }
            }
            dp[i]+=left+right;
        }
        int ans=max({
            *max_element(inc.begin(), inc.end()),
            *max_element(dec.begin(), dec.end()),
            *max_element(dp.begin(), dp.end())
        });
        printf("%d\n", ans);
    }
 
    return 0;
}