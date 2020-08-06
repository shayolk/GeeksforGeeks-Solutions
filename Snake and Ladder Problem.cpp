#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<vector<int>> adj(37);
        vector<int> next(37);
        for(int i=0; i<37; ++i) {
            next[i]=i;
        }
        while(n--) {
            int x,y;
            scanf("%d%d", &x,&y);
            next[x]=y;
        }
        for(int i=1; i<30; ++i) {
            for(int j=1; j<=6; ++j) {
                adj[i].push_back(next[i+j]);
            }
        }
        vector<int> dist(37, 2e9);
        dist[1]=0;
        vector<bool> vis(37);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        p.push({0,1});
        while(!p.empty()) {
            pair<int,int> pr=p.top();
            p.pop();
            int d=pr.first, i=pr.second;
            if(i==30) break;
            if(dist[i]<d) continue;
            vis[i]=true;
            for(int j: adj[i]) {
                if(!vis[j] && dist[i]+1<dist[j]) {
                    dist[j]=dist[i]+1;
                    p.push({dist[j],j});
                }
            }
        }
        printf("%d\n", dist[30]);
    }
    
    return 0;
}
