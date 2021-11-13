//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> vec, int K) {
    int n=vec.size();
    int lo=0, hi=n-1, mid;
    while(lo<=hi) {
        mid=lo+(hi-lo)/2;
        if(vec[mid]==K) return mid;
        if(vec[mid]<K) {
            if(vec[mid]<vec[n-1] && vec[n-1]<K) hi=mid-1;
            else lo=mid+1;
        }
        else {
            if(vec[mid]>vec[0] && vec[0]>K) lo=mid+1;
            else hi=mid-1;
        }
    }
    return -1;
}
