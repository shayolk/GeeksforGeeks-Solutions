/* Counts the number of 2s in a number at d-th
   digit */
long long int count2sinRangeAtDigit(long long int number, long long int d) {
    long long cnt=0;
    while(number) {
        cnt+=number%10==2;
        number/=10;
    }
    return cnt;
}

/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number) {
    long long cnt=0;
    for(long long i=2; i<=number; ++i) {
        cnt+=count2sinRangeAtDigit(i,-1);
    }
    return cnt;
}
