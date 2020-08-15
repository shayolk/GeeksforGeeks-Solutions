#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    char a[100005], b[100005];
    while(t--) {
        scanf("%s%s", a,b);
        unordered_map<char,bool> m,n;
        for(int i=0; a[i]; ++i) {
            m[a[i]]=true;
        }
        for(int i=0; b[i]; ++i) {
            if(n[b[i]]) continue;
            n[b[i]]=true;
            m[b[i]]^=true;
        }
        string s;
        for(auto i: m) {
            if(i.second) {
                s+=i.first;
            }
        }
        sort(s.begin(), s.end());
        cout<<s<<'\n';
    }
    
    return 0;
}
