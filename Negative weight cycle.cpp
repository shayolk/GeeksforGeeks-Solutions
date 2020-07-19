#include <bits/stdc++.h>
using namespace std;

#define INF 2e9
 
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int v,e;
        scanf("%d%d", &v,&e);
        vector<pair<pair<int,int>,int>> edges;
        for(int i=0; i<e; ++i) {
            int x,y,z;
            scanf("%d%d%d", &x,&y,&z);
            edges.push_back({{x,y},z});
        }
        vector<int> dist(v, INF);
        dist[0]=0;
        for(int i=1; i<v; ++i) {
            for(auto j: edges) {
                dist[j.first.second]=min(dist[j.first.second], dist[j.first.first]+j.second);
            }
        }
        bool flag=true;
        for(auto j: edges) {
            if(dist[j.first.first]+j.second < dist[j.first.second]) {
                puts("1");
                flag=false;
                break;
            }
        }
        if(flag) {
            puts("0");
        }
    }
 
    return 0;
}