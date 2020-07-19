#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> neb;

void init() {
    vector<int> v;
    // 0
    v.emplace_back(8);
    neb.emplace_back(v);
    // 1
    v.clear();
    v.emplace_back(2);
    v.emplace_back(4);
    neb.emplace_back(v);
    // 2
    v.clear();
    v.emplace_back(1);
    v.emplace_back(3);
    v.emplace_back(5);
    neb.emplace_back(v);
    // 3
    v.clear();
    v.emplace_back(2);
    v.emplace_back(6);
    neb.emplace_back(v);
    // 4
    v.clear();
    v.emplace_back(1);
    v.emplace_back(5);
    v.emplace_back(7);
    neb.emplace_back(v);
    // 5
    v.clear();
    v.emplace_back(2);
    v.emplace_back(4);
    v.emplace_back(6);
    v.emplace_back(8);
    neb.emplace_back(v);
    // 6
    v.clear();
    v.emplace_back(3);
    v.emplace_back(5);
    v.emplace_back(9);
    neb.emplace_back(v);
    // 7
    v.clear();
    v.emplace_back(4);
    v.emplace_back(8);
    neb.emplace_back(v);
    // 8
    v.clear();
    v.emplace_back(0);
    v.emplace_back(5);
    v.emplace_back(7);
    v.emplace_back(9);
    neb.emplace_back(v);
    // 9
    v.clear();
    v.emplace_back(6);
    v.emplace_back(8);
    neb.emplace_back(v);
}

const int nax=32;
vector<vector<long long>> dp(nax, vector<long long> (10));
vector<long long> pref(nax);

void build() {
    for(int j=0; j<10; ++j) {
        dp[1][j]=1;
    }
    for(int i=2; i<nax; ++i) {
        for(int j=0; j<10; ++j) {
            dp[i][j]=dp[i-1][j];
            for(int his: neb[j]) {
                dp[i][j]+=dp[i-1][his];
            }
        }
    }
    for(int i=0; i<nax; ++i) {
        for(int j=0; j<10; ++j) {
            pref[i]+=dp[i][j];
        }
    }
}
 
int main() {
    init();
    build();
	int t;
	scanf("%d", &t);
	while(t--) {
	    int n;
	    scanf("%d", &n);
	    printf("%lld\n", pref[n]);
	}
 
    return 0;
}
