// Function to find square root
// x: element to find square root
long long int floorSqrt(long long int x) {
    long long lo=1, hi=x, mid, ans;
    while(lo<=hi) {
        mid=lo+(hi-lo)/2;
        if(mid*mid==x) return mid;
        if(mid*mid<x) {
            ans=mid;
            lo=mid+1;
        }
        else {
            hi=mid-1;
        }
    }
    return ans;
}
