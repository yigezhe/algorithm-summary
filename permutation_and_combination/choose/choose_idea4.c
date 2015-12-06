//https://en.wikipedia.org/wiki/Binomial_coefficient
/*interface*/
/*interface implementation*/
int choose(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    else if (k == 0 || k == n)
        return 1;
    else {
        //k = min(k, n - k); # take advantage of symmetry
        if(k>n-k) k=n-k;
        int c = 1;
        int i;
        for (i=0; i<k; i++)
            c = c * (n - i) / (i + 1);
        return c;

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
