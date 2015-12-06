#include<stdio.h>
#define N 1000000
int main() {
    int p[N];
    int i,j;
    for(i=2; i<N; i++) {
        p[i]=1;
    }
    for(i=2; i*i<N; i++) {
        if(p[i]) {//这里节省了一些查找！
            for(j=i; i*j<N; j++) {//j=i也节省了一些查找！
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
