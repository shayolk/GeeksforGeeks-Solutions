#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> jump(10005);
    for(int i=1; i<10005; i*=2) {
        jump[i]=true;
    }
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        puts(jump[n]?"True":"False");
    }
    
    return 0;
}
