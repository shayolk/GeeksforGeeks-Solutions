#include <bits/stdc++.h>
using namespace std;

const int dx[]={-1,-1,-1,0,0,1,1,1};
const int dy[]={-1,0,1,-1,1,-1,0,1};

bool safe(int r, int c, int n, int m) {
    return (r>=0 && r<n && c>=0 && c<m);
}

bool find(string& s, int ind, int r, int c, int n, int m, vector<vector<char>>& board, vector<vector<bool>> vis) {
    if(ind==(int)s.size()) {
        return true;
    }
    for(int k=0; k<8; ++k) {
        int i=r+dx[k], j=c+dy[k];
        if(safe(i,j,n,m) && !vis[i][j] && board[i][j]==s[ind]) {
            vis[i][j]=true;
            if(find(s,ind+1,i,j,n,m,board,vis)) {
                return true;
            }
            vis[i][j]=false;
        }
    }
    return false;
}

vector<string> boggle(vector<vector<char>>& board, vector<string>& dict) {
    int n=(int)board.size(), m=(int)board[0].size(), d=(int)dict.size(), cnt=0;
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<string> ret;
    vector<bool> done(d);
    for(int i=0; i<n && cnt<d; ++i) {
        for(int j=0; j<m && cnt<d; ++j) {
            for(int k=0; k<d && cnt<d; ++k) {
                if(!done[k] && board[i][j]==dict[k][0]) {
                    vis[i][j]=true;
                    if(find(dict[k],1,i,j,n,m,board,vis)) {
                        ret.push_back(dict[k]);
                        done[k]=true;
                        ++cnt;
                    }
                    vis[i][j]=false;
                }
            }
        }
    }
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int x;
        scanf("%d", &x);
        set<string> words;
        for(int i=0; i<x; ++i) {
            string s;
            cin>>s;
            words.insert(s);
        }
        vector<string> dict;
        for(string s: words) {
            dict.push_back(s);
        }
        int n,m;
        scanf("%d%d", &n,&m);
        vector<vector<char>> board(n, vector<char>(m));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                scanf("%s", &board[i][j]);
            }
        }
        vector<string> ans=boggle(board, dict);
        if(ans.empty()) {
            printf("-1\n");
            continue;
        }
        sort(ans.begin(), ans.end());
        for(string i: ans) {
            cout<<i<<" ";
        }
        printf("\n");
    }
    
    return 0;
}
