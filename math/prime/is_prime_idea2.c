/*interface*/
#include<stdio.h>
#include<math.h>
/*interface implementation*/
int is_prime(int n) {
    if(n<=1) return 0;
    else if(n==2) return 1;
    else {
        int i;
        for(i=2; i<=(int)sqrt(n); i++) {
            if(n%i==0) return 0;
            }
        return 1;
    }
}
/*client*/
int main() {
    int i;
    for(i=0; i<20; i++) {
        if(is_prime(i)) printf("%d is a prime\n",i);
        else printf("%d is not a prime\n",i);
    }
    return 0;
}
