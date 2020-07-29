#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<pair<int,int>> a(n);
        for(int i=0; i<n; ++i) {
            scanf("%d", &a[i].second);
        }
        for(int i=0; i<n; ++i) {
            scanf("%d", &a[i].first);
        }
        sort(a.begin(), a.end());
        int cnt=0, end=0;
        for(int i=0; i<n; ++i) {
            if(a[i].second>=end) {
                ++cnt;
                end=a[i].first;
            }
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}
