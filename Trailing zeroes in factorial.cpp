//User function Template for C++
class Solution
{
public:
    int trailingZeroes(int N)
    {
        int two=0, five=0, ten=0;
        int p=2;
        while(p<=N) {
            two+=N/p;
            p*=2;
        }
        p=5;
        while(p<=N) {
            five+=N/p;
            p*=5;
        }
        p=10;
        while(p<=N) {
            ten+=N/p;
            p*=10;
        }
        return max(ten, min(two, five));
    }
};
