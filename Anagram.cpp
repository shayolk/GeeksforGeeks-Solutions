#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        string a,b;
        cin>>a>>b;
        int n=(int)a.size(), m=(int)b.size();
        if(n!=m) {
            puts("NO");
            continue;
        }
        unordered_map<char,int> mp;
        for(char c: a) {
            ++mp[c];
        }
        bool flag=true;
        for(char c: b) {
            if(!mp.count(c) || !mp[c]) {
                flag=false;
                break;
            }
            --mp[c];
            if(!mp[c]) mp.erase(c);
        }
        if(!mp.empty()) flag=false;
        puts(flag?"YES":"NO");
        // sort(a.begin(), a.end());
        // sort(b.begin(), b.end());
        // puts(a==b?"YES":"NO");
    }
    
    return 0;
}
