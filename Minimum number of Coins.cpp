#include <bits/stdc++.h>
using namespace std;

vector<int> money={1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> ans;
        for(int i=9; i>=0; --i) {
            while(n && n>=money[i]) {
                n-=money[i];
                ans.push_back(money[i]);
            }
        }
        for(int i: ans) {
            printf("%d ", i);
        }
        printf("\n");
    }
    
    return 0;
}
