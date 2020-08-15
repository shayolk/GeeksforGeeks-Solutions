#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    char c[10005];
    while(t--) {
        scanf("%s", c);
        unordered_map<char,int> m;
        for(int i=0; c[i]; ++i) {
            ++m[c[i]];
        }
        unordered_map<int,int> n;
        for(auto i:m) {
            ++n[i.second];
        }
        bool flag=true;
        if((int)n.size()>2) flag=false;
        if((int)n.size()==2) {
            auto i=n.begin();
            auto j=i++;
            if(abs((i->first)-(j->first))!=1) flag=false;
            else if(i->second>1 && j->second>1) flag=false;
        }
        printf("%d\n", flag);
    }
    
    return 0;
}
