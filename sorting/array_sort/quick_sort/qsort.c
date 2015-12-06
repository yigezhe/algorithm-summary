
/*interface*/
/*interface implementation*/
/*client*/
#include <stdio.h>
#include <stdlib.h>
int comp (const void * elem1, const void * elem2) {
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
int compare_function(const void *a,const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}
#include <string.h>
int compare_function(const void *a,const void *b) {
    return (strcmp((char *)a,(char *)b));
}
int compare_function(const void *a,const void *b) {
    double *x = (double *) a;
    double *y = (double *) b;
    // return *x - *y; // this is WRONG...
    if (*x < *y) return -1;
    else if (*x > *y) return 1;
    return 0;
}
typedef struct {
    int key;
    double value;
} the_record;

int compare_function(const void *a,const void *b) {
    the_record *x = (the_record *) a;
    the_record *y = (the_record *) b;
    return x->key - y->key;
}

int main(int argc, char* argv[]) {
    int x[] = {4,5,2,3,1,0,9,8,6,7};

    qsort (x, sizeof(x)/sizeof(*x), sizeof(*x), comp);

    for (int i = 0 ; i < 10 ; i++)
        printf ("%d ", x[i]);

    return 0;
}
