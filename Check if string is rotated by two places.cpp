#include <bits/stdc++.h>
using namespace std;

bool rot(string& a, string& b, int& n) {
    if(n<=2) return a==b;
    bool cl=true;
    for(int i=0; i<n; ++i) {
        cl&=b[i]==a[(i+2)%n];
        if(!cl) break;
    }
    bool acl=true;
    for(int i=0; i<n; ++i) {
        acl&=a[i]==b[(i+2)%n];
        if(!acl) break;
    }
    return cl||acl;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        string a,b;
        cin>>a>>b;
        int n=(int)a.size();
        printf("%d\n", rot(a,b,n));
    }
    
    return 0;
}
