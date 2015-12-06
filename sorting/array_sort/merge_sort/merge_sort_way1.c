#include<stdio.h>
#include<stdlib.h>
void print(int *a,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
}
void sort(int* a,int length) ;
void mergeSort(int *a, int * tmp, int left, int right) ;
void merge(int * a, int * tmp, int left, int right, int rightEnd ) ;
void sort(int* a,int length) {
    int *tmp = malloc(sizeof(int)*length);
    if(tmp==NULL) {
        printf("没有分配到足够的内存\n");
    }
    mergeSort(a, tmp,  0, length - 1);
}

void mergeSort(int *a, int * tmp, int left, int right) {
    if( left < right ) {
        int center = (left + right) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        merge(a, tmp, left, center + 1, right);
    }
}

void merge(int * a, int * tmp, int left, int right, int rightEnd ) {
    //这一部分代码还没有看懂，但是先用！
    int leftEnd = right - 1;
    int k = left;
    int num = rightEnd - left + 1;

    while(left <= leftEnd && right <= rightEnd)
        if(a[left]<=a[right])
            tmp[k++] = a[left++];
        else
            tmp[k++] = a[right++];

    while(left <= leftEnd)    // Copy rest of first half
        tmp[k++] = a[left++];

    while(right <= rightEnd)  // Copy rest of right half
        tmp[k++] = a[right++];

    // Copy tmp back
    int i;
    for(i = 0; i < num; i++, rightEnd--)
        a[rightEnd] = tmp[rightEnd];
}
int main() {
    int a[5] = {2, 6, 3, 5, 1};
    sort(a,5);
    print(a,5);
    return 0;
}
