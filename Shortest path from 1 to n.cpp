#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int cnt=0;
        while(n!=1) {
            (n%3)?(--n):(n/=3);
            ++cnt;
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}
