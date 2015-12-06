//https://en.wikipedia.org/wiki/Binomial_coefficient
/*interface*/
/*interface implementation*/
int factorial(int n) {
    if(n<0) return -1;
    else if( n==0 ) {
        return 1;
    } else if( n==1 ) {
        return 1;
    } else {
        int i;
        int product=1;
        for(i=2; i<=n; i++) {
            product*=i;
        }
        return product;
    }
}
int choose(int n, int k) {
    if (k > n) {
        return 0;
    }
    return factorial(n)/(factorial(k)*factorial(n-k));
}
/*client*/
#include<stdio.h>
int main() {
    int n,k;
    for(n=0; n<10; n++) {
        for(k=0; k<=n; k++) {
            printf(" %d",choose(n,k));
        }
        printf("\n");
    }
    return 0;
}
