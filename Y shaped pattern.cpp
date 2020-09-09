#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n/2; ++i) {
            for(int j=0; j<i; ++j) printf(" ");
            printf("*");
            for(int j=0; j<n-2*i-1; ++j) printf(" ");
            printf("*");
            for(int j=0; j<i; ++j) printf(" ");
            // printf("\n");
        }
        for(int i=0; i<n/2; ++i) {
            for(int j=0; j<n/2; ++j) printf(" ");
            printf("*");
            for(int j=0; j<n/2; ++j) printf(" ");
            // printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}
