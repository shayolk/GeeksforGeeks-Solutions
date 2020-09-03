#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        string a,s,ans;
        cin>>a;
        for(char c: a) {
            if(c=='.') {
                reverse(s.begin(), s.end());
                ans+=s+'.';
                s.clear();
            }
            else {
                s+=c;
            }
        }
        reverse(s.begin(), s.end());
        ans+=s;
        cout<<ans<<'\n';
    }
    
    return 0;
}
