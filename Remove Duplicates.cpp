#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        // vector<bool> vis(256);
        unordered_map<char,bool> vis;
        for(char c: s) {
            vis[c]=true;
        }
        string ans;
        for(char c: s) {
            if(vis.count(c) && vis[c]) {
                ans+=c;
                vis[c]=false;
            }
        }
        cout<<ans<<'\n';
    }
    
    return 0;
}
