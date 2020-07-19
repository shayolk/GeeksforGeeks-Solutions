/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/

bool comp(const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>& b) {
    return a.second.first*a.second.second < b.second.first*b.second.second;
}

int maxHeight(int height[],int width[],int length[],int n)
{
    vector<pair<int,pair<int,int>>> a;
    for(int i=0; i<n; ++i) {
        int x=height[i];
        int y=width[i];
        int z=length[i];
        a.push_back({x,{min(y,z), max(y,z)}});
        a.push_back({y,{min(z,x), max(z,x)}});
        a.push_back({z,{min(x,y), max(x,y)}});
    }
    sort(a.begin(), a.end(), comp);
    n=(int)a.size();
    vector<int> dp(n);
    dp[0]=a[0].first;
    for(int i=1; i<n; ++i) {
        dp[i]=a[i].first;
        for(int j=0; j<i; ++j) {
            // if(a[i].first>a[j].first && a[i].second.first>a[j].second.first) {
            //     dp[i]=max(dp[i], a[i].second.second+dp[j]);
            // }
            if(a[i].second.first>a[j].second.first && a[i].second.second>a[j].second.second) {
                dp[i]=max(dp[i], a[i].first+dp[j]);
            }
            // if(a[i].second.second>a[j].second.second && a[i].first>a[j].first) {
            //     dp[i]=max(dp[i], a[i].second.first+dp[j]);
            // }
        }
    }
    return *max_element(dp.begin(), dp.end());
}