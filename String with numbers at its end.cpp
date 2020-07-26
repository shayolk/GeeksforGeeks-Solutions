#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        string s;
        cin>>s;
        int n=(int)s.size();
        int cnt=0, ten=1;
        for(int i=n-1; i>=0; --i) {
            if(isdigit(s[i])) {
                cnt+=ten*(s[i]-'0');
                ten*=10;
                --n;
            }
            else break;
        }
        printf("%d\n", n==cnt);
    }
    
    return 0;
}
