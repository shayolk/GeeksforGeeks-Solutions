#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d%d", &n,&k);
        vector<int> a(n);
        for(int& i:a) {
            scanf("%d", &i);
        }
        sort(a.begin(), a.end());
        int need=n/(k+1)+(n%(k+1)>0);
        int x=0, y=0, i=0, j=n-1;
        while(need--) {
            x+=a[i++];
            y+=a[j--];
        }
        printf("%d %d\n", x,y);
    }
    
    return 0;
}
