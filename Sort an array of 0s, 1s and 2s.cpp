class Solution
{
    public:
    void sort012(int a[], int n)
    {
        vector<int> cnt(3);
        for(int i=0; i<n; ++i) {
            ++cnt[a[i]];
        }
        int j=0;
        for(int i=0; i<3; ++i) {
            while(cnt[i]--) {
                a[j++]=i;
            }
        }
    }
    
};
