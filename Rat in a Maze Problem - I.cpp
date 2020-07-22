// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5

const vector<int> dr={0, 0, 1, -1};
const vector<int> dc={1, -1, 0, 0};

bool safe(int i, int j, int n) {
    return i>=0 && i<n && j>=0 && j<n;
}

void back(int i, int j, int n, int m[MAX][MAX], string s, vector<string>& ans) {
    if(i==n-1 && j==n-1) {
        ans.push_back(s);
        return;
    }
    for(int x=0; x<4; ++x) {
        int r=i+dr[x], c=j+dc[x];
        if(safe(r,c,n) && m[r][c]) {
            if(x==0) s+='R';
            else if(x==1) s+='L';
            else if(x==2) s+='D';
            else s+='U';
            m[i][j]=0;
            back(r,c,n,m,s,ans);
            s.pop_back();
            m[i][j]=1;
        }
    }
}

vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string> ans;
    string s;
    if(m[0][0]) back(0,0,n,m,s,ans);
    sort(ans.begin(), ans.end());
    return ans;
}
