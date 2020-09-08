#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<char>> a;
map<tuple<int,int,int,int>,int> mp;

bool safe(int r, int c) {
    return r>=0 && r<n && c>=0 && c<m;
}

int dfs(int lr, int lc, int rr, int rc) {
    if(!safe(lr,lc) || !safe(rr,rc)) return 0;
    if(rr<lr || rc<lc) return 0;
    if(a[lr][lc]!=a[rr][rc]) return 0;
    if(abs((rr-lr)+(rc-lc))<=1) return 1;
    if(mp.count(make_tuple(lr,lc,rr,rc))) return mp[make_tuple(lr,lc,rr,rc)];
    int ret=0;
    for(pair<int,int> l: {make_pair(1,0), make_pair(0,1)}) {
        for(pair<int,int> r: {make_pair(-1,0), make_pair(0,-1)}) {
            if(lr+l.first<=rr+r.first && lc+l.second<=rc+r.second) {
                ret+=dfs(lr+l.first,lc+l.second,rr+r.first,rc+r.second);
            }
        }
    }
    mp[make_tuple(lr,lc,rr,rc)]=ret;
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n,&m);
        a.clear();
        mp.clear();
        a.resize(n, vector<char>(m));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                cin>>a[i][j];
            }
        }
        printf("%d\n", dfs(0,0,n-1,m-1));
    }
    
    return 0;
}
