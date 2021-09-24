//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        int cnt=0, p=1;
        ++n;
        for(int bit=0; bit<31; ++bit) {
            cnt+=(n/p/2)*p+max(0, n%(2*p)-p);
            p*=2;
        }
        return cnt;
    }
};
