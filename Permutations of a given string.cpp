#include <bits/stdc++.h>
using namespace std;

void back(string s, int n, int ind, vector<string>& ans) {
    if(ind==n-1) {
        ans.emplace_back(s);
        return;
    }
    for(int i=ind; i<n; ++i) {
        swap(s[i], s[ind]);
        back(s,n,ind+1,ans);
        swap(s[i], s[ind]);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        string s;
        cin>>s;
        int n=(int)s.size();
        vector<string> ans;
        back(s,n,0,ans);
        sort(ans.begin(), ans.end());
        for(string i: ans) {
            cout<<i<<' ';
        }
        printf("\n");
    }
    
    return 0;
}
