
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int IsEven(unsigned int N) {
    if(N%2==0) {
        return 1;
    } else {
        return 0;
    }
}
long int Pow(long int X,unsigned int N) {
    if(N==0) return 1;
    else if(N==1) return X;
    else if(IsEven(N)) {
        return Pow(X*X,N/2);
    } else {
        return Pow(X*X,N/2)*X;
    }
}
int main() {
    long int X=5;
    int N=4;
    printf("Pow(%ld,%d)=%ld\n",X,N,Pow(X,N));
    return 0;
}
