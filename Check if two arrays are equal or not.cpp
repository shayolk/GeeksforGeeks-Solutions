using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        // vector<int> a(n), b(n);
        // for(int& i:a) {
        //     scanf("%d", &i);
        // }
        // sort(a.begin(), a.end());
        // for(int& i:b) {
        //     scanf("%d", &i);
        // }
        // sort(b.begin(), b.end());
        // printf("%d\n", a==b);
        unordered_map<int,int> m;
        for(int i=0; i<n; ++i) {
            int x;
            scanf("%d", &x);
            ++m[x];
        }
        bool flag=true;
        for(int i=0; i<n; ++i) {
            int x;
            scanf("%d", &x);
            if(m[x]<=0) {
                flag=false;
            }
            --m[x];
        }
        printf("%d\n", flag);
    }
    
    return 0;
}
