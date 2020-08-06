#include <bits/stdc++.h>
using namespace std;

void Main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for(int& i:a) {
        scanf("%d", &i);
    }
    int k;
    scanf("%d", &k);
    if(n%2) {
        printf("False\n");
        return;
    }
    for(int i=0; i<n; ++i) {
        a[i]%=k;
    }
    sort(a.begin(), a.end());
    int i=0, j=n-1;
    while(a[i]==0) ++i;
    if(i%2) {
        printf("False\n");
        return;
    }
    while(i<j) {
        if(a[i]+a[j]!=k) {
            printf("False\n");
            return;
        }
        ++i;
        --j;
    }
    printf("True\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) Main();
    
    return 0;
}
