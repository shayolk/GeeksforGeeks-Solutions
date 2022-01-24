//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    static bool cmp(const Item& a, const Item &b) {
        return 1.0*a.value*b.weight > 1.0*b.value*a.weight;
    }
    
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, cmp);
        int i=0;
        double ans=0;
        while(W && i<n) {
            int now=min(W, arr[i].weight);
            ans+=1.0*arr[i].value/arr[i].weight*now;
            W-=now;
            ++i;
        }
        return ans;
    }
        
};
