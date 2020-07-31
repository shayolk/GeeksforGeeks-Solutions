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
        for(int i=1; i<n; ++i) {
            if(i&1) {
                if(a[i-1]>a[i]) swap(a[i-1], a[i]);
            }
            else {
                if(a[i-1]<a[i]) swap(a[i-1], a[i]);
            }
        }
        for(int i:a) {
            printf("%d ", i);
        }
        printf("\n");
    }
    
    return 0;
}
