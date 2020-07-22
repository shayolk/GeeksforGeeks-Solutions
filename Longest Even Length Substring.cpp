#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        string s;
        cin>>s;
        int n=(int)s.size();
        vector<int> pref(n+1);
        for(int i=0; i<n; ++i) {
            int his=s[i]-'0';
            pref[i+1]=pref[i]+his;
        }
        int ans=0;
        for(int gap=2; gap<=n; gap+=2) {
            for(int lo=1; lo+gap-1<=n; ++lo) {
                int hi=lo+gap-1, mid=lo+gap/2-1;
                if(pref[mid]-pref[lo-1]==pref[hi]-pref[mid]) {
                    ans=max(ans, gap);
                }
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
