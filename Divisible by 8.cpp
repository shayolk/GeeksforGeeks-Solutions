#include <bits/stdc++.h>
using namespace std;

bool find(string s) {
    int n=(int)s.size();
    if(n==0) return false;
    if(n==1) return stoi(s)%8==0;
    if(n==2) {
        if(stoi(s)%8==0) return true;
        reverse(s.begin(), s.end());
        if(stoi(s)%8==0) return true;
        return false;
    }
    for(int i=0; i<n-2; ++i) {
        for(int j=i+1; j<n-1; ++j) {
            for(int k=j+1; k<n; ++k) {
                string now;
                now+=s[i];
                now+=s[j];
                now+=s[k];
                sort(now.begin(), now.end());
                do {
                    if(stoi(now)%8==0) return true;
                } while(next_permutation(now.begin(), now.end()));
            }
        }
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        string s;
        cin>>s;
        puts(find(s)?"Yes":"No");
    }
    
    return 0;
}
