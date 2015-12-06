//https://en.wikipedia.org/wiki/Binomial_coefficient
/*interface*/
/*interface implementation*/
int choose(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    else if (k == 0 || k == n || n<=1)
        return 1;
    else {
        //k = min(k, n - k); # take advantage of symmetry
        if(k>n-k) k=n-k;
        return choose(n-1,k)+choose(n-1,k-1);
    }
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
