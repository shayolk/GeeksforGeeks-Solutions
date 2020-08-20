#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char,char> m;
    m['(']=')';
    m['{']='}';
    m['[']=']';
    int t;
    scanf("%d", &t);
    char c[100005];
    while(t--) {
        scanf("%s", c);
        stack<char> s;
        bool flag=true;
        for(int i=0; c[i]; ++i) {
            if(m.count(c[i])) {
                s.push(c[i]);
            }
            else {
                if(s.empty() || m[s.top()]!=c[i]) {
                    flag=false;
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty()) flag=false;
        puts(flag?"balanced":"not balanced");
    }
    
    return 0;
}
