//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix) {
    int n=(int)matrix.size();
    for(int i=0; i<n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    for(int i=0; i<n-1; ++i) {
        for(int j=i+1; j<n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
