/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    vector<int> parent;
    
    void init(int n) {
        parent.resize(n+1);
        for(int i=0; i<=n; ++i) {
            parent[i]=i;
        }
    }
    
    int find(int n) {
        if(parent[n]!=n) {
            parent[n]=find(parent[n]);
        }
        return parent[n];
    }
    
    void merge(int a, int b) {
        parent[a]=b;
    }
    
    static bool comp(const Job& a, const Job& b) {
        if(a.profit==b.profit) {
            return a.dead>b.dead;
        }
        return a.profit>b.profit;
    }
    
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {
        int mx=0;
        for(int i=0; i<n; ++i) {
            mx=max(mx, arr[i].dead);
        }
        init(mx);
        sort(arr, arr+n, comp);
        int count=0, profit=0;
        for(int i=0; i<n; ++i) {
            int slot=find(arr[i].dead);
            if(slot) {
                ++count;
                profit+=arr[i].profit;
                merge(slot, slot-1);
            }
        }
        return vector<int>({count, profit});
    } 
};
