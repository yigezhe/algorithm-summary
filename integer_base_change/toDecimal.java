public int toDecimal(int n, int b) {
    int result=0;
    int multiplier=1;

    while(n>0) {
        result+=n%10*multiplier;
        multiplier*=b;
        n/=10;
    }

    return result;
}
return Integer.parseInt(""+n,b);
