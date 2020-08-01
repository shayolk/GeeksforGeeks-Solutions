#include <bits/stdc++.h>
using namespace std;

bool comp(const string a, const string b) {
    // return stoi(a+b) > stoi(b+a);
    int n=(int)a.size(), m=(int)b.size();
    for(int i=0; i<min(n,m); ++i) {
        if(a[i]!=b[i]) return a[i]>b[i];
    }
    if(n>m) {
        for(int i=m; i<n; ++i) {
            if(a[i]!=a[i-m]) return a[i]>a[i-m];
        }
        for(int i=0; i<m && m-1+i<n; ++i) {
        	if(a[m-1+i]!=b[i]) return a[m-1+i]<b[i];
        }
    }
    if(m>n) {
	    for(int i=n; i<m; ++i) {
	        if(b[i]!=b[i-n]) return b[i]<b[i-n];
	    }
	    for(int i=0; i<n && n-1+i<m; ++i) {
        	if(b[n-1+i]!=a[i]) return b[n-1+i]>a[i];
        }
	}
	return a>b;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<string> a(n);
        for(string& i:a) {
            cin>>i;
        }
        sort(a.begin(), a.end(), comp);
        for(string i:a) {
            cout<<i;
        }
        printf("\n");
    }
    
    return 0;
}
