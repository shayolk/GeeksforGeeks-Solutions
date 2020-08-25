#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    char s[10005];
    while(t--) {
        scanf("%s", s);
        int ans=0, l=0, n=strlen(s);
        vector<int> last(256, -1);
        for(int r=0; r<n; ++r) {
            l=max(l, last[s[r]]+1);
            ans=max(ans, r-l+1);
            last[s[r]]=r;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
