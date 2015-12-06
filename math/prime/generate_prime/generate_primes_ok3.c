#include<stdio.h>
//办法一数组来建立一个素数的判定，只要两个数不是素数就可以！
#define N 1000000
int main() {
    int p[N];
    int i,j;
    for(i=2; i<N; i++) {
        p[i]=1;
    }
    for(i=2; i*i<N; i++) {
        if(p[i]) {
            for(j=2; i*j<N; j++) {
                p[i*j]=0;
            }
        }
    }
    p[0]=0;
    p[1]=0;
    for(i=2; i<N; i++) {
        if(p[i])printf("%d ",i);
    }
    printf("\b\n");

    return 0;
}
