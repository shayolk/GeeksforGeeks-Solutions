class Solution{
    int generate(int i, int last, int m, int n) {
        // cout<<i<<" "<<last<<"\n";
        if(i==n) return 1;
        int here=0;
        for(int j=last/2; j>0; --j) {
            here+=generate(i+1, j, m, n);
        }
        return here;
    }
    
public:
    int numberSequence(int m, int n){
        return generate(0, 2*m, m, n);
    }
};
