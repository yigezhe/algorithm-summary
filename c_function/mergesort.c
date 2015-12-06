#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
    int n;
    scanf("%d",&n);
    int *a=malloc(n*sizeof(int));
    if(a==NULL) {
        printf("n 没有分配到内存\n");
    }
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    mergesort(a,n,compare);

    free(a);
    return 0;
}
