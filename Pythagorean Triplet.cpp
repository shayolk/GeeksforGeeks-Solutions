#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for(int& i:a) {
            scanf("%d", &i);
        }
        sort(a.begin(), a.end());
        bool flag=false;
        for(int k=n-1; k>=2; --k) {
            int i=0, j=k-1;
            while(i<j) {
                if(a[i]*a[i]+a[j]*a[j]==a[k]*a[k]) {
                    flag=true;
                    break;
                }
                if(a[i]*a[i]+a[j]*a[j]>a[k]*a[k]) --j;
                else ++i;
            }
            if(flag) break;
        }
        puts(flag?"Yes":"No");
    }
    
    return 0;
}
