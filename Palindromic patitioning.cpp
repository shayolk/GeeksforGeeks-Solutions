#include <bits/stdc++.h>
using namespace std;

// bool palin(char s[], int i, int j) {
//     int cnt=(j-i+1)/2;
//     for(int x=0; x<cnt; ++x) {
//         if(s[i+x]!=s[j-x]) {
//             return false;
//         }
//     }
//     return true;
// }
 
int main() {
    int t;
    scanf("%d", &t);
    char s[1001];
    while(t--) {
        scanf("%s", &s);
        int n=strlen(s);
       // vector<vector<int>> dp(n, vector<int> (n));
        vector<int> dp(n);
        vector<vector<bool>> pal(n, vector<bool> (n, true));
        for(int gap=1; gap<n; ++gap) {
            for(int i=0; i+gap<n; ++i) {
                int j=i+gap;
               // pal[i][j]=palin(s,i,j);
                if(gap==1) {
                    pal[i][j]=s[i]==s[j];
                }
                else {
                    pal[i][j]=(s[i]==s[j]) && pal[i+1][j-1];
                }
            }
        }
        for(int i=0; i<n; ++i) {
            if(pal[0][i]) {
                continue;
            }
            dp[i]=2e9;
            for(int j=0; j<i; ++j) {
                if(pal[j+1][i]) {
                    dp[i]=min(dp[i], 1+dp[j]);
                }
            }
        }
        printf("%d\n", dp[n-1]);
    }
 
    return 0;
}