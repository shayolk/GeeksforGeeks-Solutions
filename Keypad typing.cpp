//User function template for C++


//Function to find matching decimal representation of a string as on the keypad.
string printNumber(string s, int n) 
{
    string ans;
    for(char c: s) {
        int now=c-'a';
        int q=now/3+2, r=now%3;
        if(q==8 && r==0) --q;
        else if(q==9 && r==0) --q;
        else if(q>9) --q;
        ans+=('0'+q);
    }
    return ans;
}
