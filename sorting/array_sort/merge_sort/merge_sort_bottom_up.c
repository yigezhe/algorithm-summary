#define N 100
#include<stdio.h>
int min(int a,int b) {
    if(a>b) return b;
    else return a;
}
void BottomUpMerge(int A[], int iLeft, int iRight, int iEnd, int B[]) {
    int i0 = iLeft;
    int i1 = iRight;
    int j;

    /* While there are elements in the left or right runs */
    for (j = iLeft; j < iEnd; j++) {
        /* If left run head exists and is <= existing right run head */
        if (i0 < iRight && (i1 >= iEnd || A[i0] <= A[i1])) {
            B[j] = A[i0];
            i0 = i0 + 1;
        } else {
            B[j] = A[i1];
            i1 = i1 + 1;
        }
    }
}
void print(int a[],int n) {
    int i;
    for(i = 0; i < n; i++)
        printf(" %d",a[i]);
    printf("\n");
}

void CopyArray(int B[], int A[], int n) {
    int i;
    for(i = 0; i < n; i++)
        A[i] = B[i];
}

/* array A[] has the items to sort; array B[] is a work array */
void BottomUpSort(int A[], int B[], int n) {
    /* Each 1-element run in A is already "sorted". */
    /* Make successively longer sorted runs of length 2, 4, 8, 16... until whole array is sorted. */
    int width,i;
    for (width = 1; width < n; width = 2 * width) {
        /* Array A is full of runs of length width. */
        for (i = 0; i < n; i = i + 2 * width) {
            /* Merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B[] */
            /* or copy A[i:n-1] to B[] ( if(i+width >= n) ) */
		//这里没有使用递归！
            BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B);
        }
        /* Now work array B is full of runs of length 2*width. */
        /* Copy array B to array A for next iteration. */
        /* A more efficient implementation would swap the roles of A and B */
        CopyArray(B, A, n);
        /* Now array A is full of runs of length 2*width. */
    }
}
int main() {

    int A[N];
    int B[N];
    A[0]=1;
    A[1]=8;
    A[2]=4;
    A[3]=5;
    int n=4;
    print(A,n);
    BottomUpSort(A, B, n);
    print(A,n);
    return 0;
}
