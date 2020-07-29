#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,s;
        scanf("%d%d", &n,&s);
        vector<int> a(n);
        for(int& i:a) {
            scanf("%d", &i);
        }
        int l=0, r, sum=0;
        bool flag=false;
        for(int i=0; i<n; ++i) {
            r=i;
            sum+=a[i];
            if(sum==s) {
                flag=true;
                break;
            }
            while(l<n && sum>s) {
                sum-=a[l++];
            }
            if(sum==s) {
                flag=true;
                break;
            }
        }
        if(flag) {
            printf("%d %d\n", l+1,r+1);
        }
        else {
            printf("-1\n");
        }
    }
    
    return 0;
}
