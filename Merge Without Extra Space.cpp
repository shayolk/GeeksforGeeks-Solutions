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
        a.push_back(2e9);
        for(int& i:b) {
            scanf("%d", &i);
        }
        b.push_back(2e9);
        int i=0, j=0;
        while(i<n || j<m) {
            if(a[i]<b[j]) {
                printf("%d ", a[i++]);
            }
            else {
                printf("%d ", b[j++]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
