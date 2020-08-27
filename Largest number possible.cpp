#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,s;
        scanf("%d%d", &n,&s);
        if(n==0 || s==0 || s>9*n) {
            printf("-1\n");
            continue;
        }
        while(s>=9 && n) {
            printf("9");
            s-=9;
            --n;
        }
        if(s&&n) {
            printf("%d", s);
            --n;
        }
        while(n--) {
            printf("0");
        }
        printf("\n");
    }
    
    return 0;
}
