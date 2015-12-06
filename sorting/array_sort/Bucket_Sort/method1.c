/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100
int main() {
    int a[6]= {3,11,2,9,1,5};
    int b[N];
    int i;
    for(i=0; i<N; i++) {
        b[i]=0;
    }
    for(i=0; i<6; i++) {
        b[a[i]]=1;
    }
    for(i=0; i<N; i++) {
        if(b[i]==1) printf(" %d",i);
    }
    printf("\n");

    return 0;
}
