#include <stdio.h>
#include <stdlib.h>
int main() {
    int n1,n2;
    int **array,i,j;
    printf("请输入所要创建的动态数组的第一维长度：");
    scanf("%d",&n1);
    printf("请输入所要创建的动态数组的第二维长度：");
    scanf("%d",&n2);
    array=(int**)malloc(n1*sizeof(int*)); //第一维
    for(i=0; i<n1; i++) {
        array[i]=(int*)malloc(n2* sizeof(int));//第二维
    }
    for(i=0; i<n1; i++) {
        for(j=0; j<n2; j++) {
            array[i][j]=i*n2+j+1;
            printf("%d\t",array[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<n1; i++) {
        free(array[i]);//释放第二维指针
    }
    free(array);//释放第一维指针
    return 0;
}
