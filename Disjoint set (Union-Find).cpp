/*Complete the functions below*/
int find(int A[],int X)
{
    if(A[X]!=X) {
        A[X]=find(A, A[X]);
    }
    return A[X];
}
void unionSet(int A[],int X,int Z)
{
    int x=find(A, X);
    int z=find(A, Z);
    A[x]=z;
}
