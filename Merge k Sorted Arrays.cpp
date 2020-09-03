// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
int *mergeKArrays(int arr[][N], int k) {
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;
    int *a=new int[k*k], ind=0;
    for(int i=0; i<k; ++i) p.push({arr[i][0],{i,0}});
    while(!p.empty()) {
        pair<int,pair<int,int>> pr=p.top();
        p.pop();
        a[ind++]=pr.first;
        int r=pr.second.first, c=pr.second.second;
        if(c+1<k) p.push({arr[r][c+1],{r,c+1}});
    }
    return a;
}
