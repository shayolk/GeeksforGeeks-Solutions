#include <bits/stdc++.h>
using namespace std;

bool safe(int r, int c, int n, vector<vector<int>> a, vector<int> sol) {
    for(int i=0; i<(int)sol.size(); ++i) {
        if(sol[i]==r) {
            return false;
        }
        else if(r-sol[i]==c-i) {
            return false;
        }
        else if(sol[i]-r==c-i) {
            return false;
        }
    }
    return true;
    // for(int j=0; j<c; ++j) {
    //     if(a[r][j]) {
    //         return false;
    //     }
    // }
    // for(int i=r-1, j=c-1; i>=0 && j>=0; --i, --j) {
    //     if(a[i][j]) {
    //         return false;
    //     }
    // }
    // for(int i=r+1, j=c-1; i<n && j>=0; ++i, --j) {
    //     if(a[i][j]) {
    //         return false;
    //     }
    // }
    // return true;
}

void back(int j, int n, vector<vector<int>>& a, vector<int>& sol, vector<vector<int>>& ans) {
    if(j==n) {
        ans.push_back(sol);
        return;
    }
    for(int i=0; i<n; ++i) {
        if(safe(i,j,n,a,sol)) {
            sol.push_back(i);
            a[i][j]=1;
            back(j+1,n,a,sol,ans);
            sol.pop_back();
            a[i][j]=0;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<vector<int>> a(n, vector<int>(n)), ans;
        vector<int> sol;
        back(0,n,a,sol,ans);
        if(ans.empty()) {
            printf("-1\n");
            continue;
        }
        // sort(ans.begin(), ans.end());
        for(auto i: ans) {
            printf("[");
            for(int j: i) {
                printf("%d ", j+1);
            }
            printf("] ");
        }
        printf("\n");
    }
    
    return 0;
}
