/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x) {
    int n=(int)s.size(), m=(int)x.size();
    if(n<m) return -1;
    // for(int i=0; i+m-1<n; ++i) {
    //     if(s.substr(i,m)==x) return i;
    // }
    // return -1;
    string con=x+'#'+s;
    n+=m+1;
    int l=0, r=0;
    vector<int> z(n);
    for(int i=1; i<n; ++i) {
        if(i>r) {
            l=r=i;
            while(r<n && con[r]==con[r-l]) ++r;
            z[i]=r-l;
            --r;
        }
        else if(z[i-l]<r-i+1) {
            z[i]=z[i-l];
        }
        else {
            l=i;
            while(r<n && con[r]==con[r-l]) ++r;
            z[i]=r-l;
            --r;
        }
    }
    for(int i=m+1; i<n; ++i) {
        if(z[i]==m) return i-m-1;
    }
    return -1;
}
