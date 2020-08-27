#include <queue>
// you are required to complete this function 
// function should print the required range
pair<int,int> findSmallestRange(int ar[][N], int n, int k) {
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;
    int mn, mx=-2e9, so=2e9, a, b;
    for(int i=0; i<k; ++i) {
        p.push({ar[i][0],{i,0}});
        mx=max(mx, ar[i][0]);
    }
    while(!p.empty()) {
        pair<int,pair<int,int>> pr=p.top();
        p.pop();
        mn=pr.first;
        if(mx-mn<so) {
            so=mx-mn;
            a=mn;
            b=mx;
        }
        if(pr.second.second==n-1) return {a,b};
        mx=max(mx, ar[pr.second.first][pr.second.second+1]);
        p.push({ar[pr.second.first][pr.second.second+1],{pr.second.first,pr.second.second+1}});
    }
    return {-1,-1};
}
