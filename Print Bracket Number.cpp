#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    char s[105];
    while(t--) {
        scanf("%s", &s);
        int dep=0;
        stack<int> close;
        for(int i=0; s[i]; ++i) {
            if(s[i]=='(') {
                printf("%d ", ++dep);
                close.push(dep);
            }
            else if(s[i]==')') {
                printf("%d ", close.top());
                close.pop();
            }
        }
        printf("\n");
    }
    
    return 0;
}
