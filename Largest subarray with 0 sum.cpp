/*You are required to complete this function*/

int maxLen(int a[], int n) {
    unordered_map<int,int> m;
    int sum=0, len=0;
    m[0]=-1;
    for(int i=0; i<n; ++i) {
        sum+=a[i];
        if(m.count(sum)) {
            len=max(len, i-m[sum]);
        }
        else {
            m[sum]=i;
        }
    }
    return len;
}
