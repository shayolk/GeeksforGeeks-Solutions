#include <bits/stdc++.h>
using namespace std;

const int nax=1e4+1;
 
int main() {
    vector<long long> ugly(nax, 1);
    int i2=1, i3=1, i5=1;
    long long next2=2, next3=3, next5=5;
    for(int i=2; i<nax; ++i) {
        long long next=min({next2, next3, next5});
        ugly[i]=next;
        if(next==next2) {
            next2=ugly[++i2]*2;
        }
        if(next==next3) {
            next3=ugly[++i3]*3;
        }
        if(next==next5) {
            next5=ugly[++i5]*5;
        }
    }
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", ugly[n]);
    }
 
    return 0;
}