
/*interface*/
/*interface implementation*/
/*client*/
unsigned int Gcd(unsigned int M,unsigned int N) {
    unsigned int Rem;
    while(N>0) {
        Rem=M%N;
        M=N;
        N=Rem;
    }
    return M;
}
#include<stdio.h>
int main() {
    int M=50;
    int N=15;
    printf("Gcd(%d,%d)=%d\n",M,N,Gcd(M,N));
    return 0;
}
