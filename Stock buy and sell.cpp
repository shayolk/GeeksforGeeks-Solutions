#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for(int& i:a) {
            scanf("%d", &i);
        }
        vector<pair<int,int>> v;
        int st=0, i=1;
        while(i<n) {
            if(a[i]<a[i-1]) {
                if(st<i-1) v.push_back({st,i-1});
                st=i;
            }
            ++i;
        }
        if(st<i-1) v.push_back({st,i-1});
        if(v.empty()) {
            printf("No Profit\n");
            continue;
        }
        for(auto j:v) {
            printf("(%d %d) ", j.first,j.second);
        }
        printf("\n");
    }
    
    return 0;
}
