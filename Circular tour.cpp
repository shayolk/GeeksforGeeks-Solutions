/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n) {
    int st=0, pet=0, exc=0;
    for(int i=0; i<n; ++i) {
        pet+=p[i].petrol-p[i].distance;
        if(pet<0) {
            exc+=pet;
            pet=0;
            st=(i+1)%n;
        }
    }
    return pet+exc>=0?st:-1;
}
