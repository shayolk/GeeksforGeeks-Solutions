#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d%d", &n,&k);
        vector<int> a(n);
        for(int& i:a) {
            scanf("%d", &i);
        }
        deque<int> d;
        for(int i=0; i<k; ++i) {
            while(!d.empty() && a[d.back()]<=a[i]) d.pop_back();
            d.push_back(i);
        }
        printf("%d ", a[d.front()]);
        for(int i=k; i<n; ++i) {
            while(!d.empty() && d.front()<=i-k) d.pop_front();
            while(!d.empty() && a[d.back()]<=a[i]) d.pop_back();
            d.push_back(i);
            printf("%d ", a[d.front()]);
        }
        printf("\n");
        // multiset<int,greater<int>> s;
        // for(int i=0; i<k; ++i) {
        //     s.insert(a[i]);
        // }
        // printf("%d ", *s.begin());
        // for(int i=k; i<n; ++i) {
        //     s.erase(s.find(a[i-k]));
        //     s.insert(a[i]);
        //     printf("%d ", *s.begin());
        // }
        // printf("\n");
    }
    
    return 0;
}
