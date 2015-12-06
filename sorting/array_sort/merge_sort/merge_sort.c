//https://www.topcoder.com/community/data-science/data-science-tutorials/sorting/
/*interface*/
#include<stdio.h>
void sort(int *,int);
void print(int *,int);
typedef struct {
    int *data;
    int length;
} array;
/*interface implementation*/
void sort(int *data,int length) {
    array a;
    a.data=data;
    a.length=length;
    merge_sort(a);
}
array merge_sort(array);
array merge_sort (array) {
int *data=array.data;
int length=array.length;
    if (length == 1)
        return data;
    int middle = data.Length / 2;
    int[] left = mergeSort(subArray(data, 0, middle - 1));
    int[] right = mergeSort(subArray(data, middle, data.Length - 1));
    int[] result = new int[data.Length];
    int dPtr = 0;
    int lPtr = 0;
    int rPtr = 0;
    while (dPtr < data.Length) {
        if (lPtr == left.Length) {
            result[dPtr] = right[rPtr];
            rPtr++;
        } else if (rPtr == right.Length) {
            result[dPtr] = left[lPtr];
            lPtr++;
        } else if (left[lPtr] < right[rPtr]) {
            result[dPtr] = left[lPtr];
            lPtr++;
        } else {
            result[dPtr] = right[rPtr];
            rPtr++;
        }
        dPtr++;
    }
    return result;
}

void print(int *data,int length) {
    int i;
    for(i=0; i<length; i++) {
        printf(" %d",data[i]);
    }
    printf("\n");
}
/*client*/
int main() {
    int data[5]= {2,3,1,8,5};
    int length=5;
    print(data,length);
    sort(data,length);
    print(data,length);
    return 0;
}
