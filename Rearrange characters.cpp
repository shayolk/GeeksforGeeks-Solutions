#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    char a[10005];
    while(t--) {
        vector<int> cnt(26);
        scanf("%s", a);
        for(int i=0; a[i]; ++i) {
            ++cnt[a[i]-'a'];
        }
        sort(cnt.rbegin(), cnt.rend());
        int n=strlen(a);
        bool flag=true;
        if(n-cnt[0]<cnt[0]-1) flag=false;
        printf("%d\n", flag);
    }
    
    return 0;
}
