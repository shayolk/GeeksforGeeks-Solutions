#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<pair<pair<int,int>,int>> a(n);
        for(int i=0; i<n; ++i) {
            scanf("%d", &a[i].first.second);
            a[i].second=i+1;
        }
        for(int i=0; i<n; ++i) {
            scanf("%d", &a[i].first.first);
        }
        sort(a.begin(), a.end());
        int end=0;
        vector<int> meet;
        for(int i=0; i<n; ++i) {
            if(a[i].first.second>=end) {
                meet.push_back(a[i].second);
                end=a[i].first.first;
            }
        }
        for(int i: meet) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}
