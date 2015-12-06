/*interface*/
void sort(int *,int);
void print(int *,int);
int compare(const void *,const void *);

/*interface implementation*/
#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}
void sort(int *data,int length) {
    //qsort (data, sizeof(data)/sizeof(*data), sizeof(*data), compare);
    qsort (data, length, sizeof(int), compare);
}
void print(int *data,int length) {
    int i;
    for(i=0; i<length; i++) {
        printf(" %d",data[i]);
    }
    printf("\n");
}
/*client*/
#include<stdio.h>
int main() {
	int a[5]={1,2,8,6,4};
	int n=5;
    print(a,n);
    sort(a,n);
    print(a,n);
    return 0;
}
