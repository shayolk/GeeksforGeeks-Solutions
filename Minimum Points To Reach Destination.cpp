#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
	    int n,m;
	    scanf("%d%d", &n,&m);
	    vector<vector<int>> a(n, vector<int> (m)), dp(n, vector<int> (m));
	    for(int i=0; i<n; ++i) {
	    	for(int j=0; j<m; ++j) {
	    		scanf("%d", &a[i][j]);
	    	}
	    }
	    dp[n-1][m-1]=a[n-1][m-1]>0?1:1-a[n-1][m-1];
	    for(int i=n-2; i>=0; --i) {
	        dp[i][m-1]=max(dp[i+1][m-1]-a[i][m-1], 1);
	    }
	    for(int j=m-2; j>=0; --j) {
	        dp[n-1][j]=max(dp[n-1][j+1]-a[n-1][j], 1);
	    }
	    for(int i=n-2; i>=0; --i) {
	        for(int j=m-2; j>=0; --j) {
	            dp[i][j]=max(min(dp[i+1][j], dp[i][j+1])-a[i][j], 1);
	        }
	    }
	    printf("%d\n", dp[0][0]);
	    /*Not sure about what exactly is the bug in the later implementation*/
	   // if(a[0][0]>0) {
	   //     dp[0][0]=1;
	   //     ++a[0][0];
	   // }
	   // else {
	   //     dp[0][0]=1-a[0][0];
	   //     a[0][0]=1;
	   // }
	   // for(int i=1; i<n; ++i) {
	   //     if(a[i-1][0]+a[i][0]>0) {
	   //         dp[i][0]=dp[i-1][0];
	   //         a[i][0]+=a[i-1][0];
	   //     }
	   //     else {
	   //         dp[i][0]=dp[i-1][0]+1-(a[i-1][0]+a[i][0]);
	   //         a[i][0]=1;
	   //     }
	   // }
	   // for(int j=1; j<m; ++j) {
	   //     if(a[0][j-1]+a[0][j]>0) {
	   //         dp[0][j]=dp[0][j-1];
	   //         a[0][j]+=a[0][j-1];
	   //     }
	   //     else {
	   //         dp[0][j]=dp[0][j-1]+1-(a[0][j-1]+a[0][j]);
	   //         a[0][j]=1;
	   //     }
	   // }
	   // for(int i=1; i<n; ++i) {
	   //     for(int j=1; j<m; ++j) {
	   //         int x=a[i][j], y=dp[i][j];
	   //         if(a[i][j-1]+a[i][j]>0) {
	   //             y=dp[i][j-1];
	   //             x+=a[i][j-1];
	   //         }
	   //         else {
	   //             y=dp[i][j-1]+1-(a[i][j-1]+a[i][j]);
	   //             x=1;
	   //         }
	   //         if(a[i-1][j]+a[i][j]>0) {
	   //             dp[i][j]=dp[i-1][j];
	   //             a[i][j]+=a[i-1][j];
	   //         }
	   //         else {
	   //             dp[i][j]=dp[i-1][j]+1-(a[i-1][j]+a[i][j]);
	   //             a[i][j]=1;
	   //         }
	   //         if(y<=dp[i][j]) {
	   //             dp[i][j]=y;
	   //             a[i][j]=max(a[i][j], x);
	   //         }
	   //     }
	   // }
	   // printf("%d\n", dp[n-1][m-1]);
	}
 
    return 0;
}
