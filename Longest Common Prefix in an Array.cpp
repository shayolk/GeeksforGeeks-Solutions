#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<string> s(n);
        int sz=2e9;
        for(int i=0; i<n; ++i) {
            cin>>s[i];
            sz=min(sz, (int)s[i].size());
        }
        string ans;
        for(int j=0; j<sz; ++j) {
            char c=s[0][j];
            bool flag=false;
            for(int i=1; i<n; ++i) {
                if(s[i][j]!=c) {
                    flag=true;
                    break;
                }
            }
            if(flag) break;
            ans+=c;
        }
        cout<<(ans.empty()?"-1":ans)<<'\n';
    }
    
    return 0;
}
