#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int,int> a, const pair<int,int> b) {
    return abs(a.first-a.second) > abs(b.first-b.second);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,x,y;
        scanf("%d%d%d", &n,&x,&y);
        vector<pair<int,int>> v(n);
        for(int i=0; i<n; ++i) {
            scanf("%d", &v[i].first);
        }
        for(int i=0; i<n; ++i) {
            scanf("%d", &v[i].second);
        }
        sort(v.begin(), v.end(), comp);
        int ans=0;
        for(auto i: v) {
            if(x&&y) {
                if(i.first>i.second) {
                    ans+=i.first;
                    --x;
                }
                else {
                    ans+=i.second;
                    --y;
                }
            }
            else if(x) {
                ans+=i.first;
                --x;
            }
            else {
                ans+=i.second;
                --y;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
