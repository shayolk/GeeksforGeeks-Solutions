#include <bits/stdc++.h>
using namespace std;

bool safe(int** a, int r, int c, int val) {
    for(int k=0; k<9; ++k) {
        if(a[k][c]==val) return false;
        if(a[r][k]==val) return false;
    }
    int x=(r/3)*3, y=(c/3)*3;
    for(int i=x; i<x+3; ++i) {
        for(int j=y; j<y+3; ++j) {
            if(a[i][j]==val) return false;
        }
    }
    return true;
}

bool sudoku(int** a, int i, int j) {
    if(i==8 && j==9) {
        return true;
    }
    if(j==9) {
        ++i;
        j=0;
    }
    if(a[i][j]) return sudoku(a,i,j+1);
    for(int val=1; val<=9; ++val) {
        if(safe(a,i,j,val)) {
            a[i][j]=val;
            if(sudoku(a,i,j+1)) {
                return true;
            }
            a[i][j]=0;
        }
    }
    return false;
    /* Method 2 */
    // bool flag=true;
    // for(int i=0; i<9; ++i) {
    //     for(int j=0; j<9; ++j) {
    //         if(!a[i][j]) {
    //             flag=false;
    //             for(int val=1; val<=9; ++val) {
    //                 if(safe(a,i,j,val)) {
    //                     a[i][j]=val;
    //                     if(sudoku(a,0,0)) {
    //                         return true;
    //                     }
    //                     a[i][j]=0;
    //                 }
    //             }
    //         }
    //         if(!flag) break;
    //     }
    //     if(!flag) break;
    // }
    // return flag;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        // vector<vector<int>> a(9, vector<int>(9));
        /* int a[9][9]; */
        int **a=new int *[9];
        for(int i=0; i<9; i++) a[i]=new int[9];
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        sudoku(a,0,0);
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
