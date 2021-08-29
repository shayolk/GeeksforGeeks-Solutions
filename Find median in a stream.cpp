class Solution
{
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(mx.size()>mn.size()) mx.push(x);
        else mn.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(mx.size()>mn.size()) {
            mn.push(mx.top());
            mx.pop();
        }
        else {
            mx.push(mn.top());
            mn.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(mx.size()>mn.size()) return mx.top();
        else return (mn.top()+mx.top())/2.0;
    }
};
