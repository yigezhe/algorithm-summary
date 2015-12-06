#include <stdio.h>
//there we will print all C(n,m) possible combination.
//example a,b,c,d
//C(4,2) is ab,ac,ad,bc,bd,cd
#define N 100
int a[N];
int b[N];
int nn=4;
int mm=3;
void print(int *array,int size) {
    int i;
    for(i=0; i<size; i++) {
        printf(" %d",array[i]);
    }
    printf("\n");
}
void comb(int n, int m) {
    if(m==mm) {
        print(b,mm);
    } else {
        int i;
        for(i=n; i<nn; i++) {
            b[m]=a[i];
            comb(i+1,m+1);
        }
    }
}
int main(void) {
    int i;
    for(i=0; i<n; i++) {
        a[i]=i+1;
    }
    comb(0,0);
    return 0;
}
