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
        int i=0, j=n-1, flag=1;
        while(i<=j) {
            if(flag) printf("%d ", a[j--]);
            else printf("%d ", a[i++]);
            flag^=1;
        }
        printf("\n");
    }
    
    return 0;
}
