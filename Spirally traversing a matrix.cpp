#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d%d", &n,&m);
        vector<vector<int>> a(n, vector<int>(m));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        int i=0, j=-1, dir=0, horl=0, horr=m-1, verl=0, verr=n-1;
        while(horl<=horr && verl<=verr) {
            if(dir==0) {
                ++j;
                while(j<=horr) printf("%d ", a[i][j++]);
                --j;
                ++verl;
            }
            else if(dir==1) {
                ++i;
                while(i<=verr) printf("%d ", a[i++][j]);
                --i;
                --horr;
            }
            else if(dir==2) {
                --j;
                while(j>=horl) printf("%d ", a[i][j--]);
                ++j;
                --verr;
            }
            else {
                --i;
                while(i>=verl) printf("%d ", a[i--][j]);
                ++i;
                ++horl;
            }
            dir=(dir+1)%4;
        }
        printf("\n");
    }
    
    return 0;
}
