#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    char a[10005];
    while(t--) {
        scanf("%s", a);
        unordered_map<char,int> m;
        bool flag=true;
        for(int i=0; a[i]; ++i) {
            if(m[a[i]]) {
                printf("%c\n", a[i]);
                flag=false;
                break;
            }
            m[a[i]]=true;
        }
        if(flag) printf("-1\n");
    }
    
    return 0;
}
