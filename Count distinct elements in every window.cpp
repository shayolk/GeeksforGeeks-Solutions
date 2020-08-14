vector <int> countDistinct (int a[], int n, int k) {
    unordered_map<int,int> m;
    for(int i=0; i<min(n,k); ++i) {
        ++m[a[i]];
    }
    vector<int> ans;
    int now=(int)m.size();
    ans.push_back(now);
    for(int i=k; i<n; ++i) {
        if(!m[a[i]]) ++now;
        ++m[a[i]];
        --m[a[i-k]];
        if(!m[a[i-k]]) --now;
        ans.push_back(now);
    }
    return ans;
}
