class Solution{
	public:
	string fractionToDecimal(int numerator, int denominator) {
	    int quo=numerator/denominator;
	    string ans=to_string(quo);
	    int rem=numerator%denominator;
	    if(!rem) return ans;
	    string dec=".";
	    int ind=1, here;
	    map<int,int> pos;
	    while(rem && !pos.count(rem)) {
	        pos[rem]=ind;
	        rem*=10;
	        int here=rem/denominator;
	        rem%=denominator;
	        string his=to_string(here);
	        dec+=his;
	        ind+=his.size();
	    }
	    if(!rem) return ans+dec;
	    return ans+dec.substr(0, pos[rem])+'('+dec.substr(pos[rem], dec.size()-pos[rem])+')';
	}
};
