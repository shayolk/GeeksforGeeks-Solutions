#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int,int> a, const pair<int,int> b) {
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        unordered_map<int,int> m;
        for(int i=0; i<n; ++i) {
            int x;
            scanf("%d", &x);
            ++m[x];
        }
        vector<pair<int,int>> a;
        for(auto i: m) {
            a.push_back({i.second, i.first});
        }
        sort(a.begin(), a.end(), comp);
        for(auto i: a) {
            for(int j=0; j<i.first; ++j) {
                printf("%d ", i.second);
            }
        }
        printf("\n");
    }
    
    return 0;
}
