#include<stdio.h>
#define N 100
#define INF 1000000000
int main() {
	int v[N];
	v[0]=1,v[1]=3,v[2]=5;
	int vn=3;
	int s=11;
	int i,j;
	int c[N];
	for(i=0;i<N;i++) {
		c[i]=INF;
	}
	c[0]=0;
	for(i=1;i<=s;i++) {
		for(j=0;j<vn;j++) {
			if(v[j]<=i && c[i-v[j]]+1<c[i]) {
				c[i]=c[i-v[j]]+1;
			}
		}
	}
	printf("%d\n",c[s]);
	return 0;
}
