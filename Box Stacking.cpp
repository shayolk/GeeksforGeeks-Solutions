class Solution{
    struct box {
        int l,b,h;
        box(int l=0, int b=0, int h=0) {
            this->l=l;
            this->b=b;
            this->h=h;
        }
        bool operator < (const box& a) const {
            return l*b<a.l*a.b;
        }
    };
    
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int maxHeight(int height[],int width[],int length[],int n)
    {
        vector<box> a;
        for(int i=0; i<n; ++i) {
            int h=height[i], w=width[i], l=length[i];
            a.push_back(box(min(h, w), max(h, w), l));
            a.push_back(box(min(l, w), max(l, w), h));
            a.push_back(box(min(h, l), max(h, l), w));
        }
        sort(a.rbegin(), a.rend());
        int ans=a[0].h, m=a.size();
        vector<int> dp(m);
        dp[0]=a[0].h;
        for(int i=1; i<m; ++i) {
            dp[i]=a[i].h;
            for(int j=0; j<i; ++j) {
                if(a[j].l>a[i].l && a[j].b>a[i].b) {
                    dp[i]=max(dp[i], dp[j]+a[i].h);
                }
            }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};
