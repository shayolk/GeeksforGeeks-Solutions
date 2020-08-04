// return the minimum number of swaps required to sort the arra
int minSwaps(int a[], int n) {
    vector<int> b(n);
    vector<int> m(1e6+5, -1);
    for(int i=0; i<n; ++i) {
        b[i]=a[i];
    }
    sort(b.begin(), b.end());
    vector<int> adj(n, -1);
    for(int i=0; i<n; ++i) {
    	m[b[i]]=i;
    }
    for(int i=0; i<n; ++i) {
        if(a[i]!=b[i]) {
            adj[i]=m[a[i]];
        }
    }
    int ans=0;
    for(int i=0; i<n; ++i) {
        if(adj[i]==-1) continue;
        int cnt=1, j=adj[i];
        while(j!=i) {
        	int k=j;
            j=adj[j];
            adj[k]=-1;
            ++cnt;
        }
        adj[i]=-1;
        ans+=cnt-1;
    }
    return ans;
}
