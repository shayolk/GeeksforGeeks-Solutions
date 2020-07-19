#include <bits/stdc++.h>
using namespace std;

// bool check(vector<int> a, int sum, int i, int now) {
//     if(i<0 || now>sum) {
//         return false;
//     }
//     if(now==sum) {
//         return true;
//     }
//     return check(a,sum,i-1,now) || check(a,sum,i-1,now+a[i]);
// }

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, sum=0;
        scanf("%d", &n);
        vector<int> a(n);
        for(int& i: a) {
            scanf("%d", &i);
            sum+=i;
        }
       // if(sum&1 || !check(a, sum/2, n-1, 0)) {
       //     printf("NO\n");
       //     continue;
       // }
       // printf("YES\n");
        if(sum&1) {
            printf("NO\n");
            continue;
        }
        sum/=2;
        vector<bool> dp(sum+1);
        dp[0]=true;
        for(int i: a) {
            vector<int> ind;
            for(int j=0; j+i<=sum; ++j) {
                if(dp[j]) {
                   // dp[j+i]=true;
                    ind.emplace_back(j+i);
                }
            }
            for(int j: ind) {
                dp[j]=true;
            }
        }
        if(dp[sum]) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
 
    return 0;
}