#include<stdio.h>
#define N 10
#define INF 2000000000
int main() {
    int a[N][N];
    //图一,ABCD,AB=9,BC=1,CD=3,AD=2
    //0123,01=9,12=1,23=3,03=2
    /*
    int n=4;
    a[0][0]=0; a[0][1]=9; a[0][2]=-1; a[0][3]=2;
    a[1][0]=9; a[1][1]=0; a[1][2]=1; a[1][3]=-1;
    a[2][0]=-1; a[2][1]=1; a[2][2]=0; a[2][3]=3;
    a[3][0]=2; a[3][1]=-1; a[3][2]=3; a[3][3]=0;
    */
    //图二， ABC,AB=5,AC=1,CB=2
    //012,01=5,02=1,21=2
    int n=3;
    a[0][0]=0; a[0][1]=5; a[0][2]=1;
    a[1][0]=5; a[1][1]=0; a[1][2]=2;
    a[2][0]=1; a[2][1]=2; a[2][2]=0;

    int i,j,k;
    /*
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
                printf("%d to %d = %d\n",i,j,a[i][j]);
        }
    }
    */

    int dist[N][N];
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(a[i][j]==-1) dist[i][j]=INF;
            else dist[i][j]=a[i][j];
        }
    }
    /*
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
                printf("%d to %d = %d\n",i,j,dist[i][j]);
        }
    }
    */

    for (k=0; k<n; ++k) {
        for (i=0; i<n; ++i) {
            for (j=0; j<n; ++j) {
                /*
                   实际中为防止溢出，往往需要选判断 dist[i][k]和dist[k][j
                   都不是Inf ，只要一个是Inf，那么就肯定不必更新。
                 */
                if(dist[i][j]!=INF  && dist[i][k]!=INF && dist[k][j]!=INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j] ) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    for (i=0; i<n; ++i) {
        for (j=0; j<n; ++j) {
            printf("%d to %d = %d\n",i,j,dist[i][j]);
        }
    }

    return 0;
}
