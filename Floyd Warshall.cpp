#include <bits/stdc++.h>
using namespace std;

#define INF 1e7
 
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<vector<int>> adj(n, vector<int> (n));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                scanf("%d", &adj[i][j]);
            }
        }
        for(int k=0; k<n; ++k) {
            for(int i=0; i<n; ++i) {
                for(int j=0; j<n; ++j) {
                    adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
                    if(k==n-1) {
                        if(adj[i][j]==1e7) {
                            printf("INF ");
                        }
                        else {
                            printf("%d ", adj[i][j]);
                        }
                    }
                }
                if(k==n-1) {
                    printf("\n");
                }
            }
        }
    }
 
    return 0;
}