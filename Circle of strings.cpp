#include <bits/stdc++.h>
using namespace std;

bool dfs(int now, int st, int cnt, int n, vector<vector<string>>& a, vector<vector<bool>>& vis) {
    if(cnt==n) return now==st;
    for(int i=0; i<(int)a[now].size(); ++i) {
        if(!vis[now][i]) {
            vis[now][i]=true;
            if(dfs(a[now][i].back()-'a',st,cnt+1,n,a,vis)) return true;
            vis[now][i]=false;
        }
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        string s;
        vector<vector<string>> a(26);
        vector<vector<bool>> vis(26);
        for(int i=0; i<n; ++i) {
            cin>>s;
            a[s[0]-'a'].push_back(s);
            vis[s[0]-'a'].push_back(false);
        }
        int now=s.back()-'a', st=s[0]-'a';
        vis[st][(int)vis[st].size()-1]=true;
        printf("%d\n", dfs(now,st,1,n,a,vis));
    }
    
    return 0;
}
