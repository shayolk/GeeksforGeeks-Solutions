#include <bits/stdc++.h>
using namespace std;

#define in(a,n)         for(int i=0; i<(n); ++i)  cin>>a[i]
#define vi              vector <int>

void Main() {
    int n,m,p;  cin>>n>>m>>p;
    vi a(n), b(m), c(p);    in(a,n); in(b,m); in(c,p);
    int i=0, j=0, k=0;
    bool flag=true;
    while(i<n && j<m && k<p) {
        if(a[i]==b[j] && b[j]==c[k]) {
            bool print=true;
            if(i>0 && a[i-1]==a[i]) print=false;
            if(j>0 && b[j-1]==b[j]) print=false;
            if(k>0 && c[k-1]==c[k]) print=false;
            if(print)   cout<<a[i]<<' ';
            ++i, ++j, ++k;
            flag=false;
        }
        else if(a[i]<=b[j] && a[i]<=c[k])   ++i;
        else if(b[j]<=a[i] && b[j]<=c[k])   ++j;
        else    ++k;
    }
    if(flag)    cout<<-1;
    cout<<'\n';
}

signed main()
{
  int t;  cin>>t;
    while(t--)  Main();
}