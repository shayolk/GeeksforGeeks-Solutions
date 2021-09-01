//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int cnt=1, mx=0;
        for(int i=1; i<size; ++i) {
            if(a[i]==a[mx]) ++cnt;
            else --cnt;
            if(cnt==0) {
                mx=i;
                cnt=1;
            }
        }
        cnt=0;
        for(int i=0; i<size; ++i) {
            if(a[i]==a[mx]) ++cnt;
        }
        return cnt>size/2?a[mx]:-1;
    }
};
