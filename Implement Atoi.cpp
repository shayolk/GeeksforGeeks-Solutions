/*You are required to complete this method */
int atoi(string str) {
    int ans=0, n=(int)str.size(), i=0;
    bool flag=false;
    if(str[i]=='-') {
        flag=true;
        ++i;
    }
    while(i<n) {
        if(!isdigit(str[i])) return -1;
        ans=ans*10+(str[i++]-'0');
    }
    return flag?-ans:ans;
}
