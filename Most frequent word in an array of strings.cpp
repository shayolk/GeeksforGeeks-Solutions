#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<string> a(n);
        map<string,int> m;
        for(string& s: a) {
            cin>>s;
            ++m[s];
        }
        string ans;
        int cnt=0;
        for(string s: a) {
            if(m[s]>=cnt) {
                ans=s;
                cnt=m[s]--;
            }
        }
        cout<<ans<<'\n';
    }
    
    return 0;
}
