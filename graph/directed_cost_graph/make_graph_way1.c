#include<stdio.h>
#define N 100
#define INF 1000
int main() {
    int i,j;
    int map[N][N];
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(i==j) map[i][j]=0;
            else map[i][j]=INF;
        }
    }

    int v,e;
    scanf("%d%d",&v,&e);
    for(i=0; i<e; i++) {
        int s,t,w;
        scanf("%d%d%d",&s,&t,&w);
        map[s][t]=w;
    }
    for(i=0; i<v; i++) {
        for(j=0; j<v; j++) {
		if(map[i][j]==INF) { printf(" INF"); }
		else printf("%4d",map[i][j]);
        }
	printf("\n");
    }
    return 0;
}
