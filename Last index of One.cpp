#include <bits/stdc++.h>
using namespace std;

const int nax=1e6+5;
char a[nax];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", &a);
        bool flag=true;
        for(int i=strlen(a)-1; i>=0; --i) {
            if(a[i]=='1') {
                flag=false;
                printf("%d\n", i);
                break;
            }
        }
        if(flag) printf("-1\n");
    }
    
    return 0;
}
