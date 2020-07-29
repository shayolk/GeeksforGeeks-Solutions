#include <bits/stdc++.h>
using namespace std;

bool find(vector<int>& a, int lo, int hi, int n) {
    while(lo<=hi) {
        int mid=lo+(hi-lo)/2;
        if(a[mid]==n) return true;
        else if(a[mid]>n) hi=mid-1;
        else lo=mid+1;
    }
    return false;
}

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
        sort(a.begin(), a.end());
        int cnt=0;
        for(int k=2; k<n; ++k) {
            int i=0, j=k-1;
            while(i<j) {
                if(a[i]+a[j]==a[k]) {
                    ++cnt;
                    ++i;
                    --j;
                }
                else if(a[i]+a[j]<a[k]) {
                    ++i;
                }
                else {
                    --j;
                }
            }
        }
        printf("%d\n", cnt?cnt:-1);
    }
    
    return 0;
}
