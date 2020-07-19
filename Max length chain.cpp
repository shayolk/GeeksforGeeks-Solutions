/*
The structure to use is as follows
struct val{
    int first;
    int second;
};*/

/*You are required to complete this method*/

bool comp(struct val& i, struct val& j) {
    if(i.first!=j.first) {
        return i.first<j.first;
    }
    return i.second<j.second;
}

int maxChainLen(struct val p[],int n)
{
    sort(p,p+n, comp);
    vector<int> dp(n, 1);
    for(int i=1; i<n; ++i) {
        for(int j=0; j<i; ++j) {
            if(p[j].second<p[i].first) {
                dp[i]=max(dp[i], 1+dp[j]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}