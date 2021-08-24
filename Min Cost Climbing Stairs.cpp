//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        for(int i=2; i<N; ++i) {
            cost[i]+=min(cost[i-1], cost[i-2]);
        }
        return min(cost[N-2], cost[N-1]);
    }
};
