#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char,int> m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    
    int t;
    scanf("%d", &t);
    while(t--) {
        string s;
        cin>>s;
        int n=(int)s.size(), ans=0, p=0;
        for(int i=n-1; i>=0; --i) {
            if(m[s[i]]>=p) ans+=m[s[i]];
            else ans-=m[s[i]];
            p=m[s[i]];
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
