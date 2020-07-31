#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& a, int lo, int hi, int val) {
    int ret=lo-1;
    while(lo<=hi) {
        int mid=lo+(hi-lo)/2;
        if(a[mid]<val) lo=mid+1, ret=max(ret,mid);
        else hi=mid-1;
    }
    return ret;
}

long long merge(vector<int>& a, int l, int r) {
    if(l>=r) return 0;
    int mid=l+(r-l)/2;
    long long ans = merge(a,l,mid) + merge(a,mid+1,r);
    for(int k=l; k<=mid; ++k) {
        ans+=search(a,mid+1,r,a[k])-mid;
    }
    vector<int> x,y;
    x.assign(a.begin()+l, a.begin()+mid+1);
    y.assign(a.begin()+mid+1, a.begin()+r+1);
    x.push_back(2e9);
    y.push_back(2e9);
    int i=0, j=0, n=mid-l+1, m=r-mid, k=l;
    while(i<n || j<m) {
        if(x[i]<y[j]) a[k++]=x[i++];
        else a[k++]=y[j++];
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for(int& i: a) {
            scanf("%d", &i);
        }
        printf("%lld\n", merge(a,0,n-1));
    }
    
    return 0;
}
