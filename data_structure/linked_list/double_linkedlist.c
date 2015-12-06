
/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*interface implementation*/
/*client*/
int main() {
	int *n=malloc(n*sizeof(int));
	if(n==NULL) {
		printf("n 没有分配到内存\n");
	}

	free(n);
	return 0;
}
