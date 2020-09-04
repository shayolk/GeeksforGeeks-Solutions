#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(9, vector<int>(9));
vector<bool> vis;

bool check() {
    for(int i=0; i<9; ++i) {
        vis.clear();
        vis.resize(10);
        for(int j=0; j<9; ++j) {
            if(a[i][j]) {
                if(vis[a[i][j]]) return false;
                vis[a[i][j]]=true;
            }
        }
        vis.clear();
        vis.resize(10);
        for(int j=0; j<9; ++j) {
            if(a[j][i]) {
                if(vis[a[j][i]]) return false;
                vis[a[j][i]]=true;
            }
        }
    }
    for(int r=0; r<9; r+=3) {
        for(int c=0; c<9; c+=3) {
            vis.clear();
            vis.resize(10);
            for(int i=r; i<r+3; ++i) {
                for(int j=c; j<c+3; ++j) {
                    if(a[i][j]) {
                        if(vis[a[i][j]]) return false;
                        vis[a[i][j]]=true;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        printf("%d\n", check());
    }
    
    return 0;
}
