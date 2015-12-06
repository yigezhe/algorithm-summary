
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>

long int Pow(long int X,unsigned int N) {
    unsigned int i;
    long int res=1;
    for(i=0; i<N; i++) {
        res*=X;
    }
    return res;
}
int main() {
    long int X=5;
    int N=4;
    printf("Pow(%ld,%d)=%ld\n",X,N,Pow(X,N));
    return 0;
}
