#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
	    int n;
	    scanf("%d", &n);
	    int nc=n, sum=0;
	    while(nc) {
	        sum+=nc%10;
	        nc/=10;
	    }
	    printf("%d\n", n%sum==0);
	}
 
    return 0;
}
