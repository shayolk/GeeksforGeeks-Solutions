//User function template for C++
class Solution{
    static bool comp(const string& a, const string& b) {
        string ab=a+b, ba=b+a;
        return ab>ba;
    }
    
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(vector<string> &arr) {
	    sort(arr.begin(), arr.end(), comp);
	    string ans;
	    for(string s: arr) {
	        ans+=s;
	    }
	    return ans;
	}
};
