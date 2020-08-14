#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    char a[100005], b[100005];
    while(t--) {
        scanf("%s%s", a,b);
        unordered_map<char,int> m;
        for(int i=strlen(a)-1; i>=0; --i) {
            m[a[i]]=i;
        }
        char c='$', id=2e9;
        for(int i=0; b[i]; ++i) {
            if(!m.count(b[i])) continue;
            if(m[b[i]]<id) {
                id=m[b[i]];
                c=b[i];
            }
        }
        printf("%c\n", c);
    }
    
    return 0;
}
