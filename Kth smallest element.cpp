#include <bits/stdc++.h>
using namespace std;

#define ran(l,r) (l)+rand()%((r)-(l)+1)

int part(vector<int>& a, int lo, int hi) {
    int pos=ran(lo,hi);
    swap(a[pos], a[hi]);
    int x=a[hi], i=lo;
    for(int j=lo; j<hi; ++j) {
        if(a[j]<=x) {
            swap(a[i++], a[j]);
        }
    }
    swap(a[i], a[hi]);
    return i;
}

int find(vector<int>& a, int lo, int hi, int k) {
    int pos=part(a,lo,hi);
    if(pos==k) {
        return a[pos];
    }
    if(pos>k) {
        return find(a,lo,pos-1,k);
    }
    return find(a,pos+1,hi,k);
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
        int k;
        scanf("%d", &k);
        printf("%d\n", find(a,0,n-1,k-1));
    }
    
    return 0;
}
