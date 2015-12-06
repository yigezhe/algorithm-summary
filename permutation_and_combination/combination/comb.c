#include <stdio.h>
//there we will print all C(n,m) possible combination.
//example a,b,c,d
//C(4,2) is ab,ac,ad,bc,bd,cd
#define N 100
int a[N];
int b[N];
void print(int *array,int size) {
    int i;
    for(i=0; i<size; i++) {
        printf(" %d",array[i]);
    }
    printf("\n");
}
void comb(int n, int m,int M) {
    if(m==0) {
        print(b,M);
        //if there use print(b,m),
        //because m is local variable,
        //you will not get combination.
        //you must use print(b,3) to get what you want
    } else {
        int i;
        for(i=n-1; i>=0; i--) {
            b[m-1]=a[i];
            comb(i,m-1,M);
        }
    }
}
int main(void) {
    // your code goes here
    int n=4;
    int m=3;
    int i;
    for(i=0; i<n; i++) {
        a[i]=i+1;
    }
    comb(n,m,m);
    return 0;
}
