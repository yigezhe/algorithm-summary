#include<stdio.h>
#include<math.h>
int main() {
	int a[2]={1,2};
	int b[2]={0,3};
	int c[2]={-1,2};
	int ab[2];
	ab[0]=b[0]-a[0];
	ab[1]=b[1]-a[1];
	int ac[2];
	ac[0]=c[0]-a[0];
	ac[1]=c[1]-a[1];
	double cross_product=ab[0]*ac[1]-ab[1]*ac[0];
	double ab_length=sqrt(ab[0]*ab[0]+ab[1]*ab[1]);
	double distance=cross_product/ab_length;
	printf("C to AB line distance is %f\n",distance);

	return 0;
}
