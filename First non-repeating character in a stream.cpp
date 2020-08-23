#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        deque<char> d;
        vector<bool> vis(26), pop(26);
        for(int i=0; i<n; ++i) {
            char c;
            cin>>c;
            if(vis[c-'a']) {
                pop[c-'a']=true;
                while(!d.empty() && pop[d.front()-'a']) {
                    pop[d.front()-'a']=true;
                    d.pop_front();
                }
            }
            else {
                d.push_back(c);
                vis[c-'a']=true;
            }
            d.empty()?printf("-1 "):printf("%c ", d.front());
        }
        printf("\n");
    }
    
    return 0;
}
