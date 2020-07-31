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
        vector<int> ans;
        int mx=a[n-1];
        for(int i=n-1; i>=0; --i) {
            if(a[i]>=mx) ans.push_back(a[i]);
            mx=max(mx,a[i]);
        }
        for(auto i=ans.rbegin(); i!=ans.rend(); ++i) {
            printf("%d ", *i);
        }
        printf("\n");
    }
    
    return 0;
}
