#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    char s[2005];
    while(t--) {
        scanf("%s", s);
        int n=strlen(s);
        int i=0, j=n-1;
        while(i<j) {
            swap(s[i++], s[j--]);
        }
        i=0;
        while(i<n) {
            j=i;
            while(j<n && s[j]!='.') ++j;
            int lo=i, hi=j-1;
            while(lo<hi) swap(s[lo++], s[hi--]);
            i=j+1;
        }
        puts(s);
    }
    
    return 0;
}
