#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d%d", &n,&m);
        vector<int> a(n), b(m);
        for(int& i:a) {
            scanf("%d", &i);
        }
        for(int& i:b) {
            scanf("%d", &i);
        }
        int i=0, j=0, a1=0, b1=0, sum=0;
        while(i<n && j<m) {
            if(a[i]==b[j]) {
                sum+=max(a1, b1);
                int x=a[i];
                a1=x; b1=x;
                ++i; ++j;
                while(i<n && a[i]==x) {
                    a1+=x;
                    ++i;
                }
                while(j<m && b[j]==x) {
                    b1+=x;
                    ++j;
                }
                sum+=max(a1, b1);
                a1=0; b1=0;
            }
            else if(a[i]<b[j]) {
                a1+=a[i++];
            }
            else {
                b1+=b[j++];
            }
        }
        while(i<n) a1+=a[i++];
        while(j<m) b1+=b[j++];
        sum+=max(a1, b1);
        printf("%d\n", sum);
    }
    
    return 0;
}
