
/*interface*/
#include<stdio.h>
void sort(int *,int);
void bubble_sort(int *,int);
void print(int *,int);
/*interface implementation*/
void sort(int *data,int length) {
    bubble_sort(data,length);
}
void bubble_sort(int *data,int length) {
    int i,j;
    //最终把最小的放在第一位！
    for (i = 0; i < length; i++)
        //保证最后一位是最大的！
        for (j = 0; j < length-1; j++)
            if (data[j] > data[j + 1]) {
                int tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
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
